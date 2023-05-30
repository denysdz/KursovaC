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

    cout << "\t\t������� ������\n�������� ��� ������������ ����� ĳ���� �����, ��������� ��c��,\n�������, ������, ������ ����������� �����\n";
    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. ������������ ������ ����� Real Number\n";
        cout << "2. ������������ ������ ����� Complex Number\n";
        cout << "3. ������������ ������ ����� Vector\n";
        cout << "4. ������������ ������ ����� Matrix\n";
        cout << "5. ������������ ������ ����� Vector Complex Number\n";
        cout << "6. ������������ ������� ��'��������\n";
        cout << "7. ����� � ��������\n";
        cout << "\n������� ����� ����: ";

        string choiceStr;
        cout << "������� ����� �� 1 �� 7: ";
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
            cout << endl << "������������ ����� Real Number" << endl << endl;

            RealNumber x(0);
            RealNumber y(0);

            try {
                cout << "������ ����� ����� �����" << endl;
                cin >> x;
                cout << "������ ����� ����� �����" << endl;
                cin >> y;
            }
            catch (invalid_argument e) {
                cout << "������� �����. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << "��������� �������� +: " << (x + y).getValue() << endl;
            cout << "��������� �������� -: " << (x - y).getValue() << endl;
            cout << "��������� �������� *: " << (x * y).getValue() << endl;
            cout << "��������� �������� /: " << (x / y).getValue() << endl;
            cout << "����� ������� �����: " << x.norm() << endl;
            cout << "����� ������� �����: " << y.norm() << endl;

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 2: {
            cout << endl << "������������ ����� Complex Number" << endl << endl;

            ComplexNumber complexNumber(0, 0);

            try {
                cout << "������ ����� � ����� ������� ������������ �����: ";
                cin >> complexNumber;
            }
            catch (invalid_argument e) {
                cout << "������� �����. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << "���������� �����: " << complexNumber << endl;
            cout << "����� ����������� �����: " << complexNumber.norm() << endl;

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 3: {

            cout << endl << "������������ ����� Vector" << endl << endl;
            Vector vector(0);
            try {
                cin >> vector;
            }
            catch (invalid_argument e) {
                cout << "������� �����. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }
            cout << "������: " << vector << endl;
            cout << "����� �������: " << vector.norm() << endl;

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 4: {
            cout << endl << "������������ ����� Matrix" << endl << endl;
            Matrix mtx(0, 0);
            try {
                cin >> mtx;
                cout << "������� �������: " << endl;
                cout << mtx;
                cout << "����� �������: " << mtx.norm() << endl;
            }
            catch (invalid_argument e) {
                cout << "������� �����. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 5: {
            cout << endl << "������������ ����� Vector Complex Numbers" << endl << endl;
            try {
                vector<ComplexNumber> v(0);
                VectorComplex vectorComplex(v);
                cin >> vectorComplex;
                cout << "�������� ������ ���������� �����: " << endl;
                cout << vectorComplex;
                ComplexNumber maxModuleNumber = vectorComplex.getMaxModule();
                cout << "���������� ����� � ��������� �������: " << maxModuleNumber.getValue() << "+" << maxModuleNumber.getImageNumber() << "i";
            }
            catch (invalid_argument e) {
                cout << "������� �����. " << e.what() << endl;
                cin.clear();
                while (cin.get() != '\n');
                break;
            }

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 6: {
            cout << endl << "������������ ����� ϳ������ ����������" << endl << endl;

            int vectorSize = 5;
            RealNumber* complexNumber;
            RealNumber* vector;

            complexNumber = new ComplexNumber(25, 34);

            double exampleArray[] = { 5, 8, 10, 15, -52 };
            vector = new Vector(exampleArray, vectorSize);

            cout << "����� ������������ �����: " << complexNumber->norm() << endl;
            cout << "����� �������: " << vector->norm() << endl;

            cout << endl << "�������� ��� ����������..." << endl;
            cin.get();
            cin.ignore();
            break;
        }
        case 7: {
            cout << "����� � ��������..." << endl;
            break;
        }
        default:
            cout << "������� �����. ������� ����� �� 1 �� 7" << endl;
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