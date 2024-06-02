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
    cout << "�������� ��������:" << endl;
    cout << "1. �������� '������� �� �������'" << endl;
    cout << "2. �������� '������� �� �������'" << endl;
    cout << "3. �������� '������� �� ��������������� �������'" << endl;
    cout << "4. �������� '������� �� ��������'" << endl;
    cout << "5. �������� '���-�������'" << endl;
    cout << "6. ������� ������� �� �������" << endl;
    cout << "7. �������� ������� � �������" << endl;
    cout << "8. �������� ������������� ����� �� ���� ��������" << endl;
    cout << "0. �����" << endl;
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
            cout << "������� �� �������" << endl;
            B.Print_Arr();
            break;
        case 2:
            cout << "������� �� �������" << endl;
            A.print();
            break;
        case 3:
            cout << "������� �� ��������������� �������" << endl;
            C.Print_Arr();
            break;
        case 4:
            cout << "������� �� ��������" << endl;
            D.print();
            break;
        case 5:
            cout << "���-�������" << endl;
            E.print();
            break;
        case 6:
            int tableChoice;
            cout << "�������� ������� ��� �������� ��������:" << endl;
            cout << "1. ������� �� �������" << endl;
            cout << "2. ������� �� �������" << endl;
            cout << "3. ������� �� ��������������� �������" << endl;
            cout << "4. ������� �� ��������" << endl;
            cout << "5. ���-�������" << endl;
            cin >> tableChoice;
            cout << "������� ���� ��� ��������: ";
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
                cout << "�������� ����� �������." << endl;
                break;
            }
            break;
        case 7:
            cout << "�������� ������� ��� ���������� ��������:" << endl;
            cout << "1. ������� �� �������" << endl;
            cout << "2. ������� �� �������" << endl;
            cout << "3. ������� �� ��������������� �������" << endl;
            cout << "4. ������� �� ��������" << endl;
            cout << "5. ���-�������" << endl;
            cin >> tableChoice;
            cout << "������� ���� ��� ����������: ";
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
                cout << "�������� ����� �������." << endl;
                break;
            }
            break;
        case 8:
            cout << "������� ���� ��� �������� �������������: ";
            cin >> key;
            cout << "������������� ����� '" << key << "' �� ���� ��������:" << endl;
            cout << "������� �� �������: " << B.efect(key) << endl;
            cout << "������� �� �������: " << A.efect(key) << endl;
            cout << "������� �� ��������������� �������: " << C.efect(key) << endl;
            cout << "������� �� ��������: " << D.effect(key) << endl;
            cout << "���-�������: " << E.effect(key) << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "�������� �����. ���������� �����." << endl;
            break;
        }
    }

    return 0;
}
