void BubbleSort(int Array[], short ArrayLength) {
	for (int i = 0; i < ArrayLength - 1; i++) {
		bool swapped = false; // to check if any swap happened

		// Last i elements are already sorted
		for (int j = 0; j < ArrayLength - i - 1; j++) {
			if (Array[j] > Array[j + 1]) {
				std::swap(Array[j], Array[j + 1]);
				swapped = true;
			}
		}
		// If no swaps happened in this pass, array is sorted
		if (!swapped) break;
	}
}
