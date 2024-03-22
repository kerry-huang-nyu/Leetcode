#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main(){
    int N, K, val;
    cin >> N >> K;
    vector<long long> limits;
    int mod = pow(10, 9) + 7;
    //cout << mod;
    
    for (int i = 0; i<N; ++i){
        cin>>val;
        limits.push_back(val);
    }

    //sort(limits.begin(), limits.end());
    //vector<int>::iterator most = max_element(limits.begin(), limits.end());

    vector<long long> prev(K+1, 0); 
    vector<long long> curr(K+1, 0);
    prev[prev.size() - 1] = 1; 

    for (int i = 0; i<N; i ++){ //iterate  through the children 
        long long lim = limits[i];
        long long total = 0;
        for (int k = 0; k < lim + 1; ++k){
            total += prev[k];
            total = total % mod;
        }
        //size_t total = accumulate(prev.begin(), prev.begin() + lim + 1, 0) % mod; //accumulation here 
        
        for (int j = 0; j<curr.size(); ++j){ //iterate within the children 
            curr[j] = total % mod; 
            //cout << "j " << j <<" lim "<< lim << "   total "<< curr[j] << endl;

            total = (total - prev[j] + mod) % mod;
            if ((j + lim + 1) < curr.size()) {
                total += prev[j+lim + 1];
                total = total % mod;
            }
        }

        swap(prev, curr);
    }
    cout << prev[0];
}