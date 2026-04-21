import tkinter as tk
janela = tk.Tk()
janela.title("Minha Aplicação") #Titulo da Janela
janela.geometry("500x250+200+200") #Tamanho da Janela
janela.resizable( width= False, height= False) #Comando para não deixar redimensionar a janela.
janela.minsize( width= 500, height= 250) #Comando para definir o valor mínimo de altura e largura
janela.maxsize( width= 1000, height= 500) #Comando para definir o valor mínimo de altura e largura
janela.iconbitmap("python.ico") #Define o icone da aplicação
janela.attributes("-topmost", True) #Define a janela sempre em cima
janela.attributes("-alpha", 0.5) #Define transparênccia na janela
janela.attributes("-fullscreen", True) #Define a janela cheia



janela.mainloop()