int binSearch(const int s[], const int size, const int target) {
	int left = 0, right = size-1, mid;
	while (left < right) {
		mid = left + (right-left)/2;
		if (s[mid] > target) {
			right = mid-1;
		}
		else {
			if (s[mid] == target and s[mid+1] != target) return mid;
			left = mid+1;
		}
	}
	if (s[right] != target) return -1;
	return right;
}