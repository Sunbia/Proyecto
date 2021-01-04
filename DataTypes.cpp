#include "DataTypes.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//
// ─── WORKER_T ───────────────────────────────────────────────────────────────────
//
bool worker_t::verify()
{
  return RUT.digitos > 99999999 && (RUT.verificador != 'k' || RUT.verificador <= '0' || RUT.verificador >= '9') && (nacimiento.day < 1 || nacimiento.day > 31) && (nacimiento.month < 1 || nacimiento.month > 12) && (nacimiento.year < 1900 || nacimiento.year > 2003) && nombre.length() > 50 && apellidoP.length() > 25 && apellidoM.length() > 25;
}

std::ostream &operator<<(std::ostream &output, const worker_t &worker)
{
  output << "Nombre:" << worker.nombre << ' ' << worker.apellidoP << ' ' << worker.apellidoM << endl;
  output << "Rut:" << worker.RUT.digitos << '-' << worker.RUT.verificador << endl;
  output << "Fecha de nacimiento:" << worker.nacimiento.day << '/' << worker.nacimiento.month << '/' << worker.nacimiento.year << endl;
  output << "Tipo de contrato:" << worker.contrato << endl;
  output << "Salario por hora:" << worker.salario << endl;
  output << "Numero de cargas:" << worker.cargas << endl;
  return output;
}
std::istream &operator>>(std::istream &in, worker_t &trabajador)
{
  cout << "-- Rut --" << endl;

  cout << "Numero inicial (12.345.678 sin puntos):";
  in >> trabajador.RUT.digitos;
  cout << endl;

  cout << "Digito verificador:";
  in >> trabajador.RUT.verificador;
  cout << endl;

  cout << "-- Fecha de nacimiento --" << endl;

  cout << "Day:";
  in >> trabajador.nacimiento.day;
  cout << endl;

  cout << "Month:";
  in >> trabajador.nacimiento.month;
  cout << endl;

  cout << "Year:";
  in >> trabajador.nacimiento.month;

  cout << endl
       << "Nombre:";
  in >> trabajador.nombre;

  cout << endl
       << "Apellido Paterno:";
  in >> trabajador.apellidoP;

  cout << endl
       << "Apellido Paterno:";
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
      cout << "Ingrese una opcion correcta" << endl;
      break;
    }
  } while (expression < 1 || expression > 5);
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
bool Workers::isEmpty()
{
  return !numWorkers;
}
// ────────────────────────────────────────────────────────────────────────────────
bool Workers::contains(rut_t rut_p)
{
  return trabajadores->contains(rut_p);
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
  if (this->isEmpty())
  {
    cout << "La lista de trabajadores esta vacia" << endl;
  }
  else if (!contains(rut_p))
  {
    cout << "El trabajador no se encuentra en la lista" << endl;
  }
  else
  {
    trabajadores->remove(rut_p);
    numWorkers--;
    cout << trabajadores->find(rut_p).nombre << "ha sido removido de la lista" << endl;
  }
}

// ────────────────────────────────────────────────────────────────────────────────

void Workers::modifyWorker(rut_t rut_p, worker_t worker_p)
{
  if (trabajadores->empty())
  {
    cout << "La lista de trabajadores esta vacia" << endl;
  }
  else if (!trabajadores->contains(rut_p))
  {
    cout << "El trabajador no se encuentra en la lista" << endl;
  }
  else
  {
    trabajadores->find(rut_p) = worker_p;
    cout << "Los datos de " << trabajadores->find(rut_p).nombre << "han sido modificados" << endl;
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::displayWorkers()
{
  if (!trabajadores->empty())
  {
    trabajadores->display();
  }
}
// ────────────────────────────────────────────────────────────────────────────────

void Workers::genLiq(rut_t id)
{
  salario_t porDia = trabajadores->find(id).salario * 8;
  salario_t porSemana = porDia * 40;
  salario_t porMes = porSemana * 4;
  salario_t descuentosDia = (7 / 100) * porDia + porDia * (1 / 10);
  salario_t beneficiosDia = (porDia / 4) + 1500;
  salario_t descuentosSemana = descuentosDia * 5;
  salario_t beneficiosSemana = beneficiosDia * 5;
  salario_t descuentosMes = descuentosSemana * 4;
  salario_t beneficiosMes = descuentosSemana * 4;
  if (trabajadores->find(id).contrato == "Fijo")
  {
    cout << "Salario Mensual:" << porMes - descuentosMes + beneficiosMes;
  }
  else if (trabajadores->find(id).contrato == "Indefinido")
  {
    cout << "Salario Dia" << porDia - descuentosDia + beneficiosDia;
    cout << "Salario Semanal" << porSemana - descuentosSemana + beneficiosSemana;
    cout << "Salario Mensual:" << porMes - descuentosMes + beneficiosMes;
  }
  else if (trabajadores->find(id).contrato == "Faena")
  {
    cout << "Salario por Hora" << porDia / 8 - descuentosDia / 8 + beneficiosDia / 8;
    cout << "Salario Dia" << porDia - descuentosDia + beneficiosDia;
    cout << "Salario Semanal" << porSemana - descuentosSemana + beneficiosSemana;
    cout << "Salario Mensual:" << porMes - descuentosMes + beneficiosMes;
  }
  else if (trabajadores->find(id).contrato == "Dia")
  {
    cout << "Salario por dia" << porDia - descuentosDia + beneficiosDia;
  }
  else if (trabajadores->find(id).contrato == "Honorarios")
  {
    int expression;
    int cantidad;
    do
    {
      cout << "Ingrese el tiempo que el trabajador va prestar su servicio";
      cin >> expression;
      cout << "1.Horas" << endl;
      cout << "2.Dias" << endl;
      cout << "3.Semanas" << endl;
      switch (expression)
      {
      case 1:
        cout << "Ingrese la cantidad de horas:";
        cin >> cantidad;
        cout << "Salario por " << cantidad << " horas" << porDia / 8 * cantidad;
        break;
      case 2:
        cout << "Ingrese la cantidad de dias:";
        cin >> cantidad;
        cout << "Salario por " << cantidad << "dias" << porDia * cantidad;
      case 3:
        cout << "Ingrese la cantidad de semanas:";
        cin >> cantidad;
        cout << "Salario por " << cantidad << "semanas" << porSemana * cantidad;
      default:
        break;
      }
    } while (expression >= 1 && expression <= 3);
  }
}

//
// ─── DEPARTMENT ─────────────────────────────────────────────────────────────────
//

Department::Department()
{
  departamentos = new DLinkedList<department_t>;
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
bool Department::isEmpty()
{
  return totalDpto == 0;
  // return departamentos->empty();
}
// ────────────────────────────────────────────────────────────────────────────────
bool Department::contains(id_dpto idpto)
{
  for (size_t i = 0; i < departamentos->getsize(); i++)
  {
    if (departamentos->get(i).numero == idpto)
    {
      return true;
    }
  }
  return false;
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
  if (isEmpty())
  {
    cout << "No se han agregado departamentos" << endl;
  }
  else if (departamentos->contains(target) == false)
  {
    cout << "No se encontro el departamento" << endl;
  }
  else
  {
    departamentos->remove(target);
    totalDpto--;
  }
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
      break;
    }
  }
  return target;
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayWorkers(id_dpto dpto)
{
  getDpto(dpto).Trabajadores->displayWorkers();
}
// ────────────────────────────────────────────────────────────────────────────────

void Department::DisplayDptos()
{
  cout << "================ Departamentos ================" << endl;
  for (index_t i = 0; i < departamentos->getsize(); i++)
  {
    cout <<"Nombre:"<< departamentos->get(i).nombre << endl;
    cout <<"Numero identificador:" << departamentos->get(i).numero << endl;
    cout <<"Total de Trabajadores:" << departamentos->get(i).Trabajadores->getNumWorkers() << endl;
    cout <<"===============================================" << endl;
  }
}