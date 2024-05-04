#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "Paddle.h"
#include <sstream>

int main()

{
	sf::VideoMode VM(1280, 720);
	sf::RenderWindow window(VM, "Kennedy's Pong");
	sf::Clock clock;
	ball pongball(1280/2,100);
	Paddle pongpaddleleft(1280 / 2 + 500 , 720 / 2);
	Paddle pongpaddleright(1280 / 2 - 500, 720 / 2);

	sf::Font leftfont;
	leftfont.loadFromFile("Fonts/UbuntuSansMono-Regular.ttf");
	sf::Text leftfontHUD;
	leftfontHUD.setFont(leftfont);
	leftfontHUD.setPosition(1280 / 2 + 200 , 0);
	leftfontHUD.setCharacterSize(30);
	leftfontHUD.setFillColor(sf::Color::White);
	leftfontHUD.setOutlineThickness(4);
	leftfontHUD.setOutlineColor(sf::Color::Black);
	int RedPoints = 0;
	std::stringstream sl;
	sl << "" << RedPoints;

	leftfontHUD.setString(sl.str());

	sf::Font rightfont;
	rightfont.loadFromFile("Fonts/UbuntuSansMono-Regular.ttf");
	sf::Text rightfontHUD;
	rightfontHUD.setFont(rightfont);
	rightfontHUD.setPosition(1280 / 2 - 200, 0);
	rightfontHUD.setCharacterSize(30);
	rightfontHUD.setFillColor(sf::Color::White);
	rightfontHUD.setOutlineThickness(4);
	rightfontHUD.setOutlineColor(sf::Color::Black);
	int BluePoints = 0;
	std::stringstream sr;
	sr << "" << BluePoints;

	rightfontHUD.setString(sr.str());

	sf::Time dt;
	sf::Event event;

	float bounceTimer = 0.10f;

	while (window.isOpen())
	{
		dt = clock.restart();
		bounceTimer -= dt.asSeconds();

		if (pongball.getPosition().intersects(pongpaddleleft.getPosition()))
		{
			if (bounceTimer < 0)
			{
				pongball.hitBall();
				bounceTimer = 0.10f;
			}
	
		}

		if (pongball.getPosition().intersects(pongpaddleright.getPosition()))
		{
			if (bounceTimer < 0)
			{
				pongball.hitBall();
				bounceTimer = 0.10f;
			}

		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			pongpaddleleft.moveUp();
		}
		else
		{
			pongpaddleleft.stopUp();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			pongpaddleleft.moveDown();
		}
		else
		{
			pongpaddleleft.stopDown();
		}

		if (pongball.getPosition().intersects(pongpaddleright.getPosition()))
		{
			if (bounceTimer < 0)
			{
				pongball.hitBall();
				bounceTimer = 0.10f;
			}

		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pongpaddleright.moveUp();
		}
		else
		{
			pongpaddleright.stopUp();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pongpaddleright.moveDown();
		}
		else
		{
			pongpaddleright.stopDown();
		}

		if (pongball.getPosition().left > 1280)
		{
			pongball.missSides();
			BluePoints++;
			sr.str("");
			sr << "" << BluePoints;
			rightfontHUD.setString(sr.str());

		}

		if (pongball.getPosition().left < 0 )
		{
			pongball.missSides();
			RedPoints++;
			sl.str("");
			sl << "" << RedPoints;
			leftfontHUD.setString(sl.str());
		}

		if (pongball.getPosition().top < 0 && bounceTimer < 0)
		{
			pongball.bounceTop();
			bounceTimer = 0.10f;
		}

		if (pongball.getPosition().top + pongball.getPosition().height > 720)
		{
			pongball.bounceBottom();
		}

		window.clear(sf::Color(0, 155, 0, 255));
		pongball.update(dt);
		pongpaddleleft.update(dt);
		pongpaddleright.update(dt);

		window.draw(pongball.getShape());
		window.draw(pongpaddleleft.getShape());
		window.draw(pongpaddleright.getShape());
		window.draw(leftfontHUD);
		window.draw(rightfontHUD);

		window.display();



	}
	return(0);

}