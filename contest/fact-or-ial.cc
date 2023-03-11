// Proof: There is no formal proof for this problem, but we can use properties of bitwise OR operation. 
//   We have total 10 digits from 0,1,....,8,9 and bitwise OR of all the digits is 15. 
//   If we calculate factorial of numbers greater than 40 we can see that all the digits are present in 
//   factorial of any number greater than 40. If anyone wants to see if all digits are present or not for factorial of 
//   numbers greater than 40 , use following code.
// Code for factorial calculation upto 3000 is given below , interested people can edit it for this problem.
#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n, rem = 0, x = 0, k, i;
  cout << "Enter the number (should be less than 3000) you want to find factorial of :";
  cin >> n;
  vector<int>a(9300, 0);
  //setting the last digit to one
  a[a.size() - 1] = 1;
  for (i = 1; i <= n; i++) {
    k = a.size() - 1, rem = 0;
    //doing multiplication and updating the next values by adding remainder to them
    while (k >= 0)x = a[k] * i + rem, a[k] = x % 10, rem = x / 10, k--;
  }
  i = 0;
  while (!a[i])i++;
  cout << "\nFactorial of the number " << n << " is :\n";
  for (; i < a.size(); i++)cout << a[i];
  cout << '\n';
}
int32_t main() {
  int t=1;
  while(t){
    solve();
    char c;
    cout<<"Enter n/N if you want to exit :";
    if(c=='n' or c=='N')t--;
  }
}

// For numbers less than 40 we can observe some pattern using above code.

// Another Approach: Observation...
// If we calculate factOR for each of the numbers from 0 to 9 we get following result: {0,1,2,6,6,3,7,5,7,15}
// If we calculate factOR for any number greater than 9 , the result is 15, and even if someone calculates for numbers
// from 0 to 20 they will observer the pattern of appearance of 15, and can easily answer this problem.
// Again we have to take string of integers as input as we know the answer for any string of length greater than 1 is 15.


// Solution in c++:

#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main(){
    int factorial[10]={0,1,2,6,6,3,7,5,7,15};
    int n; cin>>n; //for number of queries
    for(int i=0;i<n;i++){
        string s; cin>>s;//taking string of integers as input because we can't store more than 20 digits in integer.
        if(s.size()==1) cout<<factorial[s[0]-'0']<<'\n';//in case of single digits
        else cout<<15<<'\n';//otherwise the answer will be 15 always
    }
    
}

// Time complexity: O(N*|s|) max size of the string.




