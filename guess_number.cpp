#include <iostream>
#include <cstdlib>

using namespace std;

unsigned short number_tries = 3;
const unsigned short min_bound = 0;
unsigned short max_bound = 100;
int rand_number;
unsigned short player_guess;
bool game_running = true;

void run_guess(){
    cout << "You have " << number_tries << " tries remaining. Please type your guess:\n";
    cin >> player_guess;
}

void playagain_check(){
    char agree;
    cout << "Would you like to play again? y/n\n";
    cin >> agree;
    if (agree == 'n' || agree == 'N'){
        game_running = false;
    }
    else if (agree == 'y' || agree == 'Y'){
    }
    else{
        cout << "Invalid entry. Please restart game if you want to try again.";
        game_running = false;
    }
}

int main(){
    string player_name; 

    cout << "Welcome to the number guessing game!\n Please state your name:\n";
    cin >> player_name;
    cout << "Hello " + player_name + ".\n Thank you for playing the game!\n";

    while (game_running == true)
    {
        number_tries = 3;
        cout << "Please type the number you would like to use as the upper bound in this game:\n";
        cin >> max_bound;
        cout << "Thank you " + player_name + "! The random number you will be guessing lies between " << min_bound << " and " << max_bound << ".\n";
    
        rand_number = (rand() % (max_bound - min_bound + 1)) + min_bound;

        while (number_tries > 0){   
            run_guess();
            if (player_guess == rand_number){
                cout << "You guessed the number! Congratulations!\n";
                playagain_check();
                break;
            }
            else if (player_guess < rand_number+10 && player_guess > rand_number-10){
                cout << "Warm! Almost guessed it! Try again!\n";
            }
            else if (player_guess < rand_number-10 || player_guess > rand_number+10){
                cout << "Cold. Your guess was not correct. Try again!\n";
            }
            
            number_tries--;
        }

        if (number_tries == 0){
            cout << "You are out of guesses!\n";
            playagain_check();
        }
    }
    //implement type check
    return 0;
    
}