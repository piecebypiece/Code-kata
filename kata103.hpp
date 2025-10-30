#pragma once
#include <string>
#include <vector>
#include <algorithm>

//#pragma region KATA_https://github.com/piecebypiece/Code-kata

//#pragma endregion KATA_
//
using namespace std;

string solution(vector<int> numbers)
{
	vector<string> toStrs;
	toStrs.reserve(numbers.size());

	for (int i : numbers)
	{
		toStrs.push_back(to_string(i));
	}

	// 핵심: a+b 와 b+a 비교로 내림차순
	sort(toStrs.begin(), toStrs.end(),
		[](const string& a, const string& b)
	{
		return a + b > b + a;
	});

	// 전부 0인 경우
	if (!toStrs.empty() && toStrs[0] == "0")
		return "0";

	string ans;
	ans.reserve(toStrs.size()); // 대략적 예약(옵션)
	for (const auto& t : toStrs)
		ans += t;

	return ans;
}