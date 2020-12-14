/**========================================================================
 * ?                              About
 * @Autor       : David Gomez Pinto
 * @Email       : dgomezp@ing.ucsc.cl  
 * @Repository  : https://github.com/Sunbia/Proyecto
 * @Description : Definiciones de datos
 *========================================================================**/
#ifndef DEFINICIONES_HPP
#define DEFINICIONES_HPP
//
// ─── Includes ──────────────────────────────────────────────────────────────────
//
#include <string>
#include "List/LinkedList.hpp"
using std::string;
//
// ─── Data Types ─────────────────────────────────────────────────────────────────
//

typedef unsigned int size_t;
typedef unsigned int id_dpto;
typedef unsigned int salario_t;
typedef unsigned int carga_t;
struct rut
{
  unsigned int digitos[8];
  char verificador;
  int toInt();
};

struct fecha
{
  unsigned int day;
  unsigned int month;
  unsigned int year;
  bool isSafe();
};

struct worker
{
  rut RUT; //  key
  fecha nacimiento;
  string nombre;
  string apellidoP;
  string apellidoM;
  string contrato;
  salario_t salario;
  carga_t cargas;
};

//
// ─── Trabajadores ───────────────────────────────────────────────────────────────
//

class Trabajadores
{
  friend class LinkedList<worker>;

private:
  ListADT<worker> *workers;
  size_t size;

public:
  Trabajadores();
  ~Trabajadores();
};
//
// ─── Departamentos ──────────────────────────────────────────────────────────────
//
class Departamentos
{
private:
  id_dpto nDpto; //key
  string nombre;
  size_t numWorkers;
  Trabajadores **bucket;

public:
  Departamentos(size_t);
  Departamentos();
  void addDpto();
  void removeDpto();
  void getnumWorkers();

  ~Departamentos();
};
//
// ─── La Choza De Concreto ───────────────────────────────────────────────────────
//
class LaChozaDeConcreto
{
private:
  size_t totalWorkers;
  size_t cantidadDpto;
  Departamentos **bucket;
};

// ────────────────────────────────────────────────────────────────────────────────

#endif