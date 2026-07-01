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
        throw VeiculoNaoEncontrado();
    }
    
    return encontrado;
}

// 3 quilometragem, usa o () de arvore e atualiza a quilometragem
Veiculo* Frota::operator()(const string& placa, double novaQuilometragem) {
    Veiculo* veiculo = (*this)(placa); 
    
    if (veiculo != nullptr) {
        veiculo->atualizaQuilometragem(novaQuilometragem);
    }
    
    return veiculo;
}

// 4 imprime, usa o imprime de arvore
void Frota::imprime() const {
    cout << arvoreVeiculos;
}

void Frota::calculaCustoManutencao() const {
    double somaCarro = 0, somaCaminhao = 0, somaMoto = 0;
    int qtdCarro = 0, qtdCaminhao = 0, qtdMoto = 0;

    // Dispara a função auxiliar passando a raiz da árvore e as variáveis por referência
    acumulaCustos(arvoreVeiculos.getRaiz(), somaCarro, qtdCarro, somaCaminhao, qtdCaminhao, somaMoto, qtdMoto);

    // Exibe os resultados calculando a média (com validação para não dividir por zero)
    cout << "\n=== Custo Medio de Manutencao por Tipo ===" << endl;
    
    cout << "Carro: ";
    if (qtdCarro > 0) cout << "R$ " << (somaCarro / qtdCarro) << " (Qtd: " << qtdCarro << ")" << endl;
    else cout << "Nenhum carro registrado." << endl;

    cout << "Caminhao: ";
    if (qtdCaminhao > 0) cout << "R$ " << (somaCaminhao / qtdCaminhao) << " (Qtd: " << qtdCaminhao << ")" << endl;
    else cout << "Nenhum caminhao registrado." << endl;

    cout << "Moto: ";
    if (qtdMoto > 0) cout << "R$ " << (somaMoto / qtdMoto) << " (Qtd: " << qtdMoto << ")" << endl;
    else cout << "Nenhuma moto registrado." << endl;
    cout << "==========================================" << endl;
}

//metodo auxiliar
void Frota::acumulaCustos(Arvore<Veiculo*>::no* atual, double& somaCarro, int& qtdCarro, double& somaCaminhao, int& qtdCaminhao, double& somaMoto, int& qtdMoto) const {
    
    //se o no for nulo retorna (fim de um ramo)
    if (atual == nullptr) return;

    //visita pela esquerda
    acumulaCustos(atual->esq, somaCarro, qtdCarro, somaCaminhao, qtdCaminhao, somaMoto, qtdMoto);

    //so soma quando o atual for diferente de nulo, ou seja, quando termina de percorrer
    string tipo = atual->dado->getTipo();
    double custo = atual->dado->calculaCustoManutencao();

    if (tipo == "Carro") {
        somaCarro += custo;
        qtdCarro++;
    } else if (tipo == "Caminhao") {
        somaCaminhao += custo;
        qtdCaminhao++;
    } else if (tipo == "Moto") {
        somaMoto += custo;
        qtdMoto++;
    }

    //Visita toda a subárvore da direita
    acumulaCustos(atual->dir, somaCarro, qtdCarro, somaCaminhao, qtdCaminhao, somaMoto, qtdMoto);
}
