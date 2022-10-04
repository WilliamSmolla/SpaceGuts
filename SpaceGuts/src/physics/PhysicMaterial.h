#pragma once
#include <string>

class PhysicMaterial
{
public:
	PhysicMaterial() = default;
	PhysicMaterial(std::string name, float density, float friction, float restitution, float restitutionThreshold)
		: _name{ name }, _density{ density }, _friction{ friction },
		_restitution{ restitution }, _restitutionThreshold{ restitutionThreshold } {}
	~PhysicMaterial() = default;

	std::string Name() { return _name; }
	float Density() { return _density; }
	float Friction() { return _friction; }
	float Restitution() { return _restitution; }
	float RestitutionThreshold() { return _restitutionThreshold; }

private:
	std::string _name = "PhysicMaterial";
	float _density = 1.0f;
	float _friction = 0.9f;
	float _restitution = 0.5f;
	float _restitutionThreshold = 0.5f;
};
