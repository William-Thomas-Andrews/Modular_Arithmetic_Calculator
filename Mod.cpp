#include "Mod.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits>
#include <climits>
#include <variant>
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <numeric>


int GCD(int m, int v) // m represents modulus and v represents value, but arbitrary numbers a and b work fine too.
    {
        if (m == 0 && v != 0)
        {
            return v;
        }
        if (m != 0 && v == 0)
        {
            return m;
        }
        if (m == 0 && v == 0)
        {
            return 0;
        }
        int mod = m;
        int val = v;
        int rem = std::min(m, v);
        int prev_rem = 0;
        do
        {
            prev_rem = rem;
            rem = mod - ((mod / val) * val);
            mod = val;
            val = rem;
        } while (rem != 0);

        return prev_rem;
    }

int LCM(int a, int b)
{
    return ((a * b) / (GCD(a, b)));
}



// Constructor
ModularArithmetic::ModularArithmetic(int mod) : value(0), modulus(mod), result(mod==0 ? std::variant<int, std::string>("Undefined") : 0) {}

// Constructor 
ModularArithmetic::ModularArithmetic(int val, int mod) : value(val), modulus(mod), result(mod==0 ? std::variant<int, std::string>("Undefined") : modulo(val, mod)) {}

// Copy Constructor
ModularArithmetic::ModularArithmetic(const ModularArithmetic& t) 
{
    value = t.value;
    modulus = t.modulus;
    result = t.result;
    std::cout << "Copy Constructor Called" << std::endl;
}

ModularArithmetic& ModularArithmetic::operator=(const ModularArithmetic& a)
{
    if (this != &a)
    {
        value = a.value;
        modulus = a.modulus;
        result = a.result;
        // std::cout << "Copy Assingment Initiated" << std::endl;
    }
    return *this;
}





std::ostream& operator<<(std::ostream& os, const ModularArithmetic& obj)
{
    os << obj.value << " mod(" << obj.modulus << ") ≡ ";
    std::visit([&os](auto&& val)
    { 
        os << val; 
    }, obj.result);
    return os;
}

ModularArithmetic operator+(const ModularArithmetic& op1, const ModularArithmetic& op2)
{
    if (op1.modulus == 0 || op2.modulus == 0)
    {
        throw std::invalid_argument("Cannot add 'Undefined'");
        return ModularArithmetic(0, 1);
    }
    else if (op1.modulus == op2.modulus) // if the moduli are equal; the normal case
    {
        ModularArithmetic temp = ModularArithmetic((op1.value+op2.value), op1.modulus);
        return temp;
    }
    else if (op1.modulus != op2.modulus)
    {
        int new_modulus = std::lcm(op1.modulus, op2.modulus);
        int new_op1 = (new_modulus / op1.modulus) * op1.value;
        int new_op2 = (new_modulus / op2.modulus) * op2.value;
        int new_op = new_op1 + new_op2;
        ModularArithmetic temp = ModularArithmetic(new_op, new_modulus);
        return temp;
    }
    return ModularArithmetic(0, 1);
}

ModularArithmetic operator-(const ModularArithmetic& op1, const ModularArithmetic& op2)
{
    if (op1.modulus == 0 || op2.modulus == 0)
    {
        throw std::invalid_argument("Cannot add 'Undefined'");
    }
    else if (op1.modulus == op2.modulus) // if the moduli are equal; the normal case
    {
        ModularArithmetic temp = ModularArithmetic((op1.value+op2.value), op1.modulus);
        return temp;
    }
    else if (op1.modulus != op2.modulus)
    {
        int new_modulus = std::lcm(op1.modulus, op2.modulus);
        int new_op1 = (new_modulus / op1.modulus) * op1.value;
        int new_op2 = (new_modulus / op2.modulus) * op2.value;
        int new_op = new_op1 - new_op2;
        return ModularArithmetic(new_op, new_modulus);
    }
}


int modulo(int a, int b) // A more mathematical modulo operation
{
    if (a < 0)
    {
        // return (a%b) + b;
        return (a - (b * std::floor(a/b))) + b;
    }
    else return (a - (b * std::floor(a/b)));
}


void ModularArithmetic::operator+=(int n)
{
    value += n;
    result = modulo(value, modulus);
}
void ModularArithmetic::operator-=(int n)
{
    value -= n;
    result = modulo(value, modulus);
}
void ModularArithmetic::operator*=(int n)
{
    value *= n;
    result = modulo(value, modulus);
}
void ModularArithmetic::operator/=(int n)
{
    value /= n;
    result = modulo(value, modulus);
}
void ModularArithmetic::operator++(int n)
{
    value += 1;
    result = modulo(value, modulus);
}
void ModularArithmetic::operator--(int n)
{
    value -= 1;
    result = modulo(value, modulus);
}
ModularArithmetic ModularArithmetic::operator+() //unary +
{
    return ModularArithmetic(value, modulus);
}
ModularArithmetic ModularArithmetic::operator-() //unary -
{
    return ModularArithmetic((-value), modulus);
}
ModularArithmetic ModularArithmetic::operator~() // Modulus complement ~ 
{
    // int gcd = std::gcd(value, modulus);
    int gcd = GCD(value, modulus);
    if (gcd != 1)
    {
        throw std::invalid_argument("GCD ≠ 1, so there is no multiplicative inverse.");
    }
    else
    {
        for (int i = 1; i <= modulus; i++)
        {
            if ((modulo((i * value), modulus)) == 1)
            {
                return ModularArithmetic(i, modulus);
            }
        }
    }
}
ModularArithmetic::~ModularArithmetic() = default;