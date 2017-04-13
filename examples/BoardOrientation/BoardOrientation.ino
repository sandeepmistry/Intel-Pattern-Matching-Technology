#include <CurieIMU.h>
#include <CurieSerialFlash.h>
#include <CuriePME.h>

const int NUM_ORIENTATIONS = 6;

const String ORIENTATIONS[NUM_ORIENTATIONS] = {
  "Up",
  "Down",
  "Digital pins up",
  "Analog pins up",
  "Connector down",
  "Connector up"
};

const char* filename = "CuriePME.dat";

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  CuriePME.begin();

  Serial.println("Initializing IMU device...");
  CurieIMU.begin();

  Serial.println("Initializing on-board SPI flash ...");
  if (!SerialFlash.begin(ONBOARD_FLASH_SPI_PORT, ONBOARD_FLASH_CS_PIN)) {
    Serial.println("Unable to access SPI Flash chip");
    while (1);
  }

  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);

  Serial.println("Welcome to the CuriePME + CurieIMU orientation demo sketch!");
  Serial.println();
}

void loop() {
  Serial.println("Please select an option:");
  Serial.println("1) Determine orientation");
  Serial.println("2) Train orientation");
  Serial.println("3) Clear training data");
  Serial.println("4) Save training data to SPI flash");
  Serial.println("5) Restore training data from SPI flash");
  Serial.println();

  int selection;

  do {
    selection = Serial.parseInt();
  } while (selection == 0);

  if (selection == 1) {
    determineOrientation();
  } else if (selection == 2) {
    trainOrientation();
  } else if (selection == 3) {
    clearTraining();
  } else if (selection == 4) {
    saveTraining();
  } else if (selection == 5) {
    restoreTraining();
  } else {
    Serial.println("Invalid option!");
  }

  Serial.println();
  Serial.println();
}

void determineOrientation() {
  while (!CurieIMU.dataReady(ACCEL));

  int rawX = CurieIMU.readAccelerometer(X_AXIS);
  int rawY = CurieIMU.readAccelerometer(Y_AXIS);
  int rawZ = CurieIMU.readAccelerometer(Z_AXIS);

  // training data must be a byte (0 - 255),
  // so map the full range of the IMU data to a
  // value between 0 and 255
  byte x = (byte) map(rawX, -32768, 32767, 0, 255);
  byte y = (byte) map(rawY, -32768, 32767, 0, 255);
  byte z = (byte) map(rawZ, -32768, 32767, 0, 255);

  CuriePME.beginClassify();
  CuriePME.write(x);
  CuriePME.write(y);
  CuriePME.write(z);
  int category = CuriePME.endClassify();

  if (category >= 1 && category <= NUM_ORIENTATIONS) {
    Serial.print("Board orientation is: ");
    Serial.println(ORIENTATIONS[category - 1]);
  } else {
    Serial.println("Unknown orientation!");
  }
  Serial.println();
}

void trainOrientation() {
  Serial.println("Please enter the boards current orientation:");
  for (int i = 0; i < NUM_ORIENTATIONS; i++) {
    Serial.print(i + 1);
    Serial.print(") ");
    Serial.println(ORIENTATIONS[i]);
  }
  Serial.println();

  int category;

  do {
    category = Serial.parseInt();
  } while (category == 0);

  if (category >= 1 && category <= NUM_ORIENTATIONS) {
    while (!CurieIMU.dataReady(ACCEL));

    int rawX = CurieIMU.readAccelerometer(X_AXIS);
    int rawY = CurieIMU.readAccelerometer(Y_AXIS);
    int rawZ = CurieIMU.readAccelerometer(Z_AXIS);

    byte x = (byte) map(rawX, -32768, 32767, 0, 255);
    byte y = (byte) map(rawY, -32768, 32767, 0, 255);
    byte z = (byte) map(rawZ, -32768, 32767, 0, 255);

    CuriePME.beginLearning(category);
    CuriePME.write(x);
    CuriePME.write(y);
    CuriePME.write(z);
    CuriePME.endLearning();

    Serial.print("Added training data for orienation: ");
    Serial.println(ORIENTATIONS[category - 1]);
  } else {
    Serial.println("Invalid option!");
  }
}

void clearTraining() {
  Serial.println("Clearing training data");

  CuriePME.clearState();
}

void saveTraining() {
  Serial.println("Saving training data");
  
  if (!SerialFlash.exists(filename)) {
    SerialFlash.createErasable(filename, CuriePME.maxNeuronStateSize());
  }

  SerialFlashFile file = SerialFlash.open(filename);

  if (!file) {
    Serial.println("Error opening SPI flash file!");
    return;
  }

  if (!CuriePME.saveState(file)) {
    Serial.println("Error saving state to SPI flash!");
  } else {
    Serial.println("Successfully saved state to SPI flash");
  }

  file.close();
}

void restoreTraining() {
  Serial.println("Restoring training data");

  SerialFlashFile file = SerialFlash.open(filename);

  if (!file) {
    Serial.println("Error opening SPI flash file!");
    return;
  }

  if (!CuriePME.restoreState(file)) {
    Serial.println("Error restoring state from SPI flash!");
  } else {
    Serial.println("Successfully restoring state from SPI flash");
  }

  file.close();
}

