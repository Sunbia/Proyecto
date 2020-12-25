#include "DataTypes.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
  worker_t trabajador;
  id_dpto key_dpto;
  rut_t key_worker;
  string nombre_dpto;
  int expression;
  int expression2;
  Department *chozadeconcreto = new Department();

  do
  {
    cout << "1. Agregar Departamento" << endl;
    cout << "2. Eliminar Departamento" << endl;
    cout << "3. Mostrar Departamentos" << endl;
    cout << "4. Salir" << endl;
    cout << "Total Trabajadores: " << chozadeconcreto->getTotalWorkers() << endl;
    cout << "Total Departamentos: " << chozadeconcreto->getTotalDpto() << endl;
    cout << "Seleccione una opcion:";
    cin >> expression;
    switch (expression)
    {
    case 1:
      cout << "Ingrese un nombre para el departamento:";
      cin >> nombre_dpto;
      cout << "Numero identificador:";
      cin >> key_dpto;
      chozadeconcreto->pushDpto(key_dpto, nombre_dpto);
      break;
    case 2:
      cout << "Ingrese identificador para eliminar:";
      cin >> key_dpto;
      chozadeconcreto->deleteDpto(key_dpto);
      break;
    case 3:
      chozadeconcreto->DisplayDptos();
      cout << "1.Agregar trabajador" << endl;
      cout << "2.Eliminar trabajador" << endl;
      cout << "3.Modificar trabajador" << endl;
      cout << "4.Mostrar trabajadores de un departamento" << endl;
      cout << "5.Generar liquidacion de sueldo" << endl;
      cout << "6.Volver al menu" << endl;
      cout << "Seleccione una opcion:";
      cin >> expression2;
      switch (expression2)
      {
      case 1:
        cout << "En que departamento desea ingresar ?(ID): ";
        cin >> key_dpto;
        cin >> trabajador;
        chozadeconcreto->getDpto(key_dpto).Trabajadores->insertWorker(trabajador);
        break;
      case 2:
        chozadeconcreto->getDpto(key_dpto).Trabajadores->deleteWorker(key_worker);
        cout << "Despedido con exito!" << endl;
        break;
      case 3:
        cout << "ingrese identificador de departamento:";
        cin >> key_dpto;
        cout << "Numero inicial del rut del trabajador (12.345.678 sin puntos): ";
        cin >> key_worker;
        cin >> trabajador;
        chozadeconcreto->getDpto(key_dpto).Trabajadores->modifyWorker(key_worker, trabajador);
        break;
      case 4:
        chozadeconcreto->DisplayWorkers(key_dpto);
        break;
      case 5:
        cout << "ingrese identificador de departamento:";
        cin >> key_dpto;
        cout << "Numero inicial del rut del trabajador (12.345.678 sin puntos): ";
        cin >> key_worker;
        chozadeconcreto->getDpto(key_dpto).Trabajadores->genLiq(key_worker);
        break;
      case 6:
        continue;
      default:
        break;
      }
      break;
    case 4:
      break;
    default:
      break;
    }
  } while (expression <= 1 || expression > 5 || expression2 <= 1 || expression2 > 3);

  return 0;
}
