#include<iostream>
#include<vector>
using namespace std; 

/*

<50. 영지 선택(small : 2차원 배열 브루트포스)>

세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 
전체 땅은 사각형으로 표시된다. 

그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는
땅의 크기(세로의 길이와 가로의 길이)를 정해주면 전체 땅 중에서
그 크기의 땅의 위치를 현수가 정하면 되는 것이다.

전체 땅은 사각형 모양의 격자로 되어 있으며, 
그 사각형 땅 안에는 많은 오렌지 나무가 심겨져 있다. 
현수는 오렌지를 무척 좋아하여 오렌지 나무가 
가장 많이 포함되는 지역을 선택하고 싶어 한다. 

현수가 얻을 수 있는 영지의 오렌지 나무 
최대 개수를 출력하는 프로그램을 작성하세요. 

다음과 같은 땅의 정보가 주어지고, 
현수가 하사받을 크기가 가로 2, 세로 3의 크기이면 
가장 많은 오렌지 나무가 있는 영지는 
총 오렌지 나무의 개수가 16인 3행 4열부터 시작하는 구역이다.

3  5  1  3  1  3  2
1  2  1  3  1  1  2
1  3  1 (5)(1)(3) 4
5  1  1 (3)(1)(3) 2
3  1  1  3  1  1  2
1  3  1  3  1  2  2

=============================================================================

▶ 입력설명
첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (5 <= H, W <= 50) 

그 다음 H줄에 걸쳐 각 사각형 지역에 오렌지의 나무 개수(1 ~ 9개) 정보가 주어진다.

그 다음 영지의 크기인 세로길이(1 ~ H)와 가로길이(1 ~ W)가 차례로 입력된다.

▶ 출력설명
첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.

=============================================================================

▶ 입력예제
6 7
3 5 1 3 1 3 2
1 2 1 3 1 1 2
1 3 1 5 1 3 4
5 1 1 3 1 3 2
3 1 1 3 1 1 2
1 3 1 3 1 2 2
2 3

▶ 출력예제
16

*/

int main()
{
	// 최초의 풀이 

	/*
	int h, w, terrain[50][50]{ 0 }, hCount = 0, sum = 0, max = numeric_limits<int>::min();
	int terrH, terrW;

	cin >> h >> w; 

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> terrain[i][j];
		}
	}

	cin >> terrH >> terrW;

	for (int i = 0; i < h - (terrH - 1); i++)
	{
		for (int j = 0; j < w - (terrW - 1); j++)
		{
			hCount = 0;
			sum = 0;

			while (hCount < terrH)
			{
				for (int k = j; k < j + terrW; k++)
				{
					sum += terrain[i + hCount][k];
				}

				hCount++;
			}

			if (sum > max) max = sum; 
		}
	}

	cout << max << endl; 
	*/

	//============================================================================//

	// 강의 풀이 

	int terrain[50][50]{ 0 };
	int h, w, height, width, sum = 0, max = numeric_limits<int>::min();

	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> terrain[i][j];
		}
	}

	cin >> height >> width;

	for (int i = 0; i < h - (height - 1); i++)
	{
		for (int j = 0; j < w - (width - 1); j++)
		{
			sum = 0;

			for (int k = i; k < i + height; k++)
			{
				for (int l = j; l < j + width; l++)
				{
					sum += terrain[k][l];
				}
			}

			if (sum > max) max = sum;
		}
	}

	cout << max << endl; 

	return 0;
}