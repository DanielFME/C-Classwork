#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;

    // Solicita la contraseña al usuario.
    cout << "Ingrese una contraseña: ";
    cin >> password;

    // Evalúa cada regla de seguridad solicitada en el ejercicio.
    bool longitudMinima = password.length() >= 8;
    bool tieneMayuscula = false;
    bool tieneNumero = false;
    bool tieneEspecial = false;

    for (char c : password) {
        if (c >= 'A' && c <= 'Z') {
            tieneMayuscula = true;
        }
        if (c >= '0' && c <= '9') {
            tieneNumero = true;
        }
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*') {
            tieneEspecial = true;
        }
    }

    // Suma cuántas reglas se cumplen para clasificar el nivel.
    int reglasCumplidas = longitudMinima + tieneMayuscula + tieneNumero + tieneEspecial;

    if (reglasCumplidas <= 2) {
        cout << "Nivel: DEBIL" << endl;
    } else if (reglasCumplidas == 3) {
        cout << "Nivel: MEDIA" << endl;
    } else {
        cout << "Nivel: FUERTE" << endl;
    }

    return 0;
}
