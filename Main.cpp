#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//  1) впорядковані за англійською абеткою; 
void SortUsingEnglishAlphabet(vector<char>& Vector, vector<int>& ArrayInt) {
    for (int i = 0; i < Vector.size() - 1; i++) {
        for (int j = i + 1; j < Vector.size(); j++) {
            if (Vector[i] > Vector[j]) {
                swap(Vector[i], Vector[j]);
                swap(ArrayInt[i], ArrayInt[j]);
            }
        }
    }
}
// 2) впорядковані за спаданням кількості.
void SortbyDescendingNumbers(vector<char>& Vector, vector<int>& ArrayInt) {
    for (int i = 0; i < Vector.size() - 1; i++) {
        for (int j = i + 1; j < Vector.size(); j++) {
            if (ArrayInt[i] > ArrayInt[j]) {
                swap(Vector[i], Vector[j]);
                swap(ArrayInt[i], ArrayInt[j]);
            }
        }
    }
}

bool SameChar(vector<char> Vector, char Char, int& ArrayIntindex) {
    for (int i = 0; i < (int)Vector.size(); i++) {
        if (Vector[i] == Char) {
            ArrayIntindex = i;
            return true;
        }
    }
    return false;
}

void coutArr(vector<char> Vector, vector<int> ArrayInt) {
    for (int i = 0; i < Vector.size(); i++)
        cout << Vector[i] << " - " << ArrayInt[i] << "\n";
}

int main() {
    ifstream file("file.txt");
    vector <char> Array{};
    vector <int> ArrayInt{};
    string fileInString, temp;
    int ArrayIntIndex;

    if (file.is_open()) {
        while (getline(file, temp)) {
            fileInString += temp + '\n';
        }
        for (int i = 0; i < fileInString.size(); i++) {
            if (SameChar(Array, fileInString[i], ArrayIntIndex)) {
                ArrayInt[ArrayIntIndex]++;
            }
            else if (fileInString[i] != ' ' && fileInString[i] != '\n') {
                Array.push_back(fileInString[i]);
                ArrayInt.push_back(1);
                //cout << fileInString[i];
            }
        }
        file.close();
    }
    cout << "Your file: \n"; cout << fileInString;
    cout << "1. Sort Using English alphabet\n";
    cout << "2. Sort by descending numbers\n";
x:
    cout << "->";  cin >> temp;

    if (temp == "1") {
        SortUsingEnglishAlphabet(Array, ArrayInt);
        coutArr(Array, ArrayInt);
    }
    else if (temp == "2") {
        SortbyDescendingNumbers(Array, ArrayInt);
        coutArr(Array, ArrayInt);
    }
    else {
        cout << "Wrong Option\n";
        goto x;
    }

    return 0;
}

/*
Cтворіть файл з даними:
XWOTLYQVUTZYXWOTZYQVUTSXWVNZYXPUMZRWVUMYXWOTYQVU
TSXWVNZYXPATZRWVUMYXWOTZYQVUTSXWVNZYXPUBZ

Зчитайте дані з файла в оперативну пам’ять. Використовуючи методи і
структури даних з бібліотеки стандартних шаблонів, обчисліть скільки
разів кожен окремий символ стрічається в такому наборі даних.
Зробіть дві функції, які би виводили результати на екран:

1) впорядковані за англійською абеткою;
2) впорядковані за спаданням кількості.

В головній функції зробіть меню, де користувач вибиратиме яким
способом виводити дані на екран.
*/
