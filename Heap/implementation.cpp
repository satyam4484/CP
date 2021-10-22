//SATYAM SINGH  
// time complecity -> O(n)  for inserting which is faster than O(nlogn)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minHeap{
    int size;
    vector<int>heap;
    int parent(int i) {return i/2;}
    int leftChild(int i) {return  i*2+1;}
    int rightChild(int i) {return i*2+2;}

public:
    minHeap(int );
    int top();
    void heapify(int);
    void pop();
    void push(int );
    bool empty();
};

minHeap::minHeap(int capactiy){
    this->size = 0;
    this->heap.resize(capactiy);
}

int minHeap::top() {
    if(size == 0) return -1;
    return this->heap[0];
}

void minHeap::heapify(int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int small = i;

    if((l < size) and (heap[l] < heap[small])) small = l;
    if((r<size)  and (heap[r] < heap[small])) small = r;

    if(small != i) {
        swap(heap[i],heap[small]);
        heapify(small);
    }
}
void minHeap::pop() {
    if(size == 0) return ;
    swap(heap[0],heap[size-1]);
    size--;
    heapify(0);
}

void minHeap::push(int data) {
    if(size == heap.size()) return ;
    size++;
    int i=size-1;
    heap[i] = data;

    while(i!=0 and heap[i] < heap[parent(i)]) {
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
    }
}

bool minHeap::empty() {
    return this->size ==0; 
}

int main( ) {
    minHeap heap(50);
    for(int i=0;i<5;i++) {
        int x;
        cin>>x;
        heap.push(x);
    }
    cout<<heap.top()<<endl;
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    cout<<heap.top()<<endl;
    cout<<heap.empty()<<endl;
    return 0;
}