#include "DataTypes.hpp"
#include <iostream>
using std::cout;
using std::endl;

//
// ─── WORKER_T ─────────────────────────────────────────────────────────────────────
//

void worker_t::see()
{
  cout << RUT.digitos << '-' << RUT.verificador << endl;
  cout << nacimiento.day << '/' << nacimiento.month << '/' << nacimiento.year << endl;
  cout << nombre << ' ' << apellidoP << ' ' << apellidoM << endl;
  cout << contrato << endl;
  cout << salario << endl;
  cout << cargas << endl;
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
  for (size_t i = 0; i < MAX; i++)
  {
    trabajadores[i] = new LinkedList<worker_t>;
  }
  maxLength = MAX;
}
// ────────────────────────────────────────────────────────────────────────────────

Workers::~Workers()
{
  for (size_t i = 0; i < maxLength; i++)
  {
    while (trabajadores[i]->getHead() != NULL)
    {
      trabajadores[i]->removeTail();
    }
  }
  delete[] trabajadores;
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

  for (size_t i = 0; i < maxLength; i++)
  {
    node<worker_t> *aux = trabajadores[i]->getHead();
    while (aux != NULL)
    {
      aux->data.see();
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::genLiq(rut_t)
{
  // pendiente
}

//
// ─── DEPARTMENT ─────────────────────────────────────────────────────────────────
//
node<department_t> *Department::find(id_dpto idpto)
{
  for (node<department_t> *i = primero; i != NULL; i = i->next)
  {
    if (i->data.numero == idpto)
    {
      return i;
    }
  }
}
// ────────────────────────────────────────────────────────────────────────────────

Department::Department()
{
  primero = NULL;
  primero->data.Trabajadores = new Workers;
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

size_t Department::getNumWorkers(id_dpto idpto)
{
  node<department_t> *aux = find(idpto);
  return aux->data.numWorkers;
}
// ────────────────────────────────────────────────────────────────────────────────

size_t Department::getTotalWokers()
{
  size_t sum = 0;
  for (node<department_t> *i = primero; i != NULL; i = i->next)
  {
    sum += i->data.numWorkers;
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
  size_t j = 0;
  for (node<department_t> *i = primero; i != NULL; i = i->next)
  {
    cout << endl
         << "ID:" << i->data.numero << endl;
    cout << "Nombre:" << i->data.nombre << endl;
    cout << "Total de trabajadores:" << i->data.numWorkers << endl
         << endl;
  }
}
