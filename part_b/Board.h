#ifndef BOARD_H
#define BOARD_H

#include "Auxiliaries.h"
#include "Exceptions.h"
#include <sstream>

namespace mtm{
    template <class T>
    /**
     * the generic type T is required to have the methods:
     *  T()
     *  ~T()
     *  T(cosnt T&)
     *  operator=(cosnt T&)
     *  std::ostream& operator<<(std::ostream& os) const -- expects output to be a single char.
     */
    class Board{
    public:
        ~Board();
        Board(const Board& other);
        /**
         * 'other' and 'this' will not effect one another after assignment.
         * (assignment 'by copy' not 'by reference').
         */
        Board& operator=(const Board& other);

    protected:
        Board(int num_rows, int num_cols, const T& default_value);
        int getWidth() const;
        bool positionWithinBoard(const GridPoint& coordiantes);

        #define CREATE_OPBR_ROWCOL(maybe_const)\
        maybe_const T& operator()(int row, int col) maybe_const{\
            return (*this)(GridPoint(row, col));\
        }
        CREATE_OPBR_ROWCOL()
        CREATE_OPBR_ROWCOL(const)
        #undef CREATE_OPBR_ROWCOL

        #define CREATE_OPBR_GRIDPOINT(maybe_const)\
        maybe_const T& operator()(const GridPoint& point) maybe_const{\
            if(!positionWithinBoard(point)){\
                throw IllegalCell();\
            }\
            return items_array[toLinearPosition(point)];\
        }
        CREATE_OPBR_GRIDPOINT()
        CREATE_OPBR_GRIDPOINT(const)
        #undef CREATE_OPBR_GRIDPOINT

        #define CREATE_OPBR_INDEX(maybe_const)\
        maybe_const T& operator()(int index) maybe_const{\
            if(index < 0 || index >= num_cols*num_rows){\
                throw IllegalCell();\
            }\
            return items_array[index];\
        }
        CREATE_OPBR_INDEX()
        CREATE_OPBR_INDEX(const)
        #undef CREATE_OPBR_INDEX

        #define CREATE_ITERATOR(iterator_name, maybe_const)\
        class iterator_name{\
        public:\
            explicit operator GridPoint() const{\
                return GridPoint(index/(board->num_cols), index%(board->num_cols));\
            }\
            maybe_const T& operator*(){\
                return board->items_array[index];\
            }\
            bool operator!=(const iterator_name& other) const{\
                return index != other.index || board != other.board;\
            }\
            iterator_name& operator++(){\
                index++;\
                return *this;\
            }\
            int index;\
            maybe_const Board* board;\
        };\
        iterator_name begin() maybe_const{\
            iterator_name it = {0, this};\
            return it;\
        }\
        iterator_name end() maybe_const{\
            iterator_name it = {num_cols*num_rows, this};\
            return it;\
        }
        CREATE_ITERATOR(iterator,)
        CREATE_ITERATOR(const_iterator, const)
        #undef CREATE_ITERATOR

    private:
        int num_rows, num_cols;
        T* items_array;

        template<class S>
        static void swapAux(S& first, S& second){
            S old_first = first;
            first = second;
            second = old_first;
        }
        /**
         * swaps all values inner data between this and other.
         */
        void swap(Board& other){
            swapAux(num_rows, other.num_rows);
            swapAux(num_cols, other.num_cols);
            swapAux(items_array, other.items_array);
        }
        /**
         * frees any resources allocated by self, accept the memory of the field themselfs.
         */
        void dealloate(){
            delete[] items_array;
        }
        int toLinearPosition(const GridPoint& coordianets){
            return coordianets.row*num_cols + coordianets.col;
        }
        template <class S>
        friend std::ostream& operator<<(std::ostream& os, const Board<S>& board);
    };

    template <class T>
    std::ostream& operator<<(std::ostream& os, const Board<T>& board){
        std::stringstream stream;
        for(const T& item : board){
            stream << item;
        }
        std::string str = stream.str();
        printGameBoard(os, str.c_str(), str.c_str() + str.size(), board.getWidth());
        return os;
    }

    template <class T>
    Board<T>::Board(int num_rows, int num_cols, const T& default_value):
            num_rows(num_rows), num_cols(num_cols), items_array(nullptr){
        if(num_rows <= 0 || num_cols <= 0){
            throw IllegalArgument();
        }
        items_array = new T[num_rows*num_cols];
        for(T& item : *this){
            item = T(default_value);
        }
    }
    template <class T>
    Board<T>::~Board(){
        dealloate();
    }
    template <class T>
    Board<T>::Board(const Board& other): num_rows(other.num_rows), num_cols(other.num_cols), items_array(nullptr){
        items_array = new T[num_rows*num_cols];
        for(Board::iterator it = this->begin(); it != this->end(); ++it){
            *it = T(other(it.index));
        }
    }
    template <class T>
    Board<T>& Board<T>::operator=(const Board& other){
        Board new_self(other);
        dealloate();
        swap(*this, new_self);
        return *this;
    }
    template <class T>
    int Board<T>::getWidth() const{
        return num_cols;
    }
    
    template <class T>
    bool Board<T>::positionWithinBoard(const GridPoint& coordiantes){
        int col = coordiantes.col, row = coordiantes.row;
        if(col < 0 || row < 0){
            return false;
        }
        return col < num_cols && row < num_rows;
    }
}
#endif