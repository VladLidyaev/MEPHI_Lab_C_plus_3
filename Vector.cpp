#include "Vector.h"
#include <string>

using namespace std;

Vector::Vector() {
    this->len = 0;
    this->p_arr = nullptr;
}

Vector::Vector(int len) {
    this->len = len;
    this->p_arr = new char[len];
    for (int i = 0; i < len; ++i) {
        this->p_arr[i] = 'X';
    }
}

Vector::Vector(string str){
    int j = 0;
    this->p_arr = new char[str.size()];
    for (int i = 0; i < str.size() ; i++){
        if (str[i] != ' '){
            if (check(str[i])) {
                this->p_arr[j] = str[i];
                j++;
            }
        }
    }
    this->len = j;
}

Vector::~Vector() {
    delete [] this->p_arr;
    this->p_arr = nullptr;
}


void Vector::upgrade(int new_len){
    for (int i = (this->len); i < new_len+1 ; i++){
        this->p_arr[i] = 'X';
    }
}

bool Vector::check(char symbol){
    if ((symbol == 'X') || (symbol == '0') || (symbol == '1')){
        return true;
    } else {
        return false;
    }
}

char* Vector::get_arr() {
    return this->p_arr;
}

int Vector::get_len() {
    return this->len;
}

bool Vector::is_correct() {
    bool ans = true;
    for (int i = 0; i < (this->len); i++){
        if ((this->p_arr[i] != '1') && (this->p_arr[i] != '0')){
            ans = false;
        }
    }
    return ans;
}

Vector &Vector::operator<<(char symbol) {
    auto p_arr_new = new char[this->len + 1];
    for (int i = 0; i < this->len; ++i) {
        p_arr_new[i] = this->p_arr[i];
    }
    p_arr_new[this->len] = symbol;
    ++this->len;
    delete [] this->p_arr;
    this->p_arr = p_arr_new;
    return *this;
}

Vector &Vector::operator<<(const Vector &vector) {
    auto p_arr_new = new char[this->len + vector.len];
    for (int i = 0; i < this->len; ++i) {
        p_arr_new[i] = this->p_arr[i];
    }
    for (int i = this->len; i < this->len + vector.len; ++i) {
        p_arr_new[i] = vector.p_arr[i - this->len];
    }
    this->len += vector.len;
    delete [] this->p_arr;
    this->p_arr = p_arr_new;
    return *this;
}

std::ostream &operator<<(ostream &out, const Vector &vector) {
    if (vector.len != 0) {
        out << "[";
        for (int i = 0; i < vector.len; ++i) {
            if (i != vector.len - 1) {
                out << vector.p_arr[i] << ", ";
            } else {
                out << vector.p_arr[i] << "]";
            }
        }
    } else {
        out << "null";
    }
    return out;
}

std::istream &operator>>(istream &in, Vector &vector) {
    char symbol;
    while ((symbol = in.get()) != '\n') {
        if (symbol == '1' || symbol == '0' || symbol == 'X') {
            auto p_arr_new = new char[vector.len + 1];
            for (int i = 0; i < vector.len; ++i) {
                p_arr_new[i] = vector.p_arr[i];
            }
            p_arr_new[vector.len] = symbol;
            ++vector.len;
            delete [] vector.p_arr;
            vector.p_arr = p_arr_new;
        }
    }
    return in;
}

Vector &Vector::operator|(const Vector &vector) {
    auto new_vector = new Vector();
    if (this->len > vector.len){
        for (int i = 0; i < vector.len; ++i) {
            *new_vector << this->_or_(this->p_arr[i], vector.p_arr[i]);
        }
        for (int i = vector.len; i < this->len; ++i) {
            *new_vector << this->_or_(this->p_arr[i],'X');
        }
    }else {
        for (int i = 0; i < this->len; ++i) {
            *new_vector << this->_or_(this->p_arr[i], vector.p_arr[i]);
        }
        for (int i = this->len; i < vector.len; ++i) {
            *new_vector << this->_or_(vector.p_arr[i],'X');
        }
    }
    return *new_vector;
}

char Vector::_or_(char symbol1, char symbol2) {
    if (symbol1 == '1' || symbol2 == '1'){
        return '1';
    }
    if (symbol1 == 'X' || symbol2 == 'X'){
        return 'X';
    } else {
        return '0';
    }
}

char Vector::_and_(char symbol1, char symbol2) {
    if (symbol1 == '0' || symbol2 == '0'){
        return '0';
    }
    if (symbol1 == 'X' || symbol2 == 'X'){
        return 'X';
    } else {
        return '1';
    }
}

Vector &Vector::operator&(const Vector &vector) {
    auto new_vector = new Vector();
    if (this->len > vector.len){
        for (int i = 0; i < vector.len; ++i) {
            *new_vector << this->_and_(this->p_arr[i], vector.p_arr[i]);
        }
        for (int i = vector.len; i < this->len; ++i) {
            *new_vector << this->_and_(this->p_arr[i],'X');
        }
    }else {
        for (int i = 0; i < this->len; ++i) {
            *new_vector << this->_and_(this->p_arr[i], vector.p_arr[i]);
        }
        for (int i = this->len; i < vector.len; ++i) {
            *new_vector << this->_and_(vector.p_arr[i],'X');
        }
    }
    return *new_vector;
}

bool &Vector::operator==(const Vector &vector) {
    bool ans = true;
    if (this->len == vector.len){
        for (int i = 0; i < vector.len; ++i) {
            if (this->p_arr[i] != vector.p_arr[i]){
                ans = false;
            }
        }
    }else {
        ans = false;
    }
    return ans;
}

Vector &Vector::operator~() {
    auto new_vector = new Vector();
    for (int i = 0; i < this->len; ++i) {
        *new_vector << _no_(this->p_arr[i]);
    }
    return *new_vector;
}

char Vector::_no_(char symbol) {
    if (symbol == '0'){
        return '1';
    }
    if (symbol == '1'){
        return '0';
    }
    if (symbol == 'X'){
        return 'X';
    }
}

Vector &Vector::operator=(const Vector &vector) {
    if (*this == vector) {
        return *this;
    }
    this->len = vector.len;
    delete [] this->p_arr;
    this->p_arr = new char [this->len];
    for (int i = 0; i < this->len; ++i) {
        p_arr[i] = vector.p_arr[i];
    }
    return *this;
}

Vector &operator|(const Vector &vector1, const Vector &vector2) {
    auto new_vector = new Vector();
    if (vector1.len > vector2.len){
        for (int i = 0; i < vector2.len; ++i) {
            *new_vector << vector1._or_(vector1.p_arr[i], vector2.p_arr[i]);
        }
        for (int i = vector2.len; i < vector1.len; ++i) {
            *new_vector << vector1._or_(vector1.p_arr[i],'X');
        }
    }else {
        for (int i = 0; i < vector1.len; ++i) {
            *new_vector << vector1._or_(vector1.p_arr[i], vector2.p_arr[i]);
        }
        for (int i = vector1.len; i < vector2.len; ++i) {
            *new_vector << vector1._or_(vector2.p_arr[i],'X');
        }
    }
    return *new_vector;
}

Vector &operator&(const Vector &vector1, const Vector &vector2) {
    auto new_vector = new Vector();
    if (vector1.len > vector2.len){
        for (int i = 0; i < vector2.len; ++i) {
            *new_vector << vector1._and_(vector1.p_arr[i], vector2.p_arr[i]);
        }
        for (int i = vector2.len; i < vector1.len; ++i) {
            *new_vector << vector1._and_(vector1.p_arr[i],'X');
        }
    }else {
        for (int i = 0; i < vector1.len; ++i) {
            *new_vector << vector1._and_(vector1.p_arr[i], vector2.p_arr[i]);
        }
        for (int i = vector1.len; i < vector2.len; ++i) {
            *new_vector << vector1._and_(vector2.p_arr[i],'X');
        }
    }
    return *new_vector;
}

bool &operator==(const Vector &vector1, const Vector &vector2) {
    bool ans = true;
    if (vector1.len == vector2.len){
        for (int i = 0; i < vector2.len; ++i) {
            if (vector1.p_arr[i] != vector2.p_arr[i]){
                ans = false;
            }
        }
    }else {
        ans = false;
    }
    return ans;
}

Vector &Vector::operator=(Vector &vector) {
    if (*this == vector) {
        return *this;
    }
    this->len = vector.len;
    delete [] this->p_arr;
    this->p_arr = new char [this->len];
    for (int i = 0; i < this->len; ++i) {
        p_arr[i] = vector.p_arr[i];
    }
    delete &vector;
//        delete [] vector.p_arr;
    return *this;
}
