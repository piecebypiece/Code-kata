// CodeKATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "KATA.hpp"
#include "KATA2.hpp"
#include "KATA3.hpp"
using namespace std;
int main()
{
	//kata95::solution(10000, 10);
	kata95::solution( 797161, 3);
	kata96::solution({ 120, 0, 60, 591 },
		{ "16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN" });
}