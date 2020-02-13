/*
*LISTA SIMPLE
*Santiago Rincon Robelto - 20172020084
*Josue Alexander Nuñez Prada - 20172020071
*/

#include "listaSimple.h"


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
		cout << "Posicion: " << i <<", Valor: "<<lis.getPos(i)<<endl;
	}
	std::cout  << '\n';

	lis.insertar(20,1);
	lis.insertar(21,4);

	std::cout << "ARREGLO CON DOS ELEMENTOS INSERTADOS" << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getPos(i)<<endl;
	}
	std::cout  << '\n';
	lis.eliminar(0);
	std::cout << "LUEGO DE ELIMINAR LA CABEZA " << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getPos(i)<<endl;
	}
	std::cout  << '\n';

	lis.eliminar(3);
	std::cout << "LUEGO DE ELIMINAR LA POSICION 3 " << '\n';
	for (int i = 0; i < lis.tamanoLista(); i++) {
		cout << "Posicion: " << i <<", Valor: "<<lis.getPos(i)<<endl;
	}
	std::cout  << '\n';


	//EN CASO DE QUE SE USE INSERTAR EN UNA POSICION NO EXISTENTE SE UTILIZARA insertarFinal
	return 0;
}
