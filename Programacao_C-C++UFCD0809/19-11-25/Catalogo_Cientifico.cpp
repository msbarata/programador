https://onlinegdb.com/K1g1GbYE7k

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

void clear(int segundos){
    sleep(segundos);
    cout << "\x1b[2J\x1b[H";
}

void catalogo()
{
    string nome, recurso, endereco;

    cout << "Bem vindo Estudante! Informe o seu nome: " << endl;
    cin >> nome;

    cout << "Informe o assunto do seu recurso educacional: " << endl;
    cin >> recurso;

    cout << "Informe o endereço eletrônico de seu recurso educacional: " << endl;
    cin >> endereco;
    clear(2);

    string nomeFile = nome + ".sav";
    ofstream out(nomeFile, ios::app);

    if (!out) {
        cout << "Erro ao criar o arquivo!" << endl;
       return;
    }

    out << nome << endl;
    out << recurso << endl;
    out << endereco << endl;
    out.close();

    cout << "\nArquivo salvo com sucesso!" << endl;
    clear(2);
   
    string nomeLido, assuntoLido, enderecoLido;
    ifstream in(nomeFile);

    if (!in) {
        cout << "Erro ao abrir o arquivo para leitura!" << endl;
       return;
    }
    
    while (true) {

    getline(in, nomeLido);
    getline(in, assuntoLido);
    getline(in, enderecoLido);
   
    if (!in) break;
    
cout << "| Assunto              | " << setw(27) << left << assuntoLido   << "|" << endl;
cout << "| URL                  | " << setw(27) << left << enderecoLido  << "|" << endl;

cout << "+----------------------+-----------------------------+" << endl;
    
        
    }
     in.close();
     cout << "\n**|| Catálogo Científico de " << nome << ": |**" << endl;
     
    }
 
 int main() {
    catalogo();
    return 0;
}