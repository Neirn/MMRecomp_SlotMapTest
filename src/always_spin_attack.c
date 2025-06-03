#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "recompdata.h"

typedef struct {
    unsigned a;
} TestStruct;

// Patches a function in the base game that's used to check if the player should quickspin.
RECOMP_PATCH s32 Player_CanSpinAttack(Player* this) {
    recomp_printf("TESTING MEMORY SLOTMAP\n");
    MemorySlotmapHandle h = recomputil_create_memory_slotmap(sizeof(TestStruct));
    recomp_printf("MEMORY SLOTMAP CREATED\n");

    collection_key_t key = recomputil_memory_slotmap_create(h); // <--- CRASHES ON THIS LINE
    recomp_printf("MEMORY SLOTMAP NEW ELEMENT ADDED\n");

    recomputil_destroy_memory_slotmap(h);
    recomp_printf("MEMORY SLOTMAP DESTROYED\n");

    recomp_printf("MEMORY SLOTMAP SUCCESS\n");

    // Always spin attack.
    return true;
}


