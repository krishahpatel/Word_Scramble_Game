#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

vector<string> word_list = {"python", "developer", "programming", "algorithm", "function", "computer", "software", "debugging"};

string scramble_word(string word) {
    random_shuffle(word.begin(), word.end());
    return word;
}

string play_game(string original_word, int attempts) {
    string guess;
    cout << "Guess the word (or type 'exit' to quit): ";
    cin >> guess;

    if (guess == "exit") cout << "Thanks for playing! Goodbye!" << endl;
    if(guess == original_word) cout << "Correct   You guessed it!" << "\n";
    else cout << "Wrong guess. Attempts left: " << attempts << "\n";

    return guess;
}


int main() {
    srand(time(0));
    
    while (true) {
        string original_word = word_list[rand() % word_list.size()];
        string scrambled = scramble_word(original_word);

        cout << "\n Welcome to the Word Scramble Game!" << endl;
        cout << "Scrambled word: " << scrambled << endl;

        int attempts = 3;
        
        while (attempts--) {
            string guess = play_game(original_word, attempts);
            if(guess == original_word || guess == "exit") break;
        }

        cout << "The correct word was: " << original_word << "\n" << endl;

        string play_again;
        cout<<"Do you want to play again? (yes/no): ";
        cin >> play_again;
        if(play_again=="no"){
            cout<<"Thanks for playing! Goodbye!"<<endl;
            break;
        }
    }
    return 0;
}