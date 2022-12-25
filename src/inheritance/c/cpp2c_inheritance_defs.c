#include "cpp2c_inheritance_defs.h"
#include "memory.h"



void _Z9MaterialsCEs(Materials* this){}


void _Z9MaterialsDEs(Materials* this){}


void _Z9MaterialsCopyCEsMaterials(Materials* this, Materials* other){
    memcpy(this,other, sizeof(Materials));
}


Materials* _Z9MaterialsAssignOperatorEsMaterials(Materials* this, Materials* other){
    *this = *other;
    return this;
}


void _Z10Material_t5CopyCEs(Material_t* this , Material_t* other ){
    _Z9MaterialsCopyCEsMaterials((Materials*)this , (Materials*)other);
    memcpy((Box*)this + sizeof(Materials),(Box*)other + sizeof(Materials), sizeof(Material_t)- sizeof(Materials));
}


Material_t* _Z10Material_t14AssignOperatorEs(Material_t* this , Material_t* other ){
    _Z9MaterialsAssignOperatorEsMaterials((Materials*)this , (Materials*)other);
    memcpy((Box*)this + sizeof(Materials),(Box*)other + sizeof(Materials), sizeof(Material_t)- sizeof(Materials));
    return this;
}


void _Z10Material_tDEs(Material_t* this){
    _Z9MaterialsDEs((Materials*)this);
}



void _Z11PhysicalBoxCEsddd(PhysicalBox* this, double l, double w, double h){
    _Z3BoxCEddd((Box*)this, l, w, h);

    _Z9MaterialsCEs((Materials*)((Material_t*)this + sizeof(Box)));
    ((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE = OTHER;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE]);
    }

    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsdddTypes(PhysicalBox* this, double l, double w, double h, enum Types t){
    _Z3BoxCEddd((Box*)this, l, w, h);

    _Z9MaterialsCEs((Materials*)((Material_t*)this + sizeof(Box)));
    ((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE]);
    }

    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsTypes(PhysicalBox* this, enum Types t){
    _Z3BoxCE((Box*)this);

    _Z9MaterialsCEs((Materials*)((Material_t*)this + sizeof(Box)));
    ((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[((Material_t*)this + sizeof(Box))->_Z10Material_t8materialVE]);
    }

    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBox5CopyCEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _ZC3BoxEsbox((Box*)this,(Box*)other);
    _Z10Material_t5CopyCEs((Material_t*)this + sizeof(Box), (Material_t*)other + sizeof(Box));
}


PhysicalBox* _Z11PhysicalBox14AssifnOperatorEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _Z10Material_t5CopyCEs((Material_t*)this + sizeof(Box), (Material_t*)other + sizeof(Box));
    *this = *other;
    return this;
}


void _Z11PhysicalBoxDEs(PhysicalBox* this){
    {
        const char* names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox dtor, %f x %f x %f, %s; ", ((Box*)this)->length, ((Box*)this)->height, ((Box*)this)->width, names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);

        _Z10Material_tDEs((Material_t*)this + sizeof(Box));
        _Z3BoxDEv((Box*)this);
    }
}


void _Z11PhysicalBox6printpEs(const PhysicalBox* this){
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ", names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);
    }


    _Z3Box7PrintEv((Box*)this);
}



void _Z9WeightBoxCEsdddd(WeightBox* this, double l, double w, double h, double wgt){
    _Z3BoxCEddd((Box*)this, l, w, h);
    this->weight = wgt;
    _Z9WeightBox6PrintwEs(this);
}


void _Z9WeightBox5CopyCEsWeightBox(WeightBox* this, WeightBox* other){
    _Z3BoxCE((Box*)this);
    this->weight = other->weight;
    _Z9WeightBox6PrintwEs(this);
}


WeightBox* _Z9Weight14AssignOperatorECsWeightBox(WeightBox* this, WeightBox* other){
    this->weight = other->weight;
    return this;
}


void _Z9WeightBoxDs(WeightBox* this){
    printf("Destructing WeightBox; ");
    _Z9WeightBox6PrintwEs(this);
    _Z3BoxDEv((Box*)this);
}


void _Z9WeightBox6PrintwEs(const WeightBox* this){
    printf("WeightBox, weight: %f; ", this->weight);
    _Z3Box7PrintEv((Box*)this);
}
