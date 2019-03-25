#include "stdafx.h"
#include "modinfo.h"
#include "utility.h"
#include <iostream>
#include <map>

// Custom Events
// - Create events you want to hook into the game here
// - To find out when events are called, please check the Event enum.
void OnPickupFoliageTest() {
	log("Foliage Picked up!");
}

void OnPreInitialize() {
	log("Mod Pre initialized!");
}


// Utility
// - Register events you want to hook into the game here
EXTERN_DLL_EXPORT extern std::map<Event, FUNC> functions = {
	{ Event::OnPickupFoliage, OnPickupFoliageTest },
	{ Event::OnPreInit, OnPreInitialize }
};

// Don't edit
EXTERN_DLL_EXPORT FUNC GetTickEvent(Event event) {
	auto iterator = functions.find(event);
	if (iterator != functions.end()) {
		return (*iterator).second;
	}
	return NULL;
}