#include "EnemySpawner.h"
#include "World.h"
#include "WorldView.h"
#include "WorldController.h"

void EnemySpawner::Update( World& world, float dt )
{
	switch( state )
	{
		case State::Waiting:
			enemy_spawn_group_timer -= dt;
			if( enemy_spawn_group_timer <= 0.f )
			{
				if( enemy_spawn_group < enemy_spawn_group_max )
					state = State::Spawning;
				else
					state = State::Complete;
			}
			break;
		case State::Spawning:
			enemy_spawn_timer -= dt;
			if( enemy_spawn_timer <= 0.f )
			{
				enemy_spawn_timer = enemy_spawn_rate;
				++enemy_spawn_group_count;
				switch( enemy_spawn_group )
				{
					case 0:
					{
						SpawnEnemy1( world );
						break;
					}
					case 1:
					{
						SpawnEnemy2( world );
						break;
					}
					case 2:
					{
						SpawnEnemy3( world );
						break;
					}
					case 3:
					{
						SpawnEnemy4( world );
						break;
					}
					case 4:
					{
						SpawnEnemy5( world );
						break;
					}
					default:
						assert( false );
						break;
				}

				if( enemy_spawn_group_count > enemy_spawn_max )
				{
					enemy_spawn_group_timer = enemy_spawn_group_delay;
					++enemy_spawn_group;
					enemy_spawn_group_count = 0;
					state = State::Waiting;
				}
			}
			break;
		default:
			break;
	}
}

void EnemySpawner::Reset() noexcept
{
	enemy_spawn_group			= 0;
	enemy_spawn_group_count		= 0;
	enemy_spawn_group_timer		= enemy_spawn_group_delay;
	enemy_spawn_timer			= 0.f;

	state						= State::Waiting;
}

void EnemySpawner::SpawnEnemy1( World& world )
{
	auto xDist = 
		std::uniform_real_distribution<float>{ -50.f, screenRect.Width() + 50.f };
	auto position = Vec2{ xDist( rng ), Enemy1::aabb.top };

	world.SpawnEnemy( { Enemy1{}, position, {0.f, 1.f} } );
}

void EnemySpawner::SpawnEnemy2( World& world )
{
	auto xDist = std::uniform_real_distribution<float>{ 0.f, screenRect.Width() };
	const auto pos = Vec2{ xDist( rng ), -50.f };
	auto delta = world.hero.position - Vec2{ xDist( rng ), Enemy2::aabb.top };

	world.SpawnEnemy( { Enemy2{}, pos, delta.Normalize() } );
}

void EnemySpawner::SpawnEnemy3( World& world )
{
	const auto xPos = ( enemy_spawn_group_count % 2 ) == 0 ? -50.f : screenRect.Width() + 50.f;
	const auto yPos = float( enemy_spawn_group_count % 2 ) * 20.f;
	
	const auto xDir = xPos < screenRect.Center().x ? 1.f : -1.f;
	const auto yDir = 0.f;
	world.SpawnEnemy( { Enemy3{}, Vec2{ xPos, yPos }, Vec2{ xDir, yDir } } );
}

void EnemySpawner::SpawnEnemy4( World& world )
{

}

void EnemySpawner::SpawnEnemy5( World& world )
{
}
