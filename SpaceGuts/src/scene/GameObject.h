#pragma once
#include "entt/entt.hpp"
#include "../maths/Maths.h"
#include "scene/Scene.h"
#include "core/Log.h"

class GameObject
{
public:
	GameObject() = default;
	GameObject(entt::entity handle, Scene* scene);
	GameObject(const GameObject& other) = default;
	
	template<typename T, typename... Args>
	T& AddComponent(Args&&... args)
	{
		if (HasComponent<T>())
		{
			Log::Error("GameObject already have this component. It can't be added again.");		
		}
		T& component = _scene->_registry.emplace<T>
			(_handle, std::forward<Args>(args)...);
		return component;
	}
	
	template<typename T>
	void RemoveComponent()
	{
		if (!HasComponent<T>())
		{
			Log::Error("GameObject don't have this component. It can't be removed.");
			return;
		}
		_scene->_registry.remove<T>(_handle);
	}

	template<typename T>
	T& GetComponent()
	{
		if (!HasComponent<T>())
		{
			Log::Error("GameObject don't have this component. It can't get a reference to it.");
		}
		return _scene->_registry.get<T>(_handle);
	}

	template<typename T>
	bool HasComponent()
	{
		return _scene->_registry.any_of<T>(_handle);
	}

	Scene* scene() { return _scene; }

	operator bool() const { return _handle != entt::null; }
	operator entt::entity() const { return _handle; }
	operator uint32_t() const { return (uint32_t)_handle; }

	bool operator==(const GameObject& other) const
	{
		return _handle == other._handle && _scene == other._scene;
	}

	bool operator!=(const GameObject& other) const
	{
		return !(*this == other);
	}

private:
	entt::entity _handle{ entt::null };
	Scene* _scene = nullptr;
};

