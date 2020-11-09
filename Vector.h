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
    static char _or_(char symbol1, char symbol2); // Логические функции
    static char _and_(char symbol1, char symbol2);
    static char _no_(char symbol);

public:

    explicit Vector(); // Конструкторы
    Vector(int len);
    Vector(string str);

    Vector(const Vector &vector): len(vector.len), p_arr(nullptr){
        this->p_arr = new char [this->len];
        for (int i = 0; i < this->len; ++i) {
            this->p_arr[i] = vector.p_arr[i];
        }
    };

    Vector(Vector &&vector): len(vector.len), p_arr(vector.p_arr){
        vector.len = 0;
        vector.p_arr = nullptr;
    };

    ~Vector();

    void upgrade(int new_len); // Методы для тестирования
    char* get_arr();
    int get_len();
    bool is_correct();

    bool &operator==(const Vector &vector); // Перегрузка операторов
    friend bool &operator==(const Vector &vector1, const Vector &vector2);
    Vector &operator|(const Vector &vector);
    Vector &operator&(const Vector &vector);
    friend Vector &operator|(const Vector &vector1, const Vector &vector2);
    friend Vector &operator&(const Vector &vector1, const Vector &vector2);
    Vector &operator=(const Vector &vector);
    Vector &operator=(Vector &&vector);
    Vector &operator~();

    Vector &operator<<(char symbol); // Перегрузка операторов потокового добавления элемента того же класса или символа
    Vector &operator<<(const Vector &vector);

    friend std::ostream& operator << (std::ostream &out, const Vector &vector); // Перегрузка операторов ввода/вывода
    friend std::istream& operator >> (std::istream &in, Vector &vector);
};