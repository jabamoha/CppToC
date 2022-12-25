#include "cpp2c_encapsulation_defs.h"




void _Z3BoxCE(Box* this){
    this->length = 1;
    this->height = 1;
    this->width = 1;
    _Z3Box7PrintEv(this);
}


void _Z3BoxCEd(Box* this ,double dim){
    this->length = dim;
    this->height = dim;
    this->width = dim;
    _Z3Box7PrintEv(this);
}


void _Z3BoxCEddd(Box* this ,double l, double w, double h){
    this->length = l;
    this->height = w;
    this->width = h;
    _Z3Box7PrintEv(this);
}


void _ZC3BoxEsbox(Box* this , Box* box){
    *this = *box;
}


Box* _Z3Box14AssignOperatorEsbox( Box* this , const Box* box){
    *this = *box;
    return this;
}


void _Z3BoxDEv(Box* this){
    printf("Box destructor, %f x %f x %f\n", this->height, this->width, this->length );
}


void _Z3Box7PrintEv(const Box* this){
    printf("Box: %f x %f x %f\n", this->length,this->height , this->width);
}

Box* _Z3Box18multAssignOperator(Box* this,double mult){
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;
    return this;
}



const char* _Z5Shelf7message = "The total volume held on the shelf is";


void _Z5ShelfCE(Shelf* this){}


void _Z5ShelfDE(Shelf* this){}


void _Z5Shelf6SetBoxEsiBox(Shelf* this , int index, const Box* dims)
{
    _Z3Box14AssignOperatorEsbox(&this->_Z5Shelf5boxes[index] , dims);
}


double _Z5Shelf9getVolumeECs(const Shelf* this ){
    double vol = 0;
    size_t i;
    for (i = 0; i < 3; ++i)
        vol += this->_Z5Shelf5boxes[i].width*this->_Z5Shelf5boxes[i].height*this->_Z5Shelf5boxes[i].length;
    return vol;
}


void _Z5Shelf5printEs(const Shelf* this){
    printf("%s %f\n", _Z5Shelf7message, _Z5Shelf9getVolumeECs(this));
}
