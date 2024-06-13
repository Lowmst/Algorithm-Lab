#include<iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quick(int head, int tail, int arr[])
{
	if (head < tail) {
		int start = head;
		int end = tail;
		int base_index = head;
		int base = arr[base_index];
		while (start < end)
		{
			for (; start < end && arr[end] >= base; end--) {}
			for (; start < end && arr[start] <= base; start++) {}
			swap(arr + end, arr + start);
		}
		int current = start;
		swap(arr + current, arr + base_index);
		quick(head, current - 1, arr);
		quick(current + 1, tail, arr);
	}
}

int select(int head, int tail, int arr[], int k)
{
	if (head < tail) {
		int start = head;
		int end = tail;
		int base_index = head;
		int base = arr[base_index];
		while (start < end)
		{
			for (; start < end && arr[end] >= base; end--) {}
			for (; start < end && arr[start] <= base; start++) {}
			swap(arr + end, arr + start);
		}
		int current = start;
		swap(arr + current, arr + base_index);
		if (current == k - 1) {
			return arr[current];
		}
		else if (current > k - 1) {
			select(head, current - 1, arr, k);
		}
		else if (current < k - 1) {
			select(current + 1, tail, arr, k);
		}

	}
}

int main(void)
{
	int arr[] = { 35, 23, 42, 17, 56, 13, 99, 44, 76, 8, 19, 62, 91, 3, 45 };
	quick(0, 14, arr);
	for (int i = 0; i < 15; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n" << select(0, 14, arr, 8);
	return 0;
}