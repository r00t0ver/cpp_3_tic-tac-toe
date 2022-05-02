#include<iostream>
#include"tictactoe.h"
#include<conio.h>
using namespace std;
void board();
void p_turn();
int main()
{
    char c;
    cout<<"1.Start the game"<<endl;
    cout<<"2.Set player Name"<<endl;
    cout<<"0.exit()"<<endl;
    
    
    do{
        cout<<"Enter a  Choice: ";
        cin>>c;
    if(c=='1')
    {
        game_start();
    }
    else if(c=='2')
    {
       name();
       game_start(); 
    }

    
    }while(c!='0');
    return 0;
}