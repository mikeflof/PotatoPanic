#include "PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>



using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
{

}

PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{struct A
    {
        void OnAddToWorld(void) {}
    };
    struct B
    {
        void OnAddToWorld(void) {}
    };

    struct C : A, B
    {
        typedef A __SUPER; // define_super(A);
        void OnAddToWorld(void)
        {
            __SUPER::OnAddToWorld();
        }
    };

    struct D : C
    {
        typedef C __SUPER; // define_super(C);
        void OnAddToWorld(void)
        {
            __SUPER::OnAddToWorld();
        }
    };
   
}

void PlayerMovementComponent::Update()
{
    struct A
    {
        void OnAddToWorld(void) {}
    };
    struct B
    {
        void OnAddToWorld(void) {}
    };

    struct C : A, B
    {
        typedef A __SUPER; // define_super(A);
        void OnAddToWorld(void)
        {
            __SUPER::OnAddToWorld();
        }
    };

    struct D : C
    {
        typedef C __SUPER; // define_super(C);
        void OnAddToWorld(void)
        {
            __SUPER::OnAddToWorld();
        }
    };

    float dt = GameEngine::GameEngineMain::GetTimeDelta();

    sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
    float playerVel = 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        wantedVel.x -= playerVel * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        wantedVel.x += playerVel * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        wantedVel.y -= playerVel * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        wantedVel.y += playerVel * dt;
    }

    GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
}