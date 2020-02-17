 #include <cstdlib>
#include <iostream>

#ifndef COLA_H     
#define COLA_H 


using namespace std;

template <class T>
struct nodo{
	T dato;
    nodo *sig;
};
       

template <class T>
class cola{
	nodo<T> *cab,*fin;
      public: cola(){
	  cab=fin=NULL;
	  }
      void InsCola(T i);
      T AtenderCola();
      void ImprimirCola();
      bool ColaVacia();
      ~cola();
 };
template <class T>
void cola<T>::InsCola(T i){
     nodo<T> *nuevo;
     nuevo= new nodo<T>;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}


template <class T>
T cola<T>::AtenderCola()
{   T x;
    nodo<T> *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
    }

template <class T>
bool cola<T>::ColaVacia(){
     return (cab==NULL);
     }

template <class T>
cola<T>::~cola(){
     nodo<T> *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
     }

#endif
 

