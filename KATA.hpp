#pragma once

template <typename T>
class vector;

//namespace KATA_0527
//{
//    //https://school.programmers.co.kr/learn/courses/30/lessons/120831
//    //int solution(int n);
//}
//
//namespace KATA_0528
//{
//    // 스레드 문제 문자열 회전
//    void solution(std::string str);
//    double solution(vector<int> numbers);
//}

namespace KATA_0529
{
    namespace RotateStrings
    { 
        std::string solution(int num);
    }

    double solution(vector<int> arr);

    namespace SumNumberSeats 
    { // 함수 정의가 겹쳐서 네임스페이스 추가
        int solution(int n);
    }
}