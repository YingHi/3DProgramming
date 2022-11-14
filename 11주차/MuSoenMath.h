#pragma once
#include <iostream>
#include <cmath>

using namespace std;
class Matrix { // Matrix Ŭ����
public:
    float element[4][4]; // ���� 2���� �迭
    int row, column; // ��,�� ���� �޴� ����

    Matrix() { // �� ��� ������
        Reset();
    }

    Matrix(int r, int c) { // ���� ��� ������
        row = r; // �� ����
        column = c; // �� ����
        Reset();
    }

    void SetMatrix() { // ��Ŀ� �� ����
        Reset();
        cout << "������ ����� �� ���� �Է��ϼ���. (�ִ� 4)" << endl;
        cin >> row;
        cout << "������ ����� �� ���� �Է��ϼ���. (�ִ� 4)" << endl;
        cin >> column; // ���� ����� ��/���� �Է�
        if (row < 1) row = 1;
        if (column < 1) column = 1;
        if (row > 4) row = 4; // �� ���� �ִ�ġ�� ����
        if (column > 4) column = 4; // �� ���� �ִ�ġ�� ����
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < column; c++) {
                cout << r + 1 << " ��" << c + 1 << " ���� ������ ���� �Է��ϼ���." << endl;
                cin >> element[r][c]; // ������� ��Ŀ� �� ����
            }
        }
    }
    
    void Reset() { // ��� �ʱ�ȭ
        for (int i = 0; i < 4; i++) { // ������Ʈ �ʱ�ȭ
            for (int j = 0; j < 4; j++) {
                element[i][j] = 0;
            }
        }
    }

    void Print() { // ��� ���
        cout << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << element[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void identity() { // ������ķ� �ʱ�ȭ�ϴ� �Լ�
        if (row == column) { // ����������� üũ
            Reset();
            for (int i = 0; i < row; i++) {
                element[i][i] = 1; // ������ķ� �����
            }
        }
        else {
            cout << "��������� �ƴϸ� ������ķ� �ʱ�ȭ �� �� �����ϴ�." << endl;
        }
    }

    void Plus() { // ��� ��/����
        cout << "����/������ ���� ���� ��İ� ���� ������ ����� �����մϴ�." << endl;
        cout << "������ �迭�� ��Ŀ� �������Ƿ� ������ �ϰ�ʹٸ� ������ �������ּ���. " << endl;
        Matrix newMatrix(row, column); // ���� ��� ����

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << i + 1 << " ��" << j + 1 << " ���� ������ ���� �Է��ϼ���." << endl;
                cin >> newMatrix.element[i][j]; // ������ �� ��Ŀ� ����
            }
        }
        cout << "���ϴ� ������ ����Դϴ�." << endl;
        newMatrix.Print();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                element[i][j] += newMatrix.element[i][j]; // ���� ����� ���� ��Ŀ� ���ϱ�
            }
        }

    }

    void transpose() { // ��ġ��ķ� ����� �Լ�
        Matrix NewMat(column, row); // ��갪 ����� ���
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

    Matrix operator *(Matrix& m) // ��� x ���
    {
        if (column > m.row) { // ��İ� ��� ���� ���� �ľ�
            cout << "���� ����� ���� ����� ����� ���� ������ �޶� ���� �� �����ϴ�." << endl;
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

    Matrix operator *(float N){ // ��� x ��Į��
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

    Vector() { // �� ���� ������
        column = 1;
    }

    void SetVector() { // ���Ϳ� �� �Է��ϴ� �Լ�
        Reset();
        cout << "������ ������ �� ���� �Է����ּ���. (�ִ� 4)" << endl;
        cin >> row;
        if (row < 1) row = 1; // �� ���� �ּ�ġ�� ����
        if (row > 4) row = 4; // �� ���� �ִ�ġ�� ����
        for (int r = 0; r < row; r++) {
            cout << r + 1 << " �࿡ ������ ���� �Է��ϼ���." << endl;
            cin >> element[r][0];
        }
    }
    void Print() { // ��� ���
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
        cout << "����/������ ���� ���� ���Ϳ� ���� ������ ���͸� �����մϴ�." << endl;
        cout << "������ ���ʹ� ��Ŀ� �������Ƿ� ������ �ϰ�ʹٸ� ������ �������ּ���. " << endl;
        Vector newVector; // ���� ���� ����

        newVector.row = row;
        for (int i = 0; i < row; i++) {
            cout << i + 1 << " �࿡ ������ ���� �Է��ϼ���." << endl;
            cin >> newVector.element[i][0]; // ������ �� ��Ŀ� ����
        }
        cout << "���ϴ� ������ �����Դϴ�." << endl;
        newVector.Print();
        for (int i = 0; i < row; i++) {
            element[i][0] += newVector.element[i][0]; // ���� ����� ���� ��Ŀ� ���ϱ�
        }
    }

    Vector operator +(Vector& v) { // ���ʹ��ϱ� ������
        if (v.row != row) {
            cout << "���� ������ ��� ����� �������� ���� ������ �޶� ���� �� �����ϴ�." << endl;
            return *this;
        }
        for (int i = 0; i < row; i++) {
            element[i][0] = element[i][0] + v.element[i][0];
        }
        return *this;
    }

    Vector operator *(Vector& v) { // ���Ͱ��ϱ� ������
        if (v.row != row) {
            cout << "���� ������ ��� ����� �������� ���� ������ �޶� ���� �� �����ϴ�." << endl;
            return *this;
        }
        for (int i = 0; i < row; i++) {
            element[i][0] = element[i][0] * v.element[i][0];
        }
        return *this;
    }
};

void m_s(Vector v) { // ���� ���ϱ� ����
    Vector newV;
    newV.SetVector();
    newV = v * newV;
    float A = 0;
    for (int i = 0; i < newV.row; i++) {
        A += newV.element[i][0];
    }
    cout << "���� �� ��� : " << A << endl;
    return;
}
Vector p_s(Vector v) { // ���� ���ϱ� ����
    Vector newV;
    newV.SetVector();
    newV = v + newV;
    return newV;
}

Matrix multiply_scalar(Matrix Mat) { // ��� ���ϱ� ���
    float n;
    cout << "��Ŀ� ���� ����� �Է��ϼ���." << endl;
    cin >>n;
    Mat = Mat * n;
    return Mat;
}

Matrix multiply_matrix(Matrix Mat) { // ��� ���ϱ� ���
    float r, c;
    int answer;
    cout << "���� ����� �� ���� �Է��ϼ���. (�ִ� 4)" << endl;
    cin >> r;
    cout << "���� ����� �� ���� �Է��ϼ���. (�ִ� 4)" << endl;
    cin >> c;
    if (r < 1) r = 1;
    if (c < 1) c = 1;
    if (r > 4) r = 4; // �� ���� �ִ�ġ�� ����
    if (c > 4) c = 4; // �� ���� �ִ�ġ�� ����
    if (Mat.column < r) {
        cout << "���� ����� ���� ����� ����� ���� ������ �޶� ���� �� �����ϴ�." << endl;
        return Mat;
    }
    Matrix newMatrix(r, c);

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << j + 1 << " ��" << i + 1 << " ���� ������ ���� �Է��ϼ���." << endl;
            cin >> newMatrix.element[j][i];
        }
    }
    cout << "���� ����Դϴ�." << endl;
    newMatrix.Print();


    Mat = Mat * newMatrix;

    return Mat;
}