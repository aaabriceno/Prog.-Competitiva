#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>

#define ERROR 1e-8

using namespace std;

typedef pair<double, double> ParDoble;

int cantidadCompetidores;
double distanciaTotal;
ParDoble velocidades[20];

inline double obtenerTiempo(ParDoble velocidad, ParDoble recorrido)
{
    return recorrido.first / velocidad.first + recorrido.second / velocidad.second;
}

inline double obtenerMayorDiferencia(double recorridoCarrera)
{
    double menorTiempo = 1e9;
    ParDoble recorridoActual(recorridoCarrera, distanciaTotal - recorridoCarrera);
    double tiempoTramposo = obtenerTiempo(velocidades[cantidadCompetidores - 1], recorridoActual);

    for (int i = 0; i < cantidadCompetidores - 1; ++i)
        menorTiempo = min(menorTiempo, obtenerTiempo(velocidades[i], recorridoActual));

    return (tiempoTramposo - menorTiempo) * 3600.0;
}

int main()
{
    while (cin >> distanciaTotal)
    {
        cin >> cantidadCompetidores;
        for (int i = 0; i < cantidadCompetidores; ++i)
            cin >> velocidades[i].first >> velocidades[i].second;

        double izquierda = 0;
        double derecha = distanciaTotal;

        while (fabs(derecha - izquierda) > ERROR)
        {
            double medio1 = (2 * derecha + izquierda) / 3.0;
            double medio2 = (2 * izquierda + derecha) / 3.0;

            if (obtenerMayorDiferencia(medio2) < obtenerMayorDiferencia(medio1))
                derecha = medio1;
            else
                izquierda = medio2;
        }

        if (obtenerMayorDiferencia(izquierda) > 0)
        {
            cout << "The cheater cannot win.\n";
        }
        else
        {
            cout << "The cheater can win by " << (int)round(-obtenerMayorDiferencia(izquierda)) << " seconds with r = ";
            cout << fixed << setprecision(2) << izquierda << "km and k = " << distanciaTotal - izquierda << "km.\n";
        }
    }

    return 0;
}
