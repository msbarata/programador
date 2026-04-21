from tkinter import *

janela = Tk()
janela.geometry('300x250')
janela.config( bg="lightblue")

Label(
	janela,
	text="Selecione um gênero:",
	font=("Arial", 12, "underline") 
   
).pack(padx=15, pady=15) #padx -> Espaçamento horizontal interno, pady -> Espaçamento vertical interno.


var = StringVar() #StringVar(), BooleanVar()
genero = StringVar() #StringVar(), BooleanVar()

var.set(" ")
genero.set(" ")

def mostrar():
    texto = genero.get()
    label.config(text=texto)  # atualiza o texto da label
  
Radiobutton(janela, text="Masculino", variable=genero, value="Opção Selecionada -> Masculino", command=mostrar).pack()
Radiobutton(janela, text="Feminino", variable=genero, value="Opção Selecionada -> Feminino", command=mostrar).pack()

label = Label(janela, text="")
label.pack(pady=10)

janela.mainloop()