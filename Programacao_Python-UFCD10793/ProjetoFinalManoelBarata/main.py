# main.py
# Arquivo principal do Sistema de Reparação de Telhados
# Este é o ponto de entrada do programa - é o primeiro arquivo executado

import tkinter as tk  # Importa a biblioteca para criar interfaces gráficas
import os  # Importa biblioteca para funções do sistema operacional
from interfaceclas import Cad, App, Age  # Importa as classes das janelas secundárias
from basedados import *  # Importa tudo do módulo da base de dados - ligação para dois ficheiros em excell

def limpar_tela():
    
    # FUNÇÃO - Limpa a tela do terminal/console
    # 0s.system executa um comando no sistema operacional
    # 'cls' é o comando para limpar tela no Windows
    # 'clear' é o comando para limpar tela no Linux/Mac
    # os.name aciona o comando CLS para Windows, ou CLEAR para outros sistemas.
   
    os.system('cls' if os.name == 'nt' else 'clear')

def abrir_cadastro():
    
    # FUNÇÃO - Abre a janela de cadastro/lista de empresas
    # A função Toplevel() cria uma nova janela (filha da janela principal)
    # Cad() é a classe definida no arquivo classes.py que cria a interface de cadastro
   
    root = tk.Toplevel(janela)  # Cria nova janela
    Cad(root)  # Passa a nova janela para a classe Cad

def abrir_calculadora():
   
    # FUNÇÃO - Abre a janela da calculadora de preços
    # Toplevel() cria uma nova janela
    # App() é a classe definida no arquivo classes.py que cria as opreações e a interface da calculadora
   
    root = tk.Toplevel(janela)  # Cria nova janela
    App(root)  # Passa a nova janela para a classe App

def abrir_agendamento():
   
   # FUNÇÃO - Abre a janela de pré-agendamento
   # Toplevel() cria uma nova janela
   # Age() é a classe definida no arquivo classes.py que cria o formulário de agendamento
   
    root = tk.Toplevel(janela)  # Cria nova janela
    Age(root)  # Passa a nova janela para a classe Age

def sair():
   
    # FUNÇÃO - Encerra o programa
    # Exibe mensagem de despedida no terminal
    # quit() fecha a janela principal e encerra o programa
   
    print("Volte sempre!!!")  # Mensagem no terminal
    janela.quit()  # Fecha a janela principal


# ==================== CONFIGURAÇÃO DA JANELA PRINCIPAL ====================

# Cria a janela principal do programa
# Tk() é a classe que cria a janela raiz (principal)
janela = tk.Tk()

# Configura o título que aparece na barra superior da janela
janela.title("**FASTRESULT - Serviços para sua Casa**")

# Define o tamanho da janela: largura 500 pixels, altura 400 pixels
janela.geometry("500x400")

# ==================== CRIAÇÃO DOS ELEMENTOS DA INTERFACE ====================

# Cria um título para a janela (Label = rótulo/texto)
# pack() posiciona o elemento na janela (empilhando verticalmente)
# pady=30 adiciona espaçamento vertical de 30 pixels
tk.Label(
    janela,  # Onde colocar o label (na janela principal)
    text="==== CONSULTA & PRÉ-AGENDAMENTO DO SERVIÇO ====",  # Texto a ser exibido
    font=('Arial', 12, 'bold')  # Fonte: Arial, tamanho 12, negrito
).pack(pady=30)  # Espaçamento vertical de 30 pixels

# ==================== CRIAÇÃO DOS BOTÕES DO MENU ====================

# Lista de opções do menu
# Cada elemento é uma tupla com (texto_do_botão, função_a_ser_chamada)
opcoes = [
    ("1 - Listar Empresas", abrir_cadastro),      # Opção 1: Listar empresas
    ("2 - Calculadora", abrir_calculadora),       # Opção 2: Calculadora
    ("3 - Pré-agendamento", abrir_agendamento)    # Opção 3: Agendamento
]

# Loop FOR para criar os botões automaticamente
# Para cada tupla em opcoes, cria um botão
for texto, comando in opcoes:
    # Cria um botão para cada opção
    tk.Button(
        janela,  # Onde colocar o botão (na janela principal)
        text=texto,  # Texto do botão (vem da tupla)
        command=comando,  # Função a executar quando clicar (vem da tupla)
        width=25,  # Largura do botão em caracteres (não pixels)
        height=2   # Altura do botão em linhas de texto
    ).pack(pady=5)  # Espaçamento vertical de 5 pixels entre botões

# ==================== BOTÃO SAIR (COM DESTAQUE) ====================

# Cria o botão SAIR separadamente (fora do loop) porque tem cor diferente
tk.Button(
    janela,  # Onde colocar o botão (na janela principal)
    text="0 - Sair",  # Texto do botão
    command=sair,  # Função a executar quando clicar
    width=25,  # Largura do botão
    height=2,  # Altura do botão
    bg='lightcoral'  # Cor de fundo (background) - vermelho claro para destacar
).pack(pady=20)  # Espaçamento vertical de 20 pixels

# ==================== INÍCIO DO PROGRAMA ====================

# Limpa a tela do terminal antes de começar
limpar_tela()

# INICIA O PROGRAMA!
# mainloop() é um loop infinito que:
# 1. Mantém a janela aberta
# 2. Fica "ouvindo" eventos (cliques do mouse, teclas)
# 3. Só termina quando a janela é fechada
janela.mainloop()

# Quando mainloop() termina (janela fechada), executa esta linha
# Limpa a tela do terminal novamente
limpar_tela()