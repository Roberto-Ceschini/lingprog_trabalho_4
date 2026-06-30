#include <iostream>
#include "Frota.h"
#include "Caminhao.h"

using namespace std;

int main() {
    // 1. Criamos nossa Frota
    Frota minhaFrota;

    // 2. Criamos caminhões de forma dinâmica (ponteiros) para suportar polimorfismo
    Veiculo* c1 = new Caminhao("MNO5678", "Volvo", 150000.0, 2000.0, 20.0);
    Veiculo* c2 = new Caminhao("ABC1234", "Scania", 80000.0, 1500.0, 15.0);
    Veiculo* c3 = new Caminhao("XYZ9999", "Mercedes", 200000.0, 3000.0, 30.0);

    cout << "--- Inserindo os veiculos na frota ---" << endl;
    // Testa o método insere que delega para o operator+ da árvore
    minhaFrota.insere(c1);
    minhaFrota.insere(c2);
    minhaFrota.insere(c3);

    // 3. Testa a impressão completa (Efeito cascata: Frota -> Arvore -> Caminhao)
    cout << "\n*** Estado Atual da Frota (Impressao em Ordem) ***" << endl;
    minhaFrota.imprime(); 

    // 4. Testa a Busca via operator() da Frota
    cout << "\n--- Testando a busca por placa ---" << endl;
    Veiculo* buscado = minhaFrota("ABC1234");
    if (buscado != nullptr) {
        cout << "Veiculo encontrado diretamente pelo operador:\n" << *buscado << endl;
    }

    // 5. Testa a Atualização de Quilometragem via operator() com dois argumentos
    cout << "\n--- Atualizando quilometragem do ABC1234 para 95000.0 ---" << endl;
    minhaFrota("ABC1234", 95000.0);

    // 6. Imprime novamente para conferir se alterou o objeto real guardado na árvore
    cout << "\n*** Frota Apos Atualizacao ***" << endl;
    minhaFrota.imprime();

    // Liberação básica da memória (Em um projeto completo, o destrutor da árvore cuidaria disso)

    return 0;
}