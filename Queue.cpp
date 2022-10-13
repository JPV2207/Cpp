#include <iostream>
using namespace std;
#define length 10
int front=-1,real=-1;
int arr[length];
void insertOperation(int n){
    if(front ==-1 && real==-1){
        front =0;
        real=0;
        arr[real]=n;
    }
    else if(real==length-1)
        cout<<"\nQueue Overflow";
    else{
        real++;
        arr[real]=n;
    }
}
void display(){
    if(front==real+1 || (front==-1 && real==-1))
    cout<<"\n Queue Underflow";
    else{
        for(int i=front;i<=real;i++)
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void deleteOpration(){
    front++;
}
int main(){
    int n,q;
    while(1){
        cout<<"\nEnter:\n 1 for insert\n 2 for display \n 3 for delete \n 4 for exit"<<endl;
        cout<<"Enter here:-";
        cin>>q;
        if(q==1){
            cout<<"\nEnter no. want to insert:";
            cin>>n;
            insertOperation(n);
        }
        else if(q==2){
            display();
        }
        else if(q==3){
            deleteOpration();
        }
        else if(q==4)
        break;
        else{
            cout<<"\nInvalid Choice";
        }
    }
    return 0;
}
