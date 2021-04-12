#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std; 

// 1차 복습 풀이시간 : 13분 

/*

<16. Anagram (구글 인터뷰)>

Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 
그 구성이 일치하면 두 단어는 아나그램이라고 합니다.

예를 들면 AbaAeCe 와 baeeACA 는 알파벳을 나열 순서는 다르지만 그 구성을 살펴보면 
A(2), a(1), b(1), C(1), e(2)로 알파벳과 그 개수가 모두 일치합니다. 
즉 어느 한 단어를 재배열하면 상대편 단어가 될 수 있는 것을 아나그램이라 합니다.

길이가 같은 두 개의 단어가 주어지면 두 단어가 
아나그램인지 판별하는 프로그램을 작성하세요. 
아나그램 판별시 대소문자가 구분됩니다.

=============================================================================

▶ 입력설명
첫 줄에 첫 번째 단어가 입력되고, 두 번째 줄에 두 번째 단어가 입력됩니다.
단어의 길이는 100을 넘지 않습니다.

▶ 출력설명
두 단어가 아나그램이면 "YES"를 출력하고, 아니면 "NO"를 출력합니다.

=============================================================================

▶ 입력예제
AbaAeCe
baeeACA

▶ 출력예제
YES

*/

int main()
{
	// 최초의 풀이 

	/*
	// 첫 줄에 첫 번째 단어가 입력되고, 
	// 두 번째 줄에 두 번째 단어가 입력됩니다.
	// 단어의 길이는 100을 넘지 않습니다.

	char a[101]{ 0 }, b[101]{ 0 };
	char alpha1[123]{ 0 }, alpha2[123]{ 0 };

	cin >> a >> b;

	for (int i = 0; a[i] != '\0'; i++)
	{
		alpha1[a[i]]++;
		alpha2[b[i]]++;
	}

	for (int i = 'A'; i <= 'z'; i++)
	{
		if (alpha1[i] != alpha2[i])
		{
			printf("NO\n");
			return 0; 
		}
	}

	printf("YES\n");

	// 두 단어가 아나그램이면 "YES"를 출력하고, 아니면 "NO"를 출력합니다.
	*/

	//============================================================================// 

	// 강의 풀이 (아스키코드 값에서 상수를 빼기 때문에 가독성이 떨어짐.)

	int a[60]{ 0 }, b[60]{ 0 };
	char str[101]{ 0 };

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		// 대문자일 경우와 소문자일 경우를 나눠서 계산 
		if (str[i] >= 65 && str[i] <= 90) a[str[i] - 64]++;
		else a[str[i] - 70]++;
	}

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		// 대문자일 경우와 소문자일 경우를 나눠서 계산 
		if (str[i] >= 65 && str[i] <= 90) b[str[i] - 64]++;
		else b[str[i] - 70]++;
	}

	for (int i = 0; i <= 52; i++)
	{
		if (a[i] != b[i])
		{
			printf("NO\n");
			exit(0);
		}
	}

	printf("YES\n");

	return 0;
}