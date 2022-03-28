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
        int pos = this -> fncHash(puerta);
        this -> array[pos] ++;
    }
    void eliminarDeHash(char puerta){
        int pos = this -> fncHash(puerta);
        this -> array[pos] --;
    }
    bool existeEnHash(char puerta){
        int pos = this -> fncHash(puerta);
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
    int fncHash(string nombre){
        int i;
        for (i = 0 ; i < this->tope && nombre.compare(this -> array[i].nombreJugador) != 0; i++);
        if (i < this -> tope){
            return i;
        }else{
            return this -> tope;
        };
    }; 
  public:
    TablaHash(int cantRondas){
        this -> array = new nodoArray[cantRondas] {}; 
        this -> tope = 0;
    };
    void insertarEnHash(string nombre, int puntajeRonda, int nRonda){
        int pos = this -> fncHash(nombre);
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

struct nodoAB {
    int dato;
    int repetidos;
    nodoAB * der;
    nodoAB * izq;  
};

struct nodoLista {
    int dato;
    nodoLista * sig;
};

//ABB con repetidos
class ABB {
    public:
        nodoAB * raiz;
        ABB(){
            this -> raiz = NULL;
        };
        void insertar(int dato, nodoAB * &cursor){
            if (cursor == NULL){
              cursor = new nodoAB;
              cursor -> dato = dato;
              cursor -> repetidos = 0;
              cursor -> der = cursor -> izq = NULL;  
            }else{
                if (dato < cursor -> dato){
                    insertar (dato, cursor -> izq);
                }else if (dato > cursor -> dato){
                    insertar (dato, cursor -> der);
                }else{
                    cursor -> repetidos ++;
                }
            };
        };
        void a_Cadena(nodoLista * &cadena, nodoAB * cursor){
            if (cursor != NULL){
                a_Cadena(cadena, cursor -> izq);
                //insercion al principio
                for (int i = 0; i <= cursor -> repetidos; i++){
                    nodoLista* nuevo = new nodoLista;
                    nuevo -> dato = cursor -> dato;
                    nuevo -> sig = cadena;
                    cadena = nuevo;
                }
                a_Cadena(cadena, cursor -> der);
            }
        };
};

int main(){
    ABB * abb = new ABB();
    int k;
    cin >> k;
    int cantElem;
    cin >> cantElem;
    for (int i = 0; i < cantElem; i ++){
        int dato;
        cin >> dato; 
        abb -> insertar(dato, abb -> raiz);       
    };
    nodoLista * cadena = NULL;
    abb -> a_Cadena(cadena, abb -> raiz);
    int contador = 0;
    while (contador < k){
        cout << cadena->dato << endl;
        cadena = cadena -> sig;
        contador ++;
    };
    return 1;
}
~~~