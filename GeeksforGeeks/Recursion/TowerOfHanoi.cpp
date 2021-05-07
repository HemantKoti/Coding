#include <iostream>

using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxillary) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, auxillary, destination);
    cout << "Move disk " << n <<  " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxillary, destination, source);
}

int main() {
    towerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}