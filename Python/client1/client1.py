import connexion_client
import Inscription_client
import conversation_client
from threading import Thread
import socket
import tkinter as tk  
hote = "192.168.1.59"
port = 443
connexion_avec_serveur = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connexion_avec_serveur.connect((hote, port))
print("Connexion établie avec le serveur sur le port {}".format(port))

msg_a_envoyer = b""
while msg_a_envoyer != b"fin":
    # Peut planter si vous tapez des caractères spéciaux
    connexion_avec_serveur.send(b"Connecter")
    print("je suis la")
    #conversation_client.affichage(connexion_avec_serveur)
    connexion_client.affichage(connexion_avec_serveur)
    print("je suis la fin")


print("Fermeture de la connexion")
connexion_avec_serveur.close()