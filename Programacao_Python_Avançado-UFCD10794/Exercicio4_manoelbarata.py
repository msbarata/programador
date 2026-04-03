#Definição da superclasse - Servicos - Controle - Relatório Janeiro-2025
#importada a Biblioteca que permite usar a função que limpa a tela
import os

class Servico:
    def __init__(self, nome_servico, empresa, valor_mensal):
     #Ano e mês do início do serviço informado manualmente durante a criação da classe   
        self.nome_servico = nome_servico
        self.empresa = empresa
        self.valor_mensal = float(valor_mensal)
        self.mes_inicio = 1
        self.ano_inicio = 2025
        
    #definição dos métodos da classe servico
    #Método que mostra as características dos servicos
    def descricao_servico(self):
    #Construtor da classe servico      
       return f"Serviço de {self.nome_servico} da empresa {self.empresa}, iniciado em {self.ano_inicio} com valor mensal de {self.valor_mensal}"
    
    #Método que calcula o total de meses já pagos a prestadora de serviço
    def calcula_meses(self):
    #Ano e mês atual informado manualmente
        mes_atual = 2  # Fevereiro
        ano_atual = 2026
        
        meses_pagos = (ano_atual - self.ano_inicio) * 12 + (mes_atual - self.mes_inicio)

        return meses_pagos
    
    #Método que calcula o valor total pago a prestadora de serviços até a presente data
    def calcula_valor_total(self):
        meses = self.calcula_meses()
        total = meses * self.valor_mensal

        return total

    #Defnição da subClasse - ReparacaoTelhado (precisamos respeitar número de parâmetros da superClasse - Pai)
    #Por herdar os métodos da super classe pai (Servico), para poder usá-los diretamente.
    #Inicializar os atributos da superClasse - (Pai)


class ReparacaoTelhado(Servico):
    #Construtor da subclasse Reparação do Telhado
    def __init__(self, nome_servico, empresa, valor_mensal, areaMetro2_telhado, valor_Metro2, tipo_cobertura="telha", garantia_meses=12, meses_empreitada=3):
        
    #Atributos herdados da superClasse Pai 
        super().__init__(nome_servico, empresa, valor_mensal)

    #atributos da subclasse ReparacaoTelhado         
        self.areaMetro2_telhado = float(areaMetro2_telhado)
        self.valor_Metro2 = float(valor_Metro2)
        self.tipo_cobertura = tipo_cobertura
        self.garantia_meses = garantia_meses
        self.meses_empreitada = meses_empreitada

    #Método sobreposto (mesmo nome da superclasse, código diferente)   
    def calcula_valor_total(self):
    #Sobrescreve o método da superclasse para incluir, valor das mensalidades (superclasse), custo adicional (área do telhado em M2)
    #Calcula valor das mensalidades (igual ao pai)       
        total_mensalidades = self.meses_empreitada * self.valor_mensal
        
    #Calcula custo adicional específico de telhado (DIFERENTE do pai)
        custo_area = self.areaMetro2_telhado * self.valor_Metro2
        
    #Calcula o valor total combinado para reparo do telhado
        total_completo = total_mensalidades + custo_area
        
        return total_completo
    
    #Método exclusivo da subclasse ReparacaoTelhado, que verifica se o reparo realizado ainda possui garantia
    def verifica_garantia(self):
    #Usa o método calcula.meses() da classe principal para calcular o tempo passado após conclusão do servico de João    
        meses_decorridos = self.calcula_meses()
    #Se os meses decorridos após a entrega do serviço forem menores ou igual ao total da garantia, informa ao operador os meses que restam.
        if meses_decorridos <= self.garantia_meses:
            meses_restantes = self.garantia_meses - meses_decorridos
            return f"Ainda em garantia! Restam {meses_restantes} meses de cobertura."
        else:
    #Caso contrário, informa ao operador a quantidade de meses que a garantia já está expirada.
            meses_expirados = meses_decorridos - self.garantia_meses
            return f"Garantia expirada há {meses_expirados} meses."
        
# Definindo a Função para limpar a tela, usando'cls' para windows, caso contrário, clear para Linux
def limpar_tela():
    os.system('cls' if os.name == 'nt' else 'clear')        
# Uso da Função principal (MAIN) para testar os serviços construídos em ambas: superclasse Servico() e subclasse ReparacaoTelhado()

#Criando a função principal (MAIN)
def main():
    
    print("""
    ==== Menu ====
    1 - Testar Superclasse - Serviço Internet MEO
    2 - Testar Subclasse - Reparação de Telhado
    3 - Testar Previsão para o Reparo do Telhado
    0 - Sair 
    """)
#Uso do while para fazer o loop do Menu, enquanto não for digitado o 0 para encerrar o programa com o comando ('break')
    while True:
        opcao = int(input("Escolha uma das seguintes opções [1, 2, 3, ou 0 para sair]: "))
#Uso do condicional if, para permitir escolha dentre duas opções de testes: (1)superclasse Servico ou (2)subclasse ReparacaoTelhado.
#Caso escolhida a opção 1 - instância a superclasse - Servico e mostra os resultados de três métodos chamados:         
        if opcao == 1:
            print("\n--- TESTE: Serviço Internet ---\n")
            servico = Servico("Internet", "MEO", 175.00)
            print(servico.descricao_servico())
            print(f"O pagamento deste serviço a empresa {servico.empresa} já decorre: {servico.calcula_meses()} meses")
            print(f"O valor total pago ao serviço da empresa {servico.empresa} até presente data é de: {servico.calcula_valor_total()} Euros\n")
#Caso escolhida a opção 2 - instância a subclasse ReparaçãoTelhado como 'telhado 1', mostra resultados de dois métodos chamados:        
        elif opcao == 2:
            print("\n--- TESTE: Reparação de Telhado ---\n")
            telhado1 = ReparacaoTelhado("Telhado", "Repara Tudo S.A", 1000, 60, 60)
            print(f"O Valor total para a reparação do telhado pela empresa {telhado1.empresa} será de: {telhado1.calcula_valor_total()} Euros")
            print(f"O Status do serviço - reparo no telhado de 'Manoel' pela empresa {telhado1.empresa} é: {telhado1.verifica_garantia()}\n")
#Caso escolhida a opção 3 - instância a subclasse ReparaçãoTelhado como 'telhado 2', obtêm metro quadrado do telhado,
#calcula o tempo gasto para reparação do telhado, baseado no tamanho do seu metro quadrado: 
        elif opcao == 3:
            print("\n--- TESTE: Tempo Estimado para Reparação do Telhado ---\n")
    #Obter a área do telhado da subclasse ReparacaoTelhado
            telhado2 = ReparacaoTelhado("Telhado", "Repara Tudo S.A", 1000, 120, 60)
            m2 = telhado2.areaMetro2_telhado
    
    #Calcular o tempo estimado por m² (reparos extensos)
    #0.12 dias por m² é um vaalor padrão estimado
            tempo_por_m2 = 0.12
    
    #Usar list compreehension para gerar lista de tempo para cada m² até chegar ao cálulo da área total
            lq = [nr * tempo_por_m2 for nr in range(1, int(m2) + 1)]

    #Mostrar na tela a área do telhado em metros quadrados e o tempo previsto para conclusão do reparo
            print(f"Área do telhado: {m2} m²")
            print(f"Tempo estimado total para reparo: {m2 * tempo_por_m2:.0f} dias")

  #Caso a opção escolhida pelo operador seja 0, mostra a mensagem de Volte Sempre e encerra o programa         
        elif opcao == 0:
            print("Volte sempre!!!")
            break
  #Caso a opção escolhida pelo operador seja diferente de (1, 2, 3 ou 0)  - operador será informado da opção inválida 
  #peritirár que se escolha uma novamente uma opção.       
        else:
            print("Opção inválida\n")

#Chamada da função principal (MAIN). Local de inicialização de todo o programa.
#Chamada de função utilizada para limpar a tela após encerramento do programa.

main()
limpar_tela()