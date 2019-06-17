
// arrays and vectors notes


// an array is a special variable having one name, but storing a list of data items
// a vector is similar to an array

// an analogy
// a variable is a truck that can only hold one item
// an array is a train that can hold multiple items

// each item in an array has a corrosponding index (position)
// the first item's index in an array is 0



// vectors
// an ordered list of a given data type
// each item in a vector is called an element

#include <iostream>
#include <vector> // vector library must be included in order to use vectors
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL)); // for later example

	int example_length = 10, init_value = 0;
	
	// declaration of a vector
	// without "using namespace std;" it is std::vectori
	// datatype goes inside of the <>
	// length of the vector goes inside of the ()
	
	// declaration of a vector with a length of 10 and initial value of 0
	vector<int> example(example_length, init_value);
	
	vector<int> b; // empty vector with 0 elements. b.at(0); will throw an erro

	// explicit initialization
	
	vector<char> alphabet = {'a' , 'b' , 'c'};

	// multidimensional vector
	
	vector<vector<int>> two_dimensions(10 , vector<int>(10 , 0));

	int i , j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {

			cout << two_dimensions.at(i).at(i);

		}

		cout << endl;
	}
	
	// output...
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000
	// 0000000000


	// explicit initialization of a multidimensional vector
	
	vector<vector<int>> vect = {{1, 2, 3},{4, 5},{6},{}};



	// vector methods

	// accessing individual elements of a vector
	
	example.at(0) = 25;
	cout << example.at(0) << endl; // 25

	example.at(1) = 30;
	cout << example.at(1) << endl; // 30

	example.at(0) = example.at(1);
	cout << example.at(0) << endl; // 30
	cout << example.at(1) << endl; // 30

	

	int var;

	example.at(2) = 100;
	var = example.at(2);

	cout << var << endl; // 100


	// getting the size of a vector
	
	cout << example.size() << endl; // 10

	for (int i = 0; i < example.size(); i++) {

		example.at(i) = i + 1;
		cout << example.at(i) << ' '; // 1 2 3 4 5 6 7 8 9 10

	}



	// finding max value in a vector example
	
	int max;

	vector<int> numbers(10);

	
	// initialze vector with random numbers
	
	for (int i = 0; i < numbers.size(); i++)
		numbers.at(i) = rand() % 100;

	max = numbers.at(0);

	// iterate through the vector to find the max number
	
	for (int i = 0; i < numbers.size(); i++)
		if (numbers.at(i) > max)
			max = numbers.at(i);

	cout << max << endl;



	// resizing a vector
	
	int size = 10;

	vector<int> a(size);
	
	size = 20;

	a.resize(size); // adds 10 new elements to the end

	size = 5;

	a.resize(size); // deletes 15 elements from the end
	
	
	// appending items to a vector
	
	vector<int> something(10 , 5);

	something.push_back(5);

	cout << something.size() << endl; // 11
	cout << something.at(10) << endl; // 5

	// deleting last item of a vector
	something.pop_back(); // deletes last item of the vector
	cout << something.size() << endl; // 10

	// getting last element from a vector
	something.push_back(100);
	cout << something.back() << endl; // 100
	

	// copying a vector
	
	vector<int> vect(10, 5);
	vector<int> vect_copy;

	vect_copy = vect; // resizes vect_copy and assigns each value corrosponding to vect

	// vector equality operation
	
	cout << (vect == vect_copy) << endl; // true

	vect_copy.push_back(34);

	cout << (vect == vect_copy) << endl; // false
	return 0;

}




// swapping two variables' values


#include <iostream>

using namespace std;




void swap(int& a, int& b);

int main() {


	int a = 5, b = 10;

	swap(a , b);

	cout << a << ' ' << b << endl; // 10 5

	return 0;

}


void swap(int& a, int& b) {

	int t; // temporary variable needed during swap

	t = a;
	a = b;
	b = a;

}



// arrays
// less safe than vectors


#include <iostream>


int main() {

	// declarations
	// it is best practice to declare a variable with the size of the array
	
	const int A_SIZE = 10;
	int a[A_SIZE];
	
	int b[] = {0,1,2,3,4,5};

	const int C_SIZE = 3
	int c[C_SIZE] = {0,1,2};
	
	// const arrays
	// arrays whos elements cannot be modified
	
	const int S_SIZE = 3;
	const int s[] = {1,2,3};

	// accessing index
	
	b[2] = 5;

	cout << b[2] << endl; // 5

	// multidimensional arrays
	
	const int I_SIZE = 5, J_SIZE = 10;
	int d[I_SIZE][J_SIZE];

	int e[][] = {{1,2},{3,4,5},{}};

	d[0][3] = 10;

	cout << d[0][3] << endl; // 10

	
	return 0;
}



// char arrays / c strings


#include <iostream>
#include <cstring>
#include <cctype>

int main() {

	// c strings have the null character '\0' at the end of the string
	
	char example[20]; // this can store strings of lengths 0 to 19. The longest string is 19. not 20 because the null character MUST be stored

	char first[9] = "Jonathan"; // the compiler actually stores this as "Jonathan\0"
	char last[] = "Benson"; // and this as "Benson\0"

	// in each cout, printing stops when reaching a null char '\0'
	
	cout << "My name is "; // compiler appends '\0' to "My name is "
	cout << first << ' ' << last << endl;

	// empty string versus null string
	
	char emptystr[5] = { '\0' }; // one null character and 4 other empty allocated char elements
	char nullstr[5]; // 5 allocated empty char elements


	// c string functions
	// strcpy(copystr , sourcestr)
	// strncpy(copystr , sourcestr , numchars)
	// strcat(origstr , otherstr)
	// strncat(astr , otherstr , numchars)
	// strchr(sourceStr, searchChar)
	// strlen(sourceStr)
	// strcmp(str1 , str2) -> will return 0 if they are equal
	

	// char functions
	// isalpha(c)
	// isdigit(c)
	// isalnum(c)
	// isspace(c)
	// islower(c)
	// isupper(c)
	// isblank(c)
	// isxdigit(c)
	// ispunct(c)
	// isprint(c)
	// iscntrl(c)
	// toupper(c)
	// tolower(c)



	return 0;
}






// functions with array parameters
// arrays passed to functions are passed by POINTER by default


#include <iostream>

using namespace std;


// when passing arrays to functions
// the array parameter need not a size, but rather empty brackets
// also it is BEST PRACTICE to include another parameter for the size of the array
int max(int numbers[], const int L);



int main() {

	const int L = 7;
	int nums[] = {3,6,1,8,9,3,6};
	
	cout << max(nums , L) << endl; // 9

	return 0;

}


int max(int numbers[], const int L) {

	int max = numbers[0];

	for (int i = 0; i < L; ++i) {

		if (numbers[i] > max) {

			max = numbers[i];

		}
	}

	return max;

}


