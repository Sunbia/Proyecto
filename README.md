# La Choza de Concreto

## Integrantes:
- David
- Cristobal
- Rodrigo

# Motivación

En  este  proyecto  utilizará  de  manera  práctica  los ADT vistos  en  clases  (List,  Stack,Queue, Hash Table o Tree) y utilizará las herramientas vistas a comienzo del curso (Tiempo de ejecución y complejidad espacial) para decidir cuál ADT es más adecuado para el contexto de su problema

# Contexto

La empresa constructora *La Choza de Concreto* le ha encargado el diseño y construcciónde un sistema informático capaz de manejar la información de todos sus trabajadores y el departamento al que cada uno de ellos pertenece. El encargo ha sido realizado a usted debidoa sus conocimientos de estructuras de datos que le permitirán realizar un software eficiente para esta empresa.

# Solución

Las Estructuras ADT que usaremos para el desplegamiento del proyecto seran Listas enlazadas, ya que nos facilitaria el manejo de los departamentos, estos generalmente al estar en poca cantidad el costo de complejidad espacial no importaria mucho y el tiempo de ejecución seria rapido. Y para administrar de forma eficiente a los trabajadores en temas de busqueda e inserción las Tablas Hash nos proporcionan una gran ventaja con su complejidad espacial *O(1)* en su mejor caso y *O(n)* cuando hayan muchas colisiones en un indice de la tabla.

Para implementar las estructuras usamos algunas de las ventajas que nos brinde el lenguaje *C++*. Una de estas son template o plantillas, y sobrecarga de operadores.

Los template nos ayudan a usar cualquier tipo de dato en  `class`, `struct` o función por ejemplo en nuestro caso nos resulto util, ya que podemos ocuparlas a la hora de implementar las estructuras y ocuparlas con los datos de cada trabajador y departamento. 

```cpp
template <class T>
struct node
{
    T data;        
    node<T> *next;  
    node<T> *prev;  
};
/* La variable data es de cualquier tipo, y los punteros next y prev */
```

Pero esto nos lleva a un problema al usar `struct` o `class` en algunas operaciones, por ejemplo cuando queremos buscar un elemento *C++* no nos deja comparar estos
```cpp
template <typename T>
node<T> *LinkedList<T>::find(T element)
{
    node<T> *aux = _head;
    while (aux != nullptr)
    {
        if (aux->data == element) // Se compara el dato del nodo con el dato a encontrar
        {
            return aux;
        }
        aux = aux->next;
    }
}
/* Funcion para buscar un elemento en una Lista enlazada */
```
ya que no existe un operador por defecto que las compare, y ahi es cuando usamos sobrecarga de operadores, que nos permiten hacer que el operador reconosca el tipo de dato y ejecute la funcion que nosotros queramos. Por ejemplo:
```cpp
struct persona
{
  string nombre;
  int edad;

  bool operator==(const persona& data){
  return nombre == data.nombre && edad == data.edad;
  }
}
/* Se crea un struct y se hace una sobrecarga del operador `==` */
```
Entonces cuando queramos comparar dos variables de tipo `persona` se ejecutara la sobrecarga de operador
```cpp
int main()
{
  persona A,B;
  A.nombre = "Andres";
  A.edad = 18;
  A.nombre = "Janice";
  A.edad = 15;
  A == B ? cout << "True" : cout << "False";
  return 0;
}
/* Output: False
```