#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//  {Название ценной бумаги; Количество сделок; Объём торгов}.
#include <iostream>
using namespace std;
class Node {
public:
    string key;
    int data1;
    int data2;
    Node* next; 
    Node()
    {
        key = "";
        data1 = 0;
        data2 = 0;
        next = NULL;
    }
    Node(string key1, int data11, int data12)
    {
        key = key1;
        data1 = data11;
        data2 = data12;
    }
};
class CircularLinkedList {
public:
    Node* h; 
    CircularLinkedList()
    {
        h = NULL;
    }
    Node* NodeExists(string k)
    {
        Node* tmp = NULL;
        Node* pointer = h;
        if (pointer == NULL)
        {
            return tmp;
        }
        else {
            do
            {
                if (pointer->key == k)
                {
                    tmp = pointer;
                }
                pointer = pointer->next;
            } while (pointer != h);
            return tmp;
        }
    }
    void AppendNode(Node* newnode)
    {
        setlocale(LC_ALL, "rus");
        if (NodeExists(newnode->key) != NULL)
        {
            cout << "Элемент с названием " << newnode->key;
            cout << " уже существует, его нельзя добавить" << endl;
        }
        else
        {
            if (h == NULL)
            {
                h = newnode;
                newnode->next = h;
            }
            else
            {
                Node* pointer = h;
                while (pointer->next != h)
                {
                    pointer = pointer->next;
                }
                pointer->next = newnode;
                newnode->next = h;
            }
            EndProgramm();
        }
    }
    void DeleteNode(string k) // deleting node 
    {
        Node* pointer = NodeExists(k);
        if (pointer == NULL)
        {
            cout << "Такого элемента не существует" << endl;
        }
        else
        {
            if (pointer == h)
            {
                if (h->next == h)
                {
                    h = NULL;
                }
                else
                {
                    Node* pointer1 = h;
                    while (pointer1->next != h)
                    {
                        pointer1 = pointer1->next;
                    }
                    pointer1->next = h->next;
                    h = h->next;
                }
            }
            else
            {
                Node* tmp = NULL;
                Node* prevpointer = h;
                Node* currentpointer = h->next;
                while (currentpointer != NULL)
                {
                    if (currentpointer->key == k)
                    {
                        tmp = currentpointer;
                        currentpointer = NULL;
                    }
                    else
                    {
                        prevpointer = prevpointer->next;
                        currentpointer = currentpointer->next;
                    }
                }
                prevpointer->next = tmp->next;
            }
        }
    }
    void UpdateNode(int newdata1, int newdata2) 
    {
        setlocale(LC_ALL, "rus");
        Node* pointer = h;
        if (h != NULL) {
            do {
                pointer->data1 = newdata1;
                pointer->data2 = newdata2;
                pointer = pointer->next;
            } while (pointer != h);
            cout << "Значения обновлены" << endl << endl;
            EndProgramm();
        }
        else
        {
            cout << "Список пуст" << endl << endl;
        }
    }
    void DisplayList()
    {
        setlocale(LC_ALL, "rus");
        if (h == NULL)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            cout << endl;
            Node* tmp = h;
            do
            {
                cout << "[" << tmp->key << ", " << tmp->data1 << ", " << tmp->data2 << "] ----> ";
                
                tmp = tmp->next;
            } while (tmp != h);
        }
        cout << endl << endl;
        EndProgramm();
    }
    void DeleteAll(int data, int c) {
        setlocale(LC_ALL, "rus");
        if (h == NULL)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            Node* tmp = h;
            do
            {
                if ((c == 1 and tmp->data1 == data) or (c == 2 and tmp->data2 == data)) {
                    DeleteNode(tmp->key);
                }
                tmp = tmp->next;
            } while (tmp != h);
        }
        EndProgramm();
        cout << "Операция завершена" << endl << endl;
    }
    void EndProgramm() {
        setlocale(LC_ALL, "rus");
        ofstream fout("laba6.txt");
        if (h == NULL)
        {
            cout << "Список пуст" << endl;
        }
        else
        {
            Node* tmp = h;
            do
            {
                fout << tmp->key << " " << tmp->data1 << " " << tmp->data2 << " ";

                tmp = tmp->next;
            } while (tmp != h);
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    CircularLinkedList c;
    int op;
    string keyvalue{};
    string kvalue{};
    int datavalue1,datavalue2, datavalue;

    ifstream in("laba6.txt");
    string Name;
    if (!in.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        while (!in.eof())
        {
            Node* node1 = new Node();
            in >> Name;
            in >> datavalue1;
            in >> datavalue2;
            node1->key = Name;
            node1->data1 = datavalue1;
            node1->data2 = datavalue2;
            c.AppendNode(node1);
        }
    }
    in.close();

    do
    {
        cout << "Введите номер, чтобы выполнить операцию с кольцевым однонаправленным списком" << endl;
        cout << "1 -- Добавить элемент в конец" << endl;
        cout << "2 -- Печать всех элементов" << endl;
        cout << "3 -- Удаление всех элементов равных определенному значению" << endl;
        cout << "4 -- Присвоение всем элементам одного значения" << endl;
        cout << "Буквы или 0 -- Завершить работу" << endl;
        cout << endl;
        cin >> op;
        Node* node1 = new Node();
        switch (op) {
        case 0:
            cout << "Завершение работы" << endl;
            break;
        case 1:
            cout << "Введите название ценной бумаги НА АНГЛИЙСКОМ ЯЗЫКЕ" << endl;
            cin >> keyvalue;
            cout << "Введите количество сделок (целое число)" << endl;
            cin >> datavalue1;
            cout << "Введите объем торгов (целое число)" << endl;
            cin >> datavalue2;
            node1->key = keyvalue;
            node1->data1 = datavalue1;
            node1->data2 = datavalue2;
            c.AppendNode(node1);
            cout << "Операция завершена" << endl << endl;
            break;
        case 2:
            c.DisplayList();
            break;
        case 3:
            cout << "Будем удалять элементы по количеству сделок или объему торгов? " << endl;
            cout << "1 -- сделок, 2 -- торгов" << endl;
            int a;
            cin >> a;
            if (a == 1) {
                cout << "Введите количество сделок, элементы с которым нужно удалить " << endl;
                cin >> datavalue;
                c.DeleteAll(datavalue, 1);
            }
            else {
                if (a == 2) {
                    cout << "Введите объем торгов, элементы с которым нужно удалить " << endl;
                    cin >> datavalue;
                    c.DeleteAll (datavalue, 2);
                }
                else {
                    cout << "Ошибка ввода" << endl;
                }
            }
            break;
        case 4:
            cout << "Введите новое количество сделок (целое число)" << endl;
            cin >> datavalue1;
            cout << "Введите новый объем торгов (целое число)" << endl;
            cin >> datavalue2;
            c.UpdateNode(datavalue1, datavalue2);
            break;
        default:
            cout << "Ошибка ввода" << endl;
        }
    } 
    while (op != 0);
    c.EndProgramm();
    return 0;
}