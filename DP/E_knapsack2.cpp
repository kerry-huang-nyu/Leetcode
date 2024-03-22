
#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
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

    sort(gems.begin(), gems.end()); 
    //sort such that we built up the values from a pt where earlier values are sure to come before 
    
    vector<pair<size_t, size_t>> answer;
    answer.push_back({0,0}); //first value is empty <0,0> 

    vector<pair<size_t, size_t>> new_answer;
    new_answer.push_back({0,0});
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, std::greater<pair<size_t, size_t>>> pq; //contains values to insert into new_answer created from combining gems and pairs 


    for (pair<size_t, size_t> gem : gems){ //take out each gem 
        //std::cout << gem.first << "    "<< gem.second << endl;

        for (pair<size_t, size_t> curr_pair : answer){ 
            //std::cout << "curr pair " << curr_pair.first << ", " << curr_pair.second << endl;

            while (pq.size() > 0){ //inserts all values if weight is less than pair 
                //cout << " ishoudl not be in this loop";
                if (pq.top().first <= curr_pair.first){ //<= to add and equal or improved version at the same index  
                    new_answer.push_back(pq.top());
                    pq.pop();
                }
                else break; 
            }

            //if we qualify to be in here then put ourselves in here 
            pair<size_t, size_t> prev = new_answer[new_answer.size()-1];
            if (prev.second < curr_pair.second){ //self must be an improvement to be added. equal is already in there  
                new_answer.push_back(curr_pair);
            }

            //generate the next pair and check if it should be in pq 
            //next pair must be better than anything else in the pq already 
            //only need to check the answer and see if its better. binary search the answer 
            //for location nextpair should be in then see if its an improvement 

            pair<size_t,size_t> next_pair = {gem.first + curr_pair.first, gem.second + curr_pair.second};
            if (next_pair.first <= W){ //weight constraint is satisfied 
                auto lower = lower_bound(answer.begin(), answer.end(), next_pair); //find the lower bound of next pair 
                //if nextpair is found, then put in next_pair 
                //lower is an iterator 
                if ((lower-1)->second < next_pair.second){ //don't do anything if its not an improvment from the smaller value 
                    pq.push(next_pair);
                }
            }
        }

        //put in all the values left in pq 
        while (pq.size() > 0){
            new_answer.push_back(pq.top());
            pq.pop();
        }

        /*
        cout << "current state of new_answer    ";
        for (auto gem : new_answer){
            cout << gem.first << ", " << gem.second << "        ";
        }
        cout << endl;*/

        swap(answer, new_answer); //this should be making a swap that is not going to do N operations right?
        new_answer.clear();
        new_answer.emplace_back(0,0);
    }

    cout << answer[answer.size()-1].second;

    /*
    for (auto gem : gems){
        cout << gem.first << "   " << gem.second << endl;
    }*/
}




