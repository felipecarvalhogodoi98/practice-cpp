namespace F
{
  void selectionSort(int* array, int size) {
    for (int i = 0; i <= size; i++) {
      int small = i;

      for (int j = i; j <= size; j++) {
        if (array[j] < array[small]) {
          small = j;
        }
      }

      int aux = array[small];
      array[small] = array[i];
      array[i] = aux;
    }
  }
} // namespace F
