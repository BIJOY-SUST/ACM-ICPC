#include<bits/stdc++.h>
using namespace std;
long long MPG;
class node{
public:
    long long endmark;
    node *next[3];
    node(){
        endmark = 0;
        for(int i=0;i<3;i++){
            next[i]=NULL;
        }
    }
};
node *root;
void insert(string s){
    node *current_node=root;
    for(int i=0;i<s.length();i++){
        int id = s[i]-'0';
        if(current_node->next[id]==NULL){
            current_node->next[id]=new node();
        }
        current_node=current_node->next[id];
        current_node->endmark=current_node->endmark+1;
        MPG=max(MPG,current_node->endmark*(i+1));
    }
}
int main(){
    int T,N;
    cin>>T;
    while(T--){
        MPG=0;
        string s;
        root = new node();
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>s;
            insert(s);
        }
        cout<<MPG<<endl;
    }
    return 0;
}
/*

*/