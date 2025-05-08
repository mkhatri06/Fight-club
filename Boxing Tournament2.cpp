#include<iostream>
#include<conio.h>
#include<cstdlib> 
#include<ctime>   
#include<thread>
#include<chrono>
#include<iomanip>

using namespace std;


class skills {
protected:
    int fighters[8] = {0};
    int health[8] = {0}; 
    int stamina[8] = {0}; 
    int punch_power[8] = {0};
    int sum[8] = {0};

public:
    void UD_skills(int b) {
        for (int i = 0; i < b; i++) {
            fighters[i] = i;
        }

        cout << "Assign Health (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> health[i];
        }

        cout << "Assign Stamina (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> stamina[i];
        }

        cout << "Assign Punch Power (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> punch_power[i];
        }
        
        for (int i = 0; i < b; i++) {
            sum[i] = health[i] + stamina[i] + punch_power[i];
        }
        
        cout << "\nUser-defined skills assigned:\n";
        for (int i = 0; i < b; i++) {
            cout << "Fighter " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
        }
    }

    void Random(int a) {
        for (int i = 0; i < a; i++) {
            fighters[i] = i;
            health[i] = rand() % 100;
            stamina[i] = rand() % 100;
            punch_power[i] = rand() % 100;
            sum[i] = health[i] + stamina[i] + punch_power[i];
        }

        cout << "\nRandom skills assigned:\n";
        for (int i = 0; i < a; i++) {
            cout << "Fighter " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
        }
    }
};

class fight_club : public skills {
protected:
    int semi[4] = {0};
    int final[2] = {0};


public:
    void fight() {
        cout << "\n\nGroup matches..." << endl << endl;
        
        int semi_index = 0;
        for (int i = 0, n = 7; i < 4 && n > 3; i++, n--) {
            cout << "\nFighter " << i + 1 << " vs Fighter " << n + 1 << "..." << endl;

			cout << "\n\n";
            cout << "      O            O\n";
            cout << "     /|\\          /|\\\n";
            cout << "     / \\          / \\\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(400));

            
			getch();
            
            if (sum[i] > sum[n]) {
                cout << "Fighter " << i + 1 << " won the fight!\n";
                semi[semi_index++] = i + 1;
            } else {
                cout << "Fighter " << n + 1 << " won the fight!\n";
                semi[semi_index++] = n + 1;
            }
        }

        cout << "\n\nSemi-finals..." << endl << endl;

        int final_index = 0;
        for (int i = 0, n = 3; i < 2 && n > 1; i++, n--) {
            cout << "\nFighter " << semi[i] << " vs Fighter " << semi[n] << "..." << endl;

			cout << "\n\n";
            cout << "      O            O\n";
            cout << "     /|\\          /|\\\n";
            cout << "     / \\          / \\\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(400));


            getch();

            if (sum[semi[i] - 1] > sum[semi[n] - 1]) {
                cout << "Fighter " << semi[i] << " won the semi-final!\n";
                final[final_index++] = semi[i];
            } else {
                cout << "Fighter " << semi[n] << " won the semi-final!\n";
                final[final_index++] = semi[n];
            }
        }

        cout << "\n\nFinal..." << endl << endl;
        cout << "\nFighter " << final[0] << " vs Fighter " << final[1] << "..." << endl;
    
		cout << "\n\n";
        cout << "      O            O\n";
        cout << "     /|\\          /|\\\n";
  	    cout << "     / \\          / \\\n";
	    cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));

	
	
	    getch();

        if (sum[final[0] - 1] > sum[final[1] - 1]) {
            cout << "\nFighter " << final[0] << " wins the tournament!!! \n";
        } else {
            cout << "\nFighter " << final[1] << " wins the tournament!!! \n";
        }
    }
};

class tournament : public fight_club {
public:
    int start() {
        int a, b;
        
	 const std::string heading = R"( 
  ||||||||  ||||||   ||||||||   ||      ||   |||||||||||||       ||||||||||||   ||          |||      |||   ||||||||
  ||          ||     |||        ||      ||        |||            |||       ||   ||          |||      |||   |||     |
  ||||||      ||     |||  ||||  ||||||||||        |||            |||            ||          |||      |||   ||||||||
  ||          ||     |||   |||  ||      ||        |||            |||       ||   ||          |||      |||   |||     |
  ||        ||||||   |||||||||  ||      ||        |||            ||||||||||||   |||||||||   ||||||||||||   ||||||||
    )";

    int width = 100; // Total width of the console (adjust as needed)

    // Calculate padding for centering the text
    int padding = (width - heading.length()) / 2;

    std::cout << std::setw(padding + heading.length()) << heading << std::endl;
		
		
		
        cout << "How many fighters do you want to randomize (0-8)? ";
        cin >> a;

        b = 8 - a;

        if (b > 0) {
            UD_skills(b);
        }
        if (a > 0 && a< 9) {
            Random(a);
        }
        else {
        	cout<<"Invalid Input "<<endl;
        	return 0;
		}

        fight();
    }
};

int main() {
    srand(time(0));

    tournament t;
    t.start();

    return 0;
}

