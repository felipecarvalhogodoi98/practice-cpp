namespace F {
  void swap(int* array, int indexA, int indexB) {
    int aux = array[indexA];
    array[indexA] = array[indexB];
    array[indexB] = aux;
  }

  int partition(int* array, int const l, int const r) {
    int pivot = array[r];

    int i = (l - 1);

    for (int j = l; j <= r; j++) {
      if (array[j] < pivot) {
        i++;
        swap(array, i, j);
      }
    }
    swap(array, i+1, r);
    return i + 1;
  }

  void quickSort(int* array, int const l, int const r) {
    if (l >= r )
      return;

    int pivot = partition(array, l, r);

    quickSort(array, l, pivot - 1);
    quickSort(array, pivot + 1, r);
  }
}
