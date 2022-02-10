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

    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;

    int16_t score;

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    GroundCommon* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<Bomb*> FindAllBombs() const;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
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


template <typename T>
class IIterator {              // ����������� ��������
protected:
    std::vector<T> arr;
    int index;
    int size;

public:
    virtual T get() const = 0;
    virtual void next() = 0;
    virtual bool operator!=(const T) = 0;
    virtual bool is_end() = 0;
};



template <typename T, typename C> 
class ArrIterator : public IIterator<T> {               // �������� , ��������� ��������� ��� SBomber
public:
    ArrIterator(std::vector<T> _arr) : IIterator<T>() {
        this->arr = _arr;
        this->index = 0;
        this->size = this->arr.size();
    }

    virtual C get() const override {
        T obj = this->index < this->size ? this->arr[this->index] : nullptr;
        return dynamic_cast<C>(obj);
    }

    void next() override {
        this->index++;
    }

    virtual bool is_end() {
        return this->index >= this->size;
    }

    virtual bool operator!=(const T t2) override {
        return dynamic_cast<T>(t2) != get();
    }

 };





