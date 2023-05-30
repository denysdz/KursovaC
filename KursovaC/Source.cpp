#include <iostream>
#include <cstdlib>
#include <string>
#include "RealNumber.h"
#include "ComplexNumber.h"
#include "Vector.h"
#include "Matrix.h"
#include "VectorComplex.h"

using namespace std;

bool isDoubleNumber(const string& s);

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "\t\tКурсова робота\nПрограма для демонстрації класів Дійсне число, Комлексне чиcло,\nМатриця, Вектор, Вектор Комплексних чисел\n";
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Демонстрація роботи класу Real Number\n";
        cout << "2. Демонстрація роботи класу Complex Number\n";
        cout << "3. Демонстрація роботи класу Vector\n";
        cout << "4. Демонстрація роботи класу Matrix\n";
        cout << "5. Демонстрація роботи класу Vector Complex Number\n";
        cout << "6. Демонстрація пізнього зв'язування\n";
        cout << "7. Вихід з програми\n";
        cout << "\nВиберіть пункт меню: ";

        string choiceStr;
        cout << "Виберіть пункт від 1 до 7: ";
        cin >> choiceStr;

        bool isNumber = true;
        for (char c : choiceStr) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber || choiceStr.length() > 1) {
            choice = -1;
        }
        else {
            choice = stoi(choiceStr);
        }

        switch (choice) {
        case 1: {
            cout << endl << "Демонстрація класу Real Number" << endl << endl;

            RealNumber x(0);
            RealNumber y(0);

            try {
                cout << "Введіть перше дійсне число" << endl;
                cin >> x;
                cout << "Введіть друге дійсне число" << endl;
                cin >> y;
            }
            catch (invalid_argument e) {
                cout << "Помилка вводу. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << "Результат операції +: " << (x + y).getValue() << endl;
            cout << "Результат операції -: " << (x - y).getValue() << endl;
            cout << "Результат операції *: " << (x * y).getValue() << endl;
            cout << "Результат операції /: " << (x / y).getValue() << endl;
            cout << "Норма першого числа: " << x.norm() << endl;
            cout << "Норма другого числа: " << y.norm() << endl;

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 2: {
            cout << endl << "Демонстрація класу Complex Number" << endl << endl;

            ComplexNumber complexNumber(0, 0);

            try {
                cout << "Введіть дійсну і уявну частину комплексного числа: ";
                cin >> complexNumber;
            }
            catch (invalid_argument e) {
                cout << "Помилка вводу. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << "Комплексне число: " << complexNumber << endl;
            cout << "Норма комлексного числа: " << complexNumber.norm() << endl;

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 3: {

            cout << endl << "Демонстрація класу Vector" << endl << endl;
            Vector vector(0);
            try {
                cin >> vector;
            }
            catch (invalid_argument e) {
                cout << "Помилка вводу. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }
            cout << "Вектор: " << vector << endl;
            cout << "Норма вектору: " << vector.norm() << endl;

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 4: {
            cout << endl << "Демонстрація класу Matrix" << endl << endl;
            Matrix mtx(0, 0);
            try {
                cin >> mtx;
                cout << "Введена матриця: " << endl;
                cout << mtx;
                cout << "Норма матриці: " << mtx.norm() << endl;
            }
            catch (invalid_argument e) {
                cout << "Помилка вводу. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 5: {
            cout << endl << "Демонстрація класу Vector Complex Numbers" << endl << endl;
            try {
                vector<ComplexNumber> v(0);
                VectorComplex vectorComplex(v);
                cin >> vectorComplex;
                cout << "Введений вектор комлексних чисел: " << endl;
                cout << vectorComplex;
                ComplexNumber maxModuleNumber = vectorComplex.getMaxModule();
                cout << "Комплексне число з найбільшим модулем: " << maxModuleNumber.getValue() << "+" << maxModuleNumber.getImageNumber() << "i";
            }
            catch (invalid_argument e) {
                cout << "Помилка вводу. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 6: {
            cout << endl << "Демонстрація класу Пізнього звязування" << endl << endl;

            int vectorSize = 5;
            RealNumber* complexNumber;
            RealNumber* vector;

            complexNumber = new ComplexNumber(25, 34);

            double exampleArray[] = { 5, 8, 10, 15, -52 };
            vector = new Vector(exampleArray, vectorSize);

            cout << "Норма комплексного числа: " << complexNumber->norm() << endl;
            cout << "Норма вектора: " << vector->norm() << endl;

            cout << endl << "Натисніть щоб продовжити..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 7: {
            cout << "Вихід з програми..." << endl;
            break;
        }
        default:
            cout << "Помилка вводу. Виберіть пункт від 1 до 7" << endl;
            break;
        }

    } while (choice != 7);

    return 0;
};


bool isDigitNumber(const string& s) {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c) || c == '.' || c == '-') {
            return false;
        }
    }
    return true;
}

bool isDoubleNumber(const string& s) {
    if (s.empty()) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c) && c != '.' || c == '-') {
            return false;
        }
    }
    return true;
}