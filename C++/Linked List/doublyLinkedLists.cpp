#include <bits/stdc++.h>
using namespace std;

/*
    DOUBLY LINKED LIST IN A NUTSHELL
*/

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head , int val){

    node *n = new node(val);
    n->next = head;
    
    if(head != NULL){
        head->prev = n;
    }

    head = n;

}

void insertAtTail(node *&head , int val){

    if(head == NULL){
        insertAtHead(head , val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;

}

void insertAtPos(node *&head, int pos, int val)
{

    if(pos <= 0){
        cout << "Invalid Position!\n";
        return;
    }else if (pos == 1)
    {
        insertAtHead(head , val);
        return;
    }
    
    node *n = new node(val);
    
    int count = 0;
    node *temp = head;
    while(temp != NULL and count != pos - 2){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return;
    }
    
    n->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = n;
    }
    n->prev = temp;
    temp->next = n;
    
}

void sortedInsert(node *&head, int x){
        
    node *n = new node(x);
    
    if(head == NULL or head->data >= x){
        n->next = head;
        if(head != NULL){
            head->prev = n;
        }
        head = n;
        return;
    }
        
    node *temp = head;
    
    while(temp->next != NULL and temp->next->data < x){
        temp = temp->next;
    }
    
    n->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = n;
    }
    n->prev = temp;
    temp->next = n;
    
}

void deleteAtHead(node *&head){

    if(head == NULL or head->next == NULL){
        delete head;

    }else{
        node *todelete = head;
        head = head->next;
        head->prev = NULL;

        delete todelete;
    }

}

void deletion(node *&head , int pos){

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int count = 1;
    while(temp != NULL and count != pos){
        temp = temp->next;
        count++;
    }

    node *todelete = temp;
    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete todelete;

}

void reverse(node *&head){

    if(head == NULL or head->next == NULL){
        return;
    }

    node *temp = head , *prevptr = NULL;
    while(temp != NULL){
        prevptr = temp->prev;
        temp->prev = temp->next;
        temp->next = prevptr; //Swapping next and prev of temp

        temp = temp->prev; //Moving temp forward
    }
    head = prevptr->prev;

}

void display(node *head){

    node *temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;

}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    
    for(int i = 20 ; i <= 50 ; i+=10){
        insertAtTail(head,i);
    }
    display(head);

    insertAtHead(head,10);
    display(head);

    insertAtPos(head , 2 ,100);
    display(head);

    // deletion(head , 1);
    // display(head);

    // reverse(head);
    // display(head);

    return 0;
}
