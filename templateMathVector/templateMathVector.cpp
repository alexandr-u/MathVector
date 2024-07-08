#include <iostream>
#include <windows.h>
#include <math.h>
template <typename T>
class BaseMathVectors {
public:
    T xVectorX;
    T yVectorX;
    T xVectorY;
    T yVectorY;

    friend std::istream& operator>>(std::istream& is, BaseMathVectors& item) //перегрузка метода ввода для вектора
    {
        is >> item.xVectorX >> item.yVectorX >> item.xVectorY >> item.yVectorY;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, BaseMathVectors& item) //перегрузка метода вывода для вектора
    {
        os << "\nКоордината x базового вектора на ось x = " << item.xVectorX << " Координата y базового вектора на ось x = " << item.yVectorX << "\nКоордината x базового вектора на ось y = " << item.xVectorY << " Координата y базового вектора на ось y = " << item.yVectorY << "\n";
        return os;
    }
};

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
    ~MathVector() = default; //деструктор по умолчанию

    MathVector(const MathVector& over) = default;

    T getX() { return x; }
    T getY() { return y; }
    void setX(T valueX) { x = valueX; }
    void setY(T valueY) { y = valueY; }

    MathVector& operator = (const MathVector& over) //перегрузка оператора =
    {
        if (this != &over)
        {
            this->x = over.x;
            this->y = over.y;
        }
        return *this;
    }

    MathVector operator + (const MathVector& over) //сложение векторов
    {
        MathVector temp;
        temp.x = this->x + over.x;
        temp.y = this->y + over.y;
        return temp;
    }
    MathVector operator += (const MathVector& over) { return *this = *this + over; }


    MathVector operator - (const MathVector& over) //вычитание векторов
    {
        MathVector temp;
        temp.x = this->x - over.x;
        temp.y = this->y - over.y;
        return temp;
    }
    MathVector operator -= (const MathVector& over) { return *this = *this - over; }


    MathVector operator * (const T& number) //умножение на число
    {
        MathVector temp;
        temp.x = this->x * number;
        temp.y = this->y * number;
        return temp;
    }
    MathVector operator *= (const double& number) { return *this = *this * number; }

    T operator * (const MathVector& over) //скалярное произведение векторов
    {
        return (this->x * over.x + this->y * over.y);
    }

    double length() //длина верктора
    {
        return sqrt(double(pow(x, 2) + pow(y, 2)));
    }

    MathVector& normal(const MathVector& over) //нормализация вектора (приведение к единичной длине)
    {
        this->x = double(this->x) / this->length();
        this->y = double(this->y) / this->length();
        return *this;
    }

    BaseMathVectors<T> base() //разложение на базовые вектора
    {
        BaseMathVectors<T> baseVectors;
        baseVectors.xVectorX = this->x;
        baseVectors.yVectorX = 0;
        baseVectors.xVectorY = 0;
        baseVectors.yVectorY = this->y;
        return baseVectors;
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
};


int main()
{
    setlocale(LC_ALL, "ru");

    MathVector<double>  a(1, 2.3);
    MathVector<double>  b(a);
    /*MathVector<double>  c = a + b;
    MathVector<double>  d = a - c;
    MathVector<double>  e = a * 5;
    double f = a * c;
    std::cout << "Создание вектра с инициализайией значений a(1, 2.3) " << a << "Инициализация с приравниванием к а b(a) " << b << "Вектор с = a+b " << c << "Вектора a-c " << d << "Умножение вектора a на 5" << e << "Скалярное произведеие векторов a и c" << f << "\n";
    std::cout << "Введите координаты вектора (x и y) через пробел: ";
    std::cin >> a;
    std::cout << "Значения введенного вектора: " << a;*/
    std::cout << "Создание вектра с инициализайией значений a(1, 2.3) " << a << "Инициализация с приравниванием к а b(a) " << b;
    BaseMathVectors<double> baseA = a.base();
    std::cout << "Базовые вектора a: " << baseA;

    b += a;
    std::cout << "b += a; " << b;
    b -= a;
    std::cout << "b -= a; " << b;
    b *= 3;
    std::cout << "b *= 3; " << b;

    return 0;
}
