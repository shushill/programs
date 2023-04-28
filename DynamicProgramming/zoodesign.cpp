#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    ll costofHerb, costofCarn, costofAqua;
    ll maxArHerb, maxArCarn, maxArAqua;
    ll mintypeofHerb, minArforHerbtype;
    ll mintypeofCarn, minArforCarn;
    ll mintypeofAqua, minArforAqua;
    ll totalArea;

    ll maxArAllocHerb, maxArAllocCarn, maxArAllocAqua;
    ll totalCost;

    cin>>costofHerb>>costofCarn>>costofAqua;
    cin>>maxArHerb>>maxArCarn>>maxArAqua;
    cin>>mintypeofHerb>>minArforHerbtype;
    cin>>mintypeofCarn>>minArforCarn;
    cin>>mintypeofAqua>>minArforAqua;
    cin>>totalArea;

    bool flag = false;
    if(costofHerb> max(costofCarn, costofAqua)){
        maxArAllocHerb = mintypeofHerb * minArforHerbtype;
        if(costofAqua < costofCarn){
            maxArAllocAqua = maxArAqua;
            flag = true;
        }else{
            maxArAllocCarn = maxArCarn;
        }
        if(flag) {
            maxArAllocCarn = (totalArea -(maxArAllocHerb + maxArAllocHerb));
        }else {
            maxArAllocAqua = (totalArea - (maxArAllocHerb + maxArAllocCarn));
        }

        totalCost = maxArAllocHerb * costofHerb + maxArAllocAqua * costofAqua + maxArAllocCarn * costofCarn;

    }else if( costofCarn>max(costofHerb, costofAqua)){
        maxArAllocCarn = mintypeofCarn * minArforCarn;
        if(costofAqua < costofHerb){
            maxArAllocAqua = maxArAqua;
            flag = true;
        }else{
            maxArAllocHerb = maxArHerb;
        }
        if(flag) {
            maxArAllocHerb = (totalArea -(maxArAllocCarn + maxArAllocAqua));
        } else {
            maxArAllocAqua = (totalArea - (maxArAllocCarn + maxArAllocHerb));
        }
        totalCost = maxArAllocHerb * costofHerb + maxArAllocAqua * costofAqua + maxArAllocCarn * costofCarn;

    }else{
        maxArAllocAqua = mintypeofAqua * mintypeofAqua;
        if(costofHerb<costofCarn){
            maxArAllocHerb = maxArHerb;
            flag = true;
        }else{
            maxArAllocCarn = maxArCarn;
        }
        if(flag) {
            maxArAllocCarn = (totalArea - (maxArAllocHerb + maxArAllocAqua));
         } else {
             maxArAllocHerb = (totalArea - (maxArAllocAqua + maxArAllocCarn));
         }
        totalCost = maxArAllocHerb * costofHerb + maxArAllocAqua * costofAqua + maxArAllocCarn * costofCarn;
    }

    cout<<totalCost<<endl;









	return 0;
}
