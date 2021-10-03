//This program finds the factorial of a large number using linkedlist
/*The factorial of a large number cannot be stored in integer therefore creating a linkedlist to do the same */

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        //making prev pointer bcz we multiply frm right to left
        node *prev;
        node(int val){
            data=val;
            prev=NULL;
        }
};

//recursive display

void display(node* tail){
    if(tail==NULL) return;
    display(tail->prev);
    cout<<tail->data;
}

void multiply(node* tail, int x){
    node *temp = tail, *PrevNode = tail;
    int carry = 0;
    while(temp){
        int val = temp->data * x + carry;
        temp->data = val%10;
        carry = val/10;
        PrevNode = temp;
        temp = temp->prev;
    }
    while(carry){
        PrevNode->prev = new node(carry%10);
        carry/=10;
        PrevNode = PrevNode->prev;
    }
}


//main
int main(){
    node *tail = new node(1);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        multiply(tail,i);
    }
    display(tail);
    return 0;
}
