#include<iostream>
using namespace std;
#define n 100
class stack
{
private:
    /* data */
    int top; int*arr;

public:
    stack(/* args */){
        arr=new int[n];
        top=-1;
    };
    void push(int x){
        if(top==n-1){
            cout<<"stack is overflow"<<endl;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"no element to pop"<<endl;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"no elemrnt in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    return 0;
}
