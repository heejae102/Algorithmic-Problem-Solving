#include<iostream>
using namespace std;

// 1차 복습 풀이시간 : 10분 내 (복습 필요)

/*

<62. 병합정렬(분할 정복)>

N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 병합정렬입니다.

=============================================================================

▶ 입력설명
첫 번째 줄에 자연수 N(1 <= N <= 100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 
각 자연수는 정수형 범위 안에 있습니다.

▶ 출력설명
오름차순으로 정렬된 수열을 출력합니다.

=============================================================================

▶ 입력예제
8
7 6 3 1 5 2 4 8

▶ 출력예제
1 2 3 4 5 6 7 8

*/

int arr[101]{ 0 }, temp[101]{ 0 };

/*
void divide(int lt, int rt)
{
	int mid;
	int p1, p2, p3;

	if (lt >= rt) return; 

	mid = (lt + rt) * 0.5f;

	divide(lt, mid);
	divide(mid + 1, rt);

	// 이미 정렬되어 있는 구간별로 나누어서 합치기 
	p1 = lt;
	p2 = mid + 1;
	p3 = lt;

	while (p1 <= mid && p2 <= rt)
	{
		(arr[p1] < arr[p2]) ? temp[p3++] = arr[p1++] : temp[p3++] = arr[p2++];
	}

	while (p1 <= mid) temp[p3++] = arr[p1++];
	while (p2 <= rt) temp[p3++] = arr[p2++];

	for (int i = lt; i <= rt; i++)
	{
		arr[i] = temp[i];
	}
}
*/
 
// 강의 풀이 정리 
void divide(int lt, int rt)
{
	if (lt >= rt) return; 

	int mid, p1, p2, p3;

	mid = (lt + rt) * 0.5f;

	divide(lt, mid);
	divide(mid + 1, rt);

	p1 = p3 = lt;
	p2 = mid + 1;

	while (p1 <= mid && p2 <= rt)
	{
		(arr[p1] < arr[p2]) ? temp[p3++] = arr[p1++] : temp[p3++] = arr[p2++];
	}

	while (p1 <= mid) temp[p3++] = arr[p1++];
	while (p2 <= rt) temp[p3++] = arr[p2++];

	for (int i = lt; i <= rt; i++)
	{
		arr[i] = temp[i];
	}
}

int main()
{
	// 강의 풀이 

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	divide(1, n);

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}