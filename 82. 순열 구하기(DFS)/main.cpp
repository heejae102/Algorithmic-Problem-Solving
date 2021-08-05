#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<82. ���� ���ϱ�(DFS : Depth First Search)>

�ڿ��� N�� R�� �־����� ���� �ٸ� N���� �ڿ��� �� R���� �̾� 
�Ϸķ� �����ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù ��° �ٿ� �ڿ��� N(1 <= N <= 15)�� R(0 <= R <= 15)�� �־�����. �� (N >= R) 
�� ��° �ٿ� N���� ���� �ٸ� �ڿ����� ������������ �־�����.

�� ��¼���
������ �� ��츦 �Ʒ��� ���� ������������ ����Ѵ�. ������ �ٿ� �� ������ ����Ѵ�.

=============================================================================

�� �Է¿���
4 3
1 3 6 7

�� ��¿���
1 3 6
1 3 7
1 6 3
1 6 7
1 7 3
1 7 6
3 1 6
3 1 7
3 6 1
3 6 7
3 7 1
3 7 6
6 1 3
6 1 7
6 3 1
6 3 7
6 7 1
6 7 3
7 1 3
7 1 6
7 3 1
7 3 6
7 6 1
7 6 3
24

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