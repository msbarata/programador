import pandas as pd
#Criação do dicionário alunos com suas notas
alunos = {'Nome':['Maria', 'Pedro', 'Carla'],
          'Nota':[13,8,16],
          'Nota Final':['Aprovado', 'Reprovado', 'Aprovado']}

#Converter o dicionário numa Dataframe de Pandas
df_alunos=pd.DataFrame(alunos)
print(alunos)
print(df_alunos)
