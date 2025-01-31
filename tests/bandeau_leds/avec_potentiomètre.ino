#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 12             // Broche de la bande LED
#define NUMPIXELS 12       // Nombre total de LEDs
#define POT_PIN A0         // Broche du potentiomètre

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Définir les 10 couleurs RGB
struct RGB {
  int r, g, b;
};

RGB colors[10] = {
  {0, 255, 204},
  {128, 255, 0},  
  {255, 204, 0},  
  {255, 204, 0},
  {255, 128, 0},  
  {255, 51, 0},  
  {255, 0, 0},    
  {255, 0, 0}
};

void setup() {
  strip.begin();
  strip.setBrightness(20); // Luminosité
  strip.show();
}

void loop() {
  int potValue = analogRead(POT_PIN);                // Lire la valeur du potentiomètre (0-1023)
  int numLedsToLight = map(potValue, 0, 1023, 0, NUMPIXELS); // Calculer le nombre de LEDs allumées

  // Allumer chaque LED avec une couleur qui va du bleu au rouge, en passant par le vert et le jaune
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i < numLedsToLight) {
      // La couleur change progressivement en fonction de l'indice de la LED
      int currentColorIndex = (i * 9) / (NUMPIXELS - 1); // Calculer l'indice de couleur basé sur l'emplacement de la LED
      RGB selectedColor = colors[currentColorIndex]; // Sélectionne la couleur
      strip.setPixelColor(i, strip.Color(selectedColor.r, selectedColor.g, selectedColor.b)); // Applique la couleur
    } else {
      // Éteindre les LEDs restantes
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }

  strip.show();  // Met à jour les LEDs
  delay(50);     // Pause pour une transition fluide
}
