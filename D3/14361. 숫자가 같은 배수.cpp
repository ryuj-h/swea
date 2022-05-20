/*

자연수 N이 있다. N의 10진법 표기(단, 0으로 시작하지 않도록 표기해야 함)에서 나타나는 숫자들을 재배열하여 N보다 큰 N의 배수(즉 2N, 3N, …, k•N, …) 를 만들 수 있는지 판단하는 프로그램을 작성하라.

[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스는 하나의 줄로 이루어진다. 각 줄에는 자연수 N (1 ≤N ≤ 106) 이 공백 하나를 사이로 두고 주어진다.
 

[출력]
각 테스트 케이스마다, 주어진 자연수에 나타난 숫자들을 재배열하여 더 큰 배수를 만들 수 있다면 ‘possible’, 불가능하다면 ‘impossible’을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool posible = false;
int numberint;
std::vector<int> numbers;
bool visited[6];

void dfs(int index, std::vector<int> madenumber)
{
    if (madenumber.size() == numbers.size())
    {
        int made = 0;
        for (auto& nb : madenumber)
            made = 10 * made + nb;
        if (made % numberint == 0 && made / numberint >= 2)
            posible = true;
        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (visited[i])
            continue;

        std::vector<int> save = madenumber;
        visited[i] = true;
        
        save.push_back(numbers[i]);
        dfs(i, save);
        visited[i] = false;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        posible = false;
        string number;
        cin >> number;

        numberint = stoi(number);
        numbers.clear();

        for (int i = 0; i < number.size(); i++)
            numbers.push_back(number[i] - '0');


        memset(visited, false, sizeof(visited));
        std::vector <int>dd;
        dfs(0, dd);
        if (posible)
            cout << "#" << test_case << " possible" << endl;
        else
            cout << "#" << test_case << " impossible" << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
