// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string word; // the word to guess



void getword() {
	cout << "Hangman" << endl;
	cout << "Input word to start game: ";
	getline(cin, word);
	//toupper(word); // fix this

	for (char c : word) {
		if (isspace(c)) {
			cout << "Word cannot contain a space. Enter another word." << endl;
			continue;

		}
	}
	if (word.empty()) {
		cout << "The word cannot be blank! " << endl;
	}
}

void hangman() {
	int attempts = 4;
	char letter_from_word; // the letter the user guesses
	string word_incomplete; // the word being guessed
	
		for (int i = 0; i < word.size(); i++) {
			if (word_incomplete == word) {
				cout << "Congratulations! You have correctly guessed the word! " << endl;
				break;
			}
			
			if (attempts < 1) {
				cout << "You have ran out of attempts. ";
				break;
			}

			cout << "You have " << attempts << " attempts left." << endl;
			cout << "|" << word_incomplete << "|" << endl;
			cout << "Enter a letter" << endl;
			cin >> letter_from_word;
			toupper(letter_from_word);
			cin.ignore();

			if (letter_from_word == word[i]) {
				cout << "Correct!" << endl;
				word_incomplete = word_incomplete + letter_from_word;
				cout << word_incomplete << endl;
				continue;
			}

			if (letter_from_word != word[i]) {
				cout << "Incorrect! ";
				attempts--;
				i--;
				continue;
			}

		}
	
}




int main()
{
	char choice;

	// for all letters in word
	// toupper(letter_from_word);
	// save letter_from_word back into string word
	getword();
	hangman();

	cout << "Game over. Play again? (y/n)" << endl;
	cin >> choice;
	cin.ignore();
	if (choice == 'y') {
		getword();
		hangman();
	}
	if (choice == 'n') {
		cout << "Goodbye! Thanks for playing. ";

	}
}


