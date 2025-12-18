#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Button
{
public:
    Button() = default;
    virtual ~Button() = default;
    Button(const sf::Vector2f& center, const sf::Vector2f& size, const std::string& textureFilename,
           const std::string& fragmentShaderFilename, const std::string& vertexShaderFilename);

    void setCenter(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);

    void render(sf::RenderWindow& window);

    bool isHovered() const;

private:
    sf::Shader shader_;
    sf::VertexBuffer vertexBuffer_;
    sf::Texture texture_;
    sf::Vector2f buttonCenter_ = sf::Vector2f{0.0f, 0.0f};
    sf::Vector2f buttonSize_ = sf::Vector2f{1.0f, 1.0f};
    sf::RenderStates renderStates_;
};
