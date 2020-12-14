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
  workers = new LinkedList<worker>;
}

//
// ─── Departamentos ──────────────────────────────────────────────────────────────
//
