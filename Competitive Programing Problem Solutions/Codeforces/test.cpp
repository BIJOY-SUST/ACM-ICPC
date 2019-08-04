#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl              '\n'
#define sf              scanf
#define pf              printf
#define F               first
#define S               second
#define pb              push_back
#define eb              emplace_back
#define ui              unsigned int
#define ll              long long int
#define ull             unsigned long long int
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define vi              vector<int>
#define vll             vector<ll>
#define vpii            vector<pii>
#define vpll            vector<pll>
#define mpii            map<int,int>
#define mpll            map<ll,ll>
#define ump             unordered_map
#define uset            unordered_set
#define PQ              priority_queue
#define rev(v)          reverse(v.begin(),v.end())
#define srt(v)          sort(v.begin(),v.end())
#define grtsrt(v)       sort(v.begin(),v.end(),greater<int>())
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mx        = 2e5+10;
const int inf       = 0x3f3f3f3f;
const int mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
bool mark[mx];vector<int>prime;
void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(mx);i+=2){if(mark[i]){for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);}
///code start here

//vi edge[mx];
//int level[mx],par[mx];
//void dfs(int u){
//    for(auto &v:edge[u]){
//        if(par[u]==v) continue;
//        par[v]=u;
//        level[v]=level[u]+1;
//        dfs(v);
//    }
//    return;
//}
//int ans=0;
//void dfs2(int u){
//    for(auto &v:edge[u]){
//        if(par[u]==v) continue;
//        level[v]=min(level[v],level[u]+1);
//        dfs2(v);
//        level[u]=min(level[u],level[v]+1);
//
//    }
//    if(level[u]>2){
//        level[par[u]]=1;
//        level[u]=2;
//        ans++;
//    }
//    return;
//}
//
//int digit(int a,int b){
//    int s=0;
//    while(a){
//        int re=a%10;
//        a/=10;
//        s+=re;
//    }
//    while(b){
//        int re=b%10;
//        b/=10;
//        s+=re;
//    }
//    return s;
//}
//int dp[mx];

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<k;i++){
        if(s.find('A'+i)==s.end()){
            cout<<0<<nl;
            return 0;
        }
    }
    return 0;
}
/*
4 4 2
2 3
1 2
1 3
1 4
*/