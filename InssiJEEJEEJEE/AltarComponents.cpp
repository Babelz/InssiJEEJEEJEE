#include "AltarComponents.h"


bool SwitchComponent::moonStateChanged() {
	if (changed) {
		changed = false;

		return true;
	}

	return false;
}
int SwitchComponent::getMoonStateVal() {
	return currentMoonVal;
}

SwitchComponent::SwitchComponent(GameObject* owner)
	: GameObjectComponent(owner) {

}
SwitchComponent::~SwitchComponent() {

}
void SwitchComponent::update(sf::Time& tpf)
{
	if (moonComponent != 0) {
		currentMoonVal = moonComponent->getMoonState();
		
		if (currentMoonVal != lastMoonVal) {
			changed = true;
		}
	}

	lastMoonVal = currentMoonVal;
}
void SwitchComponent::draw(sf::RenderWindow& win) {

}

void SwitchComponent::interactWith(GameObject* gobject) {
	SoulComponent* souls = (SoulComponent*)gobject->getComponent<SoulComponent>();
	assert(souls != NULL);

	MoonComponent* moon = (MoonComponent*)gobject->getComponent<MoonComponent>();
	assert(moon != NULL);

	moonComponent = moon;

	if (souls->getSouls() > 0)
	{
		souls->setSouls(souls->getSouls() - 1);
	
		MoonComponent* moon = (MoonComponent*)gobject->getComponent<MoonComponent>();
		assert(moon != NULL);
	
		moon->setMoonState(moon->getMoonState() + 2);
		if (moon->getMoonState() > 645)
		{
			moon->setMoonState(8);
		}
	}
}
//master purkka
//if (moonp != NULL)
//{
//
//	int moonPosition = moonp->getMoonState();
//	if (sf::milliseconds(25) < tpf)
//	{
//		if (moonPosition != 8 && moonPosition != 90 && moonPosition != 170 && moonPosition != 250 && moonPosition != 330 && moonPosition != 410 && moonPosition != 490 && moonPosition != 570 && moonPosition != 645)
//		{
//			moonp->setMoonState(moonPosition + 1);
//		}
//	}
//}