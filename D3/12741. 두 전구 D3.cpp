/*

어이 없는 문제
입출력을 손봐야 한다니


  두 개의 전구 X와 Y가 있다. 당신은 0초에서부터 시작하여 100초간 두 전구가 언제 켜지는지를 관찰하였다.
  관찰 결과, 전구 X는 관찰 시작 경과 후 A초에서부터 관찰 시작 경과 후 B초까지에만 켜져 있었다. 전구 Y는 관찰 시작 경과 후 C초에서부터 관찰 시작 경과 후 D초까지에만 켜져 있었다.
  당신이 두 전구를 관찰하던 100초 중 두 전구가 동시에 켜져 있던 시간은 몇 초일까?

[입력]
  첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
  각 테스트 케이스의 첫 번째 줄에는 네 개의 정수 A, B, C, D (0 ≤ A < B ≤ 100, 0 ≤ C < D ≤ 100)가 공백 하나를 사이로 두고 순서대로 주어진다.

[출력]
  각 테스트 케이스마다, 두 전구가 동시에 켜져 있던 시간이 몇 초인지를 한 줄에 하나씩 출력한다.



*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int rres[50000];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int xs, xe, ys, ye;
		scanf("%d %d %d %d", &xs, &xe, &ys, &ye);//통과
		//cin >> xs >> xe >> ys >> ye;
		//미통과

		int mmax = max(xs, ys);
		int mmin = min(xe, ye);

		int res = mmin - mmax;
		if (res < 0)
			res = 0;
		rres[test_case - 1] = res;
		/*memset(arr1, false, sizeof(arr1));
		memset(arr2, false, sizeof(arr2));
		for (int i = xs; i <= xe; i++)
			arr1[i] = true;
		for (int i = ys; i <= ye; i++)
			arr2[i] = true;
		
		int rres = 0;
		for (int i = 0; i < 101; i++)
		{
			if (arr1[i] && arr2[i])
				rres++;
		}
		if (rres)
			rres--;
		res.push_back(rres);*/
	}

	for (int i = 0; i < T; i++)
	{
		printf("#%d %d\n",i+1,rres[i]);//통과
		//cout << "#" << i+1 << " " << rres[i] << endl;
		//미통과
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
