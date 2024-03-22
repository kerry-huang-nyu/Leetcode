#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> mat;
vector<int> compatible;
int mod = pow(10, 9) + 7;

int recurse(int i, int val){ //i contains the location of the thing 
    //val is almost a mask of the answer in a sense 
    //cout << "reached i " << i << "  val " << val << endl;
    if (compatible[val] != -1) return compatible[val]; //we already know the value 

    int total = 0;
    int start = 1; 
    for (int j = mat.size()-1; j >= 0; --j){
        int newval = (~start) & val;
        //cout << "new val is " << newval << endl;

        if (((newval) != val) && (mat[j][mat.size()- 1 - i] == 1)){  
            //cout << " i got inttttt";
            //cout << "i is " << mat.size()- 1 - i << " j is then " << j << endl;
            total = (total + recurse(i+1, newval)) % mod;
        }
        start *= 2; 
    }

    compatible[val] = total;

    return total;
}


int main(){
    int N, val;
    cin >> N;
    int K = int(pow(2, N));
    int K_1 = K-1;

    mat.resize(N, vector<int>(N, 0));
    compatible.resize(K, -1);
    compatible[0] = 0;

    for (int i = 0; i < N; i++){ //initializes the matrix 
        for (int j= 0; j < N; j++){
            cin >> val;
            mat[i][j] = val;
        }
    } 

    //initializes the base cases for each thing 
    int i = 1; 
    for (int j = mat.size()-1; j >= 0; --j){
        compatible[i] = mat[j][0]; 
        i *= 2;
    }
    

    cout << recurse(0, K_1);

    /*
    for (int i = 0; i < K; ++i){
        cout << compatible[i] << " ";
    }*/

    
}