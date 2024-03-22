
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> height(N, -1); //height now starts at 0 and goes up forwards 
    vector<int> beauty_ind(N, -1); //beauty sorted by index 

    for (int i = 0; i < N; i++){
        cin >> height[i];
        height[i]--; //normalize the height 
    }
    for (int i = 0; i < N; i++){
        cin >> beauty_ind[i];
    }

    vector<int> index(N, -1); //beauty sorted by height 
    for (int i = 0; i < N; i++){
        index[height[i]] = i; 
    }

    //------------------------------------- parse the data 

	set<pair<int,long long>> bst;

	bst.insert({N, 0}); //the largest is 0 and then we replace all that is smaller 

	// for (auto it=bst.begin(); it!=bst.end(); ++it) {
	// 		cout << "<"<<(*it).first << " " << (*it).second << ">   ";
	// 	}
	// cout << endl;


    for (int i = N-1; i > -1; i--){ //go through the beauty sorted by height 
        int ind = index[i]; //index used as keys into the tree 

        auto bigger_it = bst.upper_bound({ind, 0}); 

        long long beauty = beauty_ind[ind];
        beauty += (*bigger_it).second;

		
        auto lesser_it = bst.lower_bound({ind, 0});
		
        while (lesser_it != bst.end() && lesser_it != bst.begin()){
			lesser_it --;

            if ((*lesser_it).second <= beauty){
                bst.erase(lesser_it);
            }
            else{
                break;
            }
            lesser_it = bst.lower_bound({ind,0});
        }

		

		//cout << "inserting at i = " << i << " where ind is " << ind << "  " << beauty << endl;
        bst.insert({ind, beauty});

		
		// for (auto it=bst.begin(); it!=bst.end(); ++it) {
		// 	cout << "<"<<(*it).first << " " << (*it).second << ">   ";
		// }
		// cout << endl;

    }
    
    auto minnode = bst.begin();
    //cout << " this is min node beauty: " << minnode->beauty << endl;

    cout << (*minnode).second;

	return 0;
}