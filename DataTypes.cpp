#include "DataTypes.hpp"
//
// ─── TRABAJADORES ───────────────────────────────────────────────────────────────
//

rut_t Workers::hash(rut_t key)
{
  return key % maxLength;
}

Workers::Workers(size_t length)
{
  trabajadores = new LinkedList<worker_t>[length];
  maxLength = length;
}
Workers::~Workers()
{
  // pendiente
}
void Workers::insertWorker(worker_t worker_p)
{
  rut_t index = hash(worker_p.RUT.digitos);
  trabajadores[index].addAfterTail(worker_p);
}
void Workers::deleteWorker(rut_t rut_p)
{
  rut_t index = hash(rut_p);
  for (node<worker_t> *i = trabajadores[index].getHead(); i != NULL; i = i->next;)
  {
    if (i->data.RUT.digitos == rut_p)
    {
      trabajadores[index].remove(i->data);
      break;
    }
  }
}
void Workers::modifyWorker(rut_t rut_p, worker_t worker_p)
{
  rut_t index = hash(rut_p);
  for (node<worker_t> *i = trabajadores[index].getHead(); i != NULL; i = i->next;)
  {
    if (i->data.RUT.digitos == rut_p)
    {
      i->data = worker_p;
      break;
    }
  }
}
void Workers::genLiq()
{
  // pendiente
}

//
// ─── DEPARTMENT ─────────────────────────────────────────────────────────────────
//
