#ifndef TSPSOLVER_H
#define TSPSOLVER_H

#include <QObject>
#include <vector>

class TSPSolver : public QObject
{
    Q_OBJECT

public:
    explicit TSPSolver(QObject *parent = nullptr);
    std::vector<int> resolverTSPFuerzaBruta(int nodoInicial);
    int getTotalDistancia(const std::vector<int>& ruta);

private:
    int calcularDistancia(const std::vector<int>& ruta);
    std::vector<std::vector<int>> grafo; // Matriz de distancias entre nodos
};

#endif // TSPSOLVER_H
