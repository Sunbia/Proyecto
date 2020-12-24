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

rut_t Workers::hash(rut_t key)
{
  return key % maxLength;
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Workers::getNumWorkers()
{
  return numWorkers;
}

// ────────────────────────────────────────────────────────────────────────────────

Workers::Workers()
{
  for (int i = 0; i < MAX; i++)
  {
    trabajadores[i] = NULL;
  }
  maxLength = MAX;
  numWorkers = 0;
}
// ────────────────────────────────────────────────────────────────────────────────

Workers::~Workers() // O(1)*O(n) = O(n)
{
  for (sizeT i = 0; i < maxLength; i++) //O(1)
  {
    while (trabajadores[i]->empty() != false)
    {
      trabajadores[i]->removeTail(); //O(n)
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::insertWorker(worker_t worker_p)
{
  rut_t index = hash(worker_p.RUT.digitos);
  trabajadores[index] = new LinkedList<worker_t>();
  trabajadores[index]->addAfterTail(worker_p);
  numWorkers++;
}
// ────────────────────────────────────────────────────────────────────────────────

worker_t Workers::getWorker(rut_t rut_p)
{
  rut_t index = hash(rut_p);
  worker_t finded;
  for (index_t i = 0; i < trabajadores[index]->getsize(); i++)
  {
    node<worker_t> *aux = trabajadores[index]->find(i);
    if (aux->data.RUT.digitos == rut_p)
    {
      finded = aux->data;
    }
  }
  return finded;
}

// ────────────────────────────────────────────────────────────────────────────────

void Workers::deleteWorker(rut_t rut_p)
{
  rut_t index = hash(rut_p);
  node<worker_t> *aux = trabajadores[index]->getHead();
  while (aux != NULL)
  {
    if (aux->data.RUT.digitos == rut_p)
    {
      trabajadores[index]->remove(aux->data);
      numWorkers--;
      break;
    }
    else
    {
      aux = aux->next;
    }
  }
}

// ────────────────────────────────────────────────────────────────────────────────

void Workers::modifyWorker(rut_t rut_p, worker_t worker_p)
{
  rut_t index = hash(rut_p);
  for (node<worker_t> *i = trabajadores[index]->getHead(); i != NULL; i = i->next)
  {
    if (i->data.RUT.digitos == rut_p)
    {
      i->data = worker_p;
      break;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::displayTable()
{

  for (sizeT i = 0; i < maxLength; i++)
  {
    node<worker_t> *aux = trabajadores[i]->getHead();
    while (aux != NULL && trabajadores[i]->empty() != false)
    {
      cout << "=========================== Trabajador " << i + 1 << endl;
      cout << aux->data;
      cout << "===========================" << endl;
      aux = aux->next;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::genLiq(rut_t id)
{
  int i = hash(id);
  node<worker_t> *aux = trabajadores[i]->getHead();
  while (aux != NULL)
  {
    if (aux->data.RUT.digitos == id)
    {
      aux->data.cargas;   // variables
      aux->data.contrato; // variables
      aux->data.salario;  // variables
    }
    else
    {
      aux = aux->next;
    }
  }
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
  while (totalDpto > 0)
  {
    departamentos->removeTail();
    totalDpto--;
  }
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
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    node<department_t> *aux = departamentos->find(i);
    if (aux->data.numero == idpto)
    {
      departamentos->remove(aux->data);
      totalDpto--;
      break;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getNumWorkers(id_dpto idpto)
{
  node<department_t> *aux = find(idpto);
  return aux->data.Trabajadores->getNumWorkers();
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getTotalWorkers()
{
  sizeT suma = 0;
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    node<department_t> *aux = departamentos->find(i);
    suma += aux->data.Trabajadores->getNumWorkers();
  }
}

// ────────────────────────────────────────────────────────────────────────────────
sizeT Department::getTotalDpto()
{
  return totalDpto;
}

// ────────────────────────────────────────────────────────────────────────────────
node<department_t> *Department::find(id_dpto idpto)
{
  node<department_t> *finded;
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    node<department_t> *aux = departamentos->find(i);
    if (aux->data.numero == idpto)
    {
      finded = aux;
    }
  }
  return finded;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayWorkers(id_dpto dpto)
{
  find(dpto)->data.Trabajadores->displayTable();
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