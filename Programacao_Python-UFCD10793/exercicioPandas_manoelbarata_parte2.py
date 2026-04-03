import pandas as pd
#Criação do dicionário pessoas com suas profissões
cadastro = {'Nomes':['Carla', 'Miguel', 'Pedro'],
          'Idades':[51,42,46],
          'Profissões':['Bailarina', 'Actor', 'Mecânico']}

#Converter o dicionário numa Dataframe de Pandas
df_colaboradores=pd.DataFrame(cadastro)
#print(cadastro)
#print(df_colaboradores)

#print(type (df_colaboradores))

print (df_colaboradores.describe())

