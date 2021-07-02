#include<iostream>
#include<vector>
using namespace std;

/*

<60. 합이 같은 부분집합(DFS : 아마존 인터뷰)>

N개의 원소로 구성된 자연수 집합이 주어지면, 
이 집합을 두 개의 부분집합으로 나누었을 때
두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 "YES"를 출력하고, 
그렇지 않으면 "NO"를 출력하는 프로그램을 작성하세요.

예를 들어 {1, 3, 5, 6, 7, 10}이 입력되면 
{1, 3, 5, 7} = {6, 10} 으로 두 부분집합의 합이 
16으로 같은 경우가 존재하는 것을 알 수 있다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 10)이 주어집니다.
두 번째 줄에 집합의 원소 N개가 주어진다. 
각 원소는 중복되지 않으며 그 크기는 1,000,000 이하입니다.

▶ 출력설명
첫 번째 줄에 "YES" 또는 "NO"를 출력한다.

=============================================================================

▶ 입력예제1
6
1 3 5 6 7 10

▶ 출력예제1
YES

*/

/*
int n, ch[11]{ 0 }, arr[11]{ 0 };
vector<int> sum;

void DFS(int x)
{
	if (x == n)
	{
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			if (ch[i] == 1) count += arr[i];
		}

		sum.push_back(count);
	}
	else
	{
		ch[x] = 1;
		DFS(x + 1);
		ch[x] = 0;
		DFS(x + 1);
	}
}
*/

int n, flag = 0, total = 0, arr[11]{ 0 };

void DFS(int L, int sum)
{
	// 두 부분집합의 원소 값이 같다면 하나의 부분집합 당 원소 합이 "전체원소값/2"일 것.
	// 즉, 부분집합의 합이 "전체원소값/2"보다 크다면 더이상 검사할 필요가 없음.
	if (sum > (total * 0.5f)) return;
	if (flag & 1) return;

	if (L == n)
	{
		if (sum == (total - sum)) flag = 1;
	}
	else
	{
		// 1 3 5 6 7 10
		// 부분집합에 원소값 포함/미포함 
		DFS(L + 1, sum + arr[L]);
		DFS(L + 1, sum);
	}
}


int main()
{
	// 최초의 풀이 (부분집합이 3개 이상인 경우의 수도 존재하므로 테스트 오류 발생)

	/*
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	DFS(0);

	for (int i = 0; i < sum.size(); i++)
	{
		for (int j = 0; j < sum.size(); j++)
		{
			if (i != j && sum[i] == sum[j])
			{
				cout << "YES" << endl;
				cout << sum[i] << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	*/

	//============================================================================//

	// 강의 풀이 

	// 하나의 부분집합 값이 구해졌을 때 나머지 전체 원소(부분집합)와 비교하면
	// 두 부분집합의 원소의 합을 비교할 수 있다. 

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		total += arr[i];
	}

	DFS(0, 0);

	(flag & 1) ? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}