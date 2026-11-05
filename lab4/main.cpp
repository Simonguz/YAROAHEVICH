#include <iostream>
using namespace std;

/*
 * ТЕМА: Численные методы.
 * СУТЬ: Вычисление интеграла f(x) = x^2 на [0, 1] методом трапеций.
 * ГДЕ БАГ: В строке 18 выражение 'x + h' не изменяет саму переменную 'x', приводя к бесконечному циклу.
 * КАК НАЙТИ: Запустите отладку. Программа зависнет. Нажмите Паузу и проверьте 'x' в окне Variables.
 */
#include <iostream>

double f(double x) { return x * x; }

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    double x = a + h;
    
    // БАГ: Ошибка обновления счетчика цикла
    while (x < b) {
        sum += f(x);
        x + h; // Должно быть x += h;
    }
    return sum * h;
}

int main() {
    std::cout << "Интеграл (Трапеции): " << trapezoidal(0.0, 1.0, 100) << std::endl;
    return 0;
}


