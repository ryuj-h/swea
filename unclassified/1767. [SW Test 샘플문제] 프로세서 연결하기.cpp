/*소요시간: 3:00:00
  
 다른사람 풀이 보고 풀었다.
 
 이런류의 문제는 왜이렇게 손에 안붙는지 모르겠다 ㅠㅠㅠ...
  
  
  */


#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
	int x;
	int y;
	bool visit;
}CORE;

int N;
int board[13][13];
int corenum;
CORE cores[12];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int MaxConnected;
int MinLinedist;


int Connect(int dirx, int diry, int currx, int curry)
{
	if (currx < 0 || currx >= N || curry < 0 || curry >= N)
		return 1;
	if (board[curry][currx] == 1 || board[curry][currx] == -1)
		return 0;
	int nb = Connect(dirx, diry, currx + dirx, curry + diry);
	if (nb)
	{
		board[curry][currx] = -1;
		return nb + 1;
	}
	else
		return 0;
}

void DisConnect(int dirx, int diry, int currx, int curry)
{
	if (currx < 0 || currx >= N || curry < 0 || curry >= N)
		return;
	board[curry][currx] = 0;
	DisConnect(dirx, diry, currx + dirx, curry + diry);
}


void dfs(int index,int connected,int linedist)
{
	if (MaxConnected < connected)
	{
		MaxConnected = connected;
		MinLinedist = linedist;
	}
	else if (MaxConnected == connected)
	{
		MinLinedist = min(MinLinedist, linedist);
	}
	if (index == corenum)
		return;


	for (int k = 0; k < 4; k++)
	{
		int condist = Connect(dx[k], dy[k], cores[index].x + dx[k], cores[index].y + dy[k]) - 1;
		if (condist > 0)
		{
			dfs(index + 1, connected + 1, linedist + condist);
			DisConnect(dx[k], dy[k], cores[index].x + dx[k], cores[index].y + dy[k]);
		}
	}
	dfs(index + 1, connected, linedist);
}


void solve()
{
	for (int y = 1; y < N - 1; y++)
	{
		for (int x = 1; x < N - 1; x++)
		{
			if (board[y][x] == 1)
			{
				cores[corenum].x = x;
				cores[corenum].y = y;
				corenum++;
			}
		}
	}
	dfs(0, 0, 0);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		corenum = 0;
		MaxConnected = 0;
		MinLinedist = 999998798798;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int nb;
				cin >> nb;
				board[y][x] = nb;
			}
		}
		solve();


		cout << "#" << test_case << " "<< MinLinedist << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
