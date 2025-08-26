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
#pragma endregion KATA_0826
//#pragma region KATA_
//#pragma endregion KATA_
//https://github.com/piecebypiece/Code-kata