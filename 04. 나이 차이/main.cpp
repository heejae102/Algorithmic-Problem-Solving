#include<iostream>
#include<limits>
using namespace std; 

// 1�� ���� Ǯ�̽ð� : 5��
// 2�� ���� Ǯ�̽ð� : 3�� 30�� �̳� 

/*

<04. ���� ����>

N(2 <= N <= 100) ���� ���̰� �Էµ˴ϴ�. 
�� N���� ��� �� ���� �������̰� ���� ���� ���� �� ���ϱ��? 
�ִ� ���� ���̸� ����ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
�Է������� input.txt�� �Ѵ�.
ù �ٿ� �ڿ��� N(2 <= N <= 100)�� �Էµǰ�, 
�� ���� �ٿ� N���� ���̰� �Էµȴ�. 

�� ��¼���
��������� output.txt�� �Ѵ�. 
ù �ٿ� �ִ� �������̸� ����մϴ�. 

=============================================================================

�� �Է¿���
10
13	15	34	23	45	65	33	11	26	42

�� ��¿���
54

*/

/*

<�ڷ����� �ִ밪/�ּҰ� �޾ƿ���>

������� : #include<limits>

numeric_limits<int>::max 
�ش� �ڷ����� �ִ밪 

numeric_limits<int>::min
�ش� �ڷ����� �ּҰ�

*/

int main()
{
	// ������ Ǯ�� 

	/*
	int num, min, max = 0;
	int age[100] = { 0 };

	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> age[i];

	min = age[0];

	for (int i = 0; i < num; i++)
	{
		if (age[i] < min) min = age[i];
		if (age[i] > max) max = age[i];
	}

	cout << max - min << endl;
	*/

	// ���� Ǯ�� 

	int num, input, max = 0, min = numeric_limits<int>::max();

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;

		if (input < min) min = input;
		if (input > max) max = input;
	}

	cout << max - min;

	return 0;
}