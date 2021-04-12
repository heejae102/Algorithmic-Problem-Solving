#include<stdio.h>
#include<iostream>
using namespace std; 

// 1차 복습 풀이시간 : 6분 
// (복습 필요 / cout으로 문자 + 정수형 출력 시 정수형 아스키코드 값으로 출력되므로 char로 캐스팅 필요)
// (tolwer, toupper, isdigit, isalpha 등의 함수는 int형 리턴값을 반환하므로 char 형으로 캐스팅 필요)

/*

<07. 영어 단어 복구(문자열 컨트롤)>

현수의 컴퓨터가 바이러스에 걸려 영어단어가 뛰어쓰기와 대소문자가 혼합되어 표현된다.
예를 들면 아름다운 이란 뜻을 가지고 있는 beautiful 단어가
“bE au T I fu L” 과 같이 컴퓨터에 표시되고 있습니다. 

위와 같이 에러로 표시되는 영어단어를 원래의 표현대로 
공백을 제거하고 소문자화 시켜 출력하는 프로그램을 작성하세요.

=============================================================================

▶ 입력설명
첫 줄에 바이러스에 걸린 영어단어가 주어진다. 
바이러스에 걸린 영어단어의 길이(공백포함)는 100을 넘지 않는다. 
문자사이의 공백은 연속적으로 존재할 수 있습니다. 
입력은 알파벳과 공백만 주어집니다.

▶ 출력설명
첫 줄에 소문자로 된 정상적인 영어단어를 출력한다.

=============================================================================

▶ 입력예제
bE au T I fu L

▶ 출력예제
beautiful

*/

int main()
{
	// 최초의 풀이 

	/*
	char input[101] = { 0 };

	// 길이 100 이하의 문자열 입력(영어알파벳 + 공백문자)
	cin.getline(input, 100);

	// ※ input[i] != '\0' 를 조건식으로 설정하면 공백문자에서 끊김
	for (int i = 0; i < strlen(input); i++)
	{
		// 공백문자 제외 소문자로 변경한 문자열 출력 
		if (input[i] != ' ')
		{
			//input[i] < 'a' ? printf("%c", input[i] + 32) : printf("%c", input[i]);

			input[i] < 'a' ? cout << char(input[i] + 32) : cout << input[i];
		}
	}
	*/

	// 개선된 풀이 

	char ch[101]{ 0 };

	cin.getline(ch, 100);

	for (int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] != ' ') cout << (char)tolower(ch[i]);
	}

	//============================================================================// 

	// 강의 풀이 

	char input[101], res[101];

	int p = 0;

	//fgets(input, 100, stdin);	// fgets로 받으면 자꾸 마지막 문자가 추가되는 오류 생김. 
	cin.getline(input, 100);

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ')
		{
			input[i] < 'a' ? res[p++] = input[i] + 32 : res[p++] = input[i];
		}
	}

	res[p] = '\0';
	printf("%s", res);

	return 0;
}