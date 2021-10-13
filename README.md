# CSCE-240-PROJ2-PERSONALCOPY

Project focuses on creating a string class and adding its own functions and data. Object definitions are contained in the SuperString.h and member functions and constructors are contained in SuperString.cpp. Testing is either done in main-gtest.cpp (using Google Test) or main.cpp. The full documentation for the member functions and constructors are listed below. 

## SuperString member variables: 
- `char *data`: a dynamic pointer array that holds each character of the string within that SuperString object
- `int size`: the size of the `data` array (how many characters it holds)

## SuperString Constructors: 
- `SuperString()`: The default constructor
  - sets `size` to 0 
  - allocates the `data` array to a new char array of size `size`
- `explicit SuperString(std::string)`: Alt. Constructor #1.
  - sets `size` to the length of the string passed in
  - allocates the `data` array to a new char array of size `size`
  - fills the contents of the `data` array with the contents of the string passed in
- `SuperString(int, char)`: Alt. Constructor #2
  - sets `size` to the value of the int passed in 
  - allocates the data array to a new char array of size `size`
  - fill alls contents of the `data` array with the character passed in
- `SuperString(const SuperString&)`: Copy Constructor
  - sets `size` to the size of the object passed in 
  - allocates the `data` array to a new char array of size `size`
  - fill all contents of the `data` array with the same contents as the passed object's data

## SuperString Destructor: 
- `~SuperString()`: Deallocates the data array

## SuperString Member Functions
- `void print()`: prints the contents of your array 
- `char get(int)`: Extracts an element from your `data` array.
- `int length()`: returns the `size`.
- `int find(char, int start = 0)`
  - returns the index of the *first* instance of the character passed in the `data` array starting at index `start` 
  - returns -1 if the character does not exist. 
  - Ex: obj.data = "Hello" then obj.find('l', 0) == 2 
- `int find(std::string, int start = 0)`
  - returns the index of the *first* instance of the string passed in the `data` array starting at index `start` 
  - returns -1 if the character dne.
  - Ex: obj.data = "that cat is a cool cat" then obj.find("cat", 0) == 5
- `SuperString substr(int start, int numChar)`
  - returns a `SuperString` object that contains the substring of the calling object's data starting at index `start` and spanning the number of characters held in `numChar`
  - Contents of the returned object should be size 0 if no substring is able to be extracted. This would happen if a user gave an index that was out of bounds. 
  - Ex. obj.data = "Hello" then obj.substr(0,2) == ret.data =="He"
- `SuperString reverse()`
  - Returns a `SuperString` object thats data array contains the calling calling object's data in reverse order.
  - Ex: obj.data = "Of Course" then obj.reverse() == ret.data == "esruoC fO"
- `SuperString replace(int index, int numChar, std::string sub)`
  - Does not modify the calling object.
  - Returns a `SuperString` object thats data array has the contents of the data after the replacement is performed. 
  - Returns a `SuperString` object with size = 0 if index is invalid.
  - Works by deleting all elements from index to numchar and then placing `string sub` at index. Also closes all gaps.
  - Ex: obj.data = "Hello" then obj.replace(0, 2, "Jal") == ret.data == "Jalllo"
- `void push_back(char)`
  - Adds a new character (the one passed in) to the `data` array of the calling object.
  - Ex: obj.data = "hello" then obj.push_back('w') -> obj.data == "hellow"
- `void append(std::string)`
  - Modifies the calling object.
  - Appends the content of the passed string to the end of the `data` array of the calling object
  - Ex: obj.data = "hello" then obj.append(" world") -> obj.data == "hello world"
- `void append(const SuperString&)`
  - Modifies the calling object.
  - Appends the content of the passed `SuperString` to the end of the `data` array of the calling object
  - Ex: obj.data = "hello" and obj2.data = " world" then obj.append(obj2) -> obj.data == "hello world"
- `void replace(char find, char rep)`
  - Modifies the calling object.
  - Replaces all instances of the character `find` in the calling object's `data` array with the `rep` character.
  - Ex: obj.data = "catcat" then obj.replace('c', 't') -> obj.data = "tattat" 
- `bool isUpper()`
  - Returns true if the `data` array contains all uppercase characters
  - Returns false if the `data` array contains anything other than uppercase characters
- `bool isLower()`
  - Returns true if the `data` array contains all lowercase characters
  - Returns false if the `data` array contains anything other than lowercase characters
- `bool isTitleCase()`
  - Returns true if the `data` array contains a sentence that is in proper "Title" case. 
  - Returns false if the `data` array contains contains a sentence that is not in proper "Title" case. 
  -Title case is simplified to be an uppercase at the start of every word.
  - For example: "This Is Our Modified Title Case"(True) and "This Does Not Count as Title Case"(False)
