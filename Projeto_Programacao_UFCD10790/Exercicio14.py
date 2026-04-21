from tkinter import *
from tkinter import ttk


janela = Tk()
janela.geometry("500x300") 
janela.title("Contador Com decremento")
janela.configure(bg="lightblue")

x = IntVar()
x.set(0)

Label(
	janela,
	text="Contador com decremento",
	font=("Arial", 12, "underline") ).pack(padx=15, pady=15) #padx -> Espaçamento horizontal interno, pady -> Espaçamento vertical interno.

def incrementar(event):
     x.set(x.get() + 1)

def decrementar(event):
     x.set(x.get() - 1)

label_contador = Label(janela, textvariable=x, font=("Arial", 24, "bold"), bg="lightblue")
label_contador.pack(pady=5)

frame = Frame(janela)
frame.pack()

btn_mais = Button(frame, text="Incrementar")
btn_mais.pack(side=LEFT, padx=5)
btn_mais.bind("<Button-1>", incrementar)

btn_menos = Button(frame, text="Decrementar")
btn_menos.pack(side=LEFT, padx=5)
btn_menos.bind("<Button-1>", decrementar)


janela.mainloop()