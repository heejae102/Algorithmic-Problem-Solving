#include<iostream>
#include<vector>
using namespace std;

/*

<66. 경로탐색(DFS : 인접리스트 방법)>

인접리스트 방식은 인접행렬보다 메모리를 적게 사용할 수 있으므로 효율적 

방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 
모든 경로의 가지 수를 출력하는 프로그램을 작성하세요. 
아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는

1 2 3 4 5
1 2 5
1 3 4 2 5
1 3 4 5
1 4 2 5
1 4 5

총 6 가지입니다.

=============================================================================

▶ 입력설명
첫째 줄에는 정점의 수 N(1 <= N <= 20)와 간선의 수 M가 주어진다. 
그 다음부터 M줄에 걸쳐 연결정보가 주어진다.

▶ 출력설명
첫 번째 줄에 경로의 가지수를 출력한다.

=============================================================================

▶ 입력예제
5 9
1 2
1 3
1 4
2 1
2 3
2 5
3 4
4 2
4 5

▶ 출력예제
6

*/

int ch[21]{ 0 }, res = 0, n;
vector<int> map[21];

void DFS(int v)
{
	if (v == n)
	{
		res++;
	}
	else
	{
		for (int i = 0; i < map[v].size(); i++)
		{
			if (ch[map[v][i]] != 0) continue;
		
			ch[map[v][i]] = 1;
			DFS(map[v][i]);
			ch[map[v][i]] = 0;
		}
	}
}

int main()
{
	// 강의 풀이 

	int m, a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a].push_back(b);
	}

	ch[1] = 1;
	DFS(1);

	cout << res << endl; 

	return 0;
}