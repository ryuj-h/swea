/*

소요시간 : 20:04

로직은 대충 맞게 짯지만 버그가 무엇인지 확인하지 못해서 다른사람의 코드를 보고 풀었음

dfs에 대한 이해가 더 필요한것 같다




A1, A2, ... , AN의 N개의 자연수가 주어졌을 때, 최소 1개 이상의 수를 선택하여 그 합이 K가 되는 경우의 수를 구하는 프로그램을 작성하시오.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 2개의 자연수 N(1 ≤ N ≤ 20)과 K(1 ≤ K ≤ 1000)가 주어진다.

두 번째 줄에는 N개의 자연수 수열 A가 주어진다. 수열의 원소인 N개의 자연수는 공백을 사이에 두고 주어지며, 1 이상 100 이하임이 보장된다.


[출력]

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 부분 수열의 합이 K가 되는 경우의 수를 출력한다.

*/
#include<iostream>

using namespace std;

int arr[21];

int Sol;
void solve(int index, int sum, int k, int N)
{
	if (sum > k)
	{
		return;
	}
	if (sum == k)
	{
		Sol = Sol + 1;
		return;
	}
	for (int i = index; i < N; i++)
	{
		solve(i + 1, sum + arr[i], k, N);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int K;

		cin >> N;
		cin >> K;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;
		}

		Sol = 0;
		solve(0, 0, K, N);


		cout << "#" << test_case << " " << Sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
