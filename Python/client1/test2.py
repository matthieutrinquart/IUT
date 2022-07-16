from tkinter import *
 
texte_label = "Hello"
 
master = Tk()
 
mon_entree = StringVar()
mon_entree.set(texte_label)
 
mon_label = Label(master, textvariable=mon_entree)
mon_label.pack()
 
 
entry=Entry(master, textvariable=mon_entree)
entry.pack()
 
master.mainloop()