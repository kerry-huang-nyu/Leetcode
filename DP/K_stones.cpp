
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>* answer; 
vector<int>* piles;

int find(int i){
    if ((*answer)[i] != -1) return (*answer)[i];
    int minval = 1;
    for (int val: (*piles)){
        if ((i - val) >= 0) minval = min(minval, find(i-val));
        else break;
    }

        
    int status = 1 - minval;
    (*answer)[i] = status;
    return status;

}
    

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> status(K+1, -1);
    status[0] = 0; //0 means lose if you get it 
    vector<int> pile;
    int val;

    answer = &status;
    piles = &pile;

    for (int i = 0; i < N; i++){
        cin >> val;
        pile.push_back(val);
    }

    sort(pile.begin(), pile.end());

    int win = find(K);
    string thing = (win == 1)? "First": "Second";
    cout << thing;
}






