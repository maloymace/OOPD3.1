#include <iostream>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы

    Complex ()
    {
    };

    Complex (double r)
    {
        re = r;
        im = 0;
    }

    Complex (double r, double i)
    {
        re = r;
        im = i;
    }

    Complex (const Complex &c)   // конструктор копирования
    {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex ()
    {
    }

    // остальные функции

    // Модуль комплексного числа
    double abs ()
    {
        return sqrt (re * re + im * im);
    }

    // оператор присваивания
    Complex& operator = (Complex &c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }


    // оператор +=
    Complex& operator += (Complex &c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // оператор сложения
    Complex operator + (const Complex &c)
    {
        return Complex (re + c.re, im + c.im);
    }

    // оператор вычитания
    Complex operator - (const Complex &c)
    {
        return Complex(re - c.re, im - c.im);
    }

    // оператор умножения
    Complex operator * (const Complex &c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // оператор деления
    Complex operator / (const Complex &c)
    {
        Complex temp;

        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;

        return temp;
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend ostream & operator<< (ostream &, const Complex &);
    friend istream & operator>> (istream &, Complex &);

};

// VECTOR

class Vector {
public:
    Vector() {
        arr_ = new T[1];
        capacity_ = 1;
    }
    Vector(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector(Vector&& other)  noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector& operator=(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    ~Vector() {
        delete[] arr_;
    }
public:
    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] size_t size() const {
        return size_;
    }

    [[nodiscard]] size_t capacity() const {
        return capacity_;
    }

    void pushBack(const T& value) {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void remove(size_t index) {
        for (size_t i = index + 1; i < size_; ++i) {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }
public:
    T* begin() {
        return &arr_[0];
    }

    const T* begin() const {
        return &arr_[0];
    }

    T* end() {
        return &arr_[size_];
    }

    const T* end() const {
        return &arr_[size_];
    }
public:
    T& operator[](size_t index)  {
        return arr_[index];
    }

    const T& operator[](size_t index) const {
        return arr_[index];
    }
private:

    void addMemory() {
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
        delete[] tmp;
    }

    T* arr_;
    size_t size_{};
    size_t capacity_{};
};

// CIRCLE

class Circle
{
    static const double Pi;

public:
    Circle(double radius = 1.0):
            _radius(radius)
    {
    }

    void set_radius(double radius)
    {
        _radius = radius;
    }

    double get_radius() const
    {
        return _radius;
    }

    double area() const
    {
        return Pi * _radius * _radius;
    }

    double circuit() const
    {
        return 2.0 * Pi * _radius;
    }

    double diameter() const
    {
        return 2.0 * _radius;
    }

private:
    double _radius;
};
