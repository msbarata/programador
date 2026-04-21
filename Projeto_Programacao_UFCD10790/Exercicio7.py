from tkinter import *


janela = Tk()
janela.geometry("500x300")  # tamanho correto
janela.title("Soma_Números_Inteiros")
janela.configure(bg="lightblue")

Label(
	janela,
	text="Soma de Números Inteiros",
	font=("Arial", 12, "underline") 
   
).pack(padx=15, pady=15) #padx -> Espaçamento horizontal interno, pady -> Espaçamento vertical interno.


Label(
	janela,
	text="Insira o primeiro número:",
	font=("Arial", 11, "underline") ).pack(pady=10)
entrada = Entry(janela, width=50,bg="white")
entrada.pack()

Label(
	janela,
	text="Insira o segundo número:",
	font=("Arial", 11, "underline") ).pack(pady=10)
entrada2 = Entry(janela, width=50,bg="white")
entrada2.pack()


def somar():
    numero1 = int(entrada.get())
    numero2 = int(entrada2.get())
    soma = numero1 + numero2
    label.config(text=f"Resultado: {soma}")

def limpar():
    texto = entrada.get()
    label.config(text="")  # Limpa o texto da label
    entrada.delete(0, END)
    entrada2.delete(0, END)


label = Label(janela, text="")
label.pack(pady=10)

Button(janela, text="Somar", command=somar).pack()
Button(janela, text="Limpar", command=limpar).pack()


janela.mainloop()