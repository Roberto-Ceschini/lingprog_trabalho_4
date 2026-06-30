#include "Veiculo.h"

using namespace std;

// Construtor
Veiculo::Veiculo(const string& placa, const string& marca, double quilometragem, double custoManutencao)
    : placa(placa), marca(marca), quilometragem(quilometragem), custoManutencao(custoManutencao) {}

void Veiculo::atualizaQuilometragem(double novaQuilometragem) {
    this->quilometragem = novaQuilometragem;
}

// OPERADORES OBJETO vs OBJETO

bool Veiculo::operator>(const Veiculo& outro) const {
    return this->placa > outro.placa; // Comparação alfabética direta de strings
}

bool Veiculo::operator==(const Veiculo& outro) const {
    return this->placa == outro.placa; // Comparação direta de strings
}

// OPERADORES OBJETO vs STRING para busca
bool Veiculo::operator==(const string& placaBusca) const {
    return this->placa == placaBusca;
}

bool Veiculo::operator<(const string& placaBusca) const {
    return this->placa < placaBusca;
}

//Imprime
void Veiculo::imprime(ostream& os) const {
    os << "placa: " << placa 
       << "marca: " << marca 
       << "km: " << quilometragem 
       << "custo: R$ " << custoManutencao;
}

ostream& operator<<(ostream& os, const Veiculo& veiculo) {
    veiculo.imprime(os);
    return os;
}