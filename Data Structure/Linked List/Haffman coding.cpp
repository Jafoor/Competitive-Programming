
/*
 Abu Jafor Mohammad Saleh
 ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 */

#include<cstdio>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>
#include <algorithm>
#include <unordered_map>
#define f first
#define s second
#define MOD 1000000007
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


struct Node
{
    char character;
    int fre;
    Node *left;
    Node *right;
};

Node* getNode(char character, int fre, Node* left, Node* right)
{
    Node* node = new Node();
    
    node->character = character;
    node->fre = fre;
    node->left = left;
    node->right = right;
    return node;
}

struct comparator
{
    bool operator()(Node* l, Node* r)
    {
        return l->fre > r->fre;
    }
};



void encode(Node* root, string str,unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;
    
    
    if (!root->left && !root->right) {
        huffmanCode[root->character] = str;
    }
    
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
    
    if (!root->left && !root->right)
    {
        cout << root->character;
        return;
    }
    
    index++;
    
    if (str[index] =='0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}


void HuffmanTree (string paragraf)
{
    unordered_map<char, int> fre;
    for (char character: paragraf) {
        fre[character]++;
    }
    
    priority_queue<Node*, vector<Node*>, comparator> priority;
    for (auto pair: fre) {
        
        priority.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    
    while (priority.size() != 1)
    {
        
        Node *left = priority.top();
        priority.pop();
        Node *right = priority.top();
        priority.pop();
        int sum = left->fre + right->fre;
        priority.push(getNode('\0', sum, left, right));
    }
    
    Node* root = priority.top();
    
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    
    cout << "Huffman Codes are :" <<endl;
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }
    
    cout << "\nOriginal string was :\n" << paragraf <<endl;
    string str = "";
    for (char character: paragraf) {
        str += huffmanCode[character];
    }
    
    cout << "\nThe String after Encoding :\n" << str <<endl;
    
    int index = -1;
    cout << "\nAfter Decoding : \n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}

int main()
{
    fast;
    string paragraf = "Huffman coding is very hard for implementation.";
    HuffmanTree(paragraf);
    return 0;
}
