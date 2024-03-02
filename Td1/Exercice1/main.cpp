#include <iostream>
#include "fraction.hpp"

int main(){
    std::cout << "Exercice 1 - Td1" << std::endl;
    std::cout << std::endl;

    Fraction f1 {9, 10};
    Fraction f2 {3, 4};

    display(f1 + f2);

    std::cout << std::endl;
    std::cout << "Exercice 2 - Td1" << std::endl;
    std::cout << std::endl;

    std::cout << f1 + f2 << std::endl;

    std::cout << std::endl;
    std::cout << "Exercice 3 - Td1" << std::endl;
    std::cout << std::endl;

    std::cout << "f1 != f2 : " << (f1 != f2) << std::endl;
    std::cout << "f1 == f2 : " << (f1 == f2) << std::endl;

    std::cout << std::endl;
    std::cout << "Exercice 4 - Td1" << std::endl;
    std::cout << std::endl;

    std::cout << "f1 < f2 : " << (f1 < f2) << std::endl;
    std::cout << "f1 <= f2 : " << (f1 <= f2) << std::endl;
    std::cout << "f1 > f2 : " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2 : " << (f1 >= f2) << std::endl;

    std::cout << std::endl;
    std::cout << "Exercice 5 - Td1" << std::endl;
    std::cout << std::endl;

    f1 += f2;
    std::cout << "f1 += f2 : " << f1 << std::endl;
    f1 -= f2;
    std::cout << "f1 -= f2 : " << f1 << std::endl;

    std::cout << std::endl;
    std::cout << "Exercice 6 - Td1" << std::endl;
    std::cout << std::endl;

    std::cout << "float(f1) : " << float(f1) << std::endl;

    std::cout << std::endl;
    std::cout << "Pour aller plus loin..." << std::endl;
    std::cout << std::endl;

    std::cout << "f1 + 2 : " << f1 + 2 << std::endl;
    std::cout << "f1 - 2 : " << f1 - 2 << std::endl;
    std::cout << "f1 * 2 : " << f1 * 2 << std::endl;
    std::cout << "f1 / 2 : " << f1 / 2 << std::endl;
    
    std::cout << std::endl;
    Fraction f3 {-34, 25};
    std::cout << "f3 : " << f3 << std::endl;
    std::cout << "f3.abs() : " << f3.abs() << std::endl;
    f3 = Fraction{-34, 25};
    std::cout << "f3.ceil() : " << f3.ceil() << std::endl;
    std::cout << "f1.ceil() : " << f1.ceil() << std::endl;
    std::cout << "f3.floor() : " << f3.floor() << std::endl;
    std::cout << "f1.floor() : " << f1.floor() << std::endl;
    std::cout << "f3.round() : " << f3.round() << std::endl;
    std::cout << "f1.round() : " << f1.round() << std::endl;
    std::cout << "Fraction{2, 5}.round() : " << Fraction{2, 5}.round() << std::endl;
    std::cout << "Fraction{3, 5}.round() : " << Fraction{3, 5}.round() << std::endl;

}