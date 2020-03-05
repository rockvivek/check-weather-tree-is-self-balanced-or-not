#include <iostream>
#include<math.h>
using namespace std;
struct Node {
    int data;
    Node *left,*right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int max(int x,int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int isBalanced(Node *root,int *height){
    if(!root){
        *height = 0;
        return true;
    }
    int lh = 0;
    int rh = 0;
    bool lb = isBalanced(root->left,&lh);
    bool rb = isBalanced(root->right,&rh);
    if(lh-rh>1 || lh-rh<-1){
        return false;
    }
    *height = max(lh,rh)+1;
    return (lb&&rb);

}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(2);
    int height = 0;
    if(isBalanced(root,&height)){
        cout<<"balanced";
    }
    else{
        cout<<"not balanced";
    }
    return 0;
}
