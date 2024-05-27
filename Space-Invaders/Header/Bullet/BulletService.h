#pragma once

namespace Bullet
{
	class BulletService
	{

	public:
		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();
	};
}
