#include<iostream>
using namespace std;
const int mod = 1e9 + 3;
char m[51][51], ans[51][51];
int f(int i, int j, int h, int w) {
	if(ans[i][j]!=-1) return ans[i][j];
	int best = 1;
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
			if (!(x == 0 and y == 0)) {
				int ind1 = x + i, ind2 = y + j;
				if (ind1 >= 0 and ind1 < h) {
					if(ind2>=0 and ind2<w){
						if(m[ind1][ind2]==m[i][j]+1)best = max(best , 1+f(ind1,ind2,h,w));
					}
				}
			}
	return ans[i][j]=best ;
}
signed main() {
	int h, w,count =1;
	while (cin >> h and h > 0) {
		cin >> w;
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> m[i][j];
		// for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cout << m[i][j] << (j == w - 1 ? '\n' : ' ');
		for (int i = 0; i <= h; i++) for (int j = 0; j <= w; j++) ans[i][j] = -1;
		//calling the function a
		int value = 0;
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++) {
				if (m[i][j] == 'A') {
					//call the function
					value = max(value , f(i,j,h,w));
				} 
			}
		cout<<"Case "<<count++<<": "<<value<<'\n';

	}

}
