#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Piece {
    private:
    //Uniquely identify each piece by its starting index
    int ID;
    //Track its color,
    string color;
    //What the piece is,
    string type;
    //and whether it's in play.
    bool inPlay;

    public:
    //Some basic functions
    int getID() { return ID; }
    string getColor() { return color; }
    string getType() { return type; }
    bool isInPlay() { return inPlay; }
    void capture() { inPlay = false; } //TODO: also move to graveyard

    //Our lovely constructor
    Piece(int IDnum, string color, string type) {
        this->ID = ID;
        this->color = color;
        this->type = type;
        inPlay = true;
    }
};
class Grid { }; //TODO: convert the two boards into grids
class Board {
    private:
    //8x8 Chess board, Rows & Cols are labeled 1 thru 8
    Piece* chessBoard[64];
    //Pieces go here when they are captured
    Piece* graveyard[32];
    static inline int toIdx(int row, int col) { return row * col - 1; }
    static bool validSpace(int row, int col) {
        bool validRow = (row >= 1 && row <= 8) ? true : false;
        bool validCol = (col >= 1 && col <= 8) ? true : false;
        int idx = toIdx(row, col);
        bool validIdx = (idx >= 0 && idx <= 63) ? true : false;
        return validRow && validCol && validIdx;
    }
    void setUp() {
        //for (int i = 0; i < chessBoard.size(); i++) { chessBoard[i] = nullptr; } //TODO: fix this chessBoard.size() error
        Piece piece1(1, "White", "Pawn");
        chessBoard[0] = &piece1;
        //TODO: rest of pieces
    }
    public:
    Board() {
        this->setUp();
    }
    string info(int row, int col) {
        Piece* pPiece = getPiece(row, col);
        string intro = "The space (" + to_string(row) + ", " + to_string(col) + ") is ";
        if (pPiece == nullptr) { return intro + "empty.\n"; } 
        string status = (pPiece->isInPlay()) ? "an alive " : "a captured ";
        return intro +
            status +
            pPiece->getColor() +
            " " +
            pPiece->getType() +
            ". ID: " +
            to_string(pPiece->getID()) +
            ".\n";
    }
    Piece* getPiece(int row, int col) {
        return validSpace(row, col) ? chessBoard[toIdx(row, col)] : nullptr;
    }
    void setPiece(Piece* piece, int row, int col) {
        if (validSpace(row, col)) { chessBoard[toIdx(row, col)] = piece; }
    }
    void reset() {
        //for (auto space : chessBoard) { delete }
    }
};
int main() {
    Board board1;
    cout << board1.info(1, 1) << "\n";

    return 0;
}