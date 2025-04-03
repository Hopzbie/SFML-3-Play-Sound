// library
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// main program
int main()
{
    // load sounds
    sf::SoundBuffer buffer_jump   ("Sounds/Jump.mp3");
    sf::SoundBuffer buffer_gun    ("Sounds/Gun.mp3");
    sf::SoundBuffer buffer_collect("Sounds/Collect.mp3");
    sf::SoundBuffer buffer_step   ("Sounds/Step.mp3");

    // sounds
    sf::Sound sound_jump   (buffer_jump);
    sf::Sound sound_gun    (buffer_gun);
    sf::Sound sound_collect(buffer_collect);
    sf::Sound sound_step   (buffer_step);
    sound_collect.setVolume(50.f);
    sound_step.setLooping(true);

    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // disable key repeat
    window.setKeyRepeatEnabled(false);

    // while window is still open
    while (window.isOpen())
    {
        // handle event
        while (std::optional event = window.pollEvent())
        {
            // when close button is release
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }
        
            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }
        
            // on keyboard press
            else if (auto key = event->getIf<sf::Event::KeyPressed>())
            {
                // jump
                if (key->scancode == sf::Keyboard::Scancode::Space)
                    sound_jump.play();
                // gun
                if (key->scancode == sf::Keyboard::Scancode::Enter)
                    sound_gun.play();
                // collect
                if (key->scancode == sf::Keyboard::Scancode::E)
                    sound_collect.play();
                // step
                if (key->scancode == sf::Keyboard::Scancode::D)
                    sound_step.play();
            }

            // on keyboard release
            else if (auto key = event->getIf<sf::Event::KeyReleased>())
            {
                // stop step
                if (key->scancode == sf::Keyboard::Scancode::D)
                    sound_step.stop();
            }
        }

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // display
        window.display();
    }

    // program end successfully
    return 0;
}