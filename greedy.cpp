#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;


/* 
//gfg choclate distribution problem

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for (int i=0,j=m-1;j<a.size();i++,j++){
            ans=min(ans,a[j]-a[i]);
        }
        return ans;
    }
};

*/


/* gfg

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        int ans=1;
        
        // priority_queue<pair<int,int>,greater<int> > q;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        // end,start
        for(int i=0;i<n;i++){
            q.push({end[i],start[i]});
        }
        
        // pahla wala push maro
        auto a=q.top();
        q.pop();
        auto oend=a.first;

        for (int i=1;i<n;i++){
            auto a=q.top();
            q.pop();
            if(a.second>oend){
                ans+=1;
                oend=a.first;
            }
        }
        return ans;
    }
};

*/

/* gfg
class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double solve(vector<int>& val, vector<int>& wt, int cap, int n) {
        // Max heap sorted by value/weight ratio
        priority_queue<pair<float, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            float ratio = (val[i] * 1.0) / wt[i];
            q.push({ratio, {val[i], wt[i]}});
        }

        double ans = 0.0;
        while (cap > 0 && !q.empty()) {
            auto front = q.top();
            q.pop();
            float ra = front.first; // Fix typo here
            int value = front.second.first;
            int weight = front.second.second;

            // If we can take the full item
            if (cap >= weight) {
                ans += value;  // Take full value
                cap -= weight;
            }
            // If we can take only a fraction
            else {
                ans += cap * ra; // Take fractional value
                cap = 0;
                break;
            }
        }
        return ans;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        return solve(val, wt, capacity, n);
    }
};
*/

/* gfg 
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int solve(vector<int>& arr,int n){
        priority_queue<int,vector<int>,greater<int> > q;
        for (int i=0;i<n;i++){
            q.push(arr[i]);
        }
        int ans=0;
        int i;
        int j;
        while(q.size()>1){
            i=q.top();
            q.pop();
            j=q.top();
            q.pop();
            ans+=i+j;
            q.push(i+j);
        }
        return ans;
    }
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n);
    }
};
*/

int main(){


    int row = 8;
    int col = 15;
    int tower = 3;

    vector<pair<int, int> > loc;
    loc.push_back(make_pair(3, 8));
    loc.push_back(make_pair(11, 2));
    loc.push_back(make_pair(8, 6));


	vector<int> xDim;
	xDim.push_back(0);
	xDim.push_back(col + 1);
	for(int i=0; i<loc.size(); i++){
		xDim.push_back(loc[i].first);
	}
	sort(xDim.begin(), xDim.end());

	vector<int> yDim;
	yDim.push_back(0);
	yDim.push_back(row + 1);
	for(int i=0; i<loc.size(); i++){
		yDim.push_back(loc[i].second);
	}
	sort(yDim.begin(), yDim.end());

	vector<int> xAns;
	for(int i=1; i<xDim.size(); i++) {
		int diff = xDim[i] - xDim[i-1] - 1;
		xAns.push_back(diff);
	}

	vector<int> yAns;
	for(int i=1; i<yDim.size(); i++) {
		int diff = yDim[i] - yDim[i-1] - 1;
		yAns.push_back(diff);
	}

	int maxi = -1;
	for(int i=0; i<xAns.size(); i++) {
		for(int j=0; j<yAns.size(); j++) {
			int prod = xAns[i] * yAns[j];
			maxi = max(maxi, prod);
		}
	}
	cout << "final ANs: " << maxi << endl;


}