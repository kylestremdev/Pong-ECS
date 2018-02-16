//
//  ECS.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
    Entity* entity;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    virtual void handleKeyDown(unsigned char key) {}
    virtual void handleKeyUp(unsigned char key) {}
    virtual void handleMouseInput(int button, int state, int x, int y) {}
    
    virtual ~Component() {}
};

class Entity {
public:
    void update() {
        for(auto& c : components) c->update();
    }
    
    void draw() {
        for(auto& c : components) c->draw();
    }
    
    void keyDown(unsigned char key) {
        for(auto& c : components) c->handleKeyDown(key);
    }
    
    void keyUp(unsigned char key) {
        for(auto& c : components) c->handleKeyUp(key);
    }
    
    void mouse(int button, int state, int x, int y) {
        for(auto& c : components) c->handleMouseInput(button, state, x, y);
    }
    
    bool isActive() { return active; }
    void destroy() { active = false; }
    
    template <typename T> bool hasComponent() const {
        return componentBitSet[getComponentTypeID<T>()];
    }
    
    template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr { c };
        components.emplace_back(std::move(uPtr));
        
        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;
        
        c->init();
        return *c;
    }
    
    template <typename T> T& getComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
};

class EntityManager {
public:
    void update() {
        for (auto& e : entities) e->update();
    }
    
    void draw() {
        for (auto& e : entities) e->draw();
    }
    
    void keyDown(unsigned char key) {
        for (auto& e : entities) e->keyDown(key);
    }
    
    void keyUp(unsigned char key) {
        for (auto& e : entities) e->keyUp(key);
    }
    
    void mouse(int button, int state, int x, int y) {
        for (auto& e : entities) e->mouse(button, state, x, y);
    }
    
    void refresh() {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity> &mEntity) {
            return !mEntity->isActive();
        }), std::end(entities));
    }
    
    Entity& addEntity() {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr { e };
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
    
    std::vector<std::unique_ptr<Entity>> entities;
    
};

class System {
public:
    System(EntityManager* em): entityManager(em) {}
    
    EntityManager* entityManager;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
};





#endif /* ECS_hpp */
