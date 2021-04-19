
#include <bits/stdc++.h>
using namespace std;

const int N = 6;
const int M = 7;
const int n_players = 2;
char marks[n_players] = {'X', 'O'};
char grid[N][M];


void print_grid()
{
    for (int i = 0; i< n_players; i++)
    {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
    }
    cout << "\n";
    cout << "--";
    for (int i = 0; i < M; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++)
    {
        cout << "|  ";
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < M; cout << "---", i++);
        cout << "--\n";
    }
}

bool check_win()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<=M-4; j++)
            if(grid[i][j]==grid[i][j+1]&&grid[i][j]==grid[i][j+2]&&grid[i][j]==grid[i][j+3]&&grid[i][j]!='.')
                return 1;
    for(int j=0; j<M; j++)
        for(int i=0; i<=N-4; i++)
            if(grid[i][j]==grid[i+1][j]&&grid[i][j]==grid[i+2][j]&&grid[i][j]==grid[i+3][j]&&grid[i][j]!='.')
                return 1;
    for(int i=0; i<=N-4; i++)
        for(int j=0; j<=M-4; j++)
            if(grid[i][j]==grid[i+1][j+1]&&grid[i][j]==grid[i+2][j+2]&&grid[i][j]==grid[i+3][j+3]&&grid[i][j]!='.')
                return 1;
    for(int i=0; i<=N-4; i++)
        for(int j=3; j<M; j++)
            if(grid[i][j]==grid[i+1][j-1]&&grid[i][j]==grid[i+2][j-2]&&grid[i][j]==grid[i+3][j-3]&&grid[i][j]!='.')
                return 1;
    return 0;
}
bool check_tie_player(char mark)
{
    for(int i=0; i<N; i++)
        for(int j=0; j<=M-4; j++)
            if(grid[i][j]!=mark&&grid[i][j+1]!=mark&&grid[i][j+2]!=mark&&grid[i][j+3]!=mark)
                return 0;
    for(int j=0; j<M; j++)
        for(int i=0; i<=N-4; i++)
            if(grid[i][j]!=mark&&grid[i+1][j]!=mark&&grid[i+2][j]!=mark&&grid[i+3][j]!=mark)
                return 0;
    for(int i=0; i<=N-4; i++)
        for(int j=0; j<=M-4; j++)
            if(grid[i][j]!=mark&&grid[i+1][j+1]!=mark&&grid[i+2][j+2]!=mark&&grid[i+3][j+3]!=mark)
                return 0;
    for(int i=0; i<=N-4; i++)
        for(int j=3; j<M; j++)
            if(grid[i][j]!=mark&&grid[i+1][j-1]!=mark&&grid[i+2][j-2]!=mark&&grid[i+3][j-3]!=mark)
                return 0;
    return 1;
}

bool check_tie()
{
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}

bool check_empty(int i)
{
    return(grid[0][i]=='.');
}

bool check_valid_column(int i)
{
    return(i>=0&&i<7);
}

void set_cell(int i, char mark)
{
    for(int j=N-1; j>=0; j--)
        if(grid[j][i]=='.')
        {
            grid[j][i]=mark;
            break;
        }


}

void grid_clear()
{
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            grid[i][j]='.';

}

void read_input(int &i)
{
    cout << "Enter the column index: ";
    cin >> i;
    while (!check_valid_column(i) || !check_empty(i))
    {
        cout << "Enter a valid column index: ";
        cin >> i;
    }
}

void play_game()
{
    cout << "Connect Four Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true)
    {

        print_grid();

        cout << "Player " << marks[player] << " is playing now\n";
        int i;
        read_input(i);

        set_cell(i, marks[player]);

        if (check_win())
        {

            print_grid();

            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }

        if (check_tie())
        {

            print_grid();

            cout << "Woah! That's a tie!\n";
            break;
        }

        player = (player + 1) % n_players;
    }
}
int main()
{
    while (true)
    {
        grid_clear();
        play_game();
        char c;
        cout << "Play Again [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }
}
