#include <iostream>
#include "testScurt.h"
#include "testExtins.h"
int main() {
    testAll();
    testAllExtins();
    std::cout << "OK" << '\n';
    return 0;
}
