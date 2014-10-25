#pragma once

#include <SFML\Audio.hpp>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>

class soundManager
{
public:

	static soundManager* _sound;

	soundManager(const soundManager&){}
	soundManager(void){}
	~soundManager(void);

	void initialiseSound();

	static void destroy();

	void playLever()
	{
		leverSound.setLoop(true);
		leverSound.play();
	}
	void playSelection(){selectionSound.play();}
	void playSmallMonsterEntry(){smallMonsterEntrySound.play();}
	void playSmallMonsterDeath(){smallMonsterGruntSound.play();}
	void playBigMonsterEntry(){bigMonsterEntrySound.play();}
	void playBigMonsterGrunt(){smallMonsterGruntSound.play();}
	void playBigMonsterDeath(){bigMonsterGrowlSound.play();}
	void playPlayerGrunt(){playerGruntSound.play();}
	void playPlayerDeath(){playerDeathSound.play();}
	void playMenuSelection(){newGameSound.play();}
	void playWizardEntry(){wizardEntrySound.play();}
	void playWizardDeath(){wizardPoofSound.play();}
	void playDogBark(){ dogBarkSound.play(); }

	void playAttackSound()
	{
		srand(time(NULL));
		random = rand() % 3;

		std::cout << random << std::endl;

		if(random == 0)
			attackSound1.play();
		
		else if(random == 1)
			attackSound2.play();

		else
			attackSound3.play();
	}

	void playWalkSound()
	{
		srand(time(NULL));
		random = rand()%2;

		if(random == 0)
		{
			walkSound1.setLoop(true);
			walkSound1.play();
		}
		else
		{
			walkSound2.setLoop(true);
			walkSound2.play();
		}
	}



	void playBackGroundMusic();
	void playMenuMusic();
	void playBattleMusic();
	void playBossMusic();
	void playFailMusic();
	void playCalmMusic();

	void toggleMuteSounds();
	void toggleMuteMusic();

	static soundManager& getSound();

	sf::SoundBuffer walkSoundBuffer1;
	sf::Sound walkSound1;
	sf::SoundBuffer walkSoundBuffer2;
	sf::Sound walkSound2;

	int random;

private:

	//Lever soundi
	sf::SoundBuffer leverSoundBuffer;
	sf::Sound leverSound;

	//Hyökkäysäänet
	sf::SoundBuffer attackSoundBuffer1;
	sf::Sound attackSound1;
	sf::SoundBuffer attackSoundBuffer2;
	sf::Sound attackSound2;
	sf::SoundBuffer attackSoundBuffer3;
	sf::Sound attackSound3;
	
	//Valintaäänet
	sf::SoundBuffer selectionSoundBuffer;
	sf::Sound selectionSound;
	sf::SoundBuffer newGameSoundBuffer;
	sf::Sound newGameSound;

	//Monsteriäänet
	sf::SoundBuffer smallMonsterGruntSoundBuffer;
	sf::Sound smallMonsterGruntSound;
	sf::SoundBuffer smallMonsterEntrySoundBuffer;
	sf::Sound smallMonsterEntrySound;
	sf::SoundBuffer bigMonsterEntrySoundBuffer;
	sf::Sound bigMonsterEntrySound;
	sf::SoundBuffer bigMonsterGruntSoundBuffer;
	sf::Sound bigMonsterGruntSound;
	sf::SoundBuffer bigMonsterGrowlSoundBuffer;
	sf::Sound bigMonsterGrowlSound;
	sf::SoundBuffer wizardEntrySoundBuffer;
	sf::Sound wizardEntrySound;
	sf::SoundBuffer wizardPoofSoundBuffer;
	sf::Sound wizardPoofSound;

	//Pelaajaäänet
	sf::SoundBuffer playerGruntSoundBuffer;
	sf::Sound playerGruntSound;
	sf::SoundBuffer playerDeathSoundBuffer;
	sf::Sound playerDeathSound;
	sf::SoundBuffer dogBarkSoundBuffer;
	sf::Sound dogBarkSound;


	sf::Music menuMusic;
	sf::Music battleMusic1;
	sf::Music battleMusic2;
	sf::Music battleMusic3;
	sf::Music calmMusic;
	sf::Music bossMusic;
	sf::Music failMusic;
};
