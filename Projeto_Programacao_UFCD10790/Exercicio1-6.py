from tkinter import *


janela = Tk()
janela.geometry("500x300")  # tamanho correto
janela.title("Minha Primeira Janela")
janela.configure(bg="lightblue")

def mensagem():
    print("Botão clicado")

Label(
	janela,
	text="Bem Vindo ao TKINTER ",
	font=("Arial", 12, "underline") 
   
).pack(padx=15, pady=15) #padx -> Espaçamento horizontal interno, pady -> Espaçamento vertical interno.

Button(
    janela,
    text="Clique aqui",
    command=mensagem,
    width=8,
    height=1,
    bg="#66AF36",
    fg="white",
    activebackground="red",
    activeforeground="orange",
    font=("Tahoma", 11, "bold"), #Define a fonte do texto
    state=NORMAL, #Define o estado do botão
    relief=RAISED, #Define o estilo da borda
    bd=10, #Define a expessura da borda
    cursor="hand2", #Define o tipo de cursor ao passar por cima (arrow, hand2, cross, fleur, ibeam, circle, plus, pirate, dot, exchange, tcross)
    disabledforeground="black", #Cor da borda quando não focado
    highlightbackground="black", #cor da borda quando não focado
    highlightcolor="red", # Cor da borda, quando focado
    justify='right', #Alinhamento
    highlightthickness=10, #Espessura da borda de foco
    anchor="n", #Posição do conteúdo dentro do botão (n, s, e, w, ne, nw, se, sw, center)
).pack()

Label(
	janela,
	text="Insira um texto abaixo e clique em mostrar:",
	font=("Arial", 11, "underline") ).pack(pady=10)
entrada = Entry(janela, width=50,bg="white")
entrada.pack()

def mostrar():
    texto = entrada.get()
    label.config(text=texto)  # atualiza o texto da label

def limpar():
    texto = entrada.get()
    label.config(text="")  # Limpa o texto da label
    entrada.delete(0, END) 


label = Label(janela, text="")
label.pack(pady=10)

Button(janela, text="Mostrar", command=mostrar).pack()
Button(janela, text="Limpar", command=limpar).pack()


janela.mainloop()