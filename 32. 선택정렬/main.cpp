#include<stdio.h>
#include<iostream>
using namespace std; 

/*

<32. ��������>

N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�����ϴ� ����� ���������Դϴ�.

=============================================================================

�� �Է¼���
ù ��° �ٿ� �ڿ��� N(1 <= N <= 100)�� �־����ϴ�.
�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. 
�� �ڿ����� ������ ���� �ȿ� �ֽ��ϴ�.

�� ��¼���
������������ ���ĵ� ������ ����մϴ�.

=============================================================================

�� �Է¿���
6
13 5 11 7 23 15

�� ��¿���
5 7 11 13 15 23

*/

int main()
{
	// ������ Ǯ�� 

	/*
	int n, index, temp, min = numeric_limits<int>::max();
	int num[100]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		min = num[i];
		index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < min)
			{
				min = num[j];
				index = j;
			}
		}

		temp = num[i];
		num[i] = num[index];
		num[index] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
	*/

	//============================================================================//

	// ���� Ǯ�� (���� �� ����ȭ�� Ǯ��)

	int n, temp, index;
	int num[100]{ 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (num[j] < num[index]) index = j;
		}

		temp = num[i];
		num[i] = num[index];
		num[index] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}

	return 0;
}