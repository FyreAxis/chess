#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Piece
{
private:
    //Uniquely identify each piece.
    int ID;
    //Track its owner,
    string owner;
    //Whether its in play,
    bool alive;
    //and position.
    int x;
    int y;
public:
    //Some basic functions
    int getID() { return ID; }
    string getOwner() { return owner; }
    void capture() { alive = false; }
    bool isAlive() { return alive; }
    void setX(int x) { this->x = x; }
    int getX() { return x; }
    void setY(int y) { this-> y = y; }
    int getY() { return y; }

    string info() {
        string status = (isAlive()) ? "Alive" : "Captured";
        return "ID: " +
            to_string(getID()) +
            ", Owner: " +
            getOwner() +
            ", Status: " +
            status +
            " at (" + 
            to_string(getX()) +
            ", " +
            to_string(getY()) +
            ").\n";
    }
    //Our lovely constructor
    Piece(int ID, string owner, int x, int y){
        this->ID = ID;
        this->owner = owner;
        alive = true;
        this->x = x;
        this->y = y;
    }
};

class Board
{

};
int main() {
    Piece piece1(1, "White", 1, 1);
    cout << piece1.info() << "\n";
    return 0;
}