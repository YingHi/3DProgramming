#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:
    float x, y, z;

    Vector() {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float a, float b, float c) { // 빈 벡터 생성자
        x = a;
        y - b;
        z = c;
    }

};
class Matrix { // Matrix 클래스
public:
    float element[3][3]; // 원소 2차원 배열
    Matrix() { // 행렬 생성자
        element[0][0] = 0;
        element[0][1] = 0;
        element[0][2] = 0;
        element[1][0] = 0;
        element[1][1] = 0;
        element[1][2] = 0;
        element[2][0] = 0;
        element[2][1] = 0;
        element[2][2] = 0;
    } // 생성자

    Matrix(float one_1, float one_2, float one_3, float two_1, float two_2, float two_3, float three_1, float three_2, float three_3) { // 행렬 생성자
        element[0][0] = one_1;
        element[0][1] = one_2;
        element[0][2] = one_3;
        element[1][0] = two_1;
        element[1][1] = two_2;
        element[1][2] = two_3;
        element[2][0] = three_1;
        element[2][1] = three_2;
        element[2][2] = three_3;
    } // 생성자

    Matrix operator *(Matrix& m) // 행렬 x 행렬
    {
        Matrix ResultMat(element[0][0], element[0][1], element[0][2], element[1][0], element[1][1], element[1][2], element[2][0], element[2][1], element[2][2]); // 계산값 저장용 행렬
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                float result = 0;
                for (int i = 0; i < 3; i++) {
                    result += element[r][i] * m.element[i][c];
                }
                ResultMat.element[r][c] = result;
            }
        }
        return ResultMat;
    }
    Vector operator *(Vector& v) {
        Vector nv;
        nv.x = element[0][0] * v.x + element[0][1] * v.y + element[0][2] * v.z;
        nv.y = element[1][0] * v.x + element[1][1] * v.y + element[1][2] * v.z;
        return nv;
    }
};
