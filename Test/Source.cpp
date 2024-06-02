#include <iostream>
#include <string>
#include "Pair.h"
#include "TList.h"
#include <Windows.h>
#include "Vector.h"
#include "Vector_sort.h"
#include "TTree.h"
#include "Hash_Table.h"
#include <stack>
#include <iomanip>
using namespace std;

void showMenu() {
    cout << "Выберите действие:" << endl;
    cout << "1. Показать 'Таблица на массиве'" << endl;
    cout << "2. Показать 'Таблица на списках'" << endl;
    cout << "3. Показать 'Таблица на отсортированном массиве'" << endl;
    cout << "4. Показать 'Таблица на деревьях'" << endl;
    cout << "5. Показать 'Хэш-таблица'" << endl;
    cout << "6. Удалить элемент из таблицы" << endl;
    cout << "7. Добавить элемент в таблицу" << endl;
    cout << "8. Показать эффективность ключа во всех таблицах" << endl;
    cout << "0. Выход" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    string key;
    TList A;
    Vector B(100);
    Vector_sort C(100);
    TTree D;
    Hash_Table E(35);

    B.Add_Element("RRR");
    B.Add_Element("D");
    B.Add_Element("WW");
    B.Add_Element("BBB");
    B.Add_Element("KKK");
    B.Add_Element("YY");
    B.Add_Element("T");
    B.Add_Element("A");
    B.Add_Element("CC");
    B.Add_Element("HH");
    B.Add_Element("PP");
    B.Add_Element("S");
    B.Add_Element("U");
    B.Add_Element("XX");
    B.Add_Element("ZZZ");
    B.Add_Element("F");
    B.Add_Element("J");
    B.Add_Element("N");
    B.Add_Element("QQQ");
    B.Add_Element("VV");
    B.Add_Element("GG");
    B.Add_Element("GG");
    B.Add_Element("OO");

    A.push_back("RRR");
    A.push_back("D");
    A.push_back("WW");
    A.push_back("BBB");
    A.push_back("KKK");
    A.push_back("YY");
    A.push_back("T");
    A.push_back("A");
    A.push_back("CC");
    A.push_back("HH");
    A.push_back("PP");
    A.push_back("S");
    A.push_back("U");
    A.push_back("XX");
    A.push_back("ZZZ");
    A.push_back("F");
    A.push_back("J");
    A.push_back("N");
    A.push_back("QQQ");
    A.push_back("VV");
    A.push_back("GG");
    A.push_back("GG");
    A.push_back("OO");

    C.Add_Element("RRR");
    C.Add_Element("D");
    C.Add_Element("WW");
    C.Add_Element("BBB");
    C.Add_Element("KKK");
    C.Add_Element("YY");
    C.Add_Element("T");
    C.Add_Element("A");
    C.Add_Element("CC");
    C.Add_Element("HH");
    C.Add_Element("PP");
    C.Add_Element("S");
    C.Add_Element("U");
    C.Add_Element("XX");
    C.Add_Element("ZZZ");
    C.Add_Element("F");
    C.Add_Element("J");
    C.Add_Element("N");
    C.Add_Element("QQQ");
    C.Add_Element("VV");
    C.Add_Element("GG");
    C.Add_Element("GG");
    C.Add_Element("OO");

    D.push_back_tree("RRR");
    D.push_back_tree("D");
    D.push_back_tree("WW");
    D.push_back_tree("BBB");
    D.push_back_tree("KKK");
    D.push_back_tree("YY");
    D.push_back_tree("T");
    D.push_back_tree("A");
    D.push_back_tree("CC");
    D.push_back_tree("HH");
    D.push_back_tree("PP");
    D.push_back_tree("S");
    D.push_back_tree("U");
    D.push_back_tree("XX");
    D.push_back_tree("ZZZ");
    D.push_back_tree("F");
    D.push_back_tree("J");
    D.push_back_tree("N");
    D.push_back_tree("QQQ");
    D.push_back_tree("VV");
    D.push_back_tree("GG");
    D.push_back_tree("GG");
    D.push_back_tree("OO");

    E.add("RRR");
    E.add("D");
    E.add("WW");
    E.add("BBB");
    E.add("KKK");
    E.add("YY");
    E.add("T");
    E.add("A");
    E.add("CC");
    E.add("HH");
    E.add("PP");
    E.add("S");
    E.add("U");
    E.add("XX");
    E.add("ZZZ");
    E.add("F");
    E.add("J");
    E.add("N");
    E.add("QQQ");
    E.add("VV");
    E.add("GG");
    E.add("GG");
    E.add("OO");

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Таблица на массиве" << endl;
            B.Print_Arr();
            break;
        case 2:
            cout << "Таблица на списках" << endl;
            A.print();
            break;
        case 3:
            cout << "Таблица на отсортированном массиве" << endl;
            C.Print_Arr();
            break;
        case 4:
            cout << "Таблица на деревьях" << endl;
            D.print();
            break;
        case 5:
            cout << "Хэш-таблица" << endl;
            E.print();
            break;
        case 6:
            int tableChoice;
            cout << "Выберите таблицу для удаления элемента:" << endl;
            cout << "1. Таблица на массиве" << endl;
            cout << "2. Таблица на списках" << endl;
            cout << "3. Таблица на отсортированном массиве" << endl;
            cout << "4. Таблица на деревьях" << endl;
            cout << "5. Хэш-таблица" << endl;
            cin >> tableChoice;
            cout << "Введите ключ для удаления: ";
            cin >> key;
            switch (tableChoice) {
            case 1:
                B.Delete_Element(key);
                B.Print_Arr();
                break;
            case 2:
                A.delete_node(key);
                A.print();
                break;
            case 3:
                C.Delete_Element(key);
                C.Print_Arr();
                break;
            case 4:
                D.delete_node_tree(key);
                D.print();
                break;
            case 5:
                E.delete_pair(key);
                E.print();
                break;
            default:
                cout << "Неверный выбор таблицы." << endl;
                break;
            }
            break;
        case 7:
            cout << "Выберите таблицу для добавления элемента:" << endl;
            cout << "1. Таблица на массиве" << endl;
            cout << "2. Таблица на списках" << endl;
            cout << "3. Таблица на отсортированном массиве" << endl;
            cout << "4. Таблица на деревьях" << endl;
            cout << "5. Хэш-таблица" << endl;
            cin >> tableChoice;
            cout << "Введите ключ для добавления: ";
            cin >> key;
            switch (tableChoice) {
            case 1:
                B.Add_Element(key);
                B.Print_Arr();
                break;
            case 2:
                A.push_back(key);
                A.print();
                break;
            case 3:
                C.Add_Element(key);
                C.Print_Arr();
                break;
            case 4:
                D.push_back_tree(key);
                D.print();
                break;
            case 5:
                E.add(key);
                E.print();
                break;
            default:
                cout << "Неверный выбор таблицы." << endl;
                break;
            }
            break;
        case 8:
            cout << "Введите ключ для проверки эффективности: ";
            cin >> key;
            cout << "Эффективность ключа '" << key << "' во всех таблицах:" << endl;
            cout << "Таблица на массиве: " << B.efect(key) << endl;
            cout << "Таблица на списках: " << A.efect(key) << endl;
            cout << "Таблица на отсортированном массиве: " << C.efect(key) << endl;
            cout << "Таблица на деревьях: " << D.effect(key) << endl;
            cout << "Хэш-таблица: " << E.effect(key) << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}
