import tkinter as tk  
from tkinter import ttk
from functools import partial  
import socket
from threading import Thread
from ecoute_client import Client

global i 

def envoi(n1, connexion_avec_serveur):
    num1 = (n1.get())  
    connexion_avec_serveur.send(num1.encode())



def affichage(connexion_avec_serveur):

    def affichage_update():
        truc = Thread1.mot()
        if truc != "":
            truc = truc + '\n'
        Thread1.truc = ""
        T.insert(tk.END, truc)
        root.after(1000,affichage_update)
    def slider():
        o = ttk.Combobox(root, values=["ligne 1", "ligne 2", "ligne 3", "ligne 4"])
        o.pack()



    root = tk.Tk()  
    Thread1 = Client(connexion_avec_serveur)
    Thread1.start()
    root.geometry('700x500+100+200')
    root.title('Messageri')  
    Id = Thread1.mot()
    Thread1.truc = ""
    print(Id)
    liste = []
    while Thread1.truc != "fini":
        liste = [liste ,Thread1.mot()]
        connexion_avec_serveur.send(b"recu")
    print(liste)
    T=tk.Text(root, height=20, width=50)
    number1 = tk.StringVar()  
    entryNum1 = tk.Entry(root, textvariable=number1).pack()   
    result = partial(envoi ,number1 ,connexion_avec_serveur)
    buttonCal = tk.Button(root, text="affiche", command=result).pack()
    T.pack()
    label=tk.Label(root,text = Id)
    label.pack()
    affichage_update()
    slider()
    root.mainloop() 

