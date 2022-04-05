# obligatorio-algoritmos-2
Repositorio para el obligatorio de Algoritmos 2

### Ejercicio1

~~~
#include <iostream>
#include <string>
using namespace std;
class TablaHash{
 private:
    int * array;
    int fncHash(char puerta){
        return int(puerta) - 65;
    } 
 public:
    TablaHash(){
        this -> array = new int[26] {}; 
    }
    void insertarEnHash(char puerta){
        int pos = this -> fncHash(puerta) % 26;
        this -> array[pos] ++;
    }
    void eliminarDeHash(char puerta){
        int pos = this -> fncHash(puerta) % 26;
        this -> array[pos] --;
    }
    bool existeEnHash(char puerta){
        int pos = this -> fncHash(puerta) % 26;
        return this -> array[pos] >= 1;
    }
};

int main(){
    int llavesMin = 0;
    int nHabitaciones;
    string input;
    cin >> nHabitaciones;
    cin >> input;
    TablaHash * tabla = new TablaHash();
    for (int i = 0 ; i < 2 * (nHabitaciones - 1) ; i += 2){
        char llave = input[i];
        tabla -> insertarEnHash(toupper(llave));    
        char puerta = input[i+1];
        if (tabla -> existeEnHash(puerta)){
            tabla -> eliminarDeHash(puerta);
        }else{
            llavesMin ++;
        }
    }
    cout << llavesMin << endl;
    return 1;
};
~~~

### Ejercicio2

~~~
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct nodoLista {
    int puntaje;
    int numRonda;
    nodoLista * sig;
};

struct nodoArray {
    string nombreJugador;
    nodoLista * puntajesRonda;
};

class TablaHash{
  private:
    nodoArray * array;
    int tope;
    int capacidad;
    int fncHash(string nombre){
        int i;
        for (i = 0 ; i < this -> tope && nombre.compare(this -> array[i].nombreJugador) != 0; i++);
        if (i < this -> tope){
            return i;
        }else{
            return this -> tope;
        };
    }; 
    int posHash(string nombre){
        return fncHash(nombre) % this -> capacidad;
    }
  public:
    TablaHash(int cantRondas){
        this -> capacidad = cantRondas;
        this -> array = new nodoArray[this -> capacidad] {}; 
        this -> tope = 0;
    };
    void insertarEnHash(string nombre, int puntajeRonda, int nRonda){
        int pos = this -> posHash(nombre);
        if (pos == this -> tope){
            this -> tope ++;
        }
        if (this -> array[pos].nombreJugador.compare("") == 0 && this -> array[pos].puntajesRonda == 0){
            this -> array[pos].nombreJugador = nombre;
            this -> array[pos].puntajesRonda = new nodoLista;
            this -> array[pos].puntajesRonda -> numRonda = nRonda;
            this -> array[pos].puntajesRonda -> puntaje = puntajeRonda;
            this -> array[pos].puntajesRonda -> sig = NULL;
        }else{
            nodoLista * nuevo = new nodoLista;
            nuevo -> numRonda = nRonda;
            nuevo -> puntaje = puntajeRonda;
            nuevo -> sig = this -> array[pos].puntajesRonda;
            this -> array[pos].puntajesRonda = nuevo;
        }
    };
    nodoArray buscarNodo(int pos){
        return this -> array[pos]; 
    }
    int obtenerTope(){
        return this -> tope;
    };
};

int main(){
    int cantRondas;
    cin >> cantRondas;
    string input;
    TablaHash * myHash = new TablaHash (cantRondas);
    cin.ignore();
    for (int i = 0 ; i < cantRondas ; i++){
        getline(cin, input);
        int posEmpty = input.find(' ');
        string nombre = input.substr(0, posEmpty);
        int puntajeRonda = stoi(input.substr(posEmpty+1));
        myHash -> insertarEnHash(nombre, puntajeRonda, i); 
    }
    int puntajeMax = 0;
    int posGanador = 0;
    string nombreGanador = "";
    for (int i = 0 ; i < myHash -> obtenerTope(); i++){
        nodoLista * cursor = myHash -> buscarNodo(i).puntajesRonda;
        string nombre = myHash -> buscarNodo(i).nombreJugador;
        int puntajeTotal = 0;
        while (cursor != NULL){
            puntajeTotal += cursor -> puntaje;
            cursor = cursor -> sig;
        }
        if (puntajeTotal > puntajeMax){
            puntajeMax = puntajeTotal;
            posGanador = i;
            nombreGanador = nombre;
        }else if (puntajeTotal == puntajeMax){
            if (myHash -> buscarNodo(i).puntajesRonda -> numRonda < 
                    myHash -> buscarNodo(posGanador).puntajesRonda -> numRonda){
                        nombreGanador = nombre;
            }
        }
    }
    cout << nombreGanador << endl;
    return 1;
};
~~~

### Ejercicio3

~~~
#include <iostream>
#include <string>
using namespace std;

class maxHeap {
    private:
        int tope;
        int capacidad;
        int * vector;
    public:
        maxHeap(int capacidad_maxima){
            this -> tope = 0;
            this -> capacidad = capacidad_maxima;
            this -> vector = new int[this -> capacidad + 1] {};
        }
        void flotar(int * vec, int pos){
            if (pos > 1 && vec[pos/2] < vec[pos]){
                int swap = vec[pos/2];
                vec[pos/2] = vec[pos];
                vec[pos] = swap;
                flotar(vec, pos/2);
            }
        }
        void insertar(int dato){
            this -> tope ++;
            this -> vector[this -> tope] = dato;
            this -> flotar(this -> vector, this -> tope);
        }
        void hundir(int * vec, int pos){
            int swap = vec[pos];
            while (2 * pos <= this -> tope){
                int hijo = 2 * pos;
                if (hijo + 1 <= this -> tope && vec[hijo] < vec[hijo + 1]){
                    hijo ++;
                }
                if (swap < vec[hijo]){
                    vec[pos] = vec[hijo];
                    pos = hijo;
                }else{
                    break;
                }
            }
            vec[pos] = swap;
        }
        //elimina y devuelve el maximo actual 
        int extraerMax(){
            int max = this -> vector[1];
            this -> tope --;
            this -> vector[1] = this -> vector[this -> tope];
            hundir(this -> vector, 1);
            return max;
        }
};

int main(){
    int k;
    cin >> k;
    int cantElem;
    cin >> cantElem;
    maxHeap * heap = new maxHeap(cantElem);
    for (int i = 0; i < cantElem; i ++){
        int dato;
        cin >> dato;
        heap -> insertar(dato); 
    };
    for (int i = 0; i < k; i++){
        cout << heap -> extraerMax() << endl;
    }
    return 1;
}
~~~