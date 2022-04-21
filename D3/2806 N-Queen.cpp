/*
01:19:58

8*8 체스보드에 8개의 퀸을 서로 공격하지 못하게 놓는 문제는 잘 알려져 있는 문제이다.

퀸은 같은 행, 열, 또는 대각선 위에 있는 말을 공격할 수 있다. 이 문제의 한가지 정답은 아래 그림과 같다.
 



이 문제의 조금 더 일반화된 문제는 Franz Nauck이 1850년에 제기했다.

N*N 보드에 N개의 퀸을 서로 다른 두 퀸이 공격하지 못하게 놓는 경우의 수는 몇가지가 있을까?

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 자연수 N(1 ≤ N ≤ 10)이 주어진다.


[출력]

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 



*/
#include<iostream>
#include <math.h>
using namespace std;



int N;
int solution;
int arr[10];

bool check(int curr)
{
	for (int i = 0; i < curr;i++)
	{
		if (arr[i] == arr[curr] || abs(arr[curr] - arr[i]) == curr - i)
			return false;
	}
	return true;
}

void Nqueen(int x)
{
	if (x == N)
	{
		solution++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			arr[x] = i;
			if (check(x))
				Nqueen(x + 1);
		}
	}
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution = 0;
		for (int i = 0; i < 10; i++)
			arr[i] = 0;
		cin >> N;

		Nqueen(0);
		cout << "#" << test_case << " " << solution << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
