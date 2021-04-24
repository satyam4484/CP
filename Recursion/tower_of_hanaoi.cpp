#include<iostream>
using namespace std;

void solve(char A,char B,char C,int n,int &count ){
    count++;    //count the number of steps taken to complete the task
    if(n==1){
        //if there is only one plate then move directly to Destinatiom
        cout<<"\tMoving plate "<<n<<" from "<<A<<" to "<<C<<endl;
        return;
    }
    //move the remaining plates and left only one plate 
    solve(A,B,C,n-1,count);
    cout<<"\tMoving plate "<<n<<" from "<<A<<" to "<<C<<endl;

    // move the remaining plates from helper to destination 
    solve(B,C,A,n-1,count);
    return;
}
int main(){
    int n,count=0;
    cout<<"\tEnter the number of plates : ";
    cin>>n;
    /* 
        A--> source plate 
        B-->helper plate 
        C-->Destination plate 
    */
    solve('A','B','C',n,count);
    cout<<endl;
    cout<<"\tThe number of steps taken is : "<<count<<endl;
    
    return 0;
}