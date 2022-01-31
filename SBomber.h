#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    void __fastcall DeleteDynamicObj(DynamicObject* pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);
    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};


class Command {         /////////////////////  ������� Command (����������� ����� Command)
protected:
    SBomber* _sb;
    Command(SBomber* sb) : _sb(sb) {}
public:
    Command() {}
    ~Command() {}
    virtual void execute() = 0;
};


class DeleteDynamicObjCommand : public Command {     ////////  ���������   DeleteDynamicObjCommand ,  ���������� � ����� SBomber.cpp � �������  CheckBombsAndGround
    std::vector<DynamicObject*> _vecDynamicObj;
    DynamicObject* _pBomb;
public:
    DeleteDynamicObjCommand(SBomber* sb, DynamicObject* pBomb) {
        _sb = sb;
        _vecDynamicObj = _sb->vecDynamicObj;
        _pBomb = pBomb;
    }
    void execute() override {
        _sb->DeleteDynamicObj(_pBomb);
    }
};


class DeleteStaticObjCommand : public Command {       ////////  ���������   DeleteStaticObjCommand ,  ���������� � ����� SBomber.cpp � �������  CheckDestoyableObjects
    std::vector<GameObject*> _vecStaticObj;
    GameObject* _pObj;
public:
    DeleteStaticObjCommand(SBomber* sb, GameObject* pObj) {
        _sb = sb;
        _vecStaticObj = _sb->vecStaticObj;
        _pObj = pObj;
    }
    void execute() override {
        _sb->DeleteStaticObj(_pObj);
    }
};


class DropBombCommand : public Command {              ////////  ���������   DropBombCheckBombsAndGround ,  ���������� � ����� SBomber.cpp � ������� ProcessKBHit()
public:
    DropBombCommand(SBomber* sb) /* : Command(sb) */ {
        _sb = sb;
    }
    void execute() override {
        _sb->DropBomb();
    }
};


