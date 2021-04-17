#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string encrypt(string input) {
    string output = "";
    
    for (int i = 0; i < input.size(); i++) 
        output.append(to_string(int(input[i])) + " ");       

    return output.append("-1");
}

string decrypt(string input) {
    string output = "";
    char *token = strtok((char *)input.c_str(), " ");
    while (token != NULL) {
        output.push_back(char(stoi(token)));
        token = strtok(NULL, " ");
    }
     
    return output;    
}

// ../Materials/CPS - 2/Problem - 5 - Love Letter.pdf
int main() {
    string ascii_input = "76 101 116 39 115 32 109 101 101 116 32 116 111 100 97 121 32 101 118 101 110 105 110 103 32 97 116 32 68 117 114 103 97 109 32 67 104 101 118 117 114 117 46";
    string sentence = "Sure. But Please bring a rose and chocolate (Dairy Milk Silk)";
    cout << encrypt(sentence) << endl << endl;
    cout << decrypt(ascii_input) << endl;
    return 0;
}