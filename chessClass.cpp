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
        {
            returnToStart() ;
        }
       bool isOccupied(Position pos) ;
       std::optional<bool> getPos(const Position &pos)
         {
           return m_board.getPos(pos) ;
         }
       void isPosValid(Position pos) ;
       void takePiece(Position pos) ;
       void returnToStart() ;
       void makeMove(const Position &pieceToMove,const Position &moveToPos)
       void checkTime() ;
   private:
       ChessBoard m_board{} ;
       size_t m_numberOfTurns{} ;
       bool m_playerTurn{} ;
} ;
void checkTime() {


}
bool Chess::isOccupied(Position pos) {
  if(!isPosValid(pos) )  throw std::invalid_argument("Invalid inputed position") ;
  if(*m_board)[pos.first][pos.second]) return true ;
  else return false ;
}

bool Chess::isPosValid() {
   if(pos.first>7 || pos.second>7 || pos.second<0 || pos.first<0) return false ;
   return true ;
}

void Chess::takePiece(Position pos) {
    if(!isPosValid(pos) ) throw std::invalid_argument("Invalid inputed position") ;
    if((*m_board)[pos.first][pos.second])
} ;

void Chess::makeMove() {
   typedef(auto) refToPiece=m_board.getPos(pieceToMove) ;

           if(!reToPiece) throw std::invalid_argument("There is no piece to move\n") ;
           if(refToPiece->first!=m_playerTurn) throw std::invalid_argument("This is not your piece\n") ;

           (refToPiece->second).movePiece(moveToPos) ;

           m_board.getPos(pieceToMove)
           m_numberOfTurns++ ;
           m_playerTurn=!m_playerTurn ;

}

void Chess::returnToStart() {

        m_board.clear() ;
       (*m_board)[0][0]=std::make_pair(0,Rook) ;
       (*m_board)[0][1]=std::make_pair(0,Knight) ;
       (*m_board)[0][2]=std::make_pair(0,Bishop) ;
       (*m_board)[0][3]=std::make_pair(0,King) ;
       (*m_board)[0][4]=std::make_pair(0,Queen) ;(*m_board)
       (*m_board)[0][5]=std::make_pair(0,Bishop) ;
       (*m_board)[0][6]=std::make_pair(0,Knight) ;
       (*m_board)[0][7]=std::make_pair(0,Rook) ;

        for(int i{} ; i!=7 ; ++i)
               (*m_board)[i][1]=std::make_pair(0,Pawn) ;


       (*m_board)[7][0]=std::make_pair(1,Rook) ;
       (*m_board)[7][1]=std::make_pair(1,Knight) ;
       (*m_board)[7][2]=std::make_pair(1,Bishop) ;
       (*m_board)[7][3]=std::make_pair(1,King) ;
       (*m_board)[7][4]=std::make_pair(1,Queen) ;
       (*m_board)[7][5]=std::make_pair(1,Bishop) ;
       (*m_board)[7][6]=std::make_pair(1,Knight) ;
       (*m_board)[7][7]=std::make_pair(1,Rook) ;

        for(int i{} ; i!=7 ; ++i)
               (*m_board)[i][6]=std::make_pair(1,Pawn) ;


}

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
   void movePiece(Position current,Position toMove,bool isWhite) {
       if(!isPosValid(current) || !isPosValid(toMove) ) throw std::invalid_argument("Invalid position") ;
       if(isWhite) {
          if(toMove.first-current.first==1 || toMove.second-current.second==1  && isOccupied(toMove) )
          if(toMove.first-current.first!=1 || isOccupied(toMove) ) throw std::invalid_argument("You can't make this move.") ;

       }
   }
};

class Knight : public chessPiece {


} ;

class Bishop : public chessPiece {


} ;

class Rook : public chessPiece {


} ;
class Queen : public chessPiece {


} ;
class King : public chessPiece {


} ;
