#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
//рабочие: find_node(), get(), init(), create_Node(), 
//нерабочие: pop()
struct Node {
    int key;
    string value;
    Node* less;
    Node* more;
    Node* parent;
};
struct Dict {
    Node* Head;
};
Node* create_Node(int key, string value)
{
    Node* temp = new Node;
    temp->more = NULL;
    temp->less = NULL;
    temp->key = key;
    temp->value = value;
    return temp;
}
void init(Dict& A)
{
    A.Head = NULL;
}
Node* find_Node(Node* it, int key)
{
    if (it->key == key)
        return it;
    else if (key < it->key && it->less != NULL)
        return find_Node(it->less, key);
    else if (key > it->key && it->more != NULL)
        return find_Node(it->more, key);
    return NULL;
}
Node* find_Node(Dict& A, int key)
{
    if (A.Head)
        return find_Node(A.Head, key);
    return NULL;
}
Node* find_parent(Node* it, const int& key)
{
    if (key < it->key && it->less != NULL)
        return find_parent(it->less, key);
    else if (key > it->key && it->more != NULL)
        return find_parent(it->more, key);
    else if (it->key != key)
        return it;
    return NULL;
}
Node* find_parent(Dict& A, int key)
{
    if (A.Head)
        return find_parent(A.Head, key);
    return NULL;
}
bool insert(Dict& A, Node* temp)
{
    Node* parent = find_parent(A.Head, temp->key);
    if (temp->key < parent->key)
    {
        parent->less = temp;
        return true;
    }
    else if (temp->key > parent->key)
    {
        parent->more = temp;
        return true;
    }
    return false;
}
string insert(Dict& A, int key, string value)
{
    Node* temp = create_Node(key, value);
    if (A.Head == NULL)
    {
        A.Head = temp;
        return "Элемент (" + to_string(key) + ": " + value + ") добавлен";
    }
    else if (find_Node(A.Head, temp->key))
        return "Такой ключ уже есть";
    else if (insert(A, temp))
        return "Элемент (" + to_string(key) + ": " + value + ") добавлен";
    return "Что-то пошло не так";
}
void add_Node(Node* it, string& text)
{
    if (it->less != NULL)
        add_Node(it->less, text);
    if (it->more != NULL)
        add_Node(it->more, text);
    text = to_string(it->key) + ": " + it->value + ", " + text;
}
void print(const Dict& A)
{
    if (A.Head) {
        string text;
        add_Node(A.Head, text);
        cout << text;
    }
    else
        cout << "Пусто";
}
string pop(Dict& A, Node* it)
{
    Node* tless = it->less;
    Node* tmore = it->more;
    string value = it->value;
    int key = it->key;
    if (it == A.Head)
    {
        delete A.Head;
        A.Head = tmore;
        insert(A, tless);
        return "Элемент (" + to_string(key) + ": " + value + ") удалён";
    }
    Node* parent = find_parent(A, key);
    if (parent)
    {
        if (key < parent->key)
        {
            delete parent->less;
            parent->less = tmore;
            insert(A, tless);
            return "Элемент (" + to_string(key) + ": " + value + ") удалён";
        }
        else if (key > parent->key)
        {
            delete parent->more;
            parent->more = tless;
            insert(A, tmore);
            return "Элемент (" + to_string(key) + ": " + value + ") удалён";
        }
        return "Очень странно (pop)";
    }
    return "Нет родителя (pop)";
}
string pop(Dict& A, int key)
{
    if (A.Head == NULL)
        return "Пусто";
    Node* it = find_Node(A, key);
    if (it)
        return pop(A, it);
    return "Нет такого ключа!";
}
void delete_Node(Node* it)
{
    if (it->less != NULL)
        delete_Node(it->less);
    if (it->more != NULL)
        delete_Node(it->more);
    delete it;
}
string delete_Dict(Dict& A)
{
    if (A.Head)
        delete_Node(A.Head);
    return "Dict is empty";
}
string get(Dict& A, int key)
{
    if (A.Head)
    {
        Node* it = find_Node(A.Head, key);
        if (it->key != key)
            return "Нет такого ключа!";
        return it->value;
    }
    return "Пусто";
}
string rev(string const& word) {
    string rev;
    for (string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
        rev = rev.append(1, *it);
    return rev;
}
string reverse(Dict& A, int key)
{
    if (A.Head)
    {
        Node* it = find_Node(A.Head, key);
        if (it->key != key)
            return "Нет такого ключа!";
        it->value = rev(it->value);
        return it->value;
    }
    return "Пусто";
}
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int vybor;
    Dict dict;
    int key;
    string value;
    while (true)
    {
        cout << "Что сделать? (0-завершить программу, 1-инициализировать АС, 2-добавить элемент, 3-вывести АС, 4-вывести элемент, 5-удалить элемент, 6-удалить АС)\n: ";
        cin >> vybor;
        if (vybor == 0)
            return 0;
        else if (vybor == 1)
            init(dict);
        else if (vybor == 2)
        {
            cout << "Введите ключ и значение: ";
            cin >> key >> value;
            cout << insert(dict, key, value) << endl;
        }
        else if (vybor == 3)
        {
            print(dict);
            cout << endl;
        }
        else if (vybor == 4)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << get(dict, key) << endl;
        }
        else if (vybor == 5)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << pop(dict, key) << endl;
        }
        else if (vybor == 6)
            cout << delete_Dict(dict) << endl;
    }
}