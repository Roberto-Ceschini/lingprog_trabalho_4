#include "Caminhao.h"

Caminhao::Caminhao(const string& placa, const string& marca, double quilometragem, double custoManutencao, double capacidadeCarga)
    : Veiculo(placa, marca, quilometragem, custoManutencao), capacidadeCarga(capacidadeCarga) {}

double Caminhao::calculaCustoManutencao() const {
    return custoManutencao + (capacidadeCarga * 50.0);
}

string Caminhao::getTipo() const {
    return "Caminhao";
}

void Caminhao::imprime(ostream& os) const {
    Veiculo::imprime(os); //  chama a de Veiculo primeiro
    os << " | Capacidade Carga: " << capacidadeCarga << " toneladas"; //adicionanndo a informacao no final
}