#include<iostream>
#include<vector>
using namespace std;

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

	int Q[100]{ 0 }, ch[10]{ 0 };
	vector<int> map[10];
	int edge = 6, front = -1, back = -1, a, b, x;

	for (int i = 0; i < edge; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	Q[++back] = 1;
	ch[1] = 1;

	while (front < back)
	{
		x = Q[++front];
		cout << x << " ";

		for (int i = 0; i < map[x].size(); i++)
		{
			if (ch[map[x][i]] != 0) continue;

			ch[map[x][i]] = 1;
			Q[++back] = map[x][i];
		}
	}

	return 0;
}