#pragma once
#include "BaseObject.h"

namespace spacey{
	namespace objects{
		class PlayerObject : BaseObject{
			public:
				PlayerObject();
				void Draw();
				float angle;
		};
	}
}