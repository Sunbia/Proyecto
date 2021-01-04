#ifndef MENU_HPP
#define MENU_HPP
#include "DataTypes.hpp"
#include "utilidades.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void menu()
{
  worker_t trabajador;
  id_dpto key_dpto;
  rut_t key_worker;
  string nombre_dpto;
  int expression;
  int expression2;
  Department *chozadeconcreto = new Department();

  do
  {
    cout << "1. Agregar Departamento" << endl;
    cout << "2. Eliminar Departamento" << endl;
    cout << "3. Mostrar Departamentos" << endl;
    cout << "4. Salir" << endl;
    cout << "Total Trabajadores: " << chozadeconcreto->getTotalWorkers() << endl;
    cout << "Total Departamentos: " << chozadeconcreto->getTotalDpto() << endl;
    cout << "Seleccione una opcion:";
    cin >> expression;
    switch (expression)
    {
    case 1:
    {
      cout << "Ingrese un nombre para el departamento:";
      cin >> nombre_dpto;
      cout << "Numero identificador:";
      cin >> key_dpto;
      if (chozadeconcreto->contains(key_dpto))
      {
        dMsgExists();
        break;
      }

      chozadeconcreto->pushDpto(key_dpto, nombre_dpto);
      break;
    }
    case 2:
    {
      if (chozadeconcreto->isEmpty())
      {
        dMsgEmpty();
        break;
      }

      cout << "Ingrese identificador para eliminar:";
      cin >> key_dpto;
      if (chozadeconcreto->contains(key_dpto))
      {
        wMsgNotFinded();
        break;
      }
      chozadeconcreto->deleteDpto(key_dpto);
      break;
    }
    case 3:
    {
      if (chozadeconcreto->isEmpty())
      {
        dMsgEmpty();
        break;
      }

      do
      {
        chozadeconcreto->DisplayDptos();
        cout << "1.Agregar trabajador" << endl;
        cout << "2.Eliminar trabajador" << endl;
        cout << "3.Modificar trabajador" << endl;
        cout << "4.Mostrar trabajadores de un departamento" << endl;
        cout << "5.Generar liquidacion de sueldo" << endl;
        cout << "6.Volver al menu" << endl;
        cout << "Seleccione una opcion:";
        cin >> expression2;
        switch (expression2)
        {
        case 1:
        {
          cout << "En que departamento desea ingresar ?(ID): ";
          cin >> key_dpto;
          if (!chozadeconcreto->contains(key_dpto))
          {
            dMsgNotFinded();
            break;
          }
          do
          {
            cin >> trabajador;
            if (!trabajador.verify())
            {
              cout << "Datos incorrectos" << endl;
            }
          } while (!trabajador.verify());

          chozadeconcreto->getDpto(key_dpto).Trabajadores->insertWorker(trabajador);
          break;
        }
        case 2:
        {
          cout << "En que departamento desea eliminar ?(ID): ";
          cin >> key_dpto;
          if (!chozadeconcreto->contains(key_dpto))
          {
            dMsgNotFinded();
            break;
          }

          cin >> trabajador;
          chozadeconcreto->getDpto(key_dpto).Trabajadores->deleteWorker(key_worker);
          break;
        }
        case 3:
        {
          cout << "En que departamento desea modificar ?(ID): ";
          cin >> key_dpto;

          if (!chozadeconcreto->contains(key_dpto))
          {
            dMsgNotFinded();
            break;
          }

          cout << "Numero inicial del rut del trabajador a modificar (12.345.678 sin puntos): ";
          cin >> key_worker;

          if (!chozadeconcreto->getDpto(key_dpto).Trabajadores->contains(key_worker))
          {
            wMsgNotFinded();
            break;
          }

          do
          {
            cin >> trabajador;
            if (!trabajador.verify())
            {
              cout << "Datos incorrectos" << endl;
              cin.ignore();
            }
          } while (!trabajador.verify());

          chozadeconcreto->getDpto(key_dpto).Trabajadores->modifyWorker(key_worker, trabajador);

          break;
        }
        case 4:
        {
          cout << "Que departamento desea mostrar ?(ID): ";
          cin >> key_dpto;

          if (!chozadeconcreto->contains(key_dpto))
          {
            dMsgNotFinded();
            break;
          }
          if (chozadeconcreto->getDpto(key_dpto).Trabajadores->isEmpty())
          {
            wMsgEmpty();
            break;
          }
          chozadeconcreto->DisplayWorkers(key_dpto);
          break;
        }
        case 5:
        {
          cout << "ingrese identificador de de  partamento:";
          cin >> key_dpto;
          if (!chozadeconcreto->contains(key_dpto))
          {
            dMsgNotFinded();
            break;
          }
          if (chozadeconcreto->getDpto(key_dpto).Trabajadores->isEmpty())
          {
            wMsgEmpty();
            break;
          }
          cout << "Numero inicial del rut del trabajador (12.345.678 sin puntos): ";
          cin >> key_worker;
          if (!chozadeconcreto->getDpto(key_dpto).Trabajadores->contains(key_worker))
          {
            wMsgNotFinded();
            break;
          }
          chozadeconcreto->getDpto(key_dpto).Trabajadores->genLiq(key_worker);
          break;
        }
        case 6:
          break;
        default:
          break;
        }
        cin.ignore();
          cin.get();
      system(clear);
      } while (expression2 >= 1 && expression2 <= 5);
      break;
    }
    case 4:
      break;
    default:
      break;
    }
    cin.ignore();
          cin.get();
  system(clear);
  } while (expression >= 1 && expression <= 3);
}

#endif