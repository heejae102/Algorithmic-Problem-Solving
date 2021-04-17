#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*

<44. 마구간 정하기(이분검색 응용 : 결정 알고리즘)>

N개의 마구간이 1차원 수직선상에 있습니다. 
각 마구간은 x1, x2, x3, ......, xN의 좌표를 가지며, 
마구간간에 좌표가 중복되는 일은 없습니다.

현수는 C마리의 말을 가지고 있는데, 
이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.

각 마구간에는 한 마리의 말만 넣을 수 있고, 
가장 가까운 두 말의 거리가 최대가 되게 말을 마구간에 배치하고 싶습니다.

C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 
최대가 되는 그 최대값을 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 줄에 자연수 N(3 <= N <= 200,000)과 C(2 <= C <= N)이 공백을 사이에 두고 주어집니다.
둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0<=xi<=1,000,000,000)가 
한 줄에 하나씩 주어집니다.

▶ 출력설명
첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.

=============================================================================

▶ 입력예제
5 3
1
2
8
4
9

▶ 출력예제
3

*/

int n;
vector<int> input;

int getCount(int distance)
{
	int count = 1, pos = 0;

	for (int i = 1; i < n; i++)
	{
		if (input[i] - input[pos] >= distance)
		{
			count++;
			pos = i;
		}
	}

	return count;
}

int main()
{
	// 최초의 풀이 (강의 풀이와 동일)

	int c, lt = 1, rt = 0, mid, temp, res;

	cin >> n >> c; 

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end(), less<int>());

	rt = input[n - 1];

	while (lt <= rt)
	{
		mid = (lt + rt) * 0.5;

		if (getCount(mid) >= c)
		{
			res = mid;
			lt = mid + 1;
		}
		else rt = mid - 1;
	}

	cout << res << endl; 

	return 0;
}