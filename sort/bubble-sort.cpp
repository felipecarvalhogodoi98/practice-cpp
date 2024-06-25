namespace F
{
  void bubbleSort(int* array, int size) {
    for (int i = size; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (array[j] > array[j+1]) {
          int aux = array[j];
          array[j] = array[j+1];
          array[j+1] = aux;
        }
      }
    }
  }
} // namespace F
