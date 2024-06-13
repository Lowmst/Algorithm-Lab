#include<iostream>
int max_sum(int arr[], int n) {

	int sum = 0;
	int b = 0;

	for (int i = 0; i < n; i++) {

		if (b > 0)
			b += arr[i];
		else
			b = arr[i];

		if (b > sum) {
			sum = b;
			std::cout << arr[i] << " ";
		}
	}
	return sum;
}