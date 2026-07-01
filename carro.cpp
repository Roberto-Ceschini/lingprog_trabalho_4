#include "Carro.h"

Carro::Carro(const string& placa, const string& marca, double quilometragem, double custoManutencao, int numPortas)
    : Veiculo(placa, marca, quilometragem, custoManutencao), numPortas(numPortas) {}

double Carro::calculaCustoManutencao() const {
    return custoManutencao + (numPortas * 100.0);
}

string Carro::getTipo() const {
    return "Carro";
}

void Carro::imprime(ostream& os) const {
    Veiculo::imprime(os);
    os << " | Portas: " << numPortas;
}