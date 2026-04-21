from tkinter import *
import tkinter as tk


janela = tk.Tk()
janela.title("Slider Dinâmico")
janela.geometry('300x100')
janela.config( bg="lightblue")


def atualizar(valor):
    label.config(text=f"Valor: {valor}")

scale = tk.Scale(janela, from_=0, to=100, orient="horizontal", command=atualizar)
scale.pack(pady=10)

label = tk.Label(janela, text="Valor: 0", font=("Arial", 14))
label.pack(pady=10)


janela.mainloop()