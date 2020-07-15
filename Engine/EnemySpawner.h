#pragma once

#include "Enemies.h"
#include <random>

class World;

struct EnemySpawner
{
public:
	void Update( World& world, float dt );
	void Reset()noexcept;

public:
	enum class State { Complete, Waiting, Spawning };

private:
	void SpawnEnemy1( World& world );
	void SpawnEnemy2( World& world );
	void SpawnEnemy3( World& world );
	void SpawnEnemy4( World& world );
	void SpawnEnemy5( World& world );
public:
	static constexpr float enemy_spawn_rate = .5f;
	static constexpr float enemy_spawn_group_delay = 12.f;
	static constexpr int enemy_spawn_group_max = 5;
	static constexpr float boss_spawn_delay = 60.f;
	static constexpr int enemy_spawn_max = 5;

	int enemy_spawn_group = 0;
	int enemy_spawn_group_count = 0;
	float enemy_spawn_group_timer = enemy_spawn_group_delay;
	float enemy_spawn_timer = 0.f;

	State state = State::Waiting;
	std::mt19937 rng;
};