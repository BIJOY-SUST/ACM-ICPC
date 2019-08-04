#include<bits/stdc++.h>
//#define mx             100010
//#define mod            1000000007
//#define pi             2*acos(0.0)
//#define ll             long long int
//#define pp             pair<int,int>
//#define ull            unsigned long long int
//#define valid(tx,ty)   tx>=0&&tx<r&&ty>=0&&ty<c
//#define mem(arr,val)   memset(arr,val,sizeof(arr))
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//int biton(int p,int pos){return p=p|(1<<pos);}
//int bitoff(int p,int pos){return p=p&~(1<<pos);}
//bool bitcheck(int p,int pos){return (bool)(p&(1<<pos));}
//ll POW(ll b,ll p) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b);b=(b*b);p>>=1;}return Ans;}
//ll BigMod(ll b,ll p,ll Mod) {ll Ans=1; while(p){if(p&1)Ans=(Ans*b)%Mod;b=(b*b)%Mod;p>>=1;}return Ans;}
//ll ModInverse(ll p,ll Mod) {return BigMod(p,Mod-2,Mod);}
using namespace std;

int main(){
//    freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++){
        double L,N,C;
        cin>>L>>N>>C;
        double L2=(1.0+(N*C))*L;
        double kom=0.0,beshi=L,mid,c=L/2.0;
        while(beshi-kom>(1e-6)){
            mid=(kom+beshi)/2.0;
            double s = 2*(asin(c/(c*c/(2*mid)+(mid/2.0))))*((c*c/(2*mid))+(mid/2));
            if(s<L2) kom=mid;
            else beshi=mid;
        }
        cout<<setprecision(10)<<"Case "<<cs<<": "<<kom<<'\n';
    }
    return 0;
}
/**
Input:
3

1000 100 0.0001

150 10 0.00006

10 0 0.001
Output:
Case 1: 61.3289915

Case 2: 2.2502024857

Case 3: 0
Soluiton
Initial Rod এর দৈর্ঘ্য ছিলো L
After Expansion , রডটার দৈর্ঘ্য হলো L’
রডটাকে আমি একটা দেয়ালের মাঝে যদি রেখে দিই,দেয়ালটার প্রস্থ যদি রডটার আদি দৈর্ঘ্যের সমান হয়,তাহলে এটা আর প্রসারিত না হয়ে বাঁকা হয়ে উপরের দিকে উঠে যাবে।
বাঁকা হয়ে উপরের দিকে উঠলে,ছবিতে h এর মান কত হবে সেটাই আমাদের বের করতে হবে।
সমাধানঃ
প্রথমেই আমরা একটি সাবপ্রব্লেম সল্ভ করে ফেলবো। Expansion টা সুষম হওয়ায় রডটা এমনভাবেই বাঁকাবে যেন এটা একটা বৃত্তের অংশ হয় এবং একটা Valid বৃত্তচাপ গঠন করে।
 তাহলে এক কাজ করি, পুরো ব্যাপারটাকে বৃত্তে নিয়ে গিয়ে কল্পনা করে ফেলি। তারপর মূল সমস্যায় ফেরত আসা যাবে।

এই ছবিটায় 2c হচ্ছে আমাদের রডটা ( তাপ প্রয়োগ করার আগে) । এই 2c অংশটার ঠিক উপরে যতটুক বৃত্তচাপ আছে,সেটা হচ্ছে তাপ প্রয়োগের পরের অবস্থা। আর b হচ্ছে h ।
a+b = বৃত্তের ব্যাস,এইটুক জানলেই হবে।
বৃত্তের আপাতত এতটুক অবস্থা থেকে আমাদের বৃত্তটার ব্যাসার্ধ (r) কোনোভাবে বের করা যায় কিনা,সেটা দেখতে হবে।
ত্রিভুজ NOM এবং ত্রিভুজ OXY পরস্পর সদৃশকোণী ত্রিভুজ। ( কেন ? কারণ NOM=XOY=90 Degree , ON=OY তাই OMN=XYO )
তাহলে আমরা বলতে পারিঃ
আচ্ছা, a আর b যদি যোগ করে দিই,আমরা ব্যাস পেয়ে যাচ্ছি,তাই না? তাহলে লিখতে পারিঃ
আমরা তাহলে বৃত্তটার ব্যাসার্ধ পেয়ে গেলাম। আমাদের কাজ হচ্ছে এবার এই বৃত্তটার চাপ NXY কেন্দ্রে যে কোণ উৎপন্ন করে,সেটা বের করা।
সেটা বের করা আরো সহজ,ছবিটা এঁকে দিলে নিজেরাই বের করে ফেলতে পারবেঃ


এখানে হাতে আঁকা বিশ্রী থিটার ভ্যালুটা বের করা লাগবে। হালকা পাতলা ত্রিকোণমিতি মেরে দিয়ে এটা বের করে ফেলা যায়।

থিটার মান হবেঃ


তাহলে , বৃত্তচাপ কেন্দ্রে যে কোণ উৎপন্ন করে,তা হবে এর দ্বিগুণঃ


এবার , বৃত্তচাপের দৈর্ঘ্য যদি হয় S , তাহলে আমরা লিখতে পারিঃ


এ পর্যন্ত যা যা পেলাম তা বসিয়ে দিয়ে পাইঃ


এখন লক্ষণীয় এইযে, S এর মান আমরা শুরুতেই বের করে ফেলতে পারি। সেটা হচ্ছে,S=L’

তাহলে আমরা আবার S এর মান এত কষ্ট করে বের করছি কেন? আমরা আসলে উপরের সমীকরণটা থেকে S এর মান বের করছি না,
বের করার চেষ্টা করছি b এর কোন মানের জন্য আমাদের S এর মান L’ এর সমান হয়!

আমরা আবারো আমাদের S বের করার সমীকরণটিতে চোখ বুলিয়ে আসি। খুব ভালোভাবে এই সমীকরণের Variable এবং Constant ভ্যালুগুলোকে আইডেন্টিফাই করে ফেলো!

খেয়াল করে দেখো,আমাদের উপরের সমীকরণটায়ঃ

c = W/2 , যেটা আমরা শুরুতেই জানি!

b = ভ্যারিয়েবল। এটাই আমাদের আসল উত্তর,মানে উচ্চতা H. এটার একটা একটা করে মান বসিয়ে বসিয়ে চেক করতে থাকবো S কত আসে।
এই S যদি L’ এর সাথে মিলে যায়,b ( বা H ) এর সেই মানটাই আমাদের উত্তর!

এখন, একটা একটা করে b এর মান বসানোর কোনো মানে হয়না! মানে যদি থাকতো,তাহলে আমরা সমস্যাটাকে এভাবে সমাধানই করতাম না!
আমরা এখানে যেই কাজটা করবো,এই ফাংশনটার একটা প্রপার্টি চেক দিবো। এবং এই প্রপারটিটা হচ্ছে বাইনারী প্রপার্টি!
**/