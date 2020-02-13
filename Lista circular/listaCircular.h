#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <iostream>
using namespace std;

template <class T>

//DECLARACION DE LA ESTRUCTURA
struct nodo {
	nodo<T> *sig;
	T info;
};

//DECLARACION DE LA CLASE QUE CONTIENE UNA ESTRUCTURA TIPO NODO
template <class T>
class Lista{

	nodo<T> *cab; //Un apuntador a un nodo
	int tam; //un tamano o identificador

public:
	Lista(){
		tam = 0; // Naturalmente el tamno inicial sera 0
	}
	bool listaVacia();
	int tamanoLista();
	void insertar(T infoNueva, int pos); //USADO SOLO PARA MODIFICAR EXISTENTES
	void insertarFinal(T infoNueva); //USADO PARA AGREGAR NUEVOS
	void insertarInicio(T infoNueva);//USADO PARA AGREGAR UNICAMENTE EL INICIAL
	void eliminar(int pos);
	void imprimirLista();
	void getPos(int);

};

/*
*Se determina si la lista tiene o no elementos
*@return  1 si hay elementos
*@return  0 si no hay elementos
*/
template <class T>
bool Lista <T>::listaVacia(){
	if (tam==0)
	return true;
	else
	return false;
}

/*
*Se determinan la cantidad de elementos de la lista
*@return  int cantidad elementos
*/
template <class T>
int Lista<T>::tamanoLista(){
	return tam;
}

/*
*Se inserta el primer elemento a la lista
*@param (T) infoNueva: el valor a guardar en el primer espacio
*/
template <class T>
void Lista<T>::insertarInicio(T infoNueva){
	nodo<T> *nuevo = new nodo <T>; //Se crea un apuntador que apunta a un nuevo nodo
	cab=nuevo; //Al apuntador cab  se le da un nodo al que apuntar
	nuevo -> sig = cab; //Ese nuevo nodo apuntara a la cabeza
	nuevo-> info =  infoNueva; //Se le pone la informacion al nuevo nodo
	tam++; // Se incremena el tamano de la variable de la CLASE
}

/*
*Se inserta un elemento al final de la lista
*@param (T) infoNueva: el valor a guardar en el ultimo espacio
*/
template <class T>
void Lista<T>::insertarFinal(T infoNueva){
	nodo<T> *nuevo = new nodo <T>;
	nodo<T> *aux ;
	aux=cab;
	nuevo->info=infoNueva; //Se agrega la informacion en el nuevo nodo

	for(int i=0;i<tam-1;i++){ //Se lleva aux hasta el ultimo nodo
		aux=aux->sig;
	}
	aux->sig=nuevo;
	nuevo->sig=cab;
	tam++;

}

/*
*Se inserta un nuevo elemento en un espacio ya existente
*@param (T) infoNueva: el valor a guardar en el primer espacio
*@param (T) pos: la posicion que se va a modificar (debe de existir)
*/
template <class T>
void Lista<T>::insertar(T infoNueva, int pos){
	if(pos==0){
		insertarInicio(infoNueva);
	}else if(pos>=tam){
		insertarFinal(infoNueva);

	}else{
		nodo<T> *modificado; //Se crea el el nuevo nodo
		nodo<T> *aux ;
		aux=cab; //El apuntador aux se iguala con el apuntador que apunta a la cabeza de la lista
		for(int i=1;i<pos-1;i++){ //Se hace avanzar aux desde la cabeza hasta pos-1 nodo existente
			aux=aux->sig;
		}
		modificado = aux->sig;
		modificado->info = infoNueva;
	}
}

/*
*Se elimina el nodo de cierta posicion
*@param (T) pos: la posicion que se va a eliminar (debe de existir)
*/
template <class T>
void Lista<T>::eliminar(int pos){

	nodo<T> *aux1, *aux2;
	aux1=cab;
	aux2=cab;
	if(pos == 0){//Si se desea eliminar la posicion 1
		aux1 = cab; //Se iguala aux 1 a el elemento 0
		aux1 = aux1->sig; //Se avanza aux1 al elemento 1
		cab = aux1; //La nueva cabeza sera el elemento 1
		delete aux2; //Se elimina el elemento 0
		tam --;

		//Se actualiza la cabeza del ultimo elemento
		nodo<T> *aux;
		aux = cab;
		for (int i = 0; i < tam-1; i++) {
			aux=aux->sig;
		}
		aux->sig = cab;



	}else{
		for(int i=1;i<pos;i++){
			aux1=aux1->sig;
			aux2=aux2->sig;
		}
		aux1=aux1->sig; //AUX1 estara apuntando al nodo que se desea eliminar
		aux2->sig=aux1->sig; //AUX2 apuntara al nuevo nodo (despues del eliminado) por medio del siguiente se aux1
		delete aux1;
		tam--;
	}
}

/*
*Se imprime la lista actual
*/
template <class T>
void Lista<T>::imprimirLista(){
	nodo<T> *aux;
	aux = cab;
	while(aux->sig != NULL){
		cout<<aux->info<<endl;
		aux=aux->sig;
	}
	if(aux->sig == NULL){
		cout << "NULL :c" << '\n';
	}

}
/*
*Se imprime la lista actual
*/
template <class T>
void Lista<T>::getPos(int pos){
	nodo<T> *aux;

	aux = cab;
	for (int i = 0; i < pos-1; i++) {
		aux=aux->sig;
	}
	cout<<aux->info<<endl;


}

#endif
