#include "MuSoenMath.h"

void main(){
	float x, y;
	int answer;
	cout << "X 좌표를 입력하세요." << endl;
	cin >> x;
	cout << "Y 좌표를 입력하세요." << endl;
	cin >> y;

	Vec3 Vector(x, y);
	Mat3 Matrix = Mat3();
	Vector.Print();

	while (true) {
		answer = 0;
		cout << "원하는 기능의 번호를 입력하세요." << endl;
		cout << "1. 이동" << endl;
		cout << "2. 각도 조정" << endl;
		cout << "3. 크기 조정" << endl;
		cout << "4. 좌표 출력" << endl;
		cout << "5. 종료" << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "X좌표를 이동시키고 싶은만큼 값을 입력하세요." << endl;
			float moveX;
			cin >> moveX;
			cout << "Y좌표를 이동시키고 싶은만큼 값을 입력하세요." << endl;
			float moveY;
			cin >> moveY;
			cout << "X좌표를 " << moveX << "만큼, Y좌표를 " << moveY << "만큼 이동합니다." << endl;
			Matrix.MoveSet(moveX, moveY);
			Vector = Vector* Matrix;
			break;
		case 2:
			cout << "회전시킬 각도를 입력하세요." << endl;
			float Rotation;
			cin >> Rotation;
			Matrix.RotateSet(Rotation);
			Vector = Vector * Matrix;
			break;
		case 3:
			cout << "몇 배로 할 것인지 값을 입력하세요." << endl;
			float Size;
			cin >> Size;
			Matrix.ScaleSet(Size);
			Vector = Vector * Matrix;
			break;
		case 4:
			Vector.Print();
			break;
		case 5:
			cout << "프로그램을 종료합니다." << endl;
			return;
		default:
			break;
		}
	}
}