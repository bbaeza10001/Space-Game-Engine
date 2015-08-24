#pragma once
#include "BaseObject.h"

namespace spacey{
	namespace objects{
		class CircleObject : BaseObject{
		public:
			CircleObject();
			CircleObject(float x_in, float y_in, float radius_in);
			void Draw();
			float radius;
		};
	}
}