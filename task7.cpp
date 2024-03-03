#include <iostream>
using namespace std;

int divisor(int numerator, int denominator)
{
    while (denominator != 0)
    {
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }
    return numerator;
}

class Rational
{
    int numerator;
    int denominator;

public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int numerator_value, int denominator_value)
    {
        numerator = numerator_value / divisor(numerator_value, denominator_value);
        denominator = denominator_value / divisor(numerator_value, denominator_value);
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    void setNumerator(int numerator_value)
    {
        numerator = numerator_value;
    }

    int getNumerator()
    {
        return numerator;
    }

    void setDenominator(int denominator_value)
    {
        denominator = denominator_value;
    }

    int getDenominator()
    {
        return denominator;
    }

    void print_Rational_Number()
    {
        cout << getNumerator() << "/" << getDenominator() << endl;
    }
};

Rational addRationalNumber(Rational r1, Rational r2)
{
    int numerator = (r1.getNumerator() * r2.getDenominator()) + (r1.getDenominator() * r2.getNumerator());
    int denominator = r1.getDenominator() * r2.getDenominator();
    return Rational(numerator, denominator);
}

Rational multiRationalNumber(Rational r1, Rational r2)
{
    int numerator = r1.getNumerator() * r2.getNumerator();
    int denominator = r1.getDenominator() * r2.getDenominator();
    return Rational(numerator, denominator);
}

Rational divRationalNumber(Rational r1, Rational r2)
{
    int numerator = r1.getNumerator() * r2.getDenominator();
    int denominator = r1.getDenominator() * r2.getNumerator();
    return Rational(numerator, denominator);
}

int main()
{
    Rational r1(2, 4);
    Rational r2(9, 3);

    Rational sum = addRationalNumber(r1, r2);
    cout << "Sum is : ";
    sum.print_Rational_Number();

    Rational product = multiRationalNumber(r1, r2);
    cout << "Product is : ";
    product.print_Rational_Number();

    Rational division = divRationalNumber(r1, r2);
    cout << "Division is : ";
    division.print_Rational_Number();
}