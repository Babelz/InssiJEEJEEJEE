#include "BoxRendererComponent.h"
#include "InssiMath.h"

BoxRendererComponent::BoxRendererComponent(GameObject* owner, sf::Texture &texture) 
	: GameObjectComponent(owner), texture(texture)
{
}


BoxRendererComponent::~BoxRendererComponent()
{
}

void BoxRendererComponent::update(sf::Time& tpf) {

}

void BoxRendererComponent::draw(sf::RenderWindow& window) {
	float originX = texture.getSize().x / 2.0f;
	float originY = texture.getSize().y / 2.0f;
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(originX, originY);
	sprite.setPosition(
		Convert::box2dToWorld(getOwner()->body->GetPosition().x) + originX,
		Convert::box2dToWorld(getOwner()->body->GetPosition().y) + originY);
	sprite.setRotation(getOwner()->body->GetAngle() * 180 / b2_pi);
	window.draw(sprite);
}