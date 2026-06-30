#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Arvore
{
public:
    struct no
    {
        T dado;
        no *esq;
        no *dir;
    };
    // inicia a arvore com a raiz nula
    Arvore() : raiz(nullptr) {}

    //("arvore = arvore + veiculo")
    Arvore<T> &operator+(T novoDado)
    {
        raiz = insere(raiz, novoDado);
        return *this;
    }

    // sobrecarga de busca
    T operator()(const string &chave) const
    {
        return busca(raiz, chave);
    }

    void imprime() const
    {
        imprime(raiz);
    }

    friend ostream& operator<<(ostream& os, const Arvore<T>& arvore) {
            arvore.imprimeEmOrdem(arvore.raiz, os);
            return os;
    }

private:
    no *raiz;

    // criacao dos metodos, perguntar ate que ponto esse modo de colocar os metodos nao é uma boa pratica de programaçcao, mas é mais simples de entender a sintaxe
    no *insere(no *atual, T novoDado)
    {
        if (atual == nullptr)
        {
            return new no{novoDado, nullptr, nullptr};
        }

        // evita a inserir msm
        if (*novoDado == *atual->dado)
        {
            return atual;
        }

        // Se o novo dado for MAIOR (>), vai para a ESQUERDA
        if (*novoDado > *(atual->dado))
        {
            atual->esq = insere(atual->esq, novoDado);
        }
        else
        {
            atual->dir = insere(atual->dir, novoDado);
        }

        return atual;
    }

    T busca(no *atual, const string &chave) const
    {
        if (atual == nullptr)
            return nullptr;

        // Se o dado atual for igual a chave, retorna o dado ()
        if (*(atual->dado) == chave)
            return atual->dado;

        if (*(atual->dado) < chave)
            return busca(atual->esq, chave);

        return busca(atual->dir, chave);
    }

    void imprimeEmOrdem(no *atual, ostream &os) const
    {
        if (atual != nullptr)
        {
            imprimeEmOrdem(atual->esq, os);
            os << *(atual->dado) << endl; // Dispara o operator<< do Veiculo*
            imprimeEmOrdem(atual->dir, os);
        }
    }
};

#endif