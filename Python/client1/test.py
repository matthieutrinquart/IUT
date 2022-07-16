from tkinter import *
from cmath import sqrt

window = Tk()
solution = "Nothing to see for now ~"
a = Entry(window)
a.pack()
b = Entry(window)
b.pack()
c = Entry(window)
c.pack()

result_text = Text(window)
result_text.pack()
def calculate():
    na = int(a.get())
    nb = int(b.get())
    nc = int(c.get())
    delta = (nb **2) - (4 * na * nc )
    if delta > 0:
        x1 = ((- nb) + sqrt(delta)) / (2 * na)
        x2 = ((- nb) - sqrt(delta)) / (2 * na)
        solution = "x1 = " + str(x1) + "n x2 = " + str(x2)
        return  solution
    elif delta==0:
        x = (-nb) / (2 * na)
        solution = "x1 = " + str(x)
        return solution
    else:
        solution = "There isn t any solution for this equation."
        return solution

button = Button(window , text = "Calculate" , command = calculate)
button.pack()
result_text.insert(END,solution)
mainloop()