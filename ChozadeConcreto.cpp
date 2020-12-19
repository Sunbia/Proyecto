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
  int validateSwitch;
  int validateSwitch2;
  Department *chozadeconcreto = new Department();
  cout << "1. Agregar Departamento" << endl;
  cout << "2. Eliminar Departamento" << endl;
  cout << "3. Mostrar Departamentos" << endl;

  do
  {
    cout << "1. Agregar Departamento" << endl;
    cout << "2. Eliminar Departamento" << endl;
    cout << "3. Mostrar Departamentos" << endl;
    cout << "Total Trabajadores: " << chozadeconcreto->getTotalWokers();
    cout << "Total Departamentos: " << chozadeconcreto->getTotalWokers();
    switch (validateSwitch)
    {
    case 1:
      cout << "Ingrese un nombre para el departamento:";
      cin >> key_dpto;
      cout << "Numero identificador:";
      cin >> nombre_dpto;
      chozadeconcreto->pushDpto(key_dpto, nombre_dpto);
      break;
    case 2:
      cout << "Ingrese identificador para eliminar:";
      cin >> key_dpto;
      chozadeconcreto->deleteDpto(key_dpto);
      break;
    case 3:
      chozadeconcreto->DisplayDptos();
      cout << "Operaciones:" << endl;
      cout << "1.Agregar trabajador :" << endl;
      cout << "2.Eliminar trabajador :" << endl;
      cout << "3.Modificar trabajador :" << endl;
      cout << "4.Mostrar trabajadores de un departamento :" << endl;
      cout << "5.Generar liquidacion de sueldo" << endl;
      cout << "6.Volver al menu" << endl;
      switch (validateSwitch2)
      {
      case 1:
        cout << "En que departamento desea ingresar ?(ID): ";
        cin >> key_dpto;
        cout << "ingrese identificador de departamento:";
        cin >> key_dpto;
        cout << "ingrese rut del trabajador sin puntos ni guion: ";
        cin >> key_worker;
        cout << "Rut:" << endl;
        cout << "Numero inicial (12.345.678 sin puntos):";
        cin >> trabajador.RUT.digitos;
        cout << "Digito verificador:";
        cin >> trabajador.RUT.verificador;
        cout << "Fecha de nacimiento:" << endl;
        cout << "Dia:";
        cin >> trabajador.nacimiento.day;
        cout << "Mes";
        cin >> trabajador.nacimiento.month;
        cout << "Año:";
        cin >> trabajador.nacimiento.year;
        cout << "Nombre:" << endl;
        cin >> trabajador.nombre;
        cout << "Apellido Paterno:" << endl;
        cin >> trabajador.apellidoP;
        cout << "Apellido Materno:" << endl;
        cin >> trabajador.apellidoM;
        cout << "Tipo contrato:" << endl;
        cin >> trabajador.contrato;
        cout << "Salario:" << endl;
        cin >> trabajador.salario;
        cout << "Numero de cargas:" << endl;
        cin >> trabajador.cargas;
        node<department_t> *aux = chozadeconcreto->find(key_dpto);
        aux->data.Trabajadores->insertWorker(trabajador);
        aux->data.numWorkers++;
        continue;
      case 2:
        chozadeconcreto->find(key_dpto)->data.Trabajadores->deleteWorker(key_worker);
        aux->data.numWorkers--;
        cout << "Despedido con exito!" << endl;
        continue;
      case 3:
        cout << "ingrese identificador de departamento:";
        cin >> key_dpto;
        cout << "ingrese rut del trabajador sin puntos ni guion: ";
        cin >> key_worker;
        cout << "Rut:" << endl;
        cout << "Numero inicial (12.345.678 sin puntos):";
        cin >> trabajador.RUT.digitos;
        cout << "Digito verificador:";
        cin >> trabajador.RUT.verificador;
        cout << "Fecha de nacimiento:" << endl;
        cout << "Dia:";
        cin >> trabajador.nacimiento.day;
        cout << "Mes";
        cin >> trabajador.nacimiento.month;
        cout << "Año:";
        cin >> trabajador.nacimiento.year;
        cout << "Nombre:" << endl;
        cin >> trabajador.nombre;
        cout << "Apellido Paterno:" << endl;
        cin >> trabajador.apellidoP;
        cout << "Apellido Materno:" << endl;
        cin >> trabajador.apellidoM;
        cout << "Tipo contrato:" << endl;
        cin >> trabajador.contrato;
        cout << "Salario:" << endl;
        cin >> trabajador.salario;
        cout << "Numero de cargas:" << endl;
        cin >> trabajador.cargas;
        chozadeconcreto->find(key_dpto)->data.Trabajadores->modifyWorker(key_worker, trabajador);
        continue;
      case 4:
        chozadeconcreto->DisplayWorkers(key_dpto);
        continue;
      case 5:
        chozadeconcreto->find(key_dpto)->data.Trabajadores->genLiq(key_worker);
        continue;
      default:
        continue;
      }
      break;
    case 4:
      break;
    default:
      break;
    }
  } while (validateSwitch > 0 && validateSwitch < 4);

  return 0;
}
