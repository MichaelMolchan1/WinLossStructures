#include <iostream>
#include <string>
using namespace std;

// Define WinLoss structure with wins and losses members (int)
struct WinLoss {
    int wins;
    int losses;
};

// Define Team structure with the team name, containing a WinLoss structure variable for total wins/losses,
// a WinLoss structure variable for home wins/losses, and a WinLoss structure variable for away wins/losses.
struct Team {
    string name;
    WinLoss total;
    WinLoss home;
    WinLoss away;
};

// Declare an array of type Team
const int MAX_TEAMS = 100;
Team teams[MAX_TEAMS];
int numTeams = 0;

// Function prototypes
int menu();
WinLoss getWinLoss(string location);
void displayWinLoss(WinLoss winLoss);
Team getTeam();
void displayTeam(Team team);
void findTeam(Team teams[], int numTeams);

int main() {
    int choice;

    do {
        choice = menu();

        switch (choice) {
        case 1:
            // Enter a new team
            teams[numTeams] = getTeam();
            numTeams++;
            break;

        case 2:
            // Display all teams
            for (int i = 0; i < numTeams; i++) {
                displayTeam(teams[i]);
            }
            break;

        case 3:
            // Display a particular team
            findTeam(teams, numTeams);
            break;

        case 4:
            // Exit the program
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}

// Function that shows the menu, gets the user selection, validates the menu selection, and returns a valid menu selection
int menu() {
    int choice;

    cout << "Menu:" << endl;
    cout << "1. Enter a new team" << endl;
    cout << "2. Display all teams" << endl;
    cout << "3. Display a particular team" << endl;
    cout << "4. Exit" << endl;

    do {
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice < 1 || choice > 4);

    return choice;
}

// Function that gets wins and losses from the keyboard for the location indicated by the string parameter
// ("home" or "away") and returns a WinLoss structure containing the input.
WinLoss getWinLoss(string location) {
    WinLoss winLoss;

    cout << endl << "Enter " << location << " wins: ";
    cin >> winLoss.wins;

    cout << endl << "Enter " << location << " losses: ";
    cin >> winLoss.losses;

    return winLoss;
}

// Function that displays a string containing the win and loss members in the format of "wins-losses".
void displayWinLoss(WinLoss winLoss) {
    cout << winLoss.wins << " - " << winLoss.losses << " ";
}

// Function to input a team
Team getTeam() {
    Team newTeam;
    cout << "Enter team name: ";
    cin >> newTeam.name;
    newTeam.home = getWinLoss("home");
    newTeam.away = getWinLoss("away");
    newTeam.total.wins = newTeam.home.wins + newTeam.away.wins;
    newTeam.total.losses = newTeam.home.losses + newTeam.away.losses;
    return newTeam;
}

// Function to display team information
void displayTeam(Team team) {
    cout << "Team Name: " << team.name << endl;
    cout << "Total Wins/Losses: ";
    displayWinLoss(team.away);
    cout << "Home Wins/Losses: ";
    displayWinLoss(team.home);
    cout << "Away Wins/Losses: ";
    displayWinLoss(team.away);
}

// Function to find a team by name and display its information
void findTeam(Team teams[], int numTeams) {
    string teamName;
    cout << "Enter team name: ";
    cin >> teamName;
    bool found = false;
    for (int i = 0; i < numTeams; i++) {
        if (teams[i].name == teamName) {
            displayTeam(teams[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Team not found." << endl;
    }
}
