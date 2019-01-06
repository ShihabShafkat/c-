#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
void insertnode(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct node* temp = root;
        while(1)
        {
            if(newnode->data <= temp->data)
            {
                //left
                if(temp->left == NULL)
                {
                    temp->left = newnode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                //right
                if(temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}
void Preorder(node *root)
{

    if (root == NULL)
        return;

    stack<node *> nodeStack;
    nodeStack.push(root);

    while (nodeStack.empty() == false)
    {
        struct node *newnode = nodeStack.top();
        printf ("%d ", newnode->data);
        nodeStack.pop();

        if (newnode->right)
            nodeStack.push(newnode->right);
        if (newnode->left)
            nodeStack.push(newnode->left);
    }
}
void postorder(node *root)
{
    map<node*, bool> visited;
    stack <node*> st;
    st.push(root);
    while (!st.empty())
    {
        node *t = st.top();
        if (t -> left != NULL && visited[t -> left] == false)
        {
            st.push(t->left);
        }
        else
        {
            if (t -> right != NULL && visited[t -> right] == false)
            {
                st.push(t -> right);
            }
            else
            {
                cout << t -> data << " ";
                visited[t] = true;
                st.pop();
            }
        }
    }
}

int main()
{
    root = NULL;
    insertnode(55);
    insertnode(40);
    insertnode(80);
    insertnode(34);
    insertnode(28);
    insertnode(38);
    insertnode(60);
    insertnode(90);
    Preorder(root);
    postorder(root);
    return 0;
}

