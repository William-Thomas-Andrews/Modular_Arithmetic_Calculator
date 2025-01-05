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



class ModularArithmetic
{
    private:
        std::variant<int, std::string> result;

    public:
        int value;
        int modulus;
        ModularArithmetic(int mod) : value(0), modulus(mod), result(mod==0 ? std::variant<int, std::string>("Undefined") : 0) {}
        ModularArithmetic(int val, int mod) : value(val), modulus(mod), result(mod==0 ? std::variant<int, std::string>("Undefined") : val%mod) {}
        ModularArithmetic(const ModularArithmetic& t) 
        {
            value = t.value;
            modulus = t.modulus;
            result = t.result;
            std::cout << "Copy Constructor Called" << std::endl;
        }
        ModularArithmetic& operator=(const ModularArithmetic& a)
        {
            value = a.value;
            modulus = a.modulus;
            result = a.result;
            std::cout << "Copy Assingment Initiated" << std::endl;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const ModularArithmetic& obj);
        friend ModularArithmetic operator+(const ModularArithmetic& op1, const ModularArithmetic& op2);
        
        void operator+=(int n)
        {
            value += n;
            result = value%modulus;
        }
        void operator-=(int n)
        {
            value -= n;
            result = value%modulus;
        }
        void operator*=(int n)
        {
            value *= n;
            result = value%modulus;
        }
        void operator/=(int n)
        {
            value /= n;
            result = value%modulus;
        }
        void operator++(int n)
        {
            value += 1;
            result = value%modulus;
        }
        void operator--(int n)
        {
            value -= 1;
            result = value%modulus;
        }
        ModularArithmetic operator+() //unary +
        {
            value *= +1;
            return *this;
        }
        ModularArithmetic operator-() //unary -
        {
            value *= -1;
            return *this;
        }
        // int recExtended(int a, int b)
        // {

        // }
        // int extendedEuclideanAlgorithm()
        // {
        //     int mod = modulus;
        //     int val = value;
        //     int rem;
        //     std::map<int, int> mp {};
        //     do
        //     {
        //         rem = mod - ((mod / val) * val);
        //         mod = val;
        //         val = rem;
        //     } while (rem != 1);
            
        //     return ;
        // }
        ModularArithmetic operator~() //Modulus complement ~ 
        {
            int gcd = std::gcd(value, modulus);
            if (gcd != 1)
            {
                throw std::invalid_argument("GCD ≠ 1, so there is no multiplicative inverse.");
            }
            else
            {
                for (int i = 1; i <= modulus; i++)
                {
                    if (((i * value) % modulus) == 1)
                    {
                        return ModularArithmetic(i, modulus);
                    }
                }
            }
        }
        ~ModularArithmetic() = default;
};


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
        int new_op = new_op1 + new_op2;
        ModularArithmetic temp = ModularArithmetic(new_op, new_modulus);
        return temp;
    }
}



int main()
{
    // ModularArithmetic math214 = ModularArithmetic(43, 8);
    // std::cout << math214 << std::endl;
    // ModularArithmetic math215 = math214;
    // std::cout << math215 << std::endl;
    // ModularArithmetic math216 = ModularArithmetic(43, 8000);
    // std::cout << math216 << std::endl;
    // math214 = math216;
    // std::cout << math214 << std::endl;
    // math214 += 2;
    // std::cout << math214 << std::endl;
    // math214 -= 13;
    // std::cout << math214 << std::endl;
    ModularArithmetic math214 = ModularArithmetic(12, 5);
    std::cout << math214 << std::endl;
    ModularArithmetic math215 = ModularArithmetic(3, 2);
    std::cout << math215 << std::endl;
    ModularArithmetic math2000 = math214 + math215;
    std::cout << math2000 << std::endl;
    ModularArithmetic math241 = ModularArithmetic(3, 1);
    std::cout << math241 << std::endl;
    math241 = -math241;
    std::cout << math241 << std::endl;
    std::cout << ~math214 << std::endl;
    // std::cout << math214 + math241 << std::endl;
    return 0;
}