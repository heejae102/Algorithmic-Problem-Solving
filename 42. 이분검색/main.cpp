#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// 1�� ���� Ǯ�̽ð� : 15�� (���� �ʿ�)
// 2�� ���� Ǯ�̽ð� : 9�� �� 

/*

<42. �̺а˻�>

������ N���� ���ڰ� �Է����� �־����ϴ�. 
N���� ���� ������������ ������ ����,

N���� �� �� �� ���� ���� M�� �־����� 
�̺а˻����� M�� ���ĵ� ���¿��� �� ��°�� �ִ��� 
���ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù �ٿ� �� �ٿ� �ڿ��� N(3 <= N <= 1,000,000)�� M�� �־����ϴ�.
�� ��° �ٿ� N���� ���� ������ ���̿� �ΰ� �־����ϴ�.

�� ��¼���
ù �ٿ� ���� �� M�� ���� ��ġ ��ȣ�� ����Ѵ�.

=============================================================================

�� �Է¿���
8 32
23 87 65 12 57 32 99 81

�� ��¿���
3

*/

int main()
{
	// ������ Ǯ�� (�̺� �˻����� ���� ����...)

	/*
	int n, m; 

	cin >> n >> m;

	vector<int> num(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	// �������� ���� 
	sort(num.begin(), num.end(), less<int>());

	for (int i = 0; i < n; i++)
	{
		if (num[i] == m)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	*/

	//============================================================================//

	// ���� Ǯ�� 

	int n, m, low = 1, high, mid;

	cin >> n >> m;

	vector<int> input(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	// �������� ���� 
	sort(input.begin(), input.end(), less<int>());

	high = n;

	while (low <= high)
	{
		mid = (low + high) * 0.5f;

		if (input[mid] > m)
		{
			high = mid - 1;
		}
		else if (input[mid] < m)
		{
			low = mid + 1;
		}
		else if (input[mid] == m)
		{
			cout << mid << endl; 
			return 0;
		}
	}

	//============================================================================//

	// ���� Ǯ�� 

	/*
	int n, m, lt = 0, rt, mid, temp;

	cin >> n >> m;

	vector<int> num;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		num.push_back(temp);
	}

	sort(num.begin(), num.end(), less<int>());

	rt = n - 1; 

	while (lt <= rt)
	{
		mid = (lt + rt) * 0.5;

		if (num[mid] == m)
		{
			cout << mid + 1 << endl;
			return 0;
		}
		else if (num[mid] > m) rt = mid - 1;
		else lt = mid + 1;
	}
	*/

	return 0;
}