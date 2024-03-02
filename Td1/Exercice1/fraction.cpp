#include "fraction.hpp"
#include <iostream>
#include "utils.hpp"

struct Fraction;


Fraction operator+(Fraction const& frac1, Fraction const& frac2){
    Fraction frac1_bis{frac1.numerateur*frac2.denominateur, frac1.denominateur*frac2.denominateur};
    Fraction frac2_bis{frac2.numerateur*frac1.denominateur, frac2.denominateur*frac1.denominateur};
    return simplify(Fraction{frac1_bis.numerateur + frac2_bis.numerateur, frac1_bis.denominateur});
}

Fraction operator-(Fraction const& frac1, Fraction const& frac2){
    Fraction frac1_bis{frac1.numerateur*frac2.denominateur, frac1.denominateur*frac2.denominateur};
    Fraction frac2_bis{frac2.numerateur*frac1.denominateur, frac2.denominateur*frac1.denominateur};
    int numerateur{};
    int denominateur{};
    if(frac1_bis.numerateur<frac2_bis.numerateur){
        numerateur = frac2_bis.numerateur - frac1_bis.numerateur;
    }
    else{
        numerateur = frac1_bis.numerateur - frac2_bis.numerateur;
    }
    denominateur = frac1_bis.denominateur;

    return simplify(Fraction{numerateur,denominateur});
}


Fraction operator*(Fraction const& frac1, Fraction const& frac2){
    return simplify(Fraction{frac1.numerateur*frac2.numerateur, frac1.denominateur*frac2.denominateur}) ;
}

Fraction operator/(Fraction const& frac1, Fraction const& frac2){
    return simplify(Fraction{frac1.numerateur*frac2.denominateur, frac1.denominateur*frac2.numerateur});
}

bool operator==(Fraction const& frac1, Fraction const& frac2){
    Fraction frac1b = simplify(frac1);
    Fraction frac2b = simplify(frac2);

    if((frac1b.numerateur == frac2b.numerateur)&&(frac1b.denominateur == frac2b.denominateur)){
        return true;
    }
    return false;
}

bool operator!=(Fraction const& frac1, Fraction const& frac2){
    return !(frac1==frac2);
}


void display(Fraction const& frac){
        std::cout << frac.numerateur << "/" << frac.denominateur << std::endl;
    }

std::ostream& operator<<(std::ostream& os, Fraction const& frac) {
    return os << frac.numerateur << "/" << frac.denominateur;
}

bool operator<(Fraction const& frac1, Fraction const& frac2){
    float nbrFrac1 {float(frac1.numerateur)/float(frac1.denominateur)};
    float nbrFrac2 {float(frac2.numerateur)/float(frac2.denominateur)};

    if(nbrFrac1 < nbrFrac2){
        return true;
    }
    return false;
}

bool operator<=(Fraction const& frac1, Fraction const& frac2){
    if(frac1<frac2 || frac1==frac2){
        return true;
    }
    return false;
}

bool operator>(Fraction const& frac1, Fraction const& frac2){
    return !(frac1<=frac2);
}

bool operator>=(Fraction const& frac1, Fraction const& frac2){
    return !(frac1<frac2);
}

Fraction& Fraction::operator+=(Fraction const& frac){
    Fraction initFrac {numerateur, denominateur};
    initFrac = initFrac + frac;
    simplify(initFrac);
    numerateur = initFrac.numerateur;
    denominateur = initFrac.denominateur;
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& frac){
    Fraction initFrac {numerateur, denominateur};
    initFrac = initFrac - frac;
    simplify(initFrac);
    numerateur = initFrac.numerateur;
    denominateur = initFrac.denominateur;
    return *this;
}

Fraction& Fraction::operator*=(Fraction const & frac){
    Fraction initFrac {numerateur, denominateur};
    initFrac = initFrac * frac;
    simplify(initFrac);
    numerateur = initFrac.numerateur;
    denominateur = initFrac.denominateur;
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& frac){
    Fraction initFrac {numerateur, denominateur};
    initFrac = initFrac / frac;
    simplify(initFrac);
    numerateur = initFrac.numerateur;
    denominateur = initFrac.denominateur;
    return *this;
}

float Fraction::to_float(){
    return (float(numerateur)/float(denominateur));
}

Fraction::operator float() const{
    return static_cast<float>(numerateur)/static_cast<float>(denominateur);
}

Fraction operator+(const Fraction& f, int const i){
    Fraction frac_bis{i*f.denominateur, f.denominateur};
    return simplify(Fraction{f.numerateur + frac_bis.numerateur, f.denominateur});
}

Fraction operator-(const Fraction& f, int const i){
    Fraction frac_bis{i*f.denominateur, f.denominateur};
    return simplify(Fraction{f.numerateur - frac_bis.numerateur, f.denominateur});
}

Fraction operator*(const Fraction& f, int const i){
    return simplify(Fraction{f.numerateur*i, f.denominateur});
}

Fraction operator/(const Fraction& f, int const i){
    return simplify(Fraction{f.numerateur, f.denominateur * i});
}

Fraction& Fraction::abs(){
    bool is_Num_Negatif{numerateur < 0};
    bool is_Den_Negatif{denominateur < 0};
    if(is_Num_Negatif){
        numerateur = -(numerateur);
    }
    if(is_Den_Negatif){
        denominateur = -(denominateur);
    }
    return *this;
}

int Fraction::floor(){
    bool is_Num_Negatif{numerateur < 0};
    bool is_Den_Negatif{denominateur < 0};
    if((is_Num_Negatif & !is_Den_Negatif) || (!is_Num_Negatif & is_Den_Negatif)){
        return int(float(*this)) - 1;
    }
    return int(float(*this));
}

int Fraction::ceil(){
    bool is_Num_Negatif{numerateur < 0};
    bool is_Den_Negatif{denominateur < 0};
    if((is_Num_Negatif & !is_Den_Negatif) || (!is_Num_Negatif & is_Den_Negatif)){
        return int(float(*this));
    }
    return int(float(*this)) + 1;
}

int Fraction::round(){
    bool is_Num_Negatif{numerateur < 0};
    bool is_Den_Negatif{denominateur < 0};
    Fraction f {numerateur, denominateur};
    if((is_Num_Negatif & !is_Den_Negatif) || (!is_Num_Negatif & is_Den_Negatif)){
        if(float(f - f.ceil()) <= -0.5 ){
            return f.floor();
        }
        return f.ceil();
    }
    if(float(f - f.floor()) >= 0.5 ){
        return f.ceil();
    }
    return f.floor();
}

