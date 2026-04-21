from tkinter import *

janela = Tk()
janela.geometry("300x300")
janela.title("Preencher e Limpar")
janela.configure(bg="lightblue")

entrada = Entry(janela, width=50,bg="white")
entrada.pack()

def inserir(event=None):
    entrada.insert(END, "Python")
def limpar(event=None):
    entrada.delete(0, END)


frame = Frame(janela)
frame.pack()

btn_Preencher = Button(frame, text="Preencher")
btn_Preencher.pack(side=LEFT, padx=5)
btn_Preencher.bind("<Button-1>", inserir)

btn_Limpar = Button(frame, text="Limpar")
btn_Limpar.pack(side=LEFT, padx=5)
btn_Limpar.bind("<Button-1>", limpar)


#Button(janela, text="Preencher", command=inserir).pack()
#Button(janela, text="Limpar", command=limpar).pack()


janela.mainloop()