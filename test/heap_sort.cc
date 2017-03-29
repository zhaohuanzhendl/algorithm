/*
 * Filename   heap_sort.cc
 * CreateTime 2017-03-28 22:15:09
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

void max_heapify(int arr[], int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;

    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son]) {
            return;
        } else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 +1;
        } 
    }
}

void heap_sort(int arr[], int len)
{
    int i;

    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    for (i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1); // becose "i - 1", make sure "i > 0", not "i >= 0"
    }
}

//unit test
int main()
{
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0,
                    1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };

    int len = (int) sizeof(arr) / sizeof(*arr);

    heap_sort(arr, len);

    cout << "output arr after heap_sort:" << endl;
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;

}
