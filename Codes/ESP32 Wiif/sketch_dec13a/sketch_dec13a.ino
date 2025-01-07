#include <WiFi.h>

// Paramètres du réseau Wi-Fi
const char* ssid = "Totem_1";           // Remplace par ton SSID

// Configuration du serveur TCP
WiFiServer server(12345);

void setup() {
  Serial.begin(115200);  // Initialise le moniteur série

  // Connexion au Wi-Fi
  WiFi.begin(ssid);
  Serial.print("Connexion au Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnecté au réseau Wi-Fi");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());

  // Démarrage du serveur
  server.begin();
  Serial.println("Serveur TCP démarré. En attente de connexions...");
}

void loop() {
  // Vérifie si un client est connecté
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connecté !");
    while (client.connected()) {
      if (client.available()) {
        // Lit les données reçues jusqu'à '\n'
        String number = client.readStringUntil('\n');
        number.trim();  // Supprime les espaces ou sauts de ligne inutiles
        Serial.println("Nombre reçu : " + number);  // Affiche chaque nombre sur une nouvelle ligne
      }
    }
    Serial.println("Client déconnecté.");
  }
}