#pragma once

#include <stdint.h>
#include <vector>
#include <memory>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:
	const uint16_t score = 40;
};

class HouseBuild : public DestroyableGroundObject {               // общий класс строитель
public:
	HouseBuild(double nx, double ny, uint16_t widthN) {
		SetWidth(widthN);
		SetPos(nx, ny);
	}
	bool isInside(double x1, double x2) const override;
	inline uint16_t GetScore() const override { return score; }
private:
	const uint16_t score = 40;
};

class HouseBody : public HouseBuild {                             // строим корпус дома
public:
	HouseBody(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};

class HouseChimney : public HouseBuild {                          // строим дымоходную трубу
public:
	HouseChimney(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};

class HouseWindow : public HouseBuild {                           // строим окно     
public:
	HouseWindow(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};



template <typename T>
class Director {                             // собираем весь дом
public:
	std::vector<HouseBuild*> vv;
	Director() { vv.clear(); }
	void Add(HouseBuild* hb) {
		vv.push_back(hb);
	}
	void Apply(std::vector<T>& dest) {
		for (int i = 0; i < vv.size(); i++)
			dest.push_back(vv.at(i));
	}
};



