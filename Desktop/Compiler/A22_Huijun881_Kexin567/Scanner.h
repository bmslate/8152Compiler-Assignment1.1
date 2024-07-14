/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2024
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
#
# ECHO "=---------------------------------------="
# ECHO "|  COMPILERS - ALGONQUIN COLLEGE (S24)  |"
# ECHO "=---------------------------------------="
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@           %&@@@@@@@@@@@     @@    ”
# ECHO "    @@       @%% (@@@@@@@@@  @     @@    ”
# ECHO "    @@      @& @   @ @       @     @@    ”
# ECHO "    @@     @ @ %  / /   @@@@@@     @@    ”
# ECHO "    @@      & @ @  @@              @@    ”
# ECHO "    @@       @/ @*@ @ @   @        @@    ”
# ECHO "    @@           @@@@  @@ @ @      @@    ”
# ECHO "    @@            /@@    @@@ @     @@    ”
# ECHO "    @@     @      / /     @@ @     @@    ”
# ECHO "    @@     @ @@   /@/   @@@ @      @@    ”
# ECHO "    @@     @@@@@@@@@@@@@@@         @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@         S O F I A           @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "                                         "
# ECHO "[READER SCRIPT .........................]"
# ECHO "                                         "
*/

/*
************************************************************
* File name: Scanner.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A22, A32.
* Date: May 01 2024
* Purpose: This file is the main header for Scanner (.h)
* Function list: (...).
*************************************************************/

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#include "Reader.h"
#endif

#ifndef SCANNER_H_
#define SCANNER_H_

#ifndef NULL
#include <_null.h> /* NULL pointer constant is defined there */
#endif

/*#pragma warning(1:4001) */	/*to enforce C89 type comments  - to make //comments an warning */

/*#pragma warning(error:4001)*/	/* to enforce C89 comments - to make // comments an error */

/* Constants */
#define VID_LEN 20  /* variable identifier length */
#define ERR_LEN 40  /* error message length */
#define NUM_LEN 5   /* maximum number of digits for IL */

#define RTE_CODE 1  /* Value for run-time error */

/* TO_DO: Define the number of tokens */
#define NUM_TOKENS 16

/* TO_DO: Define Token codes - Create your token classes */
enum TOKENS {
	ERR_T,		/*  0: Error token */
	/*MNID_T,		  1: Method name identifier token (start: &) */
	ID_T,       /*1: ID is a variable name or functio name.*/
	INL_T,		/*  2: Integer literal token */
	FLT_T,      /*3: Floating points token*/
	STR_T,		/*  4: String literal token */
	LPR_T,		/*  5: Left parenthesis token */
	RPR_T,		/*  6: Right parenthesis token */
	LBR_T,		/*  7: Left brace token */
	RBR_T,		/*  8: Right brace token */
	KW_T,		/*  9: Keyword token */
	RTE_T,		/*  10: Run-time error token */
	SEOF_T,		/* 11: Source end-of-file token */
	/* CMT_T		11: Comment token */
	MLC_T,      /*12: Multi line comments*/
	SLC_T,       /*13: Single line comments*/
	ASSMARK_T,   /*14 : a mark to assign one value or function to a variable name*/
	COMMA_T		/*15: a comma*/
};

/* TO_DO: Define the list of keywords */
static PowerR_string tokenStrTable[NUM_TOKENS] = {
		"ERR_T",		/*  0: Error token */
		"ID_T",       /* 1:ID is a variable name or functio name.*/
		"INL_T",		/*  2: Integer literal token */
		"FLT_T",      /*3: Floating points token*/
		"STR_T",		/*  4: String literal token */
		"LPR_T",		/*  5: Left parenthesis token */
		"RPR_T",		/*  6: Right parenthesis token */
		"LBR_T",		/*  7: Left brace token */
		"RBR_T",		/*  8: Right brace token */
		"KW_T",		/*  9: Keyword token */
		"RTE_T",		/*  10: Run-time error token */
		"SEOF_T",		/* 11: Source end-of-file token */
		"MLC_T",      /*12: Multi line comments*/
		"SLC_T",       /*13: Single line comments*/
		"ASSMARK_T",  /*14: a mark to assign one value or function to a variable name*/
		"COMMA_T"     /*15: a comma*/
};

/* TO_DO: Operators token attributes */
typedef enum ArithmeticOperators { OP_ADD, OP_SUB, OP_MUL, OP_DIV } AriOperator;
typedef enum RelationalOperators { OP_EQ, OP_NE, OP_GT, OP_LT } RelOperator;
typedef enum LogicalOperators { OP_AND, OP_OR, OP_NOT } LogOperator;
typedef enum SourceEndOfFile { SEOF_0, SEOF_255 } EofOperator;

/* TO_DO: Data structures for declaring the token and its attributes */
typedef union TokenAttribute {
	PowerR_int codeType;      /* integer attributes accessor */
	AriOperator arithmeticOperator;		/* arithmetic operator attribute code */
	RelOperator relationalOperator;		/* relational operator attribute code */
	LogOperator logicalOperator;		/* logical operator attribute code */
	EofOperator seofType;				/* source-end-of-file attribute code */
	PowerR_int intValue;				/* integer literal attribute (value) */
	PowerR_int keywordIndex;			/* keyword index in the keyword table */
	PowerR_int contentString;			/* string literal offset from the beginning of the string literal buffer (stringLiteralTable->content) */
	PowerR_numeric floatValue;				/* floating-point literal attribute (value) */
	PowerR_char idLexeme[VID_LEN + 1];	/* variable identifier token attribute */
	PowerR_char errLexeme[ERR_LEN + 1];	/* error token attribite */
} TokenAttribute;

/* TO_DO: Should be used if no symbol table is implemented */
typedef struct idAttibutes {
	PowerR_byte flags;			/* Flags information */
	union {
		PowerR_int intValue;				/* Integer value */
		PowerR_numeric floatValue;			/* Float value */
		PowerR_string stringContent;		/* String value */
	} values;
} IdAttibutes;

/* Token declaration */
typedef struct Token {
	PowerR_int code;				/* token code */
	TokenAttribute attribute;	/* token attribute */
	IdAttibutes   idAttribute;	/* not used in this scanner implementation - for further use */
} Token;

/* Scanner */
typedef struct scannerData {
	PowerR_int scanHistogram[NUM_TOKENS];	/* Statistics of chars */
} ScannerData, * pScanData;

///////////////////////////////////////////////////////////////////////////////////////////////////////

/* EOF definitions */
#define CHARSEOF0 '\0'
#define CHARSEOF255 0xFF

/*  Special case tokens processed separately one by one in the token-driven part of the scanner:
 *  LPR_T, RPR_T, LBR_T, RBR_T, EOS_T, SEOF_T and special chars used for tokenis include _, & and ' */

/* TO_DO: Define lexeme FIXED classes */
/* These constants will be used on nextClass */
#define CHRCOL2 '#'
#define CHRCOL3 '\n'
#define CHRCOL4 '_'
#define CHRCOL5 '.'
#define CHRCOL6 '\''
#define CHRCOL7 '"'
#define CHRCOL11 '<'
#define CHRCOL12 '-'


/* These constants will be used on VID / MID function 
#define MNID_SUF '&'
#define COMM_SYM '#'*/

/* TO_DO: Error states and illegal state */
#define ESNR	17		/* Error state with no retract */
#define ESWR	18		/* Error state with retract */
#define FS		19		/* Illegal state (why? It should be FS stands for final state)*/

 /* TO_DO: State transition table definition */
#define NUM_STATES		18//changed here
#define CHAR_CLASSES	13//changed here

/* TO_DO: Transition table - type of states defined in separate table */
static PowerR_int transitionTable[NUM_STATES][CHAR_CLASSES] = {
/*    [A-z],[0-9],    #,   \n,   _ ,   . ,    ',    "   ,Other,  (  ,   )   ,  <  ,   -  ,
	   L(0), D(1), H(2), E(3), U(4), P(5), Q1(6),  Q2(7), O(8), B(9), B2(10),A(11), T(12), */
	{     7,    9,    1, ESNR, ESNR,   11,	 13,      15, ESNR, ESNR,   ESNR, ESNR,  ESNR},	// S0: 
	{     2,    2,    4,    3,    2,    2,	  2,       2,    2,    2,      2,    2,     2},	// S1: 
	{     2,    2,    2,    3,    2,    2,	  2,       2,    2,    2,      2,    2,     2},	// S2: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,       FS,  FS,   FS,     FS,   FS,    FS},	// S3: Single line comments(SLC)
	{     4,    4,    5,    4,    4,    4,    4,       4,    4,    4,      4,    4,     4},// S4: 
	{     4,    4,    6,    4,    4,    4,    4,       4,    4,    4,      4,    4,     4},// S5: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,       FS,  FS,   FS,     FS,   FS,    FS},	// S6: Multi Line comments(MLC)
	{     7,    7,    8,    8,    7,    7,	  8,       8,    8,    8,      8,    8,     8},	// S7: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,       FS,  FS,   FS,     FS,   FS,    FS},	// S8: name(ID)
	{    10,    9,   10,   10,   10,   11,	 10,      10,   10,   10,     10,   10,    10},  // S9: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,       FS,  FS,   FS,     FS,   FS,    FS},  // S10: Integer Literal(INT_T)
	{    12,   11,   12,   12,   12,   12,	 12,      12,   12,   12,     12,   12,    12},  // S11: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,      FS,  FS,   FS,     FS,   FS,    FS},  // S12: Float literals(FLT_T)
	{    13,   13,   13,   13,   13,   13,	 14,      13,  13,   13,     13,   13,    13},  // S13: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,      FS,  FS,   FS,     FS,   FS,    FS},  // S14: String literal(STR_T)
	{    15,   15,   15,   15,   15,   15,	 15,      16,  15,   15,     15,   15,    15},  // S15: 
	{    FS,   FS,   FS,   FS,   FS,   FS,	 FS,      FS,  FS,   FS,     FS,   FS,    FS}   // S16: String literal(STR_T)
};

/* Define accepting states types */
#define NOFS	0		/* not accepting state */
#define FSNR	1		/* accepting state with no retract */
#define FSWR	2		/* accepting state with retract */

/* TO_DO: Define list of acceptable states */
static PowerR_int stateType[NUM_STATES] = {
	NOFS, /* 00 */
	NOFS, /* 01 */
	NOFS, /* 02 */
	FSNR, /* 03 (SLM_T) - Single line comment */
	NOFS, /* 04  */
	NOFS, /* 05 */
	FSNR, /* 06 (MLC_T) - Multi line comment */
	NOFS, /* 07 */
	FSWR, /* 08 name(ID_T) */
	NOFS, /* 09  */
	FSWR,  /* 10 Integer Literal(INT_T) (Err2 - retract) */
	NOFS, /* 11 */
	FSWR, /* 12 Float literals(FLT_T) */
	NOFS, /* 13 */
	FSNR, /* 14 String literal (STR_T) */
	NOFS, /* 15  */
	FSNR, /*  16 String literal (STR_T)*/
	ESNR /*17 ADD A ERROR STATE HERER error with no retraction */
};

/*
-------------------------------------------------
TO_DO: Adjust your functions'definitions
-------------------------------------------------
*/

/* Static (local) function  prototypes */
PowerR_int			startScanner(BufferPointer psc_buf);
static PowerR_int	nextClass(PowerR_char);					/* character class function */
static PowerR_int	nextState(PowerR_int, PowerR_char);		/* state machine function */
PowerR_void			printScannerData(ScannerData scData);
Token				tokenizer(PowerR_void);

/*
-------------------------------------------------
Automata definitions
-------------------------------------------------
*/

/* TO_DO: Pointer to function (of one char * argument) returning Token */
typedef Token(*PTR_ACCFUN)(PowerR_string lexeme);

/* Declare accepting states functions */
Token funcSL	(PowerR_string lexeme);
Token funcIL	(PowerR_string lexeme);
Token funcFL(PowerR_string lexeme);
//Token funcID	(PowerR_string lexeme);
Token funcCMT   (PowerR_string lexeme);
/*Token funcKEY(PowerR_string lexeme);*/
Token funcKEYORID(PowerR_string lexeme);
Token funcErr	(PowerR_string lexeme);

/* 
 * Accepting function (action) callback table (array) definition 
 * If you do not want to use the typedef, the equvalent declaration is:
 */

/* TO_DO: Define final state table */
static PTR_ACCFUN finalStateTable[NUM_STATES] = {
	NULL,		/* -    [00] */
	NULL,		/* -    [01] */
	NULL,		/* -    [02] */
	/*funcID,	MNID	[02] */
	funcCMT,	/* SLC_T comment  [03] */
	NULL,		/* -    [04] */
	NULL,       /*-    [05]*/
	funcCMT,	/* SLC_T   [06] */
	NULL,		/* -    [07] */		
	funcKEYORID,/* -    [08] */
	NULL,	    /*      [09] */
    funcIL,		/*      [10] */
	NULL,		/*      [11] */
	funcFL,		/* FL(floating point)   [12] */
	NULL,		/* SL   [13] */
	funcSL,		/* SL   [14] */
	NULL,		/* SL   [15] */
	funcSL,		/* SL   [16] */
    funcErr,	/* ERR2 [17] */
};

/*
-------------------------------------------------
Language keywords
-------------------------------------------------
*/

/* TO_DO: Define the number of Keywords from the language */
#define KWT_SIZE 18

/* TO_DO: Define the list of keywords */
static PowerR_string keywordTable[KWT_SIZE] = {
	"numberic",		/* KW00 */
	"int",			/* KW01 */
	"string",		/* KW02 */
	"if",			/* KW03 */
	"else",			/* KW04 */
	"repeat",		/* KW05 */
	"while",		/* KW06 */
	"function",		/* KW07 */
	"for",			/* KW08 */
	"in",			/* KW09 */
	"next",			/* KW10 */
	"break",		/* KW11 */
	"continue",		/* KW12 */
	"readLine",		/* KW13 */
	"TRUE",			/* KW14 */
	"FALSE",		/* KW15 */
	"cat",			/* KW16 */
	"print"			/* KW17 */
};

/* NEW SECTION: About indentation */

/*
 * Scanner attributes to be used (ex: including: intendation data
 */

#define INDENT '\t'  /* Tabulation */

/* TO_DO: Should be used if no symbol table is implemented */
typedef struct languageAttributes {
	PowerR_char indentationCharType;
	PowerR_string indentationCurrentPos;
	/* TO_DO: Include any extra attribute to be used in your scanner (OPTIONAL and FREE) */
} LanguageAttributes;

/* Number of errors */
PowerR_string numScannerErrors;

/* Scanner data */
ScannerData scData;

#endif
