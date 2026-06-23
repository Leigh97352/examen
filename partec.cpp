
#include <iostream>
using namespace std;

class RegistroTemperaturas {
private:
    double* lecturas;
    int capacidad;
    int cantidad;

public:
    RegistroTemperaturas(int cap) : capacidad(cap), cantidad(0) {
    lecturas = new double[capacidad];
    }

    ~RegistroTemperaturas() {
        delete[] lecturas;
        lecturas = nullptr;
    }
    void agregar(double temp) {
        if (temp < -50.0 || temp > 60.0) {
        std::cout << "Temperatura invalida" << endl;
        return;
        }
        if (cantidad >= capacidad) {
            std::cout << "Regristro lleno" << endl;
           return;
        }
        lecturas[cantidad++] = temp;
    }

    double promedio() const {
        if (cantidad == 0) return 0.0;
        double suma = 0.0;
        for (int i = 0; i < cantidad; i++)
            suma += lecturas[i];
        return suma / cantidad;
    }

    double maxima() const {
        double max = lecturas[0];
        for (int i = 1; i < cantidad; i++)
            if (lecturas[i] > max) max = lecturas[i];
        return max;
    }

    double minima() const {
        double min = lecturas[0];
        for (int i = 1; i < cantidad; i++)
            if (lecturas[i] < min) min = lecturas[i];
        return min;
    }

    void imprimir() const {
       std:: cout << "temperaturas: ";
        for (int i = 0; i < cantidad; i++) {
            if (i > 0) cout << " ";
           std:: cout << lecturas[i];
        }
        cout << endl;
    }

    int getCantidad() const { return cantidad; }
};

void resumen(const RegistroTemperaturas& reg) {
    reg.imprimir();
   std:: cout << "romedio : " << reg.promedio() << endl;
   std:: cout << "MMaxima   : " << reg.maxima()   << endl;
    std::cout << "Minima   : " << reg.minima()   << endl;
}

int main() {
    int n;
    cin >> n;

    RegistroTemperaturas reg(n);

    double temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        reg.agregar(temp);
    }

    resumen(reg);
    return 0;
}
