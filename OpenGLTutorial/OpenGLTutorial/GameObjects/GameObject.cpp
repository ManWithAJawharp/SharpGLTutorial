#include "GameObject.h"

using namespace GameObjects;

GameObject::GameObject()
{
	transform = Transform();
}

GameObject::GameObject(glm::vec3 pos)
{
	transform = Transform(pos, glm::vec3(0.0), glm::vec3(1.0));
}

GameObject::~GameObject()
{

}

glm::mat4 GameObject::GetTransformMatrix()
{
	glm::mat4 transformMatrix = glm::mat4();

	transformMatrix = glm::rotate(transformMatrix, transform.rotation.x, glm::vec3(1, 0, 0));
	transformMatrix = glm::rotate(transformMatrix, transform.rotation.y, glm::vec3(0, 1, 0));
	transformMatrix = glm::rotate(transformMatrix, transform.rotation.z, glm::vec3(0, 0, 1));

	transformMatrix = glm::scale(transformMatrix, transform.scale);

	transformMatrix = glm::translate(transformMatrix, transform.position);

	return transformMatrix;
}