#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int Max = 200;

// Estrutura que representa um imóvel
struct Imovel {
    string tipo, finalidade, endereco, bairro, cidade;
    float area, valor, IPTU;
    int quartos, suites, banheiros, vagas;
    string cozinha, sala, varanda, area_servico, piso, conservacao;
    string armarios, ar_condicionado, aquecedor, ventilador;
};

// Função para escrever os dados de um imóvel no arquivo
void escreverDados(ofstream &arquivo, const Imovel &imovel) {
    arquivo << imovel.tipo << " " << imovel.finalidade << " " << imovel.endereco << " " << imovel.bairro << " "
            << imovel.cidade << " " << imovel.area << " " << imovel.valor << " " << imovel.IPTU << " "
            << imovel.quartos << " " << imovel.suites << " " << imovel.banheiros << " "
            << imovel.vagas << " " << imovel.cozinha << " " << imovel.sala << " "
            << imovel.varanda << " " << imovel.area_servico << " "
            << imovel.piso << " " << imovel.conservacao << " "
            << imovel.armarios << " " << imovel.ar_condicionado << " "
            << imovel.aquecedor << " " << imovel.ventilador << endl;
}

// Função para carregar os imóveis do arquivo para o vetor
int carregarImoveis(Imovel imoveis[], int &n) {
    ifstream arq("BD_imoveis.txt");
    if (!arq) return 0; // Arquivo não encontrado
    n = 0;
    string primeiraLinha;
    getline(arq, primeiraLinha); // Ignora a primeira linha do arquivo (cabeçalho)
    while (n < Max) {
        Imovel im;
        arq >> im.tipo;
        if (im.tipo == "fim" || arq.eof()) break;
        // Leitura dos campos restantes
        arq >> im.finalidade >> im.endereco >> im.bairro >> im.cidade >> im.area >> im.valor >> im.IPTU
            >> im.quartos >> im.suites >> im.banheiros >> im.vagas >> im.cozinha >> im.sala >> im.varanda
            >> im.area_servico >> im.piso >> im.conservacao >> im.armarios >> im.ar_condicionado
            >> im.aquecedor >> im.ventilador;
        if (arq.fail()) break; // Erro de leitura
        imoveis[n++] = im;
    }
    arq.close();
    return n;
}

// Função para salvar os imóveis do vetor no arquivo
void salvarImoveis(Imovel imoveis[], int n) {
    ofstream arq("BD_imoveis.txt");
    // Escreve o cabeçalho no arquivo
    arq << "tipo finalidade endereco bairro cidade area valor IPTU quartos suites banheiros vagas cozinha sala varanda area_servico piso conservacao armarios ar_condicionado aquecedor ventilador" << endl;
    for (int i = 0; i < n; ++i) {
        escreverDados(arq, imoveis[i]);
    }
    arq << "fim" << endl; // Marca o fim do arquivo
    arq.close();
}

// Função para incluir um novo imóvel no vetor
void incluirImovel(Imovel imoveis[], int &n) {
    if (n >= Max) {
        cout << "Limite de imóveis atingido." << endl;
        return;
    }
    Imovel im;
    cout << "Digite os dados do imóvel:" << endl;
    cout << "Tipo: (casa, apartamento, comercial, terreno): ";
    cin >> im.tipo;
    cout << "Finalidade: (venda, locacao, temporada): ";
    cin >> im.finalidade;
    cout << "Endereço: ";
    cin >> im.endereco;
    cout << "Bairro: ";
    cin >> im.bairro;
    cout << "Cidade: ";
    cin >> im.cidade;
    cout << "Área (em m²): ";  
    cin >> im.area;
    cout << "Valor: ";
    cin >> im.valor;
    cout << "IPTU: ";
    cin >> im.IPTU;
    cout << "Quartos: ";
    cin >> im.quartos;
    cout << "Suítes: ";
    cin >> im.suites;
    cout << "Banheiros: ";
    cin >> im.banheiros;
    cout << "Vagas: ";
    cin >> im.vagas;
    cout << "Cozinha (sim/nao): ";
    cin >> im.cozinha;
    cout << "Sala (sim/nao): ";
    cin >> im.sala;
    cout << "Varanda (sim/nao): ";
    cin >> im.varanda;
    cout << "Área de serviço (sim/nao): ";
    cin >> im.area_servico;
    cout << "Piso (ceramica, madeira, laminado, etc): ";
    cin >> im.piso;
    cout << "Conservação (bom, regular, ruim): ";
    cin >> im.conservacao;
    cout << "Armários (sim/não): ";
    cin >> im.armarios;
    cout << "Ar-condicionado (sim/não): ";
    cin >> im.ar_condicionado;
    cout << "Aquecedor (sim/não): ";
    cin >> im.aquecedor;
    cout << "Ventilador (sim/não): ";
    cin >> im.ventilador;
    imoveis[n++] = im;
    cout << "Imóvel incluído com sucesso." << endl;
}

// Busca imóvel pelo endereço (rua)
int buscarImovelPorRua(Imovel imoveis[], int n, const string &rua) {
    for (int i = 0; i < n; ++i) {
        if (imoveis[i].endereco == rua) return i;
    }
    return -1;
}

// Exclui imóvel do vetor, deslocando os demais para a esquerda
void excluirImovel(Imovel imoveis[], int &n, int idx) {
    for (int i = idx; i < n - 1; ++i) {
        imoveis[i] = imoveis[i + 1];
    }
    n--;
    cout << "Imóvel excluído." << endl;
}

// Busca imóveis por faixa de valor
void buscarPorFaixaValor(Imovel imoveis[], int n) {
    float vmin, vmax;
    cout << "Digite o valor mínimo e máximo: ";
    cin >> vmin >> vmax;
    for (int i = 0; i < n; ++i) {
        if (imoveis[i].valor >= vmin && imoveis[i].valor <= vmax) {
            cout << "Imóvel: " << imoveis[i].endereco << " - Valor: " << imoveis[i].valor << endl;
        }
    }
}

// Busca imóveis por característica (armários, ar-condicionado, etc)
void buscarPorCaracteristica(Imovel imoveis[], int n) {
    string carac;
    cout << "Digite a característica (armarios, ar_condicionado, aquecedor, ventilador): ";
    cin >> carac;
    for (int i = 0; i < n; ++i) {
        if ((carac == "armarios" && imoveis[i].armarios == "sim") ||
            (carac == "ar_condicionado" && imoveis[i].ar_condicionado == "sim") ||
            (carac == "aquecedor" && imoveis[i].aquecedor == "sim") ||
            (carac == "ventilador" && imoveis[i].ventilador == "sim")) {
            cout << "Imóvel: " << imoveis[i].endereco << endl;
        }
    }
}

// Busca imóveis por número de quartos e suítes
void buscarPorQuartosSuites(Imovel imoveis[], int n) {
    int q, s;
    cout << "Digite o número de quartos e suítes: ";
    cin >> q >> s;
    for (int i = 0; i < n; ++i) {
        if (imoveis[i].quartos == q && imoveis[i].suites == s) {
            cout << "Imóvel: " << imoveis[i].endereco << endl;
        }
    }
}

// Relatório de estatísticas dos imóveis
void relatorioEstatisticas(Imovel imoveis[], int n) {
    int venda = 0, locacao = 0, temporada = 0, casasComSuites = 0, salasComCeramica = 0;
    for (int i = 0; i < n; ++i) {
        if (imoveis[i].finalidade == "venda") venda++;
        if (imoveis[i].finalidade == "locacao") locacao++;
        if (imoveis[i].finalidade == "temporada") temporada++;
        if (imoveis[i].finalidade == "venda" && imoveis[i].suites > 0) casasComSuites++;
        if (imoveis[i].tipo == "comercial" && imoveis[i].piso == "ceramica") salasComCeramica++;
    }
    cout << "Total de imóveis: " << n << endl;
    if (n > 0) {
        cout << "Porcentagem para venda: " << (venda * 100.0 / n) << "%" << endl;
        cout << "Porcentagem para locação: " << (locacao * 100.0 / n) << "%" << endl;
        cout << "Porcentagem para temporada: " << (temporada * 100.0 / n) << "%" << endl;
        cout << "Porcentagem de casas com suítes: " << (casasComSuites * 100.0 / n) << "%" << endl;
        cout << "Porcentagem de salas comerciais com piso cerâmica: " << (salasComCeramica * 100.0 / n) << "%" << endl;
    }
}

// Lista todos os imóveis cadastrados
void listarImoveis(Imovel imoveis[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Imóvel " << i + 1 << ": " << imoveis[i].tipo << " " << imoveis[i].finalidade << " " << imoveis[i].endereco << " " << imoveis[i].bairro << " "
             << imoveis[i].cidade << " " << imoveis[i].area << " " << imoveis[i].valor << " " << imoveis[i].IPTU << " "
             << imoveis[i].quartos << " " << imoveis[i].suites << " " << imoveis[i].banheiros << " "
             << imoveis[i].vagas << " " << imoveis[i].cozinha << " " << imoveis[i].sala << " "
             << imoveis[i].varanda << " " << imoveis[i].area_servico << " "
             << imoveis[i].piso << " " << imoveis[i].conservacao << " "
             << imoveis[i].armarios << " " << imoveis[i].ar_condicionado << " "
             << imoveis[i].aquecedor << " " << imoveis[i].ventilador << endl;
    }
}

int main() {
    Imovel imoveis[Max];
    int n = 0;
    carregarImoveis(imoveis, n); // Carrega imóveis do arquivo

    int opcao;
    do {
        cout << "\nMenu:\n";
        cout << "1 - Incluir novo imóvel\n";
        cout << "2 - Buscar imóvel por rua\n";
        cout << "3 - Buscar imóveis por faixa de valor\n";
        cout << "4 - Buscar imóveis por característica\n";
        cout << "5 - Buscar imóveis por número de quartos e suítes\n";
        cout << "6 - Relatório de estatísticas\n";
        cout << "7 - Listar todos os imóveis\n";
        cout << "8 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                incluirImovel(imoveis, n);
                break;
            case 2: {
                string rua;
                cout << "Digite a rua do imóvel: ";
                cin >> rua;
                int idx = buscarImovelPorRua(imoveis, n, rua);
                if (idx != -1) {
                    cout << "Imóvel encontrado: " << imoveis[idx].endereco << endl;
                    string exc;
                    cout << "Deseja excluir este imóvel? (s/n/sim): ";
                    cin >> exc;
                    if (exc == "s" || exc == "S" || exc == "sim" || exc == "Sim") {
                        excluirImovel(imoveis, n, idx);
                    }
                    else {
                        cout << "Imóvel mantido." << endl;
                    }
                } else {
                    cout << "Imóvel não encontrado." << endl;
                }
                break;
            }
            case 3:
                buscarPorFaixaValor(imoveis, n);
                break;
            case 4:
                buscarPorCaracteristica(imoveis, n);
                break;
            case 5:
                buscarPorQuartosSuites(imoveis, n);
                break;
            case 6:
                relatorioEstatisticas(imoveis, n);
                break;
            case 7:
                listarImoveis(imoveis, n);
                break;
            case 8:
                salvarImoveis(imoveis, n); // Salva imóveis no arquivo ao sair
                cout << "Saindo e salvando dados..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 8);

    return 0;
}
