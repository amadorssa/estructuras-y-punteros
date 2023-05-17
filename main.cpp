#include <iostream>
#include "estructuras.h"


using namespace std;

int main() {
    int choice = 0;
    Participante* listaParticipantes = nullptr;

    do {
        cout << endl << "Selecciona una de las siguientes opciones" << endl;
        cout << "\t(1) Registrar participante" << endl;
        cout << "\t(2) Imprimir participantes" << endl;
        cout << "\t(3) Dar de baja a participante" << endl;
        cout << "\t(4) Salir" << endl;

        cout << "Ingrese una opción: ";
        cin >> choice;
        cout << endl;

        userMenu(choice, listaParticipantes);

    } while (choice != 4);

    return 0;
}
