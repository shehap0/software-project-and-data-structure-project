#include <iostream>                         // shehap
using namespace std;

/*
- add to head
- add to tail
- display
- delete from head
- delete from tail
- count
- is empty
- smallest
- sum odd
- copy list
- display copy
- find in list
- reverse list
- stack
    1. is Empty
    2. is Full
    3. push
    4. pop
    5. top element
    6. display
- binary search tree
    1. in Order
    2. pre Order
    3. post Order
    4. insert
    5. size
    6. find min
    7. find max
    8. remove
    9. destroy Tree
    10. is Leaf Node
    11. max Depth
- queue
    1. inqueue
    2. dequeue
    3. display
    4. is empty*/
class node{
    public:
    int data;
    node* next;

    node(){
        data = 0;
        next =NULL;
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

    
};

int main(){
    
    return 0;
}