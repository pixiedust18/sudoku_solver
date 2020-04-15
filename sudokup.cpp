#define MAX 9
#include<math.h>
#include <iostream>
using namespace std;

class Sudoku
{
    public:
    int grid[MAX][MAX];
                      
    Sudoku()
    {    
        for(int i=0; i<MAX; i++)
        {
            for(int j=0; j<MAX; j++)
            {
                grid[i][j]=0;
            }
        }
    }
    int check_vert(int checkee, int r, int c);
    int check_hor(int checkee, int r, int c);
    int check_block(int checkee, int r, int c);
    int possible(int checkee, int r, int c);
    int full(int &r, int &c);
    int solve();
    void display();
};
int Sudoku::full(int& r, int &c)
{
    int flag=1;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(grid[i][j]==0)
            {
                r=i;
                c=j;
                flag=0;
                //cout<<"r:"<<r<<" c:"<<c<<" ";
                return 0;
            }
        }
    }
    return 1;
}
int Sudoku::check_vert(int checkee, int r, int c)
{
    int flag=1;
    for(int i=0; i<MAX; i++)
    {
        if(grid[i][c]==checkee)
        {
            flag=0;
            break;
        }   
    }
   // cout<<checkee<<"ver:"<<flag<<" "<<"|";
    return flag;
}
int Sudoku::check_hor(int checkee, int r, int c)
{
    int flag=1;
    for(int i=0; i<MAX; i++)
    {
        if(grid[r][i]==checkee)
        {
            flag=0;
            break;
        }   
    }
    //cout<<checkee<<"hor:"<<flag<<" "<<"|";
    return flag;
}
/*blocks:
0 1 2 
3 4 5 
6 7 8 */
int Sudoku::check_block(int checkee, int r, int c)
{
    int flag=1;
    int block_row=r-r% (int)(MAX/(int)sqrt(MAX));
    int block_col=c-c% (int)(MAX/(int)sqrt(MAX));
    for(int i=block_row; i<(block_row+(int)(MAX/sqrt(MAX))); i++)
    {
        for(int j=block_col; j<(block_col+(int)(MAX/sqrt(MAX))); j++)
        {
           // cout<<"badr"<<i<<"badc"<<j<<"|";
             if(grid[i][j]==checkee)
            {
                //cout<<"badr"<<i<<"badc"<<j<<endl;
                flag=0;
                break;
            }
        }
    }//cout<<endl;
    //cout<<checkee<<"blck:"<<flag<<" "<<"|";
    return flag;
}
int Sudoku::possible(int checkee, int r, int c)
{
    int flag=check_hor(checkee, r, c)&&check_vert(checkee, r, c)&& check_block(checkee, r, c);
    //cout<<checkee<<":"<<flag<<" "<<"|";
    return flag;
}
/*int unfilled_row()
{
    for(i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(grid[i][j]==0)
                return i;
        }
    }
    int x=-1;
    return x;
}
int unfilled_col()
{
    for(i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(grid[i][j]==0)
                return j;
        }
    }
    int x=-1;
    return x;
}*/

int Sudoku::solve() //modify
{
    int r=-1, c=-1;
    if(full(r, c))
    {
        display();
        return 1;
    }
    for(int i=1; i<=MAX; i++)
    {
        if(possible(i,r,c))
        {
            grid[r][c]=i;
            //display();
            if(solve())
            {
                return 1;
            } else
            {
                grid[r][c]=0;
            }
        }
    }
    return 0;
}
void Sudoku::display()
{
    cout.width(MAX*2+2);
    cout.fill('-');
    cout<<" "<<"\n";

    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(j==0)
            {
             cout<<"|";
            }
            cout<<grid[i][j];
            if((j+1)%(MAX/(int)sqrt(MAX))==0)
            {
             cout<<"|";
            } else
            {
               cout<<" ";
            }  
        }
        cout<<endl;
        if((i+1)%(int)(MAX/(int)sqrt(MAX))==0)
        {
            cout.width(MAX*2+2);
            cout.fill('-');
            cout<<" \n";
        } 
    }
    //cout<<"end"<<endl;
}
int main()
{
    Sudoku s, test; 
    s.display();
    if (!s.solve())  
        cout << "No solution exists";  
  
}
