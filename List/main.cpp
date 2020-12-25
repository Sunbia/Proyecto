#include <iostream>
#include "LinkedList.hpp"
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // Se crea una List
    ListADT<int> *test = new LinkedList<int>;
    unsigned int sw;
    index_t index;
    int element;

    cout << "1.Empty" << endl;
    cout << "2.Size" << endl;
    cout << "3.Get Tail" << endl;
    cout << "4.Get Head" << endl;
    cout << "5.Get by index" << endl;
    cout << "6.Contains element" << endl;
    cout << "7.Add on/before Head" << endl;
    cout << "8.Add on/after Tail" << endl;
    cout << "9.Add by index" << endl;
    cout << "10.Remove by element" << endl;
    cout << "11.Remove Head" << endl;
    cout << "12.Remove Tail" << endl;
    cout << "13.Display List" << endl;
    cout << "14.Exit" << endl;
    do
    {
        cout << "Ingrese una opcion:" << endl;
        cin >> sw;
        switch (sw)
        {
        case 1:
            test->empty() ? cout << "true" << endl : cout << "false" << endl;
            break;
        case 2:
            cout << test->size() << endl;
            break;
        case 3:
            cout << test->get_tail() << endl;
            break;
        case 4:
            cout << test->get_head() << endl;
            break;
        case 5:
            cout << "index:";
            cin >> index;
            cout << test->get(index) << endl;
            break;
        case 6:
            cout << "element:";
            cin >> element;
            test->contains(element) ? cout << "true" << endl : cout << "false" << endl;
            break;
        case 7:
            cout << "element:";
            cin >> element;
            test->addBeforeHead(element);
            break;
        case 8:
            cout << "element:";
            cin >> element;
            test->addAfterTail(element);
            break;
        case 9:
            cout << "element:";
            cin >> element;
            cout << "index:";
            cin >> index;
            test->add(element, index);
            break;
        case 10:
            cout << "element:";
            cin >> element;
            test->remove(element);
            break;
        case 11:
            cout << "elemento a eliminar: " << test->get_head() << endl;
            test->removeHead();
            break;
        case 12:
            cout << "elemento a eliminar:" << test->get_tail() << endl;
            test->removeTail();
            break;
        case 13:
            test->display();
            cout << endl;
            break;
        case 14:
            break;
        default:
            cout << "Seleccione una opcion correcta" << endl;
            break;
        }
    } while (sw > 0 && sw < 14);

    return 0;
}