#pragma once

#include "DynamicObject.h"
#include "Visitor.h"


class Bomb : public DynamicObject {
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����
	void Draw() const override;
    void Accept(Visitor& v);

private:
};

class BombDecorator : public Bomb {    // ����� ����� ������������� ��������� �����
protected:
    Bomb _bm;
public:
    BombDecorator() {}
    BombDecorator(Bomb* bm) {
        _bm = *bm;
    }
};

class BombDecoratorNewDraw : public BombDecorator {     // ���������� ���������� �����     ���������� � Bomb.cpp
public:
    BombDecoratorNewDraw(Bomb* bm) {
        _bm = *bm;
    }
    void Draw() const override;
    void Move(uint16_t time) {
        BombDecorator::Move(time);
    }
};

class BombDecoratorNewSpeed : public BombDecorator {     // ���������� �������� �����     ���������� � Bomb.cpp
public:
    BombDecoratorNewSpeed(Bomb* bm) { _bm = *bm; }
    void Draw() const override;
    void Move(uint16_t time) override {
        DynamicObject::Move(time * 4);
    }
};



