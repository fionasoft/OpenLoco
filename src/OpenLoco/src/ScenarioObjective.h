#pragma once
#include <OpenLoco/Core/EnumFlags.hpp>
#include <cstdint>

namespace OpenLoco::Scenario
{
    enum class ObjectiveFlags : uint8_t
    {
        none = 0U,
        beTopCompany = (1U << 0),
        beWithinTopThreeCompanies = (1U << 1),
        withinTimeLimit = (1U << 2),
        flag_3 = (1U << 3),
        flag_4 = (1U << 4),
    };
    OPENLOCO_ENABLE_ENUM_OPERATORS(ObjectiveFlags);

    enum class ObjectiveType : uint8_t
    {
        companyValue,
        vehicleProfit,
        performanceIndex,
        cargoDelivery,
    };

#pragma pack(push, 1)
    struct Objective
    {
        ObjectiveType type;            // 0x000418 (0x00526230)
        ObjectiveFlags flags;          // 0x000419 (0x00526231)
        uint32_t companyValue;         // 0x00041A (0x00526232)
        uint32_t monthlyVehicleProfit; // 0x00041E (0x00526236)
        uint8_t performanceIndex;      // 0x000422 (0x0052623A)
        uint8_t deliveredCargoType;    // 0x000423 (0x0052623B)
        uint32_t deliveredCargoAmount; // 0x000424 (0x0052623C)
        uint8_t timeLimitYears;        // 0x000428 (0x00526240)
    };
#pragma pack(pop)
    static_assert(sizeof(Objective) == 0x11);
    Objective& getObjective();

#pragma pack(push, 1)
    struct ObjectiveProgress
    {
        uint16_t timeLimitUntilYear;         // 0x000429 (0x00526241)
        uint16_t monthsInChallenge;          // 0x00042B (0x00526243)
        uint16_t completedChallengeInMonths; // 0x00042D (0x00526245)
    };
#pragma pack(pop)
    static_assert(sizeof(ObjectiveProgress) == 0x6);
    ObjectiveProgress& getObjectiveProgress();
}
