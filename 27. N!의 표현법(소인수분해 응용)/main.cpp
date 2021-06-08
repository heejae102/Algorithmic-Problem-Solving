#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std; 

// 1차 복습 풀이시간 : 15분 (복습 필요 / 암기하기)
// 2차 복습 풀이시간 : 13분 이내 

/*

<27. N!의 표현법(소인수분해 응용)>

임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 
이는 N이 커짐에 따라 급격하게 커진다. 

이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다. 
먼저 소수는 2, 3, 5, 7, 11, 13... 순으로 증가함을 알아야 한다. 

예를 들면 825는 (0 1 2 0 1)로 표현이 가능한데, 
이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 

101보다 작은 임의의 N에 대하여 N 팩토리얼을 
이와 같은 표기법으로 변환하는 프로그램을 작성해보자. 
출력은 아래 예제와 같이 하도록 한다.

=============================================================================

▶ 입력설명
첫 줄에 자연수 N(3 <= N <= 1000)이 입력된다.

▶ 출력설명
소수의 곱으로 표현한다.

=============================================================================

▶ 입력예제
5

▶ 출력예제
5! = 3 1 1

*/

int main()
{
	// 강의 풀이 

	// 예를 들면 825는 (0 1 2 0 1)로 표현이 가능한데, 
	// 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다.

	// 101보다 작은 임의의 N에 대하여 N 팩토리얼을
	// 이와 같은 표기법으로 변환하는 프로그램을 작성해보자.

	int n, j, temp; 

	cin >> n;

	// 인수의 개수를 담을 벡터. 
	// n이라는 수의 인수는 n과 같거나 n보다 작을 것이므로 index가 n까지인 (n + 1)개로 선언
	vector<int> factor(n + 1, 0);

	// 1은 소인수가 아니므로 제외 
	for (int i = 2; i <= n; i++)
	{
		temp = i;
		j = 2;

		while (1)
		{
			// 만약 j로 temp가 나누어 떨어진다면(인수라면) 인수 벡터의 j값을 1 증가
			// 나누어 떨어지지 않는다면 j 값을 1 증가시켜 다시 나누기 

			// 2부터 시작해서 나누는 것이므로, 이미 가장 작은 배수 단위의 소인수로 다 나누고 
			// j 값이 증가하기 때문에 소인수가 아닌 4, 6, 10 등은 카운트 되지 않는다.
			// 즉, 자동으로 소인수의 개수만 카운트하게 된다. 
			// (4로 나누어 떨어질 값이었다면 이미 2로 나누어 떨어졌음.)
			if (temp % j == 0)
			{
				temp /= j;
				factor[j]++;
			}
			else j++;

			// temp의 값이 완전히 분해되어 1로 나누어 떨어졌다면 break
			if (temp == 1) break;
		}
	}

	printf("%d! = ", n);

	for (int i = 2; i <= n; i++)
	{
		if(factor[i] != 0) printf("%d ", factor[i]);
	}

	return 0;
}