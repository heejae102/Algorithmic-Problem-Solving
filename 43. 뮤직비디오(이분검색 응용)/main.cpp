#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std; 

// 1차 복습 풀이시간 : 1시간 넘게 씨름했음. (복습 필요 / 이분검색 활용하기 복습)
// 2차 복습 풀이시간 : 24분 30초 내 

/*

<43. 뮤직비디오(이분검색 응용 : 결정 알고리즘)>

지니레코드에서는 불세출의 가수 조영필의 
라이브 동영상을 DVD로 만들어 판매하려 한다.

DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 
라이브에서의 순서가 그대로 유지되어야 한다. 
순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다. 
즉, 1번 노래와 5번 노래를 같은 DVD에 녹화하기 위해서는 
1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야 한다.

지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에
이 사업에 낭비되는 DVD를 가급적 줄이려고 한다. 
고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기로 하였다. 

이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 
그리고 M개의 DVD는 모두 같은 크기여야 
제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.

=============================================================================

▶ 입력설명
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ N)이 주어진다. 

다음 줄에는 조영필이 라이브에서 부른 순서대로 
부른 곡의 길이가 분 단위로(자연수) 주어진다.

부른 곡의 길이는 10,000분을 넘지 않는다고 가정하자.

▶ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.

=============================================================================

▶ 입력예제
9 3
1 2 3 4 5 6 7 8 9

▶ 출력예제
17

*/

int song[1000]{ 0 }, n;

int getCount(int s)
{
	int count = 1, sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (sum + song[i] > s)
		{
			count++;
			sum = song[i];
		}
		else sum += song[i];
	}

	return count;
}

int main()
{
	// 새로운 풀이 (이분 검색을 활용하지 않고 풀이)

	int n, m, count = 1, sum = 0, total = 0, min;

	cin >> n >> m;

	vector<int> record(n);

	for (int i = 0; i < n; i++)
	{
		cin >> record[i];
		total += record[i];
	}

	// 가능한 가장 작은 최소값은 min일 것. 
	// 여기서 실제 값과 비교하여 min 에서 값을 하나씩 늘려갈 것. 
	min = total / m;

	while (1)
	{
		count = 1;
		sum = 0;

		for (int i = 0; i < n; i++)
		{
			//if (sum + record[i] > min)
			//{
			//	count++;
			//	sum = record[i];
			//}
			//else sum += record[i];			

			sum += record[i];

			if (sum > min)
			{
				count++;
				sum = record[i];

				if (count > m) break;
			}
		}

		if (count <= m) break;

		min++;
	}

	cout << min << endl; 

	//============================================================================//

	// 강의 풀이 (이분검색을 활용하는 것이 더 효율적인지는 의문...)

	/*
	int m, lt = 1, rt = 0, mid, res, max = numeric_limits<int>::min();

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> song[i];
		rt += song[i];

		if (song[i] > max) max = song[i];
	}

	while (lt <= rt)
	{
		mid = (lt + rt)* 0.5f;

		if (getCount(mid) <= m)
		{
			res = mid;
			rt = mid - 1;
		}
		else lt = mid + 1;
	}

	cout << res << endl; 
	*/

	return 0;
}