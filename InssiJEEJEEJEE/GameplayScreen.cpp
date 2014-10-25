#include "GameplayScreen.h"

class FollowState;


#include "MonsterRendererComponent.h"
#include "InputMovementComponent.h"
#include "MouseMovementComponent.h"
#include "HealthComponent.h"
#include "Hud.h"
#include "InssiMath.h"
#include "Game.h"
#include "PlayerComponents.h"
#include "AltarComponents.h"
#include "PlayerRendererComponent.h"

b2Body* createPlayerBody(float x, float y, b2World& world);
b2Body* createSusiBody(float x, float y, b2World& world);
b2Body* createTile(bool isSensor, float x, float y, b2World& world);
b2Body* createTile(float x, float y, b2World& world);
//b2Body* createMonsterBody(float x, float y, b2World& world);
void attachBody(GameObject* owner, b2Body* body);

SwitchComponent* switchComponent;

GameplayScreen::GameplayScreen(Game* game) : GameState(game) {
	sf::Texture box, gfxPlayer, gfxSusi, altar;
	if (!box.loadFromFile("alttari1.png") || !gfxPlayer.loadFromFile("player.png") || !gfxSusi.loadFromFile("susi.png") || !altar.loadFromFile("temppeli.png"))
		return;

	game->getWindow().setMouseCursorVisible(true);
	GameObject* player = new GameObject();
	attachBody(player, createPlayerBody(64.f * 40, 25 * 64.f, *world.getBoxWorld()));
	camera = new Camera(player, world, 1280, 720, world.getActiveMap()->getTileWidth(), world.getActiveMap()->getTileHeight());

	GameObject* alttari = new GameObject();
	attachBody(alttari, 
		createTile(
		true,
		(world.getActiveMap()->getWidth() * 64.f) / 2 - 160.f,
		(world.getActiveMap()->getHeight() * 64.f) / 2 - 160.f, 
		*world.getBoxWorld()));

	world.addGameObject(alttari);

	MonsterRendererComponent* altarRenderer = new MonsterRendererComponent(alttari, altar);
	altarRenderer->sizeX = 320.f;
	altarRenderer->sizeY = 320.f;
	alttari->addComponent(altarRenderer);

	GameObject* moonSwitch = new GameObject();
	attachBody(moonSwitch, createTile(64.f * 40, 23 * 64.f, *world.getBoxWorld()));
	world.addGameObject(moonSwitch);
	switchComponent = new SwitchComponent(moonSwitch);
	moonSwitch->addComponent(new MonsterRendererComponent(moonSwitch, box));
	moonSwitch->addComponent(switchComponent);

	player->addComponent(camera);
	player->addComponent(new PlayerRendererComponent(player, gfxPlayer));
	player->addComponent(new InputMovementComponent(player));
	player->addComponent(new MouseMovementComponent(player, camera, world, game->getWindow()));
	player->addComponent(new HealthComponent(player, 100));
	player->addComponent(new SoulComponent(player));
	player->addComponent(new MoonComponent(player));
	player->addComponent(new InteractionComponent(player));
	player->addComponent(new Hud(player, sf::Vector2f(1280.f, 720.f), camera));

	world.addGameObject(player);
	world.setPlayer(player);

	GameObject* susi = new GameObject();
	susi->body = createSusiBody(2400, 1550, *world.getBoxWorld());
	susi->addComponent(new MonsterRendererComponent(susi, gfxSusi));
	susi->addComponent(new HealthComponent(susi, 100));

	FiniteStateMachine* brain = new FiniteStateMachine(susi);
	brain->pushState(new FollowState(susi, brain, &world));
	susi->addComponent(brain);

	world.addGameObject(susi);

	game->getSoundManager()->playDogBark();

	monsterGenerator = new MonsterGenerator(world, game->getSoundManager());

	monsterGenerator->generateTo(64.f * 40, 20 * 64.f);
	monsterGenerator->generateTo(64.f * 35, 20 * 64.f);
	monsterGenerator->generateTo(64.f * 35, 15 * 64.f);

}

b2Body* createSusiBody(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world.CreateBody(&BodyDef);


	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32 / 2.f), Convert::worldToBox2d(32 / 2.f));
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.005f;
	FixtureDef.friction = 0.1f;
	//FixtureDef.restitution = 0.f;
	

	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);
	return body;
}

b2Body* createPlayerBody(float x, float y, b2World& world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world.CreateBody(&BodyDef);


	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32 / 2.f), Convert::worldToBox2d(48.f / 2.f));
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.1f;
	FixtureDef.friction = 0.1f;
	//FixtureDef.restitution = 0.f;
	
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);
	return body;
}

void attachBody(GameObject* owner, b2Body* body) {
	owner->body = body;
	body->SetUserData(owner);
}

b2Body* createTile(bool isSensor, float x, float y, b2World& world) {

	b2BodyDef BodyDef;

	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_staticBody;

	b2Body* body = world.CreateBody(&BodyDef);
	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(64.f / 2.f), Convert::worldToBox2d(64.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.isSensor = isSensor;

	body->CreateFixture(&FixtureDef);
	return body;
}

b2Body* createTile(float x, float y, b2World& world) {
	return createTile(false, x, y, world);
}

GameplayScreen::~GameplayScreen()
{
	delete monsterGenerator;
	monsterGenerator = NULL;
}

void GameplayScreen::update(sf::Time& tpf) {
	monsterGenerator->spawnMonsters();
	world.update(tpf);

	if (switchComponent->moonStateChanged()) {
		std::vector<GameObject*>* gameObjects = world.getGameObjects();

		GameObject* p = world.getPlayer();

		for (int i = 0; i < gameObjects->size(); i++) {
			GameObject* o = gameObjects->at(i);
			HealthComponent* c = (HealthComponent*)o->getComponent<HealthComponent>();

			if (c != 0) {
				if (typeid(c) == typeid(p)) {
					continue;;
				}

				int moonVal = switchComponent->getMoonStateVal();
				int m = switchComponent->getMoonStateVal() / 5;

				if (moonVal > 100 && moonVal < 400) {
					c->addHitPoints(m);
				}
				else if (moonVal > 400 && moonVal < 700) {
					c->removeHitPoints(m);
				}
				else {
					c->resetToDefault();
				}
			}
		}
	}
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
