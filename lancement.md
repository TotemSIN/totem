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
   
   ### Attention de bien tout débrancher vos ports avant le lancement du programme


    ./controlTotem.py

Une fois lancé vous pouvez sortir du multi-processus en exécutant le combo de touche suivante:

    CTRL+A
    D
  
  Et voilà le programme est lancé et il ne vous reste plus qu'à configurer les ports et à utiliser le [site web](http://192.168.1.90)

Si besoin survient de se connecter nouveau au screen, la commande est la suivante:

    screen -r

## Configuration des ports
Lors du lancement du programme celui ci va vous demandez de brancher tout les ports afin de déterminer quel ports effectue quel action.

Si vous avez oublié de débrancher les ports, fermez le programme, débranchez vos ports et relancez le programme.

Pour l'attribution des ports il vous suffit juste de suivre les instructions à l'écran en attendant bien le port à attribuer avant de le brancher.

Une fois fais vous êtes prêt à lancer une partie depuis le site web directement en entrant le nom du participant.

## Encore un problème ?
Je suis présent sur un stand le jeudi de 8h à 16h (sauf pause midi) et le vendredi de 13h à 16h.

Si il y a un très gros problème je suis en sports dans la salle des fête d'Argonay (vous vous débrouillez avec le prof de sports pour expliquer mdr)
