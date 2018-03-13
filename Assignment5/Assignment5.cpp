//shuaib munshi 100835300
//reads the dictionary.txt file into a vector of strings
//grabs a random word from the vector
//turns that word into a vector of chars and also makes a vector of underscores of the same length
//gets user guess and checks if it is in the random word vector, if it is it removes that letter from the alphabet vector and replaces
//the letter in the vector of underscores


#include "stdafx.h"
#include "string"
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

enum class States {MENU, GAME, SCORE, QUIT};

void buildVector(vector<string>& words) {
	ifstream myFile;
	myFile.open("dictionary.txt");
	if (myFile.fail()) {
		cout << "Failed!" << endl;
	}
	else if (myFile.is_open()) {
		while (!myFile.eof()) {
			string temp;
			getline(myFile, temp);
			words.push_back(temp);
			//cout << temp << endl;
		}
		myFile.close();
	}
}

string getRandomWord(vector<string>& words) {
	srand(time(0));
	int num = rand() % 1000;
	return words[num];
}

int getUserScore(string userName) {
	int lineNumber;
	string line;
	ifstream highScoreFile;
	highScoreFile.open("HighScores.txt");
	if (highScoreFile.fail()) {
		cout << "Could Not Open High Scores File!" << endl;
	}
	else if (highScoreFile.is_open()) {
		while (!highScoreFile.eof()) {
			getline(highScoreFile, line);
			if (line.find("userName") != string::npos) {
				return 0;
			}
		}
	}
}

void drawTop(string userName) {
	cout << "|---------------------------------|" << endl;
	//cout << "|";
	bool front = true;
	for (int i = userName.length(); i < 33; i++){
		if (front){
			userName = " " + userName;
		}
		else{
			userName = userName + " ";
		}
		front = !front;
	}
	cout << userName.c_str() << endl;
	cout << "|---------------------------------|" << endl;
}

void drawNoose(int attempts) {
	if (attempts == 0) {
		cout << "_________" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 1) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 2) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 3) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 4) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 5) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 6) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /|\\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 7) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /|\\" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 8) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /|\\" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "      /" << endl;
		cout << "|" << endl;
	}
	else if (attempts == 9) {
		cout << "_________" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "\t0" << endl;
		cout << "|" << "      /|\\" << endl;
		cout << "|" << "\t|" << endl;
		cout << "|" << "      / \\" << endl;
		cout << "|" << endl;
	}
}

void PrintLetters(string input, char from, char to) // https://pastebin.com/UvEgGazt
{
	string s;
	for (char i = from; i <= to; i++)
	{
		if (input.find(i) == string::npos)
		{
			s += i;
			s += " ";
		}
		else
			s += "  ";
	}
	cout << s << endl;
}

void drawAlphabet(vector<char>& alphabet, int from, int to) {
	for (int i = from; i <= to; i++) {
		cout << alphabet[i] << " ";
	}
	cout << endl;
}

void stringToVector(vector<char>& charVector, int size, string string); //Overload for the event that the function is called without a string
void stringToVector(vector<char>& charVector, int size, string string = "UNDERSCORE") {
	for (int j = 0; j < size; j++) {
		if (string == "UNDERSCORE") {
			charVector.push_back('_'); //fills with underscores if string is not passed
		}
		else {
			charVector.push_back(string[j]); //fills with the characters of the string if the string is passed
		}
	}
}

void outputVector(vector<char>& vectorOutput) {
	for (auto i : vectorOutput) //syntax suger for vector size iteration for loop
		cout << i << ' ';
	cout << endl;
	cout << endl;
}

void checkUserCharacter(char userChar, vector<char>& charVector, vector<char>& underscoreVector, vector<char>& alphabetVector, int& attempts) {
	//vector<char>::iterator it;
	if (find(charVector.begin(), charVector.end(), userChar) != charVector.end()) { //Checks if the letter exists
		ptrdiff_t pos = (find(charVector.begin(), charVector.end(), userChar) - charVector.begin()); //If it does exist, finds the position
		//cout << "The vector position is: " << pos << endl;
		underscoreVector[pos] = charVector[pos];
		charVector[pos] = ' ';
		char userCharUpper = toupper(userChar); //makes char upper because the alphabet vector is all uppercase
		if (find(alphabetVector.begin(), alphabetVector.end(), userCharUpper) != alphabetVector.end()) {
			ptrdiff_t alphabetPos = (find(alphabetVector.begin(), alphabetVector.end(), userCharUpper) - alphabetVector.begin()); //Finds pos of the letter in the alphabet and makes it blank
			alphabetVector[alphabetPos] = ' ';
		}
	}
	else {
		attempts += 1; //increments the attempts counter only when a wrong character is chosen
	}
}

bool checkVictory(vector<char>& underscoreVector) { //checks to see if there are still underscores in the vector
	if (find(underscoreVector.begin(), underscoreVector.end(), '_') != underscoreVector.end()) {
		return false; //user did not win
	}
	else {
		return true; //user has won!
	}
}
int main()
{
	vector<string> words; //list of words from dictionary
	vector<char> alphabet; //List of letters in the alphabet
	vector<char> randomWordVector; //Vector containing chars of the word to be guessed
	vector<char> randomWordBlanksVector; //Vector containing underscores for the number of characters in the word to be guessed
	string randomWord;
	int randomWordSize;
	States state = States::MENU;
	buildVector(words);
	int userInput;
	int attempts = 0;
	bool win = false;
	string userName;
	int userScore = 0;

	while (true) {
		if (state == States::MENU) {
			cout << "Please choose one of the following options:" << endl;
			cout << "1) Play Hangman" << endl;
			cout << "2) View Score" << endl;
			cout << "3) Exit" << endl;
			cin >> userInput;
			state = (States)userInput;
		}
		else if (state == States::GAME) {
			system("CLS");
			randomWordVector.clear(); //Clears in case the user plays again
			randomWordBlanksVector.clear();
			randomWord = getRandomWord(words);
			randomWordSize = randomWord.length();
			//alphabetVetor(alphabet); //Makes a vector with all of the letters in the alphabet
			alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
			cout << "Please enter your username: " << endl;
			cin >> userName;

			for (attempts = 0; attempts < 10;) {
				char userLetter;
				system("CLS");
				drawTop("Hangman");
				drawTop(userName);
				drawNoose(attempts);
				//PrintLetters(randomWord, 'A', 'M');
				//PrintLetters(randomWord, 'N', 'Z');
				drawAlphabet(alphabet, 0, 12); //Draws alphabet
				drawAlphabet(alphabet, 13, 25); //Draws 2nd half of the alphabet
				if (randomWordVector.empty()) {
					stringToVector(randomWordVector, randomWordSize, randomWord); //Makes a vector with the chars of the random word
					stringToVector(randomWordBlanksVector, randomWordSize); //Makes a vector with the underscores of the random word
				}
				outputVector(randomWordVector);
				outputVector(randomWordBlanksVector);
				cout << "Enter a letter:";
				cin >> userLetter;
				checkUserCharacter(userLetter, randomWordVector, randomWordBlanksVector, alphabet, attempts);
				if (checkVictory(randomWordBlanksVector) == true) {
					system("CLS");
					userScore++;
					cout << "You won!" << endl;
					cout << "Your highscore is: " << userScore << endl;
					//cout << "1) Play Again" << endl;
					//cout << "2) Return to the main menu" << endl;
					system("PAUSE");
					//int userWinChoice;
					//cin >> userWinChoice;
					//if (userWinChoice == 1) {
					//	state = States::GAME;
					//	break;
					//	//gameState state = gameState::MENU;
					//}
					//else {
					//	state = States::MENU;
					//	break;
					state = States::MENU;
					break;
					}
				}
			state = States::MENU;
			}
			//system("CLS");
			//cout << "You Lose :(" << endl;
			//cout << "Your highscore is: " << userScore << endl;
			//cout << "1) Play Again" << endl;
			//cout << "2) Return to the main menu" << endl;
			//int userWinChoice;
			//cin >> userWinChoice;
			////if (userWinChoice == 1) {
			////	state = States::MENU;
			////	break;

			////}
			////else {
			////	state = States::MENU;
			////	break;
			////}
			////cout << words[1] << endl;
			//cout << randomWord << endl;

		else if (state == States::SCORE) {
			cout << "Your score is: " << userScore << endl;
			ofstream file("HighScores.txt", fstream::trunc);
			file << userName << " : " << userScore;
			file.close();
			system("PAUSE");
			state = States::MENU;
		}
		else if (state == States::QUIT) {
			break;
		}
	}

    return 0;
}

