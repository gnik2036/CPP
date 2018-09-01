#include<iostream>
using namespace std;
int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0;
int columnnn=0;
char IsWinning(char board[6][7])
{
    int x=0,y =0;
    if (::columnnn == 0)
    {
        x=::count0-1;
        y=::columnnn;
    }
    if (::columnnn == 1)
    {
        x=::count1-1;
        y=::columnnn;
    }
    if (::columnnn == 2)
    {
        x=::count2-1;
        y=::columnnn;
    }
    if (::columnnn == 3)
    {
        x=::count3-1;
        y=::columnnn;
    }
    if (::columnnn == 4)
    {
        x=::count4-1;
        y=::columnnn;
    }
    if (::columnnn == 5)
    {
        x=::count5-1;
        y=::columnnn;
    }
    if (::columnnn == 6)
    {
        x=::count6-1;
        y=::columnnn;
    }


    int countwin=0;
    if (board[x][y]==board[x][y+1])
    {
        countwin++;
        if (board[x][y] == board[x][y+2])
        {
            countwin++;

            if (board[x][y] ==board [x][y+3])
            {
                countwin++;

            }
        }

    }
    if (board[x][y]==board[x][y-1])
    {
        countwin++;
        if (board[x][y] == board[x][y-2])
        {
            countwin++;

            if (board[x][y] == board[x][y-3])
            {
                countwin++;
            }
        }
    }
    if (countwin >= 3)
    {
        return  board[x][y];
    }

    //*************************be el3ard *******************************
    countwin==0;
    if (board[x][y]==board[x+1][y])
    {
        countwin++;
        if (board[x][y] == board[x+2][y])
        {
            countwin++;

            if (board[x][y] == board[x+3][y])
            {
                countwin++;
            }
        }

    }
    if (board[x][y]==board[x-1][y])
    {

        countwin++;
        if (board[x][y] == board[x-2][y])
        {
            countwin++;

            if (board[x][y] == board[x-3][y])
            {
                countwin++;
            }
        }
    }
    if (countwin >= 3)
    {
        return  board[x][y];
    }
//***************************************elly fo2 b eltoooool  ******************************************************
    countwin==0;
    if (board[x][y]==board[x-1][y+1])
    {
        countwin++;
        if(board[x][y]==board[x-2][y+2])
        {
            countwin++;
            if (board[x][y]==board[x-3][y+3])
            {
                countwin++;
            }
        }

    }
    if (board[x][y]==board[x+1][y-1])
    {
        countwin++;
        if(board[x][y]==board[x+2][y-2])
        {
            countwin++;
            if (board[x][y]==board[x+3][y-3])
            {
                countwin++;
            }
        }

    }
    if (countwin >= 3)
    {
        return  board[x][y];
    }
// *****************************************be diagonals right ***************************
    countwin==0;
    if (board[x][y]==board[x-1][y-1])
    {
        countwin++;
        if(board[x][y]==board[x-2][y-2])
        {
            countwin++;
            if (board[x][y]==board[x-3][y-3])
            {
                countwin++;
            }
        }

    }
    if (board[x][y]==board[x+1][y+1])
    {
        countwin++;
        if(board[x][y]==board[x+2][y+2])
        {
            countwin++;
            if (board[x][y]==board[x+3][y+3])
            {
                countwin++;
            }
        }

    }
    if (countwin >= 3)
    {
        return  board[x][y];
    }
    //******************************* diagonals left ***********************************************
}

bool Insert(char board[6][7], char player,  int column)
{

    // int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,::count6=0;
    if (column==0)
    {
        if (::count0<6 )
        {
            board [::count0][0]= player  ;
            ::count0++;
            return true;
        }
        else return false;
    }
    if (column==1)
    {
        if (::count1<6 )
        {
            board [::count1][1]= player ;
            ::count1++;
            return true;
        }
        else return false;
    }
    if (column==2)
    {
        if (::count2<6 )
        {
            board[::count2][2]= player ;
            ::count2++;

            return true;
        }
        else return false;
    }
    if (column==3)
    {
        if (::count3<6 )
        {
            board[::count3][3]=player ;
            ::count3++;

            return true;
        }
        else return false;
    }
    if (column==4)
    {
        if (::count4<6 )
        {

            board[::count4][4]= player ;
            ::count4++;
            return true;
        }
        else return false;
    }
    if (column==5)
    {
        if (::count5<6 )
        {

            board[::count5][5]= player ;
            ::count5++;
            return true;
        }
        else return false ;

    }

    if (column==6)
    {
        if (::count6<6 )
        {
            board[::count6][6]= player ;
            ::count6++;

            return true;
        }
        else return false;
    }
    else return false ;

}
void Print(char board[6][7])
{
    for (int j=0; j<6; j++)
    {
        for (int i=0; i<7; i++)
        {
            cout<<"  | "<<board[j][i]<<"  | ";
        }
        cout<<endl;

    }

}

int main ()
{
    char board [6][7];
    char player1 = 'x';
    char player2 ='o';
    bool flag1,flag2;
    char win1,win2;
    cout<<"welcome at connect four "<<endl;
    for (int j=0; j<6; j++)
    {
        for (int i=0; i<7; i++)
        {
            board[j][i] = ' ';
        }

    }
    Print(board);
    while(true)
    {
        cout<<"enter the  play for first player  ";
        cin>>::columnnn;
        flag1 =Insert(board,player1,columnnn);

        if ( true ==  flag1 )
        {
            Print(board);
            win1 = IsWinning(board);
            if (win1 == player1)
            {
                cout<< "the winning player is player 1 " "x" " ";
                break;
            }
        }
        else continue;


    again:
        cout<<"enter the  play for second  player  ";
        cin>>::columnnn;
        flag2=Insert(board,player2,columnnn) ;
        if ( true== flag2  )
        {
            Print(board);

            win2 = IsWinning(board);
            if (win2 == player2) {
                cout<< "the winning player is player 2 " "o" " ";
                break;
            }
            continue;
        }
        else goto again;

    }
    return 0;
}
