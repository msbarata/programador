from tkinter import *
from tkinter import ttk


janela = Tk()
janela.geometry("500x300")
janela.title("Contador")
janela.configure(bg="lightblue")

x = IntVar()
x.set(0)


Label(
	janela,
	text="Contador",
	font=("Arial", 12, "underline") ).pack(padx=15, pady=15) #padx -> Espaçamento horizontal interno, pady -> Espaçamento vertical interno.

def contar(event):
     x.set(x.get() + 1)

label_contador = Label(janela, textvariable=x, font=("Arial", 24, "bold"), bg="lightblue")
label_contador.pack(pady=5)

btn = Button(janela, text="Contar")
btn.pack(pady=10)
btn.bind("<Button-1>", contar)
janela.mainloop()