#include <iostream>
#include <optional>
#include <unique_ptr>
#include <excetpions>
#include <array>
#include <pair>
#include <cstddef>

typedef std::pair<bool,chessPieceType> ColorAndPiece ;
typedef std::pair<size_t,size_t> Position ;

class ChessBoard {
  public:
      ChessBoard() : m_board(std::make_unique<std::array<std::array<std::optional<ColorAndPiece>,8>,8> > () )
                    { }
      std::optional<ColorAndPiece>& getPos(const Position &pos) {
          if(pos.first>7 || pos.second>7) throw std::invalid_argument("Invalid range\n") ;
          else return (*m_board)[pos.first][pos.second] ;
        }

  private:
      unique_ptr<std::array<std::array<std::optional<ColorAndPiece>,8>,8> > m_board ;
} ;

class Chess {

   public:
       Chess(bool whoGoFirst=0) : m_playerTurn(whoGoFirst)
                                    { }
       std::optional<bool> getPos(const Position &pos) {
           return m_board.getPos(pos) ;
         }

       void makeMove(const Position &pieceToMove,const Position &moveToPos) {

           typedef(auto) refToPiece=m_board.getPos(pieceToMove) ;

           if(!reToPiece) throw std::invalid_argument("There is no piece to move\n") ;
           if(refToPiece->first!=m_playerTurn) throw std::invalid_argument("This is not your piece\n") ;

           (refToPiece->second).movePiece(moveToPos) ;

           m_board.getPos(pieceToMove)
           m_numberOfTurns++ ;
           m_playerTurn=!m_playerTurn ;
       }

   private:
   ChessBoard m_board{} ;
   size_t m_numberOfTurns{} ;
   bool m_playerTurn{} ;
} ;


enum class chessPieceType {
  Pawn,
  Knight,
  Bishop,
  Rook,
  Queen,
  King
} ;

class ChessPiece {

   ChessPiece(PieceType type,bool player) : m_type(type),isWhite(player) {}
   chessPieceType getType() const {
       return m_type ;
       }

   bool getColor() const {
       return isWhite ;
       }

   virutal void movePiece()=0 ;

   private:
       chessPieceType m_type ;
       bool isWhite ;
} ;

class Pawn : public chessPiece {
  public:
  void movePiece override() {
      if(pos1>7 || pos2>7) return ;

  }
};

class Knight : public chessPiece {


} ;
