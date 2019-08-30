//  dataStructureLinkedList
//  Copyright © 2019 Abu Jafor Mohammad Saleh. All rights reserved.
//

#include <iostream>

using namespace std;



struct node{
    
    int data;
    node *right, *left;
    
    node()
    {
        left = NULL;
        right = NULL;
    }
};

node *root;


void insert (int data)
{
    if(root == NULL)
    {
        root = new node();
        root->data = data;
    }
    
    else{
        node *current_node = root, *parent = nullptr;
        
        while(current_node != NULL)
        {
            if(data < current_node->data)
            {
                parent = current_node;
                current_node = current_node->left;
            }
            
            else{
                parent = current_node;
                current_node = current_node->right;
            }
        }
        
        node *newnode = new node();
        newnode->data = data;
        
        if(newnode->data < parent->data)
            parent->left = newnode;
        
        else{
            parent->right = newnode;
        }
    }
}



void print_preorder(node *current){
    
    if(current == NULL) return;
    cout<<current->data<<endl;
    print_preorder(current->left);
    print_preorder(current->right);
}

int main()
{
    insert(100);
    insert(50);
    insert(130);
    insert(150);
    insert(10);
    insert(56);
    insert(109);
    print_preorder(root);
}
