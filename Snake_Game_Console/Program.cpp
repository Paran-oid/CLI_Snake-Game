#include <thread>
#include <chrono>
#include "Program.h"
#include "Container.h"
#include "threads.h"

#define WINDOW_WIDTH 20
#define WINDOW_HEIGHT 15

int Program::run()
{
	Container container(WINDOW_WIDTH, WINDOW_HEIGHT);
	bool running = true;


	while (running)
	{
		container.initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
		container.display_container();
	}
	return 0;
}