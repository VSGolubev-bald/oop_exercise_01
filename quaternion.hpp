//
// Created by Вова on 28.10.2019.
//

#ifndef LAB1_QUATERNION_HPP
#define LAB1_QUATERNION_HPP
struct quaternion {
    quaternion ();
    quaternion (double real, double x, double y, double z);
    void print();
    quaternion sum(const quaternion& a);
    quaternion diff(const quaternion& a);
    quaternion mult(const quaternion& b);
    quaternion div(const quaternion &b);
private:
    double array[4];
};
#endif //L{}{}AB1_QUATERNION_HPP
