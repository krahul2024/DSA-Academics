#include<bits/stdc++.h>
using namespace std;
vector<int>multiply(vector<int>a, int k) {
	vector<int>ans = a;
	ans.push_back(0);//for adding the remainder if there is one
	int value = 0;
	for (int i = ans.size() - 2; i >= 0; i--)value += ans[i] * k, ans[i + 1] = value % 10, value /= 10;
	ans[0] = value; //last value will be either 0 or some remainder from recent multiplication
	return ans;
}

vector<int>sum(vector<int>a, vector<int>b) {
	int i = a.size() - 1, j = b.size() - 1, value = 0;
	vector<int>ans(max(a.size(), b.size()) + 1, 0);
	while (i >= 0 and j >= 0) value += a[i] + b[j], ans[i + 1] += value % 10, value /= 10, i--, j--;
	while (i >= 0) value += a[i], ans[i + 1] += value % 10, value /= 10, i--;
	while (j >= 0) value += b[j], ans[j + 1] += value % 10, value /= 10, j--;
	ans[0] = value;
	return ans;
}

int main() {
	bool yes=1;
	while (yes) {
		cout << "Enter two numbers with less then 5000 digits:\n";
		string s1, s2; cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		vector<int>a(n), b(m), ans, temp;
		for (int i = 0; i < n; i++)a[i] = s1[i] - '0';
		for (int i = 0; i < m; i++)b[i] = s2[i] - '0';
		ans = multiply(a, b[m - 1]);
		for (int i = m - 2; i >= 0; i--) {
			a.push_back(0);
			temp = multiply(a, b[i]);
			ans = sum(temp, ans);
		}
		string product = "";
		int i = 0; char c;
		while(ans[i]==0)i++;
		for (i; i < ans.size(); i++)product += to_string(ans[i]);
		cout << "Product of "<<s1<< " and "<<s2<<" is\n" << product << "\nIf you want to exit enter n or N else press any key:";
		cin>>c;if(c=='n' or c=='N')yes=0;
	}
	cout<<"Exited...\n";
	return 0;
}
