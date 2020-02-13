/*
*LISTA CIRCULAR DOBLEMENTE ENCADENADA
*Santiago Rincon Robelto - 20172020084
*Josue Alexander Nuñez Prada - 20172020071
*/

#include "lisCirDobEnc.h"


using namespace std;

int main(){
	Lista<int> lis;

	//POS 1
	lis.insertarInicio(2);
	lis.getInfoPos(1);
	//POS 2
	lis.insertarFinal(3);
	lis.getInfoPos(2);
	//POS 3
	lis.insertarFinal(4);
	lis.getInfoPos(3);	
	//POS 4
	lis.insertarFinal(5);
	lis.getInfoPos(4);
	//POS 5
	lis.insertarFinal(6);
	lis.getInfoPos(5);
	//TAM = 5
	cout << "El tamaño de la lista es: "<<lis.tamanoLista() << '\n';
	
	lis.insertar(52,2);
	lis.getInfoPos(6);
	cout << "El tamaño de la lista es: "<<lis.tamanoLista() << '\n';
	
	lis.eliminar(2);
	lis.getInfoPos(3);
	

	//VALIDACION NATURALEZA CIRCULAR
	//Ya que el metodo imprimir lista se detiene hasta que encuentra un NULL se dara un ciclo infinito
	//pues el elemento final apunta a la cabeza y no a null
	//lis.imprimirLista();

	//Si se desea obtener un elemento utlizar getPos()
	//lis.getPos(0);


	//EN CASO DE QUE SE USE INSERTAR EN UNA POSICION NO EXISTENTE SE UTILIZARA insertarFinal
	return 0;
}
