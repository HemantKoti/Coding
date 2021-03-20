#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n = 10;
    map<int, vector<pair<int, int>>> table;

    for (int i = 1; i <= n; i++)
    {
        int result = 0;
        for (int j = 1; j <= n; j++)
        {
            result = i * i * i + j * j * j;
            if (table.find(result) == table.end())
                table.insert(pair<int, vector<pair<int, int>>>(result, {pair<int, int>(i, j)}));
            else
                table[result].push_back(pair<int, int>(i, j));
        }
    }

    for (auto const &[key, val] : table)
    {
        for (int i = 0; i < val.size(); i++)
        {
            for (int j = i + 1; j < val.size(); j++)
            {
                cout << val[i].first << " " << val[i].second << " " << val[j].first << " " << val[j].second << endl;
            }
        }
    }

    return 0;
}