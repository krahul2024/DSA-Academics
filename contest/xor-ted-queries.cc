// This problem requires knowledge of sorting based on custom comparison and prefix sum.
// Read more about prefix sum : https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
// Read more about custom comparators: 
// for c++ :  https://www.geeksforgeeks.org/comparator-class-in-c-with-examples/?ref=gcse
// for java : https://www.geeksforgeeks.org/comparator-interface-java/
// for python: https://everythingtech.dev/2021/09/how-to-python-sort-custom-comparator/

// Why do we need custom sorting in this problem?

// Well, we have to first sort the array of triples according to xort(triple) after that we need to sort triples such that they are also in non-decreasing order which is 
// Let two triples are triple1, triple2 then two triples are sorted in non-decreasing order iff following condition holds.
// triple1.a<=triple2.a && triple1.b<=triple2.b && triple1.c<=triple2.c this means triple1<=triple2.

// So for sorting with these requirements we need to define our custom sorting algorithm or use builtin sorting algorithm with something called custom comparator. You can read more following the link provided above.

// After the array of triples is sorted we can do simple prefix summing and return answer for mentioned range in the query.

// Code for the same in c++:

#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct triple {
    int a, b, c;
} typedef triple;

int xort(triple tr) {
    int ans = (tr.a ^ tr.b) + (tr.b ^ tr.c) + (tr.c ^ tr.a);
    return ans;
}
bool comp(triple tr1, triple tr2) {
    if (xort(tr1) == xort(tr2)) {
        if (tr1.a == tr2.a) {
            if (tr1.b == tr2.b)return tr1.c < tr2.c;
            return tr1.b < tr2.b;
        }
        return tr1.a < tr2.a;
    }
    return xort(tr1) < xort(tr2);
}
signed main() {
    int n; cin>>n; vector<triple>a(n);
    for(int i=0;i<n;i++)cin>>a[i].a>>a[i].b>>a[i].c;

    vector<int>ans(n+1,0);
    sort(begin(a),end(a),comp);
    for(int i=1;i<=n;i++)ans[i]+=(ans[i-1]+a[i-1].a+a[i-1].b+a[i-1].c);    

    int Q; cin>>Q;
    while(Q--){
        int l,r; cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<'\n';
    }
    return 0;
}

// Time Complexity: O(nlogn +Q) , n is size of the array and Q is number of queries
