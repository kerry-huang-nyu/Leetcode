
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<long long>>* win_pt;
vector<int>* gem_pt;


long long helper(int i, int j, long long total){
    if ((*win_pt)[i][j] != -1) return (*win_pt)[i][j];
    long long val;
    if (i == j){
        val = (*gem_pt)[i];
    }
    else{
        val = max(total - helper(i+1, j, total - (*gem_pt)[i]), 
                total - helper(i, j-1, total - (*gem_pt)[j]));
    }

    (*win_pt)[i][j] = val;
    //cout << " from " << i << " to " << j << " gives "<< (*win_pt)[i][j]  << " with total " << total << endl;
    return val; 
}

int main(){
    int N;
    cin >> N;

    vector<int> gems;
    gem_pt = &gems;
    vector<vector<long long>> gains(N, vector<long long>(N, -1));
    win_pt = &gains;
    //gains tracks the value you can win from getting that position and going first 
    //establish a matrix using 1/2 of the spaces for integer start and ends 
    
    for (int i = 0; i < N; i ++){
        int val;
        cin >> val;
        gems.push_back(val);
    }

    long long total = 0;
    for (int val : gems){
        total += val;
    }

    //cout <<" total "<< total << endl;

    long long i_gained = helper(0, N-1, total);
    long long opponent_gained = total - i_gained;

    cout << i_gained - opponent_gained;

    //cout << total << endl;
    

    
}