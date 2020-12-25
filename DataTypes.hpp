#ifndef DATATYPES_HPP
#define DATATYPES_HPP
#include "List\LinkedList.hpp"
#include "HashTable\OpenHashTable.hpp"
#include <string>
#include <iostream>
using std::string;
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
  friend std::ostream &operator<<(std::ostream &, const worker_t &);
  friend std::istream &operator>>(std::istream &, worker_t &);
  bool operator==(const worker_t &);
  bool operator!=(const worker_t &);
};

class Workers
{

private:
  HashTable<rut_t, worker_t> *trabajadores;
  sizeT numWorkers;

public:
  Workers();
  ~Workers();
  sizeT getNumWorkers();
  void insertWorker(worker_t);
  worker_t getWorker(rut_t);
  void deleteWorker(rut_t);
  void modifyWorker(rut_t, worker_t);
  void displayTable();
  void genLiq(rut_t);
};

struct department_t
{
  id_dpto numero;
  string nombre;
  Workers *Trabajadores;
  friend std::ostream &operator<<(std::ostream &, const department_t &);
  bool operator==(const department_t &);
  bool operator!=(const department_t &);
};

class Department
{
private:
  ListADT<department_t> *departamentos;
  sizeT totalDpto;

public:
  Department();
  ~Department();
  void pushDpto(id_dpto, string);
  void deleteDpto(id_dpto);
  sizeT getNumWorkers(id_dpto);
  sizeT getTotalWorkers();
  sizeT getTotalDpto();
  void DisplayWorkers(id_dpto);
  void DisplayDptos();
  department_t getDpto(id_dpto);
};

#endif