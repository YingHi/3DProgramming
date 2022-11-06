#pragma once
#include <iostream>
#include <cmath>

using namespace std;
class Mat3 { // 계산용 Mat3 클래스
public:
    float Mat[3][3]; // 멤버 변수 2차원 배열

    Mat3() { //  행렬 생성자
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0; // 멤버 변수 초기화
            }
        }
    }
    void Reset() { // 행렬 초기화 함수
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Mat[i][j] = 0;
            }
        }
        Mat[2][2] = 1;
    }

    void MoveSet(float x, float y) { // 이동 변환용 행렬 세팅 (main에서 호출)
        Reset(); // 행렬 초기화
        for (int i = 0; i < 3; i++) {
            Mat[i][i] = 1;
        }
        Mat[2][0] = x; // X좌표에 가산되도록 행렬에 값 추가
        Mat[2][1] = y; // Y좌표에 가산되도록 행렬에 값 추가
    }

    void ScaleSet(float s) { // 크기 변환용 행렬 세팅 (main에서 호출)
        Reset(); // 행렬 초기화
        Mat[0][0] = s; // X좌표에 곱해지도록 행렬에 값 추가
        Mat[1][1] = s; // Y좌표에 곱해지도록 행렬에 값 추가
    }

    void RotateSet(float r) {// 회전변환용 행렬 세팅 (main에서 호출)
        Reset(); // 행렬 초기화
        double Rotate = r * (3.14 / 180); // 라디안 설정
        Mat[0][0] = cos(Rotate);
        Mat[0][1] = (-sin(Rotate));
        Mat[1][0] = sin(Rotate);
        Mat[1][1] = cos(Rotate); // 44 ~ 47행 : 회전행렬 공식에 맞게 행렬에 값 추가
    }
};

class Vec3 { // Vec3 클래스
public:
    float Position[2]; // 멤버 변수 명 (float)

    Vec3(float x, float y) { // 생성자
        Position[0] = x;
        Position[1] = y;
    }

    void Print() { // 현재 좌표 출력 함수
        cout << "X좌표 : " << Position[0] << endl;
        cout << "Y좌표 : " << Position[1] << endl;
    }

    Vec3 operator *(Mat3& p) // 연산자 오버로딩. 행렬곱 연산이 정의되어있음.
    {
        float x = Position[0]; // 3*1행렬의 x설정
        float y = Position[1]; // 3*1행렬의 y설정
        float z = 1; // 3*1행렬의 z설정
        float a = (x * p.Mat[0][0]) + (y * p.Mat[1][0]) + (z * p.Mat[2][0]); // 행렬곱 X좌표 결과값 저장
        float b = (x * p.Mat[0][1]) + (y * p.Mat[1][1]) + (z * p.Mat[2][1]); // 행렬곱 Y좌표 결과값 저장
        // Z좌표는 2차원에선 필요없으므로 생략
        return Vec3(a, b); // 저장된 X,Y좌표 리턴
    }
};
