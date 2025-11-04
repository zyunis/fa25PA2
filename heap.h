//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size < 64) {
            data[size] = idx;
            size++;
            upheap(size - 1, weightArr);
        }
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size != 0) {
            int temp = data[0];
            data[0] = data[size - 1];
            size--;
            if (size > 0)
                downheap(0, weightArr);
            return temp;
        }
        return -1;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if (size <= 1) {
            return;
        }
        while (weightArr[data[pos]] < weightArr[data[(pos - 1) / 2]]) {
            swap(pos, (pos - 1) / 2);
            pos = (pos - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int leftC = pos * 2 + 1;
        int rightC = pos * 2 + 2;
        if (size <= 1) {
            return;
        }
        while (weightArr[data[pos]] > weightArr[data[leftC]] || weightArr[data[pos]] > weightArr[data[rightC]]) {
            int leftC = pos * 2 + 1;
            int rightC = pos * 2 + 2;
            if (weightArr[data[leftC]] < weightArr[data[rightC]]) {
                swap(pos, leftC);
            }
            else {
                swap(pos, rightC);
            }
        }
    }

    void swap(int pos1, int pos2) {
        int temp = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = temp;
    }
};

#endif