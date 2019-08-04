#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<string>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mx             100010
#define inf            0x3f3f3f3f
#define mod            1000000007
#define PI             2*acos(0.0)
#define E              2.71828182845904523536
#define ll             long long int
#define ull            unsigned long long int
#define pii            pair<int,int>
#define pll            pair<ll,ll>
#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
#define fast           ios_base::sync_with_stdio(false),cin.tie(NULL)
#define forstl(x)      for(__typeof(x.begin()) it=(x.begin());it!=(x.end());++it)
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
template <typename T> bool bitcheck(T p,T pos){return (bool)(p&(1<<pos));}
template <typename T> T biton(T p,T pos){return p=p|(1<<pos);}
template <typename T> T bitoff(T p,T pos){return p=p&~(1<<pos);}
template <typename T> ll toint(T s) {ll p;stringstream ss(s); ss>>p; return p;}
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set2 = tree<pair <T, string>, null_type, less<pair <T, string>>, rb_tree_tag, tree_order_statistics_node_update>;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string tostring(ll n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    string s;
    cin>>s;
    ll ans=1e15;
    for(ll i=1;i<50000;i++){
        ll no=i*i;
        string ss;
        stringstream sss;
        sss<<no;
        sss>>ss;

//        cout<<ss<<" ";
        ll cnt=0;
        for(ll i=0;i<s.length();i++){
            if(s[i]==ss[cnt]) ++cnt;
        }
//        cout<<cnt<<endl;
        if(cnt==ss.length()){
            ll dif=s.length()-ss.length();
            ans=min(ans,dif);
        }
    }
    if(ans==1e15){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}