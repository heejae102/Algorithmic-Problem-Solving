#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<79. 원더랜드(Prim MST 알고리즘 : priority_queue 활용)>

원더랜드에 문제가 생겼다.
원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.

원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록
도로를 선택하고 나머지 도로는 폐쇄하려고 한다.

아래의 그림은 그 한 예를 설명하는 그림이다.

위의 지도는 각 도시가 1부터 9로 표현되었고,
지도의 오른쪽은 최소비용 196으로 모든 도시를 연결하는 방법을 찾아낸 것이다.

=============================================================================

▶ 입력설명
첫째 줄에 도시의 개수 V(1 ≤ V ≤ 25)와 도로의 개수 E(1 ≤ E ≤ 200)가 주어진다.
다음 E개의 줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.

이는 A번 도시와 B번 도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다.
C는 값이 1,000,000을 넘지 않는다.

▶ 출력설명
모든 도시를 연결하면서 드는 최소비용을 출력한다.

=============================================================================

▶ 입력예제
9 12
1 2 12
1 9 25
2 3 10
2 8 17
2 9 8
3 4 18
3 7 55
4 5 44
5 6 60
5 7 38
7 8 35
8 9 15

▶ 출력예제
196

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