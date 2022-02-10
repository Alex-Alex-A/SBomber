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

class HouseBuild : public DestroyableGroundObject {               // ����� ����� ���������
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

class HouseBody : public HouseBuild {                             // ������ ������ ����
public:
	HouseBody(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};

class HouseChimney : public HouseBuild {                          // ������ ���������� �����
public:
	HouseChimney(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};

class HouseWindow : public HouseBuild {                           // ������ ����     
public:
	HouseWindow(double nx, double ny, uint16_t widthN) : HouseBuild(nx, ny, widthN) {}
	void Draw() const override;
};



template <typename T>
class Director {                             // �������� ���� ���
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



