#include "MuSoenMath.h"

void main(){
	float x, y;
	int answer;
	cout << "X ��ǥ�� �Է��ϼ���." << endl;
	cin >> x;
	cout << "Y ��ǥ�� �Է��ϼ���." << endl;
	cin >> y;

	Vec3 Vector(x, y);
	Mat3 Matrix = Mat3();
	Vector.Print();

	while (true) {
		answer = 0;
		cout << "���ϴ� ����� ��ȣ�� �Է��ϼ���." << endl;
		cout << "1. �̵�" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ũ�� ����" << endl;
		cout << "4. ��ǥ ���" << endl;
		cout << "5. ����" << endl;
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "X��ǥ�� �̵���Ű�� ������ŭ ���� �Է��ϼ���." << endl;
			float moveX;
			cin >> moveX;
			cout << "Y��ǥ�� �̵���Ű�� ������ŭ ���� �Է��ϼ���." << endl;
			float moveY;
			cin >> moveY;
			cout << "X��ǥ�� " << moveX << "��ŭ, Y��ǥ�� " << moveY << "��ŭ �̵��մϴ�." << endl;
			Matrix.MoveSet(moveX, moveY);
			Vector = Vector* Matrix;
			break;
		case 2:
			cout << "ȸ����ų ������ �Է��ϼ���." << endl;
			float Rotation;
			cin >> Rotation;
			Matrix.RotateSet(Rotation);
			Vector = Vector * Matrix;
			break;
		case 3:
			cout << "�� ��� �� ������ ���� �Է��ϼ���." << endl;
			float Size;
			cin >> Size;
			Matrix.ScaleSet(Size);
			Vector = Vector * Matrix;
			break;
		case 4:
			Vector.Print();
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return;
		default:
			break;
		}
	}
}