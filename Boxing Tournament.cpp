#include<iostream>
#include<cstdlib> 
#include<ctime>   
using namespace std;

class skills {
protected:
    int boxers[8] = {0};
    int health[8] = {0}; 
	int stamina[8] = {0}; 
	int punch_power[8] = {0};
	int sum[8] = {0};

public:
    void UD_skills() {
        for (int i = 0; i < 8; i++) {
            boxers[i] = i;
        }

        cout << "Health (0-99)" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "Boxer " << i + 1 << " : ";
            cin >> health[i];
        }

        cout << "Stamina (0-99)" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "Boxer " << i + 1 << " : ";
            cin >> stamina[i];
        }

        cout << "Punch Power (0-99)" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "Boxer " << i + 1 << " : ";
            cin >> punch_power[i];
        }
        
        for(int i=0; i<8; i++){
        	
        	sum[i] = health[i] + stamina[i] + punch_power[i];
		}
        
        cout << "User-defined skills assigned:\n";
        for (int i = 0; i < 8; i++) {
            cout << "Boxer " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
        }
        
        for(int i=0; i<8; i++){
        	
        	sum[i] = health[i] + stamina[i] + punch_power[i];
		}
        
    }

    void Random() {
        for (int i = 0; i < 8; i++) {
            boxers[i] = i;
            health[i] = rand() % 100;
            stamina[i] = rand() % 100;
            punch_power[i] = rand() % 100;
        }
	
	
        cout << "Random skills assigned:\n";
        for (int i = 0; i < 8; i++) {
            cout << "Boxer " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
        }
        for(int i=0; i<8; i++){
        	
        	sum[i] = health[i] + stamina[i] + punch_power[i];
		}
        
    }
};

class fight_club : public skills{
	
	protected :
		int semi[4]={0};
		int final[2]={0};
	public:
		
		void fight(){
		
		cout<<"\n\nGroup matches..."<<endl<<endl;
		
		for (int i = 0, n = 7; i < 4 && n > 3; i++, n--) {
 
 		cout<<"Boxer "<<i+1<<" and "<<n+1<<" are fighting..."<<endl;
		
		if(sum[i]> sum[n]){
			
			cout<<"Boxer "<<i+1<<" won the fight"<<endl;
			semi[i] = i+1;
		}
		
		else {
			
			cout<<"Boxer "<<n+1<<" won the fight"<<endl;
			semi[i] = n+1;
		}
		
		}
		
		
 		cout<<"\n\nSemi final..."<<endl<<endl;
 		for (int i = 0, n = 3; i < 2 && n > 1; i++, n--) {
 
 		cout<<"Boxer "<<semi[i]<<" and "<<semi[n]<<" are fighting..."<<endl;
		
		if(sum[i]> sum[n]){
			
			cout<<"Boxer "<<semi[i]<<" won the fight"<<endl;
			final[i] = semi[i];
		}
		
		else {
			
			cout<<"Boxer "<<semi[n]<<" won the fight"<<endl;
			final[i] = semi[n];
		}
		
			
		}
		
		cout<<"\n\nFinal..."<<endl<<endl;
 		
 		cout<<"Boxer "<<final[0]<<" and "<<final[1]<<" are fighting..."<<endl;
		
		if([0]> final[1]){
			
			cout<<"Boxer "<<final[0]<<" won the fight"<<endl;
			cout<<"\n\nBoxer "<<final[0]<<" won the tournament"<<endl;
		
		}
		
		else {
			
			cout<<"Boxer "<<final[1]<<" won the fight"<<endl;
			cout<<"\nBoxer "<<final[1]<<" won the tournament"<<endl;
		
		}
		
	}
		
	
	
	
}; 

class tournament : public fight_club {
public:
    void start() {
        int choice;
        cout << "Welcome to the boxing tournament!!!" << endl<< endl<< endl;
        cout << "1. User-defined assigning of skills of boxers" << endl;
        cout << "2. Random assigning of skills of boxers" << endl<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            UD_skills();
        } else if (choice == 2) {
            Random();
        } else {
            cout << "Invalid choice!" << endl;
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

