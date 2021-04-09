#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c=0;

void backtrack(vector<vector<int>> &finalset, vector<int> &inputset, vector<int>& ccomb, int k, int csum, unsigned int pos){
    if(pos == inputset.size()) return;
    if(k==0){
        if(csum%2 == 0){
            finalset.push_back(ccomb);
            c++;
            return;
        }
    }

    backtrack(finalset, inputset, ccomb, k, csum, pos+1);
    ccomb.push_back(inputset[pos]);
    backtrack(finalset, inputset, ccomb, k-1, csum+inputset[pos], pos+1);
    ccomb.pop_back();
}




int combination(vector<int> &inputset, unsigned int ktimes){
    vector<int> ccomb;
    vector<vector<int>> finalset;
    backtrack(finalset, inputset, ccomb, ktimes,  0, 0); //sum, pos
    unsigned int m = finalset.size();
    return m;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


    int n1;
    int n2;
    cin>>n1>>n2;
    int k;
    cin>>k;

    vector<int> v;
    for(int i=min(n1, n2); i<=max(n1, n2); ++i){
        for(int j=0; j<k; ++j){
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());

    unsigned int l = v.size();
    int ans =  combination(v, k);
    cout<<ans<<endl;
    cout<<c<<endl;


	return 0;
}
