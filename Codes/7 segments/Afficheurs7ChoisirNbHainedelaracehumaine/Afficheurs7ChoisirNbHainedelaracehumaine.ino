// définition des broches du décodeur 7 segments
const int bit_A = 2;
const int bit_B = 3;
const int bit_C = 4;
const int bit_D = 5;

// définitions des broches des transistors pour chaque afficheur
const int alim_centaine = 8; // les centaines
const int alim_dizaine = 6;  // les dizaines
const int alim_unite = 7;    // les unités

// Variables
int afficheur = 0;         // 0: unités, 1: dizaines, 2: centaines
long tempsaffichage = 0;   // Pour l'alternance des afficheurs
int valeur = 0;            // Valeur à afficher (entre 0 et 999)

void setup()
{
    // Initialisation des broches
    pinMode(bit_A, OUTPUT);
    pinMode(bit_B, OUTPUT);
    pinMode(bit_C, OUTPUT);
    pinMode(bit_D, OUTPUT);
    pinMode(alim_centaine, OUTPUT);
    pinMode(alim_dizaine, OUTPUT);
    pinMode(alim_unite, OUTPUT);

    // Mise des broches à l'état bas
    digitalWrite(bit_A, LOW);
    digitalWrite(bit_B, LOW);
    digitalWrite(bit_C, LOW);
    digitalWrite(bit_D, LOW);
    digitalWrite(alim_centaine, LOW);
    digitalWrite(alim_dizaine, LOW);
    digitalWrite(alim_unite, LOW);

    // Démarrage de la communication série
    Serial.begin(9600);
    Serial.println("Entrez un nombre entre 0 et 999 :");
}

void loop()
{
    // Vérification d'une entrée utilisateur via la console série
    if (Serial.available() > 0)
    {
        String input = Serial.readStringUntil('\n'); // Lecture jusqu'à un saut de ligne
        int newValue = input.toInt();               // Conversion en entier

        // Validation de l'entrée
        if (newValue >= 0 && newValue <= 999)
        {
            valeur = newValue;
            Serial.print("Valeur acceptée : ");
            Serial.println(valeur);
        }
        else
        {
            Serial.println("Erreur : Entrez un nombre entre 0 et 999 !");
        }
    }

    // Gestion du rafraîchissement des afficheurs
    if ((millis() - tempsaffichage) > 5)
    {
        afficheur = (afficheur + 1) % 3; // Alterne entre unités, dizaines et centaines
        afficher_nombre(valeur, afficheur);
        tempsaffichage = millis();
    }
}

// Fonction d'affichage pour un chiffre donné (0-9)
void afficher_nombre(int nombre, int afficheur)
{
    char unite = nombre % 10;               // Récupération des unités
    char dizaine = (nombre / 10) % 10;      // Récupération des dizaines
    char centaine = (nombre / 100) % 10;    // Récupération des centaines

    // Désactiver tous les afficheurs
    digitalWrite(alim_centaine, LOW);
    digitalWrite(alim_dizaine, LOW);
    digitalWrite(alim_unite, LOW);

    // Activer l'afficheur correspondant et afficher la valeur
    if (afficheur == 2) // Centaines
    {
        afficher(centaine);
        digitalWrite(alim_centaine, HIGH);
    }
    else if (afficheur == 1) // Dizaines
    {
        afficher(dizaine);
        digitalWrite(alim_dizaine, HIGH);
    }
    else // Unités
    {
        afficher(unite);
        digitalWrite(alim_unite, HIGH);
    }
}

// Fonction d'activation des segments pour afficher un chiffre donné
void afficher(char chiffre)
{
    digitalWrite(bit_A, LOW);
    digitalWrite(bit_B, LOW);
    digitalWrite(bit_C, LOW);
    digitalWrite(bit_D, LOW);

    if (chiffre >= 8)
    {
        digitalWrite(bit_D, HIGH);
        chiffre -= 8;
    }
    if (chiffre >= 4)
    {
        digitalWrite(bit_C, HIGH);
        chiffre -= 4;
    }
    if (chiffre >= 2)
    {
        digitalWrite(bit_B, HIGH);
        chiffre -= 2;
    }
    if (chiffre >= 1)
    {
        digitalWrite(bit_A, HIGH);
        chiffre -= 1;
    }
}
