#include <thread>
#include <chrono>
#include "Program.h"
#include "Container.h"

int Program::run()
{
	Container container(50, 30);
	bool running = true;
	while (running)
	{
		container.display_container();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::system("cls");
	}
	return 0;
}