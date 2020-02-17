#include <iostream>

using namespace std;

struct cabecera{
	string caracteristica;
	int pos;
};
//Variable global
cabecera lisCabeceras[10];

struct info{
	string nom, carrera, hobby;
	int edad, sigNom, sigCarr, sigHob, sigEdad;
};
//VARIABLE GLOBAL
info *estudiantes;

void ordenarPorNombre(){

	int auxNom = lisCabeceras[0].pos;

	cout<<"\n Ordenado por nombre: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigNom;
	}
}

void ordenarPorCarreraSistemas(){
	int auxNom = lisCabeceras[1].pos;

	cout<<"\n Ordenado por carrera sistemas: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigCarr;
	}
}
void ordenarPorCarreraIndustrial(){
	int auxNom = lisCabeceras[2].pos;

	cout<<"\n Ordenado por carrera industrial: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigCarr;
	}
}
void ordenarPorCarreraElectrica(){
	int auxNom = lisCabeceras[3].pos;

	cout<<"\n Ordenado por carrera electrica: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigCarr;
	}
}
void ordenarPorCarreraCatastral(){
	int auxNom = lisCabeceras[4].pos;

	cout<<"\n Ordenado por carrera catastral: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigCarr;
	}
}

void ordenarPorHobbyDanza(){
	int auxNom = lisCabeceras[5].pos;

	cout<<"\n Ordenado por hobby danza: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigHob;
	}
}
void ordenarPorHobbyNatacion(){
	int auxNom = lisCabeceras[6].pos;

	cout<<"\n Ordenado por hobby natacion: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigHob;
	}
}
void ordenarPorHobbyBeisbol(){
	int auxNom = lisCabeceras[7].pos;

	cout<<"\n Ordenado por hobby beisbol: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigHob;
	}
}
void ordenarPorHobbyBasket(){
	int auxNom = lisCabeceras[8].pos;

	cout<<"\n Ordenado por hobby Basket: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigHob;
	}
}

void ordenarPorEdad(){
	int auxNom = lisCabeceras[9].pos;

	cout<<"\n Ordenado por Edad: ";

	while(auxNom >-1 ){
		cout<<estudiantes[auxNom].nom << ",";
		auxNom = estudiantes[auxNom].sigEdad;
	}
}

int main(){


	//DECLARACION DE LAS CABEZAS
	lisCabeceras[0].caracteristica = "Nombre";
	lisCabeceras[1].caracteristica = "Sistemas";
	lisCabeceras[2].caracteristica = "Industrial";
	lisCabeceras[3].caracteristica = "Electrica";
	lisCabeceras[4].caracteristica = "Catastral";
	lisCabeceras[5].caracteristica = "Danza";
	lisCabeceras[6].caracteristica = "Natacion";
	lisCabeceras[7].caracteristica = "Beisbol";
	lisCabeceras[8].caracteristica = "Basquet";
	lisCabeceras[9].caracteristica = "Edad";

	//SE LLENAN TODAS LAS CABEZAS CON -1
	for(int i=0; i<10; i++){
		lisCabeceras[i].pos=-1;
	}

	//SE PIDE LA CANTIDAS DE ESTUDIANTES A USAR
	cout<<"Digite cuantos estudiantes va a ingresar: "<<endl;
	int numEst;
	cin>>numEst;

	//SE DA A DONDE APUNTAR AL APUNTADO (EL APUNTADOR ES GLOBAL)
	estudiantes = new info[numEst];

	//VARIABLE AUX DONDE SE ALMACENARA EL NOMBRE DEL ESTUDIANTEs
	string nombreEst;
	int auxPos;

	//SE UTILIZA EL -1 COMO POSICION DE CONTROL Y NO EL 0 COMO EN CLASE
	for(int i=0; i<numEst; i++){
		//SE LLENAN TODOS LOS SIGUIENTES CON NADIE A QUIEN SEGUIR
		estudiantes[i].sigCarr=-1;
		estudiantes[i].sigEdad=-1;
		estudiantes[i].sigHob=-1;
		estudiantes[i].sigNom=-1;

		//SE PIDE EL NOMBRE POR CONSOLA
		cout<<"Nombre: ";
		cin>>nombreEst;

		//SE LLENA EL ARREGLO ESTUDIANTES CON TODOS SUS DATOS (ES DE TIPO INFO)
		estudiantes[i].nom = nombreEst;

		//SE OBTIENE LA PRIMERA POSICION DEL NOMBRE EN CABECERA
		auxPos = lisCabeceras[0].pos;

		//Variable usada para guardar el anterior
		int auxtemp;

		//SI NO HAY NADA DEFINIDO EN LA CABECERA
		if(auxPos==-1){
			lisCabeceras[0].pos=i;
			estudiantes[i].sigNom = -1;
			//VERIFICAR LA COMPARACION PUEDE SER UN PROBLEMA

			//SI EL VALOR ACTUAL VA DESPUES AL REGISTRADO, SI HAY UNA A Y SE METE UNA B ENTRA
		}else if((estudiantes[auxPos].nom).compare(nombreEst)<=0){
			lisCabeceras[0].pos=i;
			estudiantes[i].sigNom=auxPos;
			//SI EL VALOR ACTUAL VA ANTES AL REGISTRADO SI HAY UNA B Y SE METE UNA A ENTRA
			//ESTA PARTE ES LA QUE FALLA
		}else{
			std::cout << "ENTRO" << '\n';

			while((estudiantes[auxPos].nom).compare(nombreEst)>0){
				auxtemp = auxPos;
				auxPos = estudiantes[auxPos].sigNom;
			}
			estudiantes[i].sigNom = auxPos;
			estudiantes[auxtemp].sigNom=i;

		}


		string carrera;
		int auxCarr;
		cout<<"Carrera: "; cin>>carrera;
		estudiantes[i].carrera = carrera;
		if(carrera=="Sistemas"){
			auxCarr = lisCabeceras[1].pos;
			if(auxCarr==-1)
			lisCabeceras[1].pos=i;
			else{
				auxCarr =lisCabeceras[1].pos;
				estudiantes[i].sigCarr=auxCarr;
				lisCabeceras[1].pos=i;

			}
		}
		else if (carrera == "Industrial"){
			auxCarr = lisCabeceras[2].pos;
			if(auxCarr==-1)
			lisCabeceras[2].pos=i;
			else{
				auxCarr =lisCabeceras[2].pos;
				estudiantes[i].sigCarr=auxCarr;
				lisCabeceras[2].pos=i;

			}
		}
		else if(carrera=="Electrica"){
			auxCarr = lisCabeceras[3].pos;
			if(auxCarr==-1)
			lisCabeceras[3].pos=i;
			else{
				auxCarr =lisCabeceras[3].pos;
				estudiantes[i].sigCarr=auxCarr;
				lisCabeceras[3].pos=i;

			}
		}
		else if(carrera=="Catastral"){
			auxCarr = lisCabeceras[4].pos;
			if(auxCarr==-1)
			lisCabeceras[4].pos=i;
			else{
				auxCarr =lisCabeceras[4].pos;
				estudiantes[i].sigCarr=auxCarr;
				lisCabeceras[4].pos=i;

			}
		}

		//NO QUEDA MUY CLARO COMO SE DEBE DE ORDENAR HOBBY ASI QUE SE ORDENA POR ORDEN DE LLEGADA COMO EN CLASE
		string hobby;
		int auxHobby;
		cout<<"Hobby: "; cin>>hobby;
		estudiantes[i].hobby = hobby;

		if(hobby=="Danza"){
			auxHobby = lisCabeceras[5].pos;
			if(auxHobby == -1){
				lisCabeceras[5].pos = i;
			}else{
				estudiantes[i].sigHob=auxHobby;
				lisCabeceras[5].pos = i;
			}
		}else if(hobby=="Natacion"){
			auxHobby = lisCabeceras[6].pos;
			if(auxHobby == -1){
				lisCabeceras[6].pos = i;
			}else{
				estudiantes[i].sigHob=auxHobby;
				lisCabeceras[6].pos = i;
			}
		}else if(hobby=="Beisbol"){
			auxHobby = lisCabeceras[7].pos;
			if(auxHobby == -1){
				lisCabeceras[7].pos = i;
			}else{
				estudiantes[i].sigHob=auxHobby;
				lisCabeceras[7].pos = i;
			}
		}else if(hobby=="Basquet"){
			auxHobby = lisCabeceras[8].pos;
			if(auxHobby == -1){
				lisCabeceras[8].pos = i;
			}else{
				estudiantes[i].sigHob=auxHobby;
				lisCabeceras[8].pos = i;
			}
		}

		int edad;
		int auxEdad, auxEdad2;
		cout<<"Edad: "; cin>>edad;
		estudiantes[i].edad = edad;

		auxEdad = lisCabeceras[9].pos;
		// Si no hay nada definido en la cabecera
		if(auxEdad==-1){
			lisCabeceras[9].pos=i;
		}else if(estudiantes[auxEdad].edad<edad){
			// Si la edad ingresada es la mas alta entonces es la nueva cabeza
			lisCabeceras[9].pos=i;
			estudiantes[i].sigEdad = auxEdad;
		}else{
			while((estudiantes[auxEdad].edad >edad) && (estudiantes[auxEdad].sigEdad=!-1)){
				auxEdad2=auxEdad;
				auxEdad=estudiantes[auxEdad].sigEdad;
			}
			if(estudiantes[auxEdad].sigEdad==-1)
				estudiantes[auxEdad].sigEdad = i;
			else{
				estudiantes[i].sigEdad = auxEdad;
				estudiantes[auxEdad2].sigEdad = i;
			}
		}
	}

	ordenarPorNombre();
	ordenarPorCarreraSistemas();
	ordenarPorCarreraIndustrial();
	ordenarPorCarreraElectrica();
	ordenarPorCarreraCatastral();
	ordenarPorHobbyDanza();
	ordenarPorHobbyNatacion();
	ordenarPorHobbyBeisbol();
	ordenarPorHobbyBasket();
	ordenarPorEdad();


	//ordenarPorEdad();

	return 0;
}
