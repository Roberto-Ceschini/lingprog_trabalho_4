# Gerenciador de Frota com Árvore Binária em C++

## Descrição

Sistema desenvolvido em C++ para o gerenciamento de frotas de veículos utilizando herança, polimorfismo dinâmico e uma estrutura de dados de **Árvore Binária de Busca**. 

O sistema mantém os veículos inseridos organizados de forma automática através de ordenação por placas em ordem alfabética invertida, utilizando ampla sobrecarga de operadores para manipulação opaca dos dados.

---

# Estrutura do Projeto

## Estruturas e Classes

### Veiculo (Classe Base)
Responsável por representar a fundação abstrata de um veículo. Possui os atributos protegidos `placa`, `marca`, `quilometragem` e `custoManutencao`.
Suas subclasses estendem seu comportamento com atributos específicos:
* **Carro:** `numPortas`
* **Caminhao:** `capacidadeCarga`
* **Moto:** `cilindrada`

---

### Arvore (Classe Template)
Estrutura de dados binária e genérica utilizada para armazenar os ponteiros dos veículos em nós (`No`). A árvore aplica as regras de inserção por placa de forma recursiva.

---

### Frota (Classe Controladora)
Classe responsável por encapsular a árvore binária e fornecer a interface de controle do sistema através de métodos e operadores.

---

# Funcionalidades do Menu

Todas as operações disponíveis na interface interativa foram mapeadas diretamente para as regras de negócio solicitadas:

1. **Cadastrar Novo Veículo na Frota:** Instancia dinamicamente um objeto do tipo escolhido (`Carro`, `Caminhao` ou `Moto`) e o insere na árvore utilizando a sobrecarga do `operator+`.
2. **Buscar Veículo por Placa:** Localiza um veículo específico na árvore binária por meio da sobrecarga do `operator()(placa)`. Caso a placa não exista, o sistema lança e trata a exceção customizada `VeiculoNaoEncontrado`.
3. **Atualizar Quilometragem de um Veículo:** Modifica diretamente em memória a quilometragem de um veículo localizado por sua placa através do `operator()(placa, novaQuilometragem)`. Também conta com tratamento de erro contra ponteiros nulos.
4. **Exibir Todos os Veículos da Frota:** Dispara a sobrecarga do `operator<<` de forma cascateada (`Frota` -> `Arvore` -> `Veiculo`). A árvore realiza um percurso para exibir de forma alfabética decrescente por placa.
5. **Calcular Custo Médio de Manutenção por Tipo:** `calculaCustoManutencao()`, a média exata de gastos de manutenção agrupada por categorias.

---

# Requisitos

Para compilar o programa é necessário possuir:
* g++ (Suporte a C++11 ou superior)
* mingw32-make

---

# Compilação
No terminal, execute:

Bash
mingw32-make
O comando irá gerar o executável do programa.

# Execução
Após a compilação:

Bash
.\programa
Limpeza dos Arquivos Compilados
Para remover os arquivos objeto e o executável:

Bash
mingw32-make clean
Observações
Caso utilize Linux, pode ser necessário ajustar os comandos do Makefile. Como mostrado na linha 1 deste arquivo.

Autor
Roberto Ceschin
