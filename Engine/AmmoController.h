#pragma once

#include "Rect.h"

namespace sns
{
	class Ammo;

	class AmmoController
	{
	public:
		void Update( Ammo& model, float dt )noexcept;

		void TakeDamage( Ammo& model, float amount )noexcept;
		float Damage( Ammo const& model )const noexcept;
		RectF AABB( Ammo const& model )const noexcept;
		bool IsAlive( Ammo const& model )const noexcept;
	};
}