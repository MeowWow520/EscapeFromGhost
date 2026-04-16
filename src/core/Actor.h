#ifndef ACTOR_H
#define ACTOR_H
#include "ObjectWorld.h"



class Actor : public ObjectWorld
{
protected:
    // 速度
    glm::vec2 velocity_;
    // 最大速度大小
    float maxSpeed_;

public:
    
    glm::vec2 getVelocity() const { return velocity_; }
    void setVelocity(const glm::vec2 &vc) { velocity_ = vc; }
    float getMaxSpeed() const { return maxSpeed_; }
    void setMaxSpeed(float maxs) { maxSpeed_ = maxs; }
};

#endif // ACTOR_H