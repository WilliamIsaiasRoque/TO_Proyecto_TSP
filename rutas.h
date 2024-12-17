#ifndef RUTAS_H
#define RUTAS_H

#include <vector>
#include <string>
#include <limits>
#include <QString>

using namespace std;

const int INF = numeric_limits<int>::max();

class Ruta {
public:
    string nombre;
    vector<vector<int>> distancias;

    Ruta(string nombre, const vector<vector<int>>& distancias);
};

int calcDistTotal(const vector<int>& ruta, const vector<vector<int>>& distancias);
vector<int> resolverTSPFuerzaBruta(int inicio, const vector<vector<int>>& distancias);
vector<int> resolverTSPVecinoMasCercano(const vector<vector<int>>& distancias);
QString resolverYmostrar(const Ruta& ruta);

#endif
