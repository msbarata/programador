
#   CLASSES DE INTERFACE → criam janelas e formulários com Tkinter

import os
import tkinter as tk  # Biblioteca padrão para interfaces gráficas
from tkinter import ttk  # Versão mais moderna e estilizada do tkinter
from servicoclas import ReparacaoTelhado, PinturaCasa 
import basedados  # Módulo local que contém a base de dados

# ==================== CLASSES DE INTERFACE GRÁFICA ====================
# Estas classes criam as janelas e elementos visuais do programa

class Age:
    
    # Esta Classe gera a interface de PRÉ-AGENDAMENTO de visitas
       
    def __init__(self, root):
        
    # Este é o Construtor da Classe Age, que recebe a janela principal (root)
    #  onde os elementos serão colocados
        
        self.root = root
        self.root.title("Pré-agendamento de Visita")  # Título da janela
        
        # Estes parâmetros abaixo, garantem que a janela apareça em foco ao se clicar no botão que as inicialize
        root.deiconify()
        root.focus_set()
        
        # As duas linhas de código abaixo, cria um Frame, "caixa vazia", que vai servir de base para ...
        # os botões, campos de texto, etc. serem colocados em seu interior de forma organizada.
        # Frame principal - container que agrupa elementos
        # padding adiciona espaçamento interno de 10 pixels
        frame_input = ttk.Frame(root, padding="10")
        frame_input.grid(row=0, column=0, sticky=(tk.W, tk.E))  # grid é o responsável pelo posicionamento na grade do DataFrame
        
        # Chama método para criar os campos do formulário
        self.criar_campos(frame_input)
        
        # Botão para salvar - command define a função chamada ao clicar
        ttk.Button(frame_input, text="Salvar Agendamento", 
                  command=self.salvar_agendamento).grid(row=4, column=0, columnspan=2, pady=10)
        
        # Label para mostrar mensagens (vazio inicialmente)
        self.msg_label = ttk.Label(frame_input, text="", font=('Arial', 10, 'bold'))
        self.msg_label.grid(row=5, column=0, columnspan=2, pady=5)
        
        # Label para mostrar informações da empresa selecionada
        self.info_label = ttk.Label(frame_input, text="", font=('Arial', 9))
        self.info_label.grid(row=6, column=0, columnspan=2, pady=5)
        
        # Carregar empresas ativas do banco de dados
        self.carregar_empresas_ativas()
    
    def criar_campos(self, frame):
        
        # Este Método serve para criar os campos do formulário, sejam (labels e entradas), usando o parâmetro frame
        
        # Este conjunto de linhas, permitem definir o Campo NOME
        ttk.Label(frame, text="Nome:").grid(row=0, column=0, sticky=tk.W, pady=5) 
        # ttk.Label - Cria uma Label, ou seja, um texto estático "Nome:", dentro do frame (o container pai).
        self.nome_entry = ttk.Entry(frame, width=35) 
        # Entry = campo de texto, salva a 'estrutura de entrada de dados - widgets' na classe para poder acessar o valor digitado
        self.nome_entry.grid(row=0, column=1, padx=5) 
        # O grid funciona como uma tabela invisível que organiza os 'widgets' por linhas e colunas.
        
        # Este conjunto de linhas, permitem definir o Campo TELEMÓVEL, conforme comentado para o Campo Nome.
        # Campo TELEMÓVEL
        ttk.Label(frame, text="Telemóvel:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.telemovel_entry = ttk.Entry(frame, width=35)
        self.telemovel_entry.grid(row=1, column=1, padx=5)
        
        # Este conjunto de linhas, permitem definir o Campo EMAIL, conforme comentado para o Campo Nome.
        # Campo EMAIL
        ttk.Label(frame, text="Email:").grid(row=2, column=0, sticky=tk.W, pady=5)
        self.email_entry = ttk.Entry(frame, width=35)
        self.email_entry.grid(row=2, column=1, padx=5)
        
        # Campo EMPRESA (Combobox = caixa de seleção)
        # Este campo foi desenvolvido com uso de uma Combobox para selecionar valores
        # provenientes do carregamento de uma base de dados em EXCEL;
        ttk.Label(frame, text="Empresa:").grid(row=3, column=0, sticky=tk.W, pady=5)
        self.empresa_var = tk.StringVar()  # Variável que armazena o valor selecionado
        # `StringVar` é uma **variável "inteligente"** do Tkinter. Diferente de uma variável Python normal;
        #  ela é **reativa** — quando seu valor muda, a interface atualiza automaticamente.
        # Pensa nela como um **intermediário** entre o widget e o seu código:
        # [Usuário seleciona algo] → StringVar → [Você lê o valor no código]

        self.empresa_combo = ttk.Combobox(frame, textvariable=self.empresa_var, 
                                         width=32, state='readonly')  # readonly = só leitura
        self.empresa_combo.grid(row=3, column=1, padx=5)

        # Bind significa "amarrar": 
        # "Quando acontecer o evento `<<ComboboxSelected>>`, será executada a função `mostrar_info_empresa`"
        # <<ComboboxSelected>>'` | Evento que dispara quando o usuário **escolhe uma opção** 
        # self.mostrar_info_empresa` | Função que será **chamada automaticamente** após a escolha |
        # Bind = associar evento (quando selecionar algo, chama mostrar_info_empresa)
        self.empresa_combo.bind('<<ComboboxSelected>>', self.mostrar_info_empresa)

    
    def carregar_empresas_ativas(self):
        
       # Este Método, busca por intermédio do módulo basedados, no ficheiro empresas, coluna agenda,
       # pelas empresas que possuem agenda disponível.
        
        # Filtra empresas onde 'agenda' == 1 (disponíveis para agendamento)
        empresas_ativas = basedados.empresas[basedados.empresas['agenda'] == 1]
        
        # Extrai e filtra apenas os nomes para uma lista
        self.empresas_lista = empresas_ativas['nome_empresa'].tolist()
        
        # Coloca a lista dos nomes destas empresas no combobox, 
        # para que o utilizador possa fazer a seleção de uma. 
        self.empresa_combo['values'] = self.empresas_lista
        self.empresa_combo.set("Selecione...")  # Texto inicial
        
        # Cria dicionário para acessar ID da empresa pelo nome
        # Ex: self.dict_empresas['Zeta'] = 101. 
        # Correlacionando os campos: nome_empresa ao id_empresa
        self.dict_empresas = {}
        for _, row in empresas_ativas.iterrows():  # Itera cada linha do DataFrame
            self.dict_empresas[row['nome_empresa']] = row['id_empresa']
    
    def mostrar_info_empresa(self, event):
       
        # Este Método, mostra informações da empresa quando selecionada;
        # event é o evento que disparou a função (seleção no combobox)
       
        nome = self.empresa_var.get()  # Pega o nome selecionado
        if nome in self.dict_empresas:
            self.info_label.config(
                text=f"✓ Empresa selecionada (ID: {self.dict_empresas[nome]})",
                foreground="blue"
            )
    
    def salvar_agendamento(self):
      
        # Este Método salva os dados do agendamento no banco de dados
        # O método .get() Pega o texto digitado pelo usuário no campo de entrada (entry);
        # Sem ele, você teria apenas o objeto do campo, não o conteúdo.
        # .strip() remove espaços extras no início/fim dos campos, limpando o conteudo, (muito usado em formularios)
        nome = self.nome_entry.get().strip()
        telemovel = self.telemovel_entry.get().strip()
        email = self.email_entry.get().strip()
        empresa = self.empresa_var.get()
        
        # VALIDAÇÕES - Verifica se campos obrigatórios estão preenchidos
        if not nome or not telemovel or not empresa or empresa == "Selecione...":
            self.msg_label.config(text="Preencha todos os campos obrigatórios!", foreground="orange")
            return  # Sai da função sem salvar
        
        try:
            # Pega ID da empresa selecionada
            id_empresa = self.dict_empresas[empresa]
            
            # Chama função do módulo basedados para salvar no banco
            basedados.salvar_cliente(nome, telemovel, email, id_empresa)
            
            # Mensagem de sucesso
            self.msg_label.config(
                text=f"✓ Agendamento realizado com sucesso para {nome}!",
                foreground="green"
            )
            
            # LIMPAR CAMPOS - Apaga tudo para novo cadastro
            self.nome_entry.delete(0, tk.END)  # Apaga do índice 0 até o final
            self.telemovel_entry.delete(0, tk.END)
            self.email_entry.delete(0, tk.END)
            self.empresa_combo.set("Selecione...")
            self.info_label.config(text="")
            
        except Exception as e:  # Captura qualquer erro
            self.msg_label.config(text=f"Erro: {e}", foreground="red")


class App:
   
   # Classe para interface da CALCULADORA de preços
    
    def __init__(self, root):
 
    # Construtor - configura a janela da calculadora
       
        self.root = root
        self.root.title("Calculadora de Menor Preço e Previsão de Entrega")
        root.deiconify()
        root.focus_set()
        
        # Frame para entrada de dados          
        # Label e Entry para área do telhado
        # Entry = campo de texto, salva a 'estrutura de entrada de dados - widgets' na classe para poder acessar o valor digitado
        # Estas linhas abaixo, definem o campo para entrada de dados pelo utiizador, (área do telhado em M2)
        # Label e Entry para área da Parede
        # Entry = campo de texto, salva a 'estrutura de entrada de dados - widgets' na classe para poder acessar o valor digitado
        # Estas linhas abaixo, definem o campo para entrada de dados pelo utiizador, (área da parede em M2)           
        # BOTÕES - cada um na sua linha define o método a ser chamado, ao utilizador clicar;
        # Cada ttk.Button representa um botão distinto.
        # Frame principal
        frame_input = ttk.Frame(root, padding="10")
        frame_input.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # ===== COLUNA ESQUERDA - TELHADO =====
        ttk.Label(frame_input, text="=== Reparo do Telhado ===", font=('Arial', 10, 'bold')).grid(
            row=0, column=0, columnspan=2, pady=5)

        ttk.Label(frame_input, text="Área do Telhado (m²):").grid(row=1, column=0, sticky=tk.W)
        self.area_entry = ttk.Entry(frame_input, width=15)
        self.area_entry.grid(row=1, column=1, padx=5)

        ttk.Button(frame_input, text="Listar Empresas", width=25,
            command=self.listar_empresas).grid(row=2, column=0, columnspan=2, pady=3)

        ttk.Button(frame_input, text="Menor Valor", width=25,
            command=self.mostrar_menor_valor).grid(row=3, column=0, columnspan=2, pady=3)

        ttk.Button(frame_input, text="Calcular Tempo de Reparo", width=25,
            command=self.calcular_tempo_reparo).grid(row=4, column=0, columnspan=2, pady=3)

        # ===== SEPARADOR VERTICAL =====
        ttk.Separator(frame_input, orient='vertical').grid(
            row=0, column=2, rowspan=5, sticky='ns', padx=10)

        # ===== COLUNA DIREITA - PINTURA =====
        ttk.Label(frame_input, text="=== Serviço de Pintura ===", font=('Arial', 10, 'bold')).grid(
            row=0, column=3, columnspan=2, pady=5)

        ttk.Label(frame_input, text="Área da Parede (m²):").grid(row=1, column=3, sticky=tk.W)
        self.area_entry2 = ttk.Entry(frame_input, width=15)
        self.area_entry2.grid(row=1, column=4, padx=5)

        ttk.Button(frame_input, text="Listar Empresas", width=25,
            command=self.listar_empresas_pintura).grid(row=2, column=3, columnspan=2, pady=3)

        ttk.Button(frame_input, text="Menor Valor", width=25,
            command=self.mostrar_menor_valor_pintura).grid(row=3, column=3, columnspan=2, pady=3)

        ttk.Button(frame_input, text="Calcular Tempo de Pintura", width=25,
            command=self.calcular_tempo_pintura).grid(row=4, column=3, columnspan=2, pady=3)
                
        # Frame para resultados (abaixo dos botões)
        self.frame_resultados = ttk.Frame(root, padding="10")
        self.frame_resultados.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # TREEWIDGET - Tabela para mostrar resultados
        self.tree = ttk.Treeview(self.frame_resultados, 
                                 columns=('nome', 'valor_m2', 'valor_total', 'agenda'),
                                 show='headings', height=10)
        
        # Configurar cabeçalhos das colunas
        self.tree.heading('nome', text='Empresa')
        self.tree.heading('valor_m2', text='Valor/m² (€)')
        self.tree.heading('valor_total', text='Valor Total (€)')
        self.tree.heading('agenda', text='Disponível')
        
        # Configurar larguras das colunas
        self.tree.column('nome', width=200)
        self.tree.column('valor_m2', width=100)
        self.tree.column('valor_total', width=120)
        self.tree.column('agenda', width=80)
        
        self.tree.grid(row=0, column=0)
        
        # Label para mostrar resultados (abaixo da tabela)
        self.result_label = ttk.Label(self.frame_resultados, text="", font=('Arial', 10, 'bold'))
        self.result_label.grid(row=1, column=0, pady=10)
        
        # Label para mostrar tempo de reparo
        self.tempo_label = ttk.Label(self.frame_resultados, text="", font=('Arial', 9))
        self.tempo_label.grid(row=2, column=0, pady=5)
        
    
    def calcular_tempo_reparo(self):

        # Este Método, usa novamente a classe ReparacaoTelhado para calcular o tempo
        # necessário para execução do serviço por metro quadrado.

        try:
            # tenta converter entrada para float
            area = float(self.area_entry.get())
            
            # Para calcular o tempo, precisamos de uma empresa de referência
            # Vamos usar a primeira empresa da base de dados como referência
            if len(basedados.empresas) > 0:
                primeira_empresa = basedados.empresas.iloc[0]
                
                # Cria objeto da classe ReparacaoTelhado, para calcular o tempo de reparo no telhado;
                servico = ReparacaoTelhado(
                empresa=primeira_empresa['nome_empresa'], 
                valor_mensal=100, 
                areaMetro2_telhado=area, 
                valor_Metro2=primeira_empresa['valorM2']
)
                tempo_total = servico.calcular_tempo_reparo()
              
                
                # USA O MÉTODO DA CLASSE para calcular o tempo
                tempo_total = servico.calcular_tempo_reparo()
                
                # USA O MÉTODO DA CLASSE para obter descrição formatada
                # Ou formata manualmente:
                self.result_label.config(
                    text=f"Tempo estimado para realização do serviço: {tempo_total:.0f} dias para {area:.0f} m²",
                    foreground="blue"
                )
            else:
                self.result_label.config(
                    text="Erro: Nenhuma empresa cadastrada",
                    foreground="red"
                )
            
        except ValueError:
            self.result_label.config(
                text="Erro: Digite um valor numérico válido",
                foreground="red"
            )
   
    def listar_empresas(self):
        
        # Este Método lista as empresas, ordenadas por menor valor total cobrado.
        # Limpar resultados anteriores da tabela
        for item in self.tree.get_children():
            self.tree.delete(item)
        self.result_label.config(text="")
        
        # Uso do try / except representa - uma rede de segurança:
        # o try tenta executar algo, e o except aparece com alguma,
        # ação / mensagem, caso algo dê errado.
        try:
            area = float(self.area_entry.get())
            
            # Calcular valor total para cada empresa USANDO A CLASSE
            resultados = []
            for index, row in basedados.empresas.iterrows():
                # USA O MÉTODO que chama a classe Reparacao Telhado para chamar o Método calcula_valor_total()
                servico = ReparacaoTelhado(
                empresa=row['nome_empresa'], 
                valor_mensal=100, 
                areaMetro2_telhado=area, 
                valor_Metro2=row['valorM2']
            )
               
                valor_total = servico.calcula_valor_total()
                
                resultados.append({
                    'nome': row['nome_empresa'],
                    'valor_m2': row['valorM2'],
                    'valor_total': valor_total,                    
                    'agenda': row['agenda']
                })
            
            # ORDENAR por valor total (do menor para o maior)
            # O lambda é uma função rápida que fala: "para cada item x da lista, olha o campo valor_total"
            resultados.sort(key=lambda x: x['valor_total'])
            
            # Inserir na tabela
            # for emp in resultados - Percorre cada empresa da lista ordenada, uma por vez, guardando-a em emp;
            # Se emp ['agenda'] == 1 então, Insere uma nova linha na tabela visual (Treeview do Tkinter)
            # Contendo os campos: nome da empresa, valor cobrado pelo M2 e valor total do serviço.
            for emp in resultados:
                status = "Sim" if emp['agenda'] == 1 else "Não"
                self.tree.insert('', 'end', values=(
                    emp['nome'],
                    f"{emp['valor_m2']:.2f}",
                    f"{emp['valor_total']:.2f}",
                    status
                ))
                
        except ValueError:
            self.result_label.config(text="Erro: Insira um valor numérico válido")
    
    def mostrar_menor_valor(self):
      
       # Este Método, mostra apenas a empresa com o menor valor para realizar o serviço
       
        try:
            area = float(self.area_entry.get())
            
            # idxmin() encontra o índice da linha com menor valorM2
            idx_min = basedados.empresas['valorM2'].idxmin()
            empresa_min = basedados.empresas.loc[idx_min]
            
            # USA O MÉTODO que chama a classe Reparacao Telhado para 
            servico = ReparacaoTelhado(
            empresa=empresa_min['nome_empresa'], 
            valor_mensal=100, 
            areaMetro2_telhado=area, 
            valor_Metro2=empresa_min['valorM2']
        )
            valor_total = servico.calcula_valor_total()
            
            self.result_label.config(
                text=f"Menor valor: {empresa_min['nome_empresa']} - {valor_total:.2f} € ({empresa_min['valorM2']:.2f} €/m²)",
                foreground="red"
            )
            
        except ValueError:
            self.result_label.config(text="Erro: Insira um valor numérico válido")
        except Exception as e:
            self.result_label.config(text=f"Erro ao listar empresas: {e}")

    def calcular_tempo_pintura(self):
        try:
            area = float(self.area_entry2.get())
            if len(basedados.empresas) > 0:
                primeira_empresa = basedados.empresas.iloc[0]
                servico = PinturaCasa(primeira_empresa['nome_empresa'], 100, area, primeira_empresa['valorM2P'])
                tempo_total = servico.calcular_tempo_reparo()
                self.result_label.config(
                    text=f"Tempo estimado para pintura: {tempo_total:.0f} dias para {area:.0f} m²",
                    foreground="blue"
                )
        except ValueError:
            self.result_label.config(text="Erro: Digite um valor numérico válido", foreground="red")

    def listar_empresas_pintura(self):
        for item in self.tree.get_children():
            self.tree.delete(item)
        try:
            area = float(self.area_entry2.get())
            resultados = []
            for index, row in basedados.empresas.iterrows():
                servico = PinturaCasa(row['nome_empresa'], 100, area, row['valorM2P'])
                valor_total = servico.calcula_valor_total()
                resultados.append({
                    'nome': row['nome_empresa'],
                    'valor_m2': row['valorM2P'],
                    'valor_total': valor_total,
                    'agenda': row['agenda']
                })
            resultados.sort(key=lambda x: x['valor_total'])
            for emp in resultados:
                status = "Sim" if emp['agenda'] == 1 else "Não"
                self.tree.insert('', 'end', values=(
                    emp['nome'], f"{emp['valor_m2']:.2f}", f"{emp['valor_total']:.2f}", status
                ))
        except ValueError:
            self.result_label.config(text="Erro: Insira um valor numérico válido")

    def mostrar_menor_valor_pintura(self):
        try:
            area = float(self.area_entry2.get())
            idx_min = basedados.empresas['valorM2P'].idxmin()  # ← valorM2P
            empresa_min = basedados.empresas.loc[idx_min]
            servico = PinturaCasa(empresa_min['nome_empresa'], 100, area, empresa_min['valorM2P'])
            valor_total = servico.calcula_valor_total()
            self.result_label.config(
                text=f"Menor valor pintura: {empresa_min['nome_empresa']} - {valor_total:.2f} € ({empresa_min['valorM2P']:.2f} €/m²)",
                foreground="red"
            )
        except ValueError:
            self.result_label.config(text="Erro: Insira um valor numérico válido")

class Cad:
   
    # Esta classe define a interface para a listagem de empresas;
    # assim como o cadastro de novas solicitações de visitas.    
    
    def __init__(self, root):
        
      # Este construtor - configura janela de cadastro
      
        self.root = root
        self.root.title("Dados de Contato - Empresas de Construção Civil")
        root.deiconify()
        root.focus_set()
        
        # Frame para entrada de dados
        frame_input = ttk.Frame(root, padding="10")
        frame_input.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Campo para filtrar por localidade
        ttk.Label(frame_input, text="Digite a Cidade do Serviço: (Filtro)").grid(row=0, column=0, sticky=tk.W)
        self.local_entry = ttk.Entry(frame_input, width=30) 
        self.local_entry.grid(row=0, column=1, padx=5)
        
        # Botões
        ttk.Button(frame_input, text="Listar Empresas com Filtro de Localidade", 
                  command=self.listar_empresas_por_localidade).grid(row=3, column=0, columnspan=2, pady=5)
        
        ttk.Button(frame_input, text="Listar Todas as Empresas Cadastradas", 
                  command=self.listar_todas_empresas).grid(row=4, column=0, columnspan=2, pady=5)
        
        # Frame para resultados
        self.frame_resultados = ttk.Frame(root, padding="10")
        self.frame_resultados.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Treeview com 7 colunas (mais informações que a calculadora)
        self.tree = ttk.Treeview(self.frame_resultados, 
                                columns=('nome', 'telemovel', 'email', 'localidade', 'valor_M2', 'valor_M2P', 'agenda'),
                                show='headings', height=10)

        # Configurar cabeçalhos
        self.tree.heading('nome', text='Empresa')
        self.tree.heading('telemovel', text='Telefone')
        self.tree.heading('email', text='Email')
        self.tree.heading('localidade', text='Localidade')
        self.tree.heading('valor_M2', text='Valor Reparo/m² (€)')
        self.tree.heading('valor_M2P', text='Valor Pintura/m² (€)')
        self.tree.heading('agenda', text='Disponível')

        # Configurar larguras
        self.tree.column('nome', width=100)
        self.tree.column('telemovel', width=70)
        self.tree.column('email', width=130)
        self.tree.column('localidade', width=100)
        self.tree.column('valor_M2', width=100)
        self.tree.column('valor_M2P', width=100)
        self.tree.column('agenda', width=70)
        
        self.tree.grid(row=0, column=0)
        
        # Label para mensagens
        self.result_label = ttk.Label(self.frame_resultados, text="", font=('Arial', 10, 'bold'))
        self.result_label.grid(row=1, column=0, pady=10)
    
    def listar_todas_empresas(self):
        
        # Este Método, lista TODAS as empresas (sem filtro)        
        # Limpar resultados anteriores

        for item in self.tree.get_children():
            self.tree.delete(item)
        
        self.result_label.config(text="")
        
        try:
            # Itera todas as empresas do DataFrame
            for index, row in basedados.empresas.iterrows():
                
                # Converte agenda (1/0) para texto (Sim/Não)
                status = "Sim" if row['agenda'] == 1 else "Não"
                
                # Insere na tabela de visualização (SEM o id_empresa, que é apenas interno)
                self.tree.insert('', 'end', values=(
                    row['nome_empresa'],  # Nome da empresa
                    row['telemovel'],      # Telefone para contato
                    row['email'],          # Email para contato
                    row['localidade'],     # Cidade onde atua
                    f"{row['valorM2']:.2f}",  # Preço metro quadrado telhado
                    f"{row['valorM2P']:.2f}",  # Preço por metro quadrado pintura
                    status                 # Disponível para agendamento?
                ))
            
            # Mostra contador
            total_empresas = len(basedados.empresas)
            self.result_label.config(
                text=f"Total de {total_empresas} empresas listadas",
                foreground="blue"
            )
            
        except Exception as e:
            self.result_label.config(text=f"Erro ao listar empresas: {e}")

    def listar_empresas_por_localidade(self):
        
        # Este Método, lista empresas FILTRADAS por suas respetivas localidades      
        # Limpar resultados anteriores

        for item in self.tree.get_children():
            self.tree.delete(item)
        
        self.result_label.config(text="")
        
        try:
            # Pega localidade digitada pelo utilizado .get() e passa para a variável localidade_pesquisa
            localidade_pesquisa = self.local_entry.get().strip()
            
            # Valida se o utilizador selecionou alguma localidade
            if not localidade_pesquisa:
                self.result_label.config(
                    text="Por favor, selecione uma localidade",
                    foreground="orange"
                )
                return
            
            # FILTRO - str.contains procura texto dentro da coluna 'localidade'
            # case=False ignora maiúsculas/minúsculas
            # na=False ignora valores nulos
            mascara = basedados.empresas['localidade'].str.contains(
                localidade_pesquisa, 
                case=False,
                na=False
            )
            empresas_filtradas = basedados.empresas[mascara]
            
            # Verifica se encontrou alguma
            if len(empresas_filtradas) == 0:
                self.result_label.config(
                    text=f"Nenhuma empresa encontrada em '{localidade_pesquisa}'",
                    foreground="orange"
                )
                return
            
            # Insere empresas encontradas no grid de visualização, filtradas
            # pela disponibilidade de agenda.
            for index, row in empresas_filtradas.iterrows():
                status = "Sim" if row['agenda'] == 1 else "Não"
                
                self.tree.insert('', 'end', values=(
                    row['nome_empresa'],
                    row['telemovel'],
                    row['email'],
                    row['localidade'],
                    f"{row['valorM2']:.2f}",  # Preço metro quadrado telhado
                    f"{row['valorM2P']:.2f}",  # Preço por metro quadrado pintura
                    status
                ))
            
            # Mostra resultado
            self.result_label.config(
                text=f"{len(empresas_filtradas)} empresas encontradas em '{localidade_pesquisa}'",
                foreground="blue"
            )
            
        except Exception as e:
            self.result_label.config(text=f"Erro: {e}")