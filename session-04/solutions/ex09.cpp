#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int drawCard();
void dealerTurn(int *dealerScore);

int main() {
    srand(time(nullptr));

    int playerScore = 0;
    int dealerScore = 0;

    cout << "=== MINI BLACKJACK ===" << endl;

    int card1 = drawCard();
    int card2 = drawCard();

    playerScore = card1 + card2;

    cout << "You drew cards: " << card1 << " and " << card2
         << ". Initial score: " << playerScore << endl << endl;

    int choice = 0;

    while (choice != 2 && playerScore <= 21) {
        cout << "Your score: " << playerScore << endl;
        cout << "1) Hit" << endl;
        cout << "2) Stand" << endl;
        cout << "Enter choice (1-2): ";
        cin >> choice;

        if (choice == 1) {
            int card = drawCard();
            playerScore += card;

            cout << "\n-> You drew a " << card
                 << "! New score: " << playerScore << endl << endl;

            if (playerScore > 21) {
                cout << "*** BUST! Your score exceeded 21. "
                     << "Dealer wins! ***" << endl;
            }
        } else if (choice != 2) {
            cout << "Invalid choice! Please enter 1 or 2."
                 << endl << endl;
        }
    }

    if (playerScore <= 21) {
        cout << "\n--- Dealer's Turn ---" << endl;

        dealerTurn(&dealerScore);

        cout << endl;

        if (dealerScore > 21) {
            cout << "*** VICTORY! Dealer busted with "
                 << dealerScore << ". You win! ***" << endl;
        } else if (playerScore > dealerScore) {
            cout << "*** VICTORY! You scored " << playerScore
                 << " against Dealer's " << dealerScore
                 << ". You win! ***" << endl;
        } else if (dealerScore > playerScore) {
            cout << "*** DEALER WINS! Dealer scored " << dealerScore
                 << " against your " << playerScore << ". ***" << endl;
        } else {
            cout << "*** TIE GAME! Both scored "
                 << playerScore << ". ***" << endl;
        }
    }

    return 0;
}

int drawCard() {
    return rand() % 11 + 1;
}

void dealerTurn(int *dealerScore) {
    while (*dealerScore < 17) {
        int card = drawCard();
        *dealerScore += card;

        cout << "-> Dealer draws " << card
             << ". Dealer score: " << *dealerScore << endl;
    }
}