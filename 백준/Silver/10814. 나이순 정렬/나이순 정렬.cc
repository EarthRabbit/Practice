#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare1(pair<int, string> list1, pair<int, string> list2){
    if(list1.first == list2.first) return false;
    return list1.first < list2.first;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, age;
    string name;
    vector<pair<int, string>> list1;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> age >> name;
        list1.push_back(make_pair(age, name));
    }
    stable_sort(list1.begin(), list1.end(), compare1);
    for(int i=0; i<list1.size(); i++){
        cout << list1[i].first << " " << list1[i].second << '\n';
    }
    return 0;
}