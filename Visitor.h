#pragma once

#include "DynamicObject.h"
#include "Bomb.h"
#include "Plane.h"
#include "MyTools.h"


class Bomb;
class Plane;

class Visitor
{
public:
    virtual void log(Bomb* element) = 0;
    virtual void log(Plane* element) = 0;
};

class LogVisitor : public Visitor {
public:
    void log(Bomb* element) override;
    void log(Plane* element) override;
};



