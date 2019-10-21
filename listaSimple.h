using namespace std;

template <class T>
struct nodo {
	nodo<T> *sig;
	T info;
};

template <class T>
class lista{
	
	nodo<T> *cab;
	int tam;
	
	public:
		lista(){
			tam = 0;
		}
		bool listaVacia();
		int tamanoLista();
		void insertar(T infoNueva, int pos);
		void eliminar(int pos);
		~lista();
};

template <class T>
bool lista <T>::listaVacia(){
	if (tam==0)
		return true;
	else
		return false;
}

template <class T>
int lista<T>::tamanoLista(){return tam;}

template <class T>
void lista<T>::insertar(T infoNueva, int pos){
	nodo<T> *nuevo = new nodo <T>, *aux;
}
