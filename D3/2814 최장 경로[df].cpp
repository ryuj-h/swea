/*

01:16:59

1.배열 초기화를 생활화 하자

2.dfs의 포문 시작 i를 잘 생각해 보고 정하자

문제와 같은 경우 계속해서 모든 부분의 노드를 탐색해야 했기 때문에 i는 시작점이 index+1 이 아닌 1로 시작해야 한다





N개의 정점과 M개의 간선으로 구성된 가중치가 없는 무방향 그래프에서의 최장 경로의 길이를 계산하자.

정점의 번호는 1번부터 N번까지 순서대로 부여되어 있다.

경로에는 같은 정점의 번호가 2번 이상 등장할 수 없으며, 경로 상의 인접한 점들 사이에는 반드시 두 정점을 연결하는 간선이 존재해야 한다.

경로의 길이는 경로 상에 등장하는 정점의 개수를 나타낸다.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 개의 자연수 N M(1 ≤ N ≤ 10, 0 ≤ M ≤ 20)이 주어진다.

두 번째 줄부터 M개의 줄에 걸쳐서 그래프의 간선 정보를 나타내는 두 정수 x y(1 ≤ x, y ≤ N)이 주어진다.

x와 y는 서로 다른 정수이며, 두 정점 사이에 여러 간선이 존재할 수 있다.


[출력]

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 그래프에서의 최장 경로의 길이를 출력한다.


*/

#include<iostream>

using namespace std;


int arr[21][21];
int passed[12];

int N;
int M;
int Sol = 0;

void reset()
{
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			arr[i][j] = 0;
	for (int i = 0; i < 12; i++)
		passed[i] = 0;
}

void solution(int index, int passednodenum)
{
	if (Sol < passednodenum)
		Sol = passednodenum;

	for (int i = 1; i < N + 1; i++)
	{
		if (arr[index][i])
		{
			if (passed[i] == 0)
			{
				passed[i] = 1;
				solution(i, passednodenum + 1);
				passed[i] = 0;
			}
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
		Sol = 0;
		reset();
		cin >> N;
		cin >> M;
		
		for (int i = 0; i < M; i++)
		{
			int num1;
			int num2;
			cin >> num1;
			cin >> num2;
			arr[num1][num2] = arr[num2][num1] = 1;
		}
		for (int i = 1; i <= N;i++)
		{
			passed[i] = 1;
			solution(i, 1);
			passed[i] = 0;
		}

		cout << "#" << test_case << " " << Sol << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
