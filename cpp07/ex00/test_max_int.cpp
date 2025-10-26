#include <iostream>
#include <climits>
#include "whatever.hpp"

int main() {
    // Test con INT_MAX (valor máximo de int)
    int max_int1 = INT_MAX;
    int max_int2 = INT_MAX;
    
    std::cout << "=== TEST INT_MAX ===" << std::endl;
    std::cout << "max_int1 = " << max_int1 << std::endl;
    std::cout << "max_int2 = " << max_int2 << std::endl;
    
    // Test swap con INT_MAX
    std::cout << "\n--- SWAP con INT_MAX ---" << std::endl;
    ::swap(max_int1, max_int2);
    std::cout << "Después del swap:" << std::endl;
    std::cout << "max_int1 = " << max_int1 << std::endl;
    std::cout << "max_int2 = " << max_int2 << std::endl;
    
    // Test min/max con INT_MAX
    std::cout << "\n--- MIN/MAX con INT_MAX ---" << std::endl;
    std::cout << "min(max_int1, max_int2) = " << ::min(max_int1, max_int2) << std::endl;
    std::cout << "max(max_int1, max_int2) = " << ::max(max_int1, max_int2) << std::endl;
    
    // Test con INT_MAX e INT_MIN
    std::cout << "\n=== TEST INT_MAX vs INT_MIN ===" << std::endl;
    int max_val = INT_MAX;
    int min_val = INT_MIN;
    
    std::cout << "max_val (INT_MAX) = " << max_val << std::endl;
    std::cout << "min_val (INT_MIN) = " << min_val << std::endl;
    
    std::cout << "\n--- SWAP INT_MAX con INT_MIN ---" << std::endl;
    ::swap(max_val, min_val);
    std::cout << "Después del swap:" << std::endl;
    std::cout << "max_val = " << max_val << std::endl;
    std::cout << "min_val = " << min_val << std::endl;
    
    std::cout << "\n--- MIN/MAX INT_MAX vs INT_MIN ---" << std::endl;
    ::swap(max_val, min_val); // Restaurar valores originales
    std::cout << "min(INT_MAX, INT_MIN) = " << ::min(max_val, min_val) << std::endl;
    std::cout << "max(INT_MAX, INT_MIN) = " << ::max(max_val, min_val) << std::endl;
    
    return 0;
}
