#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

class Player {
	char playerName[30];
	int score;
	public:
	Player(){
	}
	Player(const Player &p){
        	strcpy(playerName,p.playerName);
		this->score = p.score;
	}
	void getPlayer(char name[],int turn,int score=0){
		strcpy(playerName,name);
		this->score = score;
	}
	char * getPlayerName(){
		return playerName;
	}
	void play(int force){
		srand(time(0));
		int random = (rand() % (20-15+1)) +15;
		cout<<random<<endl;
		if(abs(random-force) == 0){
				this->score += 50;
				cout<<"\tBingo !! A perfect Drop.You got 50 Points"<<endl;
		}else if(abs(random-force)<2 && abs(random-force)>0){
			this->score += 25;
			cout<<"\tAwesome ! you got 25 points."<<endl;
		}else{
			this->score += 0;
			cout<<"\tOops ! You Missed it."<<endl;
		}
		
	}
	void displayScore(){
		cout<<"\t\t"<<playerName<<"\t\tScore : "<<score<<endl;
	}
	friend void BubbleSort(Player *p,int n);

};

void rules(){
    cout << "\t======PUT THE BALL IN BASKET RULES!======\n";
    cout << "\t1. Enter the magnitude of force \n";
    cout << "\t2. After each Ball Droped in the Basket Directly Player gets 50 Points \n";  
    cout << "\t3. After each Ball Droped in the Basket indirectly, Player gets 25 Points \n";
    cout << "\t4. If ball missed Basket, Player gets 0 Points \n\n";
}
void BubbleSort(Player *p,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].score < p[j+1].score){
				Player temp = p[j];
				p[j] = p[j+1];
				p[j+1] =temp;
			}
}
}
}
int main(){
	cout<<"\n\t\t============================== Put The Ball in Basket =========================="<<endl;
		rules();
		int n;
		cout<<"\n\tEnter the number of Players(atleast 2 Players) : ";
		cin>>n;
		Player p[n];
		char name[30];
		int force;
		for(int i=0;i<n;i++){
			cout<<"\n\tEnter the Player "<<i+1<<" Name : ";
			cin>>name;
			p[i].getPlayer(name,i+1);
		}
		for(int j=0;j<3;j++){
			cout<<"\n\t\t ++++========++++ Round "<<j+1<<" ++++========++++"<<endl;
		for(int i=0;i<n;i++){
			cout<<"\n\t--------Player "<<p[i].getPlayerName()<<" turns-------"<<endl;
			cout<<"\tEnter the force between 20 and 15 : ";
			cin>>force;
			p[i].play(force);
		}
		}
		cout<<"\n\t\t++++++++++++++++Final ScoreBoard++++++++++++++++"<<endl;
		BubbleSort(p,n);
		for(int i=0;i<n;i++){
			cout<<"\n\tPosition\t\tPlayer Name\t\t Score\n\t\t"<<i+1;
			p[i].displayScore();
		}
		return 0;
}


			

		


	



