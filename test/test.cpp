#include "Mod.hpp"

int main() {
    ModularArithmetic math214 = ModularArithmetic(12, 5);
    std::cout << math214 << std::endl;

    ModularArithmetic math215 = ModularArithmetic(3, 2);
    std::cout << math215 << std::endl;

    ModularArithmetic math230 = math214 + math215;
    std::cout << math230 << std::endl;
    ModularArithmetic math260 = math214 - math215;
    std::cout << math260 << std::endl;
    ModularArithmetic math270 = math214 * math215;
    std::cout << math270 << std::endl;
    ModularArithmetic math280 = math214 / math215;
    std::cout << math280 << std::endl;

    math230 += 2;
    std::cout << math230 << std::endl;
    math230 -= 13;
    std::cout << math230 << std::endl;
    
    
    math230 *= 3;
    std::cout << math230 << std::endl;
    math230 /= 10;
    std::cout << math230 << std::endl;

    math230++;
    std::cout << math230 << std::endl;
    math230--;
    std::cout << math230 << std::endl;

    std::cout << +math230 << std::endl;
    std::cout << -math230 << std::endl;
    // std::cout << ~math230 << std::endl;
    ModularArithmetic math250 = ModularArithmetic(17, 6);
    std::cout << ~math250 << std::endl;

    std::cout << (~math250 == math230) << std::endl;
    std::cout << (~math250 == ModularArithmetic(5, 1000)) << std::endl;

    std::cout << (~math250 <= ModularArithmetic(5, 1000)) << std::endl;
    std::cout << (~math250 < ModularArithmetic(5, 1000)) << std::endl;
    std::cout << (~math250 > ModularArithmetic(5, 1000)) << std::endl;
    std::cout << (~math250 >= ModularArithmetic(323423, 1000)) << std::endl;
    
    std::cout << GCD(15, 4) << std::endl;
    std::cout << LCM(15, 4) << std::endl;
    std::cout << modulo(-8, 10) << std::endl;

    return 0;
}