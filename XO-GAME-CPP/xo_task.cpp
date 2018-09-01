#include <iostream>

using namespace std;
  int row ,col;
  void Print(char board[3][3])
{
    for (int j=0; j<3; j++)
    {
        for (int i=0; i<3; i++)
        {
            cout<<"  | "<<board[j][i]<<"  | ";
        }
        cout<<endl;

    }

}
     char winner (char board[3][3])
{
    int counter = 0;
    if (board[row][col] == board[row][col+1])
    {
        counter++;
        if (board[row][col] == board[row][col+2])
        {
            counter++;
        }

    }
    if (board[row][col] == board[row][col-1])
    {
        counter++;
        if (board[row][col] == board[row][col-2])
        {
            counter++;
        }

    }
    if (counter >=2 )
    {
        return board[row][col];
    }
     counter =0 ;
    if (board [row][col] == board [row+1][col])
    {
        counter ++ ;
        if (board[row][col] == board[row+2][col])
        {
            counter++;
        }
    }
    if (board [row][col] == board [row-1][col])
    {
        counter ++ ;
        if (board[row][col] == board[row-2][col])
        {
            counter++;
        }
    }

      if (counter >=2 )
    {
        return board[row][col];
    }
     counter =0 ;

      if (board [row][col] == board [row-1][col-1])
    {
        counter ++ ;
        if (board[row][col] == board[row-2][col-2])
        {
            counter++;
        }
    }

      if (board [row][col] == board [row+1][col+1])
    {
        counter ++ ;
        if (board[row][col] == board[row+2][col+2])
        {
            counter++;
        }
    }

     if (counter >=2 )
    {
        return board[row][col];
    }
     counter =0 ;
       if (board [row][col] == board [row+1][col-1])
    {
        counter ++ ;
        if (board[row][col] == board[row+2][col-2])
        {
            counter++;
        }
    }
       if (board [row][col] == board [row-1][col+1])
    {
        counter ++ ;
        if (board[row][col] == board[row-2][col+2])
        {
            counter++;
        }
    }

  if (counter >=2 )
    {
        return board[row][col];
    }
     counter =0 ;
}

int  checkboard (char board[3][3])
{
    int counter =0;
    for (int i =0;i <3 ;i++)
    {
        for (int j = 0;j<3;j++)
        {
            if (board[j][i] == ' ')
            {
                counter++ ;
            }
        }
    }
    return counter ;
}
int main()
{
  char board[3][3];
  for(int i =0;i<3 ;i++)
  {
      for (int j =0 ;j <3;j++)
      {
          board[i][j]= ' ';
      }
  }
Print(board);
while(true){
  while (true )
  {
      if (checkboard(board)>0){
  cin >> ::row>>::col;
  if (board [row][col] == ' ' )
  {
      board[row][col] = 'x';
      Print(board);

      if(winner(board) == 'x')
      {
          cout<< "the winner is x player ";
          return 0 ;
      }
      break;
  }
  else {
    cout<<"insert another place ";
    continue;
  }
  }
  else {
    cout << "the game is draw " ;
    return 0;
  }

  }

while (true )
  {
      if (checkboard(board)>0){
  cin >> ::row>>::col;
  if (board [row][col] == ' ' )
  {
      board[row][col] = 'o';

      Print(board);
      if(winner(board) == 'o')
      {
          cout<< "the winner is o player ";
          return 0 ;
      }
      break;
  }
  else {
    cout<<"insert another place ";
    continue;
  }

  }
  else {
    cout << "the game is draw " ;
    return 0;
  }} }
    return 0;
}
