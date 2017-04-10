#include "Arbol.h"




bool Arbol::insertar (int Dato){
	if (Buscar(Dato,this->Raiz)!=NULL){
		std::cout<<"El dato no se encuentra"<<std::endl;
		return false;
	}
	Nodo *aux= Insertar(Dato,this->Raiz);
	 Nodo *n= new Nodo(Dato,aux);
	 if(aux->Dato>Dato)
	 	aux->Izq=n;
	 else
	 	aux->Der=n;
	 return true;
}

Nodo* Arbol::Buscar(int Ref, Nodo* aux){
	if(aux->Dato==Ref)
	return aux;
	if(aux->Dato<Ref && aux->Der!=NULL)
	return  Buscar(Ref,aux->Der);
	else if (aux->Dato>Ref && aux->Izq!=NULL)
	return Buscar(Ref,aux->Izq);
	return NULL;
}

Nodo* Arbol::Insertar(int Ref, Nodo * aux){
	if(aux->Dato>Ref){
		if (aux->Izq==NULL)
		{
			return aux;
		}
		return Insertar(Ref,aux->Izq);
	}
	else{
		if(aux->Der==NULL)
		{
			return aux;
		}
		return Insertar(Ref,aux->Der);
	}
}

bool Arbol::eliminar(int Ref){
	Nodo * aux=Buscar(Ref,this->Raiz);
	if (aux==NULL)
	{
	return false;
	}
		

	if(aux->Der==NULL && aux->Izq==NULL)
	{
	if (aux==aux->padre->Izq)
	{
		aux->padre->Izq=NULL;
		}else{ aux->padre->Der=NULL;}
		aux->padre=NULL;
		return true;
	}


	if(aux->Izq==NULL){
		if (aux==aux->padre->Izq)
		{aux->padre->Izq=aux->Der;}
		
		else {aux->padre->Der=aux->Der;}
		
		aux->Der->padre=aux->padre;
		aux->padre=NULL;
	
	}else{
		if(aux->Izq->Der==NULL){
			aux->Izq->Der=aux->Der;
			aux->Izq->padre=aux->padre;
			if (aux==aux->padre->Izq)
			{aux->padre->Izq=aux->Izq;}
		else{aux->padre->Der=aux->Izq;}
			aux->Der=NULL;
		aux->Izq=NULL;
		aux->padre=NULL;
		}

	else{
		Nodo *aux1=Dere(aux->Izq);
		if (aux1->Izq!=NULL)
			{
				aux1->padre->Der=aux1->Izq;
				aux1->Izq->padre=aux1->padre;
			}
			aux1->padre=aux->padre;
			aux->Izq->padre=aux1;
			aux1->Izq=aux->Izq;
			if(aux->Der!=NULL){
				aux1->Der=aux->Der;
				aux1->Der->padre=aux1;
			}
			if (aux==aux->padre->Izq)
			{
				aux1->padre->Izq=aux1;
			}
			else{
				aux1->padre->Der=aux1;
			}
			aux->Der=NULL;
			aux->Izq=NULL;
			aux->padre=NULL;
		}
	}
}

Nodo* Arbol::Dere(Nodo *aux){
	if (aux->Der!=NULL)
		return Dere(aux->Der);
	return aux;

}
void Arbol::LadoIzq(Nodo *aux)
{
	while(aux->Izq != NULL)
	{
		std::cout<<aux->Izq->Dato<<std::endl;
		aux = aux->Izq;
	}
}
void Arbol::LadoDer(Nodo *aux)
{

	std::cout<<"\t"<<" ";
	while(aux->Der != NULL)
	{
		std::cout<<"\t"<<" ";
		std::cout<<aux->Der->Dato<<std::endl;
		aux = aux->Der;
	}
}

void Arbol::ShowA()
{
	insertar(9);
	insertar(10);
	insertar(2);
	insertar(5);
	insertar(8);
	insertar(12);
	insertar(7);
	insertar(11);	
	insertar(20);
	insertar(19);
	insertar(16);
	insertar(23);
	insertar(45);
	insertar(98);
}

void Arbol::preOrden(Nodo *p){
    if(p != NULL){
        std::cout << p->Dato<< ", ";
        preOrden(p->Izq);
        preOrden(p->Der);
    }
}

void Arbol::inOrden(Nodo *p){
    if(p != NULL){        
        inOrden(p->Izq);
        std::cout << p->Dato << ", ";
        inOrden(p->Der);
    }
}

void Arbol::postOrden(Nodo *p){
    if(p != NULL){
        std::cout << p->Dato << ", ";
        postOrden(p->Izq);
        postOrden(p->Der);
    }
}
void Arbol::Recorridos(int tipo){
    switch(tipo){
        case 1:
            preOrden(Raiz);
        break;
        
        case 2:
            inOrden(Raiz);
        break;
        
        case 3:
            postOrden(Raiz);
        break;
	
        default:
	  std::cout<<"Error! opcion invalida"<<std::endl;
	  break;
    }
}


/*void Arbol::imprime()
{
		
	if (Raiz == NULL)
	{
		std::cout<<"no está el elemento"<<std::endl;
	}
	
	std::cout<<Raiz->Dato<<std::endl;
	return imprimeRec(Raiz);

}

void Arbol::imprimeRec(Nodo *aux)
{
	Nodo *Busqueda=aux;
	
	if (Busqueda->Der == NULL && Busqueda->Izq == NULL)
	{
		std::cout<<"solamente raiz existente"<<std::endl;
	}
	if (Busqueda->Izq != NULL)
	{
		while(Busqueda->Izq != NULL)
		{
		LadoIzq(Busqueda->Izq);
		LadoDer(Busqueda->Izq);
		Busqueda = Busqueda->Izq;
		}
	}
	else
	{
		if (Busqueda->Der != NULL)
		{
			while(Busqueda->Der != NULL)
			{
			LadoIzq(Busqueda->Der);
			LadoDer(Busqueda->Der);
			Busqueda = Busqueda->Der;
			}
		}
	}

}*/
