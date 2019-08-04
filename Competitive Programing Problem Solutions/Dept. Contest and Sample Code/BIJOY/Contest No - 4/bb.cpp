#include<bits/stdc++.h>
#define mx             10010
#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
//const int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
//int biton(int n,int pos){return n=n|(1<<pos);}
//int bitoff(int n,int pos){return n=n&~(1<<pos);}
//bool bitcheck(int n,int pos){return (bool)(n&(1<<pos));}
//ll POW(ll b,ll p) {ll r=1; while(p){if(p&1)r=(r*b);b=(b*b);p>>=1;}return r;}
//ll BigMod(ll b,ll p,ll m) {ll r=1; while(p){if(p&1)r=(r*b)%m;b=(b*b)%m;p>>=1;}return r;}
//ll ModInverse(ll n,ll m) {return BigMod(n,m-2,m);}
using namespace std;
bool mark[mx];
vector<int>prime;
int dd[mx];
void sieve(){
    mem(mark,true);
    mark[0]=mark[1]=false;
    for(int i=4;i<=mx;i+=2) mark[i]=false;
    for(int i=3;i<=(int)sqrt(mx);i+=2){
        if(mark[i]) for(int j=i*i;j<=mx;j+=2*i) mark[j]=false;
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2) if(mark[i]) prime.push_back(i);
}
void nod(int n){
//    int sqrtn=sqrt(n);
    for(int i=0;i<prime.size()&&prime[i]<=n;i++){
        int cnt=0;
        if(n%prime[i]==0){
            int p=prime[i];
            while(n%p==0){
                n=n/p;
                cnt++;
            }
            dd[p]+=cnt;
            //cout<<p<<" "<<cnt<<endl;
        }
    }
}
int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    mem(dd,0);
    int n; scanf("%d",&n);
    for(int i=2;i<=n;i++){
        nod(i);
    }
    ll ans=1;
    for(int i=0;i<prime.size();i++){
        if(dd[prime[i]]!=0){
            //cout<<prime[i]<<" "<<dd[prime[i]]<<endl;
            ans=(ans*(dd[prime[i]]+1))%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*

*/