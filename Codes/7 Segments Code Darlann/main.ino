int randomNumber, randomBis;
int centaine, dizaine, unite;
int old_c, old_d, old_u;
int pinState, startingPin;
int value, oldvalue;

void setup() {
  // Initialize pins 2, 3, 4, 5 as outputs
  for (int pin = 0; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // Ensure all pins are off initially
  }
  Serial.begin(9600);

  randomNumber = random(0, 1000);
  oldvalue = 0;

}

void loop() {

  String read = Serial.readStringUntil("/n");
  if (Serial.available() > 0) {
    String read = Serial.readStringUntil("/n");

  }

  value = read.toInt();
  if (value != oldvalue && value != 000) {
    oldvalue = value;
    randomNumber = oldvalue;
    centaine = randomNumber / 100;
    dizaine = (randomNumber / 10) % 10;
    unite = randomNumber % 10;

    if (unite != old_u) {
      setPinsForNumber(unite, 1);
      old_u = unite;
    }
    if (dizaine != old_d) {
      setPinsForNumber(dizaine, 2);
      old_d = dizaine;
    }
    if (centaine != old_c) {
      setPinsForNumber(centaine, 3);
      old_c = centaine;
    }
  }

  delay(1000 / 120);
}

// 157 -> 
// 1 -> 7_segment_3
// 5 -> 7 segment_2
// 7 -> 7_segment_1

void setPinsForNumber(int number, int segment) {
  if (number < 0 || number > 9) {
    return;
  }

  startingPin = (segment - 1) * 4 + 2;

  for (int i = 0; i < 4; i++) {
    pinState = (number >> i) & 1; // Extract the i-th bit
    digitalWrite(i + startingPin, pinState); // Set the corresponding pin (2, 3, 4, 5)
  }
  delay(200);
  Serial.print("Segment: ");
  Serial.println(segment);
  
  Serial.print("Valeur: ");
  Serial.println(number);
}
