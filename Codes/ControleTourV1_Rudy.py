from websocket_server import WebsocketServer
import serial
import threading


BAUDRATE = 9600
PORT_IN = '/dev/ttyACM0'
PORT_JAUGE_LED = '/dev/ttyACM1'
PORT_CABUCHON_LED = '/dev/ttyACM2'

port_in = serial.Serial(PORT_IN, baudrate=BAUDRATE, timeout=1)
port_JAUGE_LED = serial.Serial(PORT_JAUGE_LED, baudrate=BAUDRATE, timeout=1)
port_CABUCHON_LED = serial.Serial(PORT_CABUCHON_LED, baudrate=BAUDRATE, timeout=1)

def new_client(client, server):
    print(f"Nouveau client connecté : {client['id']}")

def lire_port_serie():
    if port_in and port_in.in_waiting > 0:
        try:
            data = port_in.readline().decode().strip()
            if data.isdigit():
                return int(data)
        except Exception as e:
            print(f"Erreur de lecture du port série : {e}")
    return None

def envoyer_port_serie(data, port):
    if port:
        try:
            port.write(f"{data}\n".encode())
            print(f"Envoi sur port série : {data}")
        except Exception as e:
            print(f"Erreur lors de l'envoi sur le port série : {e}")



def send_data(server):
    data = lire_port_serie()
    if data is not None:
        print(f"Réception de {data} sur le port série")
        envoyer_port_serie(data, port_JAUGE_LED)
       	envoyer_port_serie(data, port_CABUCHON_LED)
        server.send_message_to_all(str(data))
        if server.clients:
            print(f"Donnée envoyée : {data}")

def send_periodic_data(server, interval=0.2):
    send_data(server)
    threading.Timer(interval, send_periodic_data, args=(server, interval)).start()

def start_server():
    server = WebsocketServer(host="localhost", port=22222)
    server.set_fn_new_client(new_client)
    send_periodic_data(server)

    server.run_forever()

if __name__ == "__main__":
    start_server()
