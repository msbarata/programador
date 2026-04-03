import sqlite3 as sl

import pandas as pd
 
connector= sl.connect("C:/Users/carla/OneDrive/Ambiente de Trabalho/chinook/chinook.db")
 
cursor = connector.cursor()

cursor.execute("""SELECT * FROM albums;""")
 
 
resultado = cursor.fetchall()
 
connector.close()
 
df = pd.DataFrame(resultado, columns=['Id do album', 'Nome do album', 'Id do Artista'])
 
print(df.head())
 