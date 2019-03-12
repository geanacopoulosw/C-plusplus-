#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Global Variables
double *v;
int count;
int size;

void Initialize() {	
	count = 0;
	size = 2;
	v = new double[size];
}

void Finalize() {
	if (count > 0) {
		delete[] v;
	}
}

void Grow() {
	double *tempv = new double[size];
	// Moves all the values into a temporary array
	for (int ii = 0; ii < size; ++ii) {
		tempv[ii] = v[ii];
	}
	// Free the old array
	delete[] v;
	// Create a new array with twice the size
	v = new double[size * 2];
	// Copy back all the values into the array
	for (int ii = 0; ii < size; ii++) {
		v[ii] = tempv[ii];
	}
	// Free the temp array
	delete[] tempv;
	// Double the size
	size = size * 2;
	cout << "Vector grown" << endl;
	cout << "Previous size: " << size / 2 << " elements" << endl;
	cout << "New capacity: " << size << " elements " << endl;
	
}

void Shrink() {
	cout << count << endl;
        double *tempv = new double[size / 2];
        // Moves all the values into a temporary array
        for (int ii = 0; ii < size / 2; ++ii) {
        	tempv[ii] = v[ii];
		cout << v[ii] << endl;
        }

        // Free the old array
        delete[] v;
        // Create a new array with half the size

	// v = new double[size / 2];
	// Copy back all the values into the array
	cout << "Moving it bACK INTO" << endl;
	v = tempv;
	
        // Half the size
	size = size / 2;
        cout << "Vector shrunk" << endl;
        cout << "Previous size: " << size * 2 << " elements" << endl;
        cout << "New capacity: " << size << " elements " << endl;

}

void AddElement() {
	double newvalue;
	if (count == size) {
		Grow();
	}
	cout << "Enter the new element: " << endl;
	cin >> newvalue;
	v[count] = newvalue;
	count++;
}

void PrintVector() {
	cout << "Printing all the values of the vector:" << endl;
	for (int ii = 0; ii < count; ++ii) {
		cout << "Element[" << ii << "] is " << v[ii] << endl;
	}
}

void RemoveElement() {
	double occupied = (double)(count-1) / (double)size;
	if (count <= 0) {
		cout << "No more elements can be removes" << endl;
	}
	else {
		/*
		if (occupied < .30) {
			Shrink();
		}
		*/
		v[count-1] = '\0';
		count--;
		cout << count << endl;
		if (occupied < .30) {
			Shrink();
		}
		// cout << "Occupied: " << occupied << endl;
	}

}

void InsertElement() {
	int index;
	int newvalue;
	cout << "Enter the index of new element: ";
	cin >> index;
	cout << "Enter the new element: ";
	cin >> newvalue;
	if (index < 0 || index > count) {
		cout << "Index is out of range" << endl;
	}
	else {
		if (count == size) {
			Grow();
		}
		for (int ii = count; ii > index; --ii) {
			v[ii] = v[ii - 1];
		}
		v[index] = newvalue;
		count++;
		cout << count << endl; 
	}

}

int main() {
	Initialize();
	int response = 1;  
	
	while (response != 5) {
  		cout << "Main Menu:" << endl;
  		cout << "1. Print the array " << endl;
  		cout << "2. Append element at the end " << endl;
  		cout << "3. Remove last element " << endl;
  		cout << "4. Insert one element " << endl;
		cout << "5. Exit " << endl;
  		cout << "Select an option: ";
  		cin >> response;
		
		switch(response) {
			case 1: cout << "You selected \"Print the array\"" << endl;
				PrintVector();
				break;
			case 2: cout << "You selected \"Append element at the end\"" << endl;
				AddElement();
				break;
			case 3: cout << "You selected \"Remove last element\"" << endl;
				RemoveElement();
				break;
			case 4: cout << "You selected \"Insert one element\"" << endl;
				InsertElement();
				break;
			case 5: cout << "You selected \"Exit\"" << endl;
				break;
			default: cout << "Invalid option, please try again" << endl;
				cin.clear();
				cin.ignore(10000, '\n'); 
				break;			
		}
		cout << endl;
	}
	Finalize();
	return 0;
}
