void InsertionSort(int Array[], short ArrayLength) {
	for (int i = 1; i < ArrayLength; i++) {
		int key = Array[i];     // current element to insert
		int j = i - 1;

		// shift larger elements to the right
		while (j >= 0 && Array[j] > key) {
			Array[j + 1] = Array[j];
			j--;
		}

		// place key in its correct position
		Array[j + 1] = key;
	}
}
