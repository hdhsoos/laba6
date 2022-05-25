#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//  {Название ценной бумаги; Количество сделок; Объём торгов}.

#include<iostream>
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
                cout << "Первый элемент добавлен" << endl;
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
                cout << "Элемент добавлен" << endl;
            }
        }
    }
    void DeleteNode(int datavalue, int c)
    {
        setlocale(LC_ALL, "rus");
        Node* pointer = h;
        if (h != NULL) {
            do {
                if (c == 1 and pointer->data1 == datavalue) {
                    if (pointer == h) {
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
                    //else {
                    //    Node* tmp = NULL;
                    //    Node* prevpointer = h;
                    //    Node* currentpointer = h->next;
                    //    while (currentpointer != NULL)
                    //    {
                    //        if (currentpointer->data1 == datavalue)
                    //        {
                     //           tmp = currentpointer;
                     //           currentpointer = NULL;
                    //        }
                    //        else
                    //        {
                    //            prevpointer = prevpointer->next;
                    //            currentpointer = currentpointer->next;
                    //        }
                    //    }
                    //    prevpointer->next = tmp->next;
                   // }
                }
                else {
                    if (pointer == h) {
                        if (c == 2 and datavalue == pointer->data2) {
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
                    }
                    else {
                        Node* tmp = NULL;
                        Node* prevpointer = h;
                        Node* currentpointer = h->next;
                        while (currentpointer != NULL)
                        {
                            if (currentpointer->data2 == datavalue)
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
                pointer = pointer->next;
            } while (pointer != h);
            cout << "Элементы удалены";
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
            cout << "Значения обновлены";
        }
        else
        {
            cout << "Список пуст" << endl;
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
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    CircularLinkedList c;
    int op;
    string keyvalue{};
    string kvalue{};
    int datavalue1,datavalue2, datavalue;
    do
    {
        cout << "Введите номер, чтобы выполнить операцию с кольцевым однонаправленным списком" << endl;
        cout << "1 -- Добавить элемент в конец" << endl;
        cout << "2 -- Печать всех элементов" << endl;
        cout << "3 -- Удаление всех элементов равных определенному значению" << endl;
        cout << "4 -- Присвоение всем элементам одного значения" << endl;
        cout << "Любая другая -- Завершить работу" << endl;
        cout << endl;
        cin >> op;
        Node* node1 = new Node();
        switch (op) {
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
                c.DeleteNode(datavalue, 1);
            }
            else {
                if (a == 2) {
                    cout << "Введите объем торгов, элементы с которым нужно удалить " << endl;
                    cin >> datavalue;
                    c.DeleteNode(datavalue, 2);
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
    return 0;
}