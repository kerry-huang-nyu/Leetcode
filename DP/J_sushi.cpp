#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//i need to have a 3d array? 
 
vector<vector<vector<double>>>* mat; //declare a global variable to increase efficiency 
int N; //double to discourage integer conversion 

double dp(vector<int> v){
    if ((*mat)[v[0]][v[1]][v[2]] != -1){ //already dp through this 
        return (*mat)[v[0]][v[1]][v[2]];
    }

    double empty_plates = N - (v[0] + v[1] + v[2]);
    double c = empty_plates/N; //let c be the coefficient for the recurrence term 
    double recip = 1/(1 - c); //recriprocal of all terms 
    
    double total = 0;
    if (v[0] != 0) total += double(v[0])/N * (1 + dp({v[0]-1, v[1], v[2]}));
    if (v[1] != 0) total += double(v[1])/N * (1 + dp({v[0]+1, v[1]-1, v[2]}));
    if (v[2] != 0) total += double(v[2])/N * (1 + dp({v[0], v[1]+1, v[2]-1}));
    if (empty_plates != 0) total += c;
        
    total *= recip;
    (*mat)[v[0]][v[1]][v[2]] = total;
    //cout << v[0] << ", " << v[1] << ", " << v[2] << " :   " << empty_plates << " " << c << " " << recip << "        total: " << total << endl;
    //print("v1, v2, v3", (v1, v2, v3), "  ", empty_plates, c, recip,"     total: ", total)
    return total;
       
}

int main() {

    int val;
    cin >> N;
    vector<int> tupl(3, 0);

    for (int i = 0; i < N; ++i ){
        cin >> val;
        tupl[val-1] ++;
    }

    const int DIMENSION = N + 1;

    vector<vector<vector<double>>> matrix(DIMENSION, 
        vector<vector<double>>(DIMENSION, 
        vector<double>(DIMENSION, -1))); //gets -1 
    
    matrix[0][0][0] = 0;
    mat = &matrix;

    /*
    for (auto row: matrix){
        for (auto col: row){
            for (auto val : col){
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    cout << fixed << setprecision(9) << dp(tupl);
    
}

/*
def dp(v1, v2, v3):
    
    if (v1 == 0 and v2 == 0 and v3 == 0):
        return 0
    
    empty_plates = N - (v1 + v2 + v3)  
    c = empty_plates/ N #let c be the coefficient for the recurrence term 
    recip = 1/(1 - c) #recriprocal of all terms 
    
    total = 0 
    if v1:
        total += v1/N * (1 + dp(v1-1, v2, v3))
    if v2:
        total += v2/N * (1 + dp(v1+1, v2-1, v3))
    if v3:
        total += v3/N * (1 + dp(v1, v2+1, v3-1))
    if empty_plates: #there are empty plates 
        total += c
    total *= recip 
    #print("v1, v2, v3", (v1, v2, v3), "  ", empty_plates, c, recip,"     total: ", total)
    return total

    #can do some optimization when it is homogeneous just v1 

print(dp(tupl[0], tupl[1], tupl[2]))*/




