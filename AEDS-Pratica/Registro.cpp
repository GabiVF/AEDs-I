#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    // Criar o arquivo de texto onde os dados serão salvos
    ofstream arquivo("agenda.txt");
    if (!arquivo.is_open())
    {
        cout << "\nErro: não foi possível criar o arquivo.\n";
        return 1;
    }

    // registro
    typedef struct
    {
        char nome[20];
        string email;
        int celular;
        string cidade;

    } contato; // Definindo o tipo de dado "pessoa"

    contato reg1;
    int opcao = 0;
    while (true)
    {
        cout << "\n--- MENU DE OPÇÕES ---\n";
        cout << "1 - salvar um contato novo\n";
        cout << "2 - visualizar todos os contatos\n";
        cout << "3 - pesquisar contato\n";
        cout << "4 - excluir um contato\n";
        cout << "5 - alterar um contato\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {

        case 0:
            cout << "Saindo do programa...\n";
            return 0;

        case 1:
        {
            // Solicita os dados da pessoa
            cout << "Nome: ";
            cin >> reg1.nome;
            cout << "Email: ";
            cin >> reg1.email;
            cout << "Celular: ";
            cin >> reg1.celular;
            cout << "Cidade: ";
            cin >> reg1.cidade;

            // Escreve os dados no arquivo (modo append)
            ofstream arquivo("agenda.txt");
            if (!arquivo.is_open())
            {
                cout << "\nErro: não foi possível abrir o arquivo.\n";
                break;
            }
            arquivo << reg1.nome << endl;    // Escreve o nome no arquivo
            arquivo << reg1.email << endl;   // Escreve o email no arquivo
            arquivo << reg1.celular << endl; // Escreve o celular no arquivo
            arquivo << reg1.cidade << endl;  // Escreve a cidade no arquivo
            arquivo.close();
            cout << "Registro salvo com sucesso!" << endl;
            break;
        }

        case 2:
        {
            // Lê os dados do arquivo e exibe na tela
            ifstream arquivoLeitura("agenda.txt");
            if (!arquivoLeitura.is_open())
            {
                cout << "\nErro: não foi possível abrir o arquivo.\n";
                break;
            }
            cout << "\n--- CONTATOS SALVOS ---\n";
            while (arquivoLeitura >> reg1.nome >> reg1.email >> reg1.celular >> reg1.cidade)
            {
                cout << "Nome: " << reg1.nome << endl;
                cout << "Email: " << reg1.email << endl;
                cout << "Celular: " << reg1.celular << endl;
                cout << "Cidade: " << reg1.cidade << endl;
                cout << "------------------------" << endl;
            }
            arquivoLeitura.close();
            break;
        }
        case 3:
        {
            // Pesquisa um contato pelo nome
            string nomePesquisa;
            string encontrado;
            cout << "Digite o nome do contato a ser pesquisado: ";
            cin >> nomePesquisa;

            ifstream arquivoPesquisa("agenda.txt");
            if (!arquivoPesquisa.is_open())
            {
                cout << "\nErro: não foi possível abrir o arquivo.\n"
                     << endl;
                break;
            }
            for (encontrado = "falso"; arquivoPesquisa >> reg1.nome >> reg1.email >> reg1.celular >> reg1.cidade;)
            {
                if (nomePesquisa == reg1.nome)
                {
                    cout << "Contato encontrado!" << endl;
                    cout << "Nome: " << reg1.nome << endl;
                    cout << "Email: " << reg1.email << endl;
                    cout << "Celular: " << reg1.celular << endl;
                    cout << "Cidade: " << reg1.cidade << endl;
                    encontrado = "verdadeiro";
                    break;
                }
            }
            if (encontrado == "falso")
            {
                cout << "Contato não encontrado." << endl;
            }
            arquivoPesquisa.close();
            break;
        }
        case 4:
        {
            string excluir;
            string encontrado;

            cout << "Digite o nome do contato que deseja excluir: ";
            cin >> excluir;

            ifstream arquivopesquisa("agenda.txt");
            if (!arquivopesquisa.is_open())
            {
                cout << "\nErro: não foi possível abrir o arquivo.\n";
                break;
            }
            for (encontrado = "falso"; arquivopesquisa >> reg1.nome >> reg1.email >> reg1.celular >> reg1.cidade;)
            {
                if (excluir == reg1.nome)
                cout << "Contato não encontrado." << endl;
                break;
            }
        }
        case 5:
        {
            string alterar;
            string encontrado;

            cout << "Digite o contado que deseja alterar:";
            cout << "Opção inválida." << endl;
            break;

            cin >> alterar;

            ifstream arquivopesquisa("agenda.txt");
            if (!arquivopesquisa.is_open())
            {
                cout << '\nErro: não foi possivel abrir o arquivo.\n';
                break;
            }
            for (encontrado = "falso"; arquivopesquisa >> reg1.nome >> reg1.email >> reg1.celular >> reg1.cidade;)
            {
                if (alterar == reg1.nome)

                {
                    cout << "O que deseja alterar?" << endl;
                    cin >> alterar;
                    if (alterar == "nome")
                    {
                        cout << "Digite o novo nome: ";
                        cin >> reg1.nome;
                    }
                    else if (alterar == "email")
                    {
                        cout << "Digite o novo email: ";
                        cin >> reg1.email;
                    }
                    else if (alterar == "celular")
                    {
                        cout << "Digite o novo número de celular:";
                        cin >> reg1.celular;
                    }
                    else if (alterar == "cidade")
                    {
                        cout << "Digite a nova cidade: ";
                        cin >> reg1.cidade;
                    }
                    else if (alterar == "sair")
                    {
                        cout << "Voltando ao menu" << endl;
                        break;
                        ;
                    }
                    else
                    {
                        cout << "Opção inválida." << endl;
                        continue;
                    }
                }
            }
        }
        }
    }

    return 0;
}