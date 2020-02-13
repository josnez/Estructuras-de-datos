/*
*LISTA SIMPLE
*Santiago Rincon Robelto - 20172020084
*Josue Alexander Nuñez Prada - 20172020071
*/

#include "listaCircular.h"


using namespace std;

int main(){
	Lista<int> lis;

	//POS 0
	lis.insertarInicio(2);
	//POS 1
	lis.insertarFinal(3);
	//POS 2
	lis.insertarFinal(4);
	//POS 3
	lis.insertarFinal(5);
	//POS 4
	lis.insertarFinal(6);
	//TAM = 5

	lis.eliminar(0);
	lis.insertar(52,2);

	//TAMANO
	//std::cout << lis.tamanoLista() << '\n';

	//VALIDACION NATURALEZA CIRCULAR
	//Ya que el metodo imprimir lista se detiene hasta que encuentra un NULL se dara un ciclo infinito
	//pues el elemento final apunta a la cabeza y no a null
	lis.imprimirLista();

	//Si se desea obtener un elemento utlizar getPos()
	//lis.getPos(0);


	//EN CASO DE QUE SE USE INSERTAR EN UNA POSICION NO EXISTENTE SE UTILIZARA insertarFinal
	return 0;
}
