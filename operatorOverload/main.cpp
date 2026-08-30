#include <iostream>
#include "Complex.h"
#include "Generic.h"
#include "STLVector.h"
#include "Rational.h"
#include "STLList.h"

using namespace std;

void showOperatorPLus()
{
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1.addUsingCurrentObj(c2);
    Complex c4 = c1 + c2;

    cout << c3 << endl;
    cout << c4 << endl;
    cout << endl;

    Complex c5 = c1 + 7;
    Complex c6 = c1.addAnInt(7);

    cout << c5 << endl;
    cout << c6 << endl;
    cout << endl;

    Complex c8 = 7 + c1;
    // Complex c100 = 7.operator+(c1);
    cout << c8 << endl;
    cout << endl;

    Rational r(4, 2);

    cout << r << endl;
}

void showOperatorPlusEqual()
{
    Complex c1(1, 2), c2(3, 4);

    cout << c1 << endl;

    c1 += c2 += c2;
    // void += c2

    cout << c1 << endl;
}

void showOperatorMinus()
{
    Complex c1(1, 2), c2(3, 4);

    Complex c3 = -c1;
    cout << c3 << endl;

    Complex c4 = c2 - c1;
    cout << c4 << endl;

    Complex c5 = c2 - 1;
    cout << c5 << endl;

    Complex c6 = 1 - c2;
    cout << c6 << endl;
}

void showOperatorAssign()
{
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1;

    cout << c1 << endl;
    cout << c2 << endl;

    c1 = c2;

    cout << c1 << endl;
    cout << c2 << endl;

    Rational r(1, 2);
    Rational r1(5, 7);

    cout << r << endl;
    cout << r1 << endl;

    r1 = r;

    cout << r1 << endl;
}

void showOperatorPlusPlus()
{
    Complex c1(1, 2), c2(3, 4);

    cout << c1 << endl;
    // 1 + 2i
    cout << ++c1 << endl;
    // 2 + 4i
    cout << c1 << endl;
    // 2 + 4i

    cout << endl;

    cout << c2 << endl;
    // 3 + 4i
    cout << c2++ << endl;
    // Copy constructor
    // 3 + 4i
    cout << c2 << endl;
    // 4 + 6i

    // int k = 0;

    // cout << k << endl;   // 0
    // // incrementare si return la noua valoare
    // cout << ++k << endl; // 1
    // cout << k << endl;   // 1
    // // incrementare si return la valoarea initiala
    // cout << k++ << endl; // 1
    // cout << k << endl;   // 2
}

int getMax(const int &a, const int &b)
{
    return a < b ? b : a;
}

// Complex getMax(const Complex& c1, const Complex& c2) {

// }

void showGeneric()
{
    int a = 1;
    int b = 2;

    int c = Generic<int>::maximum(a, b);

    cout << "max: " << c << endl;

    Complex c1(1, 2), c2(3, 4);

    if (c1 == c2)
    {
    }

    Complex c3 = Generic<Complex>::maximum(c1, c2);
    cout << "max: " << c3 << endl;

    Rational r1(1, 2), r2(3, 4);

    Rational rMax = Generic<Rational>::maximum(r1, r2);

    cout << "max " << rMax << endl;
}

void showSTLVector()
{
    STLVector<int> v;

    v.add(10);
    v.add(20);
    v.add(30);
    v.add(40);

    // v.showIterations();
    // v.showIterators();
    // v.showErase();

    v.add(7);
    v.add(6);
    v.add(5);
    // v.showSort();

    // STLVector<Complex> vcomplex;

    // vcomplex.add(Complex(3, 4));
    // vcomplex.add(Complex(1, 2));
    // vcomplex.add(Complex(5, 6));

    // vcomplex.showSort();

    v.add(0);
    v.add(0);
    // v.showFind();
    v.showReverse();
    // v.showCount();
}

void showSTLList()
{
    STLList<int> l;

    l.addBack(1);
    l.addBack(2);
    l.addFront(3);

    l.iterateThrough();
}

int main()
{
    // showOperatorPLus();
    // showOperatorPlusEqual();
    // showOperatorMinus();
    // showOperatorAssign();
    // showOperatorPlusPlus();
    // showGeneric();
    showSTLVector();
    // showSTLList();
}