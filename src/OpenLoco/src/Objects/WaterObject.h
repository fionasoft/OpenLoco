#pragma once

#include "Object.h"
#include "Types.hpp"
#include <span>

namespace OpenLoco
{
    namespace ObjectManager
    {
        struct DependentObjects;
    }
    namespace Gfx
    {
        class DrawingContext;
    }

#pragma pack(push, 1)
    struct WaterObject
    {
        static constexpr auto kObjectType = ObjectType::water;

        StringId name;
        uint8_t costIndex; // 0x02
        uint8_t var_03;
        int16_t costFactor;     // 0x04
        uint32_t image;         // 0x06
        uint32_t mapPixelImage; // 0x0A

        bool validate() const;
        void load(const LoadedObjectHandle& handle, std::span<const std::byte> data, ObjectManager::DependentObjects*);
        void unload();
        void drawPreviewImage(Gfx::DrawingContext& drawingCtx, const int16_t x, const int16_t y) const;
    };
#pragma pack(pop)
    static_assert(sizeof(WaterObject) == 0xE);

    namespace Water::ImageIds
    {
        static constexpr uint32_t kColourPalette = 41;
        static constexpr uint32_t kToolbarTerraformWater = 42;
    }
}
