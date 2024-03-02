#include "utils.hpp"
#include "fraction.hpp"
#include <iostream>


int gcd(int a, int b){
    int back{0};
    if(b>a){
        int rest{a};
        while(rest != 0){
            back = rest;
            rest = b%a;
            b = a;
            a = rest;
        }
        return back;
    }
    int rest{b};
    while(rest != 0){
        back = rest;
        rest = a%b;
        a = b;
        b = rest;
    }
    return back;
}

Fraction simplify(Fraction frac){
    int n {abs(frac.numerateur)};
    int d {abs(frac.denominateur)};
    int pgcd{gcd(n,d)};
    frac.numerateur /= pgcd;
    frac.denominateur /= pgcd;
    return frac;
}