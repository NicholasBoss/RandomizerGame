#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>


int main()
{

	sf::RenderWindow window(sf::VideoMode(1600, 900), "Randomizer");

	sf::Font font;
	sf::Texture Texture;
	sf::Sprite Sprite;

	Texture.loadFromFile("player.png");

	Sprite.setTexture(Texture);
	int x = 0;
	int y = 0;
	Sprite.move(x, y);

	int changeX = 10;
	int changeY = 0;

	int direction = 1;
	font.loadFromFile("High Spirited.ttf");

	sf::Text welcomeText;
	sf::Text optionText;

	welcomeText.setFont(font);
	welcomeText.setString("Welcome to the Ranomizer game!");
	welcomeText.setCharacterSize(150);
	welcomeText.setFillColor(sf::Color::White);

	optionText.setFont(font);
	optionText.setString("Press [spacebar] for Random name");
	optionText.setCharacterSize(200);
	optionText.setFillColor(sf::Color::Cyan);
	optionText.setPosition(0, 100);

	while (window.isOpen())
	{
		sf::Event event;
	
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					return 0;
				}

			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					changeX += -5;
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					changeX += 5;
				}
				else if (event.key.code == sf::Keyboard::W)
				{
					changeY += -5;
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					changeY += 5;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					std::string fname = "students.csv";
					std::vector<std::vector<std::string>> content;
					std::string word, line;
					std::vector<std::string> row;
					std::fstream file(fname, std::ios::in); 
					if (file.is_open())
					{
						while (getline(file, line))
						{
							row.clear();
							std::stringstream str(line);

							while (getline(str, word, ','))
								row.push_back(word);
							content.push_back(row);
						}
						file.close();
					}
					
					int randompick;
					std::random_device generator;
					std::uniform_int_distribution<int>  distribution(0, content.size());
					randompick = distribution(generator);
					std::cout << "random number is: " << randompick << "\n";//-- to test if number is truly random
					std::cout << content[randompick][0];
					optionText.setString(content[randompick][0]);

					
				}
			}
			
		}
		Sprite.setPosition(changeX, changeY);
		window.clear();
		window.draw(welcomeText);
		window.draw(optionText);
		window.draw(Sprite);
		Sprite.move(changeX, changeY);
		window.display();
	}
	
}