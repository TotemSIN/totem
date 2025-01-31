#include <FastLED.h>

// Configuration des LEDs
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    35          // Mets ici le nombre de groupes de LEDs
#define MAX_VALUE   250
#define BRIGHTNESS  200
#define LED_PIN     3

// Variables globales
CRGB leds[NUM_LEDS];
int currentValue = 0;

void setup() {
  // Initialisation du Serial Monitor
  Serial.begin(9600);

  // Initialisation du ruban LED
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  // Nettoie les LEDs au démarrage
  FastLED.clear();
  FastLED.show();

  // Affiche la jauge initiale
  updateGauge();
}

void loop() {
  // Vérifie si une nouvelle donnée est disponible via le Serial Monitor
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Lire jusqu'à un saut de ligne
    input.trim();                               // Nettoyer les espaces superflus
    
    // Vérifie si l'entrée est un nombre valide
    if (isNumeric(input)) {
      int newValue = input.toInt();

      // Si la valeur est valide (entre 0 et MAX_VALUE)
      if (newValue >= 0 && newValue <= MAX_VALUE) {
        
        currentValue = newValue; // Mets à jour la valeur actuelle

        // Mets à jour les LEDs
        updateGauge();
      } else {
        Serial.println("error plage.");
      }
    } else {
      Serial.println("error");
    }
  }
}

// Fonction pour vérifier si une chaîne est un nombre valide
bool isNumeric(String str) {
  for (char c : str) {
    if (!isDigit(c)) return false;
  }
  return true;
}

// Fonction pour mettre à jour la jauge
void updateGauge() {
  FastLED.clear(); // Efface toutes les LEDs avant la mise à jour

  int threshold = MAX_VALUE / NUM_LEDS; // Chaque LED correspond à un "seuil" de la jauge

  for (int i = 0; i < NUM_LEDS; i++) {
    float progress = float(currentValue - (threshold * i)) / threshold;
    progress = constrain(progress, 0.0, 1.0);

    if (progress > 0.0) {
      leds[i] = getColorGradient(i, NUM_LEDS); // Mets la bonne couleur en fonction de l'index
    } else {
      leds[i] = CRGB::Black; // Éteint les LEDs non concernées
    }
  }

  FastLED.show(); // Mets à jour l'affichage des LEDs
  delay(10);      // Petite pause pour éviter les corruptions de données
}

// Fonction pour générer un dégradé dynamique (bleu -> rouge -> vert)
CRGB getColorGradient(int ledIndex, int totalLeds) {
  float position = float(ledIndex) / (totalLeds - 1);

  uint8_t red, green, blue;

  if (position < 0.5) {
    blue = map(position * 255, 0, 127, 255, 0);
    red = map(position * 255, 0, 127, 0, 255);
    green = 0;
  } else {
    red = map(position * 255, 127, 255, 255, 0);
    green = map(position * 255, 127, 255, 0, 255);
    blue = 0;
  }

  return CRGB(red, green, blue);
}
