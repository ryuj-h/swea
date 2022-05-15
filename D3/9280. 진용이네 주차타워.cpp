/*

부지런한 진용이는 정문 앞에서 유료 주차장 운영하고 있다. 이 주차장은 1 부터 n 까지 번호가 매겨진 n 개의 주차 공간을 가지고 있다.
매일 아침 모든 주차 공간이 비어 있는 상태에서 영업을 시작하며, 다음과 같은 방식으로 운영된다.

 

차가 주차장에 도착하면, 진용이는 비어있는 주차 공간이 있는지 검사한다.
 
비어있는 공간이 없다면, 빈 공간이 생길 때까지 차량을 입구에서 기다리게 한다.
 
빈 주차 공간이 있으면 진용이는 곧바로 주차를 시키며, 주차 가능한 공간 중 번호가 가장 작은 주차 공간에 주차하도록 한다.
 
만약 주차를 기다리는 차량이 여러 대라면, 입구의 대기장소에서 자기 차례를 기다려야 한다. 운전자들은 예의가 바르기 때문에 새치기를 하지 않는다.
 

주차요금은 차량의 무게와 주차 공간마다 따로 책정된 단위 무게당 금액을 곱한 가격이다. 진용이네 주차장에서는 종일 이용권만을 판매하기 때문에 이용시간은 고려하지 않는다.
 

진용이는 오늘 주차장을 이용할 m 대의 차량들이 들어오고 나가는 순서를 알고 있다.
진용이의 주차장이 오늘 하루 벌어들일 총 수입을 계산하는 프로그램을 작성하라.
 

[입력]

 

첫 번째 줄에 테스트 케이스의 수 TC 가 주어진다.
이후 TC 개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되어 있다.

 

첫 번째 줄에 자연수  n 과  m 이 주어진다. (1 ≤ n  ≤ 100, 1 ≤ m  ≤ 2000)
n 개의 줄에 i 번째 주차 공간의 단위 무게당 요금 Ri 가 정수로 주어진다. (1 ≤ Ri  ≤ 100)
m 개의 줄에 차량 i 의 무게 Wi 가 정수로 주어진다. 차량번호 i 와 차량의 도착 순서는 아무런 관계가 없다. (1 ≤ Wi  ≤ 10000)
이후  2m 개의 줄에 차량들의 주차장 출입 순서가 하나의 정수  x 로 주어진다.
주어진 정수 x 가 양수면, x 번 차가 주차장에 들어옴을 뜻한다.
x 가 음수면, -x 번 차가 주차장을 나감을 뜻한다.
 

주차장에 들어오지 않은 차량이 주차장에서 나가는 경우는 주어지지 않는다.
1 번부터 m 번까지 모든 차량은 정확하게 한 번씩 주차장에 들어오고, 한 번씩 주차장에서 나간다.
또한 입구에서 대기 중인 차량이 주차를 하지 못하고 그냥 돌아가는 경우는 없다.

 

[출력]

각 테스트 케이스마다 ‘#t ’(t 는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 진용이가 오늘 하룻동안 벌어들일 수입을 출력하라.

*/
#include<iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N>> M;
		vector<int> parks;
		vector<int> cars;
		int arr[100];
		memset(arr, -1, sizeof(arr));
		int fullnum = 0;
		for (int i = 0; i < N; i++)
		{
			int ri;
			cin >> ri;
			parks.push_back(ri);
		}
		for (int i = 0; i < M; i++)
		{
			int Wi;
			cin >> Wi;
			cars.push_back(Wi);
		}

		deque<int>wating;

		for (int i = 0; i < 2 * M; i++)
		{
			int car;
			cin >> car;
			if (car > 0)
			{
				car = car - 1;
				wating.push_back(car);
				bool find = false;
				for (int ii = 0; ii < N; ii++)
				{
					if (arr[ii] == -1)
					{
						arr[ii] = car;
						fullnum = fullnum + cars[car] * parks[ii];
						find = true;
						wating.pop_back();
						break;
					}
				}
			}
			else
			{
				car = car * -1;
				car = car - 1;
				for (int ii = 0; ii < N; ii++)
				{
					if (arr[ii] == car)
					{
						arr[ii] = -1;
						if (wating.size() > 0)
						{
							auto f = wating.front();
							arr[ii] = f;
							fullnum = fullnum + cars[f] * parks[ii];
							wating.pop_front();
						}
						break;
					}
				}
			}
		}
		cout <<"#"<< test_case<<" "<< fullnum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
