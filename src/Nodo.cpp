#include "Nodo.h"
#include <stddef.h>

Nodo::Nodo(int Dato){
 	this->Dato=Dato;
 	this->padre=NULL;
 	 }
 Nodo::Nodo(int Dato,Nodo *padre){
 	this->Dato=Dato;
 	this->padre=padre;
 }