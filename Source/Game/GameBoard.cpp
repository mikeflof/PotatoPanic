#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Component.h"

using namespace Game;

GameBoard::GameBoard()
    : m_player(nullptr)
{
    CreatePlayer();
    CreateBackground();
}

GameBoard::~GameBoard()
{
}

void GameBoard::CreatePlayer()
{
    m_player = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

    m_player->SetPos(sf::Vector2f(400.f, 400.f));
    m_player->SetSize(sf::Vector2f(50.f, 50.f));

    GameEngine::SpriteRenderComponent *spriteRender = static_cast<GameEngine::SpriteRenderComponent *>(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Transparent);
    spriteRender->SetTexture(GameEngine::eTexture::Potato);
    spriteRender->SetZLevel(1);

    //Movement
    m_player->AddComponent<PlayerMovementComponent>();
}

void GameBoard::CreateBackground()
{
    GameEngine::Entity *background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(250.f, 250.f));
    background->SetSize(sf::Vector2f(500.f, 700.f));

    GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(background->AddComponent<GameEngine::SpriteRenderComponent>());

    render->SetTexture(GameEngine::eTexture::Background);
    render->SetFillColor(sf::Color::Transparent);
    render->SetZLevel(0);

}

void GameBoard::CreateObstacle()
{
    GameEngine::Entity *obstacle = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

    obstacle->SetPos(sf::Vector2f(200.f, 200.f));
    obstacle->SetSize(sf::Vector2f(70.f, 70.f));

    GameEngine::SpriteRenderComponent* spriterender = static_cast<GameEngine::SpriteRenderComponent *>(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

    spriterender->SetFillColor(sf::Color::Transparent);
    spriterender->SetTexture(GameEngine::eTexture::Obstacle);

}

void GameBoard::Update()
{
    sf::Vector2f pos = m_player->GetPos();

    float deltaTime = GameEngine::GameEngineMain::GetTimeDelta();

    float speed = 5.f; //Sets speed
    pos.y += speed * deltaTime;

    if (pos.x > 500.f)
    {
        pos.x = 0.f;
    }
    if (pos.y > 500.f)
    {
        pos.y = 0.f;
    }
    if (pos.x < 0.f)
    {
        pos.x = 500.f;
    }
    if (pos.y < 0.f)
    {
        pos.y = 500.f;
    }
    m_player->SetPos(pos);

    //ADD JUMP
    m_player->AddComponent<PlayerMovementComponent>();

}