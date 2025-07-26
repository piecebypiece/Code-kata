#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "KATA.hpp"

using std::cout;
using std::endl;
using std::unordered_map;


#pragma region KATA_0527
// KATA_0527
namespace kata09
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
#pragma endregion KATA_0527

#pragma region KATA_0528
// KATA_0528
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
			cout << "\" " << endl;
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
#pragma endregion KATA_0528

#pragma region KATA_0529
// KATA_0529


//https://school.programmers.co.kr/learn/courses/30/lessons/12937
namespace kata11
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

#pragma endregion KATA_0529

#pragma region KATA_0602
// KATA_0602
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
#pragma endregion KATA_0602



//namespace KATA_0530
#pragma region KATA_0604
// KATA_0604
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
#pragma endregion KATA_0604

#pragma region KATA_0605
// KATA_0605
namespace kata18
{
	using namespace std;

	int solution(string s)
	{
		return  stoi(s);
	}
}
#pragma endregion KATA_0605


#pragma region KATA_0609
// KATA_0609
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
#pragma endregion KATA_0609


#pragma region KATA_0610
// KATA_0610
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
#pragma endregion KATA_0610

#pragma region KATA_0612
// KATA_0612
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
#pragma endregion KATA_0612

#pragma region KATA_0613
// KATA_0613
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
#pragma endregion KATA_0613

#pragma region KATA_0616
// KATA_0616
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
#pragma endregion KATA_0616

#pragma region KATA_0617
// KATA_0617
namespace kata30
{
	string solution(string s)
	{
		string answer = "";
		bool isOdd = s.length() & 1;
		int index = (int)(s.length() >> 1);
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
				answer += u8"수";
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
#pragma endregion KATA_0617

#pragma region KATA_0618
// KATA_0618
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
#pragma endregion KATA_0618

#pragma region KATA_0619
// KATA_0619
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


#pragma endregion KATA_0619

#pragma region KATA_0623
// KATA_0623
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

		while (true)
		{
			auto [quotTemp, remTemp] = std::div(quot, 3);
			quot = quotTemp;
			rem = remTemp;
			remList.push_back(rem);

			if (quot == 0)
				break;
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
#pragma endregion KATA_0623

#pragma region KATA_0624
// KATA_0624
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
		for (int i = 0; i < number.size(); i++)
		{
			first = number[i];
			for (int j = i + 1; j < number.size(); j++)
			{
				int sum = first + number[j];
				for (int k = j + 1; k < number.size(); k++)
				{
					if (sum + number[k] == 0)
						answer++;
				}
			}
		}

		return answer;
	}
}
#pragma endregion KATA_0624


#pragma region KATA_0626
// KATA_0626
namespace kata43
{
	int solution(string t, string p)
	{
		string* target;
		if (t.size() < p.size())
		{
			target = &t;
		}
		else
		{
			target = &p;
		}

		string& shortStr = *target;
		string& big = target == &p ? t : p;

		int answer = 0;
		long long shortNum = stoll(shortStr);
		int loopCnt = (big.size() - shortStr.size() + 1);

		for (int i = 0; i < loopCnt; i++)
		{
			string s = big.substr(i, shortStr.size());
			if (stoll(s) <= shortNum)
				answer++;
		}

		return answer;
	}
}
#pragma endregion KATA_0626

#pragma region KATA_0701
// KATA_0701
namespace kata44
{
	int solution(vector<vector<int>> sizes)
	{
		int answer = 0;
		// 명함을 회전시켜 넣는 것도 고려할 수 있다.
		// 즉 둘 중 큰 길이를 만족시키기만 하면 된다.
		// 둘 중 큰 수는 큰 수 로 비교 작은 수는 작은 수로 비교
		int maxofMax = 0;
		int minofMin = 0;
		for (vector<int>& size : sizes)
		{
			int w = size[0];
			int h = size[1];

			// 회전을 고려하여 항상 w가 더 길게 정렬
			if (w < h) std::swap(w, h);

			// 가장 큰 긴 변과 가장 큰 짧은 변을 찾는다
			maxofMax = std::max(maxofMax, w);
			minofMin = std::max(minofMin, h);
		}
		return maxofMax * minofMin;
	}
}
#pragma endregion KATA_0701

#pragma region KATA_0702
// KATA_0702
namespace kata45
{
	string solution(string s, int n)
	{
		for (auto iter = s.begin(); iter != s.end(); iter++)
		{
			char c = *iter;
			if (c == ' ')
				continue;

			int nChar = c + n;
			char starter = 'a';
			int overCount = 0;
			if (c <= 'Z' and nChar > 'Z')
			{
				overCount = nChar - 'Z';
				starter = 'A';
			}
			else if (nChar > 'z')
			{
				overCount = nChar - 'z';
				starter = 'a';
			}
			if (overCount > 0)
				nChar = starter + overCount - 1;
			*iter = nChar;
		}

		return s;
	}
}
#pragma endregion KATA_0702

#pragma region KATA_0704
// KATA_0704
namespace kata46
{
	int solution(string input)
	{
		unordered_map<string, char> wordToDigit =
		{
			{"zero", '0'}, {"one", '1'}, {"two", '2'},   {"three", '3'},
			{"four", '4'}, {"five", '5'}, {"six", '6'},  {"seven", '7'},
			{"eight", '8'}, {"nine", '9'}
		};

		string result;
		string buffer;

		for (char ch : input)
		{
			if (isdigit(ch))
			{
				result += ch;
			}
			else
			{
				buffer += ch;
				// 최대 길이 5인 단어들에 대해 검사
				if (buffer.length() >= 3 && buffer.length() <= 5)
				{
					if (wordToDigit.count(buffer))
					{
						result += wordToDigit[buffer];
						buffer.clear();
					}
				}
			}
		}

		return stoi(result);
	}
}
namespace kata47
{
	vector<string> solution(vector<string> strings, int n)
	{
		vector<string> answer;
		sort(strings.begin(), strings.end(), [&n](auto& a, auto& b)
		{
			if (a[n] == b[n])
			{
				return a < b;
			}
			return a[n] < b[n];
		});
		return strings;
	}
}
#pragma endregion KATA_0704

#pragma region KATA_0705
// KATA_0705
namespace kata48
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/42748
	vector<int> solution(vector<int> array, vector<vector<int>> commands)
	{
		vector<int> answer;

		vector<int> copyArray;
		for (auto iter = commands.begin(); iter != commands.end(); iter++)
		{
			copyArray.clear();

			for (int i = (*iter)[0] - 1; i < (*iter)[1]; i++)
				copyArray.push_back(array[i]);

			sort(copyArray.begin(), copyArray.end());

			answer.push_back(copyArray[(*iter)[2] - 1]);
		}


		return answer;
	}
}
#pragma endregion KATA_0705

#pragma region KATA_0706
// KATA_0706
#include <algorithm>
using std::sort;
namespace kata49
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/68644
	vector<int> solution(vector<int> numbers)
	{
		vector<int> answer;

		// 모든 조합을 찾아야한다.
		// 현재 인덱스보다 큰 인덱스와 조합하면 되며.
		for (int i = 0; i < numbers.size() - 1; i++)
		{
			for (int j = i + 1; j < numbers.size(); j++)
			{
				answer.push_back(numbers[i] + numbers[j]);
			}
		}
		// 중복된 내용을 제거 해준다.
		sort(answer.begin(), answer.end());
		auto lastIndex = unique(answer.begin(), answer.end());
		answer.erase(lastIndex, answer.end());


		return answer;
	}
}
#pragma endregion KATA_0706

#pragma region KATA_0707
// KATA_0707
namespace kata50
{
	using namespace std;

	vector<int> solution(string s)
	{
		vector<int> answer(s.size());

		unordered_map<char, int> charIndexMap;
		fill(answer.begin(), answer.end(), -1);

		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			auto pairOptional = charIndexMap.try_emplace(c, i);
			if (pairOptional.second == false)
			{
				int lastIndex = charIndexMap[c];
				answer[i] = i - lastIndex;
				charIndexMap[c] = i;
			}
		}

		return answer;
	}
}

namespace kata51
{
	string solution(vector<int> food)
	{
		vector<int> evenCounts(food.size() - 1);
		int sum = 0;
		for (int i = 1; i < food.size(); i++)
		{
			int foodCount = food[i] & ~1;
			sum += evenCounts[i - 1] = foodCount;
		}

		string answer(sum + 1, ' ');

		fill(answer.begin(), answer.end(), '0');

		int index = 0;
		for (int i = 0; i < evenCounts.size(); i++)
		{
			int count = evenCounts[i] >> 1;

			for (int j = 0; j < count; j++)
			{
				answer[answer.size() - index - 1] = answer[index] = ('1' + i);
				index++;
			}
		}
		answer[index] = '0';

		return answer;

	}
}

namespace kata52
{
	using namespace std;

	int solution(int a, int b, int n) 
	{
		// a 교환개수 
		// b 콜라교환수 
		// 소지 빈병의 개수

		// 교환 가능 개수는 
		// 그 다음 교환 가능 개수
		// n / a * b = r, n % a = c
		// (c + r) / a * b

		int remein = n;
		int answer = 0;
		while (remein >= a)
		{
			auto result = div(remein, a);
			int quotient = result.quot;
			int remainder = result.rem;
			int cokeNum = quotient * b;
			answer += cokeNum;
			remein = cokeNum + remainder;
		}


		return answer;
	}
}
#pragma endregion KATA_0707

#pragma region KATA_0708

namespace kata53
{
	using namespace std;

	vector<int> solution(int k, vector<int> score) 
	{
		vector<int> answer;
		answer.reserve(score.size());
		multiset<int, greater<int>> sortScore;

		int iK = k -1;
		for (int i = 0; i < score.size(); i++)
		{ // https://school.programmers.co.kr/learn/courses/30/lessons/138477
			sortScore.insert(score[i]);

			if (sortScore.size() < k)
				answer.push_back(*(--sortScore.end()));
			else
				answer.push_back(*(next(sortScore.begin(), iK)));
		}

		return answer;
	}
}

#include <numeric>
namespace kata54
{
	using namespace std;

	string solution(int a, int b) 
	{
		// 16년에 맞춘 날짜 수와 요일
		vector<int> monthDays = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

		// 이번년도의 1월 1일부터 했을 때 몇일인가.

		int totalDay = accumulate(monthDays.begin(), monthDays.begin() + a - 1, 0) + b - 1;

		string answer = days[totalDay % 7];
		return answer;
	}
}


#pragma endregion KATA_0708

#pragma region KATA_0709

namespace kata52
{ //https://school.programmers.co.kr/learn/courses/30/lessons/132267
	int solution(int a, int b, int n);
}

#pragma endregion KATA_0709



#pragma region KATA_0715

namespace kata55
{ //https://school.programmers.co.kr/learn/courses/30/lessons/159994
	bool searchRoute(vector<string>& cards1, vector<string>& cards2,
		vector<string>& goal, int i, int j, int targetIndex);
	string solution(vector<string> cards1, vector<string> cards2, vector<string> goal);

	bool searchRoute(vector<string>& cards1, vector<string>& cards2,
		vector<string>& goal, int i, int j, int targetIndex)
	{
		if (targetIndex >= goal.size())
			return true;

		const string& goalCard = goal[targetIndex];

		if (cards1.size() > i and cards1[i] == goalCard)
		{
			// 다음에 탐색할 정보를 만듬
			++i, ++targetIndex;

			if (searchRoute(cards1, cards2, goal, i, j, targetIndex))
				return true;
		}
		if ( cards2.size() > j and cards2[j] == goalCard)
		{
			// 너머에 길이 있나?
			++j, ++targetIndex;
			if (searchRoute(cards1, cards2, goal, i, j, targetIndex))
				return true;
		}

		// 양쪽에 길이 없다.
		return false;
	}
	string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
	{
		bool answer = true;

		//완전 탐색으로 해결할 수 있는가?

		answer = searchRoute(cards1, cards2, goal, 0, 0, 0);

		return answer ? "Yes" : "No";
	}
}
#pragma endregion KATA_0715

#pragma region KATA_0717
namespace kata56
{
	using namespace std;
	int solution(int k, int m, vector<int> score) 
	{
		sort(score.begin(), score.end());

		// 작은건 모두 앞에 있다.
		// 남는 사과는 버린다.

		// m 으로 딱 나누어 떨어지는 경우.
		// n 개씩 버릴 수 있는 경우가 있다.

		// 높은 점수부터 골라서 넣어보자
		int answer = 0;
		int boxCount = 0;
		int boxMin = 10; // 24 // 6, 3
		for (int i = 0; i < score.size(); i++)
		{
			if ( score.size() - i < m - boxCount)
				break;

			int reverseI = score.size() - 1 - i;


			boxCount++;
			int apple = score[reverseI];

			if ( apple < boxMin)
				boxMin = apple;

			if (boxCount == m)
			{
				//cout << "boxMin " << i + 1 << ": " << boxMin << endl;
				answer += m * boxMin;

				boxCount = 0;
				boxMin = 10;
			}
		}


		return answer;
	}
}
namespace katta57
{
	vector<int> solution(vector<int> answers) 
	{
		vector<vector<int>> supojas
		{
			{ 1, 2, 3, 4, 5 },
			{ 2, 1, 2, 3, 2, 4, 2, 5 },
			{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 },
		};
		vector<int> counts
		{
			0,0,0
		};

		for (int i = 0 ; i < answers.size(); i++)
		{
			for (int j = 0 ; j < supojas.size(); j++)
			{
				int index = i % supojas[j].size();
				int supojaAns = supojas[j][index];
				if (supojaAns == answers[i])
				{
					counts[j]++;
				}
			}
		}

		int max = *max_element(counts.begin(), counts.end());

		vector<int> answer;
		for (int i = 0 ; i < counts.size(); i++)
			if (max == counts[i])
				answer.push_back(i);

		return answer;
	}
}
#pragma endregion KATA_0717


#pragma region KATA_0718

namespace kata58
{ //https://school.programmers.co.kr/learn/courses/30/lessons/12977
	int solution(vector<int> nums) 
	{
		int answer = 0;
		//소수인 프라임 넘버를 계산해내는 것은 불가능함.
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				for (int k = j + 1; k < size; k++)
				{
					int n = nums[i] + nums[j] + nums[k];
					bool bPrime = true;
					for (int x = 2; x*x <= n; ++x) 
					{
						if (n % x == 0) 
						{
							bPrime = false;
							break;
						}
					}
					if (bPrime)
					{
						++answer;
					}
				}
			}
		}



		return answer;
	}
}

#pragma endregion KATA_0718

#pragma region KATA_0720

namespace kata59
{	// https://school.programmers.co.kr/learn/courses/30/lessons/161989
	int solution(int n, int m, vector<int> section)
	{
		// 섹션의 개수가 몇개인지 세는 것.
		// 하지만 섹션은 m 이내라면 하나로 칠 수 있다.
		int answer = 1;
		int index = 1;
		int lastSection = section[0];
		while (index < section.size())
		{
			while (index < section.size())
			{
				int curSection = section[index];
				if (curSection - lastSection <= m - 1)
				{
					index++;
					continue;
				}
				break;
			}
			if (index < section.size())
			{
				lastSection = section[index++];
				answer++;
			}
		}
		return answer;
	}
}


#pragma endregion

#pragma region KATA_0721

namespace kata60
{
	int countDivisors(int n)
	{
		int count = 0;
		for (int i = 1; i * i <= n; ++i) 
		{
			if (n % i == 0) 
			{
				// i와 n/i가 같은 경우는 한 번만 증가
				count += (i * i == n) ? 1 : 2; 
			}
		}
		return count;
	}
	int solution(int number, int limit, int power)
	{
		vector<int> memory;
		memory.reserve(number);

		for (int i =0; i < number; i++)
		{
			memory.push_back(countDivisors(i+1));
		}

		int answer = 0;

		for (int dividerNum : memory)
		{
			answer += dividerNum > limit ? power : dividerNum;
		}

		return answer;
	}
}

namespace kata61
{ //https://school.programmers.co.kr/learn/courses/30/lessons/77484
	using namespace std;
	vector<int> solution(vector<int> lottos, vector<int> win_nums)
	{
		vector<int> answer;

		// lottos 와 win_nums 가 일치하는 개수
		// 그중 0의 개수 + - 한 등수가 최고, 최저 등수가 되는거 아닌가?
		int numZero = 0;
		int correctNum = 0;
		for (int lotto : lottos)
		{
			if (lotto == 0)
			{
				++numZero;
				continue;
			}
			// 중복 숫자가 있을 수 있기 때문에 일치한 숫자는 제거
			for (int i = 0; i < win_nums.size(); ++i)
			{   
				if (win_nums[i] == lotto)
				{
					win_nums[i] = -1;
					win_nums.erase(win_nums.begin() + i);
					++correctNum;
					break;  // 여러 숫자가 일치하는지는 볼 이유가 없다.
				}
			}
		}
		answer.push_back(min(7 - (correctNum + numZero), 6) );
		answer.push_back(min(7 - correctNum, 6) );
		return answer;
	}
}
#pragma endregion KATA_0721

#pragma region KATA_0724


namespace kata62
{	//https://school.programmers.co.kr/learn/courses/30/lessons/133499
	using namespace std;
	int solution(vector<string> babbling) 
	{
		vector<string> canBabling{ "aya", "ye", "woo", "ma" };

			// 각 단어 가 canBaling 중 하나거나 그 조합으로 만들어져야 한다.
			// 같은 단어가 연속해서 조합되는 경우는 없다

		int answer = 0;

		for (string s : babbling)
		{
			int index = 0;
			int lastIndex = -1;
			while (true)
			{
				bool findSomthing = false;
				for (int i = 0; i < canBabling.size(); ++i)
				{
					if (lastIndex == i) continue;

					string o = canBabling[i];
					if (s.compare(index, o.size(), o) == 0)
					{
						index += o.size();
						lastIndex = i;
						findSomthing = true;
						break;
					}
				}

				if (findSomthing == false or index >= s.size())
					break;
			}
			if (index >= s.size())
			{
				++answer;
			}
		}


		return answer;
	}
}

namespace kata63
{
	using namespace std;
	string solution(string X, string Y) 
	{
		string& shortS = X.size() < Y.size() ? X : Y;
		vector<int> numbers(10, 0), numbers2(10, 0);

		for (char xc : X)
			++numbers[xc - '0'];
		for (char yc : Y)
			++numbers2[yc - '0'];


		vector<char> pair;
		pair.reserve(shortS.size());
		// 정렬 수고를 덜기 위해서 큰 수 부터
		for (int i = 9; i > -1; i--)
		{
			int pairCount = min(numbers[i], numbers2[i]);
			if (pairCount  > 0)
			{
				if (i == 0 and pair.size() == 0)
				{
					pairCount = 1;
				}
				for (int j = 0; j < pairCount; ++j)
					pair.push_back('0' + i);
			}
		}

		return pair.size() > 0 ? string (pair.begin(), pair.end()) : "-1";
	}
}

#pragma endregion KATA_0721

#pragma region KATA_0726
namespace kata64
{
	using namespace std;
	int solution(int n, vector<int> lost, vector<int> reserve)
	{
		// lost index +-1 까지 reserve 에 있어야 한다.
		// 최대한으로 빌려줄 것
		// reserve 에 있는 모든 요소를 최대한 소모 해야하기 때문에 소모 못하는 상황이 없어야한다.
		// reserve N이 lost 에 쳐할 수 있는 상황은 
		// 값 차이가 2
		// 값 차이 없음
		// 값 차이 1

		// reserve 가 하나 밖에 줄 수 없다면 주는 것이 이득이다.
		// 이후에 어떤 상황이 되던 하나에만 해당하는 reserve는 그곳이 아니면 소모 될 수 없기 때문.
		// 따라서 하나인 애들은 무조건 빌려줘야한다.
		int answer = 0;
		vector<int> lostSheet(n, 0);
		//vector<int> reserveSheet(n, 0);

		sort (lost.begin(), lost.end());
		sort (reserve.begin(), reserve.end());

		for (int i : lost)
			lostSheet[i - 1] = 1;


		for (int i = 0; i < reserve.size(); ++i)
		{
			int target = reserve[i] - 1;
			if (lostSheet[target] != 0)
			{
				reserve[i] = lostSheet[target] = 0;
				++answer;
			}
		}


		for (int i = 0; i < reserve.size(); ++i)
		{
			if (reserve[i] == 0)
				continue;
			int target = reserve[i] - 1;
			bool findReserve = false;
			
			if (target - 1 >= 0 and lostSheet[target - 1] != 0)
			{
				--target;
				findReserve = true;
			}
			else if(target + 1 < lostSheet.size() and lostSheet[target + 1] != 0)	
			{
				++target;
				findReserve = true;
			}

			if (findReserve)
			{
				//reserveSheet[i] = 0;
				lostSheet[target] = 0;
				++answer;
			}
		}
		return n - lost.size() + answer;
	}
}
#pragma endregion KATA_0726


//#pragma region KATA_
//#pragma endregion KATA_

////https://github.com/piecebypiece/Code-kata