#include "GameplayScreen.h"

class FollowState;


#include "BoxRendererComponent.h"
#include "InputMovementComponent.h"
#include "MouseMovementComponent.h"
#include "HealthComponent.h"
#include "Hud.h"
#include "InssiMath.h"
#include "Game.h"
#include "PlayerComponents.h"

b2Body* createPlayerBody(float x, float y, b2World& world);
b2Body* createTile(float x, float y, b2World& world);
//b2Body* createMonsterBody(float x, float y, b2World& world);
void attachBody(GameObject* owner, b2Body* body);

GameplayScreen::GameplayScreen(Game* game) : GameState(game) {
	sf::Texture box;
	if (!box.loadFromFile("box.png"))
		return;

	sound_manager.initialiseSound();
	game->getWindow().setMouseCursorVisible(true);
	GameObject* player = new GameObject();
	attachBody(player, createPlayerBody(64.f * 79, 0.f, *world.getBoxWorld()));
	camera = new Camera(player, world, 1280, 720, world.getActiveMap()->getTileWidth(), world.getActiveMap()->getTileHeight());
	player->addComponent(camera);
	player->addComponent(new BoxRendererComponent(player, box));
	player->addComponent(new InputMovementComponent(player));
	player->addComponent(new MouseMovementComponent(player, camera, world, game->getWindow()));
	player->addComponent(new HealthComponent(player, 100));
	player->addComponent(new SoulComponent(player));
	player->addComponent(new MoonComponent(player));
	player->addComponent(new Hud(player, sf::Vector2f(1280.f, 720.f), camera));

	world.addGameObject(player);
	world.setPlayer(player);

	monsterGenerator = new MonsterGenerator(world, sound_manager);
	
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

void attachBody(GameObject* owner, b2Body* body) {
	owner->body = body;
	body->SetUserData(owner);
}

b2Body* createTile(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_staticBody;

	b2Body* body = world.CreateBody(&BodyDef);
	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(64.f / 2.f), Convert::worldToBox2d(64.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;

	body->CreateFixture(&FixtureDef);
	return body;
}

GameplayScreen::~GameplayScreen()
{
	delete monsterGenerator;
	monsterGenerator = NULL;
}

void GameplayScreen::update(sf::Time& tpf) {
	
	world.update(tpf);
	//monsterGenerator->spawnMonsters();
}

void GameplayScreen::draw(sf::RenderWindow& window) {
	window.clear(sf::Color::Green);
	sf::View view = window.getDefaultView();
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	view.reset(sf::FloatRect(camera->getPosition().x, camera->getPosition().y, camera->getWidth(), camera->getHeight()));
	window.setView(view);
	
	int xPixels = (camera->getWidth()+ camera->getPosition().x) / world.getActiveMap()->getTileWidth();
	int yPixels = (camera->getHeight() + camera->getPosition().y) / world.getActiveMap()->getTileHeight();
	
	int fromX = std::max(0, (int)camera->getPosition().x / world.getActiveMap()->getTileWidth() - 1);
	
	int fromY = std::max(0, (int)camera->getPosition().y / world.getActiveMap()->getTileHeight() - 1);
	
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
