#include <iostream>
#include <cmath>
#include "quaternion.hpp"
quaternion::quaternion() {
    for (int i = 0; i < 4; ++i) {
        array[i] = 0;
    }
}
quaternion::quaternion (double real, double x, double y, double z) {
    array[0] = real;
    array[1] = x;
    array[2] = y;
    array[3] = z;
}
quaternion quaternion::sum(const quaternion &a) {
    quaternion res;
    for (int i = 0; i < 4; ++i) {
        res.array[i] = array[i] + a.array[i];
    }
    return res;
}
quaternion quaternion::diff(const quaternion &a) {
    quaternion res;
    for (int i = 0; i < 4; ++i) {
        res.array[i] = array[i] - a.array[i];
    }
    return res;
}
quaternion quaternion::mult(const quaternion &b) {
    quaternion res;
    res.array[0] = array[0] * b.array[0] - array[1] * b.array[1] - array[2] * b.array[2] - array[3] * b.array[3];
    res.array[1] = array[0] * b.array[1] + array[1] * b.array[0] + array[2] * b.array[3] - array[3] - b.array[2];
    res.array[2] = array[0] * b.array[2] + array[2] * b.array[0] + array[3] * b.array[1] - array[1] * b.array[3];
    res.array[3] = array[0] * b.array[3] + array[3] * b.array[0] +  array[1] * b.array[2] - array[2] * b.array[1];
    return res;
}
quaternion quaternion::div(const quaternion &b) {

    quaternion conjugate;
    double VectNorm;
    quaternion reverse;
    quaternion res;
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            conjugate.array[i] = b.array[i];
        } else {
            conjugate.array[i] = -b.array[i];
        }
    }
    VectNorm = sqrt(
            b.array[0] * b.array[0] + b.array[1] * b.array[1] + b.array[2] * b.array[2] + b.array[3] * b.array[3]);
    for (int i = 0; i < 4; ++i) {
        reverse.array[i] = conjugate.array[i] / (VectNorm * VectNorm);
    }
    for (int i = 0; i < 4; ++i) {
        res.array[i] = array[i] * reverse.array[i];
    }
    return res;
}
void quaternion::print() {
    std::cout << array[0] << " " "+" << " " << "(" << array[1] << ")" << "i" <<" " "+" <<" " << "(" << array[2]<< ")" "j" << " " "+" << " " << "(" << array[3] << ")" << "k" << std::endl;
}