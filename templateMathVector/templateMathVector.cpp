#include <iostream>
#include <windows.h>
#include <math.h>

template <typename T>

class MathVector
{
private:
    T x;
    T y;

public:
    MathVector() = default; //базовый конструктор
    MathVector(T valueX, T valueY) // конструктор с параметрами
    {
        x = valueX;
        y = valueY;
    }
    MathVector(const MathVector& over) //конструктор присваивания
    {
        this->x = over.x;
        this->y = over.y;
    }

    T getX() { return x; }
    T getY() { return y; }
    void setX(T valueX) { x = valueX; }
    void setY(T valueY) { y = valueY; }

    MathVector& operator = (const MathVector& over) //перегрузка оператора присваивания
    {
        this->x = over.x;
        this->y = over.y;
        return *this;
    }

    MathVector operator + (const MathVector& over) //сложение векторов
    {
        MathVector temp;
        temp.x = this->x + over.x;
        temp.y = this->y + over.y;
        return temp;
    }

    MathVector operator - (const MathVector& over) //вычитание векторов
    {
        MathVector temp;
        temp.x = this->x - over.x;
        temp.y = this->y - over.y;
        return temp;
    }

    MathVector operator * (const T& number) //умножение на число
    {
        MathVector temp;
        temp.x = this->x * number;
        temp.y = this->y * number;
        return temp;
    }

    T operator * (const MathVector& over) //скалярное произведение векторов
    {
        return (this->x * over.x + this->y * over.y);
    }

    double longVector() //длина верктора
    {
        return sqrt(double(pow(x, 2) + pow(y, 2)));
    }

    MathVector& normal(const MathVector& over) //нормализация вектора (приведение к единичной длине)
    {
        this->x = double(over.x) / this->longVector();
        this->y = double(over.y) / this->longVector();
        return *this;
    }

    void base(MathVector& baseVector_x, MathVector& baseVector_y) //разложение на базовые вектора
    {
        baseVector_x.x = this->x;
        baseVector_x.y = 0;
        baseVector_y.x = 0;
        baseVector_y.y = this->y;
    }

    MathVector intersection() //пересечение векторов 
    {
        MathVector temp;
        // на подумать. как пересекаются вектора. пересекаются только отрезки. либо нужно две точки для вектора
        return temp;
    }
    friend std::istream& operator>>(std::istream& is, MathVector& item) //перегрузка метода ввода для вектора
    {
        is >> item.x >> item.y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, MathVector& item) //перегрузка метода вывода для вектора
    {
        os << "\n x = " << item.x << " y = " << item.y << "\n";
        return os;
    }

    ~MathVector() = default; //базовый деструктор
};


int main()
{
    setlocale(LC_ALL, "ru");

    MathVector<double>  a(1, 2.3);
    MathVector<double>  b(a);
    MathVector<double>  c = a + b;
    MathVector<double>  d = a - c;
    MathVector<double>  e = a * 5;
    double f = a * c;
    std::cout << "Создание вектра с инициализайией значений a(1, 2.3) " << a << "Инициализация с приравниванием к а b(a) " << b << "Вектор с = a+b " << c << "Вектора a-c " << d << "Умножение вектора a на 5" << e << "Скалярное произведеие векторов a и c" << f << "\n";
    std::cout << "Введите координаты вектора (x и y) через пробел: ";
    std::cin >> a;
    std::cout << "Значения введенного вектора: " << a;
}
