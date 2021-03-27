#include "ComplexNumber.h"
#include <regex>
#include <sstream>

ComplexNumber::ComplexNumber(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {}

ComplexNumber &ComplexNumber::setValue(double real, double imaginary) {
    m_real = real;
    m_imaginary = imaginary;
    return *this;
}

ComplexNumber decodeExpressionResult(const ComplexNumber &left, char op, const ComplexNumber &right) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }
    throw invalid_argument("The provided operator couldn't be decoded.");
}

// Arithmetic operators
ComplexNumber ComplexNumber::operator+(const ComplexNumber &number) const {
    return ComplexNumber(m_real + number.m_real, m_imaginary + number.m_imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &number) const {
    return ComplexNumber(m_real - number.m_real, m_imaginary - number.m_imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &number) const {
    auto newReal = m_real * number.m_real - m_imaginary * number.m_imaginary;
    auto newImaginary = m_imaginary * number.m_real + m_real * number.m_imaginary;
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &number) const {
    auto denominator = number.m_real * number.m_real + number.m_imaginary + number.m_imaginary;
    if (denominator == 0.0) {
        throw invalid_argument("Can't divide by 0.");
    }

    auto newReal = (m_real * number.m_real + m_imaginary * number.m_imaginary) / denominator;
    auto newImaginary = (m_imaginary * number.m_real - m_real * number.m_imaginary) / denominator;
    return ComplexNumber(newReal, newImaginary);
}

// Stream operators
ostream &operator<<(ostream &out, const ComplexNumber &number) {
    out << number.m_real << (number.m_imaginary >= 0 ? "+" : "") << number.m_imaginary << "i";
    return out;
}

istream &operator>>(istream &in, ComplexNumber &number) {
    string inputString;
    getline(in, inputString);

    // Search for '10.37', '10.37i' or '5.2+10.37i'
    regex expression(
            "(?:^([0-9]+\\.?[0-9]*) *$)|(?:^([0-9]+\\.?[0-9]*)i *$)|(?:^([0-9]+\\.?[0-9]*) *(\\+|-)? *([0-9]+\\.?[0-9]*)?i? *$)"
    );
    smatch result;
    regex_search(inputString, result, expression);

    // Get the numbers from the regex match
    vector<double> numbersFound;
    for (int i = 1; i < result.size(); i++) {
        double tempDouble;
        stringstream ss(result[i]);
        if (ss >> tempDouble) {
            numbersFound.push_back(tempDouble);
        }
    }

    if (numbersFound.size() == 2) {
        // Found both the real part and the imaginary part
        number.m_real = numbersFound[0];
        number.m_imaginary = numbersFound[1];
    } else if (numbersFound.size() == 1) {
        // Found a number - may be from the real part, may be from the imaginary part
        if (inputString.find('i') < inputString.length()) {
            number.m_imaginary = numbersFound[0];
        } else {
            number.m_real = numbersFound[0];
        }
    } else {
        // Set so the 'if (cin >> complexNumber)' fails
        in.setstate(std::ios::failbit);
    }

    return in;
}
