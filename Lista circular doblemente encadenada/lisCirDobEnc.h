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
		void getInfoPos(int pos);
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
	if(listaVacia()){
		nodo<T> *nuevo = new nodo <T>;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
		nuevo -> info =  infoNueva;
		cab = nuevo;
	}else{
		nodo<T> *nuevo, *aux = new nodo <T>;
		aux = cab;
		for (int i = 1; i < tam; i++) {
			aux = aux -> sig;
		}
		aux -> sig = nuevo;
		nuevo -> sig = cab;
		nuevo -> ant = cab -> ant;
		cab -> ant = nuevo;
		cab = nuevo;
	}
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
	tam++;
}

template <class T>
void Lista<T>::insertar(T infoNueva, int pos){
	if(pos==0){
		insertarInicio(infoNueva);
		tam++;
	}else if(pos>=tam){
		insertarFinal(infoNueva);
		tam++;
	}else{
		nodo<T> *modificado; 
		nodo<T> *aux ;
		aux=cab; //El apuntador aux se iguala con el apuntador que apunta a la cabeza de la lista
		for(int i=1;i<pos;i++){
			aux=aux->sig;
		}
		modificado = aux;
		modificado->info = infoNueva;
		tam++;
		// -----
		/*
		nodo<T> *nuevo = new nodo<T>;
		nuevo -> info = infoNueva;
		nuevo -> ant = aux;
		aux = aux -> sig;
		nuevo -> sig = aux;
		*/
	}
}

template <class T>
void Lista<T>::eliminar(int pos){
	nodo<T> *ult, *seg;
	nodo<T> *aux = cab;
	for(int i=1;i<pos;i++){
		aux=aux->sig;
	}
	seg = aux -> sig;
	ult = aux -> ant;
	ult -> sig = seg;
	seg -> ant = ult;
	delete aux;
	tam--;
	if(pos == 1)
		cab = seg;
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
void Lista<T>::getInfoPos(int pos){
	nodo<T> *aux;
	aux = cab;
	for (int i = 1; i < pos; i++) {
		aux=aux->sig;
	}
	cout<<aux->info<<endl;
}
#endif
