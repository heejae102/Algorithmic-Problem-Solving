#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1�� ���� Ǯ�̽ð� : 15�� �� (���� / ���� �ʿ�)

/*

<76. ���װ��(�޸������̼�)>

���װ���� N���� ���Ҹ� ������ ���տ��� 
R���� ���Ҹ� �̾� �κ������� ����� ����� ���� �ǹ��Ѵ�. 
������ nCr �� ǥ���ȴ�.
N�� R�� �־����� ���װ���� ���ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù ��° �ٿ� �ڿ��� N(1 <= N <= 20)�� R(0 <= R <= 20)�� �־�����. �� (N >= R)

�� ��¼���
ù ��° �ٿ� ���װ�� ���� ����Ѵ�.

=============================================================================

�� �Է¿���
5 3

�� ��¿���
10

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