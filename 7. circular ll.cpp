// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class node{
    public: 
    int data; node *next ;
    public: 
    node(int x){
        this-> data = x;
        this-> next = NULL;
    }
    ~node(){
        if(next!=NULL){
            int data = this->data;
            delete next ;
            next= NULL;
            
        }
        cout <<endl<< "both prev and next for the data : "<<data<< " is deleted"<<endl;
    }
    
};


void insertioninmiddle(node*&tail,int val,int x ){
    if(tail==NULL){
        node * temp = new node(x);
        temp ->next = temp;
        tail =temp->next;
    }
    else{
    node * curr= tail;
    while(curr->data != val ){
        curr=curr->next;
    }
    node * temp = new node(x);
    temp -> next = curr->next;
    curr -> next = temp;
    }
}
void print(node * &tail){
    if(tail==NULL){
        cout << "LIST IS EMPTY"<< endl;
        return ;
    }
    node * temp = tail;
    do{
        cout << temp->data<< " ";
        temp = temp->next ;
    }while(temp !=tail);
    cout <<endl;
    
}
void del(node * & tail,int element){
    if(tail==NULL){
        cout << " LIST IS EMPTY "<< endl;
    }
    else if(tail!= NULL){
        node * temp = tail ;
        node * curr= tail->next;
        while(curr->data !=element){
            temp = curr;
            curr = curr-> next ;
            
        }
        temp->next = curr->next ;
        if(curr==temp){
            tail= NULL;
        }
        else if(tail== curr){
            tail = temp;
        }
        curr->next = NULL;
        delete curr;
    }
}


int main() {
    
    node * tail= NULL;
    insertioninmiddle(tail,5,3);
    print(tail);
    
    insertioninmiddle(tail,3,5);
    print(tail);
    
    insertioninmiddle(tail,3,3);
    print(tail);
    
    del(tail,3);
    print(tail);
}