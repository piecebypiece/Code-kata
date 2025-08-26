#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;


#pragma region KATA_0809

namespace kata69
{	//https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp
	string solution(vector<string> survey, vector<int> choices)
	{
		// 점수가 같으면 사전 순.
		vector<int> score(4, 0);
		vector<pair<char, char>> categoryOrder{
			{'R', 'T'},
			{'C', 'F'},
			{'J', 'M'},
			{'A', 'N'},
		};


		unordered_map<char, int> surveyMap = {
			{ 'R', 0 },
			{ 'T', 0 },
			{ 'C', 1 },
			{ 'F', 1 },
			{ 'J', 2 },
			{ 'M', 2 },
			{ 'A', 3 },
			{ 'N', 3 },
		};

		// 4 는 + 없음
		for (int i = 0; i < choices.size(); i++)
		{
			string category = survey[i];
			int choice = choices[i];

			if (choice == 4)
				continue;

			char target = '\0';
			int choiceVal = 0;
			// 좌측, 우측
			if (4 > choice)	// 1, 2, 3 == 1이면 3점
			{
				target = category[0];
			}
			else if (4 < choice)	//우측값
			{
				target = category[1];
			}
			
			auto iter = surveyMap.find(target);
			if (iter != surveyMap.end())
			{
				int index = iter->second;
				choiceVal = abs(choice - 4);	// 좌측값인 경우 음수
				if (categoryOrder[index].first == target)
					choiceVal *= -1;
				score[iter->second] += choiceVal;
			}
		}

		string answer = "";

		for (int i = 0 ; i < score.size(); i++)
		{
			int val = score[i];
			pair<char, char> currentCategory = categoryOrder[i];
			char c = '\0';
			if (val == 0)
			{
				c = min(currentCategory.first, currentCategory.second);
			}
			else if (val > 0)
				c = currentCategory.second;
			else
				c = currentCategory.first;

			answer.push_back(c);
		}
		
		return answer;
	}
}

namespace kata70
{ //https://school.programmers.co.kr/learn/courses/30/lessons/161990
	vector<int> solution(vector<string> wallpaper) 
	{
		const char blank = '.';
		const char exist = '#';
		enum Dir : uint8_t
		{
			top = 0, left, bottom, right
		};

		vector<int> answer(4);
		// 초기화
		std::fill(answer.begin(), answer.end(), 0);
		answer[left] = wallpaper[0].size();
		answer[top] = wallpaper.size();

		// min left min top
		// max right max bottom 을 찾아서 반환한다.
		for (int i = 0; i < wallpaper.size(); i++)
		{
			for (int j = 0; j < wallpaper[i].size(); j++)
			{
				char file = wallpaper[i][j];
				switch (file)
				{
				case blank:
					continue;
				case exist:
					if (j < answer[left])
						answer[left] = j;
					if (j + 1> answer[right])
						answer[right] = j + 1;
					if (i < answer[top])
						answer[top] = i;
					if (i + 1> answer[bottom])
						answer[bottom] = i + 1;

					break;
				}
			}
		}

		return answer;
	}

}

namespace kata71
{
	vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
	{
		// 개인정보, 개인정보와 연결된 유효기간
		// 유효기간 지나면 파기
		// 개월수로 정리
		// 지난 개월수의 같은 날짜가 되면 파기
		// 모든 달이 28일까지 있다고 가정.
		// terms = 약관 종류 유효기간
		// 날짜 약관 종류
		
		vector<int> answer;

		int year = stoi(today.substr(0, 4));
		int month = stoi(today.substr(5, 2));
		int day = stoi(today.substr(8, 2));

		for (int i = 0; i < privacies.size(); i++)
		{
			string target = privacies[i];
			size_t pos = target.find(' ', 0);
			string date = target.substr(0,  pos);
			string term = target.substr(pos + 1, target.size() - pos);
			
			int priYear = stoi(date.substr(0, 4));
			int priMonth = stoi(date.substr(5, 2));
			int priDay = stoi(date.substr(8, 2));

			auto termIter = find_if(terms.begin(), terms.end(), [&](string s)
			{
				return term[0] == s[0];
			});


			string termStr = *termIter;
			string termMonthStr = termStr.substr(2, termStr.size() - 2);
			int termMonth = stoi(termMonthStr);

			if (priDay == 1)
			{
				priDay = 28;
				--priMonth;
				if (priMonth < 1)
				{
					priMonth = 12;
					--priYear;
				}
			}
			auto divResult = div(termMonth, 12);
			priYear += divResult.quot;
			priMonth +=  divResult.rem;
			if (priMonth > 12)
			{
				priMonth -= 12;;
				++priYear;
			}

			bool isLater = (year > priYear) ||
				(year == priYear && month > priMonth) ||
				(year == priYear && month == priMonth && day >= priDay);

			if (isLater) 
			{
				answer.push_back(i + 1);
			}

		}

		return answer;
	}
}

namespace kata72
{
	vector<string> solution(vector<string> players, vector<string> callings) 
	{
		unordered_map<string, int> playerMap(players.size());
		for (int i = 0; i < players.size(); ++i)
		{
			playerMap.emplace(players[i], i);
		}

		for (string call : callings)
		{
			auto iter = players.begin() + playerMap[call];
			auto prev = iter - 1;
			swap(*iter, *prev);
			playerMap[*iter] = iter - players.begin();
			playerMap[*prev] = prev - players.begin();

		}
		return players;
	}
}
#pragma endregion KATA_0809

#pragma region KATA_0811

namespace kata73
{
	vector<int> solution(vector<string> park, vector<string> routes) 
	{
		vector<int> answer;

		int r, c;
		auto iter = find_if(park.begin(), park.end(), [&](string s) 
		{
			c = s.find('S');
			return c > -1;
		});
		
		r = iter - park.begin();

		for (int i = 0; i <  routes.size(); i++)
		{
			// 각 루트 실행 형태는 '방위' 숫자 모든 방위는 1바이트
			string route = routes[i];
			char dir = route[0];
			int count = stoi(route.substr(2, route.size() - 2));
			int xdir = 0, ydir = 0;

			if (dir == 'E')
			{
				if (c + count >= park[r].size())
					continue;
				xdir = 1;
			}
			else if (dir == 'W')
			{
				if (c - count < 0)
					continue;
				xdir = -1;
			}
			else if (dir == 'N')
			{
				if (r - count < 0)
					continue;
				ydir = -1;
			}
			else if (dir == 'S')
			{
				if (r + count >= park.size())
					continue;
				ydir = 1;
			}

			int x = c, y = r;
			bool exsitX = false;

			for (int j = 0; j < count; j++)
			{
				x += xdir;
				y += ydir;
				exsitX = routes[y][x] == 'X';
				if (exsitX)
					break;
			}
			if (exsitX)
				continue;

			c = x;
			r = y;
		}
		return { r, c };
	}
}

#pragma endregion KATA_0811

#pragma region KATA_0818

namespace kata74
{
	vector<int> solution(vector<string> id_list, vector<string> report, int k) 
	{

		int idCount = id_list.size();
		unordered_map<string, set<string>> reportTable(idCount);
		unordered_map<string, int> id_Index(idCount);

		for (int i = 0; i < id_list.size(); i++)
		{
			string& s = id_list[i];
			reportTable.emplace(s, set<string>());
			id_Index.emplace(s, i);
		}

		for (string reportMsg : report)
		{
			auto termIter = find(reportMsg.begin(), reportMsg.end(), ' ');

			if (termIter != reportMsg.end())
			{
				// 신고자
				string first(reportMsg.begin(), termIter);

				// 신고대상
				string second(termIter + 1, reportMsg.end());

				reportTable[second].emplace(first);
			}
		}

		vector<int> answer(id_list.size(), 0);

		for (int i = 0; i < id_list.size(); i++)
		{
			auto iter = reportTable.find(id_list[i]);

			if (iter == reportTable.end())
				continue;

			auto reporterSet = iter->second;
			// 신고자가 2 이상임으로 밴 대상
			if (reporterSet.size() > k)
			{
				for (const string& reporter : reporterSet)
				{
					int index = id_Index[reporter];
					answer[index]++;
				}
			}

		}

		return answer;
	}
}

#pragma endregion KATA_0818

#pragma region KATA_0819

namespace kata75
{ // https://school.programmers.co.kr/learn/courses/30/lessons/12939
		// 0 같다, 1 a가 크다 -1 a가 작다
	int CompareStringInt(string_view a, string_view b)
	{
		bool aNagative = a[0] == '-';
		bool bNagative = b[0] == '-';

		if (aNagative != bNagative)
		{
			if (aNagative) return -1;
			else if (bNagative) return 1;
		}

		int biggerNoSign = 0;

		if (a.size() != b.size())
		{
			if (a.size() > b.size())
				biggerNoSign = 1;

			else if (a.size() < b.size())
				biggerNoSign = -1;

			return aNagative ? biggerNoSign * -1 : biggerNoSign;
		}

		// 부호도 길이도 같은 경우
		int startIndex = aNagative ? 1 : 0;

		for (int i = startIndex; i < a.size(); i++)
		{
			if (a[i] > b[i])
			{
				biggerNoSign = 1;
				break;
			}
			else if (a[i] < b[i])
			{
				biggerNoSign = -1;
				break;
			}
		}
		return aNagative ? biggerNoSign * -1 : biggerNoSign;
	}

	string solution(string s)
	{
		string_view max = "0";
		string_view min = "999999999";

		int start = 0;
		while (true)
		{
			int pos = s.find(' ', start);

			// 공백 또는 문자열 끝까지의 뷰
			std::string_view word(s.data() + start,
				(pos == string::npos ? s.size() : pos) - start);

			if (!word.empty())
			{
				if (1 == CompareStringInt(max, word))
					max = word;
				if (1 == CompareStringInt(min, word))
					min = word;
			}

			if (pos == std::string::npos) break; // 끝 도달
			start = pos + 1; // 다음 단어 시작
		}


		string answer;
		answer.reserve(max.size() + 1 + min.size()); // 메모리 한 번만 할당
		answer.append(min);
		answer.push_back(' ');
		answer.append(max);
		return answer;
	}
}

namespace kata76
{	//https://school.programmers.co.kr/learn/courses/30/lessons/12951
	string solution(string s) 
	{
		bool first = true;    
		for (char& c : s)
		{
			if (c == ' ')
			{
				first = true;
			}
			else if (first)
			{
				c = toupper(c);
				first = false;
			}
			else
				c = tolower(c);

		}
		return s;
	}
}

namespace kata77
{
	using namespace std;

	vector<int> solution(string s) 
	{	//https://school.programmers.co.kr/learn/courses/30/lessons/70129#
		vector<int> answer{0, 0};
		int& number = answer[0];
		int& zcount = answer[1];

		//1 개수는 제거후 남은 개수

		unsigned int cnt1 = count(s.begin(), s.end(), '1');
		zcount = s.size() - (int)cnt1;
		++number;

		if (cnt1 < 2)
			return answer;

		unsigned int t1Cnt = 0;
		while (true)
		{
			t1Cnt = 0;
			// 개수의 1개수
			int pos = 0;
			while (cnt1) 
			{
				if (cnt1 & 1u)
					++t1Cnt;
				cnt1 >>= 1;
				pos++;
			}
			zcount += pos - t1Cnt;

			++number;
			if (t1Cnt == 1) 
				break;

			cnt1 = t1Cnt;
		}


		return answer;
	}
}

namespace kata78
{
	using namespace std;

	long long Fibonachi(int n)
	{
		// 메모리에 결과를 기록하여 결과 단축
		static vector<long long> memo(100001, -1);

		if (n == 1) return 1;
		else if (n == 0) return 0;
		if (memo[n] != -1) return memo[n];

		return memo[n] = (Fibonachi(n - 1) + Fibonachi(n - 2)) % 1234567L;
	}

	int solution(int n) 
	{
		int answer = Fibonachi(n) % 1234567L;
		return answer;
	}
}

namespace kata79
{
	vector<int> solution(int brown, int yellow) 
	{	//https://school.programmers.co.kr/learn/courses/30/lessons/42842
		// 가로 길이가 세로와 같거나 길다.
		// 노란 색이 인접한 다른 노란 색 면 한 면 당 brown 3 이 줄어든다.

		int sqrtY = sqrt(yellow);
		int brownHalf = brown / 2;
		vector<int> answer;

		for (int i = 1; i <= sqrtY; i++)
		{
			div_t res = div(yellow, i);  // yellow / i → 몫(res.quot), 나머지(res.rem)
			if (res.rem != 0) 
				continue;  // 나머지가 0이 아니면 약수가 아님

			int col = res.quot; // 몫

			if (brownHalf == i + col + 2)
			{
				answer = { col + 2,  i + 2 }; // 노란 박스의 가로 세로 길이가 된다.

				break;
			}
		}


		return answer;
	}
}

namespace kata80
{
	int solution(int n, int a, int b)
	{ //https://school.programmers.co.kr/learn/courses/30/lessons/12985
		int answer = 1;

		while (true)
		{
			if (a & 1)
				++a;
			if (b & 1)
				++b;

			if (a == b)
			{
				break;
			}

			a >>= 1;    // 나누기 2;
			b >>= 1;

			++answer;
		}

		return answer;
	}
}

namespace kata81
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12953
	int solution(vector<int> arr) 
	{
		vector<int> multi(arr.size(), 1);


		int index = arr.size() - 1;
		while (true)
		{
			if (index == 0)
			{
				break;
			}
			int prev = index - 1;

			if (arr[index] == 1)
			{
				break;
			}

			while(arr[prev] * multi[prev] < arr[index] * multi[index])
			{
				multi[prev] = multi[prev] + 1;
			}

			if (arr[prev] * multi[prev] == arr[index] * multi[index])
			{
				--index;
			}
			else
			{
				index = arr.size()-1;
				++multi[index];
			}
		}

		return arr[0] * multi[0];
	}
}

namespace kata82
{	// https://school.programmers.co.kr/learn/courses/30/lessons/12914
	// 피보나치 수열 나머지와 완전히 같은 코드.
	long long GetBariation(int n)
	{
		static vector<long long> memo(2001, -1);
		if (n == 2) return 2;
		if (n == 1) return 1;
		if (memo[n] != -1) return memo[n];
		return memo[n] = (GetBariation(n - 1) + GetBariation(n - 2)) % 1234567L;
	}

	long long solution(int n) 
	{
		long long answer = GetBariation(n) % 1234567L;
		return answer;
	}
}

namespace kata83
{ //https://school.programmers.co.kr/learn/courses/30/lessons/138476
	int solution(vector<int> arr) 
	{
		vector<int> multi(arr.size(), 1);


		int index = arr.size() - 1;
		while (true)
		{
			if (index == 0)
			{
				break;
			}
			int prev = index - 1;

			if (arr[prev] == 1)
			{
				break;
			}

			while(arr[prev] * multi[prev] < arr[index] * multi[index])
			{
				multi[prev] = multi[prev] + 1;
			}

			if (arr[prev] * multi[prev] == arr[index] * multi[index])
			{
				--index;
			}
			else
			{
				++multi[index];
			}
		}

		return arr[0] * multi[0];
	}
}

namespace kata84
{ //https://school.programmers.co.kr/learn/courses/30/lessons/76502
	int pushLeft(int pos, int max)
	{
		return pos + 1 < max ? pos + 1 : 0;
	}


	int solution(string s) 
	{
		int start = 0;
		int end = s.size() - 1;

		// 열지 않았는데 닫으면 아웃
		// 연만큼 닫지 못하면 아웃
		// 마지막으로 연 괄호랑 다른 종류의 닫기가 나오면 아웃
		int answer = 0;
		int flags[3] = {0, 0, 0};
		vector<char> protectStack;
		protectStack.reserve(s.size());

		for(int i = 0; i < s.size() - 1; i++)
		{
			bool check = true;
			for(int j = 0, index = start; j<s.size(); j++, index++)
			{
				if (index >= s.size())
					index = 0;

				char currentProtect = s[index];

				// 여는 괄호면 push
				if (currentProtect == '(' || currentProtect == '{' || currentProtect == '[')
				{
					protectStack.push_back(currentProtect);
					continue; 
				}

				// 닫는 괄호
				if (protectStack.empty()) 
				{
					check = false;
					break;
				}

				char openProt = protectStack.back();
				protectStack.pop_back();

				// 매칭 확인
				if (!((openProt == '(' && currentProtect == ')') ||
					(openProt == '{' && currentProtect == '}') ||
					(openProt == '[' && currentProtect == ']')))
				{
					check = false;
					break;
				}
				
			}



			if (check && protectStack.empty())
				++answer;

			protectStack.clear();
			start = pushLeft(start, s.size()-1);
			end = pushLeft(end, s.size()-1);
		}



		return answer;
	}
}

#pragma endregion KATA_0819

#pragma region KATA_0820

namespace kata85
{

	using namespace std;

	int solution(vector<int> elements) 
	{
		int n = elements.size();
		vector<int> prefix(2 * n + 1, 0);
		// 메모라이징 고속화
		for (int i = 0; i < 2 * n; i++) 
		{
			prefix[i+1] = prefix[i] + elements[i % n];
		}

		unordered_set<int> s;
		for (int len = 1; len <= n; len++) 
		{
			for (int start = 0; start < n; start++) 
			{
				int sum = prefix[start + len] - prefix[start];
				s.insert(sum);
			}
		}

		return s.size();
	}
}

#pragma endregion KATA_0820

#pragma region KATA_0821
namespace kata86
{
	using namespace std;

	int solution(vector<int> citations)
	{
		sort(citations.begin(), citations.end(), [](int x, int y)
		{
			return x > y;
		});

		int answer = 0;
		for (int i = 0; i < citations.size(); i++, answer++)
		{
			if (citations[i] < i + 1)
			{
				break;
			}
		}


		return answer;
	}
}

namespace kata87
{
	using namespace std;


	vector<int> solution(int n, long long left, long long right) 
	{

		// left, right 는 1차원
		// 1차원을 2차원으로 변경
		// 이 위치가 0,0 부터 각 차원에서 먼 값중 큰 값이 이 값이 된다.

		vector<int> answer;

		int length = right - left + 1;
		answer.reserve(length);

		for (long long i = 0; i < length; i++)
		{
			long long indexLine = i + left;
			auto divResult = div(indexLine, (long long)n);
			long long maxDis = max(divResult.quot, divResult.rem);
			answer.push_back(maxDis + 1);
		}
		return answer;
	}
}
#pragma endregion KATA_0821

#pragma region KATA_0822
namespace kata88
{
	vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
	{
		// 앞 행렬의 행
		// 뒷 행렬의 열을 가진 2차원 행렬이 답이된다.

		int row = arr1.size();
		int col = arr2.front().size();
		int multiCnt = arr1.front().size();
		vector<vector<int>> answer(row, vector<int>(col, 0));

		for (int i = 0; i < row; i ++)
		{
			for (int j = 0; j < col; j++)
			{
				
				// n, m 의 행렬값은
				// arr1 i 행 값과 arr2 j열 의 각 값을 곱하고 그 모두를 더한 것.
				// 그래서 arr1의 열개수 == arr2의 행 개수 여야 하고 이는 문제에서 보장해줌
				int value = 0;
				for (int k = 0; k < multiCnt; k++)
				{
					value += arr1[i][k] * arr2[k][j];
				}
				answer[i][j] = value;
			}
		}

		return answer;
	}
}

namespace kata89
{
	using namespace std;

	int solution(vector<string> want, vector<int> number, vector<string> discount)
	{
		// 각 품목마다 10일 가능한 날짜들중 모두가 겹칠 수 있는 날
		//
		// 각 품목별 10일 이내에 할인 하는 날짜를 기록한다
		// 반대로 각 날짜별 그날부터 10일간 구매 가능한 품목을 기록한다// 1회 순회로 완성
		// 모든 항목 숫자를 커버할 수 있는 날짜를 찾아서 반환한다.

		// 각 날짜, 종류들, 종류별 개수
		// 종목별, 존재 날짜

		//unordered_map<string, vector<int>> discountTable;
		unordered_map<string, int> discountTable;
		discountTable.reserve(discount.size() - 9);

		auto isValid = [&](unordered_map<string,int>& table) 
		{
			for (int j = 0; j < want.size(); j++) 
			{
				if (table[want[j]] < number[j]) 
					return false;
			}
			return true;
		};

		int answer = 0;
		const int window = 10;
		for (int i = 0; i < window; i++)
		{
			++discountTable[discount[i]];
		}

		if (isValid(discountTable)) answer++;

		for (int i = 1; i + window - 1 < discount.size(); i++)
		{
			--discountTable[discount[i - 1]];
			++discountTable[discount[i + window - 1]];

			if (isValid(discountTable)) answer++;
		}

		return answer;
	}

		
}
#pragma endregion KATA_0822

#pragma region KATA_0824
namespace kata90
{
	int factorial(int n) 
	{
		int result = 1;
		for (int i = 2; i <= n; i++) result *= i;
		return result;
	}

	int solution(vector<vector<string>> clothes) 
	{
		// n개 종류를 중복없이 m개 선택하면
		// n! / m!(n-m)! 이 된다.

		// i 번째 요소를 반드시 포함 한 중복없는 조합의 개수
		// n - 1, m  의식으로 결정됨 따라서 요소의 개수만큼 곱하고
		// (n - 1, m) * 요소개수 + (n - 1, m- 1) 식 (i 번째 요소를 제외한 나머지 조합)
		// 모든 상태 개수 * (n - 1, m)
		unordered_map<string, int> clothesMap;

		for (const vector<string>& v : clothes)
		{
			clothesMap[v[1]]++;
		}

		int answer = 1;
		for (const pair<string, int>& p : clothesMap)
		{
			answer *=  (1 + p.second);
		}
		answer -= 1;


		return answer;
	}
}

namespace kata91
{
	vector<int> solution(vector<int> progresses, vector<int> speeds) 
	{   
 
		vector<int> answer;
		int day = 0;
		int index = 0;
		while(true)
		{

			for (int i =0; i < progresses.size(); i++)
			{
				progresses[i] += speeds[i];
			}

			int complete = 0;
			for (int i = index; i < progresses.size(); i++)
			{
				if (progresses[i] >= 100)
				{
					complete++;
				}
				else
				{
					break;
				}
			}
			if (complete == 0) continue;
			index += complete;
			answer.push_back(complete);

			if (index >= progresses.size())
				break;
		}
		

		return answer;
	}
}
#pragma endregion KATA_0824

#pragma region KATA_0825
namespace kata92 
{
	using namespace std;

	int solution(vector<int> priorities, int location) 
	{
		// 실행 순서 = 자신 보다 높은 우선 순위 개수 + 마지막 실행위치 기준 같은 우선순위의 앞 순번

		// 자신과 같은 우선순위의 프로세스가 없으면 자신 보다 높은 우선 순위 개수 + 1
		// 있는 경우.

		map<int, vector<int>> indexMap;
		for (int i =0; i < priorities.size(); i++)
		{
			indexMap[priorities[i]].push_back(i);
		}

		int targetPriority = priorities[location];

		int answer = 0;
		int nowIndex = priorities.size();
		for (auto iter = indexMap.rbegin(); iter != indexMap.rend(); ++iter)
		{
			vector<int>& indexVec = iter->second;
			int priorityIndex = -1;

			//cout << "start : " << iter->first;
			// indexVec[j] == 0 ? indexVec.back() 

			auto it = upper_bound(indexVec.begin(), indexVec.end(), nowIndex);
			// nowIndex보다 큰 원소가 없거나 첫 번째이면 맨 뒤 원소가 마지막
			// 있으면 그 직전 원소가 마지막
			priorityIndex = (it == indexVec.begin() ? indexVec.size() - 1 : (it - indexVec.begin()) - 1);
			nowIndex = indexVec[priorityIndex];

			if (iter->first == targetPriority)
			{   // nowIndex 와의 거리 사이에 있는 이번 우선순위 요소 수 + 여태 지나온 개수
				int distance = 0; 
				// priorityIndex + 1 == 출발 인덱스
				auto iterVec = indexVec.begin() + (priorityIndex + 1);
				for (int j = 0; j < indexVec.size(); j++, distance++, iterVec++)
				{
					if (iterVec == indexVec.end())
						iterVec = indexVec.begin();
					if (*iterVec == location)
					{
						break;
					}
				}
				//cout << ", dis : " << distance << ", priorityIndex : " << priorityIndex << endl;;
				// 스스로가 처리되는 거 + 거리
				answer += distance + 1;
				break;    
			}
			answer += indexVec.size();
		}

		return answer;
	}
}
#pragma endregion KATA_0825
//#pragma region KATA_
//#pragma endregion KATA_
//https://github.com/piecebypiece/Code-kata