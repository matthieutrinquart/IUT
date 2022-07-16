import tkinter as tk  
from functools import partial  
import socket
import conversation_client
import Inscription_client

def call_result(n1, n2 , connexion_avec_serveur , root):  
    num1 = (n1.get())  
    num2 = (n2.get()) 
    connexion_avec_serveur.send(num1.encode())
    connexion_avec_serveur.send(num2.encode())
    commande=connexion_avec_serveur.recv(1024)
    commande = commande.decode()
    if commande == "mauvais":
        print("mauvais mdp ou nom")
    else:
        root.destroy()
        conversation_client.affichage(connexion_avec_serveur)

   
def affichage(connexion_avec_serveur):
    root = tk.Tk()  
    root.geometry('400x200+100+200')  
        
    root.title('connexion')  
        
    number1 = tk.StringVar()  
    number2 = tk.StringVar()  
        
    labelNum1 = tk.Label(root, text="Nom").grid(row=1, column=0)  
        
    labelNum2 = tk.Label(root, text="Mots de passe").grid(row=2, column=0)  
        
    labelResult = tk.Label(root)  
        
    labelResult.grid(row=7, column=2)  
        
    entryNum1 = tk.Entry(root, textvariable=number1).grid(row=1, column=2)  
        
    entryNum2 = tk.Entry(root, textvariable=number2).grid(row=2, column=2)  
        
    result = partial(call_result ,number1, number2 ,connexion_avec_serveur , root)  
    inscrire = partial(Inscription_client.affichage  ,connexion_avec_serveur)         
    buttonCal = tk.Button(root, text="s'inscrire", command=inscrire).grid(row=3, column=0)  

    buttonCal2 = tk.Button(root, text="envoyer", command=result).grid(row=3, column=1) 
        
    root.mainloop()  

