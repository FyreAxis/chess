#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Piece {
    private:
    //Uniquely identify each piece by its starting index
    int ID;
    //See its color,
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
    bool capture() {
        //returns whether or not a capture happened
        bool captured = isInPlay();
        inPlay = false;
        return captured;
    } //TODO: logic in Board for graveyard and if can capture
    void promote(string type) { this->type = type; }
    void move() {
        
    }
    //Our lovely constructor
    Piece(int ID, string color, string type) {
        this->ID = ID;
        this->color = color;
        this->type = type;
        inPlay = true;
    }
};
class Board {
    private:
    //8x8 Chess board, Rows & Cols are labeled 1 thru 8
    vector<unique_ptr<Piece>> chessBoard;
    //Pieces go here when they are captured
    vector<unique_ptr<Piece>> graveyard;
    static inline int toIdx(int row, int col) { return (row - 1) * 8 + (col - 1); }
    static bool validSpace(const vector<unique_ptr<Piece>> &grid, int row, int col) {
        bool validRow = row >= 1 && row <= 8;
        bool validCol = col >= 1 && col <= 8;
        int idx = toIdx(row, col);
        bool validIdx = idx >= 0 && idx < grid.size();
        return validRow && validCol && validIdx;
    }
    public:
    Board() {
        //Populate empty vectors
        for (int i = 0; i < 64; i++) { chessBoard.push_back(nullptr); }
        for (int i = 0; i < 32; i++) { graveyard.push_back(nullptr); }
        for (int i = 1; i <= 16; i++) {
            setPiece(chessBoard, make_unique<Piece>(i, "White", "Pawn"));
        }
        
        //TODO: rest of pieces
    }
    string info(vector<unique_ptr<Piece>> &grid, int row, int col) {
        Piece* pPiece = getPiece(grid, row, col);
        string intro = "The space (" + to_string(row) + ", " + to_string(col) + ") is ";
        if (pPiece == nullptr) { return intro + "empty.\n"; } 
        string status = pPiece->isInPlay() ? "an alive " : "a captured ";
        return intro +
            status +
            pPiece->getColor() +
            " " +
            pPiece->getType() +
            ". ID: " +
            to_string(pPiece->getID()) +
            ".\n";
    }
    void doToEach(vector<unique_ptr<Piece>> &grid){
        for (int i = 0; i < grid.size(); i++) {
            
        }
    }
    
    Piece* getPiece(vector<unique_ptr<Piece>> &grid, int row, int col) {
        return validSpace(grid, row, col) ? grid[toIdx(row, col)].get() : nullptr;
    }
    void setPiece(vector<unique_ptr<Piece>> &grid, unique_ptr<Piece> pPiece) {
        grid[pPiece->getID() - 1] = std::move(pPiece);
    }
    void setPiece(vector<unique_ptr<Piece>> &grid, unique_ptr<Piece> pPiece, int row, int col) {
        if (validSpace(grid, row, col)) {
            grid[toIdx(row, col)] = std::move(pPiece);
        }
    }
    void capture() {
        //capture and move to gy
    }
    void reset() {
        //for (auto space : chessBoard) { delete }
    }
    void test(int row, int col) { cout << info(chessBoard, row, col); }
};
int main() {
    Board board1;
    
    board1.test(1, 1);
    board1.test(3, 8);

    return 0;
}
