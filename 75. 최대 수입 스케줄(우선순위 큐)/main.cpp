#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1차 복습 풀이시간 : 15분 내 (오답 / 복습 필요)

/*

<75. 최대 수입 스케줄(priority_queue 응용문제)>

현수는 유명한 강연자이다. N개의 기업에서 강연 요청을 해왔다. 
각 기업은 D일 안에 와서 강연을 해 주면 M만큼의 강연료를 주기로 했다.

각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 10,000)이 주어지고, 
다음 N개의 줄에 M(1 <= M <= 10,000)과 D(1 <= D <= 10,000)가 차례로 주어진다.

▶ 출력설명
첫 번째 줄에 최대로 벌 수 있는 수입을 출력한다.

=============================================================================

▶ 입력예제
6
50 2
20 1
40 2
60 3
30 3
30 1

▶ 출력예제
150

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
		for ( ; j < n; j++)
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