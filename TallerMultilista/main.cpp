#include <iostream>

using namespace std;

struct cabecera{
	string caracteristica;
	int pos;
};
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

void ordenarPorEdad(){
	int auxEdad = lisCabeceras[9].pos;
	cout<<"\n Ordenado por edad: "<<endl;
	while(auxEdad =! -1){
		cout<<estudiantes[auxEdad].edad<<endl;
		auxEdad = estudiantes[auxEdad].sigEdad;
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

int main(){
	string a = "a";
	string b = "b";

	std::cout << (a.compare(b)) << '\n';



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
				while(estudiantes[auxCarr].sigCarr=!-1){
					auxCarr = estudiantes[auxCarr].sigCarr;
				}
				estudiantes[auxCarr].sigCarr = i;
			}
		}
		else if(carrera=="Electrica"){
			auxCarr = lisCabeceras[3].pos;
			if(auxCarr==-1)
			lisCabeceras[3].pos=i;
			else{
				while(estudiantes[auxCarr].sigCarr=!-1){
					auxCarr = estudiantes[auxCarr].sigCarr;
				}
				estudiantes[auxCarr].sigCarr = i;
			}
		}
		else if(carrera=="Catastral"){
			auxCarr = lisCabeceras[4].pos;
			if(auxCarr==-1)
			lisCabeceras[4].pos=i;
			else{
				while(estudiantes[auxCarr].sigCarr=!-1){
					auxCarr = estudiantes[auxCarr].sigCarr;
				}
				estudiantes[auxCarr].sigCarr = i;
			}
		}

/*
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
		int auxEdad;
		cout<<"Edad: "; cin>>edad;
		estudiantes[i].edad = edad;

		auxEdad = lisCabeceras[9].pos;
		if(auxEdad==-1){
			lisCabeceras[9].pos=i;
		}else{
			while((estudiantes[auxEdad].edad >edad) && (estudiantes[auxEdad].sigEdad=!-1)){
				auxEdad=estudiantes[auxEdad].sigEdad;
			}
			if(estudiantes[auxEdad].sigEdad==-1)
			estudiantes[auxEdad].sigEdad = i;
			else{
				estudiantes[i].sigEdad = estudiantes[auxEdad].sigEdad;
				estudiantes[auxEdad].sigEdad = i;
			}
		}
*/
	//	cout<<estudiantes[i].edad<<endl;
		//cout<<estudiantes[i].carrera<<endl;
	}

	ordenarPorNombre();
	ordenarPorCarreraSistemas();
	//ordenarPorEdad();

	return 0;
}
