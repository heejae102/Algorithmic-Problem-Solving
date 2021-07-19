#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1차 복습 풀이시간 : 15분 내 (오답 / 복습 필요)

/*

<76. 이항계수(메모이제이션)>

이항계수는 N개의 원소를 가지는 집합에서 
R개의 원소를 뽑아 부분집합을 만드는 경우의 수를 의미한다. 
공식은 nCr 로 표현된다.
N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 20)과 R(0 <= R <= 20)이 주어진다. 단 (N >= R)

▶ 출력설명
첫 번째 줄에 이항계수 값을 출력한다.

=============================================================================

▶ 입력예제
5 3

▶ 출력예제
10

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