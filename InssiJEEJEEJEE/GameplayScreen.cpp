#include "GameObject.h"
#include "GameplayScreen.h"
#include "BoxRendererComponent.h"
#include "InputMovementComponent.h"
#include "InssiMath.h"
b2Body* createPlayerBody(float x, float y, b2World& world);
b2Body* createTile(float x, float y, b2World& world);
GameplayScreen::GameplayScreen() {
	sf::Texture box;
	if (!box.loadFromFile("box.png"))
		return;


	GameObject* player = new GameObject();
	camera = new Camera(player, world, 1280, 720);
	player->body = createPlayerBody(0, 720 / 2, world.world);
	player->addComponent(new BoxRendererComponent(player, box));
	player->addComponent(new InputMovementComponent(player));
	player->addComponent(camera);
	world.addGameObject(player);

	player->body->SetLinearVelocity(b2Vec2(500, 0));
	GameObject* player2 = new GameObject();
	player2->body = createTile(100, 720 / 2, world.world);
	player2->addComponent(new BoxRendererComponent(player2, box));
	world.addGameObject(player2);

}

b2Body* createPlayerBody(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32.f / 2.f), Convert::worldToBox2d(32.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.1f;
	FixtureDef.friction = 0.01f;
	//FixtureDef.restitution = 0.f;
	
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);
	return body;
}

b2Body* createTile(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_staticBody;
	b2Body* body = world.CreateBody(&BodyDef);
	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32.f / 2.f), Convert::worldToBox2d(32.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);
	return body;
}

GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::update(sf::Time& tpf) {
	world.update(tpf);
}

void GameplayScreen::draw(sf::RenderWindow& window) {
	window.clear(sf::Color::Green);
	sf::View view = window.getDefaultView();
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	view.reset(sf::FloatRect(camera->getPosition().x, camera->getPosition().y, camera->width, camera->height));
	window.setView(view);
	
	/*int xPixels = (camera->getViewport().width + camera->getPosition().x) / 32.f;
	int yPixels = (camera->getViewport().height + camera->getPosition().y) / 32.f;
	
	int fromX = std::max(0, (int)camera->getPosition().x / 32 - 1);
	
	int fromY = std::max(0, (int)camera->getPosition().y / 32 - 1);
	
	int toX = std::min(xPixels + 1, world.getActiveMap()->getWidth());
	
	int toY = std::min(yPixels + 1, world.getActiveMap()->getHeight());*/
	
	world.draw(window, 0, 0, 0, 0);
	
	window.display();
}

void GameplayScreen::activate() {

}
int GameplayScreen::pollEvent(sf::Event &event) {
	return 0;
}
