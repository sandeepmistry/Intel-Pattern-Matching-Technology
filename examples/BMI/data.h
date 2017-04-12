// BMI categories
const int UNDERWEIGHT     = 1;
const int HEALTHY         = 2;
const int OVERWEIGHT      = 3;
const int OBESE           = 4;
const int EXTREMELY_OBESE = 5;

const int NUM_CATEGORIES = 5;

const String CATEGORIES[NUM_CATEGORIES] = {
  "Underweight",
  "Healthy",
  "Overweight",
  "Obese",
  "Extremely Obese"
};


// BMI category data table
const int CATEGORY_INDEX = 0;
const int HEIGHT_INDEX   = 1;
const int WEIGHT_INDEX   = 2;

const int BMI_TABLE_ENTRY_COUNT = 588;

// data from: https://bmicalculator.mes.fm/bmi-chart
const byte BMI_TABLE[BMI_TABLE_ENTRY_COUNT][3] = {
  // category, height (cm), weight (kg)
  {HEALTHY,         142, 41},
  {HEALTHY,         142, 45},
  {OVERWEIGHT,      142, 50},
  {OVERWEIGHT,      142, 54},
  {OVERWEIGHT,      142, 59},
  {OBESE,           142, 64},
  {OBESE,           142, 68},
  {OBESE,           142, 73},
  {OBESE,           142, 77},
  {EXTREMELY_OBESE, 142, 82},
  {EXTREMELY_OBESE, 142, 86},
  {EXTREMELY_OBESE, 142, 91},
  {EXTREMELY_OBESE, 142, 95},
  {EXTREMELY_OBESE, 142, 100},
  {EXTREMELY_OBESE, 142, 104},
  {EXTREMELY_OBESE, 142, 109},
  {EXTREMELY_OBESE, 142, 113},
  {EXTREMELY_OBESE, 142, 118},
  {EXTREMELY_OBESE, 142, 122},
  {EXTREMELY_OBESE, 142, 127},
  {EXTREMELY_OBESE, 142, 132},

  {HEALTHY,         145, 41},
  {HEALTHY,         145, 45},
  {HEALTHY,         145, 50},
  {OVERWEIGHT,      145, 54},
  {OVERWEIGHT,      145, 59},
  {OBESE,           145, 64},
  {OBESE,           145, 68},
  {OBESE,           145, 73},
  {OBESE,           145, 77},
  {OBESE,           145, 82},
  {EXTREMELY_OBESE, 145, 86},
  {EXTREMELY_OBESE, 145, 91},
  {EXTREMELY_OBESE, 145, 95},
  {EXTREMELY_OBESE, 145, 100},
  {EXTREMELY_OBESE, 145, 104},
  {EXTREMELY_OBESE, 145, 109},
  {EXTREMELY_OBESE, 145, 113},
  {EXTREMELY_OBESE, 145, 118},
  {EXTREMELY_OBESE, 145, 122},
  {EXTREMELY_OBESE, 145, 127},
  {EXTREMELY_OBESE, 145, 132},

  {HEALTHY,         147, 41},
  {HEALTHY,         147, 45},
  {HEALTHY,         147, 50},
  {OVERWEIGHT,      147, 54},
  {OVERWEIGHT,      147, 59},
  {OVERWEIGHT,      147, 64},
  {OBESE,           147, 68},
  {OBESE,           147, 73},
  {OBESE,           147, 77},
  {OBESE,           147, 82},
  {EXTREMELY_OBESE, 147, 86},
  {EXTREMELY_OBESE, 147, 91},
  {EXTREMELY_OBESE, 147, 95},
  {EXTREMELY_OBESE, 147, 100},
  {EXTREMELY_OBESE, 147, 104},
  {EXTREMELY_OBESE, 147, 109},
  {EXTREMELY_OBESE, 147, 113},
  {EXTREMELY_OBESE, 147, 118},
  {EXTREMELY_OBESE, 147, 122},
  {EXTREMELY_OBESE, 147, 127},
  {EXTREMELY_OBESE, 147, 132},

  {UNDERWEIGHT,     150, 41},
  {HEALTHY,         150, 45},
  {HEALTHY,         150, 50},
  {HEALTHY,         150, 54},
  {OVERWEIGHT,      150, 59},
  {OVERWEIGHT,      150, 64},
  {OBESE,           150, 68},
  {OBESE,           150, 73},
  {OBESE,           150, 77},
  {OBESE,           150, 82},
  {OBESE,           150, 86},
  {EXTREMELY_OBESE, 150, 91},
  {EXTREMELY_OBESE, 150, 95},
  {EXTREMELY_OBESE, 150, 100},
  {EXTREMELY_OBESE, 150, 104},
  {EXTREMELY_OBESE, 150, 109},
  {EXTREMELY_OBESE, 150, 113},
  {EXTREMELY_OBESE, 150, 118},
  {EXTREMELY_OBESE, 150, 122},
  {EXTREMELY_OBESE, 150, 127},
  {EXTREMELY_OBESE, 150, 132},

  {UNDERWEIGHT,     152, 41},
  {HEALTHY,         152, 45},
  {HEALTHY,         152, 50},
  {HEALTHY,         152, 54},
  {OVERWEIGHT,      152, 59},
  {OVERWEIGHT,      152, 64},
  {OVERWEIGHT,      152, 68},
  {OBESE,           152, 73},
  {OBESE,           152, 77},
  {OBESE,           152, 82},
  {OBESE,           152, 86},
  {OBESE,           152, 91},
  {EXTREMELY_OBESE, 152, 95},
  {EXTREMELY_OBESE, 152, 100},
  {EXTREMELY_OBESE, 152, 104},
  {EXTREMELY_OBESE, 152, 109},
  {EXTREMELY_OBESE, 152, 113},
  {EXTREMELY_OBESE, 152, 118},
  {EXTREMELY_OBESE, 152, 122},
  {EXTREMELY_OBESE, 152, 127},
  {EXTREMELY_OBESE, 152, 132},

  {UNDERWEIGHT,     155, 41},
  {HEALTHY,         155, 45},
  {HEALTHY,         155, 50},
  {HEALTHY,         155, 54},
  {OVERWEIGHT,      155, 59},
  {OVERWEIGHT,      155, 64},
  {OVERWEIGHT,      155, 68},
  {OBESE,           155, 73},
  {OBESE,           155, 77},
  {OBESE,           155, 82},
  {OBESE,           155, 86},
  {OBESE,           155, 91},
  {EXTREMELY_OBESE, 155, 95},
  {EXTREMELY_OBESE, 155, 100},
  {EXTREMELY_OBESE, 155, 104},
  {EXTREMELY_OBESE, 155, 109},
  {EXTREMELY_OBESE, 155, 113},
  {EXTREMELY_OBESE, 155, 118},
  {EXTREMELY_OBESE, 155, 122},
  {EXTREMELY_OBESE, 155, 127},
  {EXTREMELY_OBESE, 155, 132},

  {UNDERWEIGHT,     157, 41},
  {UNDERWEIGHT,     157, 45},
  {HEALTHY,         157, 50},
  {HEALTHY,         157, 54},
  {HEALTHY,         157, 59},
  {OVERWEIGHT,      157, 64},
  {OVERWEIGHT,      157, 68},
  {OVERWEIGHT,      157, 73},
  {OBESE,           157, 77},
  {OBESE,           157, 82},
  {OBESE,           157, 86},
  {OBESE,           157, 91},
  {OBESE,           157, 95},
  {EXTREMELY_OBESE, 157, 100},
  {EXTREMELY_OBESE, 157, 104},
  {EXTREMELY_OBESE, 157, 109},
  {EXTREMELY_OBESE, 157, 113},
  {EXTREMELY_OBESE, 157, 118},
  {EXTREMELY_OBESE, 157, 122},
  {EXTREMELY_OBESE, 157, 127},
  {EXTREMELY_OBESE, 157, 132},

  {UNDERWEIGHT,     160, 41},
  {UNDERWEIGHT,     160, 45},
  {HEALTHY,         160, 50},
  {HEALTHY,         160, 54},
  {HEALTHY,         160, 59},
  {OVERWEIGHT,      160, 64},
  {OVERWEIGHT,      160, 68},
  {OVERWEIGHT,      160, 73},
  {OBESE,           160, 77},
  {OBESE,           160, 82},
  {OBESE,           160, 86},
  {OBESE,           160, 91},
  {OBESE,           160, 95},
  {OBESE,           160, 100},
  {EXTREMELY_OBESE, 160, 104},
  {EXTREMELY_OBESE, 160, 109},
  {EXTREMELY_OBESE, 160, 113},
  {EXTREMELY_OBESE, 160, 118},
  {EXTREMELY_OBESE, 160, 122},
  {EXTREMELY_OBESE, 160, 127},
  {EXTREMELY_OBESE, 160, 132},

  {UNDERWEIGHT,     163, 41},
  {UNDERWEIGHT,     163, 45},
  {HEALTHY,         163, 50},
  {HEALTHY,         163, 54},
  {HEALTHY,         163, 59},
  {HEALTHY,         163, 64},
  {OVERWEIGHT,      163, 68},
  {OVERWEIGHT,      163, 73},
  {OVERWEIGHT,      163, 77},
  {OBESE,           163, 82},
  {OBESE,           163, 86},
  {OBESE,           163, 91},
  {OBESE,           163, 95},
  {OBESE,           163, 100},
  {OBESE,           163, 104},
  {EXTREMELY_OBESE, 163, 109},
  {EXTREMELY_OBESE, 163, 113},
  {EXTREMELY_OBESE, 163, 118},
  {EXTREMELY_OBESE, 163, 122},
  {EXTREMELY_OBESE, 163, 127},
  {EXTREMELY_OBESE, 163, 132},

  {UNDERWEIGHT,     165, 41},
  {UNDERWEIGHT,     165, 45},
  {UNDERWEIGHT,     165, 50},
  {HEALTHY,         165, 54},
  {HEALTHY,         165, 59},
  {HEALTHY,         165, 64},
  {OVERWEIGHT,      165, 68},
  {OVERWEIGHT,      165, 73},
  {OVERWEIGHT,      165, 77},
  {OBESE,           165, 82},
  {OBESE,           165, 86},
  {OBESE,           165, 91},
  {OBESE,           165, 95},
  {OBESE,           165, 100},
  {OBESE,           165, 104},
  {EXTREMELY_OBESE, 165, 109},
  {EXTREMELY_OBESE, 165, 113},
  {EXTREMELY_OBESE, 165, 118},
  {EXTREMELY_OBESE, 165, 122},
  {EXTREMELY_OBESE, 165, 127},
  {EXTREMELY_OBESE, 165, 132},

  {UNDERWEIGHT,     168, 41},
  {UNDERWEIGHT,     168, 45},
  {UNDERWEIGHT,     168, 50},
  {HEALTHY,         168, 54},
  {HEALTHY,         168, 59},
  {HEALTHY,         168, 64},
  {HEALTHY,         168, 68},
  {OVERWEIGHT,      168, 73},
  {OVERWEIGHT,      168, 77},
  {OVERWEIGHT,      168, 82},
  {OBESE,           168, 86},
  {OBESE,           168, 91},
  {OBESE,           168, 95},
  {OBESE,           168, 100},
  {OBESE,           168, 104},
  {OBESE,           168, 109},
  {EXTREMELY_OBESE, 168, 113},
  {EXTREMELY_OBESE, 168, 118},
  {EXTREMELY_OBESE, 168, 122},
  {EXTREMELY_OBESE, 168, 127},
  {EXTREMELY_OBESE, 168, 132},

  {UNDERWEIGHT,     170, 41},
  {UNDERWEIGHT,     170, 45},
  {UNDERWEIGHT,     170, 50},
  {HEALTHY,         170, 54},
  {HEALTHY,         170, 59},
  {HEALTHY,         170, 64},
  {HEALTHY,         170, 68},
  {OVERWEIGHT,      170, 73},
  {OVERWEIGHT,      170, 77},
  {OVERWEIGHT,      170, 82},
  {OBESE,           170, 86},
  {OBESE,           170, 91},
  {OBESE,           170, 95},
  {OBESE,           170, 100},
  {OBESE,           170, 104},
  {OBESE,           170, 109},
  {OBESE,           170, 113},
  {EXTREMELY_OBESE, 170, 118},
  {EXTREMELY_OBESE, 170, 122},
  {EXTREMELY_OBESE, 170, 127},
  {EXTREMELY_OBESE, 170, 132},

  {UNDERWEIGHT,     173, 41},
  {UNDERWEIGHT,     173, 45},
  {UNDERWEIGHT,     173, 50},
  {UNDERWEIGHT,     173, 54},
  {HEALTHY,         173, 59},
  {HEALTHY,         173, 64},
  {HEALTHY,         173, 68},
  {HEALTHY,         173, 73},
  {OVERWEIGHT,      173, 77},
  {OVERWEIGHT,      173, 82},
  {OVERWEIGHT,      173, 86},
  {OBESE,           173, 91},
  {OBESE,           173, 95},
  {OBESE,           173, 100},
  {OBESE,           173, 104},
  {OBESE,           173, 109},
  {OBESE,           173, 113},
  {EXTREMELY_OBESE, 173, 118},
  {EXTREMELY_OBESE, 173, 122},
  {EXTREMELY_OBESE, 173, 127},
  {EXTREMELY_OBESE, 173, 132},

  {UNDERWEIGHT,     175, 41},
  {UNDERWEIGHT,     175, 45},
  {UNDERWEIGHT,     175, 50},
  {UNDERWEIGHT,     175, 54},
  {HEALTHY,         175, 59},
  {HEALTHY,         175, 64},
  {HEALTHY,         175, 68},
  {HEALTHY,         175, 73},
  {OVERWEIGHT,      175, 77},
  {OVERWEIGHT,      175, 82},
  {OVERWEIGHT,      175, 86},
  {OBESE,           175, 91},
  {OBESE,           175, 95},
  {OBESE,           175, 100},
  {OBESE,           175, 104},
  {OBESE,           175, 109},
  {OBESE,           175, 113},
  {OBESE,           175, 118},
  {EXTREMELY_OBESE, 175, 122},
  {EXTREMELY_OBESE, 175, 127},
  {EXTREMELY_OBESE, 175, 132},

  {UNDERWEIGHT,     178, 41},
  {UNDERWEIGHT,     178, 45},
  {UNDERWEIGHT,     178, 50},
  {UNDERWEIGHT,     178, 54},
  {HEALTHY,         178, 59},
  {HEALTHY,         178, 64},
  {HEALTHY,         178, 68},
  {HEALTHY,         178, 73},
  {HEALTHY,         178, 77},
  {OVERWEIGHT,      178, 82},
  {OVERWEIGHT,      178, 86},
  {OVERWEIGHT,      178, 91},
  {OBESE,           178, 95},
  {OBESE,           178, 100},
  {OBESE,           178, 104},
  {OBESE,           178, 109},
  {OBESE,           178, 113},
  {OBESE,           178, 118},
  {OBESE,           178, 122},
  {EXTREMELY_OBESE, 178, 127},
  {EXTREMELY_OBESE, 178, 132},

  {UNDERWEIGHT,     180, 41},
  {UNDERWEIGHT,     180, 45},
  {UNDERWEIGHT,     180, 50},
  {UNDERWEIGHT,     180, 54},
  {UNDERWEIGHT,     180, 59},
  {HEALTHY,         180, 64},
  {HEALTHY,         180, 68},
  {HEALTHY,         180, 73},
  {HEALTHY,         180, 77},
  {OVERWEIGHT,      180, 82},
  {OVERWEIGHT,      180, 86},
  {OVERWEIGHT,      180, 91},
  {OVERWEIGHT,      180, 95},
  {OBESE,           180, 100},
  {OBESE,           180, 104},
  {OBESE,           180, 109},
  {OBESE,           180, 113},
  {OBESE,           180, 118},
  {OBESE,           180, 122},
  {OBESE,           180, 127},
  {EXTREMELY_OBESE, 180, 132},

  {UNDERWEIGHT,     183, 41},
  {UNDERWEIGHT,     183, 45},
  {UNDERWEIGHT,     183, 50},
  {UNDERWEIGHT,     183, 54},
  {UNDERWEIGHT,     183, 59},
  {HEALTHY,         183, 64},
  {HEALTHY,         183, 68},
  {HEALTHY,         183, 73},
  {HEALTHY,         183, 77},
  {HEALTHY,         183, 82},
  {OVERWEIGHT,      183, 86},
  {OVERWEIGHT,      183, 91},
  {OVERWEIGHT,      183, 95},
  {OBESE,           183, 100},
  {OBESE,           183, 104},
  {OBESE,           183, 109},
  {OBESE,           183, 113},
  {OBESE,           183, 118},
  {OBESE,           183, 122},
  {OBESE,           183, 127},
  {OBESE,           183, 132},

  {UNDERWEIGHT,     185, 41},
  {UNDERWEIGHT,     185, 45},
  {UNDERWEIGHT,     185, 50},
  {UNDERWEIGHT,     185, 54},
  {UNDERWEIGHT,     185, 59},
  {UNDERWEIGHT,     185, 64},
  {HEALTHY,         185, 68},
  {HEALTHY,         185, 73},
  {HEALTHY,         185, 77},
  {HEALTHY,         185, 82},
  {OVERWEIGHT,      185, 86},
  {OVERWEIGHT,      185, 91},
  {OVERWEIGHT,      185, 95},
  {OVERWEIGHT,      185, 100},
  {OBESE,           185, 104},
  {OBESE,           185, 109},
  {OBESE,           185, 113},
  {OBESE,           185, 118},
  {OBESE,           185, 122},
  {OBESE,           185, 127},
  {OBESE,           185, 132},

  {UNDERWEIGHT,     188, 41},
  {UNDERWEIGHT,     188, 45},
  {UNDERWEIGHT,     188, 50},
  {UNDERWEIGHT,     188, 54},
  {UNDERWEIGHT,     188, 59},
  {UNDERWEIGHT,     188, 64},
  {HEALTHY,         188, 68},
  {HEALTHY,         188, 73},
  {HEALTHY,         188, 77},
  {HEALTHY,         188, 82},
  {HEALTHY,         188, 86},
  {OVERWEIGHT,      188, 91},
  {OVERWEIGHT,      188, 95},
  {OVERWEIGHT,      188, 100},
  {OBESE,           188, 104},
  {OBESE,           188, 109},
  {OBESE,           188, 113},
  {OBESE,           188, 118},
  {OBESE,           188, 122},
  {OBESE,           188, 127},
  {OBESE,           188, 132},

  {UNDERWEIGHT,     191, 41},
  {UNDERWEIGHT,     191, 45},
  {UNDERWEIGHT,     191, 50},
  {UNDERWEIGHT,     191, 54},
  {UNDERWEIGHT,     191, 59},
  {UNDERWEIGHT,     191, 64},
  {HEALTHY,         191, 68},
  {HEALTHY,         191, 73},
  {HEALTHY,         191, 77},
  {HEALTHY,         191, 82},
  {HEALTHY,         191, 86},
  {OVERWEIGHT,      191, 91},
  {OVERWEIGHT,      191, 95},
  {OVERWEIGHT,      191, 100},
  {OVERWEIGHT,      191, 104},
  {OBESE,           191, 109},
  {OBESE,           191, 113},
  {OBESE,           191, 118},
  {OBESE,           191, 122},
  {OBESE,           191, 127},
  {OBESE,           191, 132},

  {UNDERWEIGHT,     193, 41},
  {UNDERWEIGHT,     193, 45},
  {UNDERWEIGHT,     193, 50},
  {UNDERWEIGHT,     193, 54},
  {UNDERWEIGHT,     193, 59},
  {UNDERWEIGHT,     193, 64},
  {UNDERWEIGHT,     193, 68},
  {HEALTHY,         193, 73},
  {HEALTHY,         193, 77},
  {HEALTHY,         193, 82},
  {HEALTHY,         193, 86},
  {HEALTHY,         193, 91},
  {OVERWEIGHT,      193, 95},
  {OVERWEIGHT,      193, 100},
  {OVERWEIGHT,      193, 104},
  {OVERWEIGHT,      193, 109},
  {OBESE,           193, 113},
  {OBESE,           193, 118},
  {OBESE,           193, 122},
  {OBESE,           193, 127},
  {OBESE,           193, 132},

  {UNDERWEIGHT,     196, 41},
  {UNDERWEIGHT,     196, 45},
  {UNDERWEIGHT,     196, 50},
  {UNDERWEIGHT,     196, 54},
  {UNDERWEIGHT,     196, 59},
  {UNDERWEIGHT,     196, 64},
  {UNDERWEIGHT,     196, 68},
  {HEALTHY,         196, 73},
  {HEALTHY,         196, 77},
  {HEALTHY,         196, 82},
  {HEALTHY,         196, 86},
  {HEALTHY,         196, 91},
  {OVERWEIGHT,      196, 95},
  {OVERWEIGHT,      196, 100},
  {OVERWEIGHT,      196, 104},
  {OVERWEIGHT,      196, 109},
  {OBESE,           196, 113},
  {OBESE,           196, 118},
  {OBESE,           196, 122},
  {OBESE,           196, 127},
  {OBESE,           196, 132},

  {UNDERWEIGHT,     198, 41},
  {UNDERWEIGHT,     198, 45},
  {UNDERWEIGHT,     198, 50},
  {UNDERWEIGHT,     198, 54},
  {UNDERWEIGHT,     198, 59},
  {UNDERWEIGHT,     198, 64},
  {UNDERWEIGHT,     198, 68},
  {UNDERWEIGHT,     198, 73},
  {HEALTHY,         198, 77},
  {HEALTHY,         198, 82},
  {HEALTHY,         198, 86},
  {HEALTHY,         198, 91},
  {HEALTHY,         198, 95},
  {OVERWEIGHT,      198, 100},
  {OVERWEIGHT,      198, 104},
  {OVERWEIGHT,      198, 109},
  {OVERWEIGHT,      198, 113},
  {OBESE,           198, 118},
  {OBESE,           198, 122},
  {OBESE,           198, 127},
  {OBESE,           198, 132},

  {UNDERWEIGHT,     201, 41},
  {UNDERWEIGHT,     201, 45},
  {UNDERWEIGHT,     201, 50},
  {UNDERWEIGHT,     201, 54},
  {UNDERWEIGHT,     201, 59},
  {UNDERWEIGHT,     201, 64},
  {UNDERWEIGHT,     201, 68},
  {UNDERWEIGHT,     201, 73},
  {HEALTHY,         201, 77},
  {HEALTHY,         201, 82},
  {HEALTHY,         201, 86},
  {HEALTHY,         201, 91},
  {HEALTHY,         201, 95},
  {OVERWEIGHT,      201, 100},
  {OVERWEIGHT,      201, 104},
  {OVERWEIGHT,      201, 109},
  {OVERWEIGHT,      201, 113},
  {OVERWEIGHT,      201, 118},
  {OBESE,           201, 122},
  {OBESE,           201, 127},
  {OBESE,           201, 132},

  {UNDERWEIGHT,     203, 41},
  {UNDERWEIGHT,     203, 45},
  {UNDERWEIGHT,     203, 50},
  {UNDERWEIGHT,     203, 54},
  {UNDERWEIGHT,     203, 59},
  {UNDERWEIGHT,     203, 64},
  {UNDERWEIGHT,     203, 68},
  {UNDERWEIGHT,     203, 73},
  {HEALTHY,         203, 77},
  {HEALTHY,         203, 82},
  {HEALTHY,         203, 86},
  {HEALTHY,         203, 91},
  {HEALTHY,         203, 95},
  {HEALTHY,         203, 100},
  {OVERWEIGHT,      203, 104},
  {OVERWEIGHT,      203, 109},
  {OVERWEIGHT,      203, 113},
  {OVERWEIGHT,      203, 118},
  {OBESE,           203, 122},
  {OBESE,           203, 127},
  {OBESE,           203, 132},

  {UNDERWEIGHT,     206, 41},
  {UNDERWEIGHT,     206, 45},
  {UNDERWEIGHT,     206, 50},
  {UNDERWEIGHT,     206, 54},
  {UNDERWEIGHT,     206, 59},
  {UNDERWEIGHT,     206, 64},
  {UNDERWEIGHT,     206, 68},
  {UNDERWEIGHT,     206, 73},
  {UNDERWEIGHT,     206, 77},
  {HEALTHY,         206, 82},
  {HEALTHY,         206, 86},
  {HEALTHY,         206, 91},
  {HEALTHY,         206, 95},
  {HEALTHY,         206, 100},
  {OVERWEIGHT,      206, 104},
  {OVERWEIGHT,      206, 109},
  {OVERWEIGHT,      206, 113},
  {OVERWEIGHT,      206, 118},
  {OVERWEIGHT,      206, 122},
  {OBESE,           206, 127},
  {OBESE,           206, 132},

  {UNDERWEIGHT,     208, 41},
  {UNDERWEIGHT,     208, 45},
  {UNDERWEIGHT,     208, 50},
  {UNDERWEIGHT,     208, 54},
  {UNDERWEIGHT,     208, 59},
  {UNDERWEIGHT,     208, 64},
  {UNDERWEIGHT,     208, 68},
  {UNDERWEIGHT,     208, 73},
  {UNDERWEIGHT,     208, 77},
  {HEALTHY,         208, 82},
  {HEALTHY,         208, 86},
  {HEALTHY,         208, 91},
  {HEALTHY,         208, 95},
  {HEALTHY,         208, 100},
  {HEALTHY,         208, 104},
  {OVERWEIGHT,      208, 109},
  {OVERWEIGHT,      208, 113},
  {OVERWEIGHT,      208, 118},
  {OVERWEIGHT,      208, 122},
  {OVERWEIGHT,      208, 127},
  {OBESE,           208, 132},

  {UNDERWEIGHT,     211, 41},
  {UNDERWEIGHT,     211, 45},
  {UNDERWEIGHT,     211, 50},
  {UNDERWEIGHT,     211, 54},
  {UNDERWEIGHT,     211, 59},
  {UNDERWEIGHT,     211, 64},
  {UNDERWEIGHT,     211, 68},
  {UNDERWEIGHT,     211, 73},
  {UNDERWEIGHT,     211, 77},
  {UNDERWEIGHT,     211, 82},
  {HEALTHY,         211, 86},
  {HEALTHY,         211, 91},
  {HEALTHY,         211, 95},
  {HEALTHY,         211, 100},
  {HEALTHY,         211, 104},
  {OVERWEIGHT,      211, 109},
  {OVERWEIGHT,      211, 113},
  {OVERWEIGHT,      211, 118},
  {OVERWEIGHT,      211, 122},
  {OVERWEIGHT,      211, 127},
  {OBESE,           211, 132},
};