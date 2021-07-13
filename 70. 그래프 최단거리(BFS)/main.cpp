#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1차 복습 풀이시간 : 7분 30초 내 (체크 누락 / 복습 필요)

/*

<70. 그래프 최단거리(BFS)>

다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.

=============================================================================

▶ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 
그 다음부터 M줄에 걸쳐 연결정보가 주어진다.

▶ 출력설명
1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.

=============================================================================

▶ 입력예제
6 9
1 3
1 4
2 1
2 5
3 4
4 5
4 6
6 2
6 5

▶ 출력예제
2 : 3
3 : 1
4 : 1
5 : 2
6 : 2

*/

int main()
{
	// 강의 풀이 

	int ch[21]{ 0 }, dis[21]{ 0 }, n, m, a, b, temp;
	vector<int> map[21];
	queue<int> Q;
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		map[a].push_back(b);
	}

	Q.push(1);
	ch[1] = 1;

	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();

		for (int i = 0; i < map[temp].size(); i++)
		{
			if (ch[map[temp][i]] != 0) continue;

			ch[map[temp][i]] = 1;
			Q.push(map[temp][i]);
			dis[map[temp][i]] = dis[temp] + 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << i << " : " << dis[i] << endl;
	}

	return 0;
}