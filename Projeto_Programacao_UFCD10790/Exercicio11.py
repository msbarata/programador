from tkinter import *

janela = Tk()
janela.geometry('300x250')
janela.config( bg="lightblue")

txt = StringVar()
txt.set("Texto original")

def alterar():
    txt.set("Texto alterado")     

Label(
    janela,
    textvariable=txt,
    wraplength=200,
).pack(padx=15, pady=30)

Button(
    janela,
    text="Alterar",
    command=alterar 
).pack()

janela.mainloop()