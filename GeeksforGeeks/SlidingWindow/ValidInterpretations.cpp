#include <iostream>
#include <vector>
#include <string>

using namespace std;

int validInterpretations(string str) {
    vector<string> result(str.size() + 2);
    int count = 1;

    result.push_back(str);

    for (int i = 0; i < str.size() - 1; i++) {
        int temp = stoi(str.substr(i, 2));
        if (temp >= 10 && temp <= 26)
            count++;
    }

    if (count > 2)
        count++;

    return count;
}

int main() {
    string str = "1001";
    cout << validInterpretations(str) << endl;

    return 0;
}