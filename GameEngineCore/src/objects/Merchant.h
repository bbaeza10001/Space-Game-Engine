#pragma once

#include "BaseObject.h"

namespace spacey{
	namespace objects{

		using namespace std;

		class Merchant : public BaseObject{
		public:

			Merchant();
			Merchant(int x, int y, string filename);

			void Draw();
		private:

		};
	}
}