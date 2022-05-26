#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

void division_into_words(string st, vector<string>& words, int& col) { // делим строку по словам
    string word = "";
    for (int i = 0; i <= st.length(); i++) {
        if (st[i] >= 'А' && st[i] <= 'я') { // если это символ русского алфавита
            word = word + st[i]; // добавляем его к слову
        }
        else if ((st[i] == ' ' || st[i] == '\n') && word != "") {

            col++;
            words.push_back(word); // добавляем слово в вектор слов
            word = "";
        }
    }
}

void sort(vector<string>& words) { // сортировка пузырьком по алфавиту
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size() - 1; j++) {
            if (words[j][0] > words[j + 1][0]) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string line, st;
    int col = 0;
    vector<string> words;
    ifstream fin("Tekst1.txt"); // окрываем файл для чтения
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            st = st + line + '\n';
        }
    }
    fin.close();     // закрываем файл
    division_into_words(st, words, col);
    sort(words);
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    cout << col;
    return 0;
}