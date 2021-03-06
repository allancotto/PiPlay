// instructions class
#include "instructions.h"

Instructions::Instructions()
{

  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");

  bgSprite.setTexture(background);
  bgSprite.setPosition(100.f, 40.f);

  instructionState = 0;

  for (int i = 0; i < NUMBER_OF_GAMES; i++){
    instructionText[i].setFont(font);
    switch (i)
    {
    case 0:
      instructionText[i].setString("Move the controller as fast as possible!");
      break;
    case 1:
      instructionText[i].setString("Hold the controller as still as possible!");
      break;
    case 2:
      instructionText[i].setString("Instructions for Game 3");
      break;
    default:
      break;
    }

    instructionText[i].setCharacterSize(36); // font size in pixels not points
    instructionText[i].setFillColor(sf::Color::White);
    instructionText[i].setStyle(sf::Text::Bold);
    instructionText[i].setPosition(500.f, 150.f); // position to upper left corner
  }

    buttonText[0].setFont(font);
    buttonText[0].setString("Play Game");
    buttonText[0].setCharacterSize(24); // font size in pixels not points
    buttonText[0].setFillColor(sf::Color::White);
    buttonText[0].setStyle(sf::Text::Bold);
    buttonText[0].setPosition(100.f, 420.f); // position to upper left corner

    buttonText[1].setFont(font);
    buttonText[1].setString("Back to Menu");
    buttonText[1].setCharacterSize(24); // font size in pixels not points
    buttonText[1].setFillColor(sf::Color::White);
    buttonText[1].setStyle(sf::Text::Bold);
    buttonText[1].setPosition(490.f, 420.f); // position to upper left corner

  // for some reason defined value isn't currently working so defining here instead
  float menuButtonSizeX = 300.f, menuButtonSizeY = 200.f;

  outline.setSize(sf::Vector2f(menuButtonSizeX + 20.f, menuButtonSizeY + 20.f));
  outline.setOutlineThickness(3.f);
  outline.setOutlineColor(sf::Color(255, 255, 255));
  outline.setPosition(90.f, 410.f);

  buttons[0].setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
  buttons[0].setFillColor(sf::Color(162, 44, 196));
  buttons[0].setPosition(100.f, 420.f);

  buttons[1].setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
  buttons[1].setFillColor(sf::Color(162, 44, 196));
  buttons[1].setPosition(490.f, 420.f);
}

void Instructions::moveRight() {

    if(instructionState +1 < 2 ) { 
        
        instructionState++;
        outline.setPosition(buttons[instructionState].getPosition().x-10,buttons[instructionState].getPosition().y-10);
    }
}

void Instructions::moveLeft() {

    if(instructionState -1 >= 0 ) {
        
        instructionState--;
        outline.setPosition(buttons[instructionState].getPosition().x-10,buttons[instructionState].getPosition().y-10);
    }
}

void Instructions::draw(sf::RenderWindow &window, int state)
{
  
  window.draw(bgSprite);
  window.draw(outline);
  window.draw(buttons[0]);
  window.draw(buttons[1]);
  window.draw(buttonText[0]);
  window.draw(buttonText[1]);

  switch (state)
  {
  case 0:
    window.draw(instructionText[state]);
    break;
  case 1:
    window.draw(instructionText[state]);
    break;
  case 2:
    window.draw(instructionText[state]);
    break;
  default:
    break;
  }

  window.draw(bgSprite);
}
