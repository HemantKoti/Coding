#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

vector<int> getMinDistances(vector<unordered_map<string, bool>> blocks, string requirement)
{
    vector<int> minDistances(blocks.size(), 0);

    int closestRequiredIndex = INT_MAX - 1;
    for (int i = 0; i < blocks.size(); i++)
    {
        if (blocks[i][requirement])
            closestRequiredIndex = i;
        minDistances[i] = abs(i - closestRequiredIndex);
    }

    for (int i = blocks.size() - 1; i >= 0; i--)
    {
        if (blocks[i][requirement])
            closestRequiredIndex = i;
        minDistances[i] = min(minDistances[i], abs(i - closestRequiredIndex));
    }

    return minDistances;
}

vector<int> getMaxDistancesAtBlocks(vector<unordered_map<string, bool>> blocks, vector<vector<int>> &minDistancesFromBlocks)
{
    vector<int> maxDistancesAtBlocks(blocks.size(), 0);
    
    for (int i = 0; i < blocks.size(); i++)
    {
        vector<int> minDistancesAtBlock;
        for (int j = 0; j < minDistancesFromBlocks.size(); j++) {
            minDistancesAtBlock.push_back(minDistancesFromBlocks[j][i]);    
        }    
        maxDistancesAtBlocks[i] = *max_element(minDistancesAtBlock.begin(), minDistancesAtBlock.end());
    }

    return maxDistancesAtBlocks;
}

int getIndexAtMinValue(vector<int> &maxDistanceAtBlocks)
{
    int indexAtMinValue = 0;
    int minValue = INT_MAX;
    for (int i = 0; i < maxDistanceAtBlocks.size(); i++)
    {
        if (maxDistanceAtBlocks[i] < minValue)
        {
            minValue = maxDistanceAtBlocks[i];
            indexAtMinValue = i;
        }
    }

    return indexAtMinValue;
}

int apartmentHunting(vector<unordered_map<string, bool>> &blocks, vector<string> &requirements)
{
    vector<vector<int>> minDistancesFromBlocks;
    vector<int> maxDistanceAtBlocks;
    for (auto requirement : requirements)
        minDistancesFromBlocks.push_back(getMinDistances(blocks, requirement));
    maxDistanceAtBlocks = getMaxDistancesAtBlocks(blocks, minDistancesFromBlocks);
    return getIndexAtMinValue(maxDistanceAtBlocks);
}

// https://medium.com/@pandeyroshan556/apartment-hunting-problem-85c6acee8741
// https://drive.google.com/file/d/1ncU7vTMLACDPD4ld6kGhANm8aVV_Jc9g/view?usp=sharing
int main()
{
    vector<unordered_map<string, bool>> blocks{
        {{"gym", false}, {"school", true}, {"store", false}},
        {{"gym", true}, {"school", false}, {"store", false}},
        {{"gym", true}, {"school", true}, {"store", false}},
        {{"gym", false}, {"school", true}, {"store", false}},
        {{"gym", false}, {"school", true}, {"store", true}}};

    vector<string> requirements{"gym", "school", "store"};
    try
    {
        cout << apartmentHunting(blocks, requirements);
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}