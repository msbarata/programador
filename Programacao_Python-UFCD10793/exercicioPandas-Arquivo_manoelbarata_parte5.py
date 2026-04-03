# Interface à Base de Dados tipo SQLITE
import pandas as pd 

import sqlite3 as sl
connector= sl.connect("C:/Python/chinook.db")

#Uso do método cursor

cursor = connector.cursor()
cursor.execute("""select * from albums;""")
#Uso do método fetchall

resultado = cursor.fetchall()

connector.close()

#df = pd.DataFrame(resultado)
df = pd.DataFrame(resultado, columns=['Id do album', 'Nome do album', 'Id do Artista'])
print (df.head)
print (df.tail)

#print(resultado[2])
#print(type(resultado[0]))

#for album in resultado:
    #print(album)

#for album in resultado:
    #print(album[1])


