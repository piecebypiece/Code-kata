#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <unordered_set>

#pragma region KATA_0826
namespace kata93
{
    using namespace std;

    int AnswerFind (int k, const vector<vector<int>>& arr, vector<bool>& used, int currentSize)
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
        if  ( i == numbers.size())
        {
            //cout << (check == target ? "t" : "F") << endl;
            return check == target ? 1 : 0;
        }

        count += dfs(numbers,  target, check + numbers[i], i + 1);
        count += dfs(numbers,  target, check - numbers[i], i + 1);
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
        if(K == 10) 
        {
            return to_string(decimal);
        }

        string result;
        int num = decimal;

        // 진법 변환 수행
        while(num > 0) 
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

        for(char c : str)
        {
            if(c == '0')
            {
                if(!current.empty())
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

        if(!current.empty() && checkZero)
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
//#pragma region KATA_
//#pragma endregion KATA_
//https://github.com/piecebypiece/Code-kata