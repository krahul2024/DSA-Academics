// This is somewhat like a greedy problem and There are various ways/solutions for solving this problem.
// We are allowed to flip any range as long as it starts from 1st element. From this we get one thing which is there is exactly one valid range of each length. Flipping a range twice doesn't help at all, as first time we will make 1 to 0 and second time again 0 to 1. 
// Let's say we are given this array : 1 1 0 0 0 , after one flip of range (1,5) the array is 0 0 1 1 1, one thing to notice is we can reduce above array to 1 0 and it will not affect our result at all.
// So far, we have seen that we can reduce consecutive 0s or 1s to a single 0 or 1 as in one flip we flip all consecutive 0s or 1s so no problem in reducing them to just single 0 or 1.
// One more thing, if the array is something like this 1 0 1 0 1 1 1 1 , then last 4 indexes already have 1s so we don't care about these as well, let's call these redundant 1s.

// so after all these exclusions and theories we will get all possible structures like following ones.
// array 1: 0 ----> 1 operation
// array 2 : 1 0 ------> 2 operations 
// array 3: 1 0 1 0 ----->4 operations
// array 4: 0 1 0 ------> 3 operations

// and for all these variations, we will have alternate appearances of 0s and 1s.
// Let's see for a=[1, 1, 0 ,0, 0, 1,1 ,1, 0,0,1,1,1] => a= [1,0,1,0]
// Initially a= 1 0 1 0
// flip range (1,4) so 4th element becomes 1 and rest are reversed: 0 1 0 1
// flip range (1,3) so 3rd element becomes 1 and rest are reversed: 1 0 1 1
// flip range (1,2) so 3rd element becomes 1 and rest are reversed: 0 1 1 1
// flip range (1,3) so 3rd element becomes 1 and rest are reversed: 1 1 1 1
// so four no. of operations are done. Now given the constraints we flip each range and change elements like this.
// We can observe that our answer each time is number of alternations (1 0 is one alternation) +1;
// We can also say that answer is size of the compressed array after all exclusions.

// code for the same in c++:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=1,first=a[0],second,min_index=n-1;
    while(min_index>=0){
        if(a[min_index]==0)break;
        min_index--;
    }
    if(min_index<0){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=min_index;i++){
        second=a[i];
        ans+=(first^second);
        first=second;
    }
    cout<<ans<<'\n';
}

// Time complexity: O(N) , N is size of the array of 0s and 1s
