#include "Vector.h"
#include <iostream>
#include <string>

int Which_vector()
{
    int index = 0;
    do {
        cout << "Выберите вектор для применения изменений: \n 1: Vector1. \n 2: Vector2." << endl;
        getchar();
        cin >> index ;
        if ( index == 1 || index == 2){
            return index;
        } else {
            cout << "!!! Некорректный выбор. Повторите ввод. !!!" << endl;
        }
    } while ( (index != 1) || (index != 0));
}

void menu() {
    setlocale(LC_ALL,"rus");

    int Ans;

    Vector vector1;
    Vector vector2;

    do {
        cout << "\n  0: Прекратить работу. \n  1: Инициализация экзамеляра класса ВЕКТОР строкой символов. \n  2: Инициализация экзамеляра класса ВЕКТОР количеством элементов (все равны Х). \n  3: Задать вектор копирующим конструктуром. \n  4: Задать вектор перегруженным оператором присваивания. \n  5: Ввод вектора перегруженны оператором >>. \n  6: Вывод вектора перегруженным оператором <<. \n  7: Выполнение поразрядной операции перегруженным оператором &. \n  8: Выполнение поразрядной операции перегруженным оператором |. \n  9: Выполнение операции сравнения перегруженным оператором ==. \n  10: Выполнение операции отрицания перегруженным оператором ~. \n  11: Анализ определенности вектора. \n  12: Просмотр векторов." << endl;
        cin >> Ans;
        if ((Ans > 0)&&(Ans < 13)){
            cout << "============" << endl;
            switch (Ans) {
                case 1:
                {string str;
                    if (Which_vector() == 1){
                        cout << "Введите строку:" << endl;
                        getchar();
                        cin >> str;
                        Vector vector3(str);
                        vector1 = vector3;
                    } else {
                        cout << "Введите строку:" << endl;
                        getchar();
                        cin >> str;
                        Vector vector3(str);
                        vector2 = vector3;
                    }
                    break;}
                case 2:
                {
                    int len;
                    if (Which_vector() == 1){
                        cout << "Введите количество элементов:" << endl;
                        getchar();
                        cin >> len;
                        Vector vector_case_2(len);
                        vector1 = vector_case_2;
                    } else {
                        cout << "Введите количество элементов:" << endl;
                        getchar();
                        cin >> len;
                        Vector vector_case_2(len);
                        vector2 = vector_case_2;
                    }
                    break;}
                case 3:
                {
                    if (Which_vector() == 1){
                        Vector vector_case_3(vector2);
                        vector1 = vector_case_3;
                    } else {
                        Vector vector_case_3(vector1);
                        vector2 = vector_case_3;
                    }
                    break;}
                case 4:
                {
                    if (Which_vector() == 1){
                        vector1 = vector2;
                    } else {
                        vector2 = vector1;
                    }
                    break;}
                case 5:
                {
                    Vector vector_case_5;
                    if (Which_vector() == 1){
                        cout << "Введите вектор:" << endl;
                        getchar();
                        cin >> vector_case_5;
                        vector1 = vector_case_5;
                    } else {
                        cout << "Введите вектор:" << endl;
                        getchar();
                        cin >> vector_case_5;
                        vector2 = vector_case_5;
                    }
                    break;}
                case 6:
                {
                    if (Which_vector() == 1){
                        cout << vector1 << endl;
                    } else {
                        cout << vector2 << endl;
                    }
                    break;}
                case 7:
                {
                    cout << (vector1 & vector2) << endl;
                    break;}
                case 8:
                {
                    cout << (vector1 | vector2) << endl;
                    break;}
                case 9:
                {
                    if ((vector1 == vector2) == true){
                        cout << "True" << endl;
                    } else {
                        cout << "False" << endl;
                    }
                    break;}
                case 10:
                {
                    if (Which_vector() == 1){
                        cout << ~vector1 << endl;
                    } else {
                        cout << ~vector2 << endl;
                    }
                    break;}
                case 11:
                {
                    if (Which_vector() == 1){
                        if (vector1.is_correct() == true){
                            cout << "True" << endl;
                        } else {
                            cout << "False" << endl;
                        }
                    } else {
                        if (vector2.is_correct() == true){
                            cout << "True" << endl;
                        } else {
                            cout << "False" << endl;
                        }
                    }
                    break;}
                case 12:
                {
                    cout << "Вектор1: " << vector1 << endl;
                    cout << "Вектор2: " << vector2 << endl;
                    break;
                    }
            }
            cout << "============" << endl;
        } else {
            if (Ans != 0){
                cout << "!!! Некорректный выбор. Повторите ввод. !!!" << endl;
            }
        }
    } while (Ans != 0);
}

int main(){
    menu();
    return 0;
}