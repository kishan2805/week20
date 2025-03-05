#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

void evenodd(int n){
    if(n&1==1)  cout<<"even";
    else    cout<<"odd"; 
}

void getIthBit(int n,int i) {
	int mask = (1 << i);
	int ans = n & mask;
	if(ans == 0) {
		cout << "bit-> 0" << endl;
	}
	else {
		cout << "bit-> 1" << endl;
	}
}

void setIthBit(int n, int i) {
	int mask = (1<<i);
	n = n | mask;
	cout << "Updated number: " << n << endl;
}

void clearIthBit(int &n, int i) {
	int mask = ~(1<<i);
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

void udpateIthBit(int n, int i, int target) {
	//clear ith bit
	clearIthBit(n, i);
	//cout << "after clearing: " << n;
	//create mask
	int mask = (target << i);
	//update n
	n = n | mask;
	cout << "Updated number: " << n << endl;
}

/* //leet 136
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        if(nums.size()<2)   return nums[0];
        for (int i=0;i<nums.size();i++){
            ans=ans^nums[i] ;
        }
        return ans;
    }
};
*/

void clearLastIBits(int n, int i) {
	int mask = (-1 << i);
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

bool checkPowerOf2(int n) {
	//count set bit
	int count = 0;

	while(n != 0 ) {
		int lastbit = n & 1;
		if(lastbit) {
			count++;
		}
		n = n >> 1;
	}

	if(count == 1 ){
		return true;
	}
	else {
		return false;
	}	
}

bool fastCheckPowerOf2(int n) {
	if((n & (n-1)) == 0)
		return true;
	else 
		return false;
}

int fastCOuntSetBits(int n) {
	int count = 0;
	while(n != 0) {
		//cout << "n value: " << n << endl;
		count++;
		n = (n & (n-1));
	}
	return count;
}
void clearBitsInRange(int n, int i, int j) {
	int a = (-1 << (i+1));
	int b = ~(-1 << j);
	int mask = a | b;
	n = n & mask;
	cout << "Updated number: " << n << endl;
}


void getSubsequences(string str) {
	int n = str.length();
	vector<string> ans;
	for(int num = 0; num < (1<<n); num++ ) {
		//number is ready
		//use num, to create subsequences

		//num -> set bit -> index -> char -> incl
		string temp = "";
		for(int i=0; i<n; i++) {
			//i -> represent index
			char ch = str[i];
			//agar i index pr num k andar set bit present hai
			//toh character ko include krdlo
			int mask = (1 << i);
			if(num & mask) {
				temp.push_back(ch);
			}
		}
		ans.push_back(temp);
	}

	cout << "printing the subsequences: " << endl;
	for(auto i: ans) {
		cout << i << endl;
	}
}


int main(){
    int n=5,i=3,target=0,j=2;
    // evenodd(5);

    // getIthBit(5,2);

    // setIthBit(n,i);
    // clearIthBit(n,i);
    //udpateIthBit(n, i, target);

    // cout<<checkPowerOf2(n);
    // cout<<fastCheckPowerOf2(n);


    // int ans=fastCOuntSetBits(n);
    // if(ans==1)  cout<<"yes";
    // else    cout<<"no";


    // keep in mind i>j 
    clearBitsInRange(n,i,j);
    


 

}