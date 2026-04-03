
#Definição da função tri-meses (acessa as informações e apresenta os meses que compõem cada trimestre)
def tri_meses(trimestre):
    
    #Condicional IF, verifica se o valor digitado pelo usuário é válido (se está entre 1 a 4), caso contrário, informa ao usuário
    #e encerra o programa.
    if trimestre < 1 or trimestre > 4:
        print("Opção errada! Escolha um trimestre entre 1 e 4.")
        return
    else:

    #Criação de lista MESES e armazenamento de informações, acessadas por meio do índice posicional para cada um dos trimestres e
    # suas respetivas sublistas de meses   
     MESES = [
    ['primeiro', ['janeiro', 'fevereiro', 'março']],
    ['segundo', ['abril', 'maio', 'junho']],
    ['terceiro', ['julho', 'agosto', 'setembro']],
    ['quarto', ['outubro', 'novembro', 'dezembro']]
]  
    # Converte os valores inteiros do trimestre (1-4) para índice da lista (0-3)
    indice = trimestre - 1
    
    # Acede aos dados do trimestre
    #Variável nome-trimestre recebe o valor armazenado na posição 0 do índice de lista MESES
    nome_trimestre = MESES[indice][0]
    #Variável lista-meses recebe os valores armazenados na sublista de posição 1 do índice de lista MESES
    lista_meses = MESES[indice][1]
    
    # Imprime as informações
    # Imprime o nome do trimestre contido na variável nome_trimestre, conforme o valor numérico do trimestre informado pelo usuário
    print(f"O {nome_trimestre} trimestre contém os seguintes meses:")
    # Imprime todos os valores 'meses' contidos na variável lista-meses, conforme o valor numérico do trimestre informado pelo usuário
    for mes in lista_meses:
        print(f"  - {mes}")
    
#Definição da função principal main() - Recebe o valor do trimestre em inteiro e remete para a função tri-meses
def main():

    #Realiza a entrada do valor numérico referente ao trimestre à ser consultado, informado pelo usuário:    
    trimestre = int(input("Digite o número do trimestre [1 a 4]: "))

    #Envia os parâmetros para a função tri_meses, por meio da variável trimestre
    tri_meses(trimestre)

#Aciona a função principal main
main()