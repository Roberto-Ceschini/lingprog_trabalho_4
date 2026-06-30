#include "Frota.h"
#include <iostream>
#include "VeiculoNaoEncontrado.h"

using namespace std;

// 1 insere, usa o + de arvore
Frota& Frota::insere(Veiculo* novoVeiculo) {
    arvoreVeiculos = arvoreVeiculos + novoVeiculo;
    return *this;
}

// 2. Busca por placa, usa o () de arvore
Veiculo* Frota::operator()(const string& placa) {
    Veiculo* encontrado = arvoreVeiculos(placa);
    
    //se nn encontrar, lança a exceção
    if (encontrado == nullptr) {
        // throw VeiculoNaoEncontrado();
        cout << "Erro: veiculo nao encontrado no sistema." << endl; // Feedback temporário
    }
    
    return encontrado;
}

// 3. quilometragem, usa o () de arvore e atualiza a quilometragem
Veiculo* Frota::operator()(const string& placa, double novaQuilometragem) {
    Veiculo* veiculo = (*this)(placa); 
    
    if (veiculo != nullptr) {
        veiculo->atualizaQuilometragem(novaQuilometragem);
    }
    
    return veiculo;
}

// 4. imprime, usa o imprime de arvore
void Frota::imprime() const {
    cout << arvoreVeiculos;
}
