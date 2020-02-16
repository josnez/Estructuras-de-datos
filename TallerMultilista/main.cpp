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
info *estudiantes;

void ordenarPorNombre(){
	int auxNom = lisCabeceras[0].pos;
	cout<<"\n Ordenado por nombre: "<<endl;
	while(auxNom =! -1){
		cout<<estudiantes[auxNom].nom<<endl;
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
	
int main(){
		
	lisCabeceras[0].caracteristica = "Nombre";
	lisCabeceras[1].caracteristica = "Ing.Sistemas";
	lisCabeceras[2].caracteristica = "Ing.Industrial";
	lisCabeceras[3].caracteristica = "Ing.Electrica";
	lisCabeceras[4].caracteristica = "Ing.Catastral";
	lisCabeceras[5].caracteristica = "Danza";
	lisCabeceras[6].caracteristica = "Natacion";
	lisCabeceras[7].caracteristica = "Beisbol";
	lisCabeceras[8].caracteristica = "Basquet";
	lisCabeceras[9].caracteristica = "Edad";
	
	for(int i=0; i<10; i++){
     	lisCabeceras[i].pos=-1;	
	}
	
	cout<<"Digite cuantos estudiantes va a ingresar: "<<endl;
	int numEst;
	cin>>numEst;
	estudiantes = new info[numEst];
	
	for(int i=0; i<numEst; i++){
		estudiantes[i].sigCarr=-1;
		estudiantes[i].sigEdad=-1;
		estudiantes[i].sigHob=-1;
		estudiantes[i].sigNom=-1;
		
		/*string nombreEst;
		cout<<"Nombre: "; cin>>nombreEst;
		
		estudiantes[i].nom = nombreEst;
		int auxPos = lisCabeceras[0].pos;
		if(auxPos==-1){
			lisCabeceras[0].pos=i;
		}else if(estudiantes[auxPos].nom>nombreEst){		
			lisCabeceras[0].pos=i;
			estudiantes[i].sigNom=auxPos;
		}else{
			while(estudiantes[auxPos].nom<nombreEst){
				auxPos = estudiantes[auxPos].sigNom;
			}
			estudiantes[i].sigNom = estudiantes[auxPos].sigNom;
			estudiantes[auxPos].sigNom = i;
		}*/
		
		string carrera;
		int auxCarr;
		cout<<"Carrera: "; cin>>carrera;
		estudiantes[i].carrera = carrera;
		if(carrera=="Ing.Sistemas"){
			auxCarr = lisCabeceras[1].pos;
			if(auxCarr==-1)
				lisCabeceras[1].pos=i;
			else{
				while(estudiantes[auxCarr].sigCarr=!-1){
					auxCarr = estudiantes[auxCarr].sigCarr;
				}
				estudiantes[auxCarr].sigCarr = i;
			}
		}
		else if (carrera == "Ing.Industrial"){
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
	 	else if(carrera=="Ing.Electrica"){
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
		else if(carrera=="Ing.Catastral"){
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

		cout<<estudiantes[i].edad<<endl;
		cout<<estudiantes[i].carrera<<endl;
	}
	
	ordenarPorNombre();
	ordenarPorEdad();
	
	return 0;
}
