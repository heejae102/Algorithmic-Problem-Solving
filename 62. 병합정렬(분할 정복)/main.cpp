#include<iostream>
#include<vector>
using namespace std;

/*

<62. 병합정렬(분할 정복)>

N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 병합정렬입니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 
각 자연수는 정수형 범위 안에 있습니다.

▶ 출력설명
오름차순으로 정렬된 수열을 출력합니다.

=============================================================================

▶ 입력예제1
8
7 6 3 1 5 2 4 8

▶ 출력예제1
1 2 3 4 5 6 7 8

*/

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

int main()
{
	// 최초의 풀이 (하나의 테스트 케이스에 대해 오류 발생)

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

	//============================================================================//

	// 강의 풀이 

	int n;
	cin >> n;



	return 0;
}