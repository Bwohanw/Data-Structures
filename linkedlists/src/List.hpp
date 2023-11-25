
template <typename T>
List<T>::List(): head(NULL), tail(NULL), length(0) {}

template <typename T>
List<T>::List(const List<T>& other) {
    _copy(other);
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
void List<T>::reverse() {
    if (length <= 1) return;
    reverse(0, length - 1);
}

template <typename T>
void List<T>::reverse(int start, int stop) {
    if (start >= stop || stop >= length) return;
    
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

