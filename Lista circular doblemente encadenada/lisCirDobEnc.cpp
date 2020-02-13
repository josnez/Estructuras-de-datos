/*
*LISTA CIRCULAR DOBLEMENTE ENCADENADA
*Santiago Rincon Robelto - 20172020084
*Josue Alexander Nu�ez Prada - 20172020071
*/

#include "lisCirDobEnc.h"


using namespace std;

int main(){
	Lista<int> lis;

	//POS 1
	lis.insertarInicio(1);
	//POS 2
	lis.insertarFinal(2);
	//POS 3
	lis.insertarFinal(3);
	//POS 4
	lis.insertarFinal(5);
	//POS 5
	lis.insertarFinal(6);
	//TAM = 5
	lis.getInfoPos(0);



	//VALIDACION NATURALEZA CIRCULAR
	//Ya que el metodo imprimir lista se detiene hasta que encuentra un NULL se dara un ciclo infinito
	//pues el elemento final apunta a la cabeza y no a null
	//lis.imprimirLista();

	//Si se desea obtener un elemento utlizar getPos()
	//lis.getPos(0);


	//EN CASO DE QUE SE USE INSERTAR EN UNA POSICION NO EXISTENTE SE UTILIZARA insertarFinal
	return 0;
}
