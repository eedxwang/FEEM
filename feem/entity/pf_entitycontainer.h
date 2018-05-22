#ifndef PF_ENTITYCONTAINER_H
#define PF_ENTITYCONTAINER_H

#include "pf_entity.h"
#include <QList>

//2018-02-15
//by Poofee
//该类实现entity的组合功能，也就是一个数组列表

class PF_EntityContainer: public PF_Entity
{
public:
    PF_EntityContainer(PF_EntityContainer * parent=nullptr, bool owner=true);
    ~PF_EntityContainer() override;

    virtual void clear();

    bool isAtomic() const override{
        return false;
    }
    bool isContainer() const override{
        return true;
    }

    virtual void addEntity(PF_Entity* entity);
    void draw(QPainter *painter, PF_GraphicView *view) override;
protected:
    QList<PF_Entity*> entities;//保存所有实体
private:
    bool autoDelete;
};

#endif // PF_ENTITYCONTAINER_H
