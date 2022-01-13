#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#define ALLHUMANMODE 1
#define MINALLHUM 2
#define MIXMODE 2
#define MINMIX 1

void set_goal(Game&);
void create_players(Game&);
void all_human_mode(Game&, int);
void mix_mode(Game&, int);

int main()
{
    Game game;
    set_goal(game);
    create_players(game);
    game.playGame();
    return 0;
}

void set_goal(Game& game)
{
    int goal;
    cout << "Enter a score players need to reach ( number ): ";
    cin >> goal;
    game.setPointGoal(goal);
}

void create_players(Game& game)
{
    int mode = 0;
    string name = "";

    do
    {
        cout << endl << "Choose game mode: \n1.Only humans\n2.Mixed humans and computers\nEnter your choice: ";
        cin >> mode;
    }
    while (mode < ALLHUMANMODE || mode > MIXMODE);

    if (mode == ALLHUMANMODE)
    {
        all_human_mode(game, mode);
    }
    else
    {
        mix_mode(game, mode);
    }
}

void all_human_mode(Game& game, int mode = ALLHUMANMODE)
{
    int humanCnt = 0, minPlayers = (mode == ALLHUMANMODE) ? MINALLHUM : MINMIX;
    string name = "";

    do
    {
        cout << endl << "Enter the number of players: ";
        cin >> humanCnt;
    }
    while (humanCnt < minPlayers);
    cout << endl;
    for (int i = 0; i < humanCnt; ++i)
    {
        do
        {
            cout << "Enter " << i + 1 << ".player name: ";
            cin >> name;
        }
        while (name.length() == 0);

        HumanPlayer* hPlayer = new HumanPlayer(name);
        game.addPlayer(hPlayer);
    }
    cout << endl;
}

void mix_mode(Game& game, int mode)
{
    all_human_mode(game, MIXMODE);

    int computerCnt = 0;

    do
    {
        cout << "Enter the number of computers: ";
        cin >> computerCnt;
    }
    while (computerCnt < MINMIX);

    for (int i = 0; i < computerCnt; ++i)
    {
        ComputerPlayer* cPlayer = new ComputerPlayer("Comp" + to_string(i + 1));

        game.addPlayer(cPlayer);
    }
    cout << endl;
}
