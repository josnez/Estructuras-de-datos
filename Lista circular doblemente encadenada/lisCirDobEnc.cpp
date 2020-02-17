/*
*LISTA CIRCULAR DOBLEMENTE ENCADENADA
*Santiago Rincon Robelto - 20172020084
*Josue Alexander Nu�ez Prada - 20172020071
*/

#include "lisCirDobEnc.h"


using namespace std;

int main(){
	Lista<int> lis;

	//POS 0
	lis.insertarInicio(1);
	//POS 1
	lis.insertar(2,1);
	//POS 2
	lis.insertar(3,2);
	//POS 3
	lis.insertar(4,3);
	//POS 4
	lis.insertarFinal(5);
	//TAM = 5

	std::cout << "ARREGLO SIN INSERTAR NADA" << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getInfoPos(i)<<endl;
	}
	std::cout  << '\n';

	lis.insertar(20,1);
	lis.insertar(21,4);

	std::cout << "ARREGLO CON DOS ELEMENTOS INSERTADOS" << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getInfoPos(i)<<endl;
	}
	std::cout  << '\n';
	lis.eliminar(0);
	std::cout << "LUEGO DE ELIMINAR LA CABEZA " << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getInfoPos(i)<<endl;
	}
	std::cout  << '\n';

	lis.eliminar(3);
	std::cout << "LUEGO DE ELIMINAR LA POSICION 3 " << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getInfoPos(i)<<endl;
	}
	std::cout  << '\n';


	//VALIDACION NATURALEZA CIRCULAR
	//Ya que el metodo imprimir lista se detiene hasta que encuentra un NULL se dara un ciclo infinito
	//pues el elemento final apunta a la cabeza y no a null
	//lis.imprimirLista();


	//EN CASO DE QUE SE USE INSERTAR EN UNA POSICION NO EXISTENTE SE UTILIZARA insertarFinal
	return 0;
}
