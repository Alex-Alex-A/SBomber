#pragma once

#include <vector>

#include "GameObject.h"

//=============================================================================================================

enum CraterSize 
{ 
	SMALL_CRATER_SIZE = 9 
};

//=============================================================================================================

class Crater : public GameObject
{
public:

	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;

private:

};

//=============================================================================================================

class GroundCommon : public GameObject {                   // ����������� ����� "�����"
protected:
	std::vector<Crater> vecCrates;
public:
	GroundCommon() { }

	virtual void Draw() const = 0;

	void AddCrater(double xn);

	bool __fastcall isInsideAnyCrater(double x) const;
};

//=============================================================================================================

class Ground : public GroundCommon                         // ����� ������� "�����"
{
public:

	Ground() { }
	void Draw() const override;
};

//=============================================================================================================

class WinterGround : public GroundCommon                   // ����� ������ "�����"
{
public:

	WinterGround() { }
	void Draw() const override;
};




















