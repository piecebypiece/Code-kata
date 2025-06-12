
#include <string>
#include <iostream>
#include <algorithm>
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

	namespace kata15
	{
		int solution(int n)
		{
			if (n % 2 == 1)
				return 2;

			int answer = n - 1;
			int sqrtN = sqrt(n);
			for (int i = 3; i <= sqrtN; i = i + 2)
			{
				if (n % i == 1)
				{
					answer = i;
					break;
				}
			}
			return answer;
		}
	}
}



//namespace KATA_0530
namespace KATA_0604
{
	namespace kata14
	{
		// 작업중.
		int solution(int n)
		{
			if (n == 0) return 0;
			int answer = n > 1 ? 1 + n : 1;
			int max = n / 2;
			for (int i = 2; i <= max; i++)
			{
				if (n % i == 0)
				{
					answer += i;
				}
			}

			return answer;
		}
	}

	namespace kata17
	{
		using namespace std;

		vector<int> solution(long long n) {
			vector<int> answer;
			string s = to_string(n);
			for (auto iter = --s.end(); iter != --s.begin(); iter--)
			{
				int val = *iter - '0';
				answer.push_back(val);
			}
			return answer;
		}
	}
	namespace kata16
	{
		vector<long long> solution(int x, int n) 
		{

			vector<long long> answer;

			if (n == 0) return answer;

			answer.push_back(x);
			long long first = x;
			for (int i = 1; i < n; i++)
			{
				answer.push_back(answer[i - 1] + first);
			}

			return answer;
		}
	}
}

namespace KATA_0605
{
	namespace kata18
	{
		using namespace std;

		int solution(string s)
		{
			return  stoi(s);
		}
	}
} // namespace KATA_0605


namespace KATA_0609
{
	namespace kata19
	{
		long long solution(long long n)
		{
			long long answer = 0;
			double val = sqrt(n);
			int intVal = val;
			if (val - intVal > 0.0)
				return -1;

			return pow(intVal + 1, 2);
		}
	}
}


namespace KATA_0610
{
	namespace kata21
	{
		using namespace std;

		bool solution(int x) 
		{
			string str = to_string(x);

			int sum = 0;

			for (char c : str)
			{
				sum += c - '0';
			}


			return x % sum == 0;
		}
	}

	namespace kata22
	{
		using namespace std;
		long long solution(int a, int b)
		{

			if (a > b)
			{
				auto temp = a;
				a = b;
				b = temp;
			}

			long long n = b - a + 1;
			return (a + b) * n / 2;
		}
	}
}

namespace KATA_0612
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12943
	namespace kata23
	{
		using namespace std;
		int solution(int num)
		{
			if (num == 1) return 0;

			long long collatz = num;
			int answer = -1;
			for (int i = 0; i < 500; i++)
			{
				bool odd = collatz & 1;
				if (odd)
					collatz = collatz * 3 + 1;
				else
					collatz >>= 1;

				if (collatz == 1)
				{
					answer = i + 1;
					break;
				}
			}

			return answer;
		}
	}
} // namespace KATA_0612