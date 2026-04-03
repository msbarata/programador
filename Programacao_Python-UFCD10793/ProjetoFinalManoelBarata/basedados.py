
# Este ficheiro possui dois objetivos principais:
# 1) carregar os dados das empresas do ficheiro empresas.xlsx 
# 2) Carregar & salvar dados do ficheiro clientes.xlsx.

import os
import pandas as pd

BASE_DIR = os.path.dirname(os.path.abspath(__file__))

CAMINHO_EMPRESAS = os.path.join(BASE_DIR, 'empresas.xlsx') #Apontador para a base EMPRESAS, na pasta de armazenamento de todos os ficheiros do Projeto.
CAMINHO_CLIENTES = os.path.join(BASE_DIR, 'clientes.xlsx') #Apontador para a base CLIENTES, na pasta de armazenamento de todos os ficheiros do Projeto.


# Carregar dados de empresas da base empresas.xlsx;

excel_empresas = pd.read_excel(CAMINHO_EMPRESAS)
#Lê um arquivo Excel chamado "empresas.xlsx" e carrega todos os dados para a memória;

empresas=excel_empresas[['id_empresa','nome_empresa', 'telemovel', 'email', 'localidade', 'valorM2', 'valorM2P', 'agenda']]
#Cria na memória, uma nova tabela reduzida chamada empresas, com esses dados filtrados

# Carregar dados dos clientes da base clientes.xlsx
excel_clientes = pd.read_excel(CAMINHO_CLIENTES)
#Lê um arquivo Excel chamado "clientes.xlsx" e carrega todos os dados para a memória;

clientes = excel_clientes[['nome_cliente', 'telemovel', 'email', 'id_empresa']]
#Cria na memória, uma nova tabela reduzida chamada clientes, com esses dados filtrados

# Função para salvar Solicitação de visitas pelos clientes e seus quatro parametros:

def salvar_cliente(nome, telemovel, email, id_empresa):
    """Salva cliente no Excel"""
    
    # Carregar dados existentes
    # Lê o ficheiro clientes em Excel e carrega todo o seu conteúdo numa estrutura de tabela chamada DataFrame - (df)
    # É como "abrir" o ficheiro para o Python trabalhar com ele.
    df = pd.read_excel(CAMINHO_CLIENTES)
    
    # Adicionar novo cliente
    # def.loc - define o local que será Adicionado uma nova linha, neste caso, no final da tabela; 
    # A função len(df) calcula o número atual de linhas, que serve como índice da próxima posição vazia;
    # Os dados do novo cliente serão inseridos nessa posição como uma lista ordenada.

    df.loc[len(df)] = [nome, telemovel, email, id_empresa]
    
    # Salvar
    # def.to_excel - Grava o DataFrame de volta no ficheiro Excel;
    # Substituindo o conteúdo anterior pelo novo (já com o cliente adicionado).
    # O parâmetro - index=False, evita que o Pandas escreva automaticamente, a coluna de índices numéricos (0, 1, 2...) no ficheiro.
    df.to_excel(CAMINHO_CLIENTES, index=False)
