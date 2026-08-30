#include "geometric_vectors/domain/Point.h"
#include "geometric_vectors/domain/Vector.h"
#include <iostream>
#include <cmath>

// ── 1. Default parameters ────────────────────────────────────────────────────
// Creates a Point; coordinates default to 0 if not provided.
Point makePoint(double x = 0.0, double y = 0.0)
{
    return Point(x, y);
}

void testDefaultParams()
{
    std::cout << "=== Default Parameters ===" << std::endl;
    Point p1 = makePoint(3.0, 4.0); // both provided
    Point p2 = makePoint(3.0);      // y defaults to 0
    Point p3 = makePoint();         // both default to 0
    std::cout << "makePoint(3, 4): " << p1 << std::endl;
    std::cout << "makePoint(3):    " << p2 << std::endl;
    std::cout << "makePoint():     " << p3 << std::endl;
}

// ── 2. Function overloading ──────────────────────────────────────────────────
// Same function name 'describe', different parameter types.
void describe(const Point &p)
{
    double dist = std::sqrt(p.getX() * p.getX() + p.getY() * p.getY());
    std::cout << "Point " << p << ", distance from origin: " << dist << std::endl;
}

void describe(const Vector &v)
{
    double dx = v.getEnd().getX() - v.getStart().getX();
    double dy = v.getEnd().getY() - v.getStart().getY();
    double magnitude = std::sqrt(dx * dx + dy * dy);
    std::cout << "Vector " << v << ", magnitude: " << magnitude << std::endl;
}

void testOverloading()
{
    std::cout << "\n=== Function Overloading ===" << std::endl;
    Point p(3, 4);
    Vector v(Point(0, 0), Point(3, 4));
    describe(p); // calls describe(const Point&)
    describe(v); // calls describe(const Vector&)
}

// ── 3. Reference type (&) ────────────────────────────────────────────────────
// Translates a Point in-place (pass by reference — no copy made).
// void translate(Point &p, double dx, double dy)
// {
//     p.setX(p.getX() + dx);
//     p.setY(p.getY() + dy);
// }

void translate(Point p, double dx, double dy)
{
    p.setX(p.getX() + dx);
    p.setY(p.getY() + dy);
}

// Swaps two Points by reference.
void swapPoints(Point &a, Point &b)
{
    Point temp = a;
    a = b;
    b = temp;
}

void testReferences()
{
    std::cout << "\n=== References (&) ===" << std::endl;
    Point p(1, 2);
    std::cout << "Before translate: " << p << std::endl;
    translate(p, 3, 4);
    std::cout << "After translate(3,4): " << p << std::endl;

    Point a(1, 2), b(5, 6);
    std::cout << "Before swap: a=" << a << ", b=" << b << std::endl;
    swapPoints(a, b);
    std::cout << "After swap:  a=" << a << ", b=" << b << std::endl;
}

// ── 4. new / delete ──────────────────────────────────────────────────────────
void testNewDelete()
{
    std::cout << "\n=== new / delete ===" << std::endl;

    // Single object
    Point *p = new Point(1, 2);
    std::cout << "Allocated Point: " << *p << std::endl;
    delete p;

    // Array of objects
    int n = 3;
    Vector *vectors = new Vector[n];
    vectors[0] = Vector(Point(0, 0), Point(1, 0));
    vectors[1] = Vector(Point(0, 0), Point(0, 1));
    vectors[2] = vectors[0] + vectors[1]; // (1,0) + (0,1) = (1,1)
    for (int i = 0; i < n; i++)
        std::cout << "vectors[" << i << "]: " << vectors[i] << std::endl;
    delete[] vectors;
}

// ── 5. cin / cout ────────────────────────────────────────────────────────────
void testCinCout()
{
    std::cout << "\n=== cin / cout ===" << std::endl;
    double x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    Point p(x, y);
    Vector v(p); // vector from origin to p
    std::cout << "Point entered: " << p << std::endl;
    std::cout << "Vector to that point: " << v << std::endl;
}

// ── main ─────────────────────────────────────────────────────────────────────





void add_to_point(Point& p, double x = 5, double y = 2) {
    p.setX(p.getX() + x);
    p.setY(p.getY() + y);
}

void add_to_point1(Point p, double x) {
    p.setX(p.getX() + x);
    std::cout << p << std::endl;
}


void testAddToPoint() {
    Point p(1, 1);
    
    add_to_point(p, 2, 5);
    std::cout << p << std::endl;

    Point q(2, 2);
    add_to_point1(q, 7);
    std::cout << q << std::endl;

}





void addPoint() {
    Point p(1, 2);
    Point q(2, 1);
    Point a = p.operator+(q);

    std::cout << p <<std::endl;
    std::cout << q <<std::endl;
    std::cout << a <<std::endl;
    std::cout << p <<std::endl;
    std::cout << q <<std::endl;
}















int main()
{
    // testDefaultParams();
    // testOverloading();
    // testReferences();
    // testNewDelete();
    // testCinCout(); // uncomment to demo interactive cin/cout

    testAddToPoint();
    return 0;
}
