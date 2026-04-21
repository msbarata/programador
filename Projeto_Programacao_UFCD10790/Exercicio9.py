from tkinter import *

janela = Tk()
janela.geometry('300x350')
janela.config( bg="lightblue")

var = IntVar() #StringVar(), BooleanVar()

def mostrar_estado():
    print(f"valor:{var.get()}")

def selecionar():
    check.select()

def desselecionar():
    check.deselect()

def alternar():
    check.toggle()

check = Checkbutton( 
    janela,
    text="Aceito os termos",

#Variaveis

    variable = var,
    onvalue=1,
    offvalue=0,

#Aparencia
    bg="lightgray",
    fg="black",
    activebackground="green",
    activeforeground="white",

#Fonte
    font=("Arial", 14, "bold"),

    #Estilo
    indicatoron=True,

    #Tamanho
    width=25,
    height=2,
    padx=10,
    pady=10,

    #Bordas
    bd=3,
    relief=RIDGE,

    #Cursor

    cursor="hand2",

    #Alinhamento
    anchor="w",
    justify="left",

    #Evento
    command=mostrar_estado,

    #Cor da seleção
    selectcolor="yellow"

)

check.pack(pady=20)

Button(janela, text="Selecionar", command=selecionar).pack()
Button(janela, text="Desselecionar", command=desselecionar).pack()
Button(janela, text="Alternar", command=alternar).pack()


janela.mainloop()