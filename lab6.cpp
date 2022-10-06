#include <iostream>
#include <string>
using namespace std;

struct EncryptedMessage {
    string message;
    string key;

    string decrypt() {
        string text;
        unsigned keylen = key.length();
        for (int i = 0; i < message.length(); i++) {
            text += modulo((message[i] - key[i % keylen]), 255) + 1;
        }
        return text;
    }
private:
    int modulo(int a, int b)
    {
        return a >= 0 ? a % b : (b - abs(a % b)) % b;
    }
};

EncryptedMessage init(string text, string key) {
    unsigned keylen = key.length();
    EncryptedMessage em;
    em.key = key;
    for (int i = 0; i < text.length(); i++) {
        em.message += (text[i] + key[i % keylen]) % 255;
    }
    return em;
}

void printEM(EncryptedMessage em) {
    cout << "Зашифрованое сообщение: " << em.message << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    string text, key;
    cout << "Введите сообщение и ключ через пробел: ";
    cin >> text >> key;

    EncryptedMessage em = init(text, key);
    printEM(em);
    string dm = em.decrypt();
    cout << "Расшифрованое сообщение: " << dm << endl;
    cout << "Ключ: " << em.key;

    return 0;
}