#pragma once
#include "utils.hpp"
#include <iostream> 



struct Fraction
{
    int numerateur{0};
    int denominateur{1};


    // void Fraction::add(Fraction & frac1, Fraction & frac2);
    // void Fraction::sub(Fraction & frac1, Fraction & frac2);
    // void Fraction::mul(Fraction & frac1, Fraction & frac2);
    // void Fraction::div(Fraction & frac1, Fraction & frac2);

    Fraction& operator+=(Fraction & frac);

    Fraction& operator-=(Fraction & frac);

    Fraction& operator*=(Fraction & frac);
    Fraction& operator/=(Fraction & frac);

    float to_float();
    operator float() const;

    Fraction& abs();
    int floor();
    int ceil();
    int round();
    

};

// Fraction::operator float() const;

void display(Fraction frac);

Fraction operator+(Fraction & frac1, Fraction & frac2);
Fraction operator-(Fraction & frac1, Fraction & frac2);
Fraction operator*(Fraction & frac1, Fraction & frac2);
Fraction operator/(Fraction & frac1, Fraction & frac2);

bool operator==(Fraction frac1, Fraction frac2);
bool operator!=(Fraction frac1, Fraction frac2);

bool operator<(Fraction frac1, Fraction frac2);
bool operator<=(Fraction frac1, Fraction frac2);
bool operator>(Fraction frac1, Fraction frac2);
bool operator>=(Fraction frac1, Fraction frac2);

std::ostream& operator<<(std::ostream& os, Fraction const& frac);

Fraction operator+(const Fraction& f, int const i);
Fraction operator-(const Fraction& f, int const i);
Fraction operator*(const Fraction& f, int const i);
Fraction operator/(const Fraction& f, int const i);

