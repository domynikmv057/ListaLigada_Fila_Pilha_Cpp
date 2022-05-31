#include <iostream>

using namespace std;

class Node
{

private:
	int valor;
	Node* proximo;
;


public:
	Node() {
		setValor(0);
		setProximo(NULL);
	}

	Node(int valor)
	{
		setValor(valor);
		setProximo(NULL);
	}

	int getValor() {
		return this->valor;
	}

	void setValor(int valor) {
		this->valor = valor;
	}

	Node* getProximo() {
		return this->proximo;
	}
	void setProximo(Node* proximo) {
		this->proximo = proximo;
	}
};

class ListaLigada
{
private:
	Node* inicio;
	int tam;

public:
	ListaLigada() {
		setInicio(NULL);
		this->tam = 0;
	}
	void setInicio(Node* primeiroElemento) {
		this->inicio = primeiroElemento;
	}

	Node* getInicio() {
		return this->inicio;
	}

	int getTamanho() {
		return this->tam;
	}


	void InserirInicio(ListaLigada* listaLigada, int valor) {
		Node* novo = (Node*)malloc(sizeof(Node));
		novo->setValor(valor);
		novo->setProximo(listaLigada->getInicio());
		listaLigada->setInicio(novo);
		listaLigada->tam = tam++;
	}

	void imprimirLista(ListaLigada* listaLigada) {
		Node* inicio = listaLigada->getInicio();
		cout << "\n----------- IMPRIMINDO LISTA LIGADA -----------\n" << endl;
		cout << "\nTamanho da lista é: " << listaLigada->getTamanho() << endl;
		while (inicio != NULL)
		{
			cout << "[" << inicio->getValor() << "]";
			inicio = inicio->getProximo();
		}
	}
};

int main()
{
	ListaLigada listaLigada;
	listaLigada.InserirInicio(&listaLigada, 25);
	listaLigada.InserirInicio(&listaLigada, 35);
	listaLigada.InserirInicio(&listaLigada, 45);

	listaLigada.imprimirLista(&listaLigada);

	system("pause");

	

	return 0;
}

