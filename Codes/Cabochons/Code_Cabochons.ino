#include <Adafruit_NeoPixel.h>

#define PIN 3 // Pin où est connecté le strip NeoPixel
#define NUM_LEDS 7  // Nombre de LEDs

// Configuration de la bande LED (NeoPixel)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800);

int acquis_donnees = 0;

void setup() {
  strip.begin(); // Initialisation du strip
  strip.setBrightness(50); // Luminosité initiale (0-255)
  strip.show(); // S'assurer que toutes les LEDs sont éteintes au départ
  Serial.begin(9600);
  Serial.println("Appuyez sur 1 pour garder en violet, 2 pour le fade, 3 pour le 3 par 3 :");

  mettre_en_violet();
 
}

void loop() {


  if (Serial.available() != 0){

    acquis_donnees = Serial.parseInt();
    Serial.println("Appuyez sur 1 pour garder en violet, 2 pour le fade, 3 pour le 3 par 3 :");
    Serial.println(acquis_donnees);
    Serial.read(); 

  
  }

  switch(acquis_donnees){
    case 1 : mettre_en_violet(); break;
    case 2 : random_fade(); break;
    case 3 : trwa_par_trwa(); break;
  }

}

// Fonction pour calculer une intensité sinusoïdale
static uint8_t sine8(uint8_t x) {
  return pgm_read_byte(&_NeoPixelSineTable[x]); // Entrée/sortie entre 0-255
}

void mettre_en_violet(){
  for (int k = 0; k < NUM_LEDS; k++) {
      strip.setPixelColor(k, strip.Color(127, 0, 255));
      
  }

  strip.show();
  

}

void random_fade(){
// Animation du dégradé coloré
  for (uint8_t i = 0; i < 255; i++) {
    // Calculer les couleurs pour chaque LED
    for (int ledNumber = 0; ledNumber < NUM_LEDS; ledNumber++) {
      // Ajuster la phase pour chaque LED pour un dégradé fluide
      uint8_t offset = ledNumber * 85; // Décalage de phase pour 3 LEDs
      uint8_t red = sine8(i + offset);      // Composante rouge
      uint8_t green = sine8(i + offset + 85);  // Composante verte
      uint8_t blue = sine8(i + offset + 170); // Composante bleue

      // Appliquer la couleur calculée
      strip.setPixelColor(ledNumber, red, green, blue);
    }

    // Mettre à jour le strip LED
    strip.show();
    delay(3); // Attente pour un effet fluide
  }

}

void trwa_par_trwa(){

 for (int j = -1; j < NUM_LEDS; j++) {
     
          strip.setPixelColor(j, strip.Color(127, 0, 255));
          delay(25);
          strip.show();
          strip.setPixelColor(j+1, strip.Color(255, 255, 0));
          delay(25);
          strip.show();
          strip.setPixelColor(j+2, strip.Color(255, 255, 255));
          delay(25);
          strip.show();
          strip.setPixelColor(j+3, strip.Color(255, 255, 0));
          delay(25);
          strip.setPixelColor(j, strip.Color(127, 0, 255));
          strip.show();
          
    }
    for (int j = -1; j < NUM_LEDS; j++) {
    
    }



}