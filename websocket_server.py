from websocket_server import WebsocketServer
import random
import threading

def new_client(client, server):
    print(f"Nouveau client connecté : {client['id']}")
    send_data(server)

def send_data(server):
    data = random.randint(0, 1000)
    server.send_message_to_all(str(data))
    print(f"Donnée envoyée : {data}")

def send_periodic_data(server, interval=0.2):
    if server.clients:
        send_data(server)
    threading.Timer(interval, send_periodic_data, args=(server, interval)).start()

def start_server():
    server = WebsocketServer(host="localhost", port=22222)
    server.set_fn_new_client(new_client)
    send_periodic_data(server)

    server.run_forever()
    
if __name__ == "__main__":
    start_server()
