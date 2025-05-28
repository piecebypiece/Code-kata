// CodeKATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "KATA.hpp"

int main()
{
	std::cout << "Hello World!\n";
	int evenSum = KATA_0527::solution(10); // https://school.programmers.co.kr/learn/courses/30/lessons/120831
	std::cout << "evenSum = " << evenSum << "\n";

	KATA_0528::solution("Every day code kata");
}