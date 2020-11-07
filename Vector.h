#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class Vector
{
private:
    int len; // Аргументы
    char *p_arr{};
    static bool check(char symbol);
    char _or_(char symbol1, char symbol2); // Логические функции
    char _and_(char symbol1, char symbol2);
    char _no_(char symbol);

public:

    explicit Vector(); // Конструкторы
    Vector(int len);
    Vector(string str);
    Vector(const Vector &vector): len(vector.len), p_arr(vector.p_arr){};
    ~Vector();

    void upgrade(int new_len); // Методы для тестирования
    char* get_arr();
    int get_len();
    bool is_correct();

    bool &operator==(const Vector &vector); // Перегрузка операторов
    Vector &operator|(const Vector &vector);
    Vector &operator&(const Vector &vector);
    Vector &operator=(const Vector &vector);
    Vector &operator~();

    Vector &operator<<(char symbol); // Перегрузка операторов потокового добавления элемента того же класса или символа
    Vector &operator<<(const Vector &vector);

    friend std::ostream& operator << (std::ostream &out, const Vector &vector); // Перегрузка операторов ввода/вывода
    friend std::istream& operator >> (std::istream &in, Vector &vector);
};