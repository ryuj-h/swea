/* 걸린 시간 1:24:00

후기:

좀 복잡하게 풀었다

실제 개발에서 사용하던 std::Map 을 사용해서 풀어봤는데 잘 안됐다.

시험볼 때는 이렇게 만들다간 시간 다갈거같은데 어쩌지...



[문제]

그림과 같이 도식화한 지도에서 A도시에서 출발하여 B도시로 가는 길이 존재하는지 조사하려고 한다.

길 중간 중간에는 최대 2개의 갈림길이 존재하고, 모든 길은 일방 통행으로 되돌아오는 것이 불가능하다.

다음과 같이 길이 주어질 때, A도시에서 B도시로 가는 길이 존재하는지 알아내는 프로그램을 작성하여라.

 - A와 B는 숫자 0과 99으로 고정된다.

 - 모든 길은 순서쌍으로 나타내어진다. 위 예시에서 2번에서 출발 할 수 있는 길의 표현은 (2, 5), (2, 9)로 나타낼 수 있다.

 - 가는 길의 개수와 상관없이 한가지 길이라도 존재한다면 길이 존재하는 것이다.

 - 단 화살표 방향을 거슬러 돌아갈 수는 없다.



[제약 사항]

출발점은 0, 도착점은 99으로 표현된다.

정점(분기점)의 개수는 98개(출발점과 도착점 제외)를 넘어가지 않으며, 한 개의 정점에서 선택할 수 있는 길의 개수도 2개를 넘어가지 않는다.

아래 제시된 가이드 라인은 제안사항일 뿐 강제사항은 아니다.

[데이터 저장 가이드]

정점(분기점)의 개수가 최대 100개 이기 때문에, size [100]의 정적 배열 2개을 선언하여, 각 정점의 번호를 주소로 사용하고, 저장되는 데이터는 각 정점에서 도착하는 정점의 번호를 저장한다.

위 그림을 저장하였을 때 결과는 다음과 같다.
 


[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호와 길의 총 개수가 주어지고 그 다음 줄에는 순서쌍이 주어진다.

순서쌍의 경우, 별도로 나누어 표현되는 것이 아니라 숫자의 나열이며, 나열된 순서대로 순서쌍을 이룬다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스에 대한 답을 출력한다.


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N = 0;
int solution = 0;

typedef struct node
{
	bool visit;
	int number;
	int tonum1;
	int tonum2;
	node* ptr1;
	node* ptr2;
}node;

void dfs(node* node)
{
	if (solution)
		return;
	if (node->tonum1 == 99 || node->tonum2 == 99)
	{
		solution = 1;
		return;
	}

	if (node->visit == true)
	{
		return;
	}
	else
	{
		node->visit = true;
		if (node->ptr1)
			dfs(node->ptr1);
		if (node->ptr2)
			dfs(node->ptr2);
		node->visit = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;
		cin >> N;
		solution = 0;


		std::map<int, node> Map;
		Map.clear();
		for (int i = 0; i < N; i++)
		{
			int num;
			int tonum;
			cin >> num;
			cin >> tonum;

			if (Map.find(num) == Map.end())
			{
				node* obj= new node;
				obj->number = num;
				obj->tonum1 = tonum;
				Map[num] = *obj;
			}
			else
			{
				Map[num].tonum2 = tonum;
			}
		}

		for (auto& obj : Map)
		{
			if (obj.second.tonum1)
			{
				auto& ptr = Map[obj.second.tonum1];
				obj.second.ptr1 = &ptr;
			}
			else
				obj.second.ptr1 = 0;
			if (obj.second.tonum2)
			{
				auto& ptr = Map[obj.second.tonum2];
				obj.second.ptr2 = &ptr;
			}
			else
				obj.second.ptr2 = 0;
		}

		dfs(&Map[0]);
		cout << "#" << test_case << " " << solution << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

