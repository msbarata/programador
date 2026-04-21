
from tkinter import *
from tkinter import messagebox


janela = Tk()
janela.geometry("500x300") 
janela.title("Soma_Números_Validação")
janela.configure(bg="lightblue")

Label(
    janela,
    text="Insira o primeiro número:",
    font=("Arial", 11, "underline")
).pack(pady=10)

entrada1 = Entry(janela, width=50, bg="white")
entrada1.pack()

Label(
    janela,
    text="Insira o segundo número:",
    font=("Arial", 11, "underline")
).pack(pady=10)

entrada2 = Entry(janela, width=50, bg="white")
entrada2.pack()

def validar_entradas(event=None):
    valido1 = True
    valido2 = True
    
    # Valida primeira entrada
    try:
        if entrada1.get():
            valor1 = float(entrada1.get())
            entrada1.config(bg="white")
        else:
            entrada1.config(bg="white")
    except ValueError:
        entrada1.config(bg="lightcoral")
        valido1 = False
    
    # Valida segunda entrada
    try:
        if entrada2.get():
            valor2 = float(entrada2.get())
            entrada2.config(bg="white")
        else:
            entrada2.config(bg="white")
    except ValueError:
        entrada2.config(bg="lightcoral")
        valido2 = False
    
    # Se alguma estiver inválida, mostra mensagem
    if not valido1 or not valido2:
        messagebox.showwarning(
            "Entrada inválida",
            "Por favor, insira apenas valores numéricos em todos os campos!"
        )
    
    return valido1 and valido2

# Aplica validação em ambas as entradas
entrada1.bind("<KeyRelease>", validar_entradas)
entrada2.bind("<KeyRelease>", validar_entradas)


def somar():
    numero1 = int(entrada1.get())
    numero2 = int(entrada2.get())
    soma = numero1 + numero2
    label.config(text=f"Resultado: {soma}")

def limpar():
    texto = entrada1.get()
    label.config(text="") 
    entrada1.delete(0, END)
    entrada2.delete(0, END)


label = Label(janela, text="")
label.pack(pady=10)

Button(janela, text="Somar", command=somar).pack()
Button(janela, text="Limpar", command=limpar).pack()


janela.mainloop()