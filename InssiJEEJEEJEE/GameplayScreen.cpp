#include "GameObject.h"
#include "GameplayScreen.h"
#include "BoxRendererComponent.h"
#include "InputMovementComponent.h"
#include "MouseMovementComponent.h"
#include "HealthComponent.h"

#include "InssiMath.h"
#include "Game.h"
b2Body* createPlayerBody(float x, float y, b2World& world);
b2Body* createTile(float x, float y, b2World& world);
b2Body* createMonsterBody(float x, float y, b2World& world);

GameplayScreen::GameplayScreen(Game* game) : State(game) {
	sf::Texture box, gfxMonster1, gfxMonster2;
	if (!box.loadFromFile("box.png") || !gfxMonster1.loadFromFile("monster1.png") || !gfxMonster2.loadFromFile("monster2.png"))
		return;

	sf::Mouse::setPosition(sf::Vector2i(1280 / 2, 720 / 2), game->getWindow());
	game->getWindow().setMouseCursorVisible(true);
	GameObject* player = new GameObject();
	camera = new Camera(player, world, 1280, 720);
	player->body = createPlayerBody(0, 720 / 2, world.world);
	player->addComponent(new BoxRendererComponent(player, box));
	player->addComponent(new InputMovementComponent(player));
	player->addComponent(new MouseMovementComponent(player, camera, game->getWindow()));
	player->addComponent(camera);
	player->addComponent(new HealthComponent(player, 100));
	world.addGameObject(player);

	player->body->SetLinearVelocity(b2Vec2(500, 0));
	GameObject* player2 = new GameObject();
	player2->body = createTile(100, 720 / 2, world.world);
	player2->addComponent(new BoxRendererComponent(player2, box));
	world.addGameObject(player2);

	GameObject* monster1 = new GameObject();
	monster1->body = createMonsterBody(100, 100, world.world);
	monster1->addComponent(new BoxRendererComponent(monster1, gfxMonster1));
	monster1->addComponent(new HealthComponent(monster1, 100));
	world.addGameObject(monster1);

	GameObject* monster2 = new GameObject();
	monster2->body = createMonsterBody(500, 500, world.world);
	monster2->addComponent(new BoxRendererComponent(monster2, gfxMonster2));
	monster2->addComponent(new HealthComponent(monster2, 100));
	world.addGameObject(monster2);
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

b2Body* createMonsterBody(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	// TODO siirrä collider alas
	Shape.SetAsBox(Convert::worldToBox2d(32 / 2.f), Convert::worldToBox2d(48.f / 2.f));
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
	
	int xPixels = (camera->getViewport().width + camera->getPosition().x) / 32.f;
	int yPixels = (camera->getViewport().height + camera->getPosition().y) / 32.f;
	
	int fromX = std::max(0, (int)camera->getPosition().x / 32 - 1);
	
	int fromY = std::max(0, (int)camera->getPosition().y / 32 - 1);
	
	int toX = std::min(xPixels + 1, world.getActiveMap()->getWidth());
	
	int toY = std::min(yPixels + 1, world.getActiveMap()->getHeight());
	
	world.draw(window, fromX, toX, fromY, toY);
	
	/*
	sf::View minimapView;
	minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	window.setView(minimapView);
<<<<<<< HEAD
	world.draw(window, fromX, toX, fromY, toY);*/
	
	window.display();
}

void GameplayScreen::activate() {

}
int GameplayScreen::pollEvent(sf::Event &event) {
	return 0;
}
