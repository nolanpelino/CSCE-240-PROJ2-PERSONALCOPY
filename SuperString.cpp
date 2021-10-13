// Copyright 2021 Nolan Pelino
#include "./SuperString.h"
#include <string>


void SuperString::print() {
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
        }
        std::cout << "\n";
    } else {
        std::cout << "<EMPTY>\n";
    }
}

char SuperString::get(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return '\0';
}

int SuperString::length() {
    return size;
}

SuperString::SuperString() {
    this->size = 0;
    data = new char[size];
}

SuperString::SuperString(std::string str) {
    this->size = str.length();
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = str.at(i);
    }
}

SuperString::SuperString(int size, char val) {
    this->size = size;
    data = new char[this->size];
    for (int i = 0; i < this->size; i++) {
        data[i] = val;
    }
}

SuperString::SuperString(const SuperString& copy) {
    this->size = copy.size;
    data = new char[this->size];
    for (int i = 0; i < this->size; i++) {
        data[i] = copy.data[i];
    }
}
int SuperString::find(char c, int start) {
    int i = start;
    while (i < size) {
        if (data[i] == c)
            return i;
        i++;
    }
    return -1;
}

int SuperString::find(std::string str, int start) {  // Finds a string starting from data[start]
    int searchLength = str.length();
    int i = start;
    bool foundBad = false;

    while (i < size) {
        int j(1);
        if (data[i] == str.at(0)) {
            while (j < searchLength && !foundBad) {
                if (data[i+j] != str.at(j))
                    foundBad = true;
                else
                    j++;
            }
            if (!foundBad)
                return i;
        }
        foundBad = false;
        i++;
    }
    return -1;
}

// captures elements from data[start] to data[finish] and places them in a new superstring
SuperString SuperString::substr(int start, int numChar) {
    std::string replacedString;
    if ((start + numChar) >= this->size) {
        SuperString * madeSuper = new SuperString();
        return * madeSuper;
    } else {
        for (int i = start; i < numChar; i++) {
            replacedString += this->data[i];
        }
        SuperString * madeSuper = new SuperString(replacedString);
        return * madeSuper;
    }
}

SuperString SuperString::reverse() {
    int j(0);
    int i = this->length() - 1;
    SuperString revSuper;
    revSuper.size = this->size;
    revSuper.data = new char[size];
    while (i >=0) {
        revSuper.data[j] = this->get(i);
        j++;
        i--;
    }

    return revSuper;
}

// deletes elements from data[start] to data[finish] and places in string "sub"
SuperString SuperString::replace(int start, int numChar, std::string sub) {
    SuperString badSup;
    badSup.size = 0;
    badSup.data = new char[0];
     if (start > numChar || numChar >= this->length())
        return badSup;
    if (sub.length() == 0)
        return badSup;

    int j(0);
    SuperString repSup;
    if (sub.length() < (numChar - start))
        repSup.size = this->size;
    else
    repSup.size = this->size + (sub.length() - (numChar - start));
    repSup.data = new char[repSup.size];

    for (int i = 0; i < repSup.size; i++) {  // load repSup array
        repSup.data[i] = this->data[i];
    }

    for (int i = start; i < numChar; i++) {  // move all elements
        repSup.data[i] = ' ';
    }
    for (int i = start; i < start + sub.length(); i ++) {  // switch
        repSup.data[i] = sub.at(j);
        j++;
    }
    for (int i = 0; i < repSup.size; i++) {  // load repSup array
        if (repSup.data[i] == ' ')
            repSup.data[i] = i + 1;
    }
    return repSup;
}

void SuperString::push_back(char c) {  // places char c at the end of the calling object's data
    size++;
    char newData[size];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    newData[size - 1] = c;
    for (int i = 0; i < size; i++)
        data[i] = newData[i];
    return;
}

void SuperString::append(std::string str) {
    int j(0);
    size += str.length();
    char newData[this->length()];
    for (int i = 0; i < size; i++)
        newData[i] = data[i];
    for (int i = (size - str.length()); i < size; i++) {
        newData[i] = str.at(j);
        j++;
    }
    for (int i = 0; i < size; i++)
        data[i] = newData[i];
    return;
}

void SuperString::append(const SuperString& obj) {  // appends data of obj to the end of the calling objects data
    int j(0);
    char newData[this->length()];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    for (int i = size; i < this->size + obj.size; i++) {
        newData[i] = obj.data[j];
        j++;
    }
    this->size = this->size + obj.size;
    for (int i = 0; i < this->size; i++) {
        data[i] = newData[i];
    }
    return;
}

void SuperString::replace(char find, char rep) {
    for (int i = 0; i < size; i ++) {
        if (data[i] == find)
            data[i] = rep;
    }
    return;
}

bool SuperString::isUpper() {  // true if contains upper case
    for (int i = 0; i < size; i ++) {
        if (data[i] >= 65 && data[i] <= 90)
            return true;
    }
    return false;
}

bool SuperString::isLower() {  // true if contains lower case
    for (int i = 0; i < size; i ++) {
        if (data[i] >= 97 && data[i] <= 122)
            return true;
    }
    return false;
}

bool SuperString::isTitleCase() {  // true if each word starts with an uppercase
    for (int i = 0; i < size; i++) {
        if (i == 0 || data[i - 1] == ' ') {
            if (data[i] < 65 || data[i] > 90)
                return false;
        }
    }
    return true;
}

SuperString::~SuperString() {
    delete [] data;
}
