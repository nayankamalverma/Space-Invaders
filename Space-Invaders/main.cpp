#include <SFML/Graphics.hpp>
#include "Header/Main/GameService.h"

using namespace std;

int main()
{
	Main::GameService* game_service = new Main::GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;
}