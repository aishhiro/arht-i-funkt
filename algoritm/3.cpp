#include <iostream>
#include <cmath>

class Complex {
public:
    double re;
    double im;

    Complex() {
        re = 0;
        im = 0;
    }

    Complex(double a, double b) {
        re = a;
        im = b;
    }

    Complex(const Complex& other) {
        re = other.re;
        im = other.im;
    }

    Complex(Complex&& other) {
        re = other.re;
        im = other.im;
        other.re = 0;
        other.im = 0;
    }

    Complex& operator=(const Complex& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
        }
        return *this;
    }

    Complex& operator=(Complex&& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
            other.re = 0;
            other.im = 0;
        }
        return *this;
    }

    ~Complex() {
    }

    Complex operator+(const Complex& other) const {
        Complex res;
        res.re = re + other.re;
        res.im = im + other.im;
        return res;
    }

    Complex operator-(const Complex& other) const {
        Complex res;
        res.re = re - other.re;
        res.im = im - other.im;
        return res;
    }

    Complex operator*(const Complex& other) const {
        Complex res;
        res.re = re * other.re - im * other.im;
        res.im = re * other.im + im * other.re;
        return res;
    }

    Complex operator/(const Complex& other) const {
        Complex res;
        double eps = 0.000000001;
        double d = other.re * other.re + other.im * other.im;
        if (d < eps && d > -eps) {
            std::cout << "error % 0" << std::endl;
            res.re = 0;
            res.im = 0;
            return res;
        }
        res.re = (re * other.re + im * other.im) / d;
        res.im = (im * other.re - re * other.im) / d;
        return res;
    }

    void operator+=(const Complex& other) {
        re = re + other.re;
        im = im + other.im;
    }

    void operator-=(const Complex& other) {
        re = re - other.re;
        im = im - other.im;
    }

    void operator*=(const Complex& other) {
        double newRe = re * other.re - im * other.im;
        double newIm = re * other.im + im * other.re;
        re = newRe;
        im = newIm;
    }

    void operator/=(const Complex& other) {
        double eps = 0.000000001;
        double d = other.re * other.re + other.im * other.im;
        if (d < eps && d > -eps) {
            std::cout << "error % 0" << std::endl;
            return;
        }
        double newRe = (re * other.re + im * other.im) / d;
        double newIm = (im * other.re - re * other.im) / d;
        re = newRe;
        im = newIm;
    }

    double modul() const {
        return sqrt(re * re + im * im);
    }

    double arg() const {
        return atan2(im, re);
    }
};

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.re << " + " << c.im << "i";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& c) {
    double a;
    double b;
    in >> a;
    in >> b;
    if (in.fail()) {
        return in;
    }
    c.re = a;
    c.im = b;
    return in;
}

int main() {
    Complex a;
    Complex b;

    std::cout << "first number (re im) ";
    std::cin >> a;
    if (std::cin.fail()) {
        std::cout << "error" << std::endl;
        return 1;
    }

    std::cout << "two number (re im) ";
    std::cin >> b;
    if (std::cin.fail()) {
        std::cout << "error" << std::endl;
        return 1;
    }

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    Complex s = a + b;
    std::cout << "a + b = " << s << std::endl;

    Complex r = a - b;
    std::cout << "a - b = " << r << std::endl;

    Complex m = a * b;
    std::cout << "a * b = " << m << std::endl;

    Complex d = a / b;
    std::cout << "a / b = " << d << std::endl;

    Complex c1 = a;
    c1 += b;
    std::cout << "a += b -> " << c1 << std::endl;

    Complex c2 = a;
    c2 -= b;
    std::cout << "a -= b -> " << c2 << std::endl;

    Complex c3 = a;
    c3 *= b;
    std::cout << "a *= b -> " << c3 << std::endl;

    Complex c4 = a;
    c4 /= b;
    std::cout << "a /= b -> " << c4 << std::endl;

    std::cout << "|a| = " << a.modul() << std::endl;
    std::cout << "arg(a) = " << a.arg() << std::endl;
    std::cout << "|b| = " << b.modul() << std::endl;
    std::cout << "arg(b) = " << b.arg() << std::endl;

    return 0;
}
