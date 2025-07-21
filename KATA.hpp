#pragma once
#include <vector>
#include <string>

#include <set>
#include <iterator>

#include <numeric>
#include <algorithm>

using std::string;
using std::vector;

#pragma region KATA_0527
// KATA_0527
namespace kata09
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/120831
	int solution(int n);
}
#pragma endregion KATA_0527

#pragma region KATA_0528
// KATA_0528
	// 스레드 문제 문자열 회전
namespace RotateStrings
{
	void solution(string str);
}
namespace kata10
{
	double solution(vector<int> numbers);
}
#pragma endregion KATA_0528

#pragma region KATA_0529
// KATA_0529
namespace kata11
{
	std::string solution(int num);
}
namespace kata13_SumNumberSeats
{
	int solution(int n);
}
#pragma endregion KATA_0529

#pragma region KATA_0530
// KATA_0530
namespace kata14
{
	int solution(int primNum);
}
#pragma endregion KATA_0530

#pragma region KATA_0602
// KATA_0602
	// 간단한 이전문제들 수정
namespace kata1
{
	int solution(int num1, int num2);
}

namespace kata2
{
	int solution(int num1, int num2);
}

namespace kata3
{
	int solution(int num1, int num2);
}

namespace kata4
{
	int solution(int age);
}

namespace kata15
{
	int solution(int n);
}
#pragma endregion KATA_0602

#pragma region KATA_0605
// KATA_0605

namespace kata18
{
	int solution(string s);
}
#pragma endregion KATA_0605

#pragma region KATA_0609
// KATA_0609
namespace kata19
{
	long long solution(long long n);
}

namespace kata20
{
	long long solution(long long n);
}

namespace kata21
{
	bool solution(int x);
}
#pragma endregion KATA_0609

#pragma region KATA_0610
// KATA_0610
namespace kata21
{
	bool solution(int x);
}
namespace kata22
{
	long long solution(int a, int b);
}
#pragma endregion KATA_0610

#pragma region KATA_0612
// KATA_0612
	//https://school.programmers.co.kr/learn/courses/30/lessons/12943
namespace kata23
{
	int solution(int num);
}
#pragma endregion KATA_0612

#pragma region KATA_0613
// KATA_0613
namespace kata24
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12919
	string solution(vector<string> seoul);
}

namespace kata25
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12910
	vector<int> solution(vector<int> arr, int divisor);
}

namespace kata26
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/76501
	int solution(vector<int> absolutes, vector<bool> signs);
}

namespace kata27
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12948
	string solution(string phone_number);
}

namespace kata28
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/86051
	int solution(vector<int> numbers);
}
#pragma endregion KATA_0613

#pragma region KATA_0616
// KATA_0616
namespace kata29
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12935
	vector<int> solution(vector<int> arr);
}
#pragma endregion KATA_0616

#pragma region KATA_0617
// KATA_0617
namespace kata30
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12903
	string solution(string s);
}

namespace kata31
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12922
	string solution(int n);
}
namespace kata32
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/70128
	int solution(vector<int> a, vector<int> b);
}
namespace kata33
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/77884
	int solution(int left, int right);
}
#pragma endregion KATA_0617

#pragma region KATA_0618
// KATA_0618
namespace kata34
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12917
	string solution(string s);
}
namespace kata35
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/82612#
	long long solution(int price, int money, int count);
}
#pragma endregion KATA_0618

#pragma region KATA_0619
// KATA_0619
namespace kata36
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12918
	bool solution(string s);
}
namespace kata37
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12950
	vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2);
}
namespace kata38
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/12969
	int solution(void);	// 문제에선 main 썻음
}
#pragma endregion KATA_0619

#pragma region KATA_0623
// KATA_0623
namespace kata39
{
	vector<int> solution(int n, int m);
}
namespace kata40
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/68935
	int solution(int n);
}
#pragma endregion KATA_0623

#pragma region KATA_0624
// KATA_0624
namespace kata41
{//https://school.programmers.co.kr/learn/courses/30/lessons/12930
	string solution(string s);
}
namespace kata42
{
	//https://school.programmers.co.kr/learn/courses/30/lessons/131705
	int solution(vector<int> number);
}
#pragma endregion KATA_0624

#pragma region KATA_0626
// KATA_0626
namespace kata43
{ //https://school.programmers.co.kr/learn/courses/30/lessons/147355
	int solution(string t, string p);
}
#pragma endregion KATA_0626

#pragma region KATA_0701
// KATA_0701
	//https://school.programmers.co.kr/learn/courses/30/lessons/86491
namespace kata44
{
	int solution(vector<vector<int>> sizes);
}
#pragma endregion KATA_0701

#pragma region KATA_0702
// KATA_0702
namespace kata45
{ //https://school.programmers.co.kr/learn/courses/30/lessons/12926#
	string solution(string s, int n);
}
#pragma endregion KATA_0702


#pragma region KATA_0704
// KATA_0704
namespace kata46
{	//https://school.programmers.co.kr/learn/courses/30/lessons/81301
	int solution(string input);
}
namespace kata47
{	//https://school.programmers.co.kr/learn/courses/30/lessons/12915
	int solution(string input);
}
#pragma endregion KATA_0704

#pragma region KATA_0705
// KATA_0705
namespace kata48
{ //https://school.programmers.co.kr/learn/courses/30/lessons/42748
	vector<int> solution(vector<int> array, vector<vector<int>> commands);
}
#pragma endregion KATA_0705

#pragma region KATA_0706
// KATA_0706

namespace kata49
{ //https://school.programmers.co.kr/learn/courses/30/lessons/68644
	vector<int> solution(vector<int> numbers);
}
#pragma endregion KATA_0706

#pragma region KATA_0707
// KATA_0707
namespace kata50
{//https://school.programmers.co.kr/learn/courses/30/lessons/142086
	vector<int> solution(string s);
}
namespace kata51
{//https://school.programmers.co.kr/learn/courses/30/lessons/134240
	string solution(vector<int> food);
}
#pragma endregion KATA_0707

#pragma region KATA_0707
namespace kata52
{ //https://school.programmers.co.kr/learn/courses/30/lessons/132267
	int solution(int a, int b, int n);
}
#pragma endregion KATA_0707

#pragma region KATA_0708

namespace kata53
{ //https://school.programmers.co.r/learn/courses/30/lessons/138477
	vector<int> solution(int k, vector<int> score);
}

namespace kata54
{ //https://school.programmers.co.kr/learn/courses/30/lessons/12901
	string solution(int a, int b);
}
#pragma endregion KATA_0708

#pragma region KATA_0715

namespace kata55
{ //https://school.programmers.co.kr/learn/courses/30/lessons/159994
	bool searchRoute(vector<string>& cards1, vector<string>& cards2,
		vector<string>& goal, int i, int j, int targetIndex);
	string solution(vector<string> cards1, vector<string> cards2, vector<string> goal);
}
#pragma endregion KATA_0715

#pragma region KATA_0717
namespace kata56
{ //https://school.programmers.co.kr/learn/courses/30/lessons/135808
	int solution(int k, int m, vector<int> score);
}

namespace kata57
{ // https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
	vector<int> solution(vector<int> answers);
}

#pragma endregion KATA_0717

#pragma region KATA_0718

namespace kata58
{ //https://school.programmers.co.kr/learn/courses/30/lessons/12977
	int solution(vector<int> nums);
}
#pragma endregion KATA_0718

#pragma region KATA_0720

namespace kata59
{	// https://school.programmers.co.kr/learn/courses/30/lessons/161989
	int solution(int n, int m, vector<int> section);
}

#pragma endregion KATA_0720

#pragma region KATA_0721

namespace kata60
{	//https://school.programmers.co.kr/learn/courses/30/lessons/136798
	int countDivisors(int n);
	int solution(int number, int limit, int power);
}

namespace kata61
{ //https://school.programmers.co.kr/learn/courses/30/lessons/77484
	vector<int> solution(vector<int> lottos, vector<int> win_nums);
}
#pragma endregion KATA_0721