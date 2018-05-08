/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <p2body.h>
#include "iostream"

p2Body::p2Body(p2BodyDef * bodydef)
{
	this->position = bodydef->position;
	this->linearVelocity = bodydef->position;
	this->type = bodydef->type;
}

p2Vec2 p2Body::GetLinearVelocity()
{
	return linearVelocity;
}

void p2Body::SetLinearVelocity(p2Vec2 velocity)
{
	linearVelocity = velocity;
}
float p2Body::GetAngularVelocity()
{
	return angularVelocity;
}

p2Vec2 p2Body::GetPosition()
{
	return position;
}

p2AABB p2Body::GetAABB()
{
	return p2AABB(this->aabb);
}

void p2Body::SetPosition(p2Vec2 v)
{
	position = position + v;
	aabb.SetPosition(v);
}

p2BodyType p2Body::GetType()
{
	return this->type;
}

p2Collider * p2Body::GetCollider()
{
	return nullptr;
}

	p2Collider * p2Body::CreateCollider(p2ColliderDef * colliderDef)
{
	if (p2CircleShape* d = dynamic_cast<p2CircleShape*>(colliderDef->shape)) 
	{
		this->aabb = p2AABB(GetPosition(), d->GetRadius());
	}
	else if (p2RectShape* d = dynamic_cast<p2RectShape*>(colliderDef->shape)) 
	{

	};
	return (this->collider);
}

	bool p2Body::CheckContact(p2Body * b)
	{
		return false;
	}
