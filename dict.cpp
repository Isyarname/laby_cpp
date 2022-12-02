#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
//рабочие: create_Node(), init(), find_node(), get(), get_children(), _add_branch(), print(), reverse(), delete_branch(), delete_Dict(), find_parent(), insert()
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
Node* create_Node(const int& key, const string& value)
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
Node* _find_Node(Node* it, const int& key)
{
    if (it->key == key)
        return it;
    else if (key < it->key && it->less != NULL)
        return _find_Node(it->less, key);
    else if (key > it->key && it->more != NULL)
        return _find_Node(it->more, key);
    return NULL;
}
Node* find_Node(Dict& A, const int& key)
{
    if (A.Head)
        return _find_Node(A.Head, key);
    return NULL;
}
string get(Dict& A, const int& key)
{
    if (A.Head)
    {
        Node* it = find_Node(A, key);
        if (it)
        {
            if (it->key == key)
                return it->value;
            return "key: " + to_string(key) + ", it->key: " + to_string(it->key);
        }
        return "Нет такого ключа!";
    }
    return "Пусто";
}
string get_children(Dict& A, const int& key)
{
    if (A.Head)
    {
        Node* it = find_Node(A, key);
        if (it)
        {
            if (it->key == key)
            {
                string children;
                if (it->less != NULL)
                    children += it->less->value;
                if (it->more != NULL)
                    children += it->more->value;
                return children;
            }
            return "key: " + to_string(key) + ", it->key: " + to_string(it->key);
        }
        return "Нет такого ключа!";
    }
    return "Пусто";
}
void _add_branch(Node* it, string& text)
{
    if (it->less != NULL)
        _add_branch(it->less, text);
    if (it->more != NULL)
        _add_branch(it->more, text);
    text = to_string(it->key) + ": " + it->value + ", " + text;
}
void print(const Dict& A)
{
    if (A.Head) {
        string text;
        _add_branch(A.Head, text);
        cout << text;
    }
    else
        cout << "Пусто";
}
string reverse(string const& word) {
    string rev;
    for (string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
        rev = rev.append(1, *it);
    return rev;
}
string reverse(Dict& A, const int& key)
{
    Node* it = find_Node(A, key);
    if (it)
    {
        it->value = reverse(it->value);
        return it->value;
    }
    return "Нет такого ключа!";
}
void _delete_branch(Node* it)
{
    if (it->less != NULL)
        _delete_branch(it->less);
    if (it->more != NULL)
        _delete_branch(it->more);
    delete it;
}
string delete_Dict(Dict& A)
{
    if (A.Head)
    {
        _delete_branch(A.Head);
        A.Head = NULL;
    }
    return "Пусто";
}
Node* _find_parent(Node* it, const int& key)
{
    if (key < it->key && it->less != NULL)
        return _find_parent(it->less, key);
    else if (key > it->key && it->more != NULL)
        return _find_parent(it->more, key);
    else if (it->key != key)
        return it;
    return NULL;
}
Node* find_parent(Dict& A, const int& key)
{
    if (A.Head)
        return _find_parent(A.Head, key);
    return NULL;
}
bool insert(Dict& A, Node* temp)
{
    Node* parent = find_parent(A, temp->key);
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
string insert(Dict& A, const int& key, const string& value)
{
    Node* temp = create_Node(key, value);
    if (A.Head == NULL)
    {
        A.Head = temp;
        return "Элемент (" + to_string(key) + ": " + value + ") добавлен";
    }
    else if (find_Node(A, temp->key))
        return "Такой ключ уже есть";
    else if (insert(A, temp))
        return "Элемент (" + to_string(key) + ": " + value + ") добавлен";
    return "Что-то пошло не так";
}

string pop(Dict& A, Node* it)
{
    return "Не доделано";
}
string pop(Dict& A, const int& key)
{
    if (A.Head == NULL)
        return "Пусто";
    Node* it = find_Node(A, key);
    if (it)
        return pop(A, it);
    return "Нет такого ключа!";
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
        cout << "Что сделать?\n(0-завершить программу, 1-инициализировать словарь, 2-добавить элемент," << endl;
        cout << "3-вывести словарь, 4-перевернуть элемент, 5-вывести элемент, 6-удалить элемент, 7-удалить словарь)" << endl;
        cout << ": ";
        cin >> vybor;
        if (vybor == 0)
            return 0;
        else if (vybor == 1)
            init(dict);
        else if (vybor == 2)
        {
            cout << "Введите ключ и значение: ";
            cin >> key >> value;
            cout << insert(dict, key, value) << endl << endl;
        }
        else if (vybor == 3)
        {
            print(dict);
            cout << endl << endl;
        }
        else if (vybor == 4)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << reverse(dict, key) << endl << endl;
        }
        else if (vybor == 5)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << get(dict, key) << endl << endl;
        }
        else if (vybor == 6)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << pop(dict, key) << endl << endl;
        }
        else if (vybor == 7)
            cout << delete_Dict(dict) << endl << endl;
        else if (vybor == 8)
        {

            //cout <<  << endl << endl;
        }
    }
}