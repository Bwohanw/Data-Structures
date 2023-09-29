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