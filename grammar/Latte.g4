grammar Latte;

program
    : topDef+
    ;

funcDef
    : type_ ID '(' arg? ')' block
    ;

topDef
    : funcDef                               # FunTopDef
    | 'class' ID ('extends' ID)? classBody  # ClassDef
    ;

classItem
    : funcDef                       # ClassFunDef
    | type_ item ( ',' item )* ';'  # ClassVarDef
    ;

classBody
    : '{' classItem* '}'
    ;

arg
    : type_ ID ( ',' type_ ID )*
    ;

block
    : '{' stmt* '}'
    ;

stmt
    : ';'                                # Empty
    | block                              # BlockStmt
    | type_ item ( ',' item )* ';'       # Decl
    | ID '=' expr ';'                    # Ass
    | ID '++' ';'                        # Incr
    | ID '--' ';'                        # Decr
    | 'return' expr ';'                  # Ret
    | 'return' ';'                       # VRet
    | 'if' '(' expr ')' stmt             # Cond
    | 'if' '(' expr ')' stmt 'else' stmt # CondElse
    | 'while' '(' expr ')' stmt          # While
    | expr ';'                           # SExp
    ;

type_
    : 'int'     # Int
    | 'string'  # Str
    | 'boolean' # Bool
    | 'void'    # Void
    | ID        # Class
    ;

item
    : ID
    | ID '=' expr
    ;

expr
    : ('-'|'!') expr                      # EUnOp
    | expr mulOp expr                     # EMulOp
    | expr addOp expr                     # EAddOp
    | expr relOp expr                     # ERelOp
    | <assoc=right> expr '&&' expr        # EAnd
    | <assoc=right> expr '||' expr        # EOr
    | ID                                  # EId
    | INT                                 # EInt
    | 'true'                              # ETrue
    | 'false'                             # EFalse
    | ID '(' ( expr ( ',' expr )* )? ')'  # EFunCall
    | STR                           # EStr
    | '(' expr ')'                  # EParen
    | expr '.' ID                   # EClassField
    | expr '.' ID '(' ( expr ( ',' expr )* )? ')' # EClassFun
    | 'new' ID  # EClassDef
    | '(' ID ')' 'null' # ETypedNull
    ;

addOp
    : '+'
    | '-'
    ;

mulOp
    : '*'
    | '/'
    | '%'
    ;

relOp
    : '<'
    | '<='
    | '>'
    | '>='
    | '=='
    | '!='
    ;

COMMENT : ('#' ~[\r\n]* | '//' ~[\r\n]*) -> channel(HIDDEN);
MULTICOMMENT : '/*' .*? '*/' -> channel(HIDDEN);

fragment Letter  : Capital | Small ;
fragment Capital : [A-Z\u00C0-\u00D6\u00D8-\u00DE] ;
fragment Small   : [a-z\u00DF-\u00F6\u00F8-\u00FF] ;
fragment Digit : [0-9] ;

INT : Digit+ ;
fragment ID_First : Letter | '_';
ID : ID_First (ID_First | Digit)* ;

WS : (' ' | '\r' | '\t' | '\n')+ ->  skip;

STR
    :   '"' StringCharacters? '"'
    ;
fragment StringCharacters
    :   StringCharacter+
    ;
fragment
StringCharacter
    :   ~["\\]
    |   '\\' [tnr"\\]
    ;
