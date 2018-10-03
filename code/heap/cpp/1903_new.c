//
//  main.cpp
//  Sort_and_BS
//
//  Created by Дарья Яковлева on 23.05.14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>


using namespace std;

const int N = 100010;
int n;
int heap[N];
int size;
void sift_down(int x) {
    int v = x;
    while ((2 * v + 1 < size && heap[v] < heap[2 * v + 1]) || (2 * v + 2 < size && heap[v] < heap[2 * v + 2])) {
        if  (2 * v + 1 < size && heap[v] < heap[2 * v + 1]  && (heap[2 * v + 1] >= heap[2 * v + 2] || (2 * v + 2 >= size))) {
            int t = heap[v];
            heap[v] = heap[2 * v + 1];
            heap[2 * v + 1] = t;
            v = 2 * v + 1;
        } else {
            if  (2 * v + 2 < size && heap[v] < heap[2 * v + 2]) {
                int t = heap[v];
                heap[v] = heap[2 * v + 2];
                heap[2 * v + 2] = t;
                v = 2 * v + 2;
            }
        }
    }
}

void heap_sort() {
    for (int i = n - 1; i >= 0; i--) {
        sift_down(i);			
    }
    for (int i = 0; i < n; i++) {
        int t = heap[0];
        heap[0] = heap[size - 1]; 
        heap[size - 1] = t;
        size--;
        sift_down(0);
    }
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    size = n;
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    heap_sort();
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }
}

