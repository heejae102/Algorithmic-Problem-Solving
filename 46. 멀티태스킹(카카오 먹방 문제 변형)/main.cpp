#include<iostream>
#include<vector>
using namespace std;

// 1차 복습 풀이시간 : 20분 
// 2차 복습 풀이시간 : 14분 내(복습 필요 / 예외처리 오류)

/*

<46. 멀티태스킹(카카오 "먹방" 문제 변형)>

현수의 컴퓨터는 멀티태스킹이 가능하다. 
처리해야 할 작업이 N개 들어오면 현수의 컴퓨터는
작업을 1부터 N까지의 번호를 부여하고 처리를 다음과 같이 한다.

1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다. 
즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.

2) 마지막 번호의 작업을 1초 했으면 
다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다.

3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 
정전이 되어 컴퓨터가 일시적으로 멈추었다. 

전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 
다시 시작해야 하는지 알아내는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에 작업의 개수 N(1 <= N <= 2,000)이 주어지고 

그 다음 N줄에 걸쳐 각 작업을 처리하는데 걸리는 시간이 초단위로 주어진다. 
한 작업을 처리하는데 필요한 시간은 1,000를 넘지 않는다.

마지막 줄에 정전이 발생한 시간 K(1 <= K <= 2,000,000)가 주어진다.

▶ 출력설명
첫 번째 줄에 몇 번 작업부터 다시 시작해야 하는지 작업 번호를 출력한다.
만약 더 이상 처리할 작업이 없다면 -1를 출력한다.

=============================================================================

▶ 입력예제
3
1
2
3
5

▶ 출력예제
3

<입출력 설명>
0~1초 동안에 1번 작업을 처리한다. 남은 시간은 [0, 2, 3] 이다.
1~2초 동안 2번 작업을 처리한다. 남은 시간은 [0, 1, 3] 이다.
2~3초 동안 3번 작업을 처리한다. 남은 시간은 [0, 1, 2] 이다.
3~4초 동안 2번 작업을 처리한다(1번 작업은 다 처리했다). 남은 시간은 [0, 0, 2] 이다.
4~5초 동안 3번 작업을 처리한다. 남은 시간은 [0, 0, 1] 이다.
5초 후 정전이 발행했으므로 3번 작업을 해야 할 때 중단되었으므로, 
전기가 돌아온 후로는 3번 작업부터 시작하면 된다.

*/

int main()
{
	// 최초의 풀이 (예외 처리를 잊어버림 : 더 이상 처리할 작업이 없다면 -1 출력) 

	/*
	int n, k, count = 0, pos = 1, done = 0;

	cin >> n;

	vector<int> task(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> task[i];
	}

	cin >> k;

	while (1)
	{
		if (pos > n) pos = 1;

		if (task[pos] != 0)
		{
			if (count >= k) break;

			task[pos]--;
			count++;

			if (task[pos] <= 0)
			{
				done++;

				if (done >= n)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}

		pos++;
	}

	cout << pos << endl; 
	*/

	// 개선된 풀이 (강의 풀이와 절충하여 개선한 풀이)

	int n, k, pos = 0, count = 0, total = 0;

	cin >> n;

	vector<int> task(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> task[i];
		total += task[i];
	}

	cin >> k;

	// 정전이 끝나는 시점까지 모든 task가 끝났다면 -1 출력 

	if (k >= total)
	{
		cout << -1 << endl; 
		return 0;
	}

	while (1)
	{
		pos++;
		if (pos > n) pos = 1;

		if (task[pos] == 0) continue; 

		if (count >= k) break; 

		task[pos]--;
		count++;
	}

	cout << pos << endl; 

	//============================================================================//

	// 강의 풀이 (최적화가 덜됨.)

	/*
	int n, k, pos = 0, count = 0, total = 0;

	cin >> n;

	vector<int> task(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> task[i];

		total += task[i];
	}

	cin >> k;

	// 정전이 끝날 때까지 시점에 더 이상 처리할 작업이 없다는 것은 
	// 처리해야 할 전체 task의 양이 정전이 시작되는 시점의 시간과 같거나 작다는 의미. 
	// (1초 당 1 task가 처리되기 때문)

	if (total <= k)
	{
		cout << -1 << endl;
		return 0;
	}

	while (1)
	{
		pos++;

		if (pos > n) pos = 1; 

		if (task[pos] == 0) continue; 

		task[pos]--;
		count++;

		// 정전되는 시점 
		if (count >= k) break; 
	}

	// 정전 뒤에 시작될 다음 task 찾기 

	while (1)
	{
		pos++;

		if (pos > n) pos = 1; 
		if (task[pos] != 0) break;
	}

	cout << pos << endl; 
	*/

	return 0;
}