#include <iostream>
#include <string>

using namespace std;

int main() {
    string mensaje;
    int desplazamiento;

    // Solicita mensaje y desplazamiento para aplicar cifrado Cesar.
    cout << "Ingrese el mensaje: ";
    cin >> mensaje;
    cout << "Ingrese el desplazamiento: ";
    cin >> desplazamiento;

    // Ajusta el desplazamiento al rango 0-25 para evitar valores fuera de rango.
    desplazamiento = desplazamiento % 26;

    for (int i = 0; i < static_cast<int>(mensaje.length()); i++) {
        char c = mensaje[i];

        if (c >= 'a' && c <= 'z') {
            mensaje[i] = (c - 'a' + desplazamiento) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            mensaje[i] = (c - 'A' + desplazamiento) % 26 + 'A';
        }
        // Si no es letra, se deja igual.
    }

    cout << "Mensaje cifrado: " << mensaje << endl;

    return 0;
}
