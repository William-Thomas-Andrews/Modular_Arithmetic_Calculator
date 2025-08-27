# Modular Arithmetic Calculator

This is a calculator program that takes in two arguments V (value) and M (modulus), in the mathematical formula: V mod(M) ≡ Result. The result is calculated by the class itself. 

## The construction is as follows:

ModularArithmetic math214 = ModularArithmetic(12, 5);

std::cout << math214 << std::endl;

### 12 mod(5) ≡ 2

## Features
- ### Object-oriented design: 
A ModularArithmetic class that automatically calculates results from (value, modulus) pairs.

- ### Operator overloading; supports:

- Arithmetic operators: +, -, *, /

- Compound operators: +=, -=, *=, /=

- Increment/decrement: ++, --

- Unary operators: +, -, and ~ (modular inverse)

- Comparison operators: ==, <, <=, >, >=, <=>

- Stream output: <<

- ### Automatic LCM handling:
If two modular expressions have different moduli, the calculator converts them into a common modulus using the least common multiple.

- ### Mathematical helpers:
Includes standalone GCD, LCM, and modulo functions.

- ### Error safety:
Throws exceptions (e.g., when attempting to compute a modular inverse when GCD(value, modulus) ≠ 1).


## Requirements
- C++20 or later  
- CMake (for build system)  

## Installation and running the program
```bash
# Clone the repository
git clone https://github.com/William-Thomas-Andrews/Modular_Arithmetic_Calculator.git
cd Modular_Arithmetic_Calculator

# Build
cd scripts/
./configure.sh
./build.sh
./run.sh
```

---

# Examples:

## The +, -, *, / and << operators:
ModularArithmetic math215 = ModularArithmetic(3, 2);

ModularArithmetic math230 = math214 + math215;

std::cout << math230 << std::endl;

### 39 mod(10) ≡ 9

ModularArithmetic math260 = math214 - math215;

std::cout << math260 << std::endl;

### 9 mod(10) ≡ 9

ModularArithmetic math270 = math214 * math215;

std::cout << math270 << std::endl;

### 360 mod(10) ≡ 0

ModularArithmetic math280 = math214 / math215;

std::cout << math280 << std::endl;
    
### 1 mod(10) ≡ 1

#### When moduli don't match, we use the Least Common Multiple to put both expressions in the same terms of 
#### modulus, then we add them together.

___

## The += and -= operators:

math230 += 2;

std::cout << math230 << std::endl;

### 41 mod(10) ≡ 1

math230 -= 13;

std::cout << math230 << std::endl;

### 28 mod(10) ≡ 8

___

## The *= and /= operators:

math230 *= 3;

std::cout << math230 << std::endl;

### 84 mod(10) ≡ 4

math230 /= 10;

std::cout << math230 << std::endl;

### 8 mod(10) ≡ 8

___

## The ++, -- operators:

math230++;

std::cout << math230 << std::endl;

### 9 mod(10) ≡ 9

math230--

std::cout << math230 << std::endl;

### 8 mod(10) ≡ 9

___

## The unary +, -, and ~ operators:

## + and - do as you would expect to the value, not the modulus, but the ~ does something more interesting: it calculates the multiplicative inverse of P mod(N)

std::cout << +math230 << std::endl;

### 8 mod(10) ≡ 8

std::cout << -math230 << std::endl;

### -8 mod(10) ≡ 2

std::cout << ~math230 << std::endl;

### libc++abi: terminating due to uncaught exception of type 
### std::invalid_argument: GCD ≠ 1, so there is no multiplicative inverse.
### zsh: abort      ./a.out

#### As per the rules of modular inverses, there is no multiplicative inverse for two numbers in a modular 
#### expression whose GCD ≠ 1

ModularArithmetic math250 = ModularArithmetic(17, 6);

std::cout << ~math250 << std::endl;

### 5 mod(6) ≡ 5

___

## All of the comparison operators are also included, which compare only the result of the modular expression, not the Value or Modulus:
std::cout << (~math250 == math230) << std::endl;
### 0
std::cout << (~math250 == ModularArithmetic(5, 1000)) << std::endl;
### 1
std::cout << (~math250 <= ModularArithmetic(5, 1000)) << std::endl;
### 1
std::cout << (~math250 < ModularArithmetic(5, 1000)) << std::endl;
### 0
std::cout << (~math250 > ModularArithmetic(5, 1000)) << std::endl;
### 0
std::cout << (~math250 >= ModularArithmetic(323423, 1000)) << std::endl;
### 0

___

## We also have new basic GCD, LCM, and Modulo functions available

std::cout << GCD(15, 4) << std::endl;

### 1

std::cout << LCM(15, 4) << std::endl;

### 60

std::cout << modulo(-8, 10) << std::endl;

### 2