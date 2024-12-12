#include <iostream>
using namespace std;

// shehap       -> used double linked list

/*
- add to head
- add to tail
- display

- delete from head                                                                                                                                                                       
- delete from tail
- delete from specific place
- delete specific song 
- count
- is empty
- copy list
- display copy
- find in list
- reverse list
*/


class node{
    public:
    string name;
    node* next;
    node* previous;

    node(){
        name="";
        next=previous=NULL;
    }
};

class musicPlayList{
    public:
    node* head;

    musicPlayList(){
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void addToHead(string song){
        node* newItem=new node;
        newItem->name=song;

        if(isEmpty())
        {
            head=newItem;
            newItem->next=NULL;
            newItem->previous=NULL;
        }else{
            node* temp=new node;
            temp=head;
            head=newItem;
            newItem->next=temp;
            temp->previous=newItem;
            newItem->previous=NULL;
        }
    }

    void addToTail(string song){
        node* newItem=new node;
        newItem->name=song;
        if(isEmpty()){
            head=newItem;
            newItem->next=NULL;
            newItem->previous=NULL;
        }else{
            node* temp=new node;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newItem;
            newItem->next=NULL;
            newItem->previous=temp;
        }
    }

    void display(){
        node* temp=new node;
        temp=head;
        while(temp!=NULL){
            cout<<"song name: "<<temp->name<<endl;
            temp=temp->next;
        }
        cout<<"----------------------"<<endl;
    }
};

int main(){
    musicPlayList w;
    w.addToHead("new person, same old mistakes");
    w.addToHead("die for you");
    w.addToHead("out of time");
    w.addToHead("young & dumb");
    w.addToHead("dont let me go");
    w.addToTail("after hours");
    
    w.display();

    return 0;
}