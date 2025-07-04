#include <iostream>
#include <cstring>
using namespace std;

int main() {

    string str;
    cin >> str;

    for(int i = 0; i < 3; i++) cout << ":fan:";
    cout << '\n' << ":fan:";
    cout << ":" << str << ":" << ":fan:" << '\n';
    for(int i = 0; i < 3; i++) cout << ":fan:";
    
    return 0;
}