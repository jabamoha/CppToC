#include "cpp2c_inheritance_defs.h"


void doMaterials(){

    Materials mat;
    Material_t mat1, mat2;
    typedef struct  { Materials mat; Material_t mat_t; char flag;}MatTest;
    printf("\n--- Start doMaterials() ---\n\n");

    _Z9MaterialsCEs(&mat);
    printf("Size of Materials: %lu\n", sizeof(Materials)+1);
    printf("Size of mat: %lu\n", sizeof(mat)+1);
    printf("Size of Materials::Types: %lu\n", sizeof(enum Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));


    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    _Z9MaterialsCEs((Materials*)(&mat1));
    (&mat1)->_Z10Material_t8materialVE = OTHER;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[(&mat1)->_Z10Material_t8materialVE]);
    }

    _Z9MaterialsCEs((Materials*)(&mat2));
    (&mat2)->_Z10Material_t8materialVE = METAL;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[(&mat2)->_Z10Material_t8materialVE]);
    }

    printf("\n--- End doMaterials() ---\n\n");

    _Z10Material_tDEs(&mat2);
    _Z10Material_tDEs(&mat1);
    _Z9MaterialsDEs(&mat);
}


void doPhysicalBox() {

    PhysicalBox pb1, pb2, pb3, pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    _Z11PhysicalBoxCEsdddTypes(&pb1, 8, 6, 4,PLASTIC);
    _Z11PhysicalBoxCEsTypes(&pb2, WOOD);
    _Z11PhysicalBoxCEsddd(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");

    _Z11PhysicalBox5CopyCEsPhysicalBox(&pb4,&pb1);

    _Z11PhysicalBox6printpEs(&pb4);
    _Z11PhysicalBox6printpEs(&pb1);

    printf("pb4 %s pb1\n", ((((const Box*)&pb4)->width == ((const Box*)&pb1)->width && ((const Box*)&pb4)->height == ((const Box*)&pb1)->height && ((const Box*)&pb4)->length == ((const Box*)&pb1)->length && ((Material_t*)&pb4+sizeof(Box))->_Z10Material_t8materialVE == ((Material_t*)&pb1+sizeof(Box))->_Z10Material_t8materialVE) ? "equals" : "does not equal"));

    printf("\npb4 is copy-assigned from pb3\n");

    _Z11PhysicalBox14AssifnOperatorEsPhysicalBox(&pb4, &pb3);
    _Z11PhysicalBox6printpEs(&pb4);
    _Z11PhysicalBox6printpEs(&pb3);

    printf("pb4 %s pb3\n",((((const Box*)&pb4)->width == ((const Box*)&pb3)->width && ((const Box*)&pb4)->height == ((const Box*)&pb3)->height && ((const Box*)&pb4)->length == ((const Box*)&pb3)->length && ((Material_t*)&pb4+sizeof(Box))->_Z10Material_t8materialVE == ((Material_t*)&pb3+sizeof(Box))->_Z10Material_t8materialVE)? "equals" : "does not equal"));

    printf("\n--- End doPhysicalBox() ---\n\n");

    _Z11PhysicalBoxDEs(&pb4);
    _Z11PhysicalBoxDEs(&pb3);
    _Z11PhysicalBoxDEs(&pb2);
    _Z11PhysicalBoxDEs(&pb1);
}


void doWeightBox() {
    WeightBox pw1, pw2, pw3, pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    _Z9WeightBoxCEsdddd(&pw1, 8, 6, 4, 25);
    _Z9WeightBoxCEsdddd(&pw2, 1, 2, 3, 0.0);
    _Z9WeightBoxCEsdddd(&pw3, 10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");

    _Z9WeightBox5CopyCEsWeightBox(&pw4, &pw1);
    _Z9WeightBox6PrintwEs(&pw4);
    _Z9WeightBox6PrintwEs(&pw1);

    printf("pw4 %s pw1\n",(((const Box*)&pw1)->width == ((const Box*)&pw4)->width && ((const Box*)&pw1)->height == ((const Box*)&pw4)->height && ((const Box*)&pw1)->length == ((const Box*)&pw4)->length && pw1.weight==pw4.weight)? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    _Z9Weight14AssignOperatorECsWeightBox(&pw4, &pw3);
    _Z9WeightBox6PrintwEs(&pw4);
    _Z9WeightBox6PrintwEs(&pw3);
    printf("pw4 %s pw3\n", (((const Box*)&pw4)->width == ((const Box*)&pw3)->width && ((const Box*)&pw4)->height == ((const Box*)&pw3)->height && ((const Box*)&pw4)->length == ((const Box*)&pw3)->length && pw4.weight==pw3.weight)? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    _Z9WeightBoxDs(&pw4);
    _Z9WeightBoxDs(&pw3);
    _Z9WeightBoxDs(&pw2);
    _Z9WeightBoxDs(&pw1);
}


int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();
    doPhysicalBox();
    doWeightBox();

    printf("\n--- End main() ---\n\n");
    return 0;
}