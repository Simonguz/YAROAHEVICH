
#include <iostream>
#include <numeric>
using namespace std;

class A {
    unsigned int x, y;

public:
    A(unsigned int x, unsigned int y) : x(x), y(y) {}

    // Сложение: НОК
    A operator+(const A& b) const {
        return A(lcm(x, b.x), lcm(y, b.y));
    }

    // Вычитание: НОД
    A operator-(const A& b) const {
        return A(gcd(x, b.x), gcd(y, b.y));
    }

    // Префиксный --x
    A& operator--() {
        *this = *this - A(10, 10);
        return *this;
    }

    // Постфиксный x++
    A operator++(int) const {
        A copy = *this;
        copy = copy + A(10, 10);
        return copy;
    }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// Сумма произвольного числа аргументов
template <typename T, typename... Args>
T sum(const T& first, const Args&... rest) {
    return (first + ... + rest);
}

int main() {
    A a(6, 15), b(10, 9), c(4, 25);
    A d(7, 2), e(8, 14);

    cout << "a + b = ";
    (a + b).print();
    cout << endl;

    cout << "a - b = ";
    (a - b).print();
    cout << endl;

    A t(6, 15);
    --t;
    cout << "After --t: t = ";
    t.print();
    cout << endl;

    A result = t++;
    cout << "Result of t++ = ";
    result.print();
    cout << ", t = ";
    t.print();
    cout << endl;

    cout << "sum(a) = ";
    sum(a).print();
    cout << endl;

    cout << "sum(a, b, c) = ";
    sum(a, b, c).print();
    cout << endl;

    cout << "sum(a, b, c, d, e) = ";
    sum(a, b, c, d, e).print();
    cout << endl;

    return 0;
}
