//Author: Pavel Martinez
//Date: 07-16-2023
//Project name: Project 7
//CSCI121_VA_U2023 Computer Science 1

#include <iostream>
using namespace std;

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line

int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// pre-condition: arr has given size Of course, a main function is needed.The main function will look like following :
// post-condition: the elements in arr are rearranged from least to largest

void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void menu();
//menu for user

int main() {
	int choice;
	int a[9];
	do {
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			fill_array(a, 9);
			cout << "Enter the key you want to search: ";
			int key;
			cin >> key;
			int index = linear_search(a, 9, key);
			if (index == -1)
				cout << "The key " << key << " is not in array\n";
			else
				cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
			break;
		}
		case 2:
		{
			fill_array(a, 9);
			select_sort(a, 9);
			cout << "After sort, the array is:\n";
			print_array(a, 9);
			break;
		}
		case 3:
		{
			fill_array(a, 9);
			insert_sort(a, 9);
			cout << "After sort, the array is:\n";
			print_array(a, 9);
			break;
		}
		case 4:
		{
			fill_array(a, 9);
			bubble_sort(a, 9);
			cout << "After sort, the array is:\n";
			print_array(a, 9);
			break;
		}
		case 5:
		{
			cout << "Thank you for using the array functions\n";
			break;
		}
		default:
		{
			cout << "Wrong choice. Please choose from menu: ";
			break;
		}
		}
	} while (choice != 5);

	return 0;
}

void fill_array(int arr[], int size) {
	cout << "Enter up to " << size << " integers: ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void print_array(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << "\t";
		if (i % 5 == 4)
			cout << endl;
	}
	cout << endl;
}


int linear_search(int arr[], int size, int key) {
	{
		int i = 0;
		bool found = false; //found is used as a flag to record whether or not the target element has been found
		while ((!found) && (i < size)) // check the array elements one after the other to see whether any of them equals the key value
			if (arr[i] == key)
				found = true; //If the target element is found in the array found is true
			else
				i++;
		if (found)
			return i; // Target value found return index
		else
			return -1; // Target value not found return -1
	}
}

void select_sort(int arr[], int size) {
	// step  through position 0 to size - 2
		//find the smallest element from this position to the end of the array
		//swap it with the element at the position
	for (int position = 0; position < size - 1; position++) {
		int index_of_smallest = position; //assume arr[position] is the smallest
		for (int i = position + 1; i < size; i++) {
			if (arr[i] < arr[index_of_smallest]) {
				index_of_smallest = i;
			}
		}
		//index_of_smallest is the index of the smallest element among arr[position].....ar[size - 1]
		int temp = arr[position];
		arr[position] = arr[index_of_smallest];
		arr[index_of_smallest] = temp;
	}
	
}

void insert_sort(int arr[], int size) {
	for (int i = 1; i < size; i++) { // starting i off at 1 that way the first key value we look at is 2 element in the array
		int key = arr[i]; // This will store the current key values into the variable key
		int j = i - 1; // J will keep track of our position in that sorted portion of the array as we shift over values
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;

	}
}

void bubble_sort(int arr[], int size) {
	
		// Bubble largest number toward the right
		for (int i = size - 1; i > 0; i--)
			for (int j = 0; j < i; j++)
				if (arr[j] > arr[j + 1])
				{
					// Swap the numbers
					int temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
}

void menu() {
		cout << "\n**********************";
		cout << "\n*       Menu         *";
		cout << "\n* 1. Linear Search   *";
		cout << "\n* 2. Select Sort     *";
		cout << "\n* 3. Insert Sort     *";
		cout << "\n* 4. Bubble Sor      *";
		cout << "\n* 5. Quit            *";
		cout << "\n**********************";
		cout << endl;
}