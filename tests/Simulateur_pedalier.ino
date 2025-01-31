int valeur = 0;
void setup() {
  Serial.begin(9600); // port série à 9600 bauds
}

void loop() {
  valeur += 10;
  valeur %= 1000;
  Serial.println(valeur);
  delay(500);
  
}
