#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

void WordCount(vector<string>& words) {
    int letters[33] = { 0 };
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < words.size(); j++) {
            if (words[j][0] == (char)(i + (int)('А')) || words[j][0] == (char)(i + (int)('а'))) {
                letters[i] += 1;
            }
        }
        cout << "Слов на букву '" << (char)(i + (int)('А')) << "': " << letters[i] << endl;
    }
}

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

char down_reg(char letter) {
    char NoRegister = letter;
    if (letter >= 'А' && letter <= 'Я') {
        int temp = letter - 'А';
        NoRegister = temp + 'а';
    }
    return NoRegister;
}

void sort(vector<string>& words) { // сортировка пузырьком по алфавиту
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size() - 1; j++) {
            char NoRegister1 = down_reg(words[j][0]);
            char NoRegister2 = down_reg(words[j + 1][0]);
            if (NoRegister1 > NoRegister2) {
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
    unsigned int start_time = clock(); // начальное время
    sort(words);
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "время: " << (double)search_time / (double)CLOCKS_PER_SEC << " сек";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    cout << col;
    WordCount(words);
    return 0;
}