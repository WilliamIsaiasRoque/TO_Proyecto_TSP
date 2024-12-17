#include "tspsolver.h"
#include <algorithm>



// Constructor: Inicializa la matriz de distancias
TSPSolver::TSPSolver(QObject *parent) : QObject(parent) {
    int temp[N][N] = {
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
    };

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            distancias[i][j] = temp[i][j];
}

// Resolver TSP usando fuerza bruta
std::vector<int> TSPSolver::resolverTSPFuerzaBruta(int inicio) {
    std::vector<int> nodos;
    for (int i = 0; i < N; i++) {
        if (i != inicio) {
            nodos.push_back(i);
        }
    }

    std::vector<int> mejorRuta;
    int menorDist = INF;

    do {
        // Crear una ruta actual: inicio -> nodos -> inicio
        std::vector<int> ruta = {inicio};
        ruta.insert(ruta.end(), nodos.begin(), nodos.end());
        ruta.push_back(inicio);

        int distActual = getTotalDistancia(ruta);

        if (distActual < menorDist) {
            menorDist = distActual;
            mejorRuta = ruta;
        }
    } while (std::next_permutation(nodos.begin(), nodos.end()));

    emit grafoResuelto(mejorRuta, menorDist);
    return mejorRuta;
}

// Calcular la distancia total de una ruta
int TSPSolver::getTotalDistancia(const std::vector<int>& ruta) {
    int totalDist = 0;
    for (size_t i = 0; i < ruta.size() - 1; ++i) {
        int from = ruta[i];
        int to = ruta[i + 1];
        if (distancias[from][to] == INF) return INF;
        totalDist += distancias[from][to];
    }
    return totalDist;
}

// Getter para acceder a la matriz de distancias
int TSPSolver::getDistancia(int i, int j) const {
    if (i >= 0 && i < N && j >= 0 && j < N) {
        return distancias[i][j];
    }
    return INF; // Si la posición está fuera de rango
}

