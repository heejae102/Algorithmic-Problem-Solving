#include<iostream>
#include<vector>
using namespace std;

// 1차 복습 풀이시간 : 12분 내 (복습 필요)

/*

<69. 이진트리 너비우선탐색(BFS)>

레벨 단위로 탐색하므로 레벨탐색으로도 불린다. 

아래 그림과 같은 이진트리를 너비우선탐색해 보세요. 
간선 정보 6개를 입력받아 처리해보세요.


				1
		2				3
	4		5		6		7


너비우선 탐색 : 1 2 3 4 5 6 7

=============================================================================

▶ 입력예제
1 2
1 3
2 4
2 5
3 6
3 7

▶ 출력예제
1 2 3 4 5 6 7

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