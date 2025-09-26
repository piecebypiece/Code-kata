#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <chrono>
#include <charconv>

#include <queue>
#pragma region KATA_0826
namespace kata93
{
	using namespace std;

	int AnswerFind(int k, const vector<vector<int>>& arr, vector<bool>& used, int currentSize)
	{
		int maxSize = currentSize;

		for (int i = 0; i < arr.size(); ++i)
		{
			const vector<int>& current = arr[i];

			if (!used[i] && current[0] <= k && current[1] <= k)
			{
				used[i] = true;
				maxSize = std::max(maxSize, AnswerFind(k - current[1], arr, used, currentSize + 1));
				used[i] = false; // 되돌리기
			}
		}

		return maxSize;
	}

	int solution(int k, vector<vector<int>> dungeons)
	{
		vector<bool> used(dungeons.size(), false);
		return AnswerFind(k, dungeons, used, 0);
	}
}
namespace kata94
{
	using namespace std;

	int dfs(const vector<int>& numbers, int target, int check, int i)
	{
		int count = 0;
		if (i == numbers.size())
		{
			//cout << (check == target ? "t" : "F") << endl;
			return check == target ? 1 : 0;
		}

		count += dfs(numbers, target, check + numbers[i], i + 1);
		count += dfs(numbers, target, check - numbers[i], i + 1);
		return count;
	}

	int solution(vector<int> numbers, int target)
	{
		return dfs(numbers, target, 0, 0);;
	}
}
#pragma endregion KATA_0826

#pragma region KATA_0827
namespace kata95
{
	using namespace std;

	string decimalToK(int decimal, int K)
	{
		// 0인 경우 바로 처리
		if (K == 10)
		{
			return to_string(decimal);
		}

		string result;
		int num = decimal;

		// 진법 변환 수행
		while (num > 0)
		{
			auto divResult = div(num, K);

			int remainder = divResult.rem;
			result += to_string(remainder);  // 숫자를 문자열로 변환하여 추가
			num = divResult.quot;  // 몫으로 갱신
		}

		// 나머지를 역순으로 정렬 (가장 마지막 계산이 가장 높은 자리수)
		reverse(result.begin(), result.end());

		return result;
	}

	vector<string> splitByZero(const string& str)
	{
		vector<string> parts;
		string current;

		bool checkZero = false;

		for (char c : str)
		{
			if (c == '0')
			{
				if (!current.empty())
				{
					parts.push_back(current);
					current.clear();
				}
				checkZero = true;
			}
			else
			{
				current += c;
			}
		}

		if (!current.empty() && checkZero)
		{
			parts.push_back(current);
		}

		return parts;
	}

	int countPrimes(const vector<string>& numbers)
	{
		int count = 0;

		for (const string& numStr : numbers)
		{
			// 문자열을 숫자로 변환
			long long num = stoll(numStr);
			if (num <= 1) continue;
			// 2보다 작은 수는 소수가 아님
			if (num == 2)
			{
				count++;
				continue;
			}

			// 짝수는 소수가 아님
			if (num % 2 == 0) continue;

			// 홀수에 대해서만 제곱근까지 검사
			bool isPrime = true;
			long long sqrtNum = floor(sqrt((long double)num));

			for (long long i = 3; i <= sqrtNum; i += 2)
			{
				if (num % (long long)i == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime) count++;
		}

		return count;
	}

	int solution(int n, int k)
	{
		string kNumber = decimalToK(n, k);
		vector<string> v = splitByZero(kNumber);
		return v.size() == 0 ? 0 : countPrimes(v);
	}
}
#pragma endregion KATA_0827

#pragma region KATA_0828

namespace kata96
{
	vector<int> solution(vector<int> fees, vector<string> records)
	{
		// record 데이터 "05:34 5961 IN"

		unordered_map<string_view, int> carInMap;
		map<string_view, int> parkingMinentMap;

		for (int i = 0; i < records.size(); i++)
		{
			string_view current(records[i]);
			// 첫 번째 공백 위치
			size_t pos1 = current.find(' ');
			// 두 번째 공백 위치
			size_t pos2 = current.find(' ', pos1 + 1);

			// 각각 string_view 로 잘라서 변수에 저장
			string_view time = current.substr(0, pos1);
			string_view number = current.substr(pos1 + 1, pos2 - (pos1 + 1));
			string_view inout = current.substr(pos2 + 1);

			int h, m;
			from_chars(time.data(), time.data() + 2, h);
			from_chars(time.data() + 3, time.data() + 3 + 2, m);
			int total = h * 60 + m;

			if (carInMap.find(number) == carInMap.end())
			{
				carInMap[number] = total;
			}
			else
			{
				parkingMinentMap[number] += total - carInMap[number];
				carInMap.erase(number);
			}
		}
		// 남아있는 데이터는 out이 없는 데이터 최대 시간까지 주차했다고 가정해야한다.
		for (pair<string_view, int> pair : carInMap)
		{
			// 최대시간 생성
			const int maxTimeMinute = 23 * 60 + 59;
			parkingMinentMap[pair.first] += (maxTimeMinute - pair.second);
		}


		vector<int> answer;
		answer.reserve(parkingMinentMap.size());

		// fees = 기본 시간(분),	기본 요금(원),	단위 시간(분),	단위 요금(원)
		// 기본시간 이내면 기본 요금 그 위 의 단위시간 초과분 마다 단위 요금 

		for (const pair<string_view, int>& pair : parkingMinentMap)
		{
			int minutes = pair.second;
			int fee = 0;
			if (minutes > 0)
			{
				fee = fees[1];
			}

			minutes -= fees[0];
			if (minutes > 0)
			{
				div_t divResult = div(minutes, fees[2]);
				fee += divResult.quot * fees[3];
				if (divResult.rem > 0)
					fee += fees[3];

			}

			answer.push_back(fee);
		}

		return answer;
	}
}

#pragma endregion KATA_0828

#pragma region KATA_0829
namespace kata97
{
	using namespace std;

	int counter = 0;              // 몇 번째인지 세는 변수
	vector<int> target;           // 찾고 싶은 경로
	bool found = false;           // 찾았는지 여부

	void dfs(int depth, vector<int>& path, int N) 
	{
		if (found || depth > N) return; // 이미 찾았으면 중단


		counter++; // 경로
		if (path == target)
		{
			found = true;
			return;
		}

		// 가능한 선택지 (예시: 1~N)
		for (int i = 0; i < N; i++) 
		{
			path.push_back(i);
			dfs(depth + 1, path, N);
			path.pop_back();
		}
	}


	int solution(string word) 
	{
		const string dict = "AEIOU";

		for (char c : word)
		{
			target.push_back(dict.find(c));
		}
		vector<int> path;
		path.reserve(dict.size());
		dfs(0, path, dict.size());
		return   counter;
	}
}
#pragma endregion KATA_0829
#pragma region KATA_0901

namespace kata98
{
	using namespace std;
	vector<int> solution(vector<int> numbers)
	{

		vector<int> answer(numbers.size(), -1);
		map<int, vector<int>> searchIndex;
		
		searchIndex[numbers.front()] =  { 0 };

		for (int i = 1; i < numbers.size(); i++)
		{
			//numbers[i] 이 값보다 작은 대기중 인덱스들은 모두 이값으로 변경한다
			int number = numbers[i];

			searchIndex[number].push_back(i);
			

			auto numberIter = searchIndex.find(number);
			auto iter = make_reverse_iterator(numberIter);
			if (iter != searchIndex.rend())
			{
				for (; iter != searchIndex.rend(); iter++)
				{
					auto& vec = iter->second;
					for (int tIndex : vec)
					{
						answer[tIndex] = number;
					}
				}
				searchIndex.erase(searchIndex.begin(), searchIndex.lower_bound(number));
			}
		}
		return answer;
	}
}
#pragma endregion KATA_0901

#pragma region KATA_0915

namespace kata99
{
	using namespace std;

	int solution(vector<int> topping)
	{
		int answer = 0;

		unordered_map<int, int> kindCounterMap;

		for (int top : topping)
		{
			kindCounterMap[top]++;
		}

		unordered_map<int, int> splitCountMap;

		int leftCnt = 0, rightCnt = 0;
		leftCnt = kindCounterMap.size();
		for (int i = topping.size() - 1; i >= 0; i--)
		{
			int top = topping[i];
			splitCountMap[top]++;
			kindCounterMap[top]--;
			
			if (kindCounterMap[top] == 0)
			{
				kindCounterMap.erase(top);
			}

			if (kindCounterMap.size() == splitCountMap.size())
			{
				answer++;
			}
		}

		return answer;
	}
}

#pragma endregion KATA_0915

#pragma region KATA_0917
namespace kata100
{
	int solution(int x, int y, int n) 
	{
		if (x == y) return 0;

		vector<bool> visited(y + 1, false);
		queue<pair<int, int>> q;
		q.push({x, 0});
		visited[x] = true;

		while (!q.empty()) 
		{
			auto [current, cnt] = q.front();
			q.pop();

			// 세 가지 연산 시도
			int operations[] = {current * 3, current * 2, current + n};

			for (int nextVal : operations) 
			{
				if (nextVal == y) return cnt + 1;
				if (nextVal > y || visited[nextVal]) continue;

				visited[nextVal] = true;
				q.push({nextVal, cnt + 1});
			}
		}

		return -1;
	}
}
#pragma endregion KATA_0917

#pragma region KATA_0926
namespace kata101
{
	using namespace std;

	int MSB(long long checker)
	{
		int cnt = 0;
		while(checker > 0)
		{
			checker >>= 1;
			++cnt;
		}
		return cnt;
	}

	long long TwoBitDiffMinimum(long long number)
	{
		// 이진 수에서 
		// 가장 큰 비트의 1까지의 비트 개수 내에서 1의 개수가 많거나
		// 더 큰 비트에서 1이 더 있거나

		// 우측부터 0 자리에 1을 넣기.
		// 빈 자리가 없는 경우가 아니라면 
		//most significant bit
		// c++ 20 이상 안되면 우측 쉬프트 해서 0 될 때까지 실행하고 횟수 카운트

		//int retval = 0;
		//int msb = MSB(number); 
		//long long shifter = 1;
		//for (int i = 0; i < msb; i++, shifter <<= 1)
		//{
		//	if ((number & shifter) == 0)
		//	{
		//		// 이 비트 자리가 0이라는 뜻
		//		retval = number | shifter;
		//		break;
		//	}
		//}
		//if (retval == 0)
		//{
		//	retval = number | shifter;
		//}

		//// 1 개수를 늘렸음으로 하나 다름 
		//// 늘린 비트 위치 에서 다시 0 비트까지 내려가면서 1인 걸 0으로 변경
		//// 다 내려갈 필요없고 한 자리 옆이면 된다.
		//if ((shifter >>= 1) > 0)
		//{
		//	retval = retval & ~shifter;
		//}
		//return retval;

		if (number == 0) return 1;
		if ((number & 1LL) == 0) return number + 1;            // 짝수

		// 홀수: 꼬리 1의 개수 t 찾기 = 처음 만나는 0의 위치 s=1<<t
		long long s = 1;
		while (number & s) s <<= 1;

		// 그 0을 1로 켜고, 바로 아래 비트를 0으로 끈 결과와 동일
		// 수식으로는 number + (s >> 1)
		return (number | s) & ~(s >> 1);
	}

	vector<long long> solution(vector<long long> numbers) 
	{
		vector<long long> answer;
		answer.reserve(numbers.size());

		for (auto number : numbers)
			answer.push_back(TwoBitDiffMinimum(number));


		return answer;
	}
}
#pragma endregion KATA_0926

//#pragma region KATA_
//#pragma endregion KATA_
//https://github.com/piecebypiece/Code-kata