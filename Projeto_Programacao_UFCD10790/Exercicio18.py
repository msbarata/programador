from tkinter import *
from tkinter import messagebox

janela = Tk()
janela.geometry('300x350')
janela.config( bg="lightblue")

var = IntVar() #StringVar(), BooleanVar()

def mostrar_estado():
    if var.get() == 1:
        messagebox.showinfo("Termos", "Termo aceito! ✅")
    else:
        messagebox.showwarning("Termos", "Termo não aceito! ❌")

def selecionar():
    check.select()
    mostrar_estado()

def desselecionar():
    check.deselect()
    mostrar_estado()

def alternar():
    check.toggle()
    mostrar_estado()

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