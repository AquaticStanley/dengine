#include <iostream>
#include "surfaces/fire.h"
#include "GameObject.h"
#include "status_effects/status_effects.h"

int main() {
	std::cout << "Test" << std::endl;
    GameObject object;
    effects::Burning burning;

    object.set_status(burning);
    object.trigger_status_effects();
}
