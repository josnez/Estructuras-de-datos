#include "cola.h"
#include <iostream>

int main(){
	cola<int> a;
	
	a.InsCola(12);
	a.InsCola(1);
	a.InsCola(2);
	
	cout << a.AtenderCola() << endl;
	cout << a.AtenderCola() << endl;
	cout << a.AtenderCola() << endl;
	
}
