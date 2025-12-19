#include <iostream>
using namespace std;

int LinearSearch(int* arr, int len, int key) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int LinearSearchRec(int* arr, int len, int key) {
    return LinearSearchRec(arr, len, key, 0);
}

int LinearSearchRec(int* arr, int len, int key, int i) {
    if (i >= len) {
        return -1;
    } else if (arr[i] == key) {
        return i;
    }

    return LinearSearchRec(arr, len, key, i + 1);
}

//Sorted array
int BinarySearch(int* arr, int len, int key) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int BinarySearchRec(int* arr, int len, int key) {
    return BinarySearchRec(arr, key, 0, len - 1);
}

int BinarySearchRec(int* arr, int key, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (key < arr[mid]) {
        return BinarySearchRec(arr, key, low, mid - 1);
    } else {
        return BinarySearchRec(arr, key, mid + 1, high);
    }
}

void SelectionSort(int * arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;

        //find the index of the smallest element after i
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        //swap if needed
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//Inner loop
int findMinIndex(int* arr, int len, int i, int j, int minIndex) {
    if(j == len) {
        return minIndex;
    }

    if (arr[j] < arr[minIndex]) {
        minIndex = j;
    }

    return findMinIndex(arr, len, i, j + 1, minIndex);
}

//Outer loop
void SelectionSortRec(int* arr, int len, int i) {
    if (i == len - 1) {
        return;
    }

    int minIndex = findMinIndex(arr, len, i, i + 1, i);

    //swap
    if (minIndex != i) {
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    SelectionSortRec(arr, len, i + 1);

}

void SelectionSortRec(int* arr, int len) {
    SelectionSortRec(arr, len, 0);
}

void BubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Inner loop
void bubblePass(int* arr, int j, int end) {
    if (j == end) {
        return;
    }

    if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }

    bubblePass(arr, j + 1, end);
}

//Outer loop
void BubbleSortRec(int* arr, int len, int i) {
    if (i == len - 1) {
        return;
    }

    //do one bubbling pass
    bubblePass(arr, 0, len - i - 1);

    //next pass
    BubbleSortRec(arr, len, i + 1);
}

void BubbleSortRec(int* arr, int len) {
    BubbleSortRec(arr, len, 0);
}

void InsertionSort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1; 

        //Move larger elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        //Insert key in the correct position
        arr[j + 1] = key;
    }
}

void insertSorted(int* arr, int n) {
    int key = arr[n - 1];
    int  j = n - 2;

    while(j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

void InsertionSortRec(int* arr, int n) {
    if (n <= 1) {
        return;
    }

    //Sort first n-1 elements
    InsertionSortRec(arr, n - 1);

    //Insert n-th element into sorted sublist
    insertSorted(arr, n);
}

void InsertionSortRec(int* arr, int len) {
    InsertionSortRec(arr, len);
}

/* //Question 1
void ReverseStack(Stack& s) {
    Stack temp1;
    Stack temp2;

    // Move s -> temp1 (reverse #1)
    while (!s.IsEmpty()) {
        temp1.Push(s.Pop());
    }

    // Move temp1 -> temp2 (reverse #2, back to original order)
    while (!temp1.IsEmpty()) {
        temp2.Push(temp1.Pop());
    }

    // Move temp2 -> s (reverse #3, now reversed overall)
    while (!temp2.IsEmpty()) {
        s.Push(temp2.Pop());
    }
} */

/* //Question 3
int RemoveBottom(Stack& s) {
    if (s.isEmpty()) {
        return 0;
    } else {
        Stack temp;
        while(!s.isEmpty()) {
           temp.push(s.pop());
        }

        int val = temp.pop();

        while(!temp.isEmpty()) {
           s.push(temp.pop());
        }
        
        return val;
    }
} */

/* //Question 4
void AddBottom(Stack& s, int val) {  
    if (s.IsEmpty()) {
        s.Push(val);
        return;
    } else {

        Stack temp;
        while(!s.isEmpty()) {
           temp.push(s.pop());
        }

        temp.push(val);

        while(!temp.isEmpty()) {
           s.push(temp.pop());
        }
        
    }
} */

/* //Question 5
void SortStack(Stack& s) {
    if (s.isEmpty()) {
        return;
    } else {
        Stack temp;
        while(!s.isEmpty()) {
            int x = s.Pop();

            while(!temp.IsEmpty() && temp.Peek() > x) {
                s.Push(temp.Pop());
            }

           temp.push(x);
        }


        while(!temp.isEmpty()) {
           s.push(temp.pop());
        }
        
    }
} */

/* int RemoveLastN(Queue& q, int n) {
    if (q.IsEmpty()) {
        return 0;
    } else {
        int count = 0;
        int sum = 0;
        Queue temp;

        int size = 0;
        while (!q.IsEmpty()) {
            temp.Enqueue(q.Dequeue);
            size++;
        }

        while (!temp.IsEmpty()) {
            if (size - count == n) {
                break;
            }
            q.Enqueue(temp.Dequeue);
            count++;
        }

        int curr
        for (int i = 0; i < n; i++) {
            curr = temp.Dequeue();
            sum += curr;
        }

        return sum;

    }
} */

/* void SortLL() {
    if (IsEmpty() || head->next == nullptr) {
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        Node* minNode = current;
        Node* temp = current->next;

        while(temp != nullptr) {
            if (temp->value < minNode->value) {
                minNode = temp;
            }
            temp = temp->next;
        }

        int t = current->value;
        current->value = minNode->value;
        minNode->value = t;

        current = current->next;
    }
} */