#include <iostream>
using namespace std;


class Node
{

private:
	int valor;
	Node* proximo;
;
public:

	Node()
	{
		setValor(NULL);
		setProximo(NULL);
	}
	Node(int valor)
	{
		setValor(valor);
		setProximo(NULL);
	}
	Node(int valor, Node* elemento)
	{
		setValor(valor);
		setProximo(elemento);
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
	Node* inicioLista;
	Node* fimLista;
	int tam;

public:
	ListaLigada() {
		setInicio(NULL);
		setFim(NULL);
		this->tam = 0;
	}

	void setInicio(Node* primeiroElemento) {
		this->inicioLista = primeiroElemento;
	}

	Node* getInicio() {
		return this->inicioLista;
	}


	void setFim(Node* ultimoElemento) {
		this->fimLista = ultimoElemento;
	}

	Node* getFim() {
		return this->fimLista;
	}

	int getTamanho() {
		return this->tam;
	}
	// Metodo para Inserir no inicio
	void InserirInicio( int valor) {
		Node *novo = new Node(valor, this->inicioLista);
		if (this->inicioLista == NULL)// Se inicioLista == a null é o 1 elemento entao seto inicio e o fim da lista para esse elemento
		{
			this->inicioLista = novo;
			this->fimLista = novo;
			this->tam++;
		}
		else// se nao, a lista tem elementos, entao so seto o novo elemento;
		{
			this->inicioLista = novo;
			this->tam++;
		}
	}
	// Fim do metodo para Inserir no inicio
	
	// Metodo para Inserir no final. 
	void inserirFinal(int valor) {
		Node * novo = new Node(valor);

		if (this->inicioLista == NULL)
		{
			this->inicioLista = novo;
			this->fimLista = novo;
		}
		else
		{
			this->fimLista->setProximo(novo);
			this->fimLista = novo;
		}
		this->tam++;
	}
	// Fim do metodo para Inserir no final.
	
	// Metodo Remover Lista ligada
	void removerListaLigada(int valor) {
		Node* inicioAux = this->inicioLista;
		Node* eleRemover = NULL;

		if (inicioAux != NULL && this->inicioLista->getValor() == valor)
		{
			eleRemover = this->inicioLista;
			this->inicioLista = eleRemover->getProximo();
		}
		else
		{
			while ( inicioAux != NULL && 
					inicioAux->getProximo() != NULL &&
					inicioAux->getProximo()->getValor() != valor)
			{
				inicioAux = inicioAux->getProximo();
			}if (inicioAux != NULL && inicioAux->getProximo()->getValor() == this->fimLista->getValor())
			{
				eleRemover = inicioAux->getProximo();
				inicioAux->setProximo(NULL);
				this->fimLista = inicioAux;


			}else if (inicioAux != NULL && inicioAux->getProximo() != NULL)
			{
				eleRemover = inicioAux->getProximo();
				inicioAux->setProximo(eleRemover->getProximo());
			}
		}

		if (eleRemover)
		{
			free(eleRemover);
			this->tam--;
		}
	}
	// Fim metodo Remover Lista Ligada
	
	// Metodo Para imprimir
	void imprimirLista() {
		Node* inicio = this->inicioLista;
		cout << "\n----------- IMPRIMINDO -----------\n" << endl;
		cout << "\nTotal de elementos: " << this->tam << endl;
		while (inicio != NULL)
		{
			cout << "[" << inicio->getValor() << "]";
			inicio = inicio->getProximo();
		}
	}
	// Fim do metodo Para imprimir

	// Metodo para remover primeiro elemento;
	void removerPrimeiro() {
		Node* eleRemover = this->inicioLista;

		if (this->inicioLista != NULL)
		{
			if (this->inicioLista == this->fimLista)
			{
				this->inicioLista = NULL;
				this->fimLista = NULL;
			}
			else {
				eleRemover = this->inicioLista;
				this->inicioLista = eleRemover->getProximo();
			}

		}
		if (eleRemover)
		{
			free(eleRemover);
			this->tam--;
		}
	}
	// Fim metodo para remover primeiro elemento;

	// Metodo para remover ultimo elemento;
	void removerUltimo() {
		Node* aRemover = this->fimLista,*percorrer = this->inicioLista;

		if (this->inicioLista != NULL)
		{
			if (this->inicioLista == this->fimLista) {
				this->inicioLista = NULL;
				this->fimLista = NULL;
			}
			else
			{
				while (percorrer->getProximo()->getProximo() != NULL)
				{
					percorrer = percorrer->getProximo();
				}
				percorrer->setProximo(NULL);
				this->fimLista = percorrer;
			}
		}

		if (aRemover)
		{
			free(aRemover);
			this->tam--;
		}
	}
	// fim metodo para remover ultimo elemento;
};

class Fila : public ListaLigada {

public:
	Fila() : ListaLigada() {
	}

};

class Pilha : public ListaLigada {
public:
	Pilha() : ListaLigada() {

	}
};

int main()
{
	int opcao, opcaoListaLigada, opcaoFila, opcaoPilha, valor;
	ListaLigada* listaLigada = new ListaLigada();
	Fila* fila = new Fila();
	Pilha* pilha = new Pilha();
	

	cout << "\n -- Escolha com qual estrutura deseja trabalhar -- \n" << endl;

	do
	{
		cout << "\n 1- Lista Ligada " << endl
			 << "\n 2- Fila. " << endl
			 << "\n 3- Pilha." << endl
			 << "\n 5- Sair.\n" << endl;
		cin >> opcao;

		switch (opcao)
		{
		case 1:

			do
			{
				cout << "\n 1- Inserir no inicio da lista. " << endl
					<< "\n 2- Inserir no final da lista. " << endl
					<< "\n 3- Remover elemento da lista." << endl
					<< "\n 4- Remover elemento do inicio da lista." << endl
					<< "\n 5- Remover elemento do fim da lista." << endl
					<< "\n 6- Imprimir a lista." << endl
					<< "\n 7- Sair.\n" << endl;

				cin >> opcaoListaLigada;

				switch (opcaoListaLigada)
				{
				case 1:
					system("cls");
					cout << "\n INSERIR NO INICIO DA LISTA." << endl
						<< "\n Digite o valor a ser inserido: \n" << endl;
					cin >> valor;
					listaLigada->InserirInicio(valor);
					break;
				case 2:
					system("cls");
					cout << "\n INSERIR NO FINAL DA LISTA." << endl
						<< "\n Digite o valor a ser inserido: \n" << endl;
					cin >> valor;
					listaLigada->inserirFinal(valor);
					break;
				case 3:
					system("cls");
					listaLigada->imprimirLista();
					cout << "\n\n REMOVER ELEMENTO DA LISTA." << endl
						<< "\n Digite o valor a ser removido: \n" << endl;
					cin >> valor;
					listaLigada->removerListaLigada(valor);
					break;
				case 4:
					system("cls");
					listaLigada->imprimirLista();
					cout << "\n\n REMOVER PRIMEIRO ELEMENTO DA LISTA." << endl;
					listaLigada->removerPrimeiro();
					break;
				case 5:
					system("cls");
					listaLigada->imprimirLista();
					cout << "\n\n REMOVER ULTIMO ELEMENTO DA LISTA." << endl;
					listaLigada->removerUltimo();
					break;
				case 6:
					system("cls");
					cout << "\n IMPRIMIR A LISTA.\n" << endl;
					listaLigada->imprimirLista();
					cout << endl;
					system("pause");
					break;
				case 7:
					cout << "\n Saindo ... \n" << endl;
					break;
				default:
					cout << "\n Opção invalida, tente de novo ... \n" << endl;
				}

			} while (opcaoListaLigada != 7);
			break;
		case 2:
			do
			{
				system("cls");
				cout << "\n 1- Inserir. " << endl
					<< "\n 2- Imprimir. " << endl
					<< "\n 3- Remover." << endl
					<< "\n 5- Sair.\n" << endl;
				cin >> opcaoFila;

				switch (opcaoFila)
				{
				case 1:
					system("cls");
					cout << "\n--- INSERIR ---" << endl
						<< "\n Digite o valor a ser inserido: \n" << endl;
					cin >> valor;
					fila->InserirInicio(valor);
					break;
				case 2:
					system("cls");
					cout << "\n IMPRIMIR A LISTA.\n" << endl;
					fila->imprimirLista();
					cout << endl;
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "\n\n--- REMOVER ELEMENTO ---." << endl;
					fila->removerUltimo();
					break;
				case 5:
					system("cls");
					cout << "\n saindo ..." << endl;
					break;
				default:
					cout << "\nOpção invalida ... \n" << endl;
				}

			} while (opcaoFila != 5);
			break;
		case 3:
			do
			{
				system("cls");
				cout << "\n 1- Inserir. " << endl
					<< "\n 2- Imprimir. " << endl
					<< "\n 3- Remover." << endl
					<< "\n 5- Sair.\n" << endl;
				cin >> opcaoPilha;

				switch (opcaoPilha)
				{
				case 1:
					system("cls");
					cout << "\n--- INSERIR ---" << endl
						<< "\n Digite o valor a ser inserido: \n" << endl;
					cin >> valor;
					pilha->InserirInicio(valor);
					break;
				case 2:
					system("cls");
					cout << "\n IMPRIMIR A LISTA.\n" << endl;
					pilha->imprimirLista();
					cout << endl;
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "\n\n--- REMOVER ELEMENTO ---." << endl;
					pilha->removerPrimeiro();
					break;
				case 5:
					system("cls");
					cout << "\n saindo ..." << endl;
					break;
				default:
					cout << "\nOpção invalida ... \n" << endl;
				}

			} while (opcaoPilha != 5);
			break;
			break;
		case 5:
			cout << "\n saindo ..." << endl;
			break;
		default:
			cout << "\nOpção invalida ... \n" << endl;
		}


	} while (opcao);

	system("pause");

	

	return 0;
}

