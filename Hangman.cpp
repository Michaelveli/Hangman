#include "pch.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

bool found = false;
char guess;
string word; // the word being guessed
char guessed[4]; // This string gets all the correct letters you have already typed
int validletter = false;
int aux = 0;
bool tracker = false;
string word_upper;

void test() {
	vector<bool> tracker;
	vector<char> guess;		// this could also just be a single string
	for (int i = 0; i < guess.size(); i++) {
		tracker.push_back(false);
	}
}

void check_correctness(char letter_guess, vector<char> guess, vector<bool> tracker) {
	for (int i = 0; i < guess.size(); i++) {
		if (letter_guess == guess[i]) {
			tracker[i] = true;
			// word_to_guess[0] = J
			// word_to_guess[1] = E
			// word_to_guess[2] = E
			// word_to_guess[3] = P

			cout << guess[i] << endl;
		}
	}
}

void display() {
	for (int i = 0; i < guess.size(); i++) {
		if (tracker[i] == true) {
			cout << word[i] << endl;//show letter;
		}
		else {
			cout << "_" << endl; // show "_"
		}
	}
}

int main() {

	int tries = 4; // number of wrong attempts
	int right = 0;   // counter for correct guesses
	int length = word.length();
	int size = 1;
	cout << "Input word to start game: ";
	getline(cin, word);

	//for (char c : word) {                       
	//	word_upper += toupper(c);
	//	}

	for (char c : word) {                        //checks space
		if (isspace(c)) {
			cout << "Word cannot contain a space. Enter another word." << endl;
			continue;

		}
	}
	if (word.empty()) {                                 // checks empty
		cout << "The word cannot be blank! " << endl;
	}
	
	cout << "The word length is " << length << endl;


	cout << "Try to guess the word, you have FOUR guesses!" << endl;

	while (tries <= 4) {
		validletter = false;

		if (aux == 0)
		{
			cout << "Enter a 1st letter: ";
			cin >> guess;
			guessed[0] = guess;
			cout << "You guessed: " << guess << endl;

		}
		else {

			while (validletter == false) // You can only get out of this loop by typing a valid letter. 
			{
				cout << "\n\nEnter a letter: ";
				cin >> guess;
				cout << "You guessed: " << guess << endl;
				validletter = true;
			}
		}

		aux++;

		for (int i = 0; i < length; i++) {
			found = false;

			if (word[i] == guess) {        // Letter is in word

				cout << "This letter is in the word!" << endl;
				cout << word[i] << "\t";
				i = length;
				found = true;
				right++;
				guessed[size] = guess;
				size++;
				

			}

			else if (i == length - 1 && found == false) {

				cout << "This letter is not in the word. " << endl;
				tries--;
				cout << "__\t";
			}
		}

		if (right == length) {     // winning condition

			cout << "You win!" << endl;
			cout << "The word was " << word << endl;
			break;
		}

		if (tries == 0 && right != length) {          // losing condition

			cout << "You lost!" << endl;
			cout << "The word was " << word << endl;
			break;
		}
	} // while loop close


	return 0;
}

