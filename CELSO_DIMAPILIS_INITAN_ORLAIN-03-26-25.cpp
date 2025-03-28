#include <iostream>
#include <string>
using namespace std;

int countWordsInSentence(string sentence) {
    int wordCount = 0;
    bool inWord = false;
    // Count the words in the sentence
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {                   
            if (!inWord) {  
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return wordCount;
}

string convertVowelsToUppercase(string sentence) {
    // Convert each vowel found to uppercase
    for (char &ch : sentence) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            ch = toupper(ch);
        }
    }
    return sentence;
}

string reverseSentence(string sentence) {
    // Reverse the sentence
    string reversedSentence;
    for (int i = sentence.length() - 1; i >= 0; i--) { // Concatenate characters starting from the last character of sentence to reversedSentence
        reversedSentence += sentence[i]; 
    }
    return reversedSentence;
}

void stringManip() {
    string sentence, reversedSentence;
    int sentenceCount = 0;
    cin.ignore();

    // Prompt user to enter two sentences
    do {
        cout << "Enter at least two sentences: ";
        getline(cin, sentence);

        for (char ch : sentence) {  
            if (ch == '.' || ch == '?' || ch == '!')    // Count the number of sentences (should be at least 2)
                sentenceCount++;
        }

        if (sentenceCount < 2)
            cout << "Invalid! Please enter at least 2 sentences." << endl;
    } while (sentenceCount < 2);

    // Display all string manipulation outputs
    cout << "\nSTRING MANIPULATION OUTPUT" << endl;
    cout << "\nNumber of words in the sentence: " << countWordsInSentence << endl;
    cout << "\nSentence with uppercase vowels: " << convertVowelsToUppercase(sentence) << endl;
    cout << "\nReversed sentence: " << reverseSentence(sentence) << endl;
}

void findLargest(int arr[], int size) {
    // Find the largest number in the array
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "Largest element: " << largest << endl;
}

void reverseArray(int arr[], int size) {
    // Reverse the array
    cout << "\nReversed array: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void sortArray(int arr[], int size) {
    // Simple sorting method without using a sorting algorithm (brute force approach)
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void arrayManip() {
    int size;
    // Get array size
    while (true) {
        cout << "\nHow many elements: ";
        cin >> size;
        if (cin.fail() || size < 1) { // Validate if input is a number not less than 1
            cout << "Invalid input!";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }
    int arr[size];

    // Prompt user to enter the array elements
    for (int i = 0; i < size; i++) {
        while (true){
            cout << "Enter an element of an array: ";
            cin >> arr[i];
            if (cin.fail()) { // Validate if input is a number
                cout << "Invalid input!";
                cin.clear();
                cin.ignore(1000, ' ');
                continue;
            }
            break;
        }
    }

    // Display original array
    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    // Display all manipulation outputs
    reverseArray(arr, size);
    findLargest(arr, size);
    sortArray(arr, size);
}

int main() {
    int choice;
    do {
        // Prompt user to choose from the options
        cout << "OPTION" << endl;
        cout << "1 - String Manipulation" << endl;
        cout << "2 - Array Manipulation" << endl;
        cout << "3 - Exit";
        
        while (true) {
            cout << "\nEnter Option: ";
            cin >> choice;
            if (cin.fail()) { // Validate if input is a number
                cout << "Invalid input!";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            } else if (choice != 1 && choice != 2 && choice != 3) { // Validate if input is one of the choices
                cout << "Invalid option! Choose from 1-3.";
                continue;
            }
            break;
        }

        // Do manipulations based on user choice
        switch (choice) {
        case 1:
            stringManip();
            cout << endl;
            break;
        case 2:
            arrayManip();
            cout << endl;
            break;
        case 3:
            cout << "Thank you!" << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
