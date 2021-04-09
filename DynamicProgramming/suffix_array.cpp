
#include<bits/stdc++.h>
using namespace std;

const int max_n = 100010;

string s;
int n;
int sa[max_n], tempsa[max_n];
int ra[max_n], tempra[max_n];
int c[max_n];

void countingsort(int k){
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for(i =0; i<n; ++i){
        c[i+k<n? ra[i+k] : 0]++;
    }
    for(i=sum=0; i<maxi; ++i){
        int t =c[i];
        c[i] =sum;
        sum+=t;
    }
    for(i = 0; i<n; ++i){
        tempsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
    }
    for(i=0; i<n; ++i){
        sa[i]=tempsa[i];
    }
}

void construct_suffix_array(){
    for(int i=0; i<n; ++i){
        ra[i]=s[i]-'.';
    }
    for(int i=0; i<n; ++i){
        sa[i]=i;
    }
    int r, k;
    for( k=1; k<n; k<<=1){
        countingsort(k);
        countingsort(0);
        tempsa[sa[0]]=r=0;
        for(int i=1; i<n; ++i){
            tempra[sa[i]] = (ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])? r: ++r;
        }
        for(int i=0; i<n; ++i){
            ra[i]=tempra[i];
        }
    }
}

int *lcp_kasai(int *lcp){
    for(int i=0; i<n; ++i){
        lcp[i]=0;
    }
    int invsuffix[n];
    for(int i=0; i<n; ++i){
        invsuffix[sa[i]]=i;
    }
    int k=0;
    for(int i=0; i<n; ++i){
        if(invsuffix[i]== n-1){
            k=0;
            continue;
        }
        int j = sa[invsuffix[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[invsuffix[i]]=k;
        if(k>0) k--;
    }
    return lcp;
}

pair<int, int> search(){
    int l=0, h=n-1, mid=l;
    string x; x=s.substr(0, 1);
    cout<<x<<endl;
    while(l<h){
        mid = (l+h)/2;
        string ss = s.substr(sa[mid]);
        int res = ss.compare(0, x.size(), x, 0, x.size());
        if(res>=0){
            h=mid;
        }else{
            l=mid+1;
        }
    }
    string ss = s.substr(sa[l]);
    int m = ss.size();
    if(ss.compare(0, x.size(), x, 0, x.size()) !=0){
        return pair<int, int>({-1, -1});
    }
    pair<int, int> ans;
    ans.first = l;
    l=0; h=n-1; mid = l;
    while(l<h){
        mid = (l+h)/2;
        string ss = s.substr(sa[mid]);
        int m = ss.size();
       int res = ss.compare(0, x.size(), x, 0, x.size());
        if(res>0){
            h=mid;
        }else{
            l=mid+1;
        }
    }
    ss = s.substr(sa[h]);
     m = ss.size();
    if(ss.compare(0, x.size(), x, 0, x.size()) !=0){
        h--;
    }
    ans.second = h;
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin>>s;
    n =(int)s.size();
    construct_suffix_array();
    pair<int, int> ans = search();
    int *lcp = new int[n];
    lcp = lcp_kasai(lcp);
    // for(int i=0; i<n; ++i){
    //     cout<<lcp[i]<<"\t"<<s.substr(sa[i])<<"\n";
    // }
    // cout<<ans.first<<"\t"<<ans.second<<"\n";

    int sum = n;
    for(int i=ans.first; i<=ans.second; ++i){
        sum+=lcp[i];
    }
    cout<<sum<<"\n";

    return 0;
}
