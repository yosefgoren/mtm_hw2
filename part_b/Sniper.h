#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"

namespace mtm{
    class Sniper : public Character{
    public:
        Sniper(Team team, units_t health, units_t ammo, units_t range, units_t power);
        ~Sniper() = default;
        virtual char getSymbol() const noexcept override;
        virtual Character* clone() const override;
        virtual int maxMoveDistance() const noexcept override;
        virtual bool inAttackRange(const GridPoint& src_point, const GridPoint& dst_point)
                const noexcept override;
        virtual bool canAttackTile(TileItem& other) const noexcept override;
        
    };
}

#endif