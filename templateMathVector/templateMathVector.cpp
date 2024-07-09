#include <iostream>
#include <windows.h>
#include <math.h>

template <typename T>

class MathVector
{
public:
    T m_x;
    T m_y;

    MathVector() = default; //базовый конструктор
    MathVector(T valueX, T valueY) : m_x(valueX), m_y(valueY) {} // список инициализации
    ~MathVector() = default; //деструктор по умолчанию

    MathVector(const MathVector& over) = default;

    MathVector& operator = (const MathVector& over) //перегрузка оператора =
    {
        if (this != &over)
        {
            m_x = over.m_x;
            m_y = over.m_y;
        }
        return *this;
    }

    MathVector operator + (const MathVector& over) //сложение векторов
    {
        return MathVector<T>(m_x + over.m_x, m_y + over.m_y);
    }
    MathVector operator += (const MathVector& over) { return *this = *this + over; }


    MathVector operator - (const MathVector& over) //вычитание векторов
    {
        return MathVector<T>(m_x - over.m_x, m_y - over.m_y);
    }
    MathVector operator -= (const MathVector& over) { return *this = *this - over; }


    MathVector operator * (const T& number) //умножение на число
    {
        return MathVector<T>(m_x * number, m_y * number);
    }
    MathVector operator *= (const double& number) { return *this = *this * number; }

    T operator * (const MathVector& over) //скалярное произведение векторов
    {
        return (m_x * over.m_x + m_y * over.m_y);
    }

    double length() //длина верктора
    {
        return sqrt(double(pow(m_x, 2) + pow(m_y, 2)));
    }

    std::pair<MathVector<T>, MathVector<T>> base() //разложение на базовые вектора
    {
        return { MathVector<T>(m_x,0),MathVector<T>(0,m_y) };
    }

    MathVector& normal(const MathVector& over) //нормализация вектора (приведение к единичной длине)
    {
        return MathVector<T>(double(m_x) / length(), double(m_y) / length());
    }

    
    friend std::istream& operator>>(std::istream& is, MathVector& item) //перегрузка метода ввода для вектора
    {
        is >> item.m_x >> item.m_y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, MathVector& item) //перегрузка метода вывода для вектора
    {
        os << "x = " << item.m_x << " y = " << item.m_y << "\n";
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
    std::cout << "Создание вектра с инициализайией значений a(1, 2.3)\n " << a << "Инициализация с приравниванием к а b(a) \n" << b;
    auto baseA = a.base();
    std::cout << "Базовые вектора x и y вектора a: \n" << baseA.first<<baseA.second;

    b += a;
    std::cout << "\nb += a; \n" << b;
    b -= a;
    std::cout << "b -= a; \n" << b;
    b *= 3;
    std::cout << "b *= 3; \n" << b;

    return 0;
}
