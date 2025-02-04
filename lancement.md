# Lancement de la tour

Hello, c'est Darlann et, si vous n'arrivez pas à préparer le Raspberry, voici les différentes étapes.


## Connexion au Raspberry

Pour se connecter au raspberry il faut utiliser l'adresse IP suivante: `192.168.1.90` en connexion SSH avec l'utilisateur `admin`.
Donc voici ce qu'il faut rentrer dans votre [invite de commande](https://fr.wikipedia.org/wiki/Cmd)

    ssh admin@192.168.1.90
   Celui ci va ensuite vous demander: 

> admin@192.168.1.90's password:

Le mot de passe est le suivant: `lachenal123`

## Lancement du programme de contrôle

Pour lancer le programme il faut tout d'abord lancer un [screen](https://fr.wikipedia.org/wiki/GNU_Screen) (c'est une console virtuelle qui permet de séparer le Raspberry en plusieurs processus distinct et qui permet de se déconnecter tout en continuant le programme).

    screen
   Une fois lancé vous pouvez lancer le programme de la manière suivante:
   

    ./controlTotem.py

Une fois lancé vous pouvez sortir du multi-processus en exécutant le combo de touche suivante:

    CTRL+A
    D
  
  Et voilà le programme est lancé et il ne vous reste plus qu'à utiliser le [site web](http://192.168.1.90)

Si besoin survient de se connecter nouveau au screen, la commande est la suivante:

    screen -r
