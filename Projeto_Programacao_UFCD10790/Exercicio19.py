from tkinter import *

janela = Tk()
janela.geometry('300x350')
janela.config( bg="lightblue")

var = StringVar() #StringVar(), BooleanVar()

var.set("Phyton")

Radiobutton(janela, text="Python", variable=var, value="Python").pack()
Radiobutton(janela, text="Java", variable=var, value="Java").pack()
Radiobutton(janela, text="C++", variable=var, value="C++").pack()

def confirmar():
    valor = var.get()
    label.config(text=f"Valor: {valor}") 


label = Label(janela, text="")
label.pack(pady=10)


Button(janela, text="Confirmar", command=confirmar).pack()

janela.mainloop()