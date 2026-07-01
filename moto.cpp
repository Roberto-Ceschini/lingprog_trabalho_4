#include "Moto.h"

#include "Moto.h"

Moto::Moto(const string& placa, const string& marca, double quilometragem, double custoManutencao, int cilindrada)
    : Veiculo(placa, marca, quilometragem, custoManutencao), cilindrada(cilindrada) {}

double Moto::calculaCustoManutencao() const {
    return custoManutencao + (cilindrada * 0.1);
}

string Moto::getTipo() const {
    return "Moto"; //motomoto kkk
}

void Moto::imprime(ostream& os) const {
    Veiculo::imprime(os);
    os << " | Cilindradas: " << cilindrada;
}