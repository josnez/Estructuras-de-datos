#include "listaSimple.h"


using namespace std;

int main(){
	Lista<int> lis;
	lis.insertar( 3, 1);
	lis.insertar(9, 2);
	lis.imprimirLista();
	lis.~Lista();
	return 0;
}
