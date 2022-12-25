#include <stdio.h>

typedef void*(*TYPE)(void*);
typedef void(*PrintLC)(const void*, long, char);
typedef void(*pDCtor)(void*);
typedef void(*PrintChar)(void*,const char*);
typedef void(*pPrintLong)(void*,long,char);
typedef char(*GetDefaultSymbol)(void*);



/*/// TextFormatter ///////////*/
extern int next_id;
extern char DEFAULT_SYMBOL;
extern void* (*TextFormatterVPTR[])(void*) ;
extern void* (*DefaultTextFormatterVPTR[])(void*);
extern void* (*PrePostFixerVPTR[])(void*);
extern void* (*PrePostDollarFixerVPTR[])(void*);
extern void* (*PrePostHashFixerVPTR[])(void*);
extern void* (*PrePostFloatDollarFixerVPTR[])(void*);
extern void* (*PrePostCheckerVPTR[])(void*);
extern void* (*MultiplierVPTR[])(void*);

enum Function{
    Dtor,
    printEpkc,
    printEklc,
    getDefaultSymbol
};


typedef struct {
    void*(** PTvptr)(void *);
}TextFormatter;


void _Z13TextFormatterCEs(TextFormatter* this);
void _Z13TextFormatter8VirtualDEs(void * this);
void _Z13TextFormatter12VirtualPrintEkc(const void * this, const char* text);



/*/// DefaultTextFormatter Defs ///////////*/

typedef struct{
    TextFormatter _Z20DefaultTextFormatter13textFormatterVE;
    /*Ider _Z20DefaultTextFormatter4iderVE;*/
    int id;
}DefaultTextFormatter;


void _Z20DefaultTextFormatterCEs(DefaultTextFormatter* this);
void _Z20DefaultTextFormatterCEskDefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*  other);
DefaultTextFormatter* _Z20DefaultTextFormatter14AssignOperatorEskDefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*  other);
void _Z20DefaultTextFormatter8VirtualDEs(void * this);
void _Z20DefaultTextFormatter12VirtualPrintEkc(const void * this, const char* text);



DefaultTextFormatter* generateFormatterArray();

/*/// PrePostFixer ///////////*/

typedef struct {

    DefaultTextFormatter _Z12PrePostFixer20defaultTextFormatterEV;
    const char* pre;
    const char* post;

}PrePostFixer;


void _Z12PrePostFixerCEs(PrePostFixer* this, const char* prefix, const char* postfix);
void _Z12PrePostFixerCopyCEs(PrePostFixer* this,PrePostFixer* other);
void _Z12PrePostFixer8VirtualDEs(void * this);
void _Z12PrePostFixer12VirtualPrintEkc(const void * this, const char* text);

void _Z12PrePostFixer12VirtualPrintEslc(const void * this, long num, char symbol);
char _Z12PrePostFixer23VirtualgetDefaultSymbol(const void * this);


/*/// PrePostDollarFixer ///////////*/

typedef struct {
    PrePostFixer _Z18PrePostDollarFixer12prePostFixer;

}PrePostDollarFixer;

void _Z18PrePostDollarFixerCEskcpkcp(PrePostDollarFixer* this, const char* prefix, const char* postfix);
void _Z18PrePostDollarFixer5CopyCEskPrePostDollarFixer(PrePostDollarFixer* this, const PrePostDollarFixer* other);
void _Z18PrePostDollarFixerDEs(void * this);
void _Z18PrePostDollarFixer5printEksic(const PrePostDollarFixer* this, int num, char symbol) ;
void _Z18PrePostDollarFixer5printEkslc(const void * this, long num, char symbol);
void _Z18PrePostDollarFixer5printEksdc(const PrePostDollarFixer* this, double num, char symbol);
char _Z18PrePostDollarFixer16getDefaultSymbolEks(const void * this);


/*/// PrePostHashFixer ///////////*/

typedef struct {
    PrePostDollarFixer _Z16PrePostHashFixer18PrePostDollarFixerEV;
    int precision;
}PrePostHashFixer;


void _Z16PrePostHashFixerCEsi(PrePostHashFixer* this, int prc);
void _Z16PrePostHashFixer8VirtualDEs(void* this);
void _Z16PrePostHashFixer5printEsic(const PrePostHashFixer* this, int num, char symbol);
void _Z16PrePostHashFixer12VirtualprintEslc(const void * this, long num, char symbol);
char _Z16PrePostHashFixer16getDefaultSymbol(const void * this);


/*/// PrePostFloatDollarFixer ///////////*/

typedef struct {
    PrePostDollarFixer _Z23PrePostFloatDollarFixer18PrePostDollarFixerEV;

}PrePostFloatDollarFixer;

void _Z23PrePostFloatDollarFixerCEskcpkcp(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void _Z23PrePostFloatDollarFixerCopyCEskPrePostFloatDollarFixer(PrePostFloatDollarFixer* this,const PrePostFloatDollarFixer* other);
void _Z23PrePostFloatDollarFixerDEs(void * this);
void _Z23PrePostFloatDollarFixer5printEksf(const PrePostFloatDollarFixer* this, float num);
void _Z23PrePostFloatDollarFixer5printEksfc(const PrePostFloatDollarFixer* this, float num, char symbol) ;
char _Z23PrePostFloatDollarFixer16getDefaultSymbol(const void* this);


/*/// PrePostChecker ///////////*/

typedef struct {
    PrePostFloatDollarFixer _Z14PrePostChecker23PrePostFloatDollarFixerEV;
}PrePostChecker;

void _Z14PrePostCheckerCEs(PrePostChecker* this);
void _Z14PrePostCheckerDEs(PrePostChecker* this);

void _Z14PrePostChecker24printThisSymbolUsingFuncEs(const PrePostChecker* this);
void _Z14PrePostChecker23printThisSymbolDirectlyEs(const PrePostChecker* this);
void _Z14PrePostChecker32printDollarSymbolByCastUsingFuncEs(const PrePostChecker* this);
void _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncEs(const PrePostChecker* this);
void _Z14PrePostChecker31printDollarSymbolByCastDirectlyEs(const PrePostChecker* this);
void _Z14PrePostChecker32printDollarSymbolByScopeDirectlyEs(const PrePostChecker* this);


/*/// Multiplier ///////////*/

typedef struct {
    DefaultTextFormatter _Z10Multiplier20DefaultTextFormatterVE;
    int _Z10Multiplier5timesVE;
}Multiplier;


void _Z10Multiplier8VirtualDEs(void * this);
void _Z10Multiplier5printEs(const void* this, const char*);