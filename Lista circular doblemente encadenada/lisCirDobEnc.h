#ifndef LISTACIRDOB_H
#define LISTACIRDOB_H

#include <iostream>
using namespace std;

template <class T>
struct nodo {
	nodo<T> *sig,*ant;
	T info;
};

template <class T>
class Lista{
	nodo<T> *cab;
	int tam;

public:
	Lista(){
		cab = NULL;
		tam = 0;
	}
	bool listaVacia();
	int tamanoLista();
	void insertar(T infoNueva, int pos); //USADO SOLO PARA MODIFICAR EXISTENTES
	void insertarFinal(T infoNueva); //USADO PARA AGREGAR NUEVOS
	void insertarInicio(T infoNueva);//USADO PARA AGREGAR UNICAMENTE EL INICIAL
	void eliminar(int pos);
	void imprimirLista();
	T getInfoPos(int pos);
};

template <class T>
bool Lista <T>::listaVacia(){
	if (tam==0)
	return true;
	else
	return false;
}

template <class T>
int Lista<T>::tamanoLista(){
	return tam;
}

template <class T>
void Lista<T>::insertarInicio(T infoNueva){
	nodo<T> *nuevo = new nodo <T>;
	cab = nuevo;

	nuevo -> sig = cab;
	nuevo -> ant = cab;
	nuevo -> info =  infoNueva;
	tam++;
}

template <class T>
void Lista<T>::insertarFinal(T infoNueva){
	nodo<T> *nuevo = new nodo <T>;
	nodo<T> *aux;
	aux = cab;
	for(int i=1;i<tam;i++){
		aux = aux -> sig;
	}
	aux -> sig = nuevo;
	nuevo -> ant = aux;
	nuevo -> sig = cab;
	nuevo -> info = infoNueva;
	cab -> ant = nuevo;
	tam++;
}

template <class T>
void Lista<T>::insertar(T infoNueva, int pos){
	if(pos==0){
		insertarInicio(infoNueva);
	}else if(pos>=tam){
		insertarFinal(infoNueva);
	}else{
		nodo<T> *nuevo = new nodo<T>;
		nodo<T> *auxA;
		nodo<T> *auxB;
		auxA=cab; //El apuntador aux se iguala con el apuntador que apunta a la cabeza de la lista
		auxB=cab;
		for(int i=1;i<pos;i++){
			auxA=auxB->sig;
			auxB=auxB->sig;
		}
		//Se avanza auxB uno mas
		auxB=auxB->sig;



		nuevo->info = infoNueva;
		//Se relacionan de ida
		nuevo->sig = auxB;
		auxA->sig = nuevo;

		//Se relacionan de vuelta
		nuevo->ant = auxA;
		auxB->ant = nuevo;
		tam++;



	}
}

template <class T>
void Lista<T>::eliminar(int pos){
	nodo<T> *auxA = cab;
	nodo<T> *auxB = cab;
	//Se elimina la cabeza
	if(pos == 0){
		//El elemento a eliminar
		auxB = cab;
		//Se almacena el elemento final
		auxA =  cab ->ant;
		//Se actualiza la cabeza
		cab = cab ->sig;
		cab ->ant = auxA;
		//Se actualiza el ultimo elemento
		auxA ->sig = cab;

		delete auxB;
		tam --;
		//Se elimina un elemento de en medio
	}else if (pos < tamanoLista()){
		//Se sube hasta el nodo anterior a ser eliminado
		for(int i=1;i<pos;i++){
			auxA=auxA->sig;
			auxB=auxB->sig;
		}
		//Se sube auxB uno mas quedando en el nodo a eliminar
		auxB=auxB->sig;

		//Revinculacion de ida
		auxA->sig = auxB->sig;

		//Revinculacion de vuelta
		//Se salta al nodo siguiente del que se va a eliminar y se modifica su anterior
		(auxB->sig)->ant = auxA;

		//Se elimina auxB
		delete auxB;
		tam--;

		//Se elimina el ultimo elemento
	}else{
		//Elemento a borrar
		auxA =  cab->ant;

		//Se sube auxB hasta el penultimo nodo
		for(int i=1;i<tamanoLista();i++){
			auxB=auxB->sig;
		}
		//Se actualizan los vinculos
		auxB->sig =  cab;
		cab->ant = auxB;

		//Se elimina el elemento
		delete auxA;
		tam--;
	}
}

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

template <class T>
T Lista<T>::getInfoPos(int pos){
	nodo<T> *aux;
	aux = cab;
	for (int i = 0; i < pos; i++) {
		aux=aux->sig;
	}
	return aux->info;
}
#endif
