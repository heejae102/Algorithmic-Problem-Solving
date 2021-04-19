#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

// 1차 복습 풀이시간 : 14분

/*

<40. 교집합(투포인터 알고리즘 : MS 인터뷰, 제한시간 1초)>

두 집합 A, B가 주어지면 
두 집합의 교집합을 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에 집합 A의 크기 N(1 <= N <= 30,000)이 주어집니다.
두 번째 줄에 N개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
세 번째 줄에 집합 B의 크기 M(1 <= M <= 30,000)이 주어집니다.
네 번째 줄에 M개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.

▶ 출력설명
두 집합의 교집합을 오름차순 정렬하여 출력합니다.

=============================================================================

▶ 입력예제
5
2 7 10 5 3
5
3 10 5 17 12

▶ 출력예제
3 5 10

*/

int main()
{
	// 최초의 풀이 (놀랍게도 제한시간에 걸리지 않았다... 어째서?)

	/*
	int n, m;
	vector<int> res;

	cin >> n;

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m;

	vector<int> arr2(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	// 교집합 추출

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr1[i] == arr2[j])
			{
				res.push_back(arr1[i]);
				break;
			}
		}
	}

	sort(res.begin(), res.end(), less<int>());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	*/

	//============================================================================//

	// 새로운 풀이 (벡터 푸시백 이용)

	vector<int> res;
	int n, m, p1{ 0 }, p2{ 0 };

	cin >> n; 

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m; 

	vector<int> arr2(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	sort(arr1.begin(), arr1.end(), less<int>());
	sort(arr2.begin(), arr2.end(), less<int>());

	while (p1 < n && p2 < m)
	{
		if (arr1[p1] == arr2[p2])
		{
			res.push_back(arr1[p1]);
			p1++;
			p2++;
		}
		else if (arr1[p1] < arr2[p2]) p1++;
		else if (arr1[p1] > arr2[p2]) p2++;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	//============================================================================//

	// 강의 풀이 

	/*
	int n, m, p1 = 0, p2 = 0, p3 = 0;

	cin >> n;

	vector<int> arr1(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	cin >> m;

	vector<int> arr2(m, 0), res(n + m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> arr2[i];
	}

	// sort : 디폴트는 오름차순 정렬 

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	// 두 수열을 정렬하고 비교하기 
	// 두 포인터를 비교하면서 작은 수가 나오면 해당 포인터는 넘기고(작은 수와 같은 수는 없을 것이므로), 
	// 같은 수가 나오면 두 포인터를 모두 증가시켜서 이동시킨다. 
	// 한쪽 수열의 포인터가 마지막까지 이동하면 모든 교집합 검사가 완료된다. 

	while (p1 < n && p2 < m)
	{
		if (arr1[p1] == arr2[p2])
		{
			res[p3++] = arr1[p1++];
			p2++;
		}
		else if (arr1[p1] < arr2[p2]) p1++;
		else if (arr2[p2] < arr1[p1]) p2++;
	}

	for (int i = 0; i < p3; i++)
	{
		cout << res[i] << " ";
	}
	*/

	return 0;
}