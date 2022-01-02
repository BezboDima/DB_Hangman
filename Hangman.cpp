#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int updatedWord(string word, string& hidden, string letter, int& wrong);
string createHiddenWord(string word);

int main() {

	srand(time(0));

	//create a list of possible words
	string list[] = { "meter","program", "number","difficult" };
	
	//answer is used only for the question if player wants to continue
	char answer = 'y';

	
	while (answer != 'n') {
		//for the new game pick a word, word to display, players guess, number of wrong answers
		string word = list[rand() % 5];
		string wordToDisplay = createHiddenWord(word);
		string letter;
		int wrong = 0;

		// if word to display contains * char do not quit
		while (wordToDisplay.find("*") != string::npos){

			// ask user for a letter to check (must be a string, fix in the future)
			cout << "Enter a letter in word " << wordToDisplay << endl;
			cin >> letter;

			// updateWord gives a status of letter and the word (already in it, found, not found) (0,1,-1)
			//display the info according to the status
			
			switch (updatedWord(word,wordToDisplay,letter,wrong))
			
			// NOTE without 'break' statements program works incorrectly (reasone not found)
			{
			case -1:
				cout << letter << " is not in word " << wordToDisplay << endl;
				break;
			
			case 0:
				cout << letter << " is already in word " << wordToDisplay << endl;
				break;
			
			}
			
		}
		//asks if user wants to continue
		cout << "The word is " << word << ". You missed " << wrong << " times" << endl;
		cout << "Do you want to try again? n = no. anything = yes" << endl;
		cin >> answer;
	}

	return 0;
}

//gives the status of letter in the word and keep track of wrong tries
//shadow word and wrong are given by reference to make it easier to keep track
int updatedWord(string word, string& hidden, string letter, int& wrong) {
	
	// create control and result variables
	int control = 0;
	int result;
	
	//if shadow word and actuall one contain a letter letter was already guessed
	if (hidden.find(letter) != string::npos && word.find(letter) != string::npos) {
		result = 0;
	}

	else {

		// try to find the letter until reach the end of the word
		while (word.find(letter, control) != string::npos) {

			//if found status is 1 => found and continue from next charachter to seek
			hidden.replace(word.find(letter, control), 1, letter);
			control = word.find(letter, control) + 1;
			result = 1;
		}

		// if not found from the 1 attempt status => not found number of wrong +1
		if (control == 0) {
			wrong += 1;
			result = -1;
		}
	}

	// give back the status
	return result;
}

// creates a SHADOW of the word(word => ****)
string createHiddenWord(string word) {
	return word.assign(word.size(), '*');
}