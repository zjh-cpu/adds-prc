// Assuming the class declaration and some initial methods are in Heap.tpp

// ... [Heap class declaration and other methods]

/*******************************/
// add values to the heap
/*******************************/
template <typename T>
void Heap<T>::insert(T value) {
    values.push_back(value);
    int index = values.size() - 1;

    // bubble up
    while (index > 0) {
        int parent_index = (index - 1) / 2;
        if (values.at(index) < values.at(parent_index)) {
            // swap with parent
            std::swap(values.at(index), values.at(parent_index));
            index = parent_index;
        } else {
            break;
        }
    }
}

/*******************************/
/* delete values from the heap */
/*******************************/
template <typename T>
void Heap<T>::remove(T value) {
    int index = -1;
    for (int i = 0; i < values.size(); i++) {
        if (values.at(i) == value) {
            index = i;
            break;
        }
    }

    if (index == -1) return; // value not found

    // replace the value with the last element in the heap
    values.at(index) = values.back();
    values.pop_back();

    // heapify to maintain heap property
    heapify(index);
    heapify((index - 1) / 2); // also, check for the parent just in case
}

/*******************************/
// find the smallest value in the heap
/*******************************/
template <typename T>
T Heap<T>::getMin() {
    if (values.empty()) throw std::runtime_error("Heap is empty");
    return values.at(0);
}

