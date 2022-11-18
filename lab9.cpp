#include <iostream>
#include <Windows.h>

using namespace std;

struct Node {
    double data;
    Node* next;
};

struct Fifo {
    Node* Head;
};

Node* create_Node(double a = 0.0)
{
    Node* temp;
    temp = new Node;
    temp->next = NULL;
    temp->data = a;
    return temp;
}

void init(Fifo& A)
{
    A.Head = NULL;
}

void push_back(Fifo& A, double data = 0.0)
{
    Node* temp = create_Node(data);
    if (A.Head == NULL)
        A.Head = temp;
    else
    {
        Node* it = A.Head;
        while (it->next != NULL)
        {
            it = it->next;
        }
        it->next = temp;
    }
}

void print(const Fifo& A)
{
    if (A.Head) {
        Node* it = A.Head;
        while (it != NULL) {
            cout << it->data << " ";
            it = it->next;
        }
    }
    else
        cout << "Fifo is empty!";
    cout << endl << endl;
}

double top(const Fifo& A)
{
    if (!A.Head)
        return 0;
    return A.Head->data;
}

void pop(Fifo& A)
{
    if (A.Head)
    {
        Node* temp = A.Head->next;
        delete A.Head;
        A.Head = temp;
    }
}

void delete_Fifo(Fifo& A)
{
    while (A.Head)
        pop(A);
    cout << "Fifo is empty\n";
}

void copy(Fifo& A, Fifo& B)
{
    init(B);

    Node* itA = A.Head;
    B.Head = create_Node(itA->data);

    Node* itB = B.Head;
    
    while (itA->next != NULL)
    {
        itA = itA->next;
        itB->next = create_Node(itA->data);
        itB = itB->next;
    }
}

void test()
{
    Fifo A;
    init(A);
    push_back(A, 10.3);
    push_back(A);
    push_back(A, -72);
    print(A);
    pop(A);
    print(A);
    delete_Fifo(A);
}

void add(Fifo& A)
{
    double data = 0.0;
    cout << "Введите значение: ";
    cin >> data;
    push_back(A, data);
    cout << "Элемент " << data << " добавлен \n\n";
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Fifo F[5];
    unsigned i = 0;
    int vybor;

    while (true)
    {
        cout << "Что сделать? (0 - завершить программу, 1 - тест, 2 - создать очередь, \n3 - скопировать очередь, 4 - добавить элемент, 5 - вывести очередь, \n6 - выбрать очередь (0-4), 7 - вывести номер выбранной очереди, 8 - удалить очередь)\n: ";
        cin >> vybor;
        if (vybor == 0)
        {
            return 0;
        }
        else if (vybor == 1)
        {
            test();
            cout << endl << endl;
        }
        else if (vybor == 2)
        {
            init(F[i]);
            cout << endl;
        }
        else if (vybor == 3)
        {
            copy(F[i], F[i + 1]);
            cout << "Очередь " << i << " скопирована в очередь " << i + 1 << endl << endl;
            i += 1;
        }
        else if (vybor == 4)
        {
            add(F[i]);
        }
        else if (vybor == 5)
        {
            print(F[i]);
        }
        else if (vybor == 6)
        {
            cout << "Введите номер очереди: ";
            cin >> i;
            cout << endl << endl;
        }
        else if (vybor == 7)
        {
            cout << i << endl << endl;
        }
        else if (vybor == 8)
        {
            delete_Fifo(F[i]);
            cout << "Очередь " << i << " удалена \n\n";
        }
    }
}