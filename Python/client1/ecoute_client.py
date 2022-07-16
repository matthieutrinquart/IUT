 
import threading
import socket
class Client(threading.Thread):
    truc = ""	
    def __init__(self, conn):
        threading.Thread.__init__(self)
        self.connexion = conn	   # socket de connexion
 


    def run(self):
        
        while True :
            commande=self.connexion.recv(1024)
            #ce qui tu as à faire avec cette commande
            commande = commande.decode()
            self.truc = commande
            
    def mot(self):
        return (self.truc)
#pour l'établissement des connexions, j'imagine que tu sais comment faire