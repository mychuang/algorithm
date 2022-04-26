#include <stdio.h>

// Function to return the only odd
// occurring element
int findOdd(int arr[], int length) {
    int res = 0;

    for (int i = 0; i < length; i++){
        res = res ^ arr[i];
    }
    return res;
}

int main() {
    
    int arr[] = { 12, 12, 14, 90, 14, 14, 14 };

    int length = sizeof(arr) / sizeof(arr[0]);

    printf("The odd occurring element is %d ",
           findOdd(arr, length));

    return 0;
}