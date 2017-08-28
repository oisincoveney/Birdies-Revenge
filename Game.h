#pragma once
#include "ofSoundPlayer.h"
#include "ofImage.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "ofTrueTypeFont.h"
using namespace std;

class Game
{
private:
	Player p;

	typedef set<Bullet> PlayerBullets;
	typedef set<Bullet> EnemyBullets;
	typedef set<unique_ptr<Enemy>> Enemies;

	Enemies e;
	PlayerBullets player_bullets;
	EnemyBullets enemy_bullets;

	ofSoundPlayer sound;
	ofSoundPlayer lasers;
	ofImage background;
	ofTrueTypeFont font1, font2;
	int score, level, highscore;
	int key, mouseX, mouseY;
	int width, height;

	string scoreString;
	string levelString;
	string highscoreString;

	bool scoreChanged, levelChanged;

	ofVboMesh scoreMesh, levelMesh, highscoreDisplay;

public:

	//constructor
	Game();

	//populate enemy set
	void loadLevel();
	//display functions
	int display();		//1 to continue, 2 for pause, 3 for end
	void player();
	void playerShoot();
	void bullets();
	bool enemies();
	void scoreboard();
	//cross-check functions
	void enemy_bullets_crossCheck();	//checks score
	bool player_bullets_crossCheck();
	bool scoreCheck() const;
	//iterator definitions/functions
	typedef PlayerBullets::iterator pb_it;
	typedef EnemyBullets::iterator eb_it;
	typedef Enemies::iterator e_it;
	typedef PlayerBullets::const_iterator const_pb_it;
	typedef EnemyBullets::const_iterator const_eb_it;
	typedef Enemies::const_iterator const_e_it;
	pb_it pb_begin();
	eb_it eb_begin();
	e_it e_begin();
	pb_it pb_end();
	eb_it eb_end();
	e_it e_end();

	void reset();

	//Setters
	void setKey(int key);
	void setMouseX(int x);
	void setMouseY(int y);
};
