#include <iostream>
using namespace std;
class node{
	public: 
	int data ;
	node*next ;
	public:
	node(int x){
		this->data = x;
		next = NULL;
	}
};
void insertionathead(node* &head ,int x){
    
    node* temp = new node(x);

    temp-> next= head ;

    head= temp;

}
void printll(node * & head){
    node * temp = head;
    while(temp!=NULL){
        cout << temp->data<< " ";
        temp = temp-> next;
    }
    cout << endl;
    
}

void insertionattail(node* &tail,int x){

    node* temp = new node(x);

    tail->next= temp;

    tail = temp;

}
void insertioninmiddle(node*& head ,node*&tail,int pos,int x ){
    if(head == NULL){
        node * temp = new node(x);
        head = temp;
        tail = temp;
        return;
    }

    if(pos==1){
 
       insertionathead(head,x);
   
       return;
   
    }
    
    node* temp = head;

    node*temp2= new node(x);

    for(int i=1;i<pos-1 ;i++){

        temp=temp->next;

    }

    if(temp->next ==NULL){

        insertionattail(tail,x);
        return;

    }

    temp2->next= temp-> next;
    temp->next= temp2;

}
void printheadtail(node * & head,node* & tail){
    cout << endl<<"head is : "<< head -> data << endl << "tail is : "<<  tail->data << endl;
}
void  reverse(node *&head,node*&tail,node* & prev,node *& curr){
    if(curr==NULL){
        tail = head;
        head = prev ;
        return ;
    }
    
    reverse(head,tail,curr,curr->next);
    curr->next = prev ;
    
}

int main()
{
    node * head;
    node * tail;
    insertioninmiddle(head,tail,1,5);
    insertioninmiddle(head,tail,2,12);
    insertioninmiddle(head,tail,2,23);
    insertioninmiddle(head,tail,3,3);
    printll(head);
    node * curr = head;
    node * prev = NULL;
    reverse(head,tail,prev,curr);
    printll(head);
    
    
}
