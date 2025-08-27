#pragma once

#include <iostream>
#include <variant>


// The standard GCD(a, b)
int GCD(int a, int b);

// The standard LCM(a, b)
int LCM(int a, int b);

// Modulo Function - standard % but now works for negative values
int modulo(int a, int b);

class ModularArithmetic {
    private:
        std::variant<int, std::string> result;
        int value;
        int modulus;

    public:

        // Constructors
        ModularArithmetic(int mod);
        ModularArithmetic(int val, int mod);
        
        // Copy Constructor
        ModularArithmetic(const ModularArithmetic& t);

        // Assignment Operator
        ModularArithmetic& operator=(const ModularArithmetic& a);

        // Friend Functions
        friend std::ostream& operator<<(std::ostream& os, const ModularArithmetic& obj);
        friend ModularArithmetic operator+(const ModularArithmetic& op1, const ModularArithmetic& op2);
        friend ModularArithmetic operator-(const ModularArithmetic& op1, const ModularArithmetic& op2);
        friend ModularArithmetic operator*(const ModularArithmetic& op1, const ModularArithmetic& op2);
        friend ModularArithmetic operator/(const ModularArithmetic& op1, const ModularArithmetic& op2);

        // Friend Comparison Operators
        friend bool operator==(const ModularArithmetic& op1, const ModularArithmetic& op2);
        friend std::strong_ordering operator<=>(const ModularArithmetic& op1, const ModularArithmetic& op2);
        

        // Arithmetic Operators
        void operator+=(int n);
        void operator-=(int n);
        void operator*=(int n);
        void operator/=(int n);
        void operator++(int n);
        void operator--(int n);

        // Unary Operators
        ModularArithmetic operator+(); //unary +
        ModularArithmetic operator-(); //unary -

        // Modulus Complement
        ModularArithmetic operator~(); //Modulus complement ~

        // Destructor
        ~ModularArithmetic();
};