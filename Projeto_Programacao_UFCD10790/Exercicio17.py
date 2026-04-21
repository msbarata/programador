from tkinter import *

janela = Tk()
janela.title("Mensagem")
janela.geometry("300x100")

def mensagem():
     botao.config(text="Bem-vindo ao sistema")

botao = Button(
    janela,
    text="Clique aqui",
    command=mensagem,
    width=20,
    height=5,
    bg="#3697AF",
    fg="white",
    activebackground="red",
    activeforeground="orange",
    font=("Tahoma", 16, "bold"), #Define a fonte do texto
    state=NORMAL, #Define o estado do botão
    relief=RAISED, #Define o estilo da borda
    bd=10, #Define a expessura da borda
    cursor="watch", #Define o tipo de cursor ao passar por cima (arrow, hand2, cross, fleur, ibeam, circle, plus, pirate, dot, exchange, tcross)
    disabledforeground="black", #Cor da borda quando não focado
    highlightbackground="black", #cor da borda quando não focado
    highlightcolor="red", # Cor da borda, quando focado
    justify='right', #Alinhamento
    highlightthickness=10, #Espessura da borda de foco
    anchor="n", #Posição do conteúdo dentro do botão (n, s, e, w, ne, nw, se, sw, center)
)
botao.pack()

janela.mainloop()