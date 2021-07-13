#include<iostream>
#include<vector>
using namespace std;

// 1차 복습 풀이시간 : 6분 내 

/*

<68. 최소비용(DFS : 가중치 방향그래프 인접리스트)>

가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는
최소비용을 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫째 줄에는 정점의 수 N(1 <= N <= 20)와 간선의 수 M가 주어진다.
그 다음부터 M줄에 걸쳐 연결정보가 주어진다.

▶ 출력설명
최소비용을 출력합니다.

=============================================================================

▶ 입력예제
5 8
1 2 12
1 3 6
1 4 10
2 3 2
2 5 2
3 4 3
4 2 2
4 5 5

▶ 출력예제
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
	// 최초의 풀이 

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