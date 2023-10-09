#include <map>

template <typename T>
void mergesort(Vector<T>& vect) {
    //calls mergesort helper
    mergesort(vect, 0, vect.size()-1);
}

template <typename T>
void mergesort(Vector<T>& vect, int lower, int upper) {
    //mergesort helper. lower/upper represents portion of the list to mergesort, inclusive of lower and upper
    if (upper <= lower) return;
    int mid = (lower+upper)/2;
    mergesort(vect,lower,mid);
    mergesort(vect,mid+1,upper);
    merge(vect, lower, mid, upper);

}

template <typename T>
void merge(Vector<T>& vect, int lower, int mid, int upper) {
    //inclusive of lower and upper
    int secondpos = mid + 1;

    //already sorted, do nothing
    if (vect[mid] <= vect[secondpos]) return;
    
    while (lower <= mid && secondpos <= upper) {
        if (vect[lower] < vect[secondpos]) {
            lower++;
            continue;
        }
        T tmp = vect[secondpos];
        int idx = secondpos;
        while (idx != lower) {
            vect[idx] = vect[idx-1];
            idx--;
        }
        vect[lower] = tmp;
        lower++;
        mid++;
        secondpos++;
    }
}

template <typename T>
void quicksort(Vector<T>& vect) {
    quicksort(vect, 0, vect.size());
}

template <typename T>
void quicksort(Vector<T>& vect, int lower, int upper) {
    if (lower >= upper) return;
    //arbitrarily choose lower as the partition index
    int partitionIdx = partition(vect, lower, upper, lower);
    quicksort(vect, lower, partitionIdx);
    quicksort(vect, partitionIdx+1,upper);

}

template <typename T>
void swap(Vector<T>& vect, int idx1, int idx2) {
    T tmp = vect[idx1];
    vect[idx1] = vect[idx2];
    vect[idx2] = tmp;
}

template <typename T>
int partition(Vector<T>& vect, int lower, int upper, int partitionIdx) {
    //upper is exclusive
    upper -= 1;
    swap(vect, upper,partitionIdx);
    int counter = lower;
    for (int i = lower; i < upper; i++) {
        if (vect[i] < vect[upper]) {
            swap(vect, i, counter);
            counter++;
        }
    }
    swap(vect, counter,upper);
    return counter;

}

template <typename T>
int binarySearch(Vector<T>& vect, const T& target) {
    int lower = 0;
    int upper = vect.size();
    while (lower < upper) {
        int mid = (lower+upper)/2;
        if (vect[mid] == target) return mid;
        else if (vect[mid] < target) lower=mid+1;
        else upper = mid;
    }
    return -1;
}