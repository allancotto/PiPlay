#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class menuMgr
{
public:
  void startUp(){
    /* START OF VARIABLE TRANSFORM SECTION */
    window.create(sf::VideoMode(1280, 720), "PiVersus");
    window.setVerticalSyncEnabled(true); //Turning on V-Sync

    background.loadFromFile("../src/Resources/Images/PiVersus_Logo.png");
    bgSprite.setTexture(background);
    bgSprite.setPosition(758.f, 150.f);

    outline.setSize(sf::Vector2f(menuButtonSizeX + 20.f, menuButtonSizeY + 20.f));
    outline.setOutlineThickness(3.f);
    outline.setOutlineColor(sf::Color(255, 255, 255));
    outline.setPosition(90.f, 410.f);

    buttonOne.setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
    buttonOne.setFillColor(sf::Color(163, 44, 196)); //Fill colours for the button shapes
    buttonOne.setPosition(100.f, 420.f);             //Setting the positions for the shapes...
    buttonOnePosition = buttonOne.getPosition();     //...and parsing them into a vector variable for click detection purposes
    buttonTwo.setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
    buttonTwo.setFillColor(sf::Color(163, 44, 196));
    buttonTwo.setPosition(490.f, 420.f);
    buttonTwoPosition = buttonTwo.getPosition();
    buttonThree.setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
    buttonThree.setFillColor(sf::Color(163, 44, 196));
    buttonThree.setPosition(880.f, 420.f);
    buttonThreePosition = buttonThree.getPosition();

    arialFont.loadFromFile("../src/Resources/Fonts/arial.ttf"); //Load the text font from file
    buffer.loadFromFile("../src/Resources/Audio/Welcome.wav");  //Load the welcome sound effect into the sound buffer
    welcomeVoiceClip.setBuffer(buffer);

    gameOne.setFont(arialFont);             //Transforms for text 1, which goes over button 1. This is setting up the font.
    gameOne.setString("Soda Prank");        //Setting the string message
    gameOne.setCharacterSize(24);           //Setting the font size (in pixels, NOT points)
    gameOne.setFillColor(sf::Color::White); //Setting text colour
    gameOne.setStyle(sf::Text::Bold);       //Setting text to bold
    gameOne.setPosition(100.f, 420.f);      //Setting the position. This should be at the upper left corner of the shape it's in

    gameTwo.setFont(arialFont); //This process is repeated for text 2, which goes over button 2...
    gameTwo.setString("Statue Game");
    gameTwo.setCharacterSize(24);
    gameTwo.setFillColor(sf::Color::White);
    gameTwo.setStyle(sf::Text::Bold);
    gameTwo.setPosition(490.f, 420.f);

    gameThree.setFont(arialFont); //...and text 3, which goes over button 3.
    gameThree.setString("Piggy Bank");
    gameThree.setCharacterSize(24);
    gameThree.setFillColor(sf::Color::White);
    gameThree.setStyle(sf::Text::Bold);
    gameThree.setPosition(880.f, 420.f);
  }

  void menuGraphics(){
    window.clear(sf::Color::Black);

    window.draw(bgSprite);
    window.draw(outline);
    window.draw(buttonOne);
    window.draw(buttonTwo);
    window.draw(buttonThree);
    window.draw(gameOne);
    window.draw(gameTwo);
    window.draw(gameThree);
    window.display();

    if (soundFlag){welcomeVoiceClip.play();}
    soundFlag = 0;
  }

  void leftClickManager(){
    cursorWindowPosition = sf::Mouse::getPosition(window);

    //Condition block that triggers if the mouse is within the bounds of button 1.
    if ((cursorWindowPosition.x > buttonOnePosition.x) && (cursorWindowPosition.x < buttonOnePosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonOnePosition.y) && (cursorWindowPosition.y < buttonOnePosition.y + menuButtonSizeY))
    {
      std::cout << "You have successfully clicked on game 1!" << std::endl;
      //Code block that moves to the instruction scene for game one, perhaps after some nice effects.
    }

    //Condition block that triggers if the mouse is within the bounds of button 2.
    if ((cursorWindowPosition.x > buttonTwoPosition.x) && (cursorWindowPosition.x < buttonTwoPosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonTwoPosition.y) && (cursorWindowPosition.y < buttonTwoPosition.y + menuButtonSizeY))
    {
      std::cout << "You have successfully clicked on game 2!" << std::endl;
      //Code block that moves to the instruction scene for game two, perhaps after some nice effects.
    }

    //Condition block that triggers if the mouse is within the bounds of button 3.
    if ((cursorWindowPosition.x > buttonThreePosition.x) && (cursorWindowPosition.x < buttonThreePosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonThreePosition.y) && (cursorWindowPosition.y < buttonThreePosition.y + menuButtonSizeY))
    {
      std::cout << "You have successfully clicked on game 3!" << std::endl;
      //Code block that moves to the instruction scene for game three, perhaps after some nice effects.
    }
  }

  sf::RenderWindow window; //Making the window and giving it a title

  int menuState = 0; //integer that handles the state of the menu when it is controlled by a joystick.
  bool soundFlag = true;
  float menuButtonSizeX = 300.f, menuButtonSizeY = 200.f;
  sf::Vector2i cursorWindowPosition; //2D Vector with the coordinates of the mouse cursor in the window
  sf::Vector2f buttonOnePosition, buttonTwoPosition, buttonThreePosition;
  sf::Texture background;
  sf::Sprite bgSprite;
  sf::RectangleShape outline;
  sf::RectangleShape buttonOne;   //Making the shape for the button for game 1
  sf::RectangleShape buttonTwo;   //Repeating for button 2...
  sf::RectangleShape buttonThree; //...and button 3
  sf::Font arialFont; //Variable for text font
  sf::Text gameOne; //Variables for text that go over the buttons that are numbered accordingly
  sf::Text gameTwo;
  sf::Text gameThree;

  sf::SoundBuffer buffer;     //Starting the sound buffer for voice clips.
  sf::Sound welcomeVoiceClip; //Variable that plays the welcome sound clip
};