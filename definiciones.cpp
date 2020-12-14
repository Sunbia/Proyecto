/**========================================================================
 * ?                              About
 * @Autor       : David Gomez Pinto
 * @Email       : dgomezp@ing.ucsc.cl  
 * @Repository  : --- 
 * @Description : Metodos de definiciones
 *========================================================================**/
//
// ─── Includes ──────────────────────────────────────────────────────────────────
//
#include "definiciones.hpp"
//
// ─── Rut ────────────────────────────────────────────────────────────────────────
//
int rut::toInt()
{
  int sum = 0;
  int j = 100000000;
  int verify = verificador - '0';
  for (int i = 0; i < 8; i++)
  {
    sum += digitos[i] * j;
    j /= 10;
  }
  return sum + verificador;
}
//
// ─── Fecha ─────────────────────────────────────────────────────────────────────
//
bool fecha::isSafe()
{
  return (day > 0 && day < 32) &&
         (month > 0 && month < 13) &&
         (year > 1899 && year < 2020);
}
//
// ─── Trabajadores ───────────────────────────────────────────────────────────────
//
Trabajadores::Trabajadores()
{
  first = new node();
  last = first;
  size = 0;
}

Trabajadores::~Trabajadores()
{
  node *aux = last;
  while (aux != NULL)
  {
    last = last->prev;
    delete aux;
    aux = last;
  }
}

bool Trabajadores::isempty()
{
  return (first == NULL && last == NULL);
}

void Trabajadores::addWorker(node *worker)
{
  if (this->isempty())
  {
    first = worker;
    last = first;
    size++;
  }
  else
  {
    worker->next = NULL;
    worker->prev = last;
    last->next = worker;
    size++;
  }
}
void Trabajadores::removeFirst()
{
  first = first->next;
  delete first->prev;
}

void Trabajadores::removeLast()
{
  last = last->prev;
  delete last->next;
}

void Trabajadores::removeWorker(node *worker)
{
  if (worker == first)
  {
    removeFirst();
  }
  else if (worker == last)
  {
    removeLast();
  }
  else
  {
    node *aux = first;
    node *next;
    node *prev;
    while (aux != NULL)
    {
      if (aux == worker)
      {
        next = aux->next;
        prev = aux->prev;
        prev->next = next;
        delete aux;
      }
      aux = aux->next;
    }
  }
}

void Trabajadores::modifyWorker(node *worker)
{
}

void Trabajadores::genSalary(rut)
{
}

void Trabajadores::displayWorkers()
{
}
