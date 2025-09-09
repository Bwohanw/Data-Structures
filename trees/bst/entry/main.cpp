#include "../src/bst.h"


int main() {
    Bst<int> b;
    for (int i = 0; i < 10; i++) b.insert(i+1);
    return 0;
}