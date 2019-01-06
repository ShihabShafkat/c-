#include <bits/stdc++.h>
using namespace std;
struct heap {
    char ch;
    int freq;
    heap *leftNode, *rightNode;
    heap(char data, int freq){
        leftNode = NULL;
        rightNode = NULL;
        this->ch = data;
        this->freq = freq;
    }
};
struct compare {
    bool operator()(heap* l, heap* r){
        return (l->freq > r->freq);
    }
};
int main(){
    struct heap *left, *right, *top;
    priority_queue<heap*, vector<heap*>, compare> minHeap;
    char charArr[100];
    int n,freq[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>charArr[i]>>freq[i];
    }
    for (int i=0; i<n; i++){
        minHeap.push(new heap(charArr[i], freq[i]));
    }
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new heap('$', left->freq + right->freq);
        top->leftNode = left;
        top->rightNode = right;
        minHeap.push(top);
    }
    return 0;
}

