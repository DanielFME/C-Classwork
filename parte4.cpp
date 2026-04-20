#include <iostream>
#include <string>

using namespace std;

int main() {
    const int TOTAL_INTENTOS = 5;
    const string USUARIO_CORRECTO = "admin";
    const string PASSWORD_CORRECTA = "Segura123!";

    string usuarios[TOTAL_INTENTOS];
    bool exitoso[TOTAL_INTENTOS];

    // Registra 5 intentos de login y guarda usuario/resultado.
    for (int i = 0; i < TOTAL_INTENTOS; i++) {
        string passwordIngresada;

        cout << "--- Registro #" << (i + 1) << " ---" << endl;
        cout << "Usuario: ";
        cin >> usuarios[i];
        cout << "Contrasena: ";
        cin >> passwordIngresada;

        exitoso[i] = (usuarios[i] == USUARIO_CORRECTO && passwordIngresada == PASSWORD_CORRECTA);

        if (exitoso[i]) {
            cout << "-> Acceso concedido" << endl;
        } else {
            cout << "-> Acceso denegado" << endl;
        }

        cout << endl;
    }

    int exitosos = 0;
    int fallidos = 0;

    // Recorre el log para construir el reporte final.
    for (int i = 0; i < TOTAL_INTENTOS; i++) {
        if (exitoso[i]) {
            exitosos++;
        } else {
            fallidos++;
        }
    }

    float tasaFallo = (static_cast<float>(fallidos) / TOTAL_INTENTOS) * 100.0f;

    cout << "========== REPORTE DE SEGURIDAD ==========" << endl;
    for (int i = 0; i < TOTAL_INTENTOS; i++) {
        cout << "Usuario: " << usuarios[i] << " | Estado: " << (exitoso[i] ? "OK" : "FALLIDO") << endl;
    }

    cout << endl;
    cout << "Intentos exitosos: " << exitosos << "/" << TOTAL_INTENTOS << endl;
    cout << "Intentos fallidos: " << fallidos << "/" << TOTAL_INTENTOS << endl;
    cout << "Tasa de fallo: " << tasaFallo << "%" << endl;

    if (tasaFallo > 60.0f) {
        cout << "*** ALERTA: Tasa de fallo alta - posible ataque ***" << endl;
    }

    return 0;
}
