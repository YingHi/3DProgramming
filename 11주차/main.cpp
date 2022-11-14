#include "MuSoenMath.h"

void main() {
    int answer = 0;
    Matrix Mat;
    Vector Vec;
    string now;
    cout << "��� ���� ���α׷��� ���Ű� ȯ���մϴ�." << endl;
    while (true) {
        cout << "����� ���� ��� �Ǵ� ���͸� �����մϴ�." << endl;
        cout << "1. ��� �����" << endl;
        cout << "2. ���� �����" << endl;
        cin >> answer;
        if (answer == 1 || answer == 2) break;
    }
    if (answer == 1) {
        Mat.SetMatrix();
        now = "Matrix";
    }
    if (answer == 2) {
        Vec.SetVector();
        now = "Vector";
    }
    
    while (true) {
        answer = 0;
        if (now == "Matrix") {
            cout << "���� ��� :" << endl;
            Mat.Print();
            cout << "���ϴ� ����� ��ȣ�� �Է��ϼ���." << endl;
            cout << "1. Plus matrix" << endl;
            cout << "2. Multiply matrix" << endl;
            cout << "3. Multiply transpose matrix" << endl;
            cout << "4. identity matrix" << endl;
            cout << "5. transpose matrix" << endl;
            cout << "6. Multiply scalar" << endl;
            cout << "7. Reset matrix" << endl;
            cout << "8. Make Vector" << endl;
            cin >> answer;
            switch (answer)
            {
            case 1:
                Mat.Plus();
                break;
            case 2:
                Mat = multiply_matrix(Mat);
                break;
            case 3:
                Mat = multiply_matrix(Mat);
                Mat.transpose();
                break;
            case 4:
                Mat.identity();
                break;
            case 5:
                Mat.transpose();
                break;
            case 6:
                Mat = multiply_scalar(Mat);
                break;
            case 7:
                Mat.SetMatrix();
                break;
            case 8:
                Vec.SetVector();
                now = "Vector";
                break;
            default:
                break;
            }
        }
        if (now == "Vector") {
            cout << "���� ���� :" << endl;
            Vec.Print();
            cout << "���ϴ� ����� ��ȣ�� �Է��ϼ���." << endl;
            cout << "1. Plus Vector" << endl;
            cout << "2. Multiply Scalar" << endl;
            cout << "3. Plus Scalar" << endl;
            cout << "4. transpose Vector" << endl;
            cout << "5. Reset Vector" << endl;
            cout << "6. Make matrix" << endl;
            cout << "7. Multiply Vector" << endl;
            cin >> answer;
            switch (answer)
            {
            case 1:
                Vec.Plus();
                break;
            case 2:
                m_s(Vec);
                break;
            case 3:
                Vec = p_s(Vec);
                break;
            case 4:
                Mat = Vec.transpose();
                now = "Matrix";
                break;
            case 5:
                Vec.SetVector();
                break;
            case 6:
                Mat.SetMatrix();
                now = "Matrix";
                break;
            case 7:
                m_s(Vec);
            default:
                break;
            }
        }
    }
}
