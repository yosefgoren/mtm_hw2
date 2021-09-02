#ifndef CHARACTER_H
#define CHARACTER_H

namespace mtm{
    class Character{
        public:
        virtual Character* clone() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Character& character);
        private:
        virtual char getSymbol() const noexcept = 0;
    };
    std::ostream& operator<<(std::ostream& os, const Character& character){
        os << character.getSymbol();
        return os;
    }
}


#endif