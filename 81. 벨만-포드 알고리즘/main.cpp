#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<81. 벨만-포드 알고리즘>

N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 
해당 도로를 통행하는 비용이 주어질 때, 
한 도시에서 다른 도시로 이동하는데 쓰이는 
비용의 최소값을 구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에는 도시의 수N(N<=100)과 도로수 M(M<=200)가 주어지고, 
M줄에 걸쳐 도로정보와 비용이 주어진다. 

만약 1번 도시와 2번도시가 연결되고 그 비용이 13이면 “1 2 13”으로 주어진다. 
그 다음 마지막 줄에 출발도시와 도착도시가 주어진다.

▶ 출력설명
출발도시에서 도착도시까지 가는데 걸리는 최소비용을 출력한다. 
음의 사이클이 존재할 경우 -1를 출력한다.

※ 벨만포드 알고리즘은 그래프가 음의 사이클이 존재하면 안된다.

=============================================================================

▶ 입력예제
5 7
1 2 5
1 3 4
2 3 -3
2 5 13
3 4 5
4 2 3
4 5 7
1 5

▶ 출력예제
14

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