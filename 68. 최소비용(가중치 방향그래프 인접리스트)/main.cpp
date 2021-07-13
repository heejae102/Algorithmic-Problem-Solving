#include<iostream>
#include<vector>
using namespace std;

// 1�� ���� Ǯ�̽ð� : 6�� �� 

/*

<68. �ּҺ��(DFS : ����ġ ����׷��� ��������Ʈ)>

����ġ ����׷����� �־����� 1�� �������� N�� �������� ����
�ּҺ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

=============================================================================

�� �Է¼���
ù° �ٿ��� ������ �� N(1 <= N <= 20)�� ������ �� M�� �־�����.
�� �������� M�ٿ� ���� ���������� �־�����.

�� ��¼���
�ּҺ���� ����մϴ�.

=============================================================================

�� �Է¿���
5 8
1 2 12
1 3 6
1 4 10
2 3 2
2 5 2
3 4 3
4 2 2
4 5 5

�� ��¿���
13

*/

int ch[21]{ 0 }, n, min = numeric_limits<int>::max();
vector<pair<int, int>> graph[21];

void DFS(int v, int sum)
{
	if (v == n)
	{
		if (sum < min) min = sum;
	}
	else
	{
		for (int i = 0; i < graph[v].size(); i++)
		{
			if (ch[graph[v][i].first] != 0) continue;

			ch[graph[v][i].first] = 1;
			DFS(graph[v][i].first, sum + graph[v][i].second);
			ch[graph[v][i].first] = 0;
		}
	}
}

int main()
{
	// ������ Ǯ�� 

	int m, a, b, c;
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		//graph[a].push_back(make_pair(b, c));
	}

	ch[1] = 1;
	DFS(1, 0);

	cout << min << endl; 

	return 0;
}