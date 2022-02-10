
#include <iostream>
#include <vector>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}


void Bomb::Accept(Visitor& v) {
    v.log(this);
}


void BombDecoratorNewDraw::Draw() const {
    MyTools::SetColor(CC_LightCyan);
    GotoXY(x, y);
    cout << "&";
}


void BombDecoratorNewSpeed::Draw() const {
    BombDecorator::Draw();
    MyTools::SetColor(CC_LightCyan);
    GotoXY(x, y);
    cout << "&";
}
