#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;


vector<vector<long long>>* dp_ptr;
vector<int>* slim_ptr;
vector<long long>* accum_ptr; 

long long recurse(int i, int j){
    if (i == j){
        (*dp_ptr)[i][j] = 0;
        return 0;
    }

    if ((*dp_ptr)[i][j] != -1) return (*dp_ptr)[i][j];

    long long result = LLONG_MAX;
    long long answer;

    for (int loc = i+1; loc < j; ++loc){ //this is choosing the last value to accumulate  
        long long first = recurse(i, loc-1);
        long long second = recurse(loc+1, j);

        //first and second are costs for the accumulations 
        //val1 and val2 are the size of the slimes at that pt 
        long long val1 = (*accum_ptr)[loc-1] -  ((i-1 >= 0) ? (*accum_ptr)[i-1]: 0) ; //this is if i - 1 exists always as 0 
        long long val2 = (*accum_ptr)[j] - (*accum_ptr)[loc];

        answer = min(2 * (val1 + (*slim_ptr)[loc]) + val2, 
                        2 * (val2 + (*slim_ptr)[loc]) + val1) + first + second;
        
        /*
        if (i == 0 and j == 1){
            cout <<" first "<< first <<"   second "<< second << "    answer " << answer << endl;
        }*/
        
        result = min(result, answer);
    }

    //deal with edge cases where target is i and j 
    //curr val + other val + cost of other val 
    result = min(result, (*slim_ptr)[i] + ((*accum_ptr)[j] - (*accum_ptr)[i]) + recurse(i+1, j)); //target is i 
    result = min(result, (*slim_ptr)[j] + (*accum_ptr)[j-1] -  ((i-1 >= 0) ? (*accum_ptr)[i-1]: 0) + recurse(i,j-1));//target is j 

    (*dp_ptr)[i][j] = result;

    return result;
}


int main(){
    int N, val;
    vector<int> slimes;
    vector<long long> accum;
    long long total = 0;

    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> val;
        total += val;
        slimes.push_back(val);
        accum.push_back(total);
    }

    vector<vector<long long>> dp(N, vector<long long>(N, -1));
    dp_ptr = &dp;
    slim_ptr = &slimes;
    accum_ptr = &accum;

    cout << recurse(0, N-1);

/*
    for (auto row: dp){
        for (auto thing: row){
            cout << thing << " ";
        }
        cout << endl;
    }*/
}