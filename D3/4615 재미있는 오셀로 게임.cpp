/*

소요시간 59:05

진짜 깔끔하게 코드 작성한 기분

완전탐색 사용




2017년 A형 기출


오셀로라는 게임은 흑돌과 백돌을 가진 사람이 번갈아가며 보드에 돌을 놓아서 최종적으로 보드에 자신의 돌이 많은 사람이 이기는 게임이다.

보드는 4x4, 6x6, 8x8(가로, 세로 길이) 크기를 사용한다. 6x6 보드에서 게임을 할 때, 처음에 플레이어는 다음과 같이 돌을 놓고 시작한다(B : 흑돌, W : 백돌).

4x4, 8x8 보드에서도 동일하게 정가운데에 아래와 같이 배치하고 시작한다.



그리고 흑, 백이 번갈아가며 돌을 놓는다.

처음엔 흑부터 시작하는데 이 때 흑이 돌을 놓을 수 있는 곳은 다음과 같이 4군데이다.



플레이어는 빈공간에 돌을 놓을 수 있다.

단, 자신이 놓을 돌과 자신의 돌 사이에 상대편의 돌이 있을 경우에만 그 곳에 돌을 놓을 수 있고, 그 때의 상대편의 돌은 자신의 돌로 만들 수 있다.

(여기에서 "사이"란 가로/세로/대각선을 의미한다.)

(2, 3) 위치에 흑돌을 놓은 후의 보드는 다음과 같다.



이런 식으로 번갈아가며 흑, 백 플레이어가 돌을 놓는다.

만약 돌을 놓을 곳이 없다면 상대편 플레이어가 다시 돌을 놓는다.

보드에 빈 곳이 없거나 양 플레이어 모두 돌을 놓을 곳이 없으면 게임이 끝나고 그 때 보드에 있는 돌의 개수가 많은 플레이어가 승리하게 된다.


 [입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 보드의 한 변의 길이 N과 플레이어가 돌을 놓는 횟수 M이 주어진다. N은 4, 6, 8 중 하나이다.

그 다음 M줄에는 돌을 놓을 위치와 돌의 색이 주어진다.

돌의 색이 1이면 흑돌, 2이면 백돌이다.

만약 3 2 1이 입력된다면 (3, 2) 위치에 흑돌을 놓는 것을 의미한다.

돌을 놓을 수 없는 곳은 입력으로 주어지지 않는다.

 [출력]

각 테스트 케이스마다 게임이 끝난 후 보드 위의 흑돌, 백돌의 개수를 출력한다.

흑돌이 30개, 백돌이 34인 경우 30 34를 출력한다.





*/


#include<iostream>
#include<cstring>

using namespace std;

int board[8][8];

int N, M;

bool line(int dirx, int diry, int currx, int curry, int color)
{
	if (currx < 0 || currx >= N)// 맵 밖일경우 실패
		return false;
	if (curry < 0 || curry >= N)// 맵 밖일경우 실패
		return false;

	if (board[curry][currx] == 0)//진행 중 빈칸을 만났다면 실패
		return false;

	if (board[curry][currx] == color)//같은색 돌을 만나고, 만낫던 모든 색이 반대색상일경우 성공
		return true;
	else//계속 다른색 돌을 만나는중
	{
		if (line(dirx, diry, currx + dirx, curry + diry, color))//진행방향 대로 진행
		{
			board[curry][currx] = color;//성공이 반환되었다면 색상 변경후 성공 다시 반환
			return true;
		}
		else//실패
			return false;
	}
}

void solve(int x, int y,int color)
{
	board[y][x] = color;//돌 배치

	//전 방향으로 진행
	line(-1, -1, x - 1, y - 1, color);	//좌상단
	line(0, -1, x, y - 1, color);		//중상단
	line(1, -1, x + 1, y - 1, color);	//우상단

	line(1, 0, x + 1, y, color);		//우중단
	line(-1, 0, x - 1, y, color);		//좌중단

	line(-1, 1, x - 1, y + 1, color);	//좌하단
	line(0, 1, x, y + 1, color);		//중하단
	line(1, 1, x + 1, y + 1, color);	//우하단
}



int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		memset(board, 0, sizeof(board));

		//판 초기화 
		board[N / 2 - 1][N / 2 - 1] = 2;
		board[N / 2][N / 2] = 2;
		board[N / 2 - 1][N / 2] = 1;
		board[N / 2 ][N / 2 - 1] = 1;
		
		for (int i = 0; i < M; i++)
		{
			int x, y, color;
			cin >> x >> y >> color;
			solve(x - 1, y - 1, color);//예제의 좌표 1,1 부터 시작하는걸 뒤늦게 확인함.
		}

		int black = 0;
		int white = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (board[y][x] == 1)
				{
					black++;
				}
				else if (board[y][x] == 2)
				{
					white++;
				}
			}
		}
		cout << "#" << test_case << " " << black << " " << white << endl;
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
