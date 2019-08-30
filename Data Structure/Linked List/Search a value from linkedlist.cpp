//
//  Copyright © 2019 Abu Jafor Mohammad Saleh. All rights reserved.
//

#include <iostream>

using namespace std;


/// একটি নোড ডিক্লার করা
struct node {
    int roll;
    node *next;
};

node *root = NULL;


///একটি নতুন নোড ক্রিয়েট করে ভ্যালু রাখা
void append(int roll)
{
    if(root==NULL)
    {
        root = new node();
        root -> roll = roll;
        root -> next = NULL;
    }
    
    else
    {
        node *currentNode = root;
        
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        
        node *newNode = new node(); //create a new node
        newNode->roll = roll;
        newNode->next = NULL;
        
        currentNode -> next = newNode;
    }
}


/// লিংক লিস্ট থেকে কোন ভ্যালু খোঁজা 
void searchanitem(int key)
{
    node *searchnode = root;
    int c= 1;
    bool f = true;
    while(searchnode != NULL)
    {
        if(searchnode->roll == key)
        {
            cout<<"The position of "<<key<<" is "<<c<<endl;
            f = false;
            break;
        }
        else{
            searchnode =searchnode->next;
        }
        c++;
    }
    
    if(f)
        cout<<key<<" not found"<<endl;
 
}


int main()
{
    append(1);
    append(2);
    append(6);
    append(188);
    append(45);
    searchanitem(6);
    return 0;
}
