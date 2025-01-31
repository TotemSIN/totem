/*

  Author : Triliaxy

  TODO : tests
  FIXME : 


*/


//var globales


/* Fonction setup() */
void setup() {

  /* Toutes les broches en sorties */

  //afficheur gauche
  pinMode(31, OUTPUT);
  digitalWrite(31, LOW);
  pinMode(23, OUTPUT);
  digitalWrite(23, LOW);
  pinMode(29, OUTPUT);
  digitalWrite(29, LOW);
  pinMode(25, OUTPUT);
  digitalWrite(25, LOW);
  pinMode(39, OUTPUT);
  digitalWrite(39, LOW);
  pinMode(35, OUTPUT);
  digitalWrite(35, LOW);
  pinMode(27, OUTPUT);
  digitalWrite(27, LOW);
  pinMode(37, OUTPUT);
  digitalWrite(37, LOW);

  //afficheur central
  pinMode(34, OUTPUT);
  digitalWrite(34, LOW);
  pinMode(22, OUTPUT);
  digitalWrite(22, LOW);
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  pinMode(24, OUTPUT);
  digitalWrite(24, LOW);
  pinMode(38, OUTPUT);
  digitalWrite(38, LOW);
  pinMode(30, OUTPUT);
  digitalWrite(30, LOW);
  pinMode(28, OUTPUT);
  digitalWrite(28, LOW);
  pinMode(36, OUTPUT);
  digitalWrite(36, LOW);

  //afficheur droit
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  // start serial port at 9600 bps:
  Serial.begin(9600);
  Serial.setTimeout(50);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

// FONCTION CHIFFRE

void chiffre0(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(39, HIGH);
    digitalWrite(23, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(22, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }
}


void chiffre1(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(29, HIGH);
    digitalWrite(35, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
  } else {
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
  }
}


void chiffre2(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(39, HIGH);
    digitalWrite(27, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(28, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
}


void chiffre3(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}


void chiffre4(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(29, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(32, HIGH);
  } else {
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
  }
}


void chiffre5(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}


void chiffre6(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(39, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(38, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }
}


void chiffre7(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(35, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(30, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
  }
}


void chiffre8(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(39, HIGH);
    digitalWrite(29, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(38, HIGH);
    digitalWrite(32, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(6, HIGH);
  }
}


void chiffre9(int afficheur) {
  if (afficheur == 0) {
    digitalWrite(31, HIGH);
    digitalWrite(23, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(29, HIGH);
  } else if (afficheur == 1) {
    digitalWrite(34, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(24, HIGH);
    digitalWrite(30, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(32, HIGH);
  } else {
    digitalWrite(7, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
  }
}


// FONCTION PRINCIPALE

void mainFunction() {

  if (Serial.available() > 0) {
    String donnees = Serial.readString();
    
    digitalWrite(31, LOW);
    digitalWrite(23, LOW);
    digitalWrite(29, LOW);
    digitalWrite(25, LOW);
    digitalWrite(39, LOW);
    digitalWrite(35, LOW);
    digitalWrite(27, LOW);
    digitalWrite(37, LOW);
    digitalWrite(34, LOW);
    digitalWrite(22, LOW);
    digitalWrite(32, LOW);
    digitalWrite(24, LOW);
    digitalWrite(38, LOW);
    digitalWrite(30, LOW);
    digitalWrite(28, LOW);
    digitalWrite(36, LOW);
    digitalWrite(7, LOW);
    digitalWrite(11, LOW);
    digitalWrite(6, LOW);
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(13, LOW);

    //Serial.print(donnees.length()); DEBUG -----------------------------
    
    while (donnees.length() < 3) {
      donnees = "0" + donnees;
    }


/*
    Serial.print(int(donnees[0]));
    Serial.print(int(donnees[1]));
    Serial.print(int(donnees[2]));
DEBUG-------------------------------------*/
    

    for (int compteur = 0; compteur < 3; compteur++) { 
      if (donnees[compteur] == '0') {
        chiffre0(compteur);
      } else if (donnees[compteur] == '1') {
        chiffre1(compteur);
      } else if (donnees[compteur] == '2') {
        chiffre2(compteur);
      } else if (donnees[compteur] == '3') {
        chiffre3(compteur);
      } else if (donnees[compteur] == '4') {
        chiffre4(compteur);
      } else if (donnees[compteur] == '5') {
        chiffre5(compteur);
      } else if (donnees[compteur] == '6') {
        chiffre6(compteur);
      } else if (donnees[compteur] == '7') {
        chiffre7(compteur);
      } else if (donnees[compteur] == '8') {
        chiffre8(compteur);
      } else if (donnees[compteur] == '9') {
        chiffre9(compteur);
      }
    }
  }
}


/** Fonction loop() */
void loop() {

  mainFunction();
 



  


}
