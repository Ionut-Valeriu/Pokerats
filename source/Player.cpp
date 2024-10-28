//
// Created by ionut on 22.10.2024.
//

#include "Player.h"

#include <iostream>

void Player::setAction(Actions &action) {
    std::cout << action.name() << " " << action.type() << std::endl;
    if (action.type() == "START") {
        if (action.name() == "UP") {
            m_velocity.y = -m_speed;
        } else if (action.name() == "DOWN") {
            m_velocity.y = m_speed;
        } else if (action.name() == "LEFT") {
            m_velocity.x = -m_speed;
        } else if (action.name() == "RIGHT") {
            m_velocity.x = m_speed;
        } else {
            std::cerr << "[Player::setAction - START] Invalid action name: " << action.name() << std::endl;
        }
    } else if (action.type() == "END") {
             if (action.name() == "UP"   ) { if (m_velocity.y < 0) { m_velocity.y = 0; } }
        else if (action.name() == "DOWN" ) { if (m_velocity.y > 0) { m_velocity.y = 0; } }
        else if (action.name() == "LEFT" ) { if (m_velocity.x < 0) { m_velocity.x = 0; } }
        else if (action.name() == "RIGHT") { if (m_velocity.x > 0) { m_velocity.x = 0; } }
        else {
            std::cerr << "[Player::setAction - END] Invalid action name: " << action.name() << std::endl;
        }
    } else {
        std::cerr << "[Player::setAction] Invalid action type: " << action.type() << std::endl;
    }

    std::cout << m_velocity.x << " " << m_velocity.y << std::endl;

}
