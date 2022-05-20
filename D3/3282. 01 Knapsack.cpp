/*

다시 풀어볼것


민수에게는 1번부터 N번까지의 번호가 부여된 N(1≤N≤100)개의 물건과 최대 K(1≤K≤1000) 부피만큼을 넣을 수 있는 가방이 있다.

1번 물건부터 N번 물건 각각은 부피  Vi와 가치 Ci 를 가지고 있다. (1≤Vi, Ci≤100)

민수는 물건들 중 몇 개를 선택하여 가방에 넣어서 그 가치의 합을 최대화하려고 한다.

단, 선택한 물건들의 부피 합이 K 이하여야 한다.

민수가 가방에 담을 수 있는 최대 가치를 계산하자.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫째 줄에 물건의 개수와 가방의 부피인 N K가 주어진다.

다음 N개의 줄에 걸쳐서 i번 물건의 정보를 나타내는 부피  Vi와 가치 Ci가 주어진다.

[출력]

각 테스트 케이스마다 가방에 담을 수 있는 최대 가치를 출력한다.

민수에게는 1번부터 N번까지의 번호가 부여된 N(1≤N≤100)개의 물건과 최대 K(1≤K≤1000) 부피만큼을 넣을 수 있는 가방이 있다.

1번 물건부터 N번 물건 각각은 부피  Vi와 가치 Ci 를 가지고 있다. (1≤Vi, Ci≤100)

민수는 물건들 중 몇 개를 선택하여 가방에 넣어서 그 가치의 합을 최대화하려고 한다.

단, 선택한 물건들의 부피 합이 K 이하여야 한다.

민수가 가방에 담을 수 있는 최대 가치를 계산하자.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫째 줄에 물건의 개수와 가방의 부피인 N K가 주어진다.

다음 N개의 줄에 걸쳐서 i번 물건의 정보를 나타내는 부피  Vi와 가치 Ci가 주어진다.

[출력]

각 테스트 케이스마다 가방에 담을 수 있는 최대 가치를 출력한다.
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
        int v[101][1001];
        int w[101];
        int c[101];
        int N, W, answer = 0;
        cin >> N >> W;

        for (int i = 1; i <= N; i++)
            cin >> w[i] >> c[i];

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (w[i] > j)
                    v[i][j] = v[i - 1][j];
                else
                {
                    if (c[i] + v[i - 1][j - w[i]] > v[i - 1][j])
                    {
                        v[i][j] = c[i] + v[i - 1][j - w[i]];
                    }
                    else
                    {
                        v[i][j] = v[i - 1][j];
                    }
                }
            }
        }
		/*for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << "#" << test_case << " " << v[N][W] << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
