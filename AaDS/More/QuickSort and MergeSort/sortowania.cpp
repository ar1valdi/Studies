#include <iostream>
using namespace std;


void coutTable(int* t, int start, int size) {
    for (int i = start; i < size; i++)
        cout << t[i] << " ";
}
/*
void merge(int* t, int start, int mid, int end) {
    int size1 = mid - start+1;
    int size2 = end - mid;

    int* t1 = new int[size1];
    int* t2 = new int[size2];

    for (int i = 0; i < size1; i++)
        t1[i] = t[start + i];
    for (int i = 0; i < size2; i++)
        t2[i] = t[mid + 1 + i];

    int id1 = 0;
    int id2 = 0;
    int idR = start;

    while (id1 < size1 && id2 < size2) {
        if (t1[id1] < t2[id2]) {
            t[idR++] = t1[id1++];
        }
        else {
            t[idR++] = t2[id2++];
        }
    }

    while (id1 < size1) {
        t[idR++] = t1[id1++];
    }
    while (id2 < size2) {
        t[idR++] = t2[id2++];
    }

    delete[] t1;
    delete[] t2;
}

void mergeSort(int* t, int id, int id2) {
    if (id >= id2)
        return;
    int mid = id + (id2 - id) / 2;
    mergeSort(t, id, mid);
    mergeSort(t, mid + 1, id2);
    merge(t, id, mid, id2);
}
*/
int rozdziel(int* t, int left, int right) {
    int pivot = t[left];
    while (1) {
        while (t[left] < pivot)
            left++;
        while (t[right] > pivot)
            right--;

        if (left >= right)
            return right;
        swap(t[left], t[right]);
        left++;
        right--;
    }
}
 
void quickSort(int *t, int left, int right) {
    if (left < right) {
        int q = rozdziel(t, left, right);
        quickSort(t, left, q);
        quickSort(t, q+1, right);
    }
}

void merge(int* t, int left, int mid, int right) {
    int size1 = mid - left+1;
    int size2 = right - mid;
    int* t1 = new int[size1];
    int* t2 = new int[size2];
    int id1 = 0;
    int id2 = 0;
    int idR = left;
    
    while (id1 < size1)
        t1[id1++] = t[idR++];
    while (id2 < size2)
        t2[id2++] = t[idR++];

    id1 = id2 = 0;
    idR = left;

    while (id1 < size1 && id2 < size2) {
        if (t1[id1] < t2[id2])
            t[idR++] = t1[id1++];
        else
            t[idR++] = t2[id2++];
    }

    while (id1 < size1)
        t[idR++] = t1[id1++];
    while (id2 < size2)
        t[idR++] = t2[id2++];

    delete[]t1;
    delete[]t2;
}

void mergeSort(int* t, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(t, left, mid);
        mergeSort(t, mid+1, right);
        merge(t, left, mid, right);
    }
}

int main()
{
    srand(time(NULL));
    int t[20];
    for (int i = 0; i < 20; i++)
        t[i] = rand() % 20;
    coutTable(t, 0, 20);
    cout << endl;
    mergeSort(t, 0, 19);
    coutTable(t, 0, 20);
}








/*
19 5 82 8 2 4 14 10 k=1
5 19 8 82 2 3 10 14 k=2
5 8 19 82 2 3 10 14 k=4
2 3 5 8 10 14 19 82 k=8
*/