#ifndef GAME_H
#define GAME_H
#include <vector>
#include <memory>
#include <string>
#include "Cell.h"
#include "Player.h"
#include "Link.h"
#include "Subject.h"
#include "Board.h"

using namespace std;

// NOTE: abilityIndex is the ability number, not index. Change the name later

class Game : public Subject {
    shared_ptr<Board> board;
    vector<shared_ptr<Player>> players;
    vector<Cell*> trappedCells;
    const int playerCount;
    int activePlayers;
    int currentTurn = 1;
    bool gameOver = false;
    int playerWon = 0;
    bool graphicsEnabled;
    public:
    Game(int playerCount, const vector<string> &linkOrders, const vector<string> &abilities, bool graphicsEnabled);
    void move(char link, const string &direction);
    void displayAbilities(bool multipleDisplay) const;
    void displayErr(const string &err, bool multipleDisplay) const;
    string getAbilityName(int index);
    void useAbility(int abilityNumber, int row, int col, const string &abilityName);
    void useAbility(int abilityNumber, int r1, int c1, int r2, int c2);
    void useAbility(int abilityNumber, const string &abilityName, char link);
    void useFirewall(int row, int col);
    void useDownload(char link);
    void useLinkBoost(char link);
    void usePolarise(char link);
    void useScan(char link);
    void useTrojan(char link);
    void useWarp(int r1, int c1, int r2, int c2);
    void useImprison(int row, int col);
    void battle(shared_ptr<Link> currLink, shared_ptr<Link> opponentLink, int opponentIndex, Cell &cell);
    void checkGameOver();
    void displayGameOver();
    bool validOutOfBounds(int row, int col) const;
    bool isActive(int playeri) const;
    const shared_ptr<Player>& getPlayer(int playerNumber) const;
    shared_ptr<Board> getBoard() const;
    int getCurrentTurn() const;
    int getPlayerCount() const;
    bool getIsGameOver() const;
    int getPlayerWon() const;
};


#endif
