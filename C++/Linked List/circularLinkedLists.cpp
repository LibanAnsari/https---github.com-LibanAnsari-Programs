#include <bits/stdc++.h>
using namespace std;

/*
    FLOYD'S ALGO
    HARE AND TORTOISE ALGO
    (fast and slow meathod only)
*/

class node
{
public:
    int data;
    node *next;

    node(int x){
        data = x;
        next = NULL;
    }
};

void insertAtTail(node *&head , int val){
    
    node *n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node *temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;

}

void display(node *head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAtCycleHead(node *&head , int val){

    // NAIVE METHOD O(n)
    // node *n = new node(val);

    // if(head == NULL){
    //     n->next = head;
    //     head = n;
    //     return;
    // }

    // node *temp = head;
    
    // while(temp->next != head){
    //     temp = temp->next;
    // }
    // temp->next = n;
    // n->next = head;
    // head = n;


    // EFFICIENT METHOD O(1)
    /*
        add new node temp after head, between head and head->next
        then swaps data of temp and head
    */
    node *n = new node(val);
    if(head == NULL){
        n->next = head;
        head = n;
    }else{
        n->next = head->next; 
        head->next = n; //Insertion after head

        int data = head->data;
        head->data = n->data;
        n->data = data; //Swapping data
    }

}

void insertAtCycleTail(node *&head , int val){
    // O(1)
    node *n = new node(val);
    if(head == NULL){
        n->next = head;
        head = n;
        return;
    }else{
        n->next = head->next;
        head->next = n; //Inserting after head

        int data = head->data;
        head->data = n->data;
        n->data = data; //Swapping data

        head = n; //Making new head
    }

}

void deleteCycleHead(node *&head){
    // O(1)
    if(head == NULL or head->next == head){
        delete head;
    }else{
        head->data = head->next->data; //Copying data of next node to head
        node *todelete = head->next; //Deleting the node after head
        head->next = head->next->next;

        delete todelete;
    }

}

void deletekthNode(node *&head , int k){

    if(head == NULL){
        return;
    }
    
    if(k == 1){
        deleteCycleHead(head);
        return;
    }
    
    node *temp = head;
    int count = 1;
    while(count < k - 1){
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete temp;

}

void makeCycle(node *&head , int pos){

    if(head == NULL or pos < 1){
        cout << "NULL" << endl;
    }

    node *temp = head , *startnode = NULL;
    int count = 1;

    while(temp->next != NULL){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;

}

void removeCycle(node *&head){
    
    if(head == NULL or head->next == NULL){
        cout << "NULL HEAD OR A SINGLE NODE" << endl;
        return;
    }

    node *slow = head , *fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    fast = head;
    if(slow == head){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }else{
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
    }

}

bool detectCycle(node *&head){
    
    node *slow = head , *fast = head;

    while(fast != NULL and fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;

}


int main(int argc, char const *argv[])
{
    node *head = NULL;

    for (int i = 10; i <= 50; i += 10){
        insertAtTail(head, i);
    }
    display(head);


    makeCycle(head , 1);
    // display(head); //Makes and infinite loop

    cout << detectCycle(head) << endl;

    insertAtCycleTail(head,60);

    // deleteCycleHead(head);
    
    deletekthNode(head,3);

    if(detectCycle(head)){
        removeCycle(head);
        display(head);
    }else{
        cout << "CYCLE NOT PRESENT!" << endl;
    }

    return 0;
}
