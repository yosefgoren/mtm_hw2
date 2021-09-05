#ifndef MEDIC_H
#define MEDIC_H
#include "Character.h"

namespace mtm{
    class Medic : public Character{
    public:
        Medic(Team team, units_t health, units_t ammo, units_t range, units_t power);
        ~Medic() = default;
        virtual char getSymbol() const noexcept override;
        virtual Character* clone() const override;
        virtual int maxMoveDistance() const noexcept override;
        virtual std::vector<GridPoint> coordinatesAffectedByAttack(const GridPoint& src_point,
                TileItem& target) const override;
        virtual void executeAttack(std::vector<TileItem*> targeted_tiles,
                const GridPoint& target_point) noexcept override;
    };
}

#endif