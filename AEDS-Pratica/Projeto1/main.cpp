/******************************************************************************
 * PROJETO: Gerenciador de Imóveis
 *
 * DESCRIÇÃO:
 * Este aplicativo gerencia um banco de dados de imóveis, lendo e escrevendo
 * informações em um arquivo texto. Permite ao usuário realizar operações de
 * inclusão, exclusão, busca e geração de relatórios estatísticos sobre os
 * dados carregados em um vetor de registros.
 *
 * AUTORES: Gustavo de Sousa Zimmermann, Gabriela Vinha Feitosa
 * DISCIPLINA: AEDs I
 *****************************************************************************/

// Inclusão de bibliotecas padrão
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits> 

// Usando o namespace std para evitar a necessidade de std:: ao longo do código
using namespace std;

// Estrutura de dados para armazenar informações de um imóvel 
struct Imovel {
    string tipo;
    string finalidade;
    string endereco;
    string bairro;
    string cidade;
    double area;
    string valor;
    double iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    bool cozinha;
    bool sala;
    bool varanda;
    bool area_de_servico;
    string piso;
    string conservacao;
    bool armarios;
    bool ar_condicionado;
    bool aquecedor;
    bool ventilador;
};

//FUNÇÕES AUXILIARES

// Converte string "sim" ou "nao" para booleano
bool stringParaBool(const string& s) {
    return s == "sim";
}

// Converte booleano para string "sim" ou "nao"
string boolParaString(bool b) {
    return b ? "sim" : "nao";
}

// Extrai o valor numérico de uma string de valor do imóvel
// Lida com formatos como "500000" ou "300/dia"
double extrairValorNumerico(const string& valorStr) {
    try {
        return stod(valorStr);
    } catch (const invalid_argument&) {
        size_t pos = valorStr.find('/');
        if (pos != string::npos) {
            try {
                return stod(valorStr.substr(0, pos));
            } catch (const invalid_argument&) {
                return 0.0;
            }
        }
        return 0.0;
    }
}

// Limpa o buffer de entrada do teclado
void limparBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função auxiliar para ler um valor numérico (double) com validação
double lerDouble(const string& prompt) {
    double valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero valido.\n";
            cin.clear(); // Limpa o estado de erro
            limparBufferEntrada(); // Limpa o buffer de entrada
        } else {
            limparBufferEntrada(); // Limpa o buffer após leitura bem-sucedida
            return valor;
        }
    }
}

// Função auxiliar para ler um valor numérico (int) com validação
int lerInt(const string& prompt) {
    int valor;
    while (true) {
        cout << prompt;
        cin >> valor;
        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero inteiro valido.\n";
            cin.clear(); // Limpa o estado de erro
            limparBufferEntrada(); // Limpa o buffer de entrada
        } else {
            limparBufferEntrada(); // Limpa o buffer após leitura bem-sucedida
            return valor;
        }
    }
}

// Função auxiliar para ler uma string booleana com validação "sim" ou "nao"
bool lerBool(const string& prompt) {
    string resposta;
    while (true) {
        cout << prompt << " (sim/nao): ";
        cin >> resposta;
        if (resposta == "sim" || resposta == "nao") {
            limparBufferEntrada();
            return stringParaBool(resposta);
        } else {
            cout << "Entrada invalida. Por favor, digite 'sim' ou 'nao'.\n";
            limparBufferEntrada();
        }
    }
}


// Exibe todas as informações formatadas de um único imóvel
void exibirImovel(const Imovel& im) {
    cout << "----------------------------------------\n"
              << "Tipo: " << im.tipo << " | Finalidade: " << im.finalidade << "\n"
              << "Endereco: " << im.endereco << ", " << im.bairro << ", " << im.cidade << "\n"
              << "Area: " << im.area << " m2 | Valor: " << im.valor << " | IPTU: " << im.iptu << "\n"
              << "Quartos: " << im.quartos << " | Suites: " << im.suites << " | Banheiros: " << im.banheiros << " | Vagas: " << im.vagas << "\n"
              << "Caracteristicas:\n"
              << "  - Cozinha: " << boolParaString(im.cozinha) << " | Sala: " << boolParaString(im.sala)
              << " | Varanda: " << boolParaString(im.varanda) << " | Area de Servico: " << boolParaString(im.area_de_servico) << "\n"
              << "  - Piso: " << im.piso << " | Conservacao: " << im.conservacao << "\n"
              << "Comodidades:\n"
              << "  - Armarios: " << boolParaString(im.armarios) << " | Ar-cond.: " << boolParaString(im.ar_condicionado)
              << " | Aquecedor: " << boolParaString(im.aquecedor) << " | Ventilador: " << boolParaString(im.ventilador) << "\n"
              << "----------------------------------------\n";
}

// FUNÇÕES DE MANIPULAÇÃO DE DADO

// Carrega os dados dos imóveis de um arquivo de texto para o vetor 'bd'
void carregarDados(vector<Imovel>& bd, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "ERRO: Nao foi possivel encontrar o arquivo de banco de dados '" << nomeArquivo << "'.\n";
        cerr << "Verifique se o arquivo esta na mesma pasta do executavel.\n";
        cout << "Pressione Enter para sair...";
        limparBufferEntrada();
        exit(1);
    }

    string linha;
    getline(arquivo, linha); // Pula cabeçalho

    while (getline(arquivo, linha)) {
        if (linha.empty() || linha.find_first_not_of(" \t\r\n") == string::npos) {
            continue;
        }

        stringstream ss(linha);
        Imovel imovel;
        string tempBool; // Para ler valores booleanos "sim"/"nao"

        ss >> imovel.tipo;
        if (imovel.tipo == "fim") { // Sinaliza o fim do arquivo de dados
            break;
        }

        // Lê os campos do imóvel em sequência (alguns ainda lidos com >> por simplicidade,
        // mas em um sistema real, todos os campos de string deveriam ser lidos com getline
        // de forma mais robusta, mas exigiria um formato de arquivo diferente ou mais complexo)
        ss >> imovel.finalidade >> imovel.endereco >> imovel.bairro >> imovel.cidade >> imovel.area >>
            imovel.valor >> imovel.iptu >> imovel.quartos >> imovel.suites >> imovel.banheiros >>
            imovel.vagas;

        // Converte strings "sim"/"nao" para booleanos
        ss >> tempBool; imovel.cozinha = stringParaBool(tempBool);
        ss >> tempBool; imovel.sala = stringParaBool(tempBool);
        ss >> tempBool; imovel.varanda = stringParaBool(tempBool);
        ss >> tempBool; imovel.area_de_servico = stringParaBool(tempBool);
        // Os campos 'piso' e 'conservacao' são lidos aqui com '>>', o que pode causar problemas se tiverem espaços.
        // Para leitura de arquivo, isso dependeria do formato exato do arquivo.
        // Se o arquivo usar _ para espaços como sugerido no input, então '>>' funciona.
        ss >> imovel.piso >> imovel.conservacao;
        ss >> tempBool; imovel.armarios = stringParaBool(tempBool);
        ss >> tempBool; imovel.ar_condicionado = stringParaBool(tempBool);
        ss >> tempBool; imovel.aquecedor = stringParaBool(tempBool);
        ss >> tempBool; imovel.ventilador = stringParaBool(tempBool);

        bd.push_back(imovel); // Adiciona o imóvel lido ao vetor
    }
    arquivo.close();
    cout << "Banco de dados carregado. Total de " << bd.size() << " imoveis.\n";
}

// Salva os dados dos imóveis do vetor 'bd' em um arquivo de texto
void salvarDados(const vector<Imovel>& bd, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro: Nao foi possivel salvar os dados no arquivo " << nomeArquivo << ".\n";
        return;
    }
    arquivo << "# Tipo Finalidade Endereco Bairro Cidade Area Valor IPTU Quartos Suites Banheiros Vagas Cozinha Sala Varanda Area_de_Servico Piso Conservacao Armarios Ar-condicionado Aquecedor Ventilador\n";
    for (const auto& imovel : bd) {
        arquivo << imovel.tipo << " " << imovel.finalidade << " " << imovel.endereco << " " << imovel.bairro << " "
                << imovel.cidade << " " << imovel.area << " " << imovel.valor << " " << imovel.iptu << " "
                << imovel.quartos << " " << imovel.suites << " " << imovel.banheiros << " " << imovel.vagas << " "
                << boolParaString(imovel.cozinha) << " " << boolParaString(imovel.sala) << " "
                << boolParaString(imovel.varanda) << " " << boolParaString(imovel.area_de_servico) << " "
                << imovel.piso << " " << imovel.conservacao << " " << boolParaString(imovel.armarios) << " "
                << boolParaString(imovel.ar_condicionado) << " " << boolParaString(imovel.aquecedor) << " "
                << boolParaString(imovel.ventilador) << "\n";
    }
    arquivo << "fim\n"; // Marca o fim do arquivo de dados
    arquivo.close();
    cout << "Dados salvos com sucesso no arquivo " << nomeArquivo << ".\n";
}

// FUNÇÕES DAS OPERAÇÕES DO MENU

// Permite ao usuário incluir um novo imóvel com validação de entrada
void incluirImovel(vector<Imovel>& bd) {
    if (bd.size() >= 200) { // Limite máximo de imóveis
        cout << "Erro: Limite maximo de 200 imoveis atingido.\n";
        return;
    }

    Imovel novo;
    cout << "\n--- Inclusao de Novo Imovel ---\n";
    cout << "Digite as informacoes:\n";

    // Lendo campos com 'cin >>' para strings simples
    cout << "Tipo (casa, apartamento, etc.): "; cin >> novo.tipo; limparBufferEntrada(); // Limpa o buffer após cin >>
    cout << "Finalidade (venda, aluguel, temporada): "; cin >> novo.finalidade; limparBufferEntrada();

    // Lendo campos com 'getline' para permitir espaços
    cout << "Endereco (ex: Rua das Flores, Avenida Principal): "; getline(cin, novo.endereco);
    cout << "Bairro: "; getline(cin, novo.bairro);
    cout << "Cidade: "; getline(cin, novo.cidade);

    // Lendo campos numéricos com validação
    novo.area = lerDouble("Area (m2): ");
    cout << "Valor (ex: 500000 ou 300/dia): "; cin >> novo.valor; limparBufferEntrada(); // Valor ainda é string
    novo.iptu = lerDouble("IPTU: ");
    novo.quartos = lerInt("Quartos: ");
    novo.suites = lerInt("Suites: ");
    novo.banheiros = lerInt("Banheiros: ");
    novo.vagas = lerInt("Vagas de garagem: ");

    // Lendo campos booleanos com validação
    novo.cozinha = lerBool("Cozinha");
    novo.sala = lerBool("Sala");
    novo.varanda = lerBool("Varanda");
    novo.area_de_servico = lerBool("Area de Servico");

    // Lendo campos de string com espaços
    cout << "Piso (ex: ceramica, porcelanato): "; getline(cin, novo.piso);
    cout << "Conservacao (ex: novo, usado, reformado): "; getline(cin, novo.conservacao);

    // Lendo mais campos booleanos com validação
    novo.armarios = lerBool("Armarios");
    novo.ar_condicionado = lerBool("Ar-condicionado");
    novo.aquecedor = lerBool("Aquecedor");
    novo.ventilador = lerBool("Ventilador");

    bd.push_back(novo); // Adiciona o novo imóvel
    cout << "\nImovel incluido com sucesso!\n";
}

// Busca um imóvel por endereço (permitindo espaços) e permite a exclusão
void buscarExcluirPorRua(vector<Imovel>& bd) {
    string rua;
    cout << "\n--- Busca e Exclusao por Rua ---\n";
    cout << "Digite o nome da rua (endereco) para buscar: ";
    getline(cin, rua); // Usa getline para permitir espaços no endereço

    int indiceEncontrado = -1;
    for (size_t i = 0; i < bd.size(); ++i) {
        if (bd[i].endereco == rua) {
            cout << "\nImovel encontrado:\n";
            exibirImovel(bd[i]);
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        char confirmacao;
        cout << "Deseja excluir este imovel? (s/n): ";
        cin >> confirmacao;
        limparBufferEntrada(); // Limpa o buffer após ler o char
        if (confirmacao == 's' || confirmacao == 'S') {
            bd.erase(bd.begin() + indiceEncontrado); // Remove o imóvel
            cout << "Imovel excluido com sucesso.\n";
        } else {
            cout << "Operacao de exclusao cancelada.\n";
        }
    } else {
        cout << "Nenhum imovel encontrado no endereco '" << rua << "'.\n";
    }
}

// Busca imóveis por finalidade e faixa de valor
void buscarPorFaixaDeValor(const vector<Imovel>& bd) {
    string finalidade;
    cout << "\n--- Busca por Faixa de Valor ---\n";
    cout << "Digite a finalidade (venda, aluguel, temporada): ";
    cin >> finalidade;
    limparBufferEntrada(); // Limpa o buffer após cin >>

    double min = lerDouble("Digite o valor minimo: ");
    double max = lerDouble("Digite o valor maximo: ");

    int encontrados = 0;
    cout << "\nImoveis encontrados para '" << finalidade << "' entre " << min << " e " << max << ":\n";
    for (const auto& imovel : bd) {
        // Inclui "aluguel" se a finalidade for "locacao"
        if (imovel.finalidade == finalidade || (finalidade == "locacao" && imovel.finalidade == "aluguel")) {
            double valorImovel = extrairValorNumerico(imovel.valor);
            if (valorImovel >= min && valorImovel <= max) {
                exibirImovel(imovel);
                encontrados++;
            }
        }
    }
    if (encontrados == 0) {
        cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

// Busca imóveis por características específicas
void buscarPorCaracteristicas(const vector<Imovel>& bd) {
    cout << "\n--- Busca por Caracteristicas ---\n";
    bool reqArmarios = lerBool("Deseja com armarios");
    bool reqAr = lerBool("Deseja com ar-condicionado");
    bool reqAquecedor = lerBool("Deseja com aquecedor");
    bool reqVentilador = lerBool("Deseja com ventilador");

    int encontrados = 0;
    cout << "\nImoveis encontrados com as caracteristicas desejadas:\n";
    for (const auto& imovel : bd) {
        // Verifica se o imóvel atende a todos os requisitos
        if ((!reqArmarios || imovel.armarios) &&
            (!reqAr || imovel.ar_condicionado) &&
            (!reqAquecedor || imovel.aquecedor) &&
            (!reqVentilador || imovel.ventilador)) {
            exibirImovel(imovel);
            encontrados++;
        }
    }
     if (encontrados == 0) {
        cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

// Busca imóveis por número de quartos e suítes
void buscarPorQuartosESuites(const vector<Imovel>& bd) {
    cout << "\n--- Busca por Quartos e Suites ---\n";
    int q = lerInt("Digite o numero de quartos: ");
    int s = lerInt("Digite o numero de suites: ");

    int encontrados = 0;
    cout << "\nImoveis encontrados com " << q << " quarto(s) e " << s << " suite(s):\n";
    for (const auto& imovel : bd) {
        if (imovel.quartos == q && imovel.suites == s) {
            exibirImovel(imovel);
            encontrados++;
        }
    }
     if (encontrados == 0) {
        cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

// Exibe um relatório estatístico dos imóveis
void exibirRelatorioEstatisticas(const vector<Imovel>& bd) {
    if (bd.empty()) {
        cout << "Nao ha dados para gerar estatisticas.\n";
        return;
    }

    int total = bd.size();
    int countVenda = 0, countAluguel = 0, countTemporada = 0;
    int countCasas = 0, countCasasComSuite = 0;
    int countSalas = 0, countSalasComCeramica = 0;

    for (const auto& imovel : bd) {
        if (imovel.finalidade == "venda") countVenda++;
        else if (imovel.finalidade == "aluguel") countAluguel++;
        else if (imovel.finalidade == "temporada") countTemporada++;

        if (imovel.tipo == "casa") {
            countCasas++;
            if (imovel.suites > 0) {
                countCasasComSuite++;
            }
        }

        if (imovel.tipo == "sala_comercial") {
            countSalas++;
            if (imovel.piso == "ceramica") {
                countSalasComCeramica++;
            }
        }
    }
    
    cout << fixed << setprecision(2);

    cout << "\n--- Relatorio de Estatisticas ---\n";
    cout << "Total de imoveis: " << total << "\n\n";

    cout << "1. Porcentagem por Finalidade:\n";
    cout << "   - Venda: " << (static_cast<double>(countVenda) / total) * 100.0 << "%\n";
    cout << "   - Aluguel: " << (static_cast<double>(countAluguel) / total) * 100.0 << "%\n";
    cout << "   - Temporada: " << (static_cast<double>(countTemporada) / total) * 100.0 << "%\n\n";

    cout << "2. Porcentagem de Casas com Suites:\n";
    if (countCasas > 0) {
        cout << "   - " << (static_cast<double>(countCasasComSuite) / countCasas) * 100.0 << "% das casas possuem suite.\n\n";
    } else {
        cout << "   - Nenhuma casa cadastrada.\n\n";
    }

    cout << "3. Porcentagem de Pisos com Ceramica nas Salas Comerciais:\n";
    if (countSalas > 0) {
        cout << "   - " << (static_cast<double>(countSalasComCeramica) / countSalas) * 100.0 << "% das salas comerciais tem piso de ceramica.\n";
    } else {
        cout << "   - Nenhuma sala comercial cadastrada.\n";
    }
    cout << "-----------------------------------\n";
}

// Lista todos os imóveis cadastrados
void listarTodosImoveis(const vector<Imovel>& bd) {
     if (bd.empty()) {
        cout << "Nao ha imoveis cadastrados para listar.\n";
        return;
    }
    cout << "\n--- Listagem de Todos os Imoveis (" << bd.size() << ") ---\n";
    for(const auto& imovel : bd){
        exibirImovel(imovel);
    }
}

// Exibe o menu principal de opções
void exibirMenu() {
    cout << "\n===== MENU DE OPCOES =====\n"
              << "1. Incluir Novo Imovel\n"
              << "2. Buscar e Excluir Imovel por Rua\n"
              << "3. Buscar Imoveis por Faixa de Valor\n"
              << "4. Buscar Imoveis por Caracteristicas\n"
              << "5. Buscar Imoveis por Quartos e Suites\n"
              << "6. Relatorio de Estatisticas\n"
              << "7. Listar Todos os Imoveis\n"
              << "8. Sair e Salvar\n"
              << "==========================\n"
              << "Escolha uma opcao: ";
}


// FUNÇÃO PRINCIPAL
// Ponto de entrada do programa, gerencia o loop do menu
int main() {
    vector<Imovel> baseDeDados;
    const string nomeArquivo = "BD_Imoveis2.txt";

    carregarDados(baseDeDados, nomeArquivo); // Carrega dados do arquivo

    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        
        if(cin.fail()) { // Trata entrada inválida (não numérica)
            cout << "Opcao invalida. Por favor, digite um numero.\n";
            cin.clear();
            limparBufferEntrada();
            opcao = 0;
            continue;
        }
        
        limparBufferEntrada();

        switch (opcao) { // Executa a função baseada na opção escolhida
            case 1: incluirImovel(baseDeDados); break;
            case 2: buscarExcluirPorRua(baseDeDados); break;
            case 3: buscarPorFaixaDeValor(baseDeDados); break;
            case 4: buscarPorCaracteristicas(baseDeDados); break;
            case 5: buscarPorQuartosESuites(baseDeDados); break;
            case 6: exibirRelatorioEstatisticas(baseDeDados); break;
            case 7: listarTodosImoveis(baseDeDados); break;
            case 8:
                salvarDados(baseDeDados, nomeArquivo); // Salva dados antes de sair
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 8); // Continua até o usuário escolher 'Sair e Salvar'

    return 0;
}
