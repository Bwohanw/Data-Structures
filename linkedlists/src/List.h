#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
    private:
    class ListNode {
        public:
        ListNode();
        ListNode(const T& ndata);
        ListNode* next;
        ListNode* prev;
        const T data;
    };

    public:
    List();
    List(const List<T>& other);
    List<T>& operator=(const List<T>& rhs);
    ~List();

    int size() const;
    void print(std::ostream& os = std::cout) const;
    bool empty() const;

    void insertFront(const T& data);
    void insertBack(const T& data);
    void insertAt(int index, const T& data);
    void removeAt(int index);
    void reverse(); //reverses the whole list
    void reverse(int start, int stop);//reverses from index start to index stop (inclusive)

    void sort();

    private:

    ListNode* head;
    ListNode* tail;
    int length;

    ListNode* step(ListNode* start, int step);

    void _copy(const List<T>& other);
    void _destroy();

    ListNode* splitmid(ListNode* start);//splits the list in the middle, returns the latter half's head node
    void merge(ListNode* first, ListNode* second);

    ListNode* mergesort(ListNode* start);
};


#include "List.hpp"