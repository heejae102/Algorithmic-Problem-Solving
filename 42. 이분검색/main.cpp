#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// 1차 복습 풀이시간 : 15분 (복습 필요)
// 2차 복습 풀이시간 : 9분 내 

/*

<42. 이분검색>

임의의 N개의 숫자가 입력으로 주어집니다. 
N개의 수를 오름차순으로 정렬한 다음,

N개의 수 중 한 개의 수인 M이 주어지면 
이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 
구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 줄에 한 줄에 자연수 N(3 <= N <= 1,000,000)과 M이 주어집니다.
두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.

▶ 출력설명
첫 줄에 정렬 후 M의 값의 위치 번호를 출력한다.

=============================================================================

▶ 입력예제
8 32
23 87 65 12 57 32 99 81

▶ 출력예제
3

*/

int main()
{
	// 최초의 풀이 (이분 검색으로 하지 않음...)

	/*
	int n, m; 

	cin >> n >> m;

	vector<int> num(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	// 오름차순 정렬 
	sort(num.begin(), num.end(), less<int>());

	for (int i = 0; i < n; i++)
	{
		if (num[i] == m)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	*/

	//============================================================================//

	// 복습 풀이 

	int n, m, low = 1, high, mid;

	cin >> n >> m;

	vector<int> input(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	// 오름차순 정렬 
	sort(input.begin(), input.end(), less<int>());

	high = n;

	while (low <= high)
	{
		mid = (low + high) * 0.5f;

		if (input[mid] > m)
		{
			high = mid - 1;
		}
		else if (input[mid] < m)
		{
			low = mid + 1;
		}
		else if (input[mid] == m)
		{
			cout << mid << endl; 
			return 0;
		}
	}

	//============================================================================//

	// 강의 풀이 

	/*
	int n, m, lt = 0, rt, mid, temp;

	cin >> n >> m;

	vector<int> num;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		num.push_back(temp);
	}

	sort(num.begin(), num.end(), less<int>());

	rt = n - 1; 

	while (lt <= rt)
	{
		mid = (lt + rt) * 0.5;

		if (num[mid] == m)
		{
			cout << mid + 1 << endl;
			return 0;
		}
		else if (num[mid] > m) rt = mid - 1;
		else lt = mid + 1;
	}
	*/

	return 0;
}