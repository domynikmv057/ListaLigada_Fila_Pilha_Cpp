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

	// Metodo para Inserir no inicio
	void InserirInicio(ListaLigada* listaLigada, int valor) {
		Node* novo = (Node*)malloc(sizeof(Node));
		novo->setValor(valor);
		novo->setProximo(listaLigada->getInicio());
		listaLigada->setInicio(novo);
		listaLigada->tam = tam++;
	}
	// Fim do metodo para Inserir no inicio
	// Metodo para Inserir no final. 
	void inserirFinal(ListaLigada* listaLigada, int valor) {
		Node* node, * novo = (Node*)malloc(sizeof(Node));
		novo->setValor(valor);
		novo->setProximo(NULL);

		if (listaLigada->getInicio() == NULL)
		{
			listaLigada->setInicio(novo);
		}
		else
		{
			node = listaLigada->getInicio();

			while (node->getProximo() != NULL)
			{
				node = node->getProximo();
			}
			node->setProximo(novo);
		}
		listaLigada->tam++;
	}
	// Fim do metodo para Inserir no final. 
	// Metodo Remover Lista ligada
	
	void removerListaLigada(ListaLigada* listaLigada, int valor) {
		Node* inicioAux = listaLigada->getInicio();
		Node* eleRemover = NULL;

		if (inicioAux != NULL && listaLigada->getInicio()->getValor() == valor)
		{
			eleRemover = listaLigada->getInicio();
			listaLigada->setInicio(eleRemover->getProximo());
		}
		else
		{
			while ( inicioAux != NULL && 
					inicioAux->getProximo() != NULL &&
					inicioAux->getProximo()->getValor() != valor)
			{
				inicioAux = inicioAux->getProximo();
			}if (inicioAux != NULL && inicioAux->getProximo() != NULL)
			{
				eleRemover = inicioAux->getProximo();
				inicioAux->setProximo(eleRemover->getProximo());
			}
		}

		if (eleRemover)
		{
			free(eleRemover);
			listaLigada->tam--;
		}
	}

	// Fim metodo Remover Lista Ligada
	// Metodo Para imprimir
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
	// Fim do metodo Para imprimir

};

int main()
{
	int opcao, opcaoListaLigada, valor;


		ListaLigada listaLigada;
	do
	{
		system("cls");
		cout << "\n 1- Inserir no inicio da lista. " << endl
			 << "\n 2- Inserir no final da lista. " << endl
			 << "\n 3- Remover elemento da lista." << endl
			 << "\n 4- Imprimir a lista." << endl
			 << "\n 5- Sair.\n" << endl;

		cin >> opcaoListaLigada;

		switch (opcaoListaLigada)
		{
		case 1:
			system("cls");
			cout << "\n INSERIR NO INICIO DA LISTA." << endl
				<< "\n Digite o valor a ser inserido: \n" << endl;
			cin >> valor;	
			listaLigada.InserirInicio(&listaLigada, valor);
			break;
		case 2:
			system("cls");
			cout << "\n INSERIR NO FINAL DA LISTA." << endl
				<< "\n Digite o valor a ser inserido: \n" << endl;
			cin >> valor;
			listaLigada.inserirFinal(&listaLigada, valor);
			break;
		case 3:
			system("cls");
			listaLigada.imprimirLista(&listaLigada);
			cout << "\n\n REMOVER ELEMENTO DA LISTA." << endl
				<< "\n Digite o valor a ser removido: \n" << endl;
			cin >> valor;
			listaLigada.removerListaLigada(&listaLigada, valor);
			break;
		case 4:
			system("cls");
			cout << "\n IMPRIMIR A LISTA.\n" << endl;
			listaLigada.imprimirLista(&listaLigada);
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "\n Saindo ... \n" << endl;
			break;
		default:
			cout << "\n Opção invalida, tente de novo ... \n" << endl;
		}

	} while (opcaoListaLigada != 5);

	system("pause");

	

	return 0;
}

