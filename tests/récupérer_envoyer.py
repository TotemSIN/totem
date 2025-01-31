import serial

########## configuration des connexion série 
port_pedalier = '/dev/ttyACM0'
baudrate = 9600  ########### regarder si c'est bien le bon baudrate
port_out = '/dev/ttyACM1'

try:
    # ouverture de la connexion sur les différent port 
    ser = serial.Serial(port_pedalier, baudrate, timeout=1)
    print(f"Connexion sur le {port_pedalier} réussie")
    
    port_out1 = serial.Serial(port_out, baudrate, timeout=1)
    print(f"connexion  COM {port_out1} réussie")
    # Lecture des données
    print("En attente du nombre")
    
    while True:
        if ser.in_waiting > 0:
            # lire le nombre
            data = ser.readline().decode('utf-8').strip() #######permet de lire le nombre ressus
            try:
                number = int(data)  # permet de le convertir en entier 
                print(f"Nombre reçu : {number}")
                try:
                    port_out1.write(f"{number}\n".encode()) #### pour envoyer sur l'autre port
                    print(f"Envoyé au premier port : {number}")
                except Exception as e:
                    print(f"Erreur d'envoi au deuxième port : {e}")
            except ValueError:  # si la donnée reçue n'est pas valide
                print(f"Donnée non valide : {data}")

except serial.SerialException as e:  # erreur de connexion sur un des port 
    print(f"Erreur de connexion : {e}")

finally:  # fermeture des connexion
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("Connexion fermée")
    if 'port_out1' in locals() and port_out1.is_open:
        port_out1.close()
        print("Connexion au second port fermée")
