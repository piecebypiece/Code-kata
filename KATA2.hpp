#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

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
	{
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


#pragma endregion KATA_0819


//#pragma region KATA_
//#pragma endregion KATA_
//https://github.com/piecebypiece/Code-kata