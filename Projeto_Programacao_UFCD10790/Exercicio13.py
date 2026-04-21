from tkinter import *

janela = Tk()
janela.geometry('300x250')

cor_atual = StringVar()
cor_atual.set("lightblue")
janela.config(bg="lightblue") 

def alterar():
    if cor_atual.get() == "lightblue":
        cor_atual.set("gold")
    else:
        cor_atual.set("lightblue")
    
    janela.config(bg=cor_atual.get()) 

Label(
    janela,
    textvariable=cor_atual,
    wraplength=200,
).pack(padx=15, pady=30)

Button(
    janela,
    text="Alterar cor da janela",
    command=alterar
).pack()

janela.mainloop()