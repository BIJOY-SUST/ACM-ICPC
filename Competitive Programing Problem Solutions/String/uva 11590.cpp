#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

///Faster I/O
#define     sfs(a)              scanf("%s",&a)
#define     sfi1(a)             scanf("%d",&a)
#define     sfi2(a,b)           scanf("d",&a,&b)
#define     sfi3(a,b,c)         scanf("d%d",&a,&b,&c)
#define     sfi4(a,b,c,d)       scanf("dd",&a,&b,&c,&d)
#define     sfd1(a)             scanf("%lf",&a)
#define     sfd2(a,b)           scanf("lf",&a,&b)
#define     sfd3(a,b,c)         scanf("lf%lf",&a,&b,&c)
#define     sfd4(a,b,c,d)       scanf("lflf",&a,&b,&c,&d)
#define     sfll1(a)            scanf("%lld",&a)
#define     sfll2(a,b)          scanf("lld",&a,&b)
#define     sfll3(a,b,c)        scanf("lld%lld",&a,&b,&c)
#define     sfll4(a,b,c,d)      scanf("lldlld",&a,&b,&c,&d)
#define     sfull1(a)           scanf("%llu",&a)
#define     sfull2(a,b)         scanf("llu",&a,&b)
#define     sfull3(a,b,c)       scanf("llu%llu",&a,&b,&c)
#define     caseprint(case)     printf("Case%d: ",case ++)

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
#define all(v)          v.begin(),v.end()
#define valid(tx,ty)    tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)    memset(arr,val,sizeof(arr))
#define Unique(x)       x.erase(unique(x.begin(),x.end()),x.end())
#define forstl(it,v)    for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL)
template <typename T> T POW(T b,T p) {T Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
template <typename T> T BigMod(T b,T p,T Mod) {T Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
template <typename T> T ModInverse(T p,T Mod) {return BigMod(p,Mod-2,Mod);}
typedef  tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> o_set;
//bool mark[1000010];vector<int>prime;
//void sieve(){memset(mark,true,sizeof(mark));for(int i=3;i<=(int)sqrt(1000010);i+=2){if(mark[i]){for(int j=i*i;j<=1000010;j+=2*i) mark[j]=false;}}prime.push_back(2);for(int i=3;i<=1000010;i+=2) if(mark[i]) prime.push_back(i);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args> void deb(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;deb(++it, args...);}
const int fx[]      = {+0,+0,+1,-1,-1,+1,-1,+1};
const int fy[]      = {-1,+1,+0,+0,+1,+1,-1,-1};
const int mxn       = 2e6+10;
const int inf       = 0x3f3f3f3f;
const ll  mod       = 1e9+7;
const double pi     = 2*acos(0.0);
const double E      = 2.71828182845904523536;
const double eps    = 1e-9;
///code start here

struct node{
    ull cnt;
    node *next[2];
    node(){
        cnt=0;
        next[0]=next[1]=nullptr;
    }
};

node *root;

void add_trie(string s,ull ind){
    node *cur_r=root;
//        debug(s,ind);

    for(int i=0;i<s.length();i++){
        int id=s[i]-'0';
        if(cur_r->next[id]==nullptr) cur_r->next[id]=new node();
        cur_r=cur_r->next[id];
    }
    cur_r->cnt=(1LL<<ind);
//    debug(s,ind,cur_r->cnt);
}
ull lol(node *cur_r,int in){
    if(cur_r==nullptr) return 0LL;
    ull ret=0;
    if(cur_r->cnt){
        return cur_r->cnt;
    }
//    for(int i=0;i<2;i++){
//        if(cur_r->next[i]){
//            ret+=lol(cur_r->next[i]);
//        }
//    }
//    debug(in,cur_r->cnt);
    if(cur_r->next[0]){
            ret+=lol(cur_r->next[0],in);


    }
//    debug(ret);
    if(cur_r->next[1]) {
            ret+=lol(cur_r->next[1],in);

    }
//    debug(ret);
    return ret;
}
ull query(string s){
    node *cur_r=root;
    for(int i=0;i<s.length();i++){
        int id=s[i]-'0';
        cur_r=cur_r->next[id];
    }
//    debug(cur_r->cnt,(cur_r->next[1]->cnt),(cur_r->next[0]->cnt));
    ull ans = cur_r->cnt - lol(cur_r->next[0],0)-lol(cur_r->next[1],1);
    return ans;
}

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
    fast;
    ull n,m;
    while(cin>>n>>m ){
        if(n==0 and m==0) break;
        root = new node();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            s.pop_back();
//            debug(s);
            add_trie(s,m-s.length());
        }
        root->cnt=(1ull<<m);
        int k;
        cin>>k;
        while(k--){
            string s;
            cin>>s;
            s.pop_back();

            if(m==64 and s.length()==0){
                    ull ans = ((1ull<<m)-1) - lol(root->next[0],0)-lol(root->next[1],1)+1;
                    cout<<ans<<nl;
                    continue;

            }
            ull d=query(s);

           cout<<d<<nl;

        }
            cout<<nl;

    }
    return 0;
}

/*
4 4
0*
11*
011*
1110*
5
*
0*
11*
011*
1110*

4
6
3
2
1
*/