#include "UI.h"
#include <crtdbg.h>

void run()
{
	TestService tservice;
	tservice.Run();

	TestRepo trepo;
	trepo.Run();

	UI start;
	start.Console();
}

int main()
{
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}