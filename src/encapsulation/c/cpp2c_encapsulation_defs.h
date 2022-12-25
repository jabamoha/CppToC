#include <stdbool.h>
#include <stdio.h>

/*/// Box ///////////*/

typedef struct {
    double length;
    double width;
    double height;
}Box;

void _Z3BoxCE(Box* this);
void _Z3BoxCEd(Box* this ,double dim);
void _Z3BoxCEddd(Box* this ,double l, double w, double h);
void _Z3BoxDEv(Box* this);
void _ZC3BoxEsbox(Box* this , Box* box);
Box* _Z3Box14AssignOperatorEsbox( Box* this , const Box* box);
Box* _Z3Box18multAssignOperator(Box* this,double mult);
void _Z3Box7PrintEv(const Box* this);


/*Box multOperatorKboxd(const Box* box, double mult);
Box multOperatordKbox(double mult, const Box* box);*/

/*/// Shelf ///////////*/

extern const char* _Z5Shelf7message;

typedef struct {
    Box _Z5Shelf5boxes[3];
}Shelf;

void _Z5ShelfCE(Shelf* this);
void _Z5ShelfDE(Shelf* this);
void _Z5Shelf6SetBoxEsiBox(Shelf* this , int index, const Box* dims);
double _Z5Shelf9getVolumeECs(const Shelf* this );
void _Z5Shelf5printEs(const Shelf* this);

