
#Criação de Dicionário MESES, com chaves numéricas pelos trimestres [1,2,3,4]:
MESES = {
    1: {
        'nomeTrim': 'primeiro',
        'meses': {
            1: 'janeiro',
            2: 'fevereiro',
            3: 'março'
        }
    },
    2: {
        'nomeTrim': 'segundo',
        'meses': {
            4: 'abril',
            5: 'maio',
            6: 'junho'
        }
    },
    3: {
        'nomeTrim': 'terceiro',
        'meses': {
            7: 'julho',
            8: 'agosto',
            9: 'setembro'
        }
    },
    4: {
        'nomeTrim': 'quarto',
        'meses': {
            10: 'outubro',
            11: 'novembro',
            12: 'dezembro'
        }
    }
}

#Entrada do valor numérico referente ao trimestre a ser consultado, informado pelo usuário:
trimestre = int(input("Digite o número do trimestre [1 a 4]: "))

# Usa get() para obter os dados do dicionário MESES, referente ao trimestre informado pelo usuário, e armazena na variável trim_data:
trim_data = MESES.get(trimestre)

# Condição if/else para tratar a escolha; Se valor do trimestre for de [1 a 4] o programa segue, caso contrário é tratado pelo 'else'.
if trim_data:
    # Obtém os valores usando get(); a variável nome_trimestre recebe o valor contido na chave 'nomeTrim' do dicionário:
    nome_trimestre = trim_data.get('nomeTrim')

    # Obtém os valores usando get(); a variável meses recebe os valores contidos na chave 'meses' do dicionário:
    meses = trim_data.get('meses')
    
    # Imprime o resultado final, contendo o texto de exibição e as duas variáveis configuradas com %s:      
    print("Meses do %s trimestre: %s" % (nome_trimestre, meses))
#Encerra programa e informa ao usuário para escolher uma outra opção, devido ao valor numérico do trimestre não constar como chave válida
# para o dicionario MESES. 
else:
    print("Opção errada! Escolha um trimestre entre 1 e 4.")