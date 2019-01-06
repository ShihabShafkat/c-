#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
void insertnode(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
    }else{
      struct node* temp = root;
      while(1){
        if(newnode->data <= temp->data){
            //left
            if(temp->left == NULL){
                temp->left = newnode;
                break;
            }else{
                temp = temp->left;
            }
        }else{
            //right
             if(temp->right == NULL){
                temp->right = newnode;
                break;
            }else{
                temp = temp->right;
            }
        }
      }
    }
}
void preorder(struct node* r){
    if(r == NULL)
        return;
    printf(" %d\t",r->data);
    preorder(r->left);
    preorder(r->right);

}
void inorder(struct node* r){
    if(r == NULL)
        return;
    inorder(r->left);
    printf(" %d\t",r->data);
    inorder(r->right);
}
void postorder(struct node* r){
    if(r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    printf(" %d\t",r->data);
}
int main(){
    root = NULL;
    insertnode(55);
    insertnode(40);
    insertnode(80);
    insertnode(34);
    insertnode(28);
    insertnode(38);
    insertnode(60);
    insertnode(90);
    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}
