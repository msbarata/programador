from tkinter import *

janela = Tk()
janela.geometry('300x250')
janela.config( bg="lightblue")

Label(
	janela,
	text="Insira um texto abaixo e clique em mostrar:",
	font=("Arial", 11, "underline") ).pack(pady=10)
entrada = Entry(janela, width=50,bg="white")
entrada.pack()

def mostrar():
    texto = entrada.get()
    label.config(text=texto) 

label = Label(janela, text="")
label.pack(pady=10)

Button(janela, text="Mostrar", command=mostrar).pack()


janela.mainloop()