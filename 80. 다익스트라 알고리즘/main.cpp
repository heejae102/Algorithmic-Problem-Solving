#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<80. ���ͽ�Ʈ�� �˰���>

�Ʒ��� ����ġ ����׷������� 1�� �������� 
��� ���������� �ּ� �Ÿ������ ����ϴ� ���α׷��� �ۼ��ϼ���. 
(��ΰ� ������ Impossible�� ����Ѵ�)

=============================================================================

�� �Է¼���
ù° �ٿ��� ������ �� N(1 <= N <= 20)�� ������ �� M�� �־�����. 
�� �������� M�ٿ� ���� ���������� �Ÿ������ �־�����.

�� ��¼���
1�� �������� �� �������� ���� �ּ� ����� 2�� �������� ���ʴ�� ����ϼ���.

=============================================================================

�� �Է¿���
6 9
1 2 12
1 3 4
2 1 2
2 3 5
2 5 5
3 4 5
4 2 2
4 5 5
6 4 5

�� ��¿���
2 : 11
3 : 4
4 : 9
5 : 14
6 : impossible

*/

struct Data
{
	int money;
	int when;

	Data(int a, int b)
	{
		money = a;
		when = b;
	}

	bool operator<(Data &b)
	{
		// �������� ���� 
		return when > b.when;
	}
};

int main()
{
	// ���� Ǯ�� 

	int n, j, a, b, res = 0, max = numeric_limits<int>::min();

	vector<Data> T;
	priority_queue<int> pQ;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		T.push_back(Data(a, b));

		if (b > max) max = b;
	}

	sort(T.begin(), T.end());

	j = 0;

	for (int i = max; i >= 1; i--)
	{
		for (; j < n; j++)
		{
			if (T[j].when < i) break;
			pQ.push(T[j].money);
		}

		if (!pQ.empty())
		{
			res += pQ.top();
			pQ.pop();
		}
	}

	cout << res << endl;

	return 0;
}