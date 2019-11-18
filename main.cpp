#include <bits/stdc++.h>

using namespace std;

stack <int> pila; //Posicion 0 del vector
queue <int> cola; //Posicion 1 del vector
priority_queue <int> colaPrioridad; //Posicion 2 del vector
vector <int> conteo(4); //Posicion 3 cuando es imposible

void agregarElemento(int numero) {
    pila.push(numero);
    cola.push(numero);
    colaPrioridad.push(numero);
}

void quitarElemento(int numero) {
    if (pila.size() == 0 || cola.size() == 0 || colaPrioridad.size() == 0) {
        conteo[3]++;
        return;
    }
    if (numero != pila.top() && numero != cola.front() && numero != colaPrioridad.top()) {
        conteo[3]++;
        return;
    }
    if (numero == pila.top()) {
        conteo[0]++;
        if (pila.size() > 0) {
            pila.pop();
        } else {
            conteo[3]++;
        }
    }
    if (numero == cola.front()) {
        conteo[1]++;
        if (cola.size() > 0) {
            cola.pop();
        } else {
            conteo[3]++;
        }
    }
    if (numero == colaPrioridad.top()) {
        conteo[2]++;
        if (colaPrioridad.size() > 0) {
            colaPrioridad.pop();
        } else {
            conteo[3]++;
        }
    }
}

int main() {
    
    int numeroEntradas;
    while (scanf("%d", &numeroEntradas) == 1) {
        pila = stack <int>();
        cola = queue <int>();
        colaPrioridad = priority_queue <int>();
        conteo = vector <int>(4);
        vector <bool> resultado(3);
        int casosExitosos = 0;
        for (int i = 0; i < numeroEntradas; ++i) {
            int comando, numero;
            cin >> comando >> numero;
            if (comando == 1) {
                agregarElemento(numero);
            } else {
                quitarElemento(numero);
                casosExitosos++;
            }
        }
        if (conteo[3] > 0) {
            cout << "impossible" << endl;
            continue;
        }
        resultado[0] = conteo[0] == casosExitosos;
        resultado[1] = conteo[1] == casosExitosos;
        resultado[2] = conteo[2] == casosExitosos;
        int resultadosPosibles = 0;
        if (resultado[0]) resultadosPosibles++;
        if (resultado[1]) resultadosPosibles++;
        if (resultado[2]) resultadosPosibles++;
        if (resultadosPosibles > 1) {
            cout << "not sure" << endl;
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            if (resultado[i]) {
                switch(i) {
                    case 0: {
                        cout << "stack" << endl;
                        break;
                    }
                    case 1: {
                        cout << "queue" << endl;
                        break;
                    }
                    case 2: {
                        cout << "priority queue" << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}