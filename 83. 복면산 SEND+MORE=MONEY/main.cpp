#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<83. 복면산 SEND+MORE=MONEY (MS인터뷰)>

SEND+MORE=MONEY 라는 유명한 복면산이 있습니다. 
이 복면산을 구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 15)과 R(0 <= R <= 15)이 주어진다. 단 (N >= R)
두 번째 줄에 N개의 서로 다른 자연수가 오름차순으로 주어진다.

▶ 출력설명
순열의 각 경우를 아래와 같이 오름차순으로 출력한다. 마지막 줄에 총 개수도 출력한다.

=============================================================================

▶ 입력예제
4 3
1 3 6 7

▶ 출력예제
  9 5 6 7
+ 1 0 8 5
------------------
1 0 6 5 2

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