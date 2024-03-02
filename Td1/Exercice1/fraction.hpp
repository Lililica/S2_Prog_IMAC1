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

    Fraction& operator+=(Fraction const& frac);

    Fraction& operator-=(Fraction const& frac);

    Fraction& operator*=(Fraction const& frac);
    Fraction& operator/=(Fraction const& frac);

    float to_float();
    operator float() const;

    Fraction& abs();
    int floor();
    int ceil();
    int round();
    

};

// Fraction::operator float() const;

void display(Fraction const& frac);

Fraction operator+(Fraction const& frac1, Fraction const& frac2);
Fraction operator-(Fraction const& frac1, Fraction const& frac2);
Fraction operator*(Fraction const& frac1, Fraction const& frac2);
Fraction operator/(Fraction const& frac1, Fraction const& frac2);

bool operator==(Fraction const& frac1, Fraction const& frac2);
bool operator!=(Fraction const& frac1, Fraction const& frac2);

bool operator<(Fraction const& frac1, Fraction const& frac2);
bool operator<=(Fraction const& frac1, Fraction const& frac2);
bool operator>(Fraction const& frac1, Fraction const& frac2);
bool operator>=(Fraction const& frac1, Fraction const& frac2);

std::ostream& operator<<(std::ostream& os, Fraction const& frac);

Fraction operator+(const Fraction& f, int const i);
Fraction operator+(int const i, const Fraction& f);
Fraction operator-(const Fraction& f, int const i);
Fraction operator-(int const i, const Fraction& f);
Fraction operator*(const Fraction& f, int const i);
Fraction operator*(int const i, const Fraction& f);
Fraction operator/(const Fraction& f, int const i);
Fraction operator/(int const i, const Fraction& f);

