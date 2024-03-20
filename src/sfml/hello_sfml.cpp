
#include <SFML/Graphics.hpp>

struct
{
    int Width;
    int Height;
    int bg[3] = {0 , 0 , 0};
    char *Title;
}Window;

int main()
{
    sf::RenderWindow window(sf::VideoMode(Window.Width, Window.Height), Window.Title);
    sf::CircleShape player(100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {       
            if (!event.type == sf::Event::Closed)
            {
                window.clear();
                window.draw(player);
                window.display();        
            }
            else
            {
                window.close();
                return 1;
            }
        }
    }

    return 0;
}