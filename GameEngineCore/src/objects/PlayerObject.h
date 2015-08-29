#pragma once
#include "BaseObject.h"
#include "../graphics/Window.h";

namespace spacey{
	namespace objects{
		using namespace graphics;
		class PlayerObject : BaseObject{

			public:
				PlayerObject();
				void Draw();

		};
	}
}