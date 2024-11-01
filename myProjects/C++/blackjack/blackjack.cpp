#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <vector>


using namespace std;

void play();
void playerStart();
void dealerStart();
void decision(string);
int faceToNumber(int);
string faceCardToString(int , string);
string dealerDraw();
string playerDraw();

enum faceCards{J=11, Q=12, K=13, A=14};
enum class gameStatus{CONTINUE, END};

int playerTotal=0, dealerTotal=0;
double totalMoney=0, bet=0; 
string playerDecision="";
gameStatus Status=gameStatus::CONTINUE;
vector<int> playerDraws;

int main(){
    srand(static_cast<unsigned int>(time(0)));
    
    play();

    return 0;
}

void play(){
    cout<<"How much total money in chips?: ";
    cin>>totalMoney;
    dealerStart();
    string playOn="";
    bool cont=true; 
    while(cont){
        while(true){
        cout<<"\n\nHow much money to bet?: ";
        cin>>bet;
        if(totalMoney-bet<0){
            cout<<"Insufficient funds, please try again: ";
        }else{
            break;
        }
        }

    playerStart();
    
    if(playerTotal==21){
        while(dealerTotal<17){
            cout<<"Dealer: "<<dealerDraw()<<"Total: "<<dealerTotal<<endl;
        }
        if(dealerTotal==21){
            cout<<"Push"<<endl;
        }
    }
    
    while(Status==gameStatus::CONTINUE){
        cout<<"Hit or Stand?: "<<endl;
        cin>>playerDecision;
        decision(playerDecision);


        if(playerDecision=="stand"){
            while(dealerTotal<17){
                cout<<"Dealer drew: "<<dealerDraw()<<" Total: "<<dealerTotal<<endl;
            }
            if(dealerTotal==playerTotal){
                cout<<"Push"<<endl;
            } else if(dealerTotal<=21&&dealerTotal>playerTotal){
                cout<<"Dealer wins"<<endl;
                totalMoney-=bet;
            } else{
                cout<<"You won!"<<endl;
                totalMoney+=bet;
            }
        Status=gameStatus::END;
        }
    }
    
    }
    cout<<"Play again: Y/N"<<endl;
    cin>>playOn;
    if(playOn=="Y"){
        cont=true;
    }
}

string playerDraw(){
    int card=2+rand()%12;
    string cardString=to_string(card);
    cardString=faceCardToString(card, cardString);
    card=faceToNumber(card);
    playerTotal+=card;
    return cardString;
}

string dealerDraw(){
    int card=2+rand()%12;
    string cardString=to_string(card);
    cardString=faceCardToString(card, cardString);
    card=faceToNumber(card);
    dealerTotal+=card;
    return cardString;
}

void playerStart(){
    cout<<"You: "<< playerDraw()<<" "<<playerDraw()<<" "<<"Total: "<<playerTotal<<endl;
}

void dealerStart(){
    cout<<"Dealer: "<< dealerDraw()<< " Total:" <<dealerTotal<<endl;
}

string faceCardToString(int card, string cardString){
    switch (card)
    {
    case J:
        cardString="J";
        break;
    case Q:
        cardString="Q";
        break;
    case K:
        cardString="K";
        break;
    case A:
        cardString= "A";
        break;
    default:
        break;
    } 
    return cardString;
}
int faceToNumber(int num){
    switch (num)
    {
    case 11:
    case 12:
    case 13:
        num=10; 
        break;
    case 14:
        num=11;
        break;      
    default:
        break;
    }
    return num;
}
void decision(string decision){
    int card= 2+rand()%12;
    for(auto& letter:decision){
        letter=tolower(letter);
    }
    card=faceToNumber(card);
    if(decision=="hit"){
        playerTotal+=card;
        cout<<"You drew: "<<faceCardToString(card, to_string(card))<<endl;
        cout<<"Dealer: "<<dealerTotal<<endl;
    }
    if(playerTotal>21){
        cout<<"You lose, your total is: "<<playerTotal<<endl;
        totalMoney-=bet;
        Status=gameStatus::END;
    }
    if(playerTotal==21){
        cout<<"You win"<<endl;
        totalMoney+=bet;
        Status=gameStatus::END;
    }
}



