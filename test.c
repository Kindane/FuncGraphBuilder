#include "functions.h"

int main() {
    int n = 7;
    dot2f* arr = (dot2f*)malloc(sizeof(dot2f)*n);
    quadraticFunc(arr, 1, -7, 10);
    for (int i = 0; i < n; i++) {
        showDot2f(&arr[i]);
    }
    free(arr);
    return 0;
}
