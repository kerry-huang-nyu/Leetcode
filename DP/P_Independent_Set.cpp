#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = pow(10,9) + 7;

void dp(vector<long long>& w, vector<long long>& b, vector<vector<long long>>& adj, long long tgt){ //only solve if it is still -1. otherwise do not 
    //if (w[tgt] != -1) return; //don't calculate if already done before 
    //should not even be run let me run this to see if there are any issues here? 
    
    //1 means we are considering it and coming from it. this is done to avoid cyclic associations 
    //doubles as what we need to calculate the ending
    b[tgt] = 1; 
    w[tgt] = 1; 

    vector<long long> depend;
    for (int i: adj[tgt]){
        if (w[i] != -1) continue; //skip over times when it is considered already 

        //all of our children need to be dp. there is no other way to get to them otherwise 
        dp(w, b, adj, i); //find the dp for it first 
        depend.push_back(i); //lists all of our ready dependencies 
    }

    //now it is time to dp through our dependencies for black. chooes only white values
    for (int val: depend){
        b[tgt] = (b[tgt] * w[val]) % MOD;
        w[tgt] = (w[tgt] * ((w[val] + b[val]) % MOD) ) % MOD;
    }

    // cout << " this is for the target of " << tgt << endl;
    // for (long long i = 0; i < w.size(); i++){
    //     cout << w[i] << " ";
    // }
    // cout << endl;
    // for (long long i = 0; i < w.size(); i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;

}



int main(){
    int N, start, end;
    cin >> N;

    //inputs we were given are going to be starting from 1 but i will start from 0 
    vector<vector<long long>> adjlst(N); 
    vector<long long> white(N, -1); 
    vector<long long> black(N, -1);

    for (int i = 0; i < N-1; i++){ //generate adjlst 
        cin >> start >> end;
        start--;
        end--;
        adjlst[start].push_back(end);
        adjlst[end].push_back(start);
    }

    // cout << endl;
    // for (long long i = 0; i < adjlst.size(); i++){
    //     cout << i << ": ";
    //     for (long long j = 0; j < adjlst[i].size(); j++){
    //         cout << adjlst[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dp(white, black, adjlst, 0);

    cout << (white[0] + black[0]) % MOD;
    return 0;
}

