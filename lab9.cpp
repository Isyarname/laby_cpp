#include <iostream>
#include <Windows.h>
using namespace std;
struct Node
{
    double data;
    Node* next;
};
struct Queue
{
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
void init(Queue& A)
{
    A.Head = NULL;
}
void push_back(Queue& A, double data = 0.0)
{
    Node* temp = create_Node(data);
    if (A.Head == NULL)
        A.Head = temp;
    else
    {
        Node* it = A.Head;
        while (it->next)//(*it).next
        {
            it = it->next;
        }
        it->next = temp;
    }
}
void print(const Queue& A)
{
    if (A.Head)
    {
        Node* it = A.Head;
        while (it != NULL) {
            cout << it->data << " ";
            it = it->next;
        }
    }
    else
        cout << "Пусто!!!!!!!!!!!!!1111одинодинодин11!11!";
    cout << endl << endl;
}
double top(const Queue& A)
{
    if (!A.Head)//A.Head != 0
        return 0;
    return A.Head->data;
}
void pop(Queue& A)
{
    if (A.Head)
    {
        Node* temp = A.Head->next;
        delete A.Head;
        A.Head = temp;
    }
}
void delete_Queue(Queue& A)
{
    while (A.Head)
        pop(A);
    cout << "Пусто!!!!!!!!!!!!!1111одинодинодин11!11!\n";
}
void copy(Queue& A, Queue& B)
{
    init(B);
    Node* itA = A.Head;
    B.Head = create_Node(itA->data);
    Node* itB = B.Head;
    while (itA->next)
    {
        itA = itA->next;
        itB->next = create_Node(itA->data);
        itB = itB->next;
    }
}
void test()
{
    Queue A;
    init(A);
    push_back(A, 10.3);
    push_back(A);
    push_back(A, -72);
    print(A);
    pop(A);
    print(A);
    delete_Queue(A);
}
void add(Queue& A)
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
    Queue Q[5];
    int queue_index = 0;
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
            init(Q[queue_index]);
            cout << endl;
        }
        else if (vybor == 3)
        {
            copy(Q[queue_index], Q[queue_index + 1]);
            cout << "Очередь " << queue_index << " скопирована в очередь " << queue_index + 1 << endl << endl;
            ++queue_index;
        }
        else if (vybor == 4)
        {
            add(Q[queue_index]);
        }
        else if (vybor == 5)
        {
            print(Q[queue_index]);
        }
        else if (vybor == 6)
        {
            cout << "Введите номер очереди: ";
            cin >> queue_index;
            cout << endl << endl;
        }
        else if (vybor == 7)
        {
            cout << queue_index << endl << endl;
        }
        else if (vybor == 8)
        {
            delete_Queue(Q[queue_index]);
            cout << "Очередь " << queue_index << " удалена \n\n";
        }
    }
}