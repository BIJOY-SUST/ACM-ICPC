#include<bits/stdc++.h>
//#define mx             100001
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define pp             pair<int,int>
//#define ll             long long int
//#define bug(x)         printf("X: %d\n",x)
//#define one(n)         __builtin_popcount(n)
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
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

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    int ans=0;
    int d1=0,d2=0;
    int cnt=0;
    bool f=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B'&&f==true){
            cnt++;
            f=false;
        }
        else if(s[i]=='W'){
            f==true;
        }
    }
//    cout<<"White "<<cnt<<endl;
    d1=cnt;
    cnt=0;
    f=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='W'&&f==true){
            cnt++;
            f=false;
        }
        else if(s[i]=='B'){
            f==true;
        }
    }
//    cout<<"Black "<<cnt<<endl;
    d2=cnt;
    ans=min(d1,d2);
    cout<<ans<<endl;
    return 0;
}
/*

*/

