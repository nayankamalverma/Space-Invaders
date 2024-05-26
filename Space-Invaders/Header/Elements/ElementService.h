#pragma once
#include "Bunker/BunkerController.h"


namespace Element
{
	class BunkerController;

	class ElementService
	{
		Bunker::BunkerController* bunker_controller;

	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();
	};
}
