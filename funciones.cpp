#include <iostream>
#include "estructuras.h"

using namespace std;

void registrarParticipante(Participante*& listaParticipantes) {
    
    Participante* nuevoParticipante = new Participante;
    nuevoParticipante->siguiente = nullptr;

    // Ingresar datos del participante
        cout << "Ingrese el nombre del participante: ";
        cin >> nuevoParticipante -> nombre;

        cout << "Ingrese el expediente del participante: ";
        cin >> nuevoParticipante -> expediente;

        cout << "Ingrese el lenguaje de programacion del examen: ";
        cin >> nuevoParticipante -> examen.lenguaje;

        cout << "Ingrese la cantidad de problemas a resolver en el examen: ";
        cin >> nuevoParticipante -> examen.cantidadProblemas;

    if (listaParticipantes == nullptr) { // Verificar si la lista de participantes esta vacia
        listaParticipantes = nuevoParticipante;
    
    } else {
        Participante* ptr_temp = listaParticipantes;

        while (ptr_temp -> siguiente != nullptr) { // Ciclo para encontrar el ultimo participantante
            ptr_temp = ptr_temp -> siguiente;
        }
        ptr_temp -> siguiente = nuevoParticipante;
    }
}

void imprimirParticipantes(const Participante* listaParticipantes) {
    
    if (listaParticipantes == nullptr) { // Verificar si la lista de participantes esta vacia
        cout << "No hay participantes registrados." << endl;
    
    } else {
        cout << "***  Lista de participantes ***" << endl;
        const Participante* ptr_temp = listaParticipantes;
        
        while (ptr_temp != nullptr) { // Imprimir en pantalla la lista de participantes
            cout << "Nombre: " << ptr_temp -> nombre << endl;
            cout << "Expediente: " << ptr_temp -> expediente << endl;
            cout << "Lenguaje de programacion del examen: " << ptr_temp -> examen.lenguaje << endl;
            cout << "Cantidad de problemas a resolver en el examen: " << ptr_temp -> examen.cantidadProblemas << endl;
            cout << endl;
            ptr_temp = ptr_temp -> siguiente;
        }
    }
}

void darDeBajaParticipante(Participante*& listaParticipantes) {
    
    if (listaParticipantes == nullptr) { // Verificar si la lista de participantes esta vacia
        cout << "No hay participantes registrados." << endl;
        return;
    }

    int expediente;
    cout << "Ingrese el numero de expediente del participante a dar de baja: ";
    cin >> expediente;

    Participante* ptr_temp = listaParticipantes;
    Participante* ptr_ant = nullptr;

    while (ptr_temp != nullptr && ptr_temp -> expediente != expediente) { // Recorrer la lista de participantes y verificar expediente
        ptr_ant = ptr_temp;
        ptr_temp = ptr_temp -> siguiente;
    }

    if (ptr_temp == nullptr) { 
        cout << "No se encontró un participante con ese numero de expediente." << endl;
        return;
    }

    if (ptr_ant == nullptr) { // Enlazar elementos de la estructura despues de eliminar un participante
        listaParticipantes = ptr_temp -> siguiente;
    } else {
        ptr_ant -> siguiente = ptr_temp -> siguiente;
    }
}

void liberarMemoria(Participante* listaParticipantes) {
   
    while (listaParticipantes != nullptr) {
        Participante* siguiente = listaParticipantes->siguiente;
        delete listaParticipantes;
        listaParticipantes = siguiente;
    }
}

void userMenu(int choice, Participante*& listaParticipantes) {

    switch (choice) {
        case 1: // Registrar participante
            registrarParticipante(listaParticipantes);
            cout << "Participante registrado con éxito." << endl;
            break;

        case 2: // Imprimir participantes
            imprimirParticipantes(listaParticipantes);
            break;

        case 3: // Dar de baja a participante
            darDeBajaParticipante(listaParticipantes);
            cout << "Participante dado de baja exitosamente." << endl;
            break;

        case 4: // Salir del programa
            liberarMemoria(listaParticipantes);
            cout << "Gracias por usar nuestro programa." << endl;
            cout << "Autor: Amado Rosas" << endl;
            break;

        default:
            cout << "Opción inválida." << endl;            
            break;
    }
}

