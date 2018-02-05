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
		int computer_count = (rand() % 10) + 1;
		int computer_first_card = (rand() % 10) + 1;
		int player_first_card = (rand() % 10) + 1;
		char hit_stay = 'h';
		bool player_stay = false;
		bool player_bust = false;
		
		cout << "You are dealt a " << player_first_card << " and a " << player_count << endl;
		player_count = player_count + player_first_card;
		
		while ((player_stay == false) && (player_bust==false)){
			cout << "Do you want to hit or stay? (h/s): ";
			cin >> hit_stay;
			if (hit_stay == 'h') {
				player_count = player_count + (rand() % 10) + 1;
				if (player_count == 21) { cout << "21, YOU WIN!!!"; }
				else if (player_count > 21) { cout << player_count << ", you busted.";
				player_bust = true;
				}
				else { cout << player_count << " "; }
			}
			else { player_stay = true;
			cout << "You stay with " << player_count;
			cin >> hit_stay;
			}
		}
}
