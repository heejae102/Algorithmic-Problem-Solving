#include<iostream>
#include<vector>
using namespace std; 

// 1�� ���� Ǯ�̽ð� : 10�� 30�� �� (���� �ʿ� / �ð� �ʰ�) 

/*

<52. Ugly Numbers(�������� �˰��� ����)>

� ���� ���μ����� ���� �� �� ���μ��� 
2 �Ǵ� 3 �Ǵ� 5�θ� �̷���� ���� Ugly Number��� �θ��ϴ�. 

Ugly Number�� ���ʴ�� �����
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......�Դϴ�. 

���� 1�� Ugly Number�� ù ��° ���� �մϴ�. 

�ڿ��� N�� �־����� Ugly Number�� ���ʷ� ���� �� 
N��° Ugly Number�� ���ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù �ٿ� �ڿ��� N(3 <= N <= 1500)�� �־����ϴ�.

�� ��¼���
ù �ٿ� N��° Ugly Number�� ����ϼ���.

=============================================================================

�� �Է¿���1
10

�� ��¿���1
12

�� �Է¿���2
1500

�� ��¿���2
859963392

*/

int main()
{
	// ������ Ǯ�� (�ð� ������ ���� �����ε� �ð����� �ʰ��� �׽�Ʈ ���̽� 60%�� ���)
	// ū ���� �־�����(ex. 1500) ���� �ӵ��� ��û���� �������� ���� ��������. 

	/*
	int n, i, count = 1, res = 1, temp;

	cin >> n; 

	// ���� 1�� Ugly Number�� ù ��° ���� �մϴ�.

	while (count < n)
	{
		res++;
		temp = res; 
		i = 2;

		while (1)
		{
			if (temp % i == 0)
			{
				temp /= i;
			}
			else i++;

			if (i > 5) break;

			if (temp == 1)
			{
				count++;
				break;
			}
		}
	}

	cout << res << endl; 
	*/

	//============================================================================//

	// ���ο� Ǯ�� (�ð� �ʰ� / ������ Ǯ�� ����)

	/*
	int n, i, temp, num = 1, count = 1;

	cin >> n;

	while (count < n)
	{
		temp = ++num;
		i = 2;
		count++;

		while (temp != 1)
		{
			if (temp % i == 0) temp /= i;
			else i++;

			if (i > 5)
			{
				count--;
				break;
			}
		}
	}

	cout << num << endl;
	*/

	//============================================================================//

	// ������ Ǯ�� (���� Ǯ�� ����)

	int n, p2, p3, p5, min = numeric_limits<int>::max();

	cin >> n;

	vector<int> num(n + 1, 0);

	num[1] = 1;

	p2 = p3 = p5 = 1;

	for (int i = 2; i <= n; i++)
	{
		min = (num[p2] * 2 < num[p3] * 3) ? num[p2] * 2 : num[p3] * 3;
		min = (num[p5] * 5 < min) ? num[p5] * 5 : min;

		if (num[p2] * 2 == min) p2++;
		if (num[p3] * 3 == min) p3++;
		if (num[p5] * 5 == min) p5++;

		num[i] = min;
	}

	cout << num[n] << endl;

	//============================================================================//

	// ���� Ǯ�� 

	/*
	int n, p2, p3, p5, min = numeric_limits<int>::max();

	cin >> n;

	vector<int> num(n + 1, 0);

	num[1] = 1;

	p2 = p3 = p5 = 1;

	for (int i = 2; i <= n; i++)
	{
		if (num[p2] * 2 < num[p3] * 3) min = num[p2] * 2;
		else min = num[p3] * 3;

		if (num[p5] * 5 < min) min = num[p5] * 5;
		if (num[p2] * 2 == min) p2++;
		if (num[p3] * 3 == min) p3++;
		if (num[p5] * 5 == min) p5++;

		num[i] = min;
	}

	cout << num[n] << endl;
	*/

	return 0;
}