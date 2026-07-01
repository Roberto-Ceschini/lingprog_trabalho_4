#include <iostream>
#include <string>
#include "Frota.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Moto.h"
#include "VeiculoNaoEncontrado.h"

using namespace std;


void exibeMenu() {
    cout << "\n================ MENU DE GERENCIAMENTO ================" << endl;
    cout << "1. Cadastrar Novo Veiculo na Frota" << endl;
    cout << "2. Buscar Veiculo por Placa" << endl;
    cout << "3. Atualizar Quilometragem de um Veiculo" << endl;
    cout << "4. Exibir Todos os Veiculos da Frota" << endl;
    cout << "5. Calcular Custo Medio de Manutencao por Tipo" << endl;
    cout << "0. Sair do Programa" << endl;
    cout << "=======================================================" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    Frota minhaFrota;
    int opcao = -1;

   
    string placa, marca;
    double km, custoBase;

    while (opcao != 0) {
        exibeMenu();
        cin >> opcao;

        
        cin.ignore();

        switch (opcao) {
            case 1: {
                int tipo;
                cout << "\n--- Cadastrar Veiculo ---" << endl;
                cout << "Selecione o tipo (1-Carro, 2-Caminhao, 3-Moto): ";
                cin >> tipo;
                cin.ignore();

                if (tipo < 1 || tipo > 3) {
                    cout << "Opcao de tipo invalida! Retornando ao menu." << endl;
                    break;
                }

                cout << "Digite a Placa: ";
                getline(cin, placa);
                cout << "Digite a Marca: ";
                getline(cin, marca);
                cout << "Digite a Quilometragem Atual: ";
                cin >> km;
                cout << "Digite o Custo Base de Manutencao: ";
                cin >> custoBase;

                if (tipo == 1) {
                    int portas;
                    cout << "Digite a quantidade de portas: ";
                    cin >> portas;
                    minhaFrota.insere(new Carro(placa, marca, km, custoBase, portas));
                } 
                else if (tipo == 2) {
                    double carga;
                    cout << "Digite a capacidade de carga (toneladas): ";
                    cin >> carga;
                    minhaFrota.insere(new Caminhao(placa, marca, km, custoBase, carga));
                } 
                else if (tipo == 3) {
                    int cilindradas;
                    cout << "Digite as cilindradas (cc): ";
                    cin >> cilindradas;
                    minhaFrota.insere(new Moto(placa, marca, km, custoBase, cilindradas));
                }

                cout << ">>> Veiculo cadastrado e inserido com sucesso na Arvore! <<<" << endl;
                break;
            }

            case 2: {
                cout << "\n--- Buscar Veiculo por Placa ---" << endl;
                cout << "Digite a placa desejada: ";
                getline(cin, placa);

           
                try {
                    Veiculo* v = minhaFrota(placa);
                    cout << "\n[Veiculo Encontrado]:" << endl;
                    cout << *v << endl;
                } 
                catch (const VeiculoNaoEncontrado& e) {
                    cout << "\n" << e.what() << endl;
                }
                break;
            }

            case 3: {
                cout << "\n--- Atualizar Quilometragem ---" << endl;
                cout << "Digite a placa do veiculo: ";
                getline(cin, placa);
                cout << "Digite a nova quilometragem: ";
                cin >> km;

                try {
                    minhaFrota(placa, km);
                    cout << ">>> Quilometragem atualizada com sucesso! <<<" << endl;
                } 
                catch (const VeiculoNaoEncontrado& e) {
                    cout << "\n" << e.what() << endl;
                }
                break;
            }

            case 4: {
                cout << "\n*** Relatorio Completo da Frota (Ordenado por Placa Invertida) ***" << endl;
                minhaFrota.imprime();
                cout << "*****************************************************************" << endl;
                break;
            }

            case 5: {
              
                minhaFrota.calculaCustoManutencao();
                break;
            }

            case 0:
                cout << "\nEncerrando sistema!" << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }
    }

    return 0;
}