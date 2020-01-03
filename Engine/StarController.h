#pragma once

#include "Vec2.h"
#include <random>

namespace sns
{
	class StarController
	{
	public:
		void Update( class Star& model )noexcept;

	private:
		std::mt19937 rng;

	};
}

