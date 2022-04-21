/*
26:00

패턴에서 반복되는 부분을 마디라고 부른다. 문자열을 입력 받아 마디의 길이를 출력하는 프로그램을 작성하라.


[제약 사항]

각 문자열의 길이는 30이다. 마디의 최대 길이는 10이다.


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 길이가 30인 문자열이 주어진다.


[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

*/


#include<iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int Sol = 0;
		char str[32];
		cin >> str;

		for (int i = 10; i > 0; i--)
		{
			char madi[11] = "";
			char cpy[11] = "";
			strncpy(madi, str, i);
			strncpy(cpy, str + i, i);
			madi[i] = '\0';
			cpy[i] = '\0';
			if (strcmp(madi, cpy) == 0)
			{
				Sol = i;
			}
		}


		cout << "#" << test_case << " " << Sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
