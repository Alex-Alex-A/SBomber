#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 30;
};



class TankAdaptee {               //   новый вид танка
public:
	TankAdaptee() : x(0.0), y(0.0), width(0) { }
	void Paint() {  /* do something */  };
	bool __fastcall isInRange(double x1, double x2) const { /* do something */ };
	inline uint16_t GetScore() const { return score; }
	inline void SetPos(double nx, double ny) { x = nx; y = ny; }
	inline double GetY() const { return y; }
	inline double GetX() const { return x; }
	inline void SetWidth(uint16_t widthN) { width = widthN; }
	inline uint16_t GetWidth() const { return width; }
protected:
	double x, y;
	uint16_t width;
	const uint16_t score = 30;
};


class TankAdapter : public DestroyableGroundObject {       // адаптируем новый вид танка под старый
private:
	TankAdaptee* tka;
public:
	TankAdapter(TankAdaptee* _tka) : tka(_tka) {}
	~TankAdapter() { delete tka;  }
	void Draw() const override {
		tka->Paint();
	}
	bool __fastcall isInside(double x1, double x2) const override {
		tka->isInRange(x1, x2);
	}

	void SetPos(double nx, double ny) override {
		tka->SetPos(nx, ny);
	}

	double GetY() const {  
		tka->GetY();
	}
	
	double GetX() const { 
		tka->GetX();
	}

	void SetWidth(uint16_t widthN) { 
		tka->SetWidth(widthN);
	}

	uint16_t GetWidth() const {
		tka->GetWidth();
	}

};







