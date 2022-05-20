/*
소요 시간 1:36

아기 석환이는 최근 구구단을 배웠다. 그래서 1 이상 9 이하의 자연수 두개를 곱셈할 수 있으나, 10 이상의 자연수를 곱셈하는 방법은 모른다.
두 정수 A, B가 주어진다. 아기 석환이 두 정수를 곱셈할 수 있으면 곱을 출력하고, 아니면 -1을 출력하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 TC가 주어진다. 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다. 각 테스트 케이스는 다음과 같이 구성되었다.
    ∙ 첫 번째 줄에 두 정수 A, B가 주어진다. (1 ≤ A, B ≤ 20)

[출력]
각 테스트 케이스마다 정답을 출력하라.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int A, B;
		int res;

		scanf("%d %d", &A, &B);

		if (A > 9 || B > 9)
			res = -1;
		else
			res = A * B;

		printf("#%d %d\n", test_case, res);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
