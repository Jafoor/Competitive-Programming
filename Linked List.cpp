//
//  main.cpp
//  dataStructureLinkedList
//
//  Created by Abu Jafor Mohammad Saleh on 14/8/19.
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


/// ভ্যালু প্রিন্ট করা
void print()
{
    node *currentNode = root;
    while(currentNode != NULL)
    {
        printf("%d\n",currentNode->roll);
        currentNode = currentNode->next;
    }
}


/// কোন নোড ডিলেট করা
void deleteNode(int roll)
{
    node *currentNode = root;
    node *previousNode = NULL;
    while(currentNode->roll != roll)
    {
        previousNode =currentNode;
        currentNode = currentNode->next;
    }
    
    if(currentNode == root)
    {
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    
    else  //delete non-root node
    {
        previousNode->next = currentNode->next; //previous node points the current node's next node
        delete (currentNode); // free current node
    }
}


int main()
{
    append(1);
    append(2);
    append(6);
    print();
    cout<<endl;
    deleteNode(2);
    print();
    return 0;
}
