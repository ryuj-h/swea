
/*
소요 시간 : 27:44

다소 무식하게 검사했지만 1트 통과




N X N 크기의 판이 있다. 판의 각 칸에는 돌이 있거나 없을 수 있다. 돌이 가로, 세로, 대각선 중 하나의 방향으로 다섯 개 이상 연속한 부분이 있는지 없는지 판정하는 프로그램을 작성하라.

  

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(5 ≤ N ≤ 20)이 주어진다.

다음 N개의 줄의 각 줄에는 길이 N인 문자열이 주어진다. 각 문자는 ‘o’또는 ‘.’으로, ‘o’는 돌이 있는 칸을 의미하고, ‘.’는 돌이 없는 칸을 의미한다.

  

[출력]

각 테스트 케이스 마다 돌이 다섯 개 이상 연속한 부분이 있으면 “YES”를, 아니면 “NO”를 출력한다.

*/



#include<iostream>

using namespace std;


int N;
char board[20][20];
bool Sol;

bool Omok(int dirx, int diry, int currx, int curry, int count)
{
	if (count == 5)
	{
		return true;
	}
	if (currx < 0 || currx >= N || curry < 0 || curry >= N)
		return false;
	if (board[curry][currx] == 'o')
	{
		return Omok(dirx, diry, currx + dirx, curry + diry, count + 1);
	}
	return false;
}

void solve()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == 'o')
			{
				bool a = Omok(-1, -1, x - 1, y - 1, 1);	//좌상단
				bool b = Omok(0, -1, x, y - 1, 1);		//중상단
				bool c = Omok(1, -1, x + 1, y - 1, 1);	//우상단

				bool d = Omok(1, 0, x + 1, y, 1);		//우중단
				bool e = Omok(-1, 0, x - 1, y, 1);		//좌중단

				bool f = Omok(-1, 1, x - 1, y + 1, 1);	//좌하단
				bool g = Omok(0, 1, x, y + 1, 1);		//중하단
				bool h = Omok(1, 1, x + 1, y + 1, 1);	//우하단
				
				if (a || b || c || d || e || f || g || h)
				{
					Sol = true;
					return;
				}
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

		cin >> N;
		Sol = false;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				char nb;
				cin >> nb;
				board[y][x] = nb;
			}
		}
		
		solve();

		if (Sol)
			cout << "#" << test_case << " YES" << endl;
		else
			cout << "#" << test_case << " NO" << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
