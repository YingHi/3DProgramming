#include "MuSoenMath.h"

void main() {
    float x, y; // 좌표값 입력받을 변수
    int answer; // 메뉴이동 정수값 입력받을 변수
    cout << "X 좌표를 입력하세요." << endl;
    cin >> x;
    cout << "Y 좌표를 입력하세요." << endl;
    cin >> y;

    Vec3 Vector(x, y); // 입력받은 좌표로 기본 벡터 생성
    Mat3 Matrix = Mat3(); // 계산용 행렬 객체 생성
    Vector.Print(); 

    while (true) {
        answer = 0;
        cout << "원하는 기능의 번호를 입력하세요." << endl;
        cout << "1. 이동" << endl;
        cout << "2. 각도 조정" << endl;
        cout << "3. 크기 조정" << endl;
        cout << "4. 좌표 출력" << endl;
        cout << "5. 종료" << endl;
        cin >> answer; // 메뉴이동 정수값 입력
        switch (answer)
        {
        case 1: // 이동
            cout << "X좌표를 이동시키고 싶은만큼 값을 입력하세요." << endl;
            float moveX;
            cin >> moveX; // X좌표 이동값 입력
            cout << "Y좌표를 이동시키고 싶은만큼 값을 입력하세요." << endl;
            float moveY; 
            cin >> moveY; // Y좌표 이동값 입력
            cout << "X좌표를 " << moveX << "만큼, Y좌표를 " << moveY << "만큼 이동합니다." << endl;
            Matrix.MoveSet(moveX, moveY); // 입력받은 좌표로 이동행렬 생성
            Vector = Vector * Matrix; // 연산자 오버로딩을 사용해 벡터와 행렬 연산
            break;
        case 2: // 회전
            cout << "회전시킬 각도를 입력하세요." << endl;
            float Rotation;
            cin >> Rotation; // 회전각도 입력
            Matrix.RotateSet(Rotation); // 입력받은 좌표로 회전행렬 생성
            Vector = Vector * Matrix; // 연산자 오버로딩을 사용해 벡터와 행렬 연산
            break;
        case 3: // 크기
            cout << "몇 배로 할 것인지 값을 입력하세요." << endl;
            float Size;
            cin >> Size; // 크기 배수 입력
            Matrix.ScaleSet(Size); // 입력받은 좌표로 크기행렬 생성
            Vector = Vector * Matrix; // 연산자 오버로딩을 사용해 벡터와 행렬 연산
            break;
        case 4: // 출력
            Vector.Print(); // 좌표 출력
            break;
        case 5: // 종료
            cout << "프로그램을 종료합니다." << endl;
            return; // 프로그램 종료
        default:
            break;
        }
    }
}
