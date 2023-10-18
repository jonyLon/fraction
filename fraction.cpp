#include <iostream>
#include <string>
using namespace std;


class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(const int& num, const int& dnum) {
        this->numerator = num;
        this->denominator = dnum;
    }
    int cutnum() {
        for (int i = 500; i > 1; i--)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0) {
                return i;
                break;
            }
        }
        return 1;
        
    }
    string print() {
        if (this->numerator == 0) {
            return to_string(this->numerator);
        }

        return to_string(this->numerator / cutnum()) + "/" + to_string(this->denominator / cutnum());
    }

    Fraction sum(const Fraction& other) {
        int dnum = this->denominator * other.denominator;
        int num = this->numerator * other.denominator + other.numerator * this->denominator;
        Fraction res(num, dnum);
        return res;
    }
    Fraction sub(const Fraction& other) {
        int dnum = this->denominator * other.denominator;
        int num = this->numerator * other.denominator - other.numerator * this->denominator;
        Fraction res(num, dnum);
        return res;
    }
    Fraction mult(const Fraction& other) {
        int dnum = this->denominator * other.denominator;
        int num = this->numerator * other.numerator;
        Fraction res(num, dnum);
        return res;
    }
    Fraction div(const Fraction& other) {
        int dnum = this->denominator * other.numerator;
        int num = this->numerator * other.denominator;
        Fraction res(num, dnum);
        return res;
    }

};





int main()
{
    Fraction First(1, 5);
    Fraction Second(3, 10);

    Fraction Sum = First.sum(Second);
    Fraction Sub = First.sub(Second);
    Fraction Mult = First.mult(Second);
    Fraction Div = First.div(Second);

    cout << First.print()  + " + " + Second.print() + " = " + Sum.print() << endl;
    cout << First.print() + " - " + Second.print() + " = " + Sub.print() << endl;
    cout << First.print() + " * " + Second.print() + " = " + Mult.print() << endl;
    cout << First.print() + " / " + Second.print() + " = " + Div.print() << endl;
}


