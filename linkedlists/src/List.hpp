
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
List<T>::size() const {
    return length;
}

template <typename T>
List<T>::empty() const {
    return length == 0;
}

template <typename T>
void List<T>::print(ostream& os) const {
    os << "<"
    ListNode* curr = head;
    while (curr != NULL) {
        os << " " << curr->data;
        curr = curr->next;
    }
    os << " >";
}

template <typename T>
std::ostream& operator<<(ostream& os, const List<T>& list) {
    list.print(os);
    return os;
}

template <typename T>
List<T>::ListNode::ListNode(): data(T()), next(NULL), prev(NULL) {
}

template <typename T>
List<T>::ListNode::ListNode(const T& data) : data(data), next(NULL), prev(NULL) {
}

