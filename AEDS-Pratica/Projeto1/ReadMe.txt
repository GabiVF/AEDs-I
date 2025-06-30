PROJETO: Gerenciador de Imóveis
Disciplina: Algoritmos e Estruturas de Dados I
Autores: Gustavo de Sousa Zimmermann, Gabriela Vinha Feitosa

**Arquivos**
Arquivo principal: main.cpp
Arquivo de dados: BD_Imoveis2.txt

**objetivo**

1. Descrição Geral
Este projeto consiste em um aplicativo de gerenciamento de imóveis para venda, aluguel ou
temporada. Ele permite:
- Manipular registros de até 200 imóveis por meio de vetores;
- Realizar operações de busca, inclusão, exclusão e geração de estatísticas;
- Interagir com um menu textual simples e intuitivo;
- Realizar leitura e escrita em um arquivo-texto estruturado, garantindo persistência de dados entre
execuções.

2. Requisitos e Preparação

Pré-requisitos
- Um compilador C++ instalado (como g++, MinGW ou Code::Blocks);
- O arquivo BD_Imoveis2.txt deve estar na mesma pasta que o executável.

Compilação
No terminal ou na IDE, use o seguinte comando para compilar:
g++ -std=c++11 -o gerenciador_imoveis main.cppExecução

No terminal:
./gerenciador_imoveis

**funcionalidades**

3. Funcionalidades do Menu

O sistema oferece as seguintes opções no menu principal:

1. Incluir Novo Imóvel
- Insere um novo registro no vetor.
- Você será solicitado a preencher os 22 campos.
- Use "sim" ou "nao" para campos booleanos.
- Limite máximo: 200 imóveis.

2. Buscar e Excluir Imóvel por Rua
- Busca por endereço (rua) exato.
- Exibe os dados encontrados e solicita confirmação para exclusão.
- Após exclusão, os registros são realocados (sem buracos no vetor).

3. Buscar Imóveis por Faixa de Valor
- Filtra imóveis por tipo (venda, aluguel ou temporada) e valor mínimo e máximo.
- Aceita valores como "300/dia" para temporada.

4. Buscar Imóveis por Características
- Filtra por presença de:
- Armários- Ar-condicionado
- Aquecedor
- Ventilador

5. Buscar Imóveis por Quartos e Suítes
- Permite encontrar imóveis com número exato de quartos e suítes.

6. Relatório de Estatísticas
- Mostra:
- Porcentagem de imóveis por finalidade (venda, aluguel, temporada)
- Porcentagem de casas com suítes
- Porcentagem de salas comerciais com piso de cerâmica

7. Listar Todos os Imóveis
- Exibe todos os imóveis atualmente armazenados no sistema.

8. Sair e Salvar
- Grava todos os dados atualizados no arquivo BD_Imoveis2.txt.
- Atenção: só essa opção garante a persistência das alterações. Encerrar o programa de outra
forma descartará mudanças.

**sobre o arquivo de entrada que será editavel**

4. Estrutura do Arquivo BD_Imoveis2.txt
Cada linha representa um imóvel, com 22 campos separados por espaço, seguindo a ordem:

Tipo Finalidade Endereco Bairro Cidade Area Valor IPTU Quartos Suites Banheiros Vagas Cozinha
Sala Varanda Area_de_Servico Piso Conservacao Armarios Ar-condicionado Aquecedor VentiladorObservações:

- A última linha deve conter apenas a palavra 'fim', indicando o fim dos dados.
Exemplo de linha:

casa venda Rua_das_Flores Primavera Alfenas 120 350000 800 3 1 2 2 sim sim sim sim ceramica
usado sim nao nao sim

**Parte técnica**

5. Observações Técnicas

- Todos os dados são armazenados em vetor contínuo.
- Operações como exclusão reorganizam o vetor automaticamente.
- O código utiliza: vetores, structs, condicionais, laços, entrada e saída padrão.
- A interface é robusta contra entradas inválidas no menu.
- O código-fonte contém comentários explicativos.
