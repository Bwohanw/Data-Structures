
template <typename T>
List<T>::List(): head(NULL), tail(NULL), length(0) {}

template <typename T>
List<T>::List(const List<T>& other) {
    *this = other;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        _destroy();
        _copy(other);
    } 
    return *this;
}

template <typename T>
void List<T>::_copy(const List<T>& other) {
    head = NULL;
    tail = NULL;
    length = 0;
    ListNode* curr = NULL;

    ListNode* othercurr = other.head;
    while (othercurr != NULL) {
        ListNode* node = new ListNode(othercurr->data);
        if (head == NULL) {
            head = node;
        }

        node->prev = curr;

        if (curr != NULL) {
            curr->next = node;
        }
        curr = node;
        othercurr = othercurr->next;
    }
    tail = curr;
    
    length = other.length;
}


template <typename T>
List<T>::~List() {
    _destroy();
}

template <typename T>
void List<T>::_destroy() {
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
    length = 0;
}


template <typename T>
bool List<T>::operator==(const List<T>& other) const {
    if (length != other.length) return false;
    ListNode* h1 = head;
    ListNode* h2 = other.head;
    while (h1 != NULL) {
        if (h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& other) const {
    return !(*this == other);
}

template <typename T>
void List<T>::insertFront(const T& ndata) {
    ListNode* toinsert = new ListNode(ndata);
    toinsert->next = head;
    if (head != NULL) {
        head->prev = toinsert;
    } else {
        tail = toinsert;
    }
    head = toinsert;
    length++;
}

template <typename T>
void List<T>::insertBack(const T& ndata) {
    ListNode* toinsert = new ListNode(ndata);
    toinsert->prev = tail;
    if (tail != NULL) {
        tail->next = toinsert;
    } else {
        head = toinsert;
    }
    tail = toinsert;
    length++;
}

template <typename T>
void List<T>::insertAt(int index, const T& data) {
    if (index < 0 || index > length) throw std::out_of_range("index out of range");
    ListNode* newnode = new ListNode(data);
    if (index == length) {
        newnode->prev = tail;
        if (tail != NULL) tail->next = newnode;
        tail = newnode;
        if (head == NULL) head = newnode;
        length++;
        return;
    }
    ListNode* insertnode = step(head, index);
    newnode->prev = insertnode->prev;
    if (newnode->prev != NULL) newnode->prev->next = newnode;
    insertnode->prev = newnode;
    newnode->next = insertnode;
    if (head->prev != NULL) head = head->prev;
    if (tail->next != NULL) tail = tail->next;
    length++;
}

template <typename T>
void List<T>::removeAt(int index) {
    if (index < 0 || index >= length) throw std::out_of_range("index out of range");
    ListNode* toremove = step(head, index);
    ListNode* prev = toremove->prev;
    ListNode* next = toremove->next;
    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    if (toremove == head) {
        head = next;
    }
    if (toremove == tail) {
        tail = prev;
    }
    delete toremove;
    length--;
}

template <typename T>
void List<T>::reverse() {
    if (length <= 1) return;
    reverse(0, length - 1);
}

template <typename T>
void List<T>::reverse(int start, int stop) {
    if (start >= stop || stop >= length) throw std::out_of_range("invalid index/indices");
    
    //gets the portion of the list to reverse
    ListNode* startpt = step(head, start);
    ListNode* endpt = step(head, stop);


    //disconnects the portion to be removed (will put it back later)
    ListNode* startprev = startpt->prev;
    ListNode* endnext = endpt->next;
    startpt->prev = NULL;
    endpt->next = NULL;
    if (startprev != NULL) {
        startprev->next = NULL;
    }
    if (endnext != NULL) {
        endnext->prev = NULL;
    }

    ListNode* curr = startpt;

    //while we still have things to reverse, edit the pointers for curr
    while (curr != NULL) {
        ListNode* nxt = curr->next;
        curr->next = curr->prev;
        curr->prev = nxt;
        curr = nxt;
    }


    //reconnect back to the whole list
    //we want to connect startprev to endpt and startpt to endnext
    endpt->prev = startprev;
    if (startprev != NULL) {
        startprev->next = endpt;
    }
    startpt->next = endnext;
    if (endnext != NULL) {
        endnext->prev = startpt;
    }

    //resetting head and tail (if necessary)
    if (startpt == head) head = endpt;
    if (endpt == tail) tail = startpt;
}

template <typename T>
typename List<T>::ListNode* List<T>::splitmid(ListNode* start) {
    ListNode* mid = start;
    ListNode* hare = start; //similar strategy to turtle + hare algorithm for linked list cycle detection
    //the hare moves twice as fast as mid, meaning it gets to the end of the list while mid gets to the middle
    while (hare != NULL) {
        hare = hare->next;
        if (hare != NULL) {
            mid = mid->next;
            hare = hare->next;
        }
    }

    //check if there's only one node (only start node)
    if (mid == start) return start;

    //splits the midpoint off from the previous node
    ListNode* pre = mid->prev;
    mid->prev = NULL;
    pre->next = NULL;
    return mid;

}

//merges 2 sorted lists starting from first and second into 1 big list
//returns void because head and tail are always being reset
template <typename T>
void List<T>::merge(ListNode* first, ListNode* second) {
    /*sets head
    I think this is ok because we never use head outside of the initial call to mergesort
    and also this will set head to the actual head of the list, because the last time merge will be called
    (when recursing back up), will be the merging of the 2 big halves of the list
    so the other times we reset head will be overwritten by the last (correct) setting of head
    */
    head = first == NULL || second == NULL ? (first == NULL ? second : first) : (first->data < second->data) ? first : second;
    //LOL this is scuffed but its supposed to set it to the non-null if one is null, or null if both are null
    //otherwise it sets to the one with smaller data

    //updates whichever one got set to head
    first = head == first ? first->next : first;
    second = head == second ? second->next : second;

    ListNode* current = head;

    while (first != NULL && second != NULL) {
        //finds the next min
        ListNode* next = first->data < second->data ? first : second;

        //establishes the connection
        current->next = next;
        next->prev = current;
        current = next;

        first = next == first ? first->next : first;
        second = next == second ? second->next : second;
    }

    //one of the two is now null
    while (first != NULL) {
        tail = first; //sets the tail to the current "last", this is ok by similar logic to setting head

        current->next = first;
        first->prev = current;
        current = first;
        first = first->next;
    }

    while (second != NULL) {
        tail = second;

        current->next = second;
        second->prev = current;
        current = second;
        second = second->next;
    }

    return;
}

template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start) {
    ListNode* splitpoint = splitmid(start);
    if (splitpoint == start) return start;

    start = mergesort(start);
    splitpoint = mergesort(splitpoint);
    merge(start, splitpoint);
    return head;
}

template <typename T>
void List<T>::sort() {
    mergesort(head);
}

template <typename T>
typename List<T>::ListNode* List<T>::step(ListNode* start, int step) {
    if (step >= length) return NULL;
    for (int i = 0; i < step; i++) {
        start = start->next;
        if (start == NULL) return NULL;
    }
    return start;
}

template <typename T>
int List<T>::size() const {
    return length;
}

template <typename T>
bool List<T>::empty() const {
    return length == 0;
}

template <typename T>
void List<T>::print(std::ostream& os) const {
    os << "<";
    ListNode* curr = head;
    while (curr != NULL) {
        os << " " << curr->data;
        curr = curr->next;
    }
    os << " >";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
    list.print(os);
    return os;
}

template <typename T>
List<T>::ListNode::ListNode(): data(T()), next(NULL), prev(NULL) {
}

template <typename T>
List<T>::ListNode::ListNode(const T& data) : data(data), next(NULL), prev(NULL) {
}

