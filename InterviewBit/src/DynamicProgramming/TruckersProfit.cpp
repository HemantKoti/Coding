/*
 * TruckersProfit.cpp
 *
 *  Created on: May 13, 2018
 *      Author: HemantKo
 */

#include "../../include/interviewbit.h"

vector<int> findTruckCargo(int maxCargoWeight, vector<vector<int>> cargoList)
{
	vector<vector<int>> knapsack(cargoList.size() + 1, vector<int>(maxCargoWeight + 1));
	for (int i = 0; i <= cargoList.size(); i++)
	{
		for (int weight = 0; weight <= maxCargoWeight; weight++)
		{
			if (i == 0 || weight == 0)
				knapsack[i][weight] = 0;
			else if (cargoList[i - 1][1] <= weight)
				knapsack[i][weight] = max(cargoList[i - 1][2] + knapsack[i - 1][weight - cargoList[i - 1][1]], knapsack[i - 1][weight]);
			else
				knapsack[i][weight] = knapsack[i - 1][weight];
		}
	}
	return knapsack[cargoList.size()];
}
