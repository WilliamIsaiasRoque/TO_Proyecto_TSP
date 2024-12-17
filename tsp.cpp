#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono> // Para medir el tiempo de ejecución

using namespace std;
using namespace chrono;

const int INF = numeric_limits<int>::max();

class Ruta {
public:
    string nombre;
    vector<vector<int>> distancias;

    Ruta(string nombre, const vector<vector<int>>& distancias)
        : nombre(nombre), distancias(distancias) {}
};

int calcDistTotal(const vector<int>& ruta, const vector<vector<int>>& distancias) {
    int totalDist = 0;
    for (size_t i = 0; i < ruta.size() - 1; i++) {
        int from = ruta[i];
        int to = ruta[i + 1];
        if (distancias[from][to] == INF) {
            return INF;
        }
        totalDist += distancias[from][to];
    }
    return totalDist;
}

// Función para resolver el TSP utilizando fuerza bruta (ESTO ARREGLALO CARAJO)
vector<int> resolverTSPFuerzaBruta(int inicio, const vector<vector<int>>& distancias) {
    int N = distancias.size();  // Número de nodos
    vector<int> nodos;          // Nodos por visitar

    // Se inicializa la lista de nodos excluyendo el nodo de inicio
    for (int i = 0; i < N; i++) {
        if (i != inicio) {
            nodos.push_back(i);
        }
    }

    vector<int> mejorRuta;  // Guarda la mejor ruta
    int menorDist = INF;    // Inicia con una distancia muy alta

    // Probar todas las permutaciones de los nodos
    do {
        vector<int> ruta = {inicio};
        ruta.insert(ruta.end(), nodos.begin(), nodos.end());
        ruta.push_back(inicio);  // Regresar al nodo inicial

        // Calcular la distancia total de la ruta actual
        int distActual = calcDistTotal(ruta, distancias);

        // Actualizar si encontramos una mejor distancia
        if (distActual < menorDist) {
            menorDist = distActual;
            mejorRuta = ruta;
        }
    } while (next_permutation(nodos.begin(), nodos.end()));

    return mejorRuta;
}

vector<int> resolverTSPVecinoMasCercano(const vector<vector<int>>& distancias) {
    int N = distancias.size();
    int inicio = 0; // Nodo inicial siempre es 0
    vector<int> ruta;
    vector<bool> visitado(N, false);
    int nodoActual = inicio;
    visitado[nodoActual] = true;
    ruta.push_back(nodoActual);

    while (ruta.size() < N) {
        int nodoCercano = -1;
        int minDist = INF;

        for (int j = 0; j < N; ++j) {
            if (!visitado[j] && distancias[nodoActual][j] < minDist && distancias[nodoActual][j] != INF) {
                minDist = distancias[nodoActual][j];
                nodoCercano = j;
            }
        }

        if (nodoCercano != -1) {
            visitado[nodoCercano] = true;
            ruta.push_back(nodoCercano);
            nodoActual = nodoCercano;
        } else {
            break; // No hay más nodos alcanzables
        }
    }

    ruta.push_back(inicio); // Regresar al nodo inicial
    return ruta;
}

void resolverYMostrar(const Ruta& ruta) {
    auto startVMC = high_resolution_clock::now();
    vector<int> mejorRutaVMC = resolverTSPVecinoMasCercano(ruta.distancias);
    auto endVMC = high_resolution_clock::now();
    auto duracionVMC = duration_cast<milliseconds>(endVMC - startVMC).count();
    int distTotalVMC = calcDistTotal(mejorRutaVMC, ruta.distancias);

    cout << "Ruta óptima (" << ruta.nombre << " - Vecino Más Cercano):" << endl;
    for (size_t i = 0; i < mejorRutaVMC.size() - 1; i++) {
        cout << "(" << mejorRutaVMC[i] + 1 << ") - " << ruta.distancias[mejorRutaVMC[i]][mejorRutaVMC[i + 1]] 
             << " -> ";
    }
    cout << "(" << mejorRutaVMC.back() + 1 << ")" << endl;
    cout << "Distancia total: " << distTotalVMC << endl;
    cout << "Tiempo de ejecución: " << duracionVMC << " ms" << endl << endl;
}

int main() {
    Ruta rutaACamion1("Ruta A - Camion 1", {
        {0, 80, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 42},
        {80, 0, 276, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, 276, 0, 314, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 314, 0, 76, INF, 503, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 76, 0, 522, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 522, 0, 86, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 503, INF, 86, 0, 555, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 555, 0, 107, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 107, 0, 152, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, 152, 0, 415, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 415, 0, 87, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 87, 0, 143},
        {42, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 143, 0}
    });

    Ruta rutaACamion2("Ruta A - Camion 2", {
        {0, 317, INF, INF, INF, INF, 244},   
        {317, 0, 272, INF, INF, INF, INF},   
        {INF, 272, 0, 853, INF, INF, INF},   
        {INF, INF, 853, 0, 377, INF, INF},   
        {INF, INF, INF, 377, 0, 286, INF},   
        {INF, INF, INF, INF, 286, 0, 442},   
        {244, INF, INF, INF, INF, 442, 0}    
    });

    Ruta rutaBCamion1("Ruta B - Camion 1", {
        {0, 542, 540, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 1
        {542, 0, 540, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 600}, // Nodo 2
        {540, 540, 0, 143, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
        {INF, INF, 143, 0, 182, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 4
        {INF, INF, INF, 182, 0, 140, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 5
        {INF, INF, INF, INF, 140, 0, 275, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 6
        {INF, INF, INF, INF, INF, 275, 0, 66, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 7
        {INF, INF, INF, INF, INF, INF, 66, 0, 341, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 8
        {INF, INF, INF, INF, INF, INF, INF, 341, 0, 80, INF, INF, INF, INF, INF, INF, INF},  // Nodo 9
        {INF, INF, INF, INF, INF, INF, INF, INF, 80, 0, 239, INF, INF, INF, INF, INF, INF},  // Nodo 10
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 239, 0, 300, INF, INF, INF, INF, INF}, // Nodo 11
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 300, 0, 316, INF, INF, INF, INF}, // Nodo 12
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 316, 0, 324, INF, INF, INF}, // Nodo 13
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 324, 0, 112, INF, 370}, // Nodo 14
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 112, 0, 342, INF}, // Nodo 15
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 342, 0, 204}, // Nodo 16
        {INF, 600, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 370, INF, 204, 0}  // Nodo 17
    });

    Ruta rutaCCamion1("Ruta C - Camion 1", {
        {0, 39,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 0
        {39, 0,  450, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 1
        {INF, 450, 0,  143, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 2
        {INF, INF, 143, 0,  1142, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
        {INF, INF, INF, 1142, 0, 401, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 449, INF, INF}, // Nodo 4
        {INF, INF, INF, INF, 401, 0, 394, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 5
        {INF, INF, INF, INF, INF, 394, 0, 182, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 6
        {INF, INF, INF, INF, INF, INF, 182, 0, 128, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 7
        {INF, INF, INF, INF, INF, INF, INF, 128, 0, 85, INF, INF, INF, INF, INF, INF, INF, INF, INF},   // Nodo 8
        {INF, INF, INF, INF, INF, INF, INF, INF, 85, 0, 209, INF, INF, INF, INF, INF, INF, INF, INF},   // Nodo 9
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 209, 0, 111, INF, INF, INF, INF, INF, INF, INF},  // Nodo 10
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 111, 0, 289, INF, INF, INF, INF, INF, INF},  // Nodo 11
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 289, 0, 216, INF, INF, INF, INF, INF},  // Nodo 12
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 216, 0, 122, INF, INF, INF, INF},  // Nodo 13
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 122, 0, 250, INF, INF, INF},  // Nodo 14
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 250, 0, 356, INF, INF},  // Nodo 15
        {INF, INF, INF, INF, 449, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 356, 0, 481, INF},  // Nodo 16
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 263, INF, INF, 84, 0, INF},   // Nodo 17
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 481, 0}   // Nodo 18
    });

    Ruta rutaCCamion2("Ruta C - Camion 2", {
        {0, 155, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 1
        {INF, 0, 413, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 2
        {INF, INF, 0, 1635, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
        {INF, INF, 1635, 0, 979, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 134}, // Nodo 4
        {INF, INF, INF, INF, 0, 341, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 5
        {INF, INF, INF, INF, INF, 0, 395, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 6
        {INF, INF, INF, INF, INF, INF, 0, 170, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 7
        {INF, INF, INF, INF, INF, INF, INF, 0, 308, INF, INF, 202, INF, INF, INF, INF, INF},  // Nodo 8
        {INF, INF, INF, INF, INF, INF, INF, INF, 0, 516, INF, INF, INF, INF, INF, INF, INF},  // Nodo 9
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 284, INF, INF, INF, INF, INF, INF},  // Nodo 10
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 153, INF, INF, INF, INF, INF},  // Nodo 11
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 294, INF, INF, INF, INF},  // Nodo 12
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 304, INF, INF, INF},  // Nodo 13
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 421, INF, INF},  // Nodo 14
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 446, INF},  // Nodo 15
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 250},  // Nodo 16
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}   // Nodo 17
    });

    resolverYMostrar(rutaACamion1);
    resolverYMostrar(rutaACamion2);
    resolverYMostrar(rutaBCamion1);
    resolverYMostrar(rutaCCamion1);
    resolverYMostrar(rutaCCamion2);

    return 0;
}
