#ifndef DATATYPES_HPP
#define DATATYPES_HPP
#include "List/LinkedList.hpp"
#include <string>
using std::string;
typedef unsigned int size_t;
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
};

class Workers // hash table
{

private:
  ListADT<worker_t> *trabajadores;
  size_t maxLength;
  rut_t hash(rut_t);

public:
  Workers(size_t);
  ~Workers();
  void insertWorker(worker_t);
  void deleteWorker(rut_t);
  void modifyWorker(rut_t, worker_t);
  void genLiq();
};

class Department : public Workers
{
private:
  id_dpto numero;
  string nombre; // < 51
  size_t numWorkers;
  Workers Trabajadores; // hash table

public:
  size_t getNumWorkers();
};

class ChozaDeConcreto
{
private:
  ListADT<Department> *departamentos;
  size_t TotalWorkers;

public:
  size_t getTotalWorkers();
};
#endif