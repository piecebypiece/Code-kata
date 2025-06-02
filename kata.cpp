
#include <string>
#include <iostream>
#include "KATA.hpp"

using std::cout;
using std::endl;


namespace KATA_0527
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/120831
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
	namespace RotateStrings
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
	}
	namespace kata10
	{
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
}

namespace KATA_0529
{


	//https://school.programmers.co.kr/learn/courses/30/lessons/12937
	namespace kata9
	{
		string solution(int num)
		{
			string answer = (num & 1) == 1 ? "Odd" : "Even";
			return answer;
		}
	}

	namespace kata13_SumNumberSeats
	{
		int solution(int n)
		{
			int answer = 0;

			string str = std::to_string(n);

			for (int i = 0; i < str.size(); i++)
			{
				answer += str[i] - '0'; // 문자 -> 숫자 변환
			}

			return answer;
		}
	}

}

namespace KATA_0530
{
	namespace kata14
	{
		// 작업중.
		int solution(int n)
		{
			find_prime(n);
			return n;
		}
		vector<int> find_prime(int input_num)
		{
			if (input_num <= 2) {
				return { input_num };
			}
			for (int idx = 2; idx < input_num; ++idx) {
				if (input_num % idx == 0) {
					vector<int> ret_list;
					auto val_a = find_prime(idx);
					auto val_b = find_prime(input_num / idx);
					ret_list.reserve(val_a.size() + val_b.size());
					ret_list.insert(ret_list.end(), val_a.begin(), val_a.end());
					ret_list.insert(ret_list.end(), val_b.begin(), val_b.end());
					return ret_list;
				}
			}
			return { input_num };
		}
	}
}

namespace KATA_0602
{
	namespace kata1
	{
		int solution(int num1, int num2)
		{
			return num1 - num2;
		}
	}

	namespace kata2
	{
		int solution(int num1, int num2) 
		{
			return num1 * num2;
		}
	}

	namespace kata3
	{
		int solution(int num1, int num2)
		{
			return num1 / num2;
		}
	}

	namespace kata4
	{
		int solution(int age)
		{
			return 2022 - age + 1; // 만나이
		}
	}
}