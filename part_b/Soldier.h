#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"

namespace mtm{
    class Soldier : public Character{
    public:
        Soldier(Team team, units_t health, units_t ammo, units_t range, units_t power);
        ~Soldier() = default;
        virtual char getSymbol() const noexcept override;
        virtual Character* clone() const override;
        virtual int maxMoveDistance() const noexcept override;
        virtual bool targetIsLegal(const GridPoint& attacking_position, const TileItem& tile) const override;
        virtual std::vector<GridPoint> coordinatesAffectedByAttack(const GridPoint& src_point, 
                TileItem& target) const override;
        virtual void executeAttack(std::vector<TileItem*> targeted_tiles,
                const GridPoint& target_point) noexcept override;
        virtual void reload() noexcept override;
    };
}

#endif