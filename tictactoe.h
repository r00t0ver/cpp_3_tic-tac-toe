#include<iostream>
#include<cstring>
using namespace std;
char bp[3][3]={'1','2','3','4','5','6','7','8','9'};
int row,col;
string player1="PLAYER-1",player2="PLAYER-2";
char turn='X';
void winner();
bool winner_progress();
void p_turn();
void board();

void game_start()
{
        do
    {   
        board();
        p_turn();
        system("cls");

    }while(winner_progress());
    cout<<"\n\n";
    cout<<"Match results :";
    winner();
}
void name()
{
    cout<<"Enter first player name: ";
    cin>>player1;
    cout<<"Enter second player name: ";
    cin>>player2;
    
}
void board()
{   
    system("color a");
    cout<<"         T I C    T A C   T O E\n"<<endl;
    cout<<player1<<" = X\t\t"<<player2<<" = O"<<endl;
    cout<<"      |         |       "<<endl; 
    cout<<"  "<<bp[0][0]<<"   |    "<<bp[0][1]<<"    |    "<<bp[0][2]<<"    "<<endl;  
    cout<<"______|_________|_______"<<endl;
    cout<<"      |         |       "<<endl;
    cout<<"  "<<bp[1][0]<<"   |    "<<bp[1][1]<<"    |    "<<bp[1][2]<<"   "<<endl;
    cout<<"______|_________|_______"<<endl;
    cout<<"      |         |       "<<endl;
    cout<<"  "<<bp[2][0]<<"   |    "<<bp[2][1]<<"    |    "<<bp[2][2]<<"   "<<endl;
    cout<<"      |         |       "<<endl;

}
void p_turn()
{  
    char choice;
    if(turn=='X')
    {cout<<player1<<" (X) :";cin>>choice;}
    else if(turn=='O')
    {cout<<player2<<" (O) :";cin>>choice;}
    
    switch(choice)
    {
        case '1' :row=0;col=0;break;
        case '2' :row=0;col=1;break;
        case '3' :row=0;col=2;break;
        case '4' :row=1;col=0;break;
        case '5' :row=1;col=1;break;
        case '6' :row=1;col=2;break;
        case '7' :row=2;col=0;break;
        case '8' :row=2;col=1;break;
        case '9' :row=2;col=2;break;
        default:cout<<"Invalid choice"<<endl;
    }
    if(turn=='X'&&(bp[row][col]!='X'&&bp[row][col]!='O'))
    {
        bp[row][col]=turn;;
        turn='O';
    }
    else if(turn=='O'&&(bp[row][col]!='X'&&bp[row][col]!='O'))
    {
        bp[row][col]=turn;
        turn='X';
    }
    else
    cout<<"Already Filled !"<<endl;
    

    

    
}

void winner()
{
    
    int i=0,j=0;
    for(i=0;i<3;i++){
         if(bp[i][0]=='X'&&bp[i][1]=='X'&&bp[i][2]=='X'){cout<<player1<<" WON the game!";break;}
    else if(bp[0][i]=='X'&&bp[1][i]=='X'&&bp[2][i]=='X'){cout<<player1<<" WON the game!";break;}
    else if(bp[0][0]=='X'&&bp[1][1]=='X'&&bp[2][2]=='X'){cout<<player1<<" WON the game!";break;}
    else if(bp[0][2]=='X'&&bp[1][1]=='X'&&bp[0][2]=='X'){cout<<player1<<" WON the game!";break;}
    else if(bp[i][0]=='O'&&bp[i][1]=='O'&&bp[i][2]=='O'){cout<<player2<<" WON the game!";break;}
    else if(bp[0][i]=='O'&&bp[1][i]=='O'&&bp[2][i]=='O'){cout<<player2<<" WON the game!";break;}
    else if(bp[0][0]=='O'&&bp[1][1]=='O'&&bp[2][2]=='O'){cout<<player2<<" WON the game!";break;}
    else if(bp[0][2]=='O'&&bp[1][1]=='O'&&bp[0][2]=='O'){cout<<player2<<" WON the game!";break;}
    else if((bp[0][0]!='1')&&(bp[0][1]!='2')&&(bp[0][2]!='3')&&(
        bp[1][0]!='4')&&(bp[1][1]!='5')&&(bp[1][2]!='6')&&(
        bp[2][0]!='7')&&(bp[2][1]!='8')&&(bp[2][2]!='9'))
        {
            cout<<"Draw !";break;
        }
    }
}

bool winner_progress()
{
    int i;
    bool bol=true;
    for(i=0;i<3;i++)
    {
        if(bp[i][0]==bp[i][1]&&bp[i][1]==bp[i][2])
        {
            bol= false;
            goto a;
        }
        else if(bp[0][i]==bp[1][i]&&bp[1][i]==bp[2][i])
        {
        bol= false;goto a;
        }
        else if(bp[0][0]==bp[1][1]&&bp[1][1]==bp[2][2])
        {
            bol=false;goto a;
        }
        else if(bp[0][2]==bp[1][1]&&bp[1][1]==bp[2][0])
        {
            bol=false;goto a;
        }
        else if((bp[0][0]!='1')&&(bp[0][1]!='2')&&(bp[0][2]!='3')&&(
        bp[1][0]!='4')&&(bp[1][1]!='5')&&(bp[1][2]!='6')&&(
        bp[2][0]!='7')&&(bp[2][1]!='8')&&(bp[2][2]!='9'))
        {
            
            bol=false;goto a;
            
        }
    
    }
    
    
    a:
    return bol;
}