#pragma once

#include "Graphics/Gfx.h"
#include "Location.hpp"
#include <OpenLoco/Core/EnumFlags.hpp>
#include <OpenLoco/Engine/World.hpp>
#include <optional>

using namespace OpenLoco::World;

namespace OpenLoco::Paint
{
    struct PaintStruct;
}

namespace OpenLoco::Ui
{
    struct Viewport;
    struct Window;
}

namespace OpenLoco::Ui::ViewportInteraction
{
    enum class InteractionItem : uint8_t
    {
        noInteraction = 0,
        surface = 1,
        industryTree = 2,
        entity = 3,
        track = 4,
        trackExtra = 5,
        signal = 6,
        trainStation = 7,
        roadStation = 8,
        airport = 9,
        dock = 10,
        water = 11,
        tree = 12,
        wall = 13,
        townLabel = 14,
        stationLabel = 15,
        road = 16,
        roadExtra = 17,
        bridge = 18,
        building = 19,
        industry = 20,
        headquarterBuilding = 21,
        buildingInfo = 22,
    };

    enum class InteractionItemFlags : uint32_t // Bridge missing?
    {
        none = 0U,
        surface = (1U << 0),
        entity = (1U << 1),
        track = (1U << 2),
        water = (1U << 3),
        tree = (1U << 4),
        roadAndTram = (1U << 5),
        roadAndTramExtra = (1U << 6),
        signal = (1U << 7),
        wall = (1U << 8),
        headquarterBuilding = (1U << 9),
        station = (1U << 11),
        townLabel = (1U << 12),
        stationLabel = (1U << 13),
        trackExtra = (1U << 14),
        building = (1U << 15),
        industry = (1U << 16),
    };
    OPENLOCO_ENABLE_ENUM_OPERATORS(InteractionItemFlags);

    struct InteractionArg
    {
        World::Pos2 pos;
        union
        {
            uint32_t value;
            void* object;
        };
        InteractionItem type;
        uint8_t modId; // used for track mods and to indicate left/right signals
        InteractionArg() = default;
        constexpr InteractionArg(const World::Pos2& _pos, uint32_t _value, InteractionItem _type, uint8_t _unkBh)
            : pos(_pos)
            , value(_value)
            , type(_type)
            , modId(_unkBh)
        {
        }
        InteractionArg(const Paint::PaintStruct& ps);
    };

    static constexpr auto kNoInteractionArg = InteractionArg({ 0, 0 }, 0, InteractionItem::noInteraction, 0);

    InteractionArg getItemLeft(int16_t tempX, int16_t tempY);
    InteractionArg rightOver(int16_t x, int16_t y);

    void handleRightReleased(Window* window, int16_t xPos, int16_t yPos);

    std::pair<ViewportInteraction::InteractionArg, Ui::Viewport*> getMapCoordinatesFromPos(int32_t screenX, int32_t screenY, InteractionItemFlags flags);
    std::optional<World::Pos2> getSurfaceOrWaterLocFromUi(const Point& screenCoords);
    std::optional<std::pair<World::Pos2, Ui::Viewport*>> getSurfaceLocFromUi(const Point& screenCoords);
}
