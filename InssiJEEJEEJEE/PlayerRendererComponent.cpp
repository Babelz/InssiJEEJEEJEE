#include "PlayerRendererComponent.h"
#include "InssiMath.h"

PlayerRendererComponent::PlayerRendererComponent(GameObject* owner, sf::Texture& texture) 
	: GameObjectComponent(owner), texture(texture)
{
}


PlayerRendererComponent::~PlayerRendererComponent()
{
}

void PlayerRendererComponent::update(sf::Time& tpf) {

}
void PlayerRendererComponent::draw(sf::RenderWindow& window) {

	sf::Vector2u size = texture.getSize();
	sf::Vector2f scale(32.f / size.x, 48.f / size.y);
	sf::Sprite sprite;
	sprite.setScale(scale);
	sprite.setTexture(texture);

	sprite.setPosition(
		Convert::box2dToWorld(getOwner()->body->GetPosition().x) + 16.f, //+ originX *2.f,
		Convert::box2dToWorld(getOwner()->body->GetPosition().y) + 16.f);// + originY*2.f);
	//sprite.setRotation(getOwner()->body->GetAngle() * 180 / b2_pi);

	window.draw(sprite);
}