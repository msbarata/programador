#Importa Dados de Arquivo para Dataframe Panda

#import pandas as pd

#excel_dados = pd.read_excel('C:/Python/excel_dados.xlsx')

#rint(excel_dados.head(3))
#print(excel_dados.tail(3))

import sqlite3

conn = sqlite3.connect("banco.db")
cursor = conn.cursor()

cursor.execute("CREATE TABLE IF NOT EXISTS teste (id INTEGER PRIMARY KEY, nome TEXT)")
conn.commit()
conn.close()

print("Banco criado com sucesso")
