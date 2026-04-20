#include <iostream>
#include <string>

using namespace std;

int main() {
    const string USUARIO_CORRECTO = "admin";
    const string PASSWORD_CORRECTA = "Segura123!";

    int intentos = 0;
    bool accesoConcedido = false;

    // Permite hasta 3 intentos o hasta que el acceso sea exitoso.
    while (intentos < 3 && !accesoConcedido) {
        string usuarioIngresado;
        string passwordIngresada;

        cout << "--- Intento " << (intentos + 1) << " de 3 ---" << endl;
        cout << "Usuario: ";
        cin >> usuarioIngresado;
        cout << "Contrasena: ";
        cin >> passwordIngresada;

        if (usuarioIngresado == USUARIO_CORRECTO && passwordIngresada == PASSWORD_CORRECTA) {
            accesoConcedido = true;
            cout << "Acceso concedido" << endl;
        } else {
            cout << "Credenciales incorrectas." << endl;
            intentos++;
        }

        cout << endl;
    }

    if (!accesoConcedido) {
        cout << "CUENTA BLOQUEADA" << endl;
    }

    return 0;
}
