
#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    size_t N, W;
    cin >> N >> W; //get our values 

    //cout << "N: " << N << " W " << W << endl;
    int weight, gains; 

    vector<pair<size_t,size_t>> gems(N); //should only have N values. avoids resizing and copying 

    for (size_t i = 0; i < N; ++i){
        cin >> weight >> gains;
        //cout << "weight "<< weight <<" gains "<< gains;
        gems[i] = make_pair(weight, gains);
    }

    vector<size_t> answer(W+1, 0); //[0, W] inclusive on both sides 

    for (size_t i = 0; i < N; ++i){

        //pair<int,int> gem = gems[i];
        //cout << "hellllllllllllo" << endl;
        //cout <<" gems[i].first "<< gems[i].first;

        for (size_t j = W; j >= gems[i].first; --j){

            //cout << "j " << j << " i " << i;
            answer[j] = max(answer[j], gems[i].second + answer[j - gems[i].first]);

        }
    }

    //cout << "i got here at least";
    cout << answer[answer.size() - 1 ];
}




