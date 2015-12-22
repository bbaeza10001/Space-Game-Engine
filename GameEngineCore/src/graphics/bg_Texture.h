#pragma once
#include "../objects/BaseObject.h"
#include <vector>
#include <string>
#include <iostream>

namespace spacey{
	namespace graphics{
		using namespace objects;
		using namespace std;

		class bg_Texture : BaseObject{
		public:
			bg_Texture();
			bg_Texture(string filename);
			void Draw();
		private:
			bool loadBG(string filename);
		};
	}
}