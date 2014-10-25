#include "soundManager.h"

soundManager* soundManager::_sound = 0;

soundManager& soundManager::getSound()
{
	if (!_sound)
	{
		_sound = new soundManager();
		_sound->initialiseSound();
	}
	return *_sound;
}

void soundManager::initialiseSound()
{
	attackSoundBuffer1.loadFromFile("effects/attack1.ogg");
	attackSound1.setBuffer(attackSoundBuffer1);
	attackSoundBuffer2.loadFromFile("effects/attack2.ogg");
	attackSound2.setBuffer(attackSoundBuffer2);
	attackSoundBuffer3.loadFromFile("effects/attack3.ogg");
	attackSound3.setBuffer(attackSoundBuffer3);
	walkSoundBuffer1.loadFromFile("effects/footSteps1.ogg");
	walkSound1.setBuffer(walkSoundBuffer1);
	walkSoundBuffer2.loadFromFile("effects/footSteps2.ogg");
	walkSound2.setBuffer(walkSoundBuffer2);
	smallMonsterGruntSoundBuffer.loadFromFile("effects/smallDeath.ogg");
	smallMonsterGruntSound.setBuffer(smallMonsterGruntSoundBuffer);
	smallMonsterEntrySoundBuffer.loadFromFile("effects/smallEntry.ogg");
	smallMonsterEntrySound.setBuffer(smallMonsterEntrySoundBuffer);
	bigMonsterEntrySoundBuffer.loadFromFile("effects/bigEntry.ogg");
	bigMonsterEntrySound.setBuffer(bigMonsterEntrySoundBuffer);
	bigMonsterGruntSoundBuffer.loadFromFile("effects/bigPain.ogg");
	bigMonsterGruntSound.setBuffer(bigMonsterGruntSoundBuffer);
	bigMonsterGrowlSoundBuffer.loadFromFile("effects/bigDeath.ogg");
	bigMonsterGrowlSound.setBuffer(bigMonsterGrowlSoundBuffer);
	wizardEntrySoundBuffer.loadFromFile("effects/mageEntry.ogg");
	wizardEntrySound.setBuffer(wizardEntrySoundBuffer);
	wizardPoofSoundBuffer.loadFromFile("effects/mageDeath.ogg");
	wizardPoofSound.setBuffer(wizardPoofSoundBuffer);
	leverSoundBuffer.loadFromFile("effects/moonLever.ogg");
	leverSound.setBuffer(leverSoundBuffer);
	selectionSoundBuffer.loadFromFile("effects/selection.ogg");
	selectionSound.setBuffer(selectionSoundBuffer);
	newGameSoundBuffer.loadFromFile("effects/newGame.ogg");
	newGameSound.setBuffer(newGameSoundBuffer);

	playerGruntSoundBuffer.loadFromFile("effects/playerPain.ogg");
	playerGruntSound.setBuffer(playerGruntSoundBuffer);
	playerDeathSoundBuffer.loadFromFile("effects/playerDeath.ogg");
	playerDeathSound.setBuffer(playerDeathSoundBuffer);
	dogBarkSoundBuffer.loadFromFile("effects/dogBark.ogg");
	dogBarkSound.setBuffer(dogBarkSoundBuffer);


}

void soundManager::destroy()
{
	if(_sound)
		delete _sound;

	_sound = 0;
}

soundManager::~soundManager()
{
}

void soundManager::playCalmMusic()
{
	calmMusic.openFromFile("music/calmMusic.ogg");
	calmMusic.setLoop(true);
	calmMusic.setVolume(40);
	calmMusic.play();
}
void soundManager::playMenuMusic()
{
	menuMusic.openFromFile("music/menuMusic.ogg");
	menuMusic.setLoop(true);
	menuMusic.setVolume(40);
	menuMusic.play();
}
void soundManager::playBattleMusic()
{
	int random;

	srand(time(NULL));
	random = rand() % 3;

	if( random == 0)
	{
		battleMusic1.openFromFile("music/battleMusic1.ogg");
		battleMusic1.setLoop(true);
		battleMusic1.setVolume(15);
		battleMusic1.play();
	}
	else if( random == 1)
	{
		battleMusic2.openFromFile("music/battleMusic2.ogg");
		battleMusic2.setLoop(true);
		battleMusic2.setVolume(15);
		battleMusic2.play();
	}
	else if(random == 2)
	{
		battleMusic3.openFromFile("music/battleMusic3.ogg");
		battleMusic3.setLoop(true);
		battleMusic3.setVolume(15);
		battleMusic3.play();
	}

	
}
void soundManager::playBossMusic()
{
	bossMusic.openFromFile("music/bossMusic.ogg");
	bossMusic.setLoop(true);
	bossMusic.setVolume(40);
	bossMusic.play();
}
void soundManager::playFailMusic()
{
	failMusic.openFromFile("music/failMusic.ogg");
	failMusic.setLoop(true);
	failMusic.setVolume(40);
	failMusic.play();
}