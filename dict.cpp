#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
//рабочие: find_node(), get(), print(), reverse(), delete_Dict(), insert(), find_new_parent()
//нерабочие: pop(), pop2()
struct Node {
    int key;
    string value;
    Node* less;
    Node* more;
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
Node* find_Node(Dict& A, int key)
{
    if (A.Head)
        return _find_Node(A.Head, key);
    return NULL;
}
string get(Dict& A, int key)
{
    Node* it = find_Node(A, key);
    if (it)
        return it->value;
    return "Нет такого ключа!";
}
string get_children(Dict& A, int key)
{
    Node* it = find_Node(A, key);
    if (it == NULL)
        return "Нет такого ключа!";
    if (it->more == NULL && it->less == NULL)
        return "Нет дочерних элемментов";
    string children;
    if (it->less)
        children += it->less->value + ", ";
    if (it->more)
        children += it->more->value;
    return children;
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
    if (A.Head == NULL)
        cout << "Пусто";
    else
    {
        string text;
        _add_branch(A.Head, text);
        cout << text;
    }

}
string reverse(string const& word) {
    string rev;
    for (string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
        rev = rev.append(1, *it);
    return rev;
}
string reverse(Dict& A, int key)
{
    Node* it = find_Node(A, key);
    if (it == NULL)
        return "Нет такого ключа!";
    it->value = reverse(it->value);
    return it->value;
}
void _delete_Node(Node* it)
{
    if (it->less)
        _delete_Node(it->less);
    if (it->more)
        _delete_Node(it->more);
    delete it;
}
string delete_Dict(Dict& A)
{
    if (A.Head == NULL)
        return "Пусто";
    _delete_Node(A.Head);
    A.Head = NULL;
}
Node* _find_parent(Node* it, const int& key)
{
    if (key < it->key && it->less)
    {
        if (it->less->key == key)
            return it;
        return _find_parent(it->less, key);
    }
    else if (key > it->key && it->more)
    {
        if (it->more->key == key)
            return it;
        return _find_parent(it->more, key);
    }
}
Node* find_parent(Dict& A, int key)
{
    if (A.Head == NULL)
        return NULL;
    return _find_parent(A.Head, key);
}
Node* _find_new_parent(Node* it, const int& key)
{
    if (key < it->key && it->less)
        return _find_new_parent(it->less, key);
    else if (key > it->key && it->more)
        return _find_new_parent(it->more, key);
    return it;
}
Node* find_new_parent(Dict& A, int key)
{
    if (A.Head == NULL)
        return NULL;
    return _find_new_parent(A.Head, key);
}
bool insert(Dict& A, Node* it)
{
    Node* parent = find_new_parent(A, it->key);
    if (it->key < parent->key)
    {
        parent->less = it;
        return true;
    }
    else if (it->key > parent->key)
    {
        parent->more = it;
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
    if (find_Node(A, key))
        return "Такой ключ уже есть";
    if (insert(A, temp))
        return "Элемент (" + to_string(key) + ": " + value + ") добавлен";
    return "Что-то пошло не так";
}

Node* _find_min(Node* it)
{
    if (it->less)
        return _find_min(it->less);
    return it;
}
Node* find_min(Node* it)
{
    if (it)
        return _find_min(it);
    return NULL;
}
Node* _find_max(Node* it)
{
    if (it->more)
        return _find_max(it->more);
    return it;
}
Node* find_max(Node* it)
{
    if (it)
        return _find_max(it);
    return NULL;
}


string _pop_Node_without_children(Dict& A, Node* it)
{
    int key = it->key;
    string value = it->value;
    cout << value << endl;
    Node* parent = find_parent(A, it->key);
    delete it;
    it = NULL;
    if (parent)
    {
        if (key > parent->key)
            parent->more = it;
        else if (key < parent->key)
            parent->less = it;
        else
            return "Ошибка (pop Node without children)";
    }
    else
        A.Head = it;
    return "Элемент (" + to_string(key) + ": " + value + ") удалён";
}
string _pop_Node_with_one_child(Dict& A, Node* it)
{
    int key = it->key;
    string value = it->value;
    Node* parent = find_parent(A, it->key);
    Node* child = it->more ? it->more : it->less;
    delete it;
    it = child;
    if (parent)
    {
        if (key > parent->key)
            parent->more = it;
        else if (key < parent->key)
            parent->less = it;
        else
            return "Ошибка (pop Node_ ith one child)";
    }
    else
        A.Head = it;
    return "Элемент (" + to_string(key) + ": " + value + ") удалён";
}
string _pop_Node_with_two_children(Dict& A, Node* it)
{
    int key = it->key;
    string value = it->value;
    Node* tmore = it->more;
    Node* tless = it->less;
    Node* parent = find_parent(A, it->key);
    Node* min_more = find_min(it->more);
    Node* min_more_parent = find_parent(A, min_more->key);
    if (min_more->more == NULL)
    {
        delete it;
        it = min_more;
        if (parent)
        {
            if (key > parent->key)
                parent->more = it;
            else if (key < parent->key)
                parent->less = it;
            else
                return "Ошибка (pop Node_ ith one child)";
        }
        else
            A.Head = it;
        it->less = tless;
        it->more = tmore;
    }
    else
    {

    }
    return "Не доделано";
}
string pop(Dict& A, int key)
{
    Node* it = find_Node(A, key);
    if (it == NULL)
        return "Нет такого ключа!";
    if (it->less && it->more)
        return _pop_Node_with_two_children(A, it);
    if (it->more || it->less)
        return _pop_Node_with_one_child(A, it);
    return _pop_Node_without_children(A, it);
}
string pop2(Dict& A, int key)
{
    Node* it = find_Node(A, key);
    if (it == NULL)
        return "Нет такого ключа!";
    Node* tless = it->less;
    Node* tmore = it->more;
    Node* child = NULL;
    string value = it->value;
    Node* parent = find_parent(A, key);
    delete it;
    if (tmore)
    {
        it = tmore;
        child = tless;
    }
    else if (tless)
    {
        it = tless;
        child = tmore;
    }
    else
        it = NULL;
    if (parent)
    {
        if (key < parent->key)
            parent->less = it;
        else
            parent->more = it;
    }
    else
    {
        A.Head = it;
    }
    if (child)
        insert(A, child);
    return "Элемент (" + to_string(key) + ": " + value + ") удалён";
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    Dict dict;
    int key;
    string value;
    while (true)
    {
        cout << "Что сделать?\n(0-завершить программу, 1-инициализировать словарь, 2-добавить элемент," << endl;
        cout << "3-вывести словарь, 4-перевернуть элемент, 5-вывести элемент, 6-удалить элемент, 7-удалить словарь)" << endl;
        cout << ": ";
        cin >> choice;
        if (choice == 0)
            return 0;
        else if (choice == 1)
            init(dict);
        else if (choice == 2)
        {
            cout << "Введите ключ и значение: ";
            cin >> key >> value;
            cout << insert(dict, key, value) << endl << endl;
        }
        else if (choice == 3)
        {
            print(dict);
            cout << endl << endl;
        }
        else if (choice == 4)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << reverse(dict, key) << endl << endl;
        }
        else if (choice == 5)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << get(dict, key) << endl << endl;
        }
        else if (choice == 6)
        {
            cout << "Введите ключ: ";
            cin >> key;
            cout << pop(dict, key) << endl << endl;
        }
        else if (choice == 7)
            cout << delete_Dict(dict) << endl << endl;
        else if (choice == 8)
        {

            //cout <<  << endl << endl;
        }
    }
}