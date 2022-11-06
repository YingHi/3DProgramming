#pragma once
#include <iostream>
#include <cmath>

using namespace std;
class Mat3 { // 계산용 Mat3 클래스
public:
    float Mat[3][3]; // 멤버 변수 2차원 배열 (동차좌표)

    Mat3() { //  Mat 생성자
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // 멤버 변수 초기화
            }
        }
    }
    void Reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1;
    }

    void MoveSet(float x, float y) { //  이동변환용 Mat3 세팅
        Reset();
        for (int i = 0; i < 3; i++) {
            Mat[i][i] = 1;
        }
        Mat[2][0] = x; // Mat3 멤버로 x값 대입
        Mat[2][1] = y; // Mat3 멤버로 y값 대입
    }

    void ScaleSet(float s) {
        Reset();
        Mat[0][0] = s;
        Mat[1][1] = s;
    }

    void RotateSet(float r) {
        Reset();
        double Rotate = r * (3.14 / 180);
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << Mat[i][j] << " "; // 멤버 변수 초기화
            }
            cout << endl;
        }
    }
};

class Vec3 { // Vec3 클래스
public:
    float Position[2]; // 멤버 변수 명 (float)

    Vec3(float x, float y) { // 생성자
        Position[0] = x;
        Position[1] = y;
    }

    void Print() {
        cout << "X좌표 : " << Position[0] << endl;
        cout << "Y좌표 : " << Position[1] << endl;
    }

    Vec3 operator *(Mat3& p)
    {
        float x = Position[0];
        float y = Position[1];
        float z = 1;
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]);
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]);
        return Vec3(a, b);
    }
};