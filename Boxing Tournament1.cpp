#include<iostream>
#include<conio.h>
#include<cstdlib> 
#include<ctime>   
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

        cout << "Health (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "fighter " << i + 1 << " : ";
            cin >> health[i];
        }

        cout << "Stamina (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "fighter " << i + 1 << " : ";
            cin >> stamina[i];
        }

        cout << "Punch Power (0-99)" << endl;
        for (int i = 0; i < b; i++) {
            cout << "fighter " << i + 1 << " : ";
            cin >> punch_power[i];
        }
        
        for(int i=0; i<b; i++){
        	
        	sum[i] = health[i] + stamina[i] + punch_power[i];
		}
        
        cout << "User-defined skills assigned:\n";
        for (int i = 0; i < b; i++) {
            cout << "fighter " << i + 1
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
        }
	
	
        cout << "Random skills assigned:\n";
        for (int i = 0; i < a; i++) {
            cout << "fighter " << i + 1
                 << " | Health: " << health[i]
                 << " | Stamina: " << stamina[i]
                 << " | Punch Power: " << punch_power[i] << endl;
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
		
		for (int i = 1, n = 8; i < 5 && n > 4; i++, n--) {
 
 		cout<<"\nfighter "<<i<<" and "<<n<<" are fighting..."<<endl;
 		
 		getch();
		
		if(sum[i]> sum[n]){
			
			cout<<"fighter "<<i<<" won the fight"<<endl;
			semi[i] = i;
		}
		
		else {
			
			cout<<"fighter "<<n<<" won the fight"<<endl;
			semi[i] = n;
		}
		
		}
		
		
 		cout<<"\n\nSemi final..."<<endl<<endl;
 		for (int i = 1, n = 4; i < 3 && n > 2; i++, n--) {
 
 		cout<<"\nfighter "<<semi[i]<<" and "<<semi[n]<<" are fighting..."<<endl;
		
		getch();
		
		if(semi[i]> semi[n]){
			
			cout<<"fighter "<<semi[i]<<" won the fight"<<endl;
			final[i] = semi[i];
		}
		
		else {
			
			cout<<"fighter "<<semi[n]<<" won the fight"<<endl;
			final[i] = semi[n];
		}
		
			
		}
		
		cout<<"\n\nFinal..."<<endl<<endl;
 		
 		cout<<"\nfighter "<<final[0]<<" and "<<final[1]<<" are fighting..."<<endl;
		
		getch();
		
		if(final[0]> final[1]){
			
			cout<<"fighter "<<final[0]<<" won the fight"<<endl;
			cout<<"\n\nfighter "<<final[0]<<" won the tournament"<<endl;
		
		}
		
		else {
			
			cout<<"fighter "<<final[1]<<" won the fight"<<endl;
			cout<<"\nfighter "<<final[0]<<" won the tournament"<<endl;
		
		}
		
	}
		
	
	
	
}; 

class tournament : public fight_club {
public:
    void start() {
       // int choice;
        int a;
        int b;
        
        
		
		
		
		
		cout << "Welcome to the boxing tournament!!!" << endl<< endl<< endl;
       // cout << "1. User-defined assigning of skills of fighters" << endl;
       // cout << "2. Random assigning of skills of fighters" << endl<< endl;
       // cout << "Enter your choice: ";
       // cin >> choice;
		
		cout<<"How many fighters fighters do you want to randomize : ";
		cin>>a;
		
		b = 8-a;
					
        //if (choice == 1) {
            UD_skills(b);
        //} else if (choice == 2) {
            Random(a);
        //} else {
         //   cout << "Invalid choice!" << endl;
        //}
        
        fight();
        
        
    }
};

int main() {
    srand(time(0)); 

    tournament t;
    t.start();

    return 0;
}

