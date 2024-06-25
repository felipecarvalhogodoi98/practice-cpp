namespace F {
  void merge(int* array, int const l, int const m, int const r) {
    int const sizeArrayA = m - l + 1;
    int const sizeArrayB = r - m;

    int *arrayA = new int[sizeArrayA];
    int *arrayB = new int[sizeArrayB];

    for (int i = 0; i < sizeArrayA; i++)
      arrayA[i] = array[l + i];
    for (int j = 0; j < sizeArrayB; j++)
      arrayB[j] = array[m + 1 + j];

    int indexSubA = 0;
    int indexSubB = 0;
    int k = l;

    while (indexSubA < sizeArrayA && indexSubB < sizeArrayB) {
      if (arrayA[indexSubA] <= arrayB[indexSubB]){
        array[k] = arrayA[indexSubA];
        indexSubA++;
      }
      else {
        array[k] = arrayB[indexSubB];
        indexSubB++;
      }
      k++;
    }

    while (indexSubA < sizeArrayA) {
      array[k] = arrayA[indexSubA];
      k++;
      indexSubA++;
    }

    while (indexSubB < sizeArrayB) {
      array[k] = arrayB[indexSubB];
      k++;
      indexSubB++;
    }
  
    delete[] arrayA;
    delete[] arrayB;
  }

  void mergeSort(int* array, int const l, int const r) {
    if (l >= r )
      return;
    
    int m = l + (r - l) / 2;

    mergeSort(array, l, m);
    mergeSort(array, m+1, r);
    merge(array, l, m, r);
  }
}