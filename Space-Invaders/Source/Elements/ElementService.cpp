#include "../../Header/Elements/ElementService.h"
#include "../../Header/Elements/Bunker/BunkerController.h"

namespace Element
{
	using namespace Bunker;

	ElementService::ElementService() { bunker_controller = new Bunker::BunkerController(); }

	ElementService::~ElementService() { delete(bunker_controller); }

	void ElementService::initialize()
	{
		bunker_controller->initialize(bunker_controller->getBunkerPosition());
	}

	void ElementService::update()
	{
		bunker_controller->update();
	}
	void ElementService::render()
	{
		bunker_controller->render();
	}

	


}
