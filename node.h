#pragma once
struct Node {
    int data;
    Node* next; // The next package in stack
    Node(int data) : data(data), next(nullptr){}
};