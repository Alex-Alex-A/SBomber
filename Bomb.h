#pragma once

#include "DynamicObject.h"
#include "Visitor.h"


class Bomb : public DynamicObject {
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках
	void Draw() const override;
    void Accept(Visitor& v);

private:
};

class BombDecorator : public Bomb {    // общий класс декорирования поведения бомбы
protected:
    Bomb _bm;
public:
    BombDecorator() {}
    BombDecorator(Bomb* bm) {
        _bm = *bm;
    }
};

class BombDecoratorNewDraw : public BombDecorator {     // декорируем прорисовку бомбы     реализация в Bomb.cpp
public:
    BombDecoratorNewDraw(Bomb* bm) {
        _bm = *bm;
    }
    void Draw() const override;
    void Move(uint16_t time) {
        BombDecorator::Move(time);
    }
};

class BombDecoratorNewSpeed : public BombDecorator {     // декорируем движение бомбы     реализация в Bomb.cpp
public:
    BombDecoratorNewSpeed(Bomb* bm) { _bm = *bm; }
    void Draw() const override;
    void Move(uint16_t time) override {
        DynamicObject::Move(time * 4);
    }
};



