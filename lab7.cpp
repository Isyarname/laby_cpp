#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

#define rightShift 1

using namespace std;

int modulo(int a, int b)
{
    return a >= 0 ? a % b : (b - abs(a % b)) % b;
}

string wordShift(string inText, int shift = rightShift)
{
    shift = modulo(shift, inText.length());
    string outText = inText.substr(shift);
    outText += inText.substr(0, shift);
    return outText;
}

void Shift(string path, int shift)
{
    string outText;

    ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "\n\nОшибка открытия файла" << endl;
    }
    else
    {
        string word;
        while (!file.eof())
        {
            file >> word;
            word = wordShift(word, rightShift) + " ";
            cout << word;
            outText += word;
        }
    }
    file.close();

    string path2 = path.insert(path.length() - 4, "(2)");
    ofstream file2;
    file2.open(path2);
    if (!file2.is_open())
    {
        cout << "\n\nОшибка открытия файла" << endl;
    }
    else
    {
        file2 << outText;
    }
    file2.close();
}

int main()
{
    setlocale(LC_ALL, "rus");

    string path; //"TextFile1.txt"
    cout << "Введите название файла: ";
    cin >> path;

    Shift(path, rightShift);
    
    return 0;
}