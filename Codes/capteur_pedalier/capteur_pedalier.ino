const int analogPin = A0;  

void setup() {
  // Initialiser le moniteur série à 9600 bauds
  Serial.begin(9600);
}

void loop() {
  // Lire la valeur analogique sur la broche A0 (valeur entre 0 et 1023)
  int analogValue = analogRead(analogPin);
  
  // Afficher la valeur lue sur le moniteur série
  float valeurintensite = 0;
  valeurintensite = (float(analogValue) - 512)/17 ;
  Serial.print("Valeur intensité :");
  Serial.println(valeurintensite);


  // Attendre un peu avant de relire (par exemple, 500 ms)
  delay(500);
}