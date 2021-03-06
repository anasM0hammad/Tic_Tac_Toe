#include<iostream>
#include<stdlib.h>
#include<ctime>


using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'} ;



// Function to print the Tic Tac Toe Board

void board()                                   
{
	cout<<"\n\n\t TIC TAC TOE \n\n" ;
	cout<<"\n" ;
	cout<<"\t Player 1 is O   --   Player 2 is X";
	cout<<"\n\n\n";
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t   "<<square[1]<<"  |  "<<square[2]<<"   |  "<<square[3]<<endl ;
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t  ------------------"<<endl;
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t   "<<square[4]<<"  |  "<<square[5]<<"   |  "<<square[6]<<endl ;
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t  -------------------"<<endl;
	cout<<"\t      |      |      "<<endl ;
	cout<<"\t   "<<square[7]<<"  |  "<<square[8]<<"   |  "<<square[9]<<endl ;
	cout<<"\t      |      |      "<<endl ;
	cout<<endl ;
}


// function to check the condition of the game after every turn

// will return 1 if any player wins

// will return 0 if no one wins

// will return -1 if game is not complete

int check_win()
{
	if(square[1] == square[2] && square[2] == square[3])
		return 1;

	else if (square[4] == square[5] && square[5] == square[6])
	   return 1;

	else if (square[7] == square[8] && square[8] == square[9])
	   return 1;

    else if (square[1] == square[4] && square[4] == square[7])
	   return 1;

	 else if (square[2] == square[5] && square[5] == square[8])
	   return 1;

	 else if (square[3] == square[6] && square[6] == square[9])
	   return 1;

	 else if (square[1] == square[5] && square[5] == square[9])
	   return 1;

	 else if (square[3] == square[5] && square[5] == square[7])
	   return 1;

	 else if(square[1]!='1' && square[2]!='2' && square[3]!= '3' && square[4]!= '4' && square[5]!= '5' && square[6]!= '6' && square[7]!= '7' && square[8]!= '8' && square[9]!= '9')
	 	return 0;

	 else
	 	return -1 ;

}

int main()
{
	int choice , player=1, result=-1, game_type ;               // -1 result means game is not complete initially
	char mark ;                                        //tic tac toe mark for each player
  srand (time(NULL)) ;

  cout<<"\n\n WELCOME TO TIC TAC TOE\n\n";
  cout<<"1.Play with Computer\n";
  cout<<"2.Play with Friend\n" ; 
  cin>>game_type ;

  if(game_type!=1 && game_type!=2)
  {
    game_type=1 ;
    cout<<"\nDefault game On.... Play with Computer\n" ;
  }

 	
 
	while(result==-1)
	{
       system("cls");
       board() ;
       cout<<"\n\n";

       if(game_type==2)
       {
         cout<<"\tplayer "<<player<<" Enter the Place number : ";
         cin>>choice ;
       } 

       else{

        if(player==1)
         { 
           cout<<"\tEnter the place number : " ;
           cin>>choice;
          }
          
          else
          {
            choice=(rand()%9 + 1) ;
          } 
       }

       if(player == 1)
       	mark = 'O' ;

       else
       	mark = 'X' ;


       if(choice<1 || choice >9)
       {
       	cout<<"Wrong Choice" ;
       	player = 3-player ;
       }

  
    else{
    
       if(square[choice]!='X' && square[choice]!='O')
       	 {
            square[choice] = mark ;
       	 }

       	 else
          {
          	cout<<"Already taken" ;
          	player= 3-player;
          }

      }

      player= 3-player;
      result = check_win() ;

  }
  
  system("cls");
  board();

  if(result == 0)
  	cout<<"\n\t   TIE\n" ;

  if(result== 1)
  {
  	if(mark == 'X' && game_type==2)
  		cout<<"\n\t   PLAYER 2 WINS\n";

    else if(mark =='X' && game_type == 1 )
      cout<<"\n\t   Computer Wins\n" ;   

  	else
  		cout<<"\n\t   PLAYER 1 WINS\n" ;

   }

    

   
	return 0;
}