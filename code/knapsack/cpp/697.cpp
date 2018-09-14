/*
 * author: Moenika Chowdhury
 * date: December 4th, 2017
 * pledge: I pledge my honor that I've abided by the Stevens honor system.
 * -moenika chowdhury
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Using structs to make this readable per instructions

struct Item { //in the instructions
	unsigned int item_number, weight, value;
	string description;

	explicit Item(const unsigned int item_number, const unsigned int weight,
			const unsigned int value, const string &description) :
		item_number(item_number), weight(weight), value(value),
				description(description) {
	}

	friend std::ostream& operator<<(std::ostream& os, const Item &item) {
		os << "Item " << item.item_number << ": " << item.description << " ("
				<< item.weight << (item.weight == 1 ? " pound" : " pounds")
				<< ", $" << item.value << ")";
		os.flush();
		return os;
	}
};

void print_used(vector<Item> used) { //this function gets the items going inside the inventory
	unsigned int weight = 0;
	unsigned int value = 0;

	cout << "Items to place in knapsack:"; //output
	if (used.size() < 1) { //if there are less than one in size then no items go in knap

		cout << " None" << endl;
	} else {

		cout << endl;
	}
	for (int i = used.size() - 1; i >= 0; i--) { //assigning weight and value arrays
		weight = weight + used[i].weight;
		value = value + used[i].value;
		cout << "   " << used[i] << endl;
	}
	cout << "Total weight: " << weight;
	if (weight == 1) { //outputting correctly due to "s"
		cout << " pound";
	} else {
		cout << " pounds";
	}
	cout << endl;
	cout << "Total value : $" << value << endl;
}

void search_used(int capacity, vector<Item> inv, int** arr) { //this searches for items already in the inventory
	int i = inv.size();
	int j = capacity;

	vector<Item> used; //this needs to be a vector for adding elements
	while (i > 0 && j > 0) {
		if (arr[i][j] != arr[i - 1][j]) {
			used.push_back(inv[i - 1]); //adds element to the end of vector used
			j -= inv[i - 1].weight;
			i--;

		} else {
			i--;
		}
	}

	print_used(used); //need to call print used to check for duplicates
}

void print_inventory(int capacity, vector<Item> inv) { //formatting the print
	cout << "Candidate items to place in knapsack:" << endl;
	for (unsigned int i = 0; i < inv.size(); i++) {
		cout << "   " << inv[i] << endl;
	}
	cout << "Capacity: " << capacity;
	if (capacity == 1) {
		cout << " pound";
	} else {
		cout << " pounds";
	}
	cout << endl;
}

void knapsack(int capacity, vector<Item> inv) { //knapsack alg
	unsigned int cap = capacity;
	int **arr = new int*[inv.size() + 1]; //building the table to go through the inventory
	for (unsigned int i = 0; i < inv.size() + 1; i++) {
		arr[i] = new int[capacity + 1];

		for (unsigned int j = 0; j < cap + 1; j++) { //first base case
			if (j == 0 || i == 0) {
				arr[i][j] = 0;
			} else { //the item isn't included if the weight of the nth item > knapsack capacity
				if (j < inv[i - 1].weight) {
					arr[i][j] = arr[i - 1][j];
				} else {

					//implementing useit and loseit
					int useit = inv[i - 1].value + arr[i - 1][j
							- inv[i - 1].weight];//with nth item
					int loseit = arr[i - 1][j]; //without nth item

					if (useit > loseit) { //gets the max of both
						arr[i][j] = useit;
					} else {
						arr[i][j] = loseit;
					}
				}
			}
		}
	}

	search_used(capacity, inv, arr); //calling search_used to make sure of no dupes

	for (unsigned int k = 0; k < inv.size() + 1; k++) {
		delete[] arr[k];
	}

	delete[] arr;
}

int main(int argc, char * const argv[]) { //error checking

	if (argc != 3) { //error checking if there are no arguments
		cerr << "Usage: ./knapsack <capacity> <filename>" << endl;
		return 1;
	}

	istringstream iss(argv[1]);
	int cap;

	if (!(iss >> cap)) { //checking if the capacity is valid
		cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
		return 1;
	}

	if (cap < 0) { //checking for negative numbers
		cerr << "Error: Bad value '" << cap << "' for capacity." << endl;
		return 1;
	}

	ifstream file(argv[2]); //checking if there is a file to open
	if (!(file.is_open())) {
		cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
		return 1;
	}

	vector<Item> inv;
	string curr, description, temp;
	stringstream ss;
	int i = 1, weight, value, pos = 0;

	while (getline(file, curr)) {

		temp = curr;
		if ((pos = temp.find(",")) == -1) {
			cerr << "Error: Line number " << i << " does not contain 3 fields."
					<< endl;
			return 1;
		}
		temp = curr;
		temp.erase(0, pos + 1);

		if ((pos = temp.find(",")) == -1) {
			cerr << "Error: Line number " << i << " does not contain 3 fields."
					<< endl;
			return 1;
		}

		temp.erase(0, pos + 1);

		if ((pos = temp.find(",")) > -1) {
			cerr << "Error: Line number " << i << " does not contain 3 fields."
					<< endl;
			return 1;
		}

		pos = curr.find(",");
		description = curr.substr(0, pos);
		curr.erase(0, pos + 1);
		pos = curr.find(",");
		temp = curr.substr(0, pos);
		ss << temp;

		if (!(ss >> weight) || weight <= 0) {
			cerr << "Error: Invalid weight '" << temp << "' on line number "
					<< i << "." << endl;
			return 1;
		}

		curr.erase(0, pos + 1);
		ss.clear();
		temp = curr;
		ss << temp;

		if (!(ss >> value) || value < 0) {
			cerr << "Error: Invalid value '" << temp << "' on line number "
					<< i << "." << endl;
			return 1;
		}

		Item item(i, weight, value, description);
		inv.push_back(item);
		ss.clear();
		i++;
	}

	//prints inventory with calling the knapsack function
	print_inventory(cap, inv);
	knapsack(cap, inv);
	return 0;
}

