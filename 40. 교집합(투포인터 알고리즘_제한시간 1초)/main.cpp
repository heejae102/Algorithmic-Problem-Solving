#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// 1�� ���� Ǯ�̽ð� : 14��

/*

<40. ������(�������� �˰��� : MS ���ͺ�, ���ѽð� 1��)>

�� ���� A, B�� �־����� 
�� ������ �������� ����ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù ��° �ٿ� ���� A�� ũ�� N(1 <= N <= 30,000)�� �־����ϴ�.
�� ��° �ٿ� N���� ���Ұ� �־����ϴ�. ���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
�� ��° �ٿ� ���� B�� ũ�� M(1 <= M <= 30,000)�� �־����ϴ�.
�� ��° �ٿ� M���� ���Ұ� �־����ϴ�. ���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
�� ������ ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

�� ��¼���
�� ������ �������� �������� �����Ͽ� ����մϴ�.

=============================================================================

�� �Է¿���
5
2 7 10 5 3
5
3 10 5 17 12

�� ��¿���
3 5 10

*/

int main()
{
	// ������ Ǯ�� (����Ե� ���ѽð��� �ɸ��� �ʾҴ�... ��°��?)

	/*
	int n, m;
	vector<int> res;

	cin >> n;

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m;

	vector<int> arr2(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	// ������ ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr1[i] == arr2[j])
			{
				res.push_back(arr1[i]);
				break;
			}
		}
	}

	sort(res.begin(), res.end(), less<int>());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	*/

	//============================================================================//

	// ���ο� Ǯ�� (���� Ǫ�ù� �̿�)

	vector<int> res;
	int n, m, p1{ 0 }, p2{ 0 };

	cin >> n; 

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m; 

	vector<int> arr2(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	sort(arr1.begin(), arr1.end(), less<int>());
	sort(arr2.begin(), arr2.end(), less<int>());

	while (p1 < n && p2 < m)
	{
		if (arr1[p1] == arr2[p2])
		{
			res.push_back(arr1[p1]);
			p1++;
			p2++;
		}
		else if (arr1[p1] < arr2[p2]) p1++;
		else if (arr1[p1] > arr2[p2]) p2++;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	//============================================================================//

	// ���� Ǯ�� 

	/*
	int n, m, p1 = 0, p2 = 0, p3 = 0;

	cin >> n;

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m;

	vector<int> arr2(m, 0), res(n + m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	// sort : ����Ʈ�� �������� ���� 

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	// �� ������ �����ϰ� ���ϱ� 
	// �� �����͸� ���ϸ鼭 ���� ���� ������ �ش� �����ʹ� �ѱ��(���� ���� ���� ���� ���� ���̹Ƿ�), 
	// ���� ���� ������ �� �����͸� ��� �������Ѽ� �̵���Ų��. 
	// ���� ������ �����Ͱ� ���������� �̵��ϸ� ��� ������ �˻簡 �Ϸ�ȴ�. 

	while (p1 < n && p2 < m)
	{
		if (arr1[p1] == arr2[p2])
		{
			res[p3++] = arr1[p1++];
			p2++;
		}
		else if (arr1[p1] < arr2[p2]) p1++;
		else if (arr2[p2] < arr1[p1]) p2++;
	}

	for (int i = 0; i < p3; i++)
	{
		cout << res[i] << " ";
	}
	*/

	return 0;
}