#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP
#include <iostream>
using std::cin;
using std::cout;
// ────────────────────────────────────────────────────────────────────────────────
// System(clear) para cualquier sistema operativo (PC)
#if defined(_WIN32)
#define clear "cls"
#elif defined(linux)
#define clear "clear"
#elif defined(MACH)
#define clear "clear"
#endif
// ────────────────────────────────────────────────────────────────────────────────
void dMsgEmpty();     // lista de departamentos vacia
void dMsgNotFinded(); // Departamento no encontrado
void dMsgExists();    // Departamento ya existe
void wMsgEmpty();     // lista de trabajadores vacia
void wMsgNotFinded(); // trabajador no encontrado
void wMsgExists();    // trabajador ya existe

void dMsgEmpty()
{
  cout << "Lista de departamentos vacia" << endl;
  cin.ignore();
  cin.get();
}
void dMsgNotFinded()
{
  cout << "Departamento no encotrado" << endl;
  cin.ignore();
  cin.get();
}
void dMsgExists()
{
  cout << "Departamento ya se encuentra en la lista con ese numero" << endl;
  cin.ignore();
  cin.get();
}
void wMsgEmpty()
{
  cout << "Lista de Trabajadores vacia" << endl;
  cin.ignore();
  cin.get();
}
void wMsgNotFinded()
{
  cout << "Trabajador no encotrado" << endl;
  cin.ignore();
  cin.get();
}
void wMsgExists()
{
  cout << "Ese rut ya se encuentra en la lista de trabajadores" << endl;
  cin.ignore();
  cin.get();
}
#endif