// Using Floyd's cycle algo
// Driver Code Starts
// C program to detect loop in a linked list and return the length of the loop if found
// Driver Code Starts

#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node **tail, int data)
{
	struct Node* new_node = new Node (data);
	(*tail)->next = new_node;
	(*tail) = new_node;
	return;
}

void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodesinLoop(struct Node *head);

/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node *tail = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        struct Node* new_node = new Node (tmp);
        head = new_node;
        tail = new_node;
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&tail, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodes(Node *head)
{
    int length = 1;
    Node *temp = head;
    while(temp->next!=head)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
int countNodesinLoop(struct Node *head)
{
     // Code here
     Node *f=head, *s=head;
     while(f && s && s->next)
     {
         f = f->next;
         s = s->next->next;
         if(f==s)
            return countNodes(f);
     }
     return 0;
}
