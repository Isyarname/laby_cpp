#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
struct Node {
    int key;
    string value;
    Node* next;
};
struct Map {
    Node* Head;
};
Node* create_Node(int key, string value)
{
    Node* temp;
    temp = new Node;
    temp->next = NULL;
    temp->key = key;
    temp->value = value;
    return temp;
}
void init(Map& A)
{
    A.Head = NULL;
}
Node* find_Node(Map& A, int key)
{
    if (A.Head == NULL)
    {
        return NULL;
        cout << "null";
    }
    Node* it = A.Head;
    do
    {
        if (it->key == key)
            return it;
        it = it->next;
    }
    while (it);
    return NULL;
}
void _insert(Map& A, int key, string value)
{
    Node* temp = create_Node(key, value);
    if (A.Head == NULL)
        A.Head = temp;
    else
    {
        Node* temp_next;
        if (key < A.Head->key)
        {
            temp_next = A.Head;
            A.Head = temp;
            A.Head->next = temp_next;
        }
        else if (key > A.Head->key)
        {
            Node* it = A.Head;
            while (it->next)
            {
                if (it->next->key > key)
                    break;
                it = it->next;
            }
            temp_next = it->next;
            it->next = temp;
            temp->next = temp_next;
        }
        else
            cout << "Такой ключ уже есть!";
    }
}
void print(const Map& A)
{
    if (A.Head) {
        Node* it = A.Head;
        while (it) {
            cout << "(" << it->key << ", " << it->value << "),  ";
            it = it->next;
        }
    }
    else
        cout << "Map is empty!";
    cout << endl << endl;
}
void delete_Map(Map& A)
{
    Node* temp;
    while (A.Head)
    {
        temp = A.Head->next;
        delete A.Head;
        A.Head = temp;
    }
    cout << "Map is empty\n";
}
void insert(Map& A)
{
    int key = 0.0;
    string value;
    cout << "Введите ключ и значение: ";
    cin >> key >> value;
    _insert(A, key, value);
    cout << "Элемент (" << key << ", " << value << ") добавлен \n";
}
string reverse(string const& word) {
    string rev;
    for (string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
        rev = rev.append(1, *it);
    return rev;
}
string reverse(Map& A, int key)
{
    Node* it = find_Node(A, key);
    if (it == NULL)
        return "Нет такого ключа!";
    it->value = reverse(it->value);
    return it->value;
}
string get(Map& A)
{
    int key;
    cout << "Введите ключ: ";
    cin >> key;
    Node* it = find_Node(A, key);
    if (it)
        return it->value;
    return "Нет такого ключа";
}
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Map M;
    unsigned i = 0;
    int vybor;
    while (true)
    {
        cout << "Что сделать? (1-инициализировать, 2-добавить элемент, 3-найти элемент, 4-вывести список, 5-удалить список) : ";
        cin >> vybor;
        if (vybor == 0)
        {
            return 0;
        }
        else if (vybor == 1)
        {
            init(M);
            cout << endl;
        }
        else if (vybor == 2)
        {
            insert(M);
            cout << endl;
        }
        else if (vybor == 3)
        {
            cout << get(M) << endl << endl;
        }
        else if (vybor == 4)
        {
            print(M);
        }
        else if (vybor == 5)
        {
            delete_Map(M);
            cout << endl;
        }
    }
}