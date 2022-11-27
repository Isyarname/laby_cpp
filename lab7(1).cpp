#include <fstream>
#include <iostream>
#include <string>
using namespace std;
string reverse(string const& word) {
    string rev;
    for (string::const_reverse_iterator it = word.crbegin(); it != word.crend(); ++it)
        rev = rev.append(1, *it);
    return rev;
}
void reiw(string const& path, int p = 2, int i = 2)
{
    fstream file(path);
    string word, out_text;
    file >> out_text;
    while (!file.eof())
    {
        file >> word;
        out_text += ' ' + (i++ % p ? word : reverse(word));
    }
    file.seekg(0, ios_base::beg);
    file << out_text;
}
void main()
{
    setlocale(LC_ALL, "rus");
    string path = "TextFile1.txt";
    reiw(path);
}