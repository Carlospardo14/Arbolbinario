#include "Arbol.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

void printSubMenu(){
    std::cout<<"1.Imprimir en pre-orden"<<std::endl;
    std::cout<<"2.Imprimir en in-orden"<<std::endl;
    std::cout<<"3.Imprimir en post-orden"<<std::endl;
    std::cout<<"\tOPCION: "<<std::endl;}

int main()
{
	Arbol ab = Arbol(90);
	int aux = 0;

	ab.ShowA();

	printSubMenu();
            fflush(stdin);
            std::cin>>aux;
            ab.Recorridos(aux);
            std::cout<<std::endl;

	return 0;
}
   