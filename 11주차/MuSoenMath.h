#pragma once
#include <iostream>
#include <cmath>

using namespace std;
class Matrix { // Matrix 클래스
public:
    float element[4][4]; // 원소 2차원 배열
    int row, column; // 행,렬 개수 받는 변수

    Matrix() { // 빈 행렬 생성자
        Reset();
    }

    Matrix(int r, int c) { // 계산용 행렬 생성자
        row = r; // 행 설정
        column = c; // 열 설정
        Reset();
    }

    void SetMatrix() { // 행렬에 값 세팅
        Reset();
        cout << "생성할 행렬의 행 수를 입력하세요. (최대 4)" << endl;
        cin >> row;
        cout << "생성할 행렬의 열 수를 입력하세요. (최대 4)" << endl;
        cin >> column; // 만들 행렬의 행/열수 입력
        if (row < 1) row = 1;
        if (column < 1) column = 1;
        if (row > 4) row = 4; // 행 길이 최대치에 맞춤
        if (column > 4) column = 4; // 열 길이 최대치에 맞춤
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                cout << r + 1 << " 행" << c + 1 << " 열에 삽입할 수를 입력하세요." << endl;
                cin >> element[r][c]; // 만들어진 행렬에 값 삽입
            }
        }
    }
    
    void Reset() { // 행렬 초기화
        for (int i = 0; i < 4; i++) { // 엘레먼트 초기화
            for (int j = 0; j < 4; j++) {
                element[i][j] = 0;
            }
        }
    }

    void Print() { // 행렬 출력
        cout << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << element[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void identity() { // 단위행렬로 초기화하는 함수
        if (row == column) { // 정방행렬인지 체크
            Reset();
            for (int i = 0; i < row; i++) {
                element[i][i] = 1; // 단위행렬로 만들기
            }
        }
        else {
            cout << "정방행렬이 아니면 단위행렬로 초기화 할 수 없습니다." << endl;
        }
    }

    void Plus() { // 행렬 덧/뺄셈
        cout << "덧셈/뺄셈을 위해 현재 행렬과 같은 길이의 행렬을 생성합니다." << endl;
        cout << "생성된 배열은 행렬에 더해지므로 뺄셈을 하고싶다면 음수를 삽입해주세요. " << endl;
        Matrix newMatrix(row, column); // 계산용 행렬 생성

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << i + 1 << " 행" << j + 1 << " 열에 삽입할 수를 입력하세요." << endl;
                cin >> newMatrix.element[i][j]; // 더해질 값 행렬에 삽입
            }
        }
        cout << "이하는 생성된 행렬입니다." << endl;
        newMatrix.Print();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                element[i][j] += newMatrix.element[i][j]; // 계산용 행렬을 현재 행렬에 더하기
            }
        }

    }

    void transpose() { // 전치행렬로 만드는 함수
        Matrix NewMat(column, row); // 계산값 저장용 행렬
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                NewMat.element[j][i] = element[i][j]; 
            }
        }
        for (int i = 0; i < NewMat.row; i++) {
            for (int j = 0; j < NewMat.column; j++) {
               element[i][j] = NewMat.element[i][j];
            }
        }
        row = NewMat.row;
        column = NewMat.column;
    }

    Matrix operator *(Matrix& m) // 행렬 x 행렬
    {
        if (column > m.row) { // 행렬곱 계산 가능 여부 파악
            cout << "현재 행렬의 열과 계산할 행렬의 행의 개수가 달라 곱할 수 없습니다." << endl;
            return *this;
        }
        Matrix ResultMat = Matrix(row, m.column);
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < m.column; c++) {
                float result = 0;
                for (int i = 0; i < row; i++) {
                    result += element[r][i] * m.element[i][c];
                }
                ResultMat.element[r][c] = result;
            }
        }
        return ResultMat;
    }

    Matrix operator *(float N){ // 행렬 x 스칼라
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                element[r][c] *= N;
            }
        }
        return *this;
    }
};

class Vector : public Matrix {
public:

    Vector() { // 빈 벡터 생성자
        column = 1;
    }

    void SetVector() { // 벡터에 값 입력하는 함수
        Reset();
        cout << "생성할 벡터의 행 수를 입력해주세요. (최대 4)" << endl;
        cin >> row;
        if (row < 1) row = 1; // 행 길이 최소치에 맞춤
        if (row > 4) row = 4; // 행 길이 최대치에 맞춤
        for (int r = 0; r < row; r++) {
            cout << r + 1 << " 행에 삽입할 수를 입력하세요." << endl;
            cin >> element[r][0];
        }
    }
    void Print() { // 행렬 출력
        cout << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << element[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    Matrix transpose() {
        Matrix newMat;
        newMat.row = 1;
        newMat.column = row;
        for (int i = 0; i < row; i++) {
            newMat.element[0][i] = element[i][0];
        }
        return newMat;
    }

    void Plus() {
        cout << "덧셈/뺄셈을 위해 현재 벡터와 같은 길이의 벡터를 생성합니다." << endl;
        cout << "생성된 벡터는 행렬에 더해지므로 뺄셈을 하고싶다면 음수를 삽입해주세요. " << endl;
        Vector newVector; // 계산용 벡터 생성

        newVector.row = row;
        for (int i = 0; i < row; i++) {
            cout << i + 1 << " 행에 삽입할 수를 입력하세요." << endl;
            cin >> newVector.element[i][0]; // 더해질 값 행렬에 삽입
        }
        cout << "이하는 생성된 벡터입니다." << endl;
        newVector.Print();
        for (int i = 0; i < row; i++) {
            element[i][0] += newVector.element[i][0]; // 계산용 행렬을 현재 행렬에 더하기
        }
    }

    Vector operator +(Vector& v) { // 벡터더하기 연산자
        if (v.row != row) {
            cout << "현재 벡터의 행과 계산할 벡터의의 행의 개수가 달라 더할 수 없습니다." << endl;
            return *this;
        }
        for (int i = 0; i < row; i++) {
            element[i][0] = element[i][0] + v.element[i][0];
        }
        return *this;
    }

    Vector operator *(Vector& v) { // 벡터곱하기 연산자
        if (v.row != row) {
            cout << "현재 벡터의 행과 계산할 벡터의의 행의 개수가 달라 곱할 수 없습니다." << endl;
            return *this;
        }
        for (int i = 0; i < row; i++) {
            element[i][0] = element[i][0] * v.element[i][0];
        }
        return *this;
    }
};

void m_s(Vector v) { // 벡터 곱하기 벡터
    Vector newV;
    newV.SetVector();
    newV = v * newV;
    float A = 0;
    for (int i = 0; i < newV.row; i++) {
        A += newV.element[i][0];
    }
    cout << "백터 곱 결과 : " << A << endl;
    return;
}
Vector p_s(Vector v) { // 벡터 더하기 벡터
    Vector newV;
    newV.SetVector();
    newV = v + newV;
    return newV;
}

Matrix multiply_scalar(Matrix Mat) { // 상수 곱하기 행렬
    float n;
    cout << "행렬에 곱할 상수를 입력하세요." << endl;
    cin >>n;
    Mat = Mat * n;
    return Mat;
}

Matrix multiply_matrix(Matrix Mat) { // 행렬 곱하기 행렬
    float r, c;
    int answer;
    cout << "곱할 행렬의 행 수를 입력하세요. (최대 4)" << endl;
    cin >> r;
    cout << "곱할 행렬의 열 수를 입력하세요. (최대 4)" << endl;
    cin >> c;
    if (r < 1) r = 1;
    if (c < 1) c = 1;
    if (r > 4) r = 4; // 행 길이 최대치에 맞춤
    if (c > 4) c = 4; // 열 길이 최대치에 맞춤
    if (Mat.column < r) {
        cout << "현재 행렬의 열과 계산할 행렬의 행의 개수가 달라 곱할 수 없습니다." << endl;
        return Mat;
    }
    Matrix newMatrix(r, c);

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << j + 1 << " 행" << i + 1 << " 열에 삽입할 수를 입력하세요." << endl;
            cin >> newMatrix.element[j][i];
        }
    }
    cout << "곱할 행렬입니다." << endl;
    newMatrix.Print();


    Mat = Mat * newMatrix;

    return Mat;
}