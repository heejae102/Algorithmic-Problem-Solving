#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<80. 다익스트라 알고리즘>

아래의 가중치 방향그래프에서 1번 정점에서 
모든 정점으로의 최소 거리비용을 출력하는 프로그램을 작성하세요. 
(경로가 없으면 Impossible를 출력한다)

=============================================================================

▶ 입력설명
첫째 줄에는 정점의 수 N(1 <= N <= 20)와 간선의 수 M가 주어진다. 
그 다음부터 M줄에 걸쳐 연결정보와 거리비용이 주어진다.

▶ 출력설명
1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.

=============================================================================

▶ 입력예제
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

▶ 출력예제
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
		// 내림차순 정렬 
		return when > b.when;
	}
};

int main()
{
	// 강의 풀이 

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