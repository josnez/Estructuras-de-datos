#ifndef PILA
#define PILA_H
#include <iostream>
using namespace std;




template <class T>
class Pila{
T *pila;
int p;

public:
  Pila (int max=100){
  	pila = new T[max]; p=0;
	}
	void meter(T v);
	T sacar();
	int vacia();
~Pila()
   {delete pila;}
};


template <class T>
 void Pila<T>::meter (T v)
   {pila[p++]=v;}

template <class T>
 T Pila<T>::sacar()
  {return pila [--p];}

template <class T>
int Pila<T>::vacia()
  {return !p;} 



#endif
