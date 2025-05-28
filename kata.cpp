
#include "KATA_0527.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace KATA_0527
{
    int solution(int n)
    {
        int answer = 0;
        // n 까지의 짝수 개수는 짝수인 경우 절반 아닌 경우
        int evenCnt = n / 2; // 홀 수이던 짝수 이던 항상 짝수의 개수가 됨.
        // 2부터 evenCnt * 2 까지 2씩 증가한 합 
        int evenN = evenCnt * 2;
        answer = evenCnt * (evenN + 2) / 2;
        return answer;
    }
}

namespace KATA_0528
{
    // 스레드 문제 문자열 회전
    void solution(std::string str)
    {
        int start = 0, size = str.size();

        cout << "[";
        for (int i = 0; i < str.size(); ++i, ++start)
        {
            cout << "\"";
            for (int j = start; j < size; ++j)
            {
                cout << str[j];
            }
            if (start > 0)
            {
                for (int j = 0; j < start; ++j)
                {
                    cout << str[j];
                }
            }
            cout << "\" ";
        }
        cout << "]" << endl;
    }

    double solution(vector<int> numbers) 
    {
        double answer = 0;

        for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        {
            answer += *iter;
        }
        answer /= numbers.size();
        return answer;
    }
}