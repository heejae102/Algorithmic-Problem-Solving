#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*

<71. 송아지 찾기(BFS : 상태트리탐색)>

현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 
현수의 위치와 송아지의 위치가 직선상의 좌표 점으로 주어지면 
현수는 현재 위치에서 송아지의 위치까지 다음과 같은 방법으로 이동한다.

현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 
앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다. 

최소 몇 번의 점프로 현수가 송아지의 위치까지 
갈 수 있는지 구하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 
직선의 좌표 점은 1부터 10,000까지이다.

▶ 출력설명
점프의 최소횟수를 구한다.

=============================================================================

▶ 입력예제
5 14

▶ 출력예제
3

*/

int main()
{
	// 강의 풀이 

	int ch[10001]{ 0 }, d[3]{ -1,1,5 };
	int s, e, temp, pos;
	queue<int> Q;

	cin >> s >> e;

	ch[s] = 1;
	Q.push(s);

	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();

		for (int i = 0; i < 3; i++)
		{
			pos = temp + d[i];

			if (pos < 1 || pos > 10000) continue;

			if (pos == e)
			{
				// 처음 ch[s] 값을 초기화할 때 1을 넣었기 때문. (0으로 초기화 시 해당 좌표로 다시 이동할 수 있음.)
				cout << ch[temp] << endl;
				return 0;
			}

			if (ch[pos] != 0) continue;

			ch[pos] = ch[temp] + 1;
			Q.push(pos);
		}
	}

	return 0;
}