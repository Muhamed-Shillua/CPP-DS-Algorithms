void SelectionSort(int Array[], short ArrayLength) {
	int min = 0;
	for (int i = 0; i < ArrayLength - 1; i++) {
		min = i; // assume the current index is the smallest
		for (int j = i + 1; j < ArrayLength; j++) {
			if (Array[j] < Array[min]) {
				min = j; // update min index
			}
		}
		std::swap(Array[min], Array[i]); // swap once per pass
	}
}
