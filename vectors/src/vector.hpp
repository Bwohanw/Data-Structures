

template <typename T>
Vector<T>::Vector(): capacity_(10), size_(0) {
    data_ = new T[capacity_];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    *this = other;
}

template <typename T>
Vector<T>::Vector(int size, T data): capacity_(2*size), size_(size) {
    if (capacity_ == 0) capacity_ = 10; //if size is 0
    data_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        data_[i] = data;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        _destroy();
        _copy(other);
    }
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    if (size_ != other.size_) return false;
    for (int i = 0; i < size_; i++) {
        if (data_[i] != other[i]) return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !(*this == other); 
}

template <typename T>
Vector<T>::~Vector() {
    _destroy();
}

template <typename T>
void Vector<T>::_copy(const Vector<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = new T[capacity_];

    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
void Vector<T>::_destroy() {
    capacity_ = 0;
    size_ = 0;
    if (data_ != NULL) delete[] data_;
    data_ = NULL;
}


template <typename T>
void Vector<T>::print(std::ostream& os) const {
    os << "<";
    for (int i = 0; i < size_; i++) {
        os << " " << data_[i];
    }
    os << " >";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    v.print(os);
    return os;
}

template <typename T>
int Vector<T>::size() const {
    return size_;
}

template <typename T>
int Vector<T>::max_size() const {
    return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
void Vector<T>::push_back(const T& data) {
    data_[size_++] = data;
    checksize();
}

template <typename T>
void Vector<T>::pop_back() {
    //Does not delete the element if it's allocated on the heap;
    if (empty()) throw std::out_of_range("Illegal remove from empty vector");
    size_--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return data_[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return data_[index];
}


template <typename T>
T& Vector<T>::at(int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Invalid Index");
    }
    return data_[index];
}

template <typename T>
const T& Vector<T>::at(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Invalid Index");
    }
    return data_[index];
}

template <typename T>
void Vector<T>::insert(int index, const T& elem) {
    if (index < 0 || index > size_) {
        throw std::out_of_range("Invalid Index");
    }
    for (int i = size_; i > index; i--) {
        data_[i] = data_[i-1];
    }
    data_[index] = elem;
    size_ += 1;
    checksize();
}

template <typename T>
void Vector<T>::removeAt(int index) {
    if (index < 0 || index >= size_) throw std::out_of_range("Invalid Index");
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i+1];
    }
    size_ -= 1;
}

template <typename T>
int Vector<T>::firstIndexOf(const T& data) {
    for (int i = 0; i < size_; i++) {
        if (data_[i] == data) return i;
    }
    return -1;
}

template <typename T>
int Vector<T>::lastIndexOf(const T& data) {
    if (size_ == 0) return -1;
    for (int i = size_-1; i > 0; i--) {
        if (data_[i] == data) return i;
    }
    return -1;
}

template <typename T>
void Vector<T>::reverse() {
    for (int i = 0; i < size_/2; i++) {
        T temp = data_[i];
        data_[i] = data_[size_ - i - 1];
        data_[size_ - i - 1] = temp;
    }
}

template <typename T>
void Vector<T>::checksize() {
    if (capacity_ == size_) _resize();
}

template <typename T>
void Vector<T>::_resize() {
    capacity_ *= 2;
    T* newdata = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        newdata[i] = data_[i];
    }
    delete[] data_;
    data_ = newdata;
}

template <typename T>
void Vector<T>::clear() {
    if (data_ != NULL) delete[] data_;
    data_ = new T[capacity_];
    size_ = 0;
}
