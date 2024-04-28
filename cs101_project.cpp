///////////////////////////////////////////////////////////////
/// Sajjad Akbar Khan
/// Reg No: 2023634)
/// CS 101 Project 2023
//////////////////////////////////////////////////////////
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
const int maxsize = 1000;

// Function prototypes
char* mergeParagraphs(const char* P1, const char* P2);
int countVowels(const char* Para);
int findFirstOccurrence(const char* Word, const char* Para);
int* findAllOccurrences(const char* Word, const char* Para, int& count);
void displayWordHistogram(const char* Para);
void displaySortedHistogram(const char* Para);
char* reverseWordsInParagraph(const char* Para);

int main() {
    // Prompt the user to enter two paragraphs
    char Para1[maxsize];
    char Para2[maxsize];
    
    cout << "Enter Paragraph 1:\n";
    cin.getline(Para1, maxsize);
    
    cout << "Enter Paragraph 2:\n";
    cin.getline(Para2, maxsize);

    const char* selectedPara; // Declare outside switch statement

    while (true) {
        // Display menu
        cout << "\n       Menu:\n";
        cout<<"===================="<<endl;
        cout << "1. Merge Paragraphs\n";
        cout << "2. Count Vowels\n";
        cout << "3. Find First Occurrence of Word\n";
        cout << "4. Find All Occurrences of Word\n";
        cout << "5. Display Word Histogram\n";
        cout << "6. Display Sorted Histogram\n";
        cout << "7. Reverse Paragraph\n";
        cout << "8. Exit\n";
        cout<<"===================="<<endl;
        cout << "Enter your choice: "<<endl;
        cout<<"********************"<<endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        cout<<"********************"<<endl;

        switch (choice) {
            case 1:
                char* MergedPara;
                MergedPara = mergeParagraphs(Para1, Para2);
                cout << "Merged Paragraph:\n" << MergedPara << "\n";
                delete[] MergedPara; // Free memory
                cout<<"--------------------"<<endl;
                break;

            case 2:
                cout << "Enter paragraph number (1 or 2): ";
                int paraNum;
                cin >> paraNum;
                selectedPara = (paraNum == 1) ? Para1 : Para2;
                cout << "Number of vowels: " << countVowels(selectedPara) << "\n";
                cout<<"--------------------"<<endl;
                break;

            case 3:
            {
                cout << "Enter word to find: "; 
                char wordToFind[maxsize];
                cin.ignore(); // Clear the input buffer
                cin.getline(wordToFind, maxsize);
                int firstOccurrence = findFirstOccurrence(wordToFind, Para1);
                if (firstOccurrence != -1)
                    cout << "First occurrence at index: " << firstOccurrence << "\n";
                else
                {
                    cout << "Word not found.\n";
                    // Add a placeholder statement or use an empty statement with a semicolon
                }
                cout << "--------------------" << endl;
            }
            break;

            case 4:
                {
                    cout << "Enter word to find: ";
                    char wordToFind[maxsize];
                    cin.ignore(); // Clear the input buffer
                    cin.getline(wordToFind, maxsize);
                    int count;
                    int* occurrences = findAllOccurrences(wordToFind, Para1, count);
                    if (count > 0) {
                        cout << "Occurrences at indices: ";
                        for (int i = 0; i < count; ++i) {
                            cout << occurrences[i] << " ";
                        }
                        cout << "\n";
                        cout<<"--------------------"<<endl;
                        delete[] occurrences; // Free memory
                    } else {
                        cout << "Word not found.\n";
                    }
                    cout<<"--------------------"<<endl;
                }
                break;

            case 5:
                displayWordHistogram(Para1);
                cout<<"--------------------"<<endl;
                break;

            case 6:
                displaySortedHistogram(Para1);
                cout<<"--------------------"<<endl;
                break;

            case 7:
                {
                    char* reversedPara = reverseWordsInParagraph(Para1);
                    cout << "Reversed Paragraph:\n" << reversedPara << "\n";
                    delete[] reversedPara; // Free memory
                    cout<<"--------------------"<<endl;
                }
                break;

            case 8:
                cout << "Exiting program.\n";
                cout<<"--------------------"<<endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                cout<<"--------------------"<<endl;
        }
    }

    return 0;
}

// Function to merge two paragraphs
char* mergeParagraphs(const char* P1, const char* P2) {
    int size1 = strlen(P1);
    int size2 = strlen(P2);

    // Allocate memory for merged paragraph
    char* MergedPara = new char[size1 + size2 + 1]; // +1 for the null terminator

    // Copy paragraphs to merged paragraph
    strcpy(MergedPara, P1);
    strcat(MergedPara, P2);

    return MergedPara;
}

// Function to count vowels in a paragraph
int countVowels(const char* Para) {
    int count = 0;

    // Iterate through each character in the paragraph
    for (int i = 0; Para[i] != '\0'; ++i) {
        char ch = tolower(Para[i]); // Convert to lowercase for case-insensitive comparison

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

// Function to find the first occurrence of a word in a paragraph
int findFirstOccurrence(const char* Word, const char* Para) {
    int wordLen = strlen(Word);
    int paraLen = strlen(Para);

    // Iterate through the paragraph to find the first occurrence of the word
    for (int i = 0; i <= paraLen - wordLen; ++i) {
        bool match = true;

        // Compare each character of the word with the corresponding characters in the paragraph
        for (int j = 0; j < wordLen; ++j) {
            if (tolower(Word[j]) != tolower(Para[i + j])) {
                match = false;
                break;
            }
        }

        // If the word is found, return the index
        if (match) {
            return i;
        }
    }

    // If the word is not found, return -1
    return -1;
}

// Function to find all occurrences of a word in a paragraph
int* findAllOccurrences(const char* Word, const char* Para, int& count) {
    int wordLen = strlen(Word);
    int paraLen = strlen(Para);

    // Count the number of occurrences
    count = 0;
    for (int i = 0; i <= paraLen - wordLen; ++i) {
        bool match = true;

        // Compare each character of the word with the corresponding characters in the paragraph
        for (int j = 0; j < wordLen; ++j) {
            if (tolower(Word[j]) != tolower(Para[i + j])) {
                match = false;
                break;
            }
        }

        // If the word is found, increment the count
        if (match) {
            count++;
        }
    }

    // If no occurrences are found, return nullptr
    if (count == 0) {
        //return nullptr;
    }

    // Allocate memory for the array of occurrences
    int* occurrences = new int[count];

    // Populate the array with the indices of occurrences
    int currentIndex = 0;
    for (int i = 0; i <= paraLen - wordLen; ++i) {
        bool match = true;

        // Compare each character of the word with the corresponding characters in the paragraph
        for (int j = 0; j < wordLen; ++j) {
            if ( tolower (Word[j]) != tolower (Para[i + j])) {
                match = false;
                break;
            }
        }

        // If the word is found, store the index in the array
        if (match) {
            occurrences[currentIndex] = i;
            currentIndex++;
        }
    }

    return occurrences;
}

// Function to display the word histogram of a paragraph
void displayWordHistogram(const char* Para) {
    int occurrences[maxsize] = {0};

    // Count occurrences of each word in the paragraph
    int wordStart = 0;
    int wordEnd = 0;
    while (Para[wordEnd] != '\0') {
        // Skip non-alphabetic characters to find the start of a word
        while (!isalpha(Para[wordStart]) && Para[wordStart] != '\0') {
            wordStart++;
        }

        // Find the end of the word
        wordEnd = wordStart;
        while (isalpha(Para[wordEnd])) {
            wordEnd++;
        }

        // Extract the word
        int wordLength = wordEnd - wordStart;

        // Update occurrences
        occurrences[wordLength]++;

        // Move to the next word
        wordStart = wordEnd;
    }

    // Display the histogram
    for (int i = 0; i < maxsize; ++i) {
        if (occurrences[i] > 0) {
            cout << i << "-letter words: ";
            for (int j = 0; j < occurrences[i]; ++j) {
                cout << '*';
            }
            cout << endl;
        }
    }
}

// Function to display the sorted word histogram of a paragraph
void displaySortedHistogram(const char* Para) {
    int occurrences[maxsize] = {0};

    // Count occurrences of each word in the paragraph
    int wordStart = 0;
    int wordEnd = 0;
    while (Para[wordEnd] != '\0') {
        // Skip non-alphabetic characters to find the start of a word
        while (!isalpha(Para[wordStart]) && Para[wordStart] != '\0') {
            wordStart++;
        }

        // Find the end of the word
        wordEnd = wordStart;
        while (isalpha(Para[wordEnd])) {
            wordEnd++;
        }

        // Extract the word
        int wordLength = wordEnd - wordStart;

        // Update occurrences
        occurrences[wordLength]++;

        // Move to the next word
        wordStart = wordEnd;
    }

    // Bubble sort to sort the histogram in increasing order based on frequency
    for (int i = 1; i < maxsize; ++i) {
        for (int j = 0; j < maxsize - i; ++j) {
            if (occurrences[j] > occurrences[j + 1]) {
                // Swap occurrences
                int temp = occurrences[j];
                occurrences[j] = occurrences[j + 1];
                occurrences[j + 1] = temp;
            }
        }
    }

    // Display the sorted histogram
    for (int i = 0; i < maxsize; ++i) {
        if (occurrences[i] > 0) {
            cout << i << "-letter words: ";
            for (int j = 0; j < occurrences[i]; ++j) {
                cout << '*';
            }
            cout << endl;
        }
    }
}

// Function to reverse all words in a paragraph
char* reverseWordsInParagraph(const char* Para) {
    int len = strlen(Para);

    // Allocate memory for the reversed paragraph
    char* reversedPara = new char[len + 1]; // +1 for the null terminator

    // Initialize the reversed paragraph with spaces
    memset(reversedPara, ' ', len);
    reversedPara[len] = '\0';

    // Iterate through the paragraph to reverse each word
    int wordStart = 0;
    int wordEnd = 0;
    int reversedIndex = 0;

    while (Para[wordEnd] != '\0') {
        // Skip non-alphabetic characters to find the start of a word
        while (!isalpha(Para[wordStart]) && Para[wordStart] != '\0') {
            reversedPara[reversedIndex++] = Para[wordStart++];
        }

        // Find the end of the word
        wordEnd = wordStart;
        while (isalpha(Para[wordEnd])) {
            wordEnd++;
        }

        // Reverse the word and copy to the reversed paragraph
        int start = wordStart;
        int end = wordEnd - 1;
        while (start <= end) {
            reversedPara[reversedIndex++] = Para[end--];
        }

        // Move to the next word
        wordStart = wordEnd;
    }

    return reversedPara;
}

