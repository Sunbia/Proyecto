#ifndef DATATYPES_HPP
#define DATATYPES_HPP
#include "List\DLinkedList.hpp"
#include "HashTable\OpenHashTable.hpp"
#include <string>
#include <iostream>
using std::string;
typedef unsigned int sizeT;
typedef unsigned int id_dpto; // key
typedef unsigned int salario_t;
typedef unsigned int carga_t;
typedef unsigned int rut_t; // key
// ────────────────────────────────────────────────────────────────────────────────

struct rut
{
  rut_t digitos;
  char verificador;
};

struct fecha
{
  unsigned int day;
  unsigned int month;
  unsigned int year;
};
// ────────────────────────────────────────────────────────────────────────────────

struct worker_t
{
  rut RUT;
  fecha nacimiento;
  string nombre;
  string apellidoP;
  string apellidoM;
  string contrato;
  salario_t salario;
  carga_t cargas;
  bool verify();
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
  bool isEmpty();
  bool contains(rut_t);
  sizeT getNumWorkers();
  void insertWorker(worker_t);
  worker_t getWorker(rut_t);
  void deleteWorker(rut_t);
  void modifyWorker(rut_t, worker_t);
  void displayWorkers();
  void genLiq(rut_t);
};
// ────────────────────────────────────────────────────────────────────────────────

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
  bool isEmpty();
  bool contains(id_dpto);
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