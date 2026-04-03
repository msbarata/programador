import pandas as pd
#Importa Dados de Arquivo para Dataframe Panda
#csv_dados = pd.read_excel('C:/Python/csv_dados.xls')
#print(csv_dados.head(3))


import pandas as pd

csv_dados = pd.read_excel('C:/Python/csv_dados.xls', engine='xlrd')

print(csv_dados.head(3))
print(csv_dados.tail(4))
