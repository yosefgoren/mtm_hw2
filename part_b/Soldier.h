#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"

namespace mtm{
    class Soldier : public Character{
        virtual char getSymbol() const noexcept override{
            return 'S';
        }
        static Soldier* makeSoldier(){
            return new Soldier();
        }
        virtual Character* clone() const override{
            return new Soldier();
        }
    };
}

#endif