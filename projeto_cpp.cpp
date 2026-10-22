#include <iostream>
#include <string>

#define MAX 10

using namespace std;

// Definição das Estruturas
struct Cliente {
    int id;
    string nome;
    string telefone;
};

struct Filme {
    int codigo;
    string titulo;
    string genero;
    int ano;
    int idCliente;
};

// Função simples para cadastrar cliente
void cadastrarCliente(Cliente vet[], int i) {
    cout << "\nDigite o ID do cliente: ";
    cin >> vet[i].id;
    cin.ignore(); // Limpa o buffer antes do getline

    cout << "Digite o nome: ";
    getline(cin, vet[i].nome);

    cout << "Digite o telefone: ";
    getline(cin, vet[i].telefone);

    cout << "Cliente cadastrado com sucesso!\n";
}

// Função simples para cadastrar filme
void cadastrarFilme(Filme vet[], int i) {
    cout << "\nDigite o codigo do filme: ";
    cin >> vet[i].codigo;
    cin.ignore();

    cout << "Digite o titulo: ";
    getline(cin, vet[i].titulo);

    cout << "Digite o genero: ";
    getline(cin, vet[i].genero);

    cout << "Digite o ano: ";
    cin >> vet[i].ano;

    cout << "Digite o ID do cliente que alugou: ";
    cin >> vet[i].idCliente;

    cout << "Filme cadastrado com sucesso!\n";
}

int main() {
    // Vetores fixos como na Prática 8.1
    Cliente listaClientes[MAX];
    Filme listaFilmes[MAX];

    int contClientes = 0;
    int contFilmes = 0;
    int opcao;

    while(true) {
        cout << "\n##################### MENU #####################\n";
        cout << "1 - Cadastrar Cliente\n";
        cout << "2 - Cadastrar Filme\n";
        cout << "3 - Mostrar Clientes\n";
        cout << "4 - Mostrar Filmes\n";
        cout << "5 - Buscar Filmes por Cliente\n";
        cout << "6 - Relatorio Geral\n";
        cout << "0 - Sair\n";
        cout << "################################################\n\n";
        cout << "Digite sua opcao: ";
        cin >> opcao;

        if(opcao == 0) {
            cout << "Encerrando o programa...\n";
            break;
        }

        switch(opcao) {
            case 1:
                if(contClientes < MAX) {
                    cadastrarCliente(listaClientes, contClientes);
                    contClientes++;
                } else {
                    cout << "Vetor cheio!\n";
                }
                break;

            case 2:
                if(contClientes == 0) {
                    cout << "Cadastre um cliente primeiro!\n";
                } else if(contFilmes < MAX) {
                    cadastrarFilme(listaFilmes, contFilmes);
                    contFilmes++;
                } else {
                    cout << "Vetor cheio!\n";
                }
                break;

            case 3:
                cout << "\n=== CLIENTES CADASTRADOS ===\n";
                for(int i = 0; i < contClientes; i++) {
                    cout << "-----------------------------------\n";
                    cout << "ID: " << listaClientes[i].id << endl;
                    cout << "Nome: " << listaClientes[i].nome << endl;
                    cout << "Telefone: " << listaClientes[i].telefone << endl;
                }
                break;

            case 4:
                cout << "\n=== FILMES CADASTRADOS ===\n";
                for(int i = 0; i < contFilmes; i++) {
                    cout << "-----------------------------------\n";
                    cout << "Codigo: " << listaFilmes[i].codigo << endl;
                    cout << "Titulo: " << listaFilmes[i].titulo << endl;
                    cout << "Genero: " << listaFilmes[i].genero << endl;
                    cout << "Ano: " << listaFilmes[i].ano << endl;

                    // Procura o nome do cliente usando o ID de forma direta
                    for(int j = 0; j < contClientes; j++) {
                        if(listaClientes[j].id == listaFilmes[i].idCliente) {
                            cout << "Alugado para: " << listaClientes[j].nome << endl;
                        }
                    }
                }
                break;

            case 5: {
                int idBusca;
                cout << "\nDigite o ID do cliente para buscar os filmes: ";
                cin >> idBusca;

                cout << "\nFilmes encontrados:\n";
                for(int i = 0; i < contFilmes; i++) {
                    if(listaFilmes[i].idCliente == idBusca) {
                        cout << "- " << listaFilmes[i].titulo << endl;
                    }
                }
                break;
            }

            case 6:
                cout << "\n=== RELATORIO GERAL ===\n";
                for(int i = 0; i < contClientes; i++) {
                    int totalAlugado = 0;

                    // Conta quantos filmes pertencem a este cliente
                    for(int j = 0; j < contFilmes; j++) {
                        if(listaFilmes[j].idCliente == listaClientes[i].id) {
                            totalAlugado++;
                        }
                    }

                    cout << "Cliente: " << listaClientes[i].nome;
                    cout << " | Filmes Alugados: " << totalAlugado << endl;
                }
                break;

            default:
                cout << "Opcao invalida. Digite novamente.\n\n";
                break;
        }
    }

    return 0;
}
