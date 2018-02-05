/*Programmer: Sonny Icks
CIS2013Week03_Homework01
Last Update: 2/4/2018*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

	int main() {
		srand(time(0));
		int player_count = (rand() % 10) + 1;
		int dealer_count = (rand() % 10) + 1;
		int dealer_first_card = (rand() % 10) + 1;
		int player_first_card = (rand() % 10) + 1;
		bool player_stay = false;
		bool player_bust = false;
		bool dealer_bust = false;
		bool play_again = true;
		char yes_or_no = 'n';
		char hit_stay = 'h';
		
		while (play_again) {
			//Inital deal out; two cards for player and one for dealer.
			cout << "You are dealt a " << player_first_card << " and a " << player_count << endl;
			cout << "Dealer is dealt a " << dealer_first_card << endl;
			player_count = player_count + player_first_card;
			cout << "You currently have " << player_count << endl;
			//deal another card to player when they hit, stop when they stay, and game ends immediately when they bust.
			while ((player_stay == false) && (player_bust == false)) {
				cout << "Do you want to hit or stay? (h/s): ";
				cin >> hit_stay;
				if (hit_stay == 'h') {
					cout << "You're dealt another card" << endl;
					player_count = player_count + (rand() % 10) + 1;
					if (player_count == 21) { cout << "21, YOU WIN!!!" << endl;
					//player_bust changed to true in this case so that the game will end.  Message above tells player they have won.
					player_bust = true;
					}
					else if (player_count > 21) {
						cout << "You have " << player_count << ", you have busted." << endl;
						player_bust = true;
					}
					else { cout << player_count << " "; }
				}
				else {
					player_stay = true;
					cout << "You stay with " << player_count << "," << endl << "Dealer's turn.";
				}
			//Dealer gets turn if player has not auto won with 21 or busted.
			}
			if ((player_stay == true) && (player_bust == false)) {
				cout << endl << "Dealer is dealt a " << dealer_count << endl;
				dealer_count = dealer_count + dealer_first_card;
				cout << "Dealer currently has " << dealer_count << endl;
				while (dealer_count < 17) {
					cout << "Dealer gets another card." << endl;
					dealer_count = dealer_count + (rand() % 10) + 1;
					cout << "Dealer has " << dealer_count << endl;
					if (dealer_count > 21) {
						cout << "Dealer busts...you win!" << endl;
						dealer_bust = true;
					}
					else if (dealer_count >= 17) { cout << "Dealer stays with " << dealer_count << endl; }
				}

			}
			//totals compared if both player and dealer stayed.  Highest score wins; player takes ties.
			if ((dealer_bust == false) && (player_bust == false)) {
				cout << "You have " << player_count << endl;
				cout << "The Dealer has " << dealer_count << endl;
				if (player_count >= dealer_count) { cout << "You win!" << endl; }
				else { cout << "Dealer wins..." << endl; }
			}
			cout << "play again? (y/n): ";
			cin >> yes_or_no;
			if ((yes_or_no=='n') || (yes_or_no=='N')){
				play_again = false;
			}
			else {
				//values reset for replay.
				player_count = (rand() % 10) + 1;
				dealer_count = (rand() % 10) + 1;
				dealer_first_card = (rand() % 10) + 1;
				player_first_card = (rand() % 10) + 1;
				player_stay = false;
				player_bust = false;
				dealer_bust = false;
			}
		}
}
