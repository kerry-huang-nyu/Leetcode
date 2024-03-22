#include <iostream> 
#include <vector>
#include <algorithm>
#include <deque>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    //parse the data 
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> mat(N, vector(M, 0)); //nxm matrix at the start to store values 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> mat[i][j];
        }
    }


    //create n by k mat to store ultimate values. recurse through to find the best in matrix 
    vector<vector<int>> bestmat(N, vector(K, -1)); //-1 indicates cannot be added should be skipped 

    //create m//2 by k to stroe ultimate values for a row
    vector<vector<int>> bestrow(M/2 + 1, vector(K, -1));
    vector<vector<int>> temp; //store temporay values for the row finding 


    for (int row = 0; row < N; row++){ //go through each row within the mat 
        
        //clears the bestrow 
        for (int i = 0; i < M/2 + 1; i ++){
            for (int j = 0; j < K; j++){
                bestrow[i][j] = -1;
            }
        }
        bestrow[0][0] = 0;  //establishes baseline with no values 

        for (int col = 0; col < M; col++){ //for each row find the best row values 
            int currval = mat[row][col];

            for (int i = 0; i < M/2; i++){ //for each row not including the last 
                for (int j = 0; j < K; j++){
                    if (bestrow[i][j] != -1){ //valid cell then 
                        temp.push_back({bestrow[i][j] + currval, i+1, (bestrow[i][j] + currval)%K});
                    }
                }
            }

            //record the best for that row 
            for (vector<int>& vec: temp){ //put the best values into the 
                bestrow[vec[1]][vec[2]] = max(bestrow[vec[1]][vec[2]], vec[0]);
            }
            temp.clear();
        }

        

        for (int i = 0; i < M/2 + 1; i ++){
            for (int j = 0; j < K; j++){
                bestmat[row][j] = max(bestmat[row][j], bestrow[i][j]);
            }
        }
    }

    // for (vector<int>& row: bestmat){
    //     for (int val: row){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }


    vector<int> ans(K, -1);
    for (int row = 1; row < N; row++){ //starting at row 1 
        for (int col = 0; col < K; col++){
            if (bestmat[row][col] == -1) continue; //skip if it the current row's col val is -1. 
            for (int i = 0; i < K; i++){ //for each value in the previous row 
                if (bestmat[row-1][i] == -1) continue; //skip if the previous row has -1 
                //i is previous row, col is current row 
                ans[(col + i)%K] = max(ans[(col + i)%K], bestmat[row][col] + bestmat[row-1][i]);
            }
        }
        for (int i = 0; i < K; i ++){
            bestmat[row][i] = ans[i];
            ans[i] = -1;
        }

        // cout << endl;
        // for (int i = 0; i < N; i ++){
        //     for (int j = 0; j < K; j++){
        //         cout << bestmat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    cout << bestmat[N-1][0];

}

