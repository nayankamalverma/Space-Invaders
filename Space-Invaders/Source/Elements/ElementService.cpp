#include "../../Header/Elements/ElementService.h"

namespace Element
{
	ElementService::ElementService() {  }

	ElementService::~ElementService() { destroy(); }

	void ElementService::initialize()
	{
		for (auto i : bunker_data_list)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();

			bunker_controller->initialize(i);
			bunker_list.push_back(bunker_controller);
		}
	}

	void ElementService::update()
	{
		for (auto& i : bunker_list) i->update();
	}

	void ElementService::render()
	{
		for (auto& i : bunker_list) i->render();
	}

	void ElementService::destroy()
	{
		for (auto& i : bunker_list) delete(i);
	}

}
