#include <iostream>
#include <cmath>
#include "quaternion.hpp"

int main() {
    double q1, x1, y1, z1;
    double q2, x2, y2, z2;
    std::cout << "Enter quaternions" << std::endl;
    std::cin >> q1 >> x1 >> y1 >> z1 >> q2 >> x2 >> y2 >> z2;
    quaternion V1{q1, x1, y1, z1};
    quaternion V2{q2, x2, y2, z2};
    std::cout << " H1 :" << std::endl;
    V1.print();
    std::cout << "H2:" << std::endl;
    V2.print();
    std::cout << "Sum is :" << std::endl;
    V1.sum(V2).print();
    std::cout << "Difference is :" << std::endl;
    V1.diff(V2).print();
    std::cout << "Product is :" << std::endl;
    V1.mult(V2).print();
    std::cout << "Quotient is :" << std::endl;
    V1.div(V2).print();
    return 0;
}