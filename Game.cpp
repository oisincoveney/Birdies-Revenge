#include "Game.h"
#include "ofCamera.h"
#include "RandomEnemy.h"

Game::Game() : p{ Player() }, score{ 10 }, level{ 0 }, highscore{ 0 }, key{ 0 }, mouseX{ 0 }, mouseY{ 0 }, width{ ofGetWidth() }, height{ ofGetHeight() }, scoreString{ "SCORE:   10" }, levelString{ "LEVEL: " }, highscoreString{ "HIGHEST LEVEL:   " }, scoreChanged(false), levelChanged(false)
{
	ofBackground(255);
	sound.load("battle.mp3");
	lasers.load("laser.mp3");
	lasers.setMultiPlay(true);
	background.load("background.jpg");
	sound.setLoop(true);
	sound.play();
	font1.load("header.ttf", 50);
	scoreMesh = font1.getStringMesh(scoreString, 100, 100);
	levelMesh = font1.getStringMesh(levelString, ofGetWidth() - 450, 80);
	highscoreDisplay = font1.getStringMesh(highscoreString + std::to_string(highscore), 100, ofGetHeight() - 80);
}

int Game::display()
{
	if (e.size() == 0)
	{
		level++;
		levelChanged = true;
		loadLevel();
	}
	if (key == ' ')
	{
		key = 0;
		return 2;
	}
	ofSetColor(255);
	background.draw(0, 0);
	scoreboard();
	player();
	bullets();
	enemy_bullets_crossCheck();
	if (enemies() && player_bullets_crossCheck() && scoreCheck())
	{
		highscore = level;
		return 3;
	}
	return 1;
}
void Game::player()
{
	p.setKey(key);
	p.setMouseX(mouseX);
	p.setMouseY(mouseY);
	p.setAngle();
	p.update();
	p.display();
}
void Game::playerShoot()
{
	if (player_bullets.size() < 20) {
		lasers.play();
		player_bullets.insert(p.shoot());
	}
}
void Game::bullets()
{
	std::set<Bullet>::iterator i = player_bullets.begin();
	while (i != player_bullets.end())
	{
		bool outOfBounds = (i->getX() < 0 || i->getX() > width || i->getY() < 0 || i->getY() > height);
		if (outOfBounds)
		{
			player_bullets.erase(i++);
		}
		else
		{
			(*i).display();
			++i;
		}
	}
	std::set<Bullet>::iterator it = enemy_bullets.begin();
	while (it != enemy_bullets.end())
	{
		bool outOfBounds = (it->getX() < 0 || it->getX() > width || it->getY() < 0 || it->getY() > height);
		if (outOfBounds)
		{
			enemy_bullets.erase(it++);
		}
		else
		{
			(*it).display();
			++it;
		}
	}
}
bool Game::enemies()
{
	std::set<unique_ptr<Enemy>>::iterator i = e.begin();
	while (i != e.end())
	{
		bool outOfBounds = ((*i)->getX() <= 0);
		if (outOfBounds)
		{
			e.erase(i++);
			score -= 5;
			scoreChanged = true;
			if (score <= 0)
				return false;
		}
		else
		{
			(**i).display();
			Bullet b = (**i).shoot();
			if (b.getX() >= 0)
			{
				if (ofGetFrameNum() % 6)
					lasers.play();
				enemy_bullets.insert(b);
			}
			++i;
		}
	}
	return true;
}

void Game::loadLevel()
{
	if (level < 6)
	{
		for (int i{}; i < level; i++)
		{
			e.insert(make_unique<Enemy>());
		}
	}
	else if (level < 12)
	{
		for (int i{}; i < level; i++)
		{
			e.insert(make_unique<Enemy>());
		}
		for (int j{}; j < 12 - level; j++)
			e.insert(unique_ptr<Enemy>(make_unique<RandomEnemy>()));
	}
	else if (level < 18)
	{
		for (int i{}; i < level; i++)
		{
			if (i % 3 == 0)
			{
				e.insert(unique_ptr<Enemy>(make_unique<RandomEnemy>()));
			}
			else
			{
				e.insert(make_unique<Enemy>());
			}
		}
	}
	else if (level < 24)
	{
		for (int i{}; i < level; i++)
		{
			if (i % 2 == 0)
			{
				e.insert(unique_ptr<Enemy>(make_unique<RandomEnemy>()));
			}
			else
			{
				e.insert(make_unique<Enemy>());
			}
		}
	}
	else
	{
		for (int i{}; i < level; i++)
		{
			if (rand() % 2 == 0)
			{
				e.insert(unique_ptr<Enemy>(make_unique<RandomEnemy>()));
			}
			else
			{
				e.insert(make_unique<Enemy>());
			}
		}
	}
}

void Game::scoreboard()
{
	if (scoreChanged)
	{
		scoreString = scoreString.substr(0, 7) + to_string(score);
		scoreMesh = font1.getStringMesh(scoreString, 100, 100);
		scoreChanged = false;
	}
	if (levelChanged)
	{
		levelString = levelString.substr(0, 7) + to_string(level);
		levelMesh = font1.getStringMesh(levelString, ofGetWidth() - 450, 100);
		levelChanged = false;
	}

	if (level > highscore)
	{
		highscoreString = highscoreString.substr(0, 15) + to_string(level);
		highscoreDisplay = font1.getStringMesh(highscoreString, 100, ofGetHeight() - 100);
	}

	font1.getFontTexture().bind();
	scoreMesh.draw();
	levelMesh.draw();
	highscoreDisplay.draw();
	font1.getFontTexture().unbind();
}

//Cross-check functions
void Game::enemy_bullets_crossCheck()
{
	bool hit{ false };
	std::set<unique_ptr<Enemy>>::iterator i = e.begin();
	while (i != e.end())
	{
		hit = false;

		std::set<Bullet>::iterator j = player_bullets.begin();
		while (j != player_bullets.end())
		{
			hit = (*i)->checkIfHit(j->getX(), j->getY());
			if (hit)
			{
				j = player_bullets.erase(j);
				score++;
				scoreChanged = true;
				break;
			}
			else
			{
				++j;
			}
		}

		if (hit)
		{
			e.erase(i++);;
		}
		else
		{
			++i;
		}
	}
}

bool Game::player_bullets_crossCheck()
{
	int pX = p.getX();
	int pY = p.getY();

	std::set<Bullet>::iterator it = eb_begin();
	while (it != eb_end())
	{
		bool hit = p.checkIfHit(it->getX(), it->getY());
		if (hit)
		{
			enemy_bullets.erase(it++);
			score--;
			if (score <= 0)
				return false;
			scoreChanged = true;
		}
		else
		{
			++it;
		}
	}
	return true;
}

//score check
bool Game::scoreCheck() const
{
	return score <= 0;
}
//Iterators
Game::pb_it Game::pb_begin() { return player_bullets.begin(); }
Game::eb_it Game::eb_begin() { return enemy_bullets.begin(); }
Game::e_it Game::e_begin() { return e.begin(); }
Game::pb_it Game::pb_end() { return player_bullets.end(); }
Game::eb_it Game::eb_end() { return enemy_bullets.end(); }
Game::e_it Game::e_end() { return e.end(); }

void Game::reset()
{
	p.reset();
	e.clear();
	enemy_bullets.clear();
	player_bullets.clear();
	level = 1;
	score = 10;
	key = 0;
	mouseX = 0;
	mouseY = 0;

	scoreString = "SCORE: ";
	levelString = "LEVEL: ";
	scoreChanged = false;
	levelChanged = false;
	scoreMesh = font1.getStringMesh(scoreString, 100, 200);
	levelMesh = font1.getStringMesh(levelString, ofGetWidth() - 1000, 200);
}

//Setters
void Game::setKey(int key) { this->key = key; }
void Game::setMouseX(int x) { mouseX = x; }
void Game::setMouseY(int y) { mouseY = y; }