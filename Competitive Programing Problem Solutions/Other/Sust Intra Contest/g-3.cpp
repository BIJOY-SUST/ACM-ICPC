#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[4];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    sort(arr,arr+4);
        if(arr[0]+arr[1]>arr[2]||arr[1]+arr[2]>arr[3]){
            cout<<"TRIANGLE"<<"\n";
        }
        else if(arr[0]+arr[1]==arr[2]||arr[1]+arr[2]==arr[3]){
            cout<<"SEGMENT"<<"\n";
        }
        else{
            cout<<"IMPOSSIBLE"<<"\n";
        }
    return 0;
}

