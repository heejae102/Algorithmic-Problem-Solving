#include<iostream>
#include<vector>
using namespace std; 

// 1차 복습 풀이시간 : 10분 30초 내 (복습 필요 / 시간 초과) 

/*

<52. Ugly Numbers(투포인터 알고리즘 응용)>

어떤 수를 소인수분해 했을 때 그 소인수가 
2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다. 

Ugly Number를 차례대로 적어보면
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 

숫자 1은 Ugly Number의 첫 번째 수로 합니다. 

자연수 N이 주어지면 Ugly Number를 차례로 적을 때 
N번째 Ugly Number를 구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 줄에 자연수 N(3 <= N <= 1500)이 주어집니다.

▶ 출력설명
첫 줄에 N번째 Ugly Number를 출력하세요.

=============================================================================

▶ 입력예제1
10

▶ 출력예제1
12

▶ 입력예제2
1500

▶ 출력예제2
859963392

*/

int main()
{
	// 최초의 풀이 (시간 제한이 없는 문제인데 시간제한 초과로 테스트 케이스 60%만 통과)
	// 큰 값이 주어지면(ex. 1500) 연산 속도가 엄청나게 느리지만 답은 구해진다. 

	/*
	int n, i, count = 1, res = 1, temp;

	cin >> n; 

	// 숫자 1은 Ugly Number의 첫 번째 수로 합니다.

	while (count < n)
	{
		res++;
		temp = res; 
		i = 2;

		while (1)
		{
			if (temp % i == 0)
			{
				temp /= i;
			}
			else i++;

			if (i > 5) break;

			if (temp == 1)
			{
				count++;
				break;
			}
		}
	}

	cout << res << endl; 
	*/

	//============================================================================//

	// 새로운 풀이 (시간 초과 / 최초의 풀이 정리)

	/*
	int n, i, temp, num = 1, count = 1;

	cin >> n;

	while (count < n)
	{
		temp = ++num;
		i = 2;
		count++;

		while (temp != 1)
		{
			if (temp % i == 0) temp /= i;
			else i++;

			if (i > 5)
			{
				count--;
				break;
			}
		}
	}

	cout << num << endl;
	*/

	//============================================================================//

	// 개선된 풀이 (강의 풀이 정리)

	int n, p2, p3, p5, min = numeric_limits<int>::max();

	cin >> n;

	vector<int> num(n + 1, 0);

	num[1] = 1;

	p2 = p3 = p5 = 1;

	for (int i = 2; i <= n; i++)
	{
		min = (num[p2] * 2 < num[p3] * 3) ? num[p2] * 2 : num[p3] * 3;
		min = (num[p5] * 5 < min) ? num[p5] * 5 : min;

		if (num[p2] * 2 == min) p2++;
		if (num[p3] * 3 == min) p3++;
		if (num[p5] * 5 == min) p5++;

		num[i] = min;
	}

	cout << num[n] << endl;

	//============================================================================//

	// 강의 풀이 

	/*
	int n, p2, p3, p5, min = numeric_limits<int>::max();

	cin >> n;

	vector<int> num(n + 1, 0);

	num[1] = 1;

	p2 = p3 = p5 = 1;

	for (int i = 2; i <= n; i++)
	{
		if (num[p2] * 2 < num[p3] * 3) min = num[p2] * 2;
		else min = num[p3] * 3;

		if (num[p5] * 5 < min) min = num[p5] * 5;
		if (num[p2] * 2 == min) p2++;
		if (num[p3] * 3 == min) p3++;
		if (num[p5] * 5 == min) p5++;

		num[i] = min;
	}

	cout << num[n] << endl;
	*/

	return 0;
}