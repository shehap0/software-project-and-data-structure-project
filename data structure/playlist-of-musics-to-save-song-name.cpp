#include <iostream>
using namespace std;

// shehap       -> used double linked list

/*
- is empty
- add to head
- add to tail
- display
- delete from head    
- delete from tail
- delete specific song 
- count
- find in list

- copy list
- display copy
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

    void deleteFromHead(){
        if(isEmpty())
        {
            cout<<"the list is empty"<<endl;
            return;
        }else{
            node* temp=new node;
            temp=head;
            temp=temp->next;
            temp->previous=NULL;
            delete head;
            head=temp;
        }
    }

    void deleteFromTail(){
        if(isEmpty())
        {
            cout<<"the list is empty"<<endl;
            return;
        }else if(head->next==NULL){
            delete head;
        }else
        {
            node* delptr=head;
            node* temp= new node;

            while(delptr->next!=NULL){
                delptr=delptr->next;
            }
            temp=delptr->previous;
            delete delptr;
            temp->next=NULL;
        }
    }

    void deleteSong(string song){
        if(isEmpty()){
            cout<<"the list is empty"<<endl;
            return;
        }else{
            node* delptr=head;
            node* temp=new node; 
            while(delptr->name!=song)
            {
                delptr=delptr->next;
            }
            temp=delptr->previous;
            temp->next=delptr->next;
            delete delptr;
        }
    }

    void count(){
        if(isEmpty())
        {
            cout<<"the list is empty"<<endl;
            return;
        }else{
            node* temp=head;
            int count=0;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            cout<<"total songs: "<<count<<endl;
        }
    }

    void find(string song){
        if(isEmpty()){
            cout<<"the list is empty"<<endl;
            return;
        }else{
            node* temp=head;
            while(temp!=NULL)
            {
                if(temp->name==song)
                {
                    cout<<"found song "<<temp->name<<" in the list"<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"song not found in the list"<<endl;
        }
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

    w.deleteFromHead();
    w.display();
    w.deleteFromTail();
    w.display();

    w.deleteSong("die for you");
    w.display();

    w.count();

    w.find("new person, same old mistakes");

    
    
    
    return 0;
}