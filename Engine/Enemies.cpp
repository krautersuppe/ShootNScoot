#include "Enemies.h"

void sns::Enemy::Update( float dt )
{
	std::visit( [ & ]( auto& entity_ )
	{
		using type = std::decay_t<decltype( entity_ )>;
		position += ( velocity * ( type::speed * dt ) );
	}, variant );
}
