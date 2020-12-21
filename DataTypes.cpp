#include "DataTypes.hpp"
#include <iostream>
using std::cout;
using std::endl;

//
// ─── WORKER_T ─────────────────────────────────────────────────────────────────────
//

std::ostream& operator << (std::ostream& output, const worker_t& worker)
{
  output << worker.RUT.digitos << '-' << worker.RUT.verificador << endl;
  output << worker.nacimiento.day << '/' << worker.nacimiento.month << '/' << worker.nacimiento.year << endl;
  output << worker.nombre << ' ' << worker.apellidoP << ' ' << worker.apellidoM << endl;
  output << worker.contrato << endl;
  output << worker.salario << endl;
  output << worker.cargas << endl;
  return output;
}
std::istream& operator >> (std::istream &in, worker_t &trabajador)
{

  cout << "Rut:" << endl;
  cout << "Numero inicial (12.345.678 sin puntos):";
  in >> trabajador.RUT.digitos;
  cout << "Digito verificador:";
  in >> trabajador.RUT.verificador;
  cout << "Fecha de nacimiento:" << endl;
  cout << "Dia:";
  in >> trabajador.nacimiento.day;
  cout << "Mes";
  in >> trabajador.nacimiento.month;
  cout << "Año:";
  in >> trabajador.nacimiento.year;
  cout << "Nombre:" << endl;
  in >> trabajador.nombre;
  cout << "Apellido Paterno:" << endl;
  in >> trabajador.apellidoP;
  cout << "Apellido Materno:" << endl;
  in >> trabajador.apellidoM;
  cout << "Tipo contrato:" << endl;
  in >> trabajador.contrato;
  cout << "Salario:" << endl;
  in >> trabajador.salario;
  cout << "Numero de cargas:" << endl;
  in >> trabajador.cargas;
}
bool worker_t::operator==(const worker_t &worker)
{
  return (RUT.digitos == worker.RUT.digitos 
  && RUT.verificador == worker.RUT.verificador 
  && nacimiento.day == worker.nacimiento.day 
  && nacimiento.month == worker.nacimiento.month 
  && nacimiento.year == worker.nacimiento.year 
  && nombre == worker.nombre 
  && apellidoP == worker.apellidoP 
  && apellidoM == worker.apellidoM 
  && contrato == worker.contrato 
  && salario == worker.salario 
  && cargas == worker.cargas);
}
bool worker_t::operator!=(const worker_t &worker)
{
  return (RUT.digitos != worker.RUT.digitos 
  && RUT.verificador != worker.RUT.verificador 
  && nacimiento.day != worker.nacimiento.day 
  && nacimiento.month != worker.nacimiento.month 
  && nacimiento.year != worker.nacimiento.year 
  && nombre != worker.nombre 
  && apellidoP != worker.apellidoP 
  && apellidoM != worker.apellidoM 
  && contrato != worker.contrato 
  && salario != worker.salario 
  && cargas != worker.cargas);
}

//
// ─── DEPARTMENT_TYPE ──────────────────────────────────────────────────────────────────
//
department_t::department_t()
{
  numWorkers = 0;
  Trabajadores = new Workers();

}
department_t::~department_t()
{
  Trabajadores->~Workers();
}
  
//
// ─── TRABAJADORES ───────────────────────────────────────────────────────────────
//

rut_t Workers::hash(rut_t key)
{
  return key % maxLength;
}
// ────────────────────────────────────────────────────────────────────────────────

Workers::Workers()
{
  for (int i = 0; i < MAX; i++)
  {
    trabajadores[i] = new LinkedList<worker_t>;
  }
  maxLength = MAX;
}
// ────────────────────────────────────────────────────────────────────────────────

Workers::~Workers()
{
  for (sizeT i = 0; i < maxLength; i++)
  {
    while (trabajadores[i]->getHead() != NULL)
    {
      trabajadores[i]->removeTail();
    }
    trabajadores[i]->removeHead();
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::insertWorker(worker_t worker_p)
{
  rut_t index = hash(worker_p.RUT.digitos);
  trabajadores[index]->addAfterTail(worker_p);
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::deleteWorker(rut_t rut_p)
{
  rut_t index = hash(rut_p);
  for (node<worker_t> *i = trabajadores[index]->getHead(); i != NULL; i = i->next)
  {
    if (i->data.RUT.digitos == rut_p)
    {
      trabajadores[index]->remove(i->data);
      break;
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
    while (aux != NULL)
    {
      aux->data;
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
      aux->data.cargas; // variables
      aux->data.contrato; // variables
      aux->data.salario;// variables
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
node<department_t> *Department::find(id_dpto idpto)
{
  node<department_t> *finded;
  for (node<department_t> *i = primero; i != NULL; i = i->next)
  {
    if (i->data.numero == idpto)
    {
      finded = i;
      break;
    }
  }
  return finded;
}
// ────────────────────────────────────────────────────────────────────────────────

Department::Department()
{
  primero = new node<department_t>;
  ultimo = primero;
  TotalWorkers = 0;
}
// ────────────────────────────────────────────────────────────────────────────────

Department::~Department()
{
  for (node<department_t> *i = primero; i != ultimo; i = i->next)
  {
    primero = primero->next;
    delete i;
  }
  delete ultimo;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::pushDpto(id_dpto id, string name)
{
  node<department_t> *aux;
  aux->data.numWorkers = 0;
  aux->data.numero = id;
  aux->data.nombre = name;
  aux->data.Trabajadores = new Workers();
  ultimo->next = aux;
  totalDpto++;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::deleteDpto(id_dpto idpto)
{
  node<department_t> *requerido = find(idpto);
  for (node<department_t> *i = primero; i != requerido; i = i->next)
  {
    if (i->next == requerido)
    {
      i->next = requerido->next;
      delete requerido;
      totalDpto--;
      break;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getNumWorkers(id_dpto idpto)
{
  node<department_t> *aux = find(idpto);
  return aux->data.numWorkers;
}
// ────────────────────────────────────────────────────────────────────────────────

sizeT Department::getTotalWokers()
{
  sizeT sum = 0;
  node<department_t> *i = primero;
  department_t cero;
  while (i != NULL && i->data.numWorkers != 0)
  {
    sum += i->data.numWorkers;
    i = i->next;
  }
  return sum;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayWorkers(id_dpto idpto)
{
  node<department_t> *aux = find(idpto);
  aux->data.Trabajadores->displayTable();
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayDptos()
{
  sizeT j = 0;
  for (node<department_t> *i = primero; i != NULL; i = i->next)
  {
    cout << endl
         << "ID:" << i->data.numero << endl;
    cout << "Nombre:" << i->data.nombre << endl;
    cout << "Total de trabajadores:" << i->data.numWorkers << endl
         << endl;
  }
}
