#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
using namespace std;

template <class T>
struct nodo {
	nodo<T> *sig;
	T info;
};

template <class T>
class Lista{

	nodo<T> *cab;
	int tam;

	public:
		Lista(){
			tam = 0;
		}
		bool listaVacia();
		int tamanoLista();
		void insertar(T infoNueva, int pos);
		void insertarFinal(T infoNueva);
		void insertarInicio(T infoNueva);
		void eliminar(int pos);
		void imprimirLista();
		~Lista(){
			for(int i=1;i<=tam;i++){
				nodo<T> *aux;
				aux = cab;
				cab =cab->sig;
				delete aux;
			}
		}
};

template <class T>
bool Lista <T>::listaVacia(){
	if (tam==0)
		return true;
	else
		return false;
}

template <class T>
int Lista<T>::tamanoLista(){return tam;}

template <class T>
void Lista<T>::insertarInicio(T infoNueva){
	nodo<T> *nuevo = new nodo <T>;
	cab=nuevo;
}

template <class T>
void Lista<T>::insertarFinal(T infoNueva){
	nodo<T> *nuevo = new nodo <T>, *aux;
	nuevo->info=infoNueva;
	aux=cab;
	for(int i=1;i<tam-1;i++){
		aux=aux->sig;
	}
	nuevo->sig=aux->sig;
	aux->sig=nuevo;
}

template <class T>
void Lista<T>::insertar(T infoNueva, int pos){

/*	if(pos>tam){
		std::cout << "Coefwe" << '\n';
		insertarFinal(infoNueva);
	//AQUI ENTRARA UNICAMENTE CON EL 0 SI SE LE PASA COMO POSICION 1 ENTRA AL IF DE ARRIBA Y DA ERROR
	}else if(pos<=1){
		insertarInicio(infoNueva);*/

/*Corregido*/
/* Se debe definir si la lista empieza por 0 o 1, en caso de que empiece po 0 queda asi*/
/* En todo caso es mejor invertir los if en caso de que se quiera que la lista empiece por 1*/

	if(pos==0){
		std::cout << "Coefwe" << '\n';
		insertarInicio(infoNueva);
	}else if(pos>tam){
		insertarFinal(infoNueva);
	}else{
		nodo<T> *nuevo = new nodo <T>, *aux;
		nuevo->info=infoNueva;
		aux=cab;
		for(int i=1;i<pos-1;i++){
			aux=aux->sig;
		}
		nuevo->sig=aux->sig;
		aux->sig=nuevo;
		tam++;
	}
}

template <class T>
void Lista<T>::eliminar(int pos){
	nodo<T> *aux1, *aux2;
	aux1=cab;
	aux2=cab;
	for(int i=1;i<pos-1;i++){
		aux1=aux1->sig;
	}
	for(int i=1;i<pos+1;i++){
		aux2=aux2->sig;
	}
	aux1->sig=aux2->sig;
	aux1=aux1->sig;
	delete aux1;
}

template <class T>
void Lista<T>::imprimirLista(){
	nodo<T> *aux;
	aux = cab;
	for(int i=1;i<=tam;i++){
		cout<<aux->info<<endl;
		aux=aux->sig;
	}
}

#endif
