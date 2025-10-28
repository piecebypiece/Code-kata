#pragma once

#include <queue>
#include <string>
#include <vector>
#include <algorithm>

//#pragma region KATA_https://github.com/piecebypiece/Code-kata

//#pragma endregion KATA_
//
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	// 다리를 건너는 최소 초는 bridge_length + 1 초
	// length 는 건너는 시간을 늘리거나 줄이지 않는다.
	// length = 1 = 6
	//			2 = 7 = 9초가 된다
	// 얼마나 동시에 탈 수 있느냐가 크게 좌우한다.

	// 그건 weight 로 결정된다.
	// 최저치는 lenth + n + 1 인듯?

	// -틱마다 최대 이윤 결과를 실행하면서 진행-
	int tick = 0;
	int nowWeight = 0;
	int nowTruckCnt = 0;
	int index = 0;
	queue<int> bridgeQueue;

	for (int i = 0; i < bridge_length; i++)
		bridgeQueue.push(0);

	while (true)
	{
		int completeTruckWeight = bridgeQueue.front();
		bridgeQueue.pop();
		nowWeight -= completeTruckWeight;

		if (completeTruckWeight != 0)
		{
			--nowTruckCnt;
		}
		tick++;

		// 모든 트럭이 건넜다.
		if (index >= truck_weights.size() && nowTruckCnt == 0)
			break;

		//
		if (nowTruckCnt < bridge_length
			&& nowWeight < weight
			&& index < truck_weights.size())
		{
			int nextTruck = truck_weights[index];
			int canWeight = weight - nowWeight;
			// 건널 수 있는지 확인
			if (nextTruck <= canWeight)
			{
				nowWeight += nextTruck;
				nowTruckCnt++;
				index++;
				bridgeQueue.push(nextTruck);
				continue;
			}
		}

		bridgeQueue.push(0);
	}
	return tick;
}