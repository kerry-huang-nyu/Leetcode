#include <algorithm>
#include <iostream> 
#include <string>
#include <vector>

using namespace std; 

int main(){

    string s, t;
    cin >> s >> t;

    vector<vector<int>> answer(t.size() + 1);

    for (int i = 0; i < answer.size(); ++i){
        vector<int> temp(s.size() + 1, 0);
        answer[i] = temp; //copy constructor used noooo inefficient must be a better way 
    }

    //cout << s << "    " << t;
    for (int i = 0; i < t.size(); ++i){
        for (int j = 0; j < s.size(); ++j){
            if (t[i] == s[j]){
                answer[i + 1][j + 1] = answer[i][j] + 1;
            }
            else{
                answer[i+1][j+1] = max(answer[i][j+1], answer[i+1][j]);
            }
        }
    }

    /*
    for (auto row: answer){
        for (auto val: row){
            cout << val << " ";
        }
        cout << endl;
    }*/

    int i = t.size();
    int j = s.size();

    string str = "";

    while (i > 0 && j > 0){
        //cout << "i: " << i << "     j: " << j << endl;
        if (answer[i][j] > max(answer[i][j-1], answer[i-1][j])){
            str += t[i-1]; 
            i--;
            j--;
        }
        else {
            if (answer[i][j] == answer[i][j-1]){ //came from the left 
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(str.begin(), str.end());
    cout << str; 
    //cout << "Hello from the other side";

}