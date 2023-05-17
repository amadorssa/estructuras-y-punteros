#include <string>

using namespace std;

struct Examen {
    string lenguaje;
    int cantidadProblemas;
};

struct Participante {
    string nombre;
    int expediente;
    Examen examen;
    Participante* siguiente;
};

void registrarParticipante(Participante*& listaParticipantes);
void imprimirParticipantes(const Participante* listaParticipantes);
void darDeBajaParticipante(Participante*& listaParticipantes);
void liberarMemoria(Participante* listaParticipantes);
void userMenu(int choice, Participante*& listaParticipantes);
