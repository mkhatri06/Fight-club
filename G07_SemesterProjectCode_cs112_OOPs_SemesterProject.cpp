#include<iostream>
#include<conio.h>
#include<cstdlib> 
#include<ctime>   
#include<thread>
#include<chrono>
#include<iomanip>
#include <array>

using namespace std;

class abstract_requirements
{
    protected:

    virtual void display() = 0;
    virtual int start(int xyz) = 0;
};

class skills : public abstract_requirements {
protected:

    int fighters[8] = {0};
    int health[8] = {0}; 
    int stamina[8] = {0}; 
    int punch_power[8] = {0};
    int sum[8] = {0};
    int h, s, p;

    virtual void display()
    {
        cout << "\nUser-input skills assigned:\n";
    }

public:

void shuffleFighters() // shuffle function
{
    for (int i = 0; i < 8; i++) {
        int randIndex = rand() % 8;

        // Swap indices[i] and indices[randIndex]
        int temp = fighters[i];
        fighters[i] = fighters[randIndex];
        fighters[randIndex] = temp;
    }
}


    int start(int xyz) {
        for (int i = 0; i < xyz; i++) {
            fighters[i] = i;
        }

        cout << "Assign Health (0-99)" << endl;
        for (int i = 0; i < xyz; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> h;

            if (h >= 0 && h <= 99)
            health[i] = h;

            else 
            {
                cout << "Invalid input! Assigning random value..." << endl;
                health[i] = rand() % 100;
            }
        }

        cout << "Assign Stamina (0-99)" << endl;
        for (int i = 0; i < xyz; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> s;

            if (s >= 0 && s <= 99)
            stamina[i] = s;

            else
            {
                cout << "Invalid input! Assigning random value..." << endl;
                stamina[i] = rand() % 100;
            }

        }

        cout << "Assign Punch Power (0-99)" << endl;
        for (int i = 0; i < xyz; i++) {
            cout << "Fighter " << i + 1 << " : ";
            cin >> p;
            
            if (p >= 0 && p <= 99) // ? fixed range
            punch_power[i] = p;

            else
            {
                cout << "Invalid input! Assigning random value..." << endl;
                punch_power[i] = rand() % 100;
            }
        }
        
        for (int i = 0; i < xyz; i++) {
            sum[i] = health[i] + stamina[i] + punch_power[i];
        }
        
        skills :: display();
        for (int i = 0; i < xyz; i++) {
            cout << "Fighter " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
        }

        return 0;
    }

    void Random(int a) {
        for (int i = 8-a; i < 8; i++) {
            fighters[i] = i;
            health[i] = rand() % 100;
            stamina[i] = rand() % 100;
            punch_power[i] = rand() % 100;
            sum[i] = health[i] + stamina[i] + punch_power[i];
        }

        cout << "\nRandom skills assigned:\n";
        for (int i = 8-a; i < 8; i++) {
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

    virtual void display()
    {
        cout << "\n\n";
            cout << "      O            O\n";
            cout << "     /|\\          /|\\\n";
            cout << "     / \\          / \\\n";
            cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

public:

    virtual int start(int xyz) {
        cout << "\n\nGroup matches..." << endl << endl;
        
        int semi_index = 0;
        for (int i = 0, n = 7; i < 4 && n > 3; i++, n--) {
            cout << "\nFighter " << fighters[i] + 1 << " vs Fighter " << fighters[n] + 1 << "..." << endl;

            fight_club :: display();

            cin.ignore(); // input buffer
            cin.get();
            
            if (sum[fighters[i]] > sum[fighters[n]]) { // ? use shuffled fighter indices
                cout << "Fighter " << fighters[i] + 1 << " won the fight!\n";
                semi[semi_index++] = fighters[i];
            } else {
                cout << "Fighter " << fighters[n] + 1 << " won the fight!\n";
                semi[semi_index++] = fighters[n];
            }
        }

        cout << "\n\nSemi-finals..." << endl << endl;

        int final_index = 0;
        for (int i = 0, n = 3; i < 2 && n > 1; i++, n--) {
            cout << "\nFighter " << semi[i] + 1 << " vs Fighter " << semi[n] + 1 << "..." << endl;

            fight_club :: display();

            cin.ignore(); //input buffer
            cin.get();

            if (sum[semi[i]] > sum[semi[n]]) { // ? fixed logic
                cout << "Fighter " << semi[i] + 1 << " won the semi-final!\n";
                final[final_index++] = semi[i];
            } else {
                cout << "Fighter " << semi[n] + 1 << " won the semi-final!\n";
                final[final_index++] = semi[n];
            }
        }

        cout << "\n\nFinal..." << endl << endl;
        cout << "\nFighter " << final[0] + 1 << " vs Fighter " << final[1] + 1 << "..." << endl;
    
        fight_club :: display();

        cin.ignore(); //input buffer
        cin.get();

        if (sum[final[0]] > sum[final[1]]) { // ? correct indexing
            cout << "\nFighter " << final[0] + 1 << " wins the tournament!!! \n";
        } else {
            cout << "\nFighter " << final[1] + 1 << " wins the tournament!!! \n";
        }

        return 0;
    }
};

class tournament : public fight_club {
public:

    void display()
    {
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
    }

    int start(int xyz) override {
        int a, b;
        
        display();

        cout << "How many fighters do you want to randomize (0-8)? ";
        cin >> a;

        b = 8 - a;

        if (b > 0) {
            skills :: start(b);
        }
        if (a > 0 && a <= 8) {
            skills :: Random(a);
        }
        else if (a < 0 || a > 8) {
            cout << "Invalid Input " << endl;
            return 0;
        }

        shuffleFighters();

        fight_club :: start(2);
        
        return 0;
    }
};

int main() {

    srand(time(0));

    fight_club* t = new tournament();
    t ->  start(7);
}

   
