#include "rutas.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <QString>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace chrono;

// Implementación de la clase Ruta
Ruta::Ruta(string nombre, const vector<vector<int>>& distancias)
    : nombre(nombre), distancias(distancias) {}

// Función para calcular la distancia total de una ruta
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

// Fuerza Bruta
vector<int> resolverTSPFuerzaBruta(int inicio, const vector<vector<int>>& distancias) {
    int N = distancias.size();
    vector<int> nodos;
    for (int i = 0; i < N; i++) {
        if (i != inicio) nodos.push_back(i);
    }

    vector<int> mejorRuta;
    int menorDist = INF;

    do {
        vector<int> ruta = {inicio};
        ruta.insert(ruta.end(), nodos.begin(), nodos.end());
        ruta.push_back(inicio);

        int distActual = calcDistTotal(ruta, distancias);
        if (distActual < menorDist) {
            menorDist = distActual;
            mejorRuta = ruta;
        }
    } while (next_permutation(nodos.begin(), nodos.end()));

    return mejorRuta;
}

// Vecino Más Cercano
vector<int> resolverTSPVecinoMasCercano(const vector<vector<int>>& distancias) {
    int N = distancias.size();
    int inicio = 0;
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
            break;
        }
    }

    ruta.push_back(inicio);
    return ruta;
}

// Resolver y mostrar resultados
QString resolverYmostrar(const Ruta& ruta) {
    using namespace std::chrono;
    std::ostringstream output;

    // Medición del tiempo en microsegundos
    auto startVMC = high_resolution_clock::now();
    vector<int> mejorRutaVMC = resolverTSPVecinoMasCercano(ruta.distancias);
    auto endVMC = high_resolution_clock::now();
    auto duracionVMC = duration_cast<microseconds>(endVMC - startVMC).count();

    // Cálculo de la distancia total
    int distTotalVMC = calcDistTotal(mejorRutaVMC, ruta.distancias);

    // Construcción del texto
    output << "Ruta óptima (" << ruta.nombre << " - Vecino Más Cercano):\n";
    for (size_t i = 0; i < mejorRutaVMC.size() - 1; i++) {
        output << "(" << mejorRutaVMC[i] + 1 << ") - "
               << ruta.distancias[mejorRutaVMC[i]][mejorRutaVMC[i + 1]]
               << " -> ";
    }
    output << "(" << mejorRutaVMC.back() + 1 << ")\n";
    output << "Distancia total: " << distTotalVMC << " m\n";
    output << "Tiempo de ejecución: " << duracionVMC << " microsegundos\n";

    // Convertimos el resultado a QString
    return QString::fromStdString(output.str());
}
