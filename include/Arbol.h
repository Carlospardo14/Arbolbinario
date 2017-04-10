#include "Nodo.h"
class Arbol{
public:
	Nodo * Raiz;
	Arbol(int Dato){
	this -> Raiz= new Nodo(Dato);
	}
	Arbol(){
	this-> Raiz=NULL;
	}

	Nodo *Buscar(int Ref, Nodo* aux);
	bool insertar (int Dato);
	Nodo *Insertar(int Ref, Nodo * aux);
	bool eliminar(int Ref);
	Nodo *Dere(Nodo *aux);

	void LadoIzq(Nodo *aux);
	void LadoDer(Nodo *aux);

	void ShowA();
	void imprime();
	void imprimeRec(Nodo *aux);
	void verArbol(Nodo *aux,int Ref);
	void preOrden(Nodo *p);
	void inOrden(Nodo *p);
	void postOrden(Nodo *p);
	void Recorridos(int tipo);
};