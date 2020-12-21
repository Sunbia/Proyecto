#ifndef DATATYPES_HPP
#define DATATYPES_HPP
#include "List/LinkedList.hpp"
#include <string>
#include <iostream>
using std::string;

#define MAX 10 // tamaño de la tabla
typedef unsigned int sizeT;
typedef unsigned int id_dpto; // key
typedef unsigned int salario_t;
typedef unsigned int carga_t;
typedef unsigned int rut_t; // key

struct rut
{
  rut_t digitos;
  char verificador;
  bool isCorrect();
};

struct fecha
{
  unsigned int day;   //   0 < day < 32
  unsigned int month; //  0 < month < 13
  unsigned int year;  // 1900 < month < 9999 (?)
  bool isSafe();
};

struct worker_t
{
  rut RUT; //  rut.digitos = key
  fecha nacimiento;
  string nombre;    // < 51
  string apellidoP; // < 51
  string apellidoM; // < 51
  string contrato;
  salario_t salario;
  carga_t cargas;
  friend std::ostream& operator << (std::ostream &, const worker_t &);
  friend std::istream& operator >> (std::istream &, worker_t &);
  bool operator==(const worker_t &);
  bool operator!=(const worker_t &);
};

class Workers
{
private:
  ListADT<worker_t> *trabajadores[MAX];

  sizeT maxLength;
  rut_t hash(rut_t);

public:
  Workers();
  ~Workers();
  void insertWorker(worker_t);
  void deleteWorker(rut_t);
  void modifyWorker(rut_t, worker_t);
  void displayTable();
  void genLiq(rut_t);
};

struct department_t
{
  id_dpto numero;
  string nombre;
  sizeT numWorkers;
  Workers *Trabajadores;
  department_t();
  ~department_t();
};
class Department
{
private:
  node<department_t> *primero;
  node<department_t> *ultimo;
  sizeT totalDpto;

public:
  Department();
  ~Department();
  node<department_t> *find(id_dpto);
  sizeT TotalWorkers;
  void pushDpto(id_dpto, string);
  void deleteDpto(id_dpto);
  sizeT getNumWorkers(id_dpto);
  sizeT getTotalWokers();
  void DisplayWorkers(id_dpto);
  void DisplayDptos();
};

#endif