#include "Physics.h"

Collision::Collision() {
	for (int i = 0; i < 200; i++) {
		AllGameObjects[i] = nullptr;
	}
	minCheckDistance = 50;
}

Collision::~Collision() {

}

void Collision::Update() {
	for (unsigned int i = 0; i < 200; i++) {
		if (AllGameObjects[i] != nullptr) {
			for (unsigned int j = i + 1; j < 200; j++) {
				if (AllGameObjects[j] != nullptr) {
					if (std::abs(AllGameObjects[i]->m_xPos - AllGameObjects[j]->m_xPos) < minCheckDistance) {
						int hwi = (AllGameObjects[i]->width / 2);
						int hwj = (AllGameObjects[j]->width / 2);
						int hhi = (AllGameObjects[i]->height / 2);
						int hhj = (AllGameObjects[j]->height / 2);
						int absoluteDifx = abs((AllGameObjects[i]->m_xPos + hwi) - (AllGameObjects[j]->m_xPos + hwj));
						int abosluteDify = abs((AllGameObjects[i]->m_yPos + hhi) - (AllGameObjects[j]->m_yPos + hhj));
						if (absoluteDifx < hwi + hwj) {
							if (abosluteDify < hhi + hhj) {
								AllGameObjects[i]->onCollision(AllGameObjects[j]);
								AllGameObjects[j]->onCollision(AllGameObjects[i]);
							}
						}
					}
				}
			}
		}
	}
}

void Collision::AddObjectToArray(GameObject* gameObject, int place) {
	AllGameObjects[place] = gameObject;
	std::cout << AllGameObjects[place] << std::endl;
}
