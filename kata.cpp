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

namespace KATA_0613
{
	namespace kata24
	{
		string solution(vector<string> seoul)
		{
			string answer = "";
			const string kim = "Kim";
			for (int i = 0; i < seoul.size(); ++i)
			{
				if (seoul[i] == kim)
				{
					answer = "김서방은 " + std::to_string(i) + "에 있다";
					break;
				}
			}
			return answer;
		}
	}
	namespace kata25
	{
		vector<int> solution(vector<int> arr, int divisor)
		{

			vector<int> answer;
			for (auto& element : arr)
			{
				if (element % divisor == 0)
				{
					answer.push_back(element);
				}
			}

			if (answer.size() == 0)
				answer.push_back(-1);
			else
				sort(answer.begin(), answer.end());
			return answer;
		}
	}

	namespace kata26
	{
		int solution(vector<int> absolutes, vector<bool> signs) 
		{
			int answer = 0;

			for (int i = 0; i < signs.size(); i++)
			{
				answer += (signs[i] ? 1 : -1) * absolutes[i];
			}
			return answer;
		}
	}

	namespace kata27
	{
	
		string solution(string phone_number)
		{
			string answer = phone_number;

			if (answer.size() > 4)
			{
				answer.replace(answer.begin(), answer.end() - 4, answer.size() - 4, '*');
			}

			return answer;
		}
	}
	int kata28::solution(vector<int> numbers)
	{
		int answer = -1;
		const int sumOneToNine = 45;
		answer = sumOneToNine;
		for (auto& num : numbers)
			answer -= num;
		return answer;
	}
} // namespace KATA_0613

namespace KATA_0616
{
	vector<int> kata29::solution(vector<int> arr)
	{
		vector<int> answer;
		int min = std::numeric_limits<int>::max();

		int index = 0;
		for (auto iter = arr.begin(); iter != arr.end(); iter++)
		{
			if (min > *iter)
			{
				min = *iter;
				index = iter - arr.begin();
			}
		}

		if (arr.size() == 1)
		{
			answer.push_back(-1);
			return answer;
		}

		arr.erase(arr.begin() + index);

		return arr;
	}
}

namespace KATA_0617
{
	namespace kata30
	{
		string solution(string s) 
		{
			string answer = "";
			bool isOdd = s.length() & 1;
			int index = s.length() >> 1;
			if (!isOdd)
				index--; // index 

			answer += s[index];
			if (isOdd == false)
				answer += s[index + 1];
			return answer;
		}
	}
	namespace kata31
	{
		string solution(int n)
		{
			string answer = "";
			bool turnSu = true;
			for (int i = 0; i < n; i++)
			{
				if (turnSu)
					answer += "수";
				else
					answer += u8"박";

				turnSu = !turnSu;
			}
			return answer;
		}
	}
	namespace kata32
	{
		int solution(vector<int> a, vector<int> b)
		{
			int answer = 0;
			for (int i = 0; i < a.size(); i++)
			{
				answer += a[i] * b[i];
			}
			return answer;
		}
	}
	namespace kata33
	{
		int solution(int left, int right) 
		{
			int answer = 0;
			int start = 0;
			int end = 0;
			int i = 0;
			int sum = 0;
			int square = 0;

			// 약수의 개수가 짝수 : 제곱수가 아닌 수, 약수의 개수가 홀수 : 제곱수 

			while (i * i < left) 
			{
				i++;
			}
			start = i;

			while (i * i <= right) 
			{
				i++;
			}
			if (i * i > right)
				end = i - 1;

			sum = (left + right) * (right - left + 1) / 2;

			for (i = start; i <= end; i++)
			{
				square += i * i;
			}

			answer = sum - square * 2;

			return answer;
		}
	}
} // namespace KATA_0617

namespace KATA_0618
{
	namespace kata34
	{
		string solution(string s)
		{
			sort(s.begin(), s.end(), std::greater<char>());
			return s;
		}
	}
	namespace kata35
	{
		//https://school.programmers.co.kr/learn/courses/30/lessons/82612#
		long long solution(int price, int money, int count)
		{
			long long answer = -1;
			// 시작값 + n * n / 2 = 최종가격
			int n = (price * count + price);
			long long totalPrice = (long long)n * count / 2l;
			answer = money - totalPrice;
			return answer > 0 ? 0 : -answer;
		}
	}
}

namespace KATA_0619
{
	namespace kata36
	{
		bool solution(string s) 
		{
			bool answer = true;
			int size = s.size();
			if (size != 4 && size != 6)
				return false;

			for (auto& c : s)
			{
				if (c < '0' || c > '9')
					return false;
			}

			return true;
		}
	}
	namespace kata37
	{
		vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
		{
			int m = arr1[0].size();
			vector<vector<int>> answer;
			for (int i = 0; i < arr1.size(); i++)
			{
				vector<int> col;
				col.reserve(m);
				answer.push_back(col);
				vector<int>& ref = answer[i];
				for (int j = 0; j < m; j++)
				{
					ref.push_back(arr1[i][j] + arr2[i][j]);
				}
			}

			return answer;
		}
	}

	namespace kata38
	{
		using namespace std;
		int solution(void)
		{
			int a;
			int b;
			cin >> a >> b;
			for (int i = 0; i < b; i++)
			{
				for (int j = 0; j < a; j++)
					cout << "*";
				cout << endl;
			}
			return 0;
		}
	}
	

} // namespace KATA_0619

namespace KATA_0623
{
	namespace kata39
	{
		vector<int> solution(int n, int m)
		{
			int originalA = n, originalB = m;

			// GCD 계산 (유클리드 호제법)
			while (m != 0) {
				int temp = n % m;
				n = m;
				m = temp;
			}
			int gcd = n;

			// LCM 계산 (오버플로우 방지)
			int lcm = (originalA / gcd) * originalB;

			return { gcd, lcm };
		}
	}

	namespace kata40
	{
		int solution(int n)
		{
			int quot = n;
			int rem = 0;
			vector<int> remList;
			remList.resize(n / 10);
			
			while(true)
			{
				auto [quotTemp, remTemp] = std::div(quot, 3);
				quot = quotTemp;
				rem = remTemp;
				remList.push_back(rem);

				if (quot == 0)
					return;
			}

			std::reverse(remList.begin(), remList.end());
			
			int answer = 0;
			int value = 1; // 자릿 수마다 곱해줄 값
			for (int thirdOne : remList)
			{
				answer = value * thirdOne;
				value *= 3;
			}

			return answer;
		}
	}
}

namespace KATA_0624
{
	namespace kata41
	{
		string solution(string s)

		{
			string answer = "";
			int num = 0;
			for (int i = 0; i < s.size(); i++, num++)
			{
				if (s[i] == ' ')
				{
					num = -1;
					continue;
				}

				bool isUpperCase = num == 0 or !((num & 1) == 1);

				s[i] = isUpperCase ? toupper(s[i]) : tolower(s[i]);
			}


			return s;
		}
	}
	namespace kata42
	{
		int solution(vector<int> number)
		{
			int answer = 0;

			int first;
			for(int i=0; i<number.size(); i++)
			{
				first = number[i];
				for (int j= i+1; j<number.size(); j++)
				{
					int sum = first + number[j];
					for(int k= j+1; k<number.size(); k++)
					{
						if (sum + number[k] == 0)
							answer++;
					}
				}
			}

			return answer;
		}
	}
}