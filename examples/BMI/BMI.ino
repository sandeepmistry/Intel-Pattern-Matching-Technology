/**
 * This sketch demonstrates how yo train the pattern matching engine (PME)
 * With the Body Mass Index (BMI) classification data from
 * https://bmicalculator.mes.fm/bmi-chart
 * 
 * It then prompts the user to enter their height in cm and weight in kg
 * on the Serial Monitor to classify their BMI category
 * 
 */

#include <CuriePME.h>

#include "data.h"

// debug the input data used in training
const bool DEBUG = false;

// it's typically recommended you use 70 - 80% your input data for training,
// and the remaining 30 - 20% is used to evaluate the trained model
const float TRAINING_PERCENTAGE = 0.70;

// calculate the training point count, based on the percentage and the number
// of entries in the BMI table
const int TRAINING_COUNT = TRAINING_PERCENTAGE * BMI_TABLE_ENTRY_COUNT;

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  // start the pattern matching engine (PME)
  CuriePME.begin();

  // clear the previosly trained data
  CuriePME.forget();

  // train it
  train();

  // run some sample classifications
  classifyBMI(188, 50); // Underweight?
  classifyBMI(193, 86); // Healthy?
  classifyBMI(175, 82); // Overweight?
  classifyBMI(173, 104); // Obese?
  classifyBMI(152, 118); // Extremely Obese?

  Serial.println();
}

void loop() {
  // prompt the user to enter a height and weight for classification
  
  int height;
  int weight;

  Serial.print("Please enter your height in cm: ");

  // read the height from the Serial Monitor
  do {
    height = Serial.parseInt();
  } while (height == 0);

  Serial.println(height);

  Serial.print("Please enter your weight in kg: ");

  // read the weight from the Serial Monitor
  do {
    weight = Serial.parseInt();
  } while (weight == 0);

  Serial.println(weight);

  classifyBMI(height, weight);

  Serial.println();
}

// selects random data points from the BMI to train the PME
void train() {
  Serial.print("Training with ");
  Serial.print(TRAINING_COUNT);
  Serial.print("/");
  Serial.print(BMI_TABLE_ENTRY_COUNT);
  Serial.println(" entries from the BMI table");
  Serial.println();

  for (int i = 0; i < TRAINING_COUNT; i++) {
    // determine a random index in the data to use from training
    int tableIndex = random(BMI_TABLE_ENTRY_COUNT - 1);

    // get the entry's components
    int category = BMI_TABLE[tableIndex][CATEGORY_INDEX];
    int height = BMI_TABLE[tableIndex][HEIGHT_INDEX];
    int weight = BMI_TABLE[tableIndex][WEIGHT_INDEX];

    trainBMI(category, height, weight);
  }

  Serial.println();
}

void trainBMI(int category, byte height, byte weight) {
  if (DEBUG) {
    Serial.print("Training: ");
    Serial.print(CATEGORIES[category - 1]);
    Serial.print(" | Height = ");
    Serial.print(height);
    Serial.print(" cm, Weight = ");
    Serial.print(weight);
    Serial.println(" kg");
  }

  CuriePME.beginLearning(category);
  CuriePME.write(height);
  CuriePME.write(weight);
  CuriePME.endLearning();

  if (DEBUG) {
    Serial.print("# of neuron's committed is now: ");
    Serial.println(CuriePME.neuronsCommitted());
  }
}

void classifyBMI(byte height, byte weight) {
  CuriePME.beginClassify();
  CuriePME.write(height);
  CuriePME.write(weight);
  int category = CuriePME.endClassify();

  Serial.print("Classifying: ");
  Serial.print("Height = ");
  Serial.print(height);
  Serial.print(" cm, Weight = ");
  Serial.print(weight);
  Serial.print(" kg | BMI category => ");

  if (category >= 1 && category <= NUM_CATEGORIES) {
    // known category, convert the number to category string and print;
    Serial.println(CATEGORIES[category - 1]);
  } else {
    Serial.println("Unknown");
  }
}

