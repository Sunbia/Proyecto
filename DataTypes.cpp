#include "DataTypes.hpp"
#include <iostream>
using std::cout;
using std::endl;

//
// ─── WORKER_T ───────────────────────────────────────────────────────────────────
//

std::ostream &operator<<(std::ostream &output, const worker_t &worker)
{
  output << worker.RUT.digitos << '-' << worker.RUT.verificador << endl;
  output << worker.nacimiento.day << '/' << worker.nacimiento.month << '/' << worker.nacimiento.year << endl;
  output << worker.nombre << ' ' << worker.apellidoP << ' ' << worker.apellidoM << endl;
  output << worker.contrato << endl;
  output << worker.salario << endl;
  output << worker.cargas << endl;
  return output;
}
std::istream &operator>>(std::istream &in, worker_t &trabajador)
{
  cout << "-- Rut --" << endl;
  cout << "Numero inicial (12.345.678 sin puntos):";
  in >> trabajador.RUT.digitos;
  cout << endl
       << "Digito verificador:";
  in >> trabajador.RUT.verificador;
  cout << endl
       << "-- Fecha de nacimiento --" << endl;
  cout << "Day:";
  in >> trabajador.nacimiento.day;
  cout << endl
       << "Month:";
  in >> trabajador.nacimiento.month;
  cout << endl
       << "Year:";
  in >> trabajador.nacimiento.year;
  cout << endl
       << "Nombre:";
  in >> trabajador.nombre;
  cout << endl
       << "Apellido Paterno:";
  in >> trabajador.apellidoP;
  cout << endl
       << "Apellido Materno:";
  in >> trabajador.apellidoM;
  cout << endl
       << "Tipo contrato:" << endl;
  int expression;
  do
  {
    cout << "1.Fijo" << endl;
    cout << "2.Indefinido" << endl;
    cout << "3.Faena" << endl;
    cout << "4.Dia" << endl;
    cout << "5.Honorarios" << endl;
    cout << "Elija una opcion:";
    std::cin >> expression;
    switch (expression)
    {
    case 1:
      trabajador.contrato = "Fijo";
      break;
    case 2:
      trabajador.contrato = "Indefinido";
      break;
    case 3:
      trabajador.contrato = "Faena";
      break;
    case 4:
      trabajador.contrato = "Dia";
      break;
    case 5:
      trabajador.contrato = "Honorarios";
      break;
    default:
      cout << "Ingrese una opcion correcta";
      break;
    }
  } while (expression <= 0 || expression > 5);
  cout << endl
       << "Salario:";
  in >> trabajador.salario;
  cout << endl
       << "Numero de cargas:";
  in >> trabajador.cargas;
  return in;
}
bool worker_t::operator==(const worker_t &worker)
{
  return (RUT.digitos == worker.RUT.digitos && RUT.verificador == worker.RUT.verificador && nacimiento.day == worker.nacimiento.day && nacimiento.month == worker.nacimiento.month && nacimiento.year == worker.nacimiento.year && nombre == worker.nombre && apellidoP == worker.apellidoP && apellidoM == worker.apellidoM && contrato == worker.contrato && salario == worker.salario && cargas == worker.cargas);
}
bool worker_t::operator!=(const worker_t &worker)
{
  return (RUT.digitos != worker.RUT.digitos && RUT.verificador != worker.RUT.verificador && nacimiento.day != worker.nacimiento.day && nacimiento.month != worker.nacimiento.month && nacimiento.year != worker.nacimiento.year && nombre != worker.nombre && apellidoP != worker.apellidoP && apellidoM != worker.apellidoM && contrato != worker.contrato && salario != worker.salario && cargas != worker.cargas);
}
//
// ─── DEPARTMENT_T ───────────────────────────────────────────────────────────────
//

bool department_t::operator==(const department_t &ref)
{
  return numero == ref.numero && nombre == ref.nombre;
}
bool department_t::operator!=(const department_t &ref)
{
  return numero != ref.numero && nombre != ref.nombre;
}

//
// ─── TRABAJADORES ───────────────────────────────────────────────────────────────
//

sizeT Workers::getNumWorkers()
{
  return numWorkers;
}

// ────────────────────────────────────────────────────────────────────────────────

Workers::Workers()
{
  trabajadores = new OpenHashTable<rut_t, worker_t>;
  numWorkers = 0;
}
// ────────────────────────────────────────────────────────────────────────────────

Workers::~Workers() // O(1)*O(n) = O(n)
{
  delete trabajadores;
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::insertWorker(worker_t worker_p)
{
  trabajadores->insert(worker_p.RUT.digitos, worker_p);
  numWorkers++;
}
// ────────────────────────────────────────────────────────────────────────────────

worker_t Workers::getWorker(rut_t rut_p)
{
  return trabajadores->find(rut_p);
}

// ────────────────────────────────────────────────────────────────────────────────

void Workers::deleteWorker(rut_t rut_p)
{
  trabajadores->remove(rut_p);
  numWorkers--;
}

// ────────────────────────────────────────────────────────────────────────────────

void Workers::modifyWorker(rut_t rut_p, worker_t worker_p)
{
  trabajadores->find(rut_p) = worker_p;
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::displayTable()
{
  trabajadores->display();
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::genLiq(rut_t id)
{
  trabajadores->find(id).nombre;
  trabajadores->find(id).apellidoP;
  trabajadores->find(id).apellidoM;
  trabajadores->find(id).RUT;
  trabajadores->find(id).nacimiento;
  trabajadores->find(id).contrato;
  trabajadores->find(id).cargas;
}

//
// ─── DEPARTMENT ─────────────────────────────────────────────────────────────────
//

Department::Department()
{
  departamentos = new LinkedList<department_t>;
  totalDpto = 0;
}
// ────────────────────────────────────────────────────────────────────────────────

Department::~Department()
{
  // while (totalDpto > 0)
  // {
  //   departamentos->removeTail();
  //   totalDpto--;
  // }
  delete departamentos;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::pushDpto(id_dpto id, string name)
{
  department_t nuevoDpto;
  nuevoDpto.numero = id;
  nuevoDpto.nombre = name;
  nuevoDpto.Trabajadores = new Workers();
  departamentos->addAfterTail(nuevoDpto);
  totalDpto++;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::deleteDpto(id_dpto idpto)
{
  department_t target = getDpto(idpto);
  departamentos->remove(target);
}

// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getNumWorkers(id_dpto idpto)
{
  return getDpto(idpto).Trabajadores->getNumWorkers();
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getTotalWorkers()
{
  sizeT suma = 0;
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    suma += departamentos->get(i).Trabajadores->getNumWorkers();
  }
  return suma;
}

// ────────────────────────────────────────────────────────────────────────────────
sizeT Department::getTotalDpto()
{
  return totalDpto;
}

// ────────────────────────────────────────────────────────────────────────────────
department_t Department::getDpto(id_dpto idpto)
{
  department_t target;
  for (size_t i = 0; i < departamentos->getsize(); i++)
  {
    target = departamentos->get(i);
    if (target.numero == idpto)
    {
      return target;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayWorkers(id_dpto dpto)
{
  getDpto(dpto).Trabajadores->displayTable();
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayDptos()
{
  cout << "================ Departamentos ================" << endl;
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    cout << departamentos->get(i).nombre << endl;
    cout << departamentos->get(i).numero << endl;
    cout << "===============================================" << endl;
  }
}