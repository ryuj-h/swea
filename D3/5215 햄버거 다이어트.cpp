/*
소요 시간 : 2:09:39

그리디 알고리즘 적용해보고 실패

dfs 탐색 구현 후 20^20 수행시간 실패

재료를 쓴 경우와 안 쓴 경우의 수 두가지를 완전탐색으로 변경 성공






평소 햄버거를 좋아하던 민기는 최근 부쩍 늘어난 살 때문에 걱정이 많다.

그렇다고 햄버거를 포기할 수 없었던 민기는 햄버거의 맛은 최대한 유지하면서 정해진 칼로리를 넘지 않는 햄버거를 주문하여 먹으려고 한다.
 

민기가 주로 이용하는 햄버거 가게에서는 고객이 원하는 조합으로 햄버거를 만들어서 준다.

하지만 재료는 미리 만들어서 준비해놓기 때문에 조합에 들어가는 재료를 잘라서 조합해주지는 않고, 재료를 선택하면 준비해놓은 재료를 그대로 사용하여 조합해준다. 

민기는 이 가게에서 자신이 먹었던 햄버거의 재료에 대한 맛을 자신의 오랜 경험을 통해 점수를 매겨놓았다.

민기의 햄버거 재료에 대한 점수와 가게에서 제공하는 재료에 대한 칼로리가 주어졌을 때,

민기가 좋아하는 햄버거를 먹으면서도 다이어트에 성공할 수 있도록 정해진 칼로리 이하의 조합 중에서 민기가 가장 선호하는 햄버거를 조합해주는 프로그램을 만들어보자.

(단 여러 재료를 조합하였을 햄버거의 선호도는 조합된 재료들의 맛에 대한 점수의 합으로 결정되고, 같은 재료를 여러 번 사용할 수 없으며, 햄버거의 조합의 제한은 칼로리를 제외하고는 없다.)

 

[입력]
 

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
 

각 테스트 케이스의 첫 번째 줄에는 재료의 수, 제한 칼로리를 나타내는 N, L(1 ≤ N ≤ 20, 1 ≤ L ≤ 104)가 공백으로 구분되어 주어진다.
 

다음 N개의 줄에는 재료에 대한 민기의 맛에 대한 점수와 칼로리를 나타내는 Ti, Ki(1 ≤ Ti ≤ 103, 1 ≤ Ki ≤ 103)가 공백으로 구분되어 주어진다.
 

[출력]

각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 주어진 제한 칼로리 이하의 조합중에서 가장 맛에 대한 점수가 높은 햄버거의 점수를 출력한다.

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct
{
	int point;
	int calory;
}sJeryo;


int N, L;
sJeryo jeryos[20];
int Maxpoint = 0;

void solve(int depth, int point, int calory)
{
	if (calory > L)
		return;

	if (depth == N)
	{
		if (point > Maxpoint)
		{
			Maxpoint = point;
		}
		return;
	}

	solve(depth + 1, point + jeryos[depth].point, calory + jeryos[depth].calory);
	solve(depth + 1, point, calory);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> L;
		Maxpoint = 0;

		for (int i = 0; i < N; i++)
		{
			int point;
			int calory;
			cin >> point >> calory;

			jeryos[i].point = point;
			jeryos[i].calory = calory;
		}


		solve(0, 0, 0);

		cout << "#" << test_case << " " << Maxpoint << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
