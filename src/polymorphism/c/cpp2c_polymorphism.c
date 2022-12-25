#include "cpp2c_polymorphism_defs.h"
#include "stdlib.h"

void doPrePostFixer()
{
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");
    _Z12PrePostFixerCEs(&angleBrackets, "<<< ", " >>>");
    _Z12PrePostFixer12VirtualPrintEkc(&angleBrackets, "Hello World!");
    _Z12PrePostFixer12VirtualPrintEslc(&angleBrackets, -777, '\0');
    _Z12PrePostFixer12VirtualPrintEslc(&angleBrackets, 350, '#');
    _Z12PrePostFixer12VirtualPrintEslc(&angleBrackets,(long int)(3.14), '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    _Z12PrePostFixer8VirtualDEs(&angleBrackets);
}


void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    _Z18PrePostDollarFixerCEskcpkcp(&asterisks,"***** ", " *****" );
    _Z18PrePostDollarFixer5printEksic(&asterisks,-777 ,DEFAULT_SYMBOL);
    _Z18PrePostDollarFixer5printEksic(&asterisks,350, '#');
    _Z18PrePostDollarFixer5printEksdc(&asterisks,3.14f,DEFAULT_SYMBOL);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _Z18PrePostDollarFixerDEs(&asterisks);
}


void doPrePostChecker()
{
    PrePostChecker check;
    printf("\n--- start doPrePostChecker() ---\n\n");

    _Z14PrePostCheckerCEs(&check);
    _Z14PrePostChecker24printThisSymbolUsingFuncEs(&check);
    _Z14PrePostChecker23printThisSymbolDirectlyEs(&check);
    _Z14PrePostChecker31printDollarSymbolByCastDirectlyEs(&check);
    _Z14PrePostChecker32printDollarSymbolByScopeDirectlyEs(&check);
    _Z14PrePostChecker32printDollarSymbolByCastUsingFuncEs(&check);
    _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncEs(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    _Z14PrePostCheckerDEs(&check);
}


void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    _Z23PrePostFloatDollarFixerCEskcpkcp(&hashes, "### ", " ###");
    _Z23PrePostFloatDollarFixer5printEksf(&hashes, -777);
    _Z23PrePostFloatDollarFixer5printEksfc(&hashes, 350, '#');
    _Z23PrePostFloatDollarFixer5printEksf(&hashes, 3.14f);

    _Z18PrePostDollarFixer5CopyCEskPrePostDollarFixer(&hashes2, (const PrePostDollarFixer *) &hashes);
    _Z18PrePostDollarFixer5printEksdc((PrePostDollarFixer*)&hashes2, 7.5, DEFAULT_SYMBOL);
    _Z18PrePostDollarFixer5printEksic((const PrePostDollarFixer *) &hashes2, 100, DEFAULT_SYMBOL);

    printf("\n--- end doPrePostFloatDollarFixer() ---\n\n");

    _Z18PrePostDollarFixerDEs(&hashes2);
    _Z23PrePostFloatDollarFixerDEs(&hashes);
}

void runAsPrePostFixerRef(PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
    ((pPrintLong)((((TextFormatter*)pp)->PTvptr)[printEklc]))(pp,123,'\0');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}


void runAsPrePostDollarFixerRef(PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
    _Z18PrePostDollarFixer5printEksic(pp, 123 , '$' );
    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}


void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");
    _Z18PrePostDollarFixer5printEksic(&pp, 123,'$');
    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}


void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    _Z16PrePostHashFixer5printEsic(pp, 123, '#');
    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1, m2, m3, m4;
    printf("\n--- start doMultiplier() ---\n\n");

    _Z20DefaultTextFormatterCEs((DefaultTextFormatter*)&m1);
    m1._Z10Multiplier5timesVE = 3;
    printf("--- Multiplier CTOR: times = %d\n", m1._Z10Multiplier5timesVE);

    _Z20DefaultTextFormatterCEs((DefaultTextFormatter*)&m2);
    m2._Z10Multiplier5timesVE = 5;
    printf("--- Multiplier CTOR: times = %d\n", m2._Z10Multiplier5timesVE);

    _Z20DefaultTextFormatterCEskDefaultTextFormatter((DefaultTextFormatter*)&m3, (DefaultTextFormatter*)&m1);
    m3._Z10Multiplier5timesVE = m1._Z10Multiplier5timesVE;

    _Z20DefaultTextFormatterCEskDefaultTextFormatter((DefaultTextFormatter*)&m4, (DefaultTextFormatter*)&m2);
    m4._Z10Multiplier5timesVE = m2._Z10Multiplier5timesVE;

    _Z10Multiplier5printEs(&m1, "abc ");
    _Z10Multiplier5printEs(&m2, "abc ");
    _Z10Multiplier5printEs(&m3, "abc ");
    _Z10Multiplier5printEs(&m4, "abc ");

    printf("\n--- end doMultiplier() ---\n\n");

    ((TextFormatter*)(&m4))->PTvptr = DefaultTextFormatterVPTR;
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)(&m4))->_Z10Multiplier5timesVE);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)(&m4));

    ((TextFormatter*)(&m3))->PTvptr = DefaultTextFormatterVPTR;
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)(&m3))->_Z10Multiplier5timesVE);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)(&m3));

    ((TextFormatter*)(&m2))->PTvptr = DefaultTextFormatterVPTR;
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)(&m2))->_Z10Multiplier5timesVE);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)(&m2));

    ((TextFormatter*)(&m1))->PTvptr = DefaultTextFormatterVPTR;
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)(&m1))->_Z10Multiplier5timesVE);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)(&m1));

}

void doFormatterArray() {
    int i;
    PrePostDollarFixer PrePostDollarFixerTemp;
    Multiplier MultiplierTemp;
    PrePostChecker PrePostCheckerTemp;
    DefaultTextFormatter formatters[3];

    printf("\n--- start doFormatterArray() ---\n\n");

    _Z18PrePostDollarFixerCEskcpkcp(&PrePostDollarFixerTemp, "!!! ", " !!!");
    _Z20DefaultTextFormatterCEskDefaultTextFormatter(&formatters[0],(const DefaultTextFormatter *) &PrePostDollarFixerTemp);
    _Z18PrePostDollarFixerDEs(&PrePostDollarFixerTemp);

    _Z20DefaultTextFormatterCEs((DefaultTextFormatter *) &MultiplierTemp);
    ((TextFormatter*)&MultiplierTemp)->PTvptr =MultiplierVPTR;

    MultiplierTemp._Z10Multiplier5timesVE = 4;
    printf("--- Multiplier CTOR: times = %d\n", MultiplierTemp._Z10Multiplier5timesVE);
    _Z20DefaultTextFormatterCEskDefaultTextFormatter(&formatters[1], (const DefaultTextFormatter *) &MultiplierTemp);
    ((TextFormatter*)(&MultiplierTemp))->PTvptr = DefaultTextFormatterVPTR;
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)(&MultiplierTemp))->_Z10Multiplier5timesVE);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)(&MultiplierTemp));



    _Z14PrePostCheckerCEs(&PrePostCheckerTemp);
    _Z20DefaultTextFormatterCEskDefaultTextFormatter(&formatters[2],(const DefaultTextFormatter *) &PrePostCheckerTemp);
    _Z14PrePostCheckerDEs(&PrePostCheckerTemp);

    for (i = 0; i < 3; ++i) {
        _Z20DefaultTextFormatter12VirtualPrintEkc(&formatters[i], "Hello World!");
    }

    printf("\n--- end doFormatterArray() ---\n\n");

    for (i = 2; i >= 0; --i) {
        ((pDCtor) ((((TextFormatter *) (&formatters[i]))->PTvptr)[Dtor]))(&formatters[i]);
    }
}


void doFormatterPtrs(){
    int i;
    DefaultTextFormatter* pfmt[3];
    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0] = (DefaultTextFormatter*)malloc(sizeof(PrePostDollarFixer));
    pfmt[1] = (DefaultTextFormatter*)malloc(sizeof(Multiplier));
    pfmt[2] = (DefaultTextFormatter*)malloc(sizeof(PrePostChecker));

    _Z18PrePostDollarFixerCEskcpkcp((PrePostDollarFixer*)pfmt[0], "!!! ", " !!!");
    _Z20DefaultTextFormatterCEs((DefaultTextFormatter*)pfmt[1]);
    ((TextFormatter*)((pfmt[1])))->PTvptr = MultiplierVPTR;
    ((Multiplier*)(pfmt[1]))->_Z10Multiplier5timesVE = 4;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)(pfmt[1]))->_Z10Multiplier5timesVE);

    _Z14PrePostCheckerCEs((PrePostChecker*)pfmt[2]);

    for(i=0; i<3 ; i++){
        ((PrintChar) ((((TextFormatter *) (pfmt[i]))->PTvptr)[printEpkc]))((pfmt[i]), "Hello World!");
    }

    for (i = 2; i >= 0; --i) {
        ((pDCtor) ((((TextFormatter *) (pfmt[i]))->PTvptr)[Dtor]))(pfmt[i]);
        free(pfmt[i]);
    }
    printf("\n--- end doFormatterPtrs() ---\n\n");
}



void doFormatterDynamicArray()
{
    int i;
    DefaultTextFormatter* formatters;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters = generateFormatterArray();

    for (i = 0; i < 3; ++i)
        _Z20DefaultTextFormatter12VirtualPrintEkc(&formatters[i], "Hello World!");

    for (i = 2; i >= 0; --i) {
        _Z20DefaultTextFormatter8VirtualDEs(&formatters[i]);
    }
    printf("\n--- end doFormatterDynamicArray() ---\n\n");
}


int main() {
    PrePostHashFixer hfix;
    PrePostDollarFixer temp;

    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();
    _Z16PrePostHashFixerCEsi(&hfix, 4);
    runAsPrePostFixerRef((PrePostFixer *) &hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer *) &hfix);
    _Z18PrePostDollarFixer5CopyCEskPrePostDollarFixer(&temp, (const PrePostDollarFixer *) &hfix);
    runAsPrePostDollarFixerObj(temp);
    _Z18PrePostDollarFixerDEs(&temp);
    runAsPrePostHashFixerRef(&hfix);
    doMultiplier();
    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    _Z16PrePostHashFixer8VirtualDEs(&hfix);
    return 0;
}

