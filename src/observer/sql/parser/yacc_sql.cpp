/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(const char *aggregate_name,
                                           Expression *child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(aggregate_name, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 125 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_TABLE = 8,                      /* TABLE  */
  YYSYMBOL_TABLES = 9,                     /* TABLES  */
  YYSYMBOL_INDEX = 10,                     /* INDEX  */
  YYSYMBOL_CALC = 11,                      /* CALC  */
  YYSYMBOL_SELECT = 12,                    /* SELECT  */
  YYSYMBOL_DESC = 13,                      /* DESC  */
  YYSYMBOL_SHOW = 14,                      /* SHOW  */
  YYSYMBOL_SYNC = 15,                      /* SYNC  */
  YYSYMBOL_INSERT = 16,                    /* INSERT  */
  YYSYMBOL_DELETE = 17,                    /* DELETE  */
  YYSYMBOL_UPDATE = 18,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 19,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 20,                    /* RBRACE  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 22,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 23,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 24,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 25,                     /* INT_T  */
  YYSYMBOL_STRING_T = 26,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 27,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_NULL_T = 29,                    /* NULL_T  */
  YYSYMBOL_HELP = 30,                      /* HELP  */
  YYSYMBOL_EXIT = 31,                      /* EXIT  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_INTO = 33,                      /* INTO  */
  YYSYMBOL_VALUES = 34,                    /* VALUES  */
  YYSYMBOL_FROM = 35,                      /* FROM  */
  YYSYMBOL_WHERE = 36,                     /* WHERE  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_SET = 38,                       /* SET  */
  YYSYMBOL_ON = 39,                        /* ON  */
  YYSYMBOL_LOAD = 40,                      /* LOAD  */
  YYSYMBOL_DATA = 41,                      /* DATA  */
  YYSYMBOL_INFILE = 42,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 43,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 44,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 45,                    /* FORMAT  */
  YYSYMBOL_NULLABLE = 46,                  /* NULLABLE  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_IS = 48,                        /* IS  */
  YYSYMBOL_INNER = 49,                     /* INNER  */
  YYSYMBOL_JOIN = 50,                      /* JOIN  */
  YYSYMBOL_UNIQUE = 51,                    /* UNIQUE  */
  YYSYMBOL_EQ = 52,                        /* EQ  */
  YYSYMBOL_LT = 53,                        /* LT  */
  YYSYMBOL_GT = 54,                        /* GT  */
  YYSYMBOL_LE = 55,                        /* LE  */
  YYSYMBOL_GE = 56,                        /* GE  */
  YYSYMBOL_NE = 57,                        /* NE  */
  YYSYMBOL_NUMBER = 58,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 59,                     /* FLOAT  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_SSS = 61,                       /* SSS  */
  YYSYMBOL_62_ = 62,                       /* '+'  */
  YYSYMBOL_63_ = 63,                       /* '-'  */
  YYSYMBOL_64_ = 64,                       /* '*'  */
  YYSYMBOL_65_ = 65,                       /* '/'  */
  YYSYMBOL_UMINUS = 66,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_commands = 68,                  /* commands  */
  YYSYMBOL_command_wrapper = 69,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 70,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 71,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 72,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 73,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 74,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 75,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 76,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 77,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 78,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 79,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 80,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 81,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 82,             /* attr_def_list  */
  YYSYMBOL_attr_def = 83,                  /* attr_def  */
  YYSYMBOL_nullability = 84,               /* nullability  */
  YYSYMBOL_number = 85,                    /* number  */
  YYSYMBOL_type = 86,                      /* type  */
  YYSYMBOL_row = 87,                       /* row  */
  YYSYMBOL_row_list = 88,                  /* row_list  */
  YYSYMBOL_insert_stmt = 89,               /* insert_stmt  */
  YYSYMBOL_value_list = 90,                /* value_list  */
  YYSYMBOL_value = 91,                     /* value  */
  YYSYMBOL_storage_format = 92,            /* storage_format  */
  YYSYMBOL_delete_stmt = 93,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 94,               /* update_stmt  */
  YYSYMBOL_select_stmt = 95,               /* select_stmt  */
  YYSYMBOL_calc_stmt = 96,                 /* calc_stmt  */
  YYSYMBOL_expression_list = 97,           /* expression_list  */
  YYSYMBOL_expression = 98,                /* expression  */
  YYSYMBOL_expr_value = 99,                /* expr_value  */
  YYSYMBOL_rel_attr = 100,                 /* rel_attr  */
  YYSYMBOL_relation = 101,                 /* relation  */
  YYSYMBOL_rel_list = 102,                 /* rel_list  */
  YYSYMBOL_on_condition_list = 103,        /* on_condition_list  */
  YYSYMBOL_on_condition = 104,             /* on_condition  */
  YYSYMBOL_where = 105,                    /* where  */
  YYSYMBOL_condition_list = 106,           /* condition_list  */
  YYSYMBOL_condition = 107,                /* condition  */
  YYSYMBOL_comp_op = 108,                  /* comp_op  */
  YYSYMBOL_is_op = 109,                    /* is_op  */
  YYSYMBOL_group_by = 110,                 /* group_by  */
  YYSYMBOL_load_data_stmt = 111,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 112,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 113,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 114             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    64,    62,     2,    63,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   212,   212,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   243,   249,   254,   260,   266,   272,   278,
     285,   291,   299,   311,   326,   336,   360,   363,   376,   388,
     404,   407,   411,   418,   421,   422,   423,   424,   425,   429,
     444,   447,   460,   491,   494,   505,   509,   513,   517,   521,
     527,   534,   537,   544,   556,   571,   596,   605,   610,   621,
     624,   627,   630,   633,   637,   640,   645,   651,   654,   657,
     660,   666,   670,   674,   680,   687,   692,   702,   711,   716,
     726,   738,   741,   746,   753,   764,   775,   786,   801,   804,
     810,   813,   817,   823,   828,   836,   837,   838,   839,   840,
     841,   845,   846,   852,   857,   870,   878,   888,   889
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT",
  "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "NULL_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN",
  "STORAGE", "FORMAT", "NULLABLE", "NOT", "IS", "INNER", "JOIN", "UNIQUE",
  "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER", "FLOAT", "ID", "SSS",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "create_index_stmt", "drop_index_stmt",
  "create_table_stmt", "attr_def_list", "attr_def", "nullability",
  "number", "type", "row", "row_list", "insert_stmt", "value_list",
  "value", "storage_format", "delete_stmt", "update_stmt", "select_stmt",
  "calc_stmt", "expression_list", "expression", "expr_value", "rel_attr",
  "relation", "rel_list", "on_condition_list", "on_condition", "where",
  "condition_list", "condition", "comp_op", "is_op", "group_by",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-181)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,    35,     3,    -4,    -4,   -50,     5,  -181,   -13,   -19,
     -26,  -181,  -181,  -181,  -181,  -181,    -9,    17,    83,    46,
      64,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,    16,    25,    99,    50,    51,    -4,  -181,  -181,  -181,
     -15,  -181,    -4,  -181,  -181,    19,  -181,  -181,    77,  -181,
    -181,    58,    62,    86,    75,    87,  -181,  -181,  -181,  -181,
     106,    89,    70,  -181,    96,     6,   -11,    81,  -181,    -4,
      -4,    -4,    -4,    -4,    90,   115,   116,   108,    79,   109,
     111,   112,   130,   113,  -181,  -181,     1,  -181,  -181,   -41,
     -41,  -181,  -181,  -181,   153,   -30,   132,    -4,  -181,   123,
    -181,  -181,  -181,  -181,   -17,  -181,   143,   138,   156,   159,
     119,  -181,  -181,    -4,    90,   131,  -181,    79,   161,    91,
    -181,   146,    79,  -181,  -181,   172,  -181,  -181,  -181,  -181,
    -181,   -14,   111,   164,   125,   167,    10,   139,    90,  -181,
     166,   132,  -181,   142,  -181,  -181,  -181,  -181,  -181,  -181,
      -4,    -4,    -4,   116,   133,   134,  -181,   162,  -181,   156,
     150,   170,   135,  -181,   157,    79,   177,   161,  -181,    28,
      28,  -181,  -181,  -181,  -181,   178,  -181,  -181,   154,  -181,
    -181,   180,    73,   166,  -181,  -181,    33,   149,  -181,   171,
     105,   105,  -181,   165,  -181,  -181,   144,    73,    73,    73,
    -181,  -181,  -181,  -181,  -181,  -181
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     117,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    84,    81,    82,
      85,    83,     0,    77,    66,    67,    75,    76,     0,    31,
      30,     0,     0,     0,     0,     0,   115,     1,   118,     2,
       0,     0,     0,    29,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,    73,    80,     0,    86,    68,    69,
      70,    71,    72,    87,    88,    98,     0,   100,    63,     0,
      60,    55,    57,    59,     0,   116,     0,     0,    36,     0,
       0,    34,    78,     0,     0,     0,   113,     0,    50,     0,
      99,   101,     0,    56,    58,     0,    44,    45,    46,    47,
      48,    40,     0,     0,     0,     0,     0,    89,     0,    65,
      53,     0,    52,   111,   105,   106,   107,   108,   109,   110,
       0,     0,   100,    98,     0,     0,    41,     0,    39,    36,
      61,     0,     0,    79,     0,     0,     0,    50,   112,   103,
     104,   102,    64,   114,    43,     0,    42,    37,     0,    35,
      32,     0,    91,    53,    49,    51,    40,     0,    33,    85,
       0,     0,    90,    92,    54,    38,     0,     0,     0,    91,
      62,    95,    97,    94,    96,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,   187,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,    37,    65,    12,  -181,  -181,
      59,    32,  -181,    18,   -88,  -181,  -181,  -181,  -181,  -181,
      -2,   -45,  -181,  -180,    66,    88,     4,  -181,  -102,    53,
    -181,   -97,  -181,  -181,  -181,  -181,  -181,  -181
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   143,   118,   168,   185,   141,
     128,   152,    33,   176,   200,   189,    34,    35,    36,    37,
      54,    55,    56,    57,   104,   105,   202,   203,   108,   130,
     131,   160,   161,   149,    38,    39,    40,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     115,    75,    58,   126,    76,   165,   107,    78,    46,    95,
      59,    44,   201,    45,    60,    46,    62,    77,    47,   125,
      61,   122,   123,    82,    83,    47,    94,   212,   214,   201,
     173,    96,   166,   167,    63,    99,   100,   101,   102,   150,
      79,   133,   134,    41,   163,    42,    67,    48,    49,    50,
      51,    64,    52,    53,    48,    49,    50,    51,    65,    52,
      53,   182,   129,    80,    81,    82,    83,    68,    80,    81,
      82,    83,    80,    81,    82,    83,    70,    98,   146,   166,
     167,    80,    81,    82,    83,    71,    43,   193,     1,     2,
      80,    81,    82,    83,     3,     4,     5,     6,     7,     8,
       9,    10,   110,   207,   208,    11,    12,    13,   110,    72,
      73,    74,    84,    14,    15,   179,   180,   129,    85,   211,
     213,    16,    86,    17,    87,    90,    18,    88,    91,    89,
      92,   111,   112,   199,   113,    93,   114,   111,   112,   153,
     113,    97,   114,   154,   155,   156,   157,   158,   159,   106,
     103,   127,   107,    80,    81,    82,    83,   154,   155,   156,
     157,   158,   159,   136,   137,   138,   139,   140,   109,   120,
     116,   117,   119,   121,   124,   132,   135,   142,   144,   145,
     164,   148,   151,   162,   170,   171,   172,   175,   125,   178,
     190,   186,   184,   183,   188,   191,   192,   194,   196,   197,
     198,   206,   209,    77,   210,    66,   187,   169,   205,   195,
     177,   204,   147,   215,   174,   181
};

static const yytype_uint8 yycheck[] =
{
      88,    46,     4,   105,    19,    19,    36,    52,    19,    20,
      60,     8,   192,    10,     9,    19,    35,    32,    29,    49,
      33,    20,    21,    64,    65,    29,    20,   207,   208,   209,
      20,    76,    46,    47,    60,    80,    81,    82,    83,   127,
      21,    58,    59,     8,   132,    10,     0,    58,    59,    60,
      61,    60,    63,    64,    58,    59,    60,    61,    41,    63,
      64,   163,   107,    62,    63,    64,    65,     3,    62,    63,
      64,    65,    62,    63,    64,    65,    60,    79,   123,    46,
      47,    62,    63,    64,    65,    60,    51,   175,     5,     6,
      62,    63,    64,    65,    11,    12,    13,    14,    15,    16,
      17,    18,    29,   200,   201,    22,    23,    24,    29,    10,
      60,    60,    35,    30,    31,   160,   161,   162,    60,   207,
     208,    38,    60,    40,    38,    19,    43,    52,    39,    42,
      60,    58,    59,    60,    61,    39,    63,    58,    59,    48,
      61,    60,    63,    52,    53,    54,    55,    56,    57,    34,
      60,    19,    36,    62,    63,    64,    65,    52,    53,    54,
      55,    56,    57,    25,    26,    27,    28,    29,    60,    39,
      61,    60,    60,    60,    21,    52,    33,    21,    19,    60,
       8,    50,    21,    37,    20,    60,    19,    21,    49,    47,
      20,    29,    58,    60,    44,    60,    39,    20,    20,    45,
      20,    52,    37,    32,    60,    18,   169,   142,   196,   177,
     151,   193,   124,   209,   148,   162
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    11,    12,    13,    14,    15,    16,    17,
      18,    22,    23,    24,    30,    31,    38,    40,    43,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    89,    93,    94,    95,    96,   111,   112,
     113,     8,    10,    51,     8,    10,    19,    29,    58,    59,
      60,    61,    63,    64,    97,    98,    99,   100,    97,    60,
       9,    33,    35,    60,    60,    41,    69,     0,     3,   114,
      60,    60,    10,    60,    60,    98,    19,    32,    98,    21,
      62,    63,    64,    65,    35,    60,    60,    38,    52,    42,
      19,    39,    60,    39,    20,    20,    98,    60,    97,    98,
      98,    98,    98,    60,   101,   102,    34,    36,   105,    60,
      29,    58,    59,    61,    63,    91,    61,    60,    83,    60,
      39,    60,    20,    21,    21,    49,   105,    19,    87,    98,
     106,   107,    52,    58,    59,    33,    25,    26,    27,    28,
      29,    86,    21,    82,    19,    60,    98,   102,    50,   110,
      91,    21,    88,    48,    52,    53,    54,    55,    56,    57,
     108,   109,    37,    91,     8,    19,    46,    47,    84,    83,
      20,    60,    19,    20,   101,    21,    90,    87,    47,    98,
      98,   106,   105,    60,    58,    85,    29,    82,    44,    92,
      20,    60,    39,    91,    20,    88,    20,    45,    20,    60,
      91,   100,   103,   104,    90,    84,    52,   108,   108,    37,
      60,    91,   100,    91,   100,   103
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    79,    80,    81,    82,    82,    83,    83,
      84,    84,    84,    85,    86,    86,    86,    86,    86,    87,
      88,    88,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    92,    92,    93,    94,    95,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   105,   105,
     106,   106,   106,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   111,   112,   113,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     8,     9,     5,     8,     0,     3,     6,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     4,
       0,     3,     6,     0,     3,     1,     2,     1,     2,     1,
       1,     0,     4,     4,     7,     6,     2,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     4,     6,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       6,     0,     1,     3,     3,     3,     3,     3,     0,     2,
       0,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 213 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1785 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 243 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1794 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 249 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1802 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 254 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1810 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 260 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1818 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 266 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1826 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 272 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1834 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 278 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1844 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 285 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1852 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 291 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1862 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 300 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      create_index.is_unique = false;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 1878 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 312 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      create_index.is_unique = true;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 1894 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 327 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1906 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 337 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 1931 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 360 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 364 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 1953 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE nullability  */
#line 377 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      if ((yyvsp[0].nullability)) {
        (yyval.attr_info)->length += 1;
      }
      (yyval.attr_info)->nullable = (yyvsp[0].nullability);
      free((yyvsp[-5].string));
    }
#line 1969 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type nullability  */
#line 389 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      if ((yyvsp[0].nullability)) {
        (yyval.attr_info)->length += 1;
      }
      (yyval.attr_info)->nullable = (yyvsp[0].nullability);
      free((yyvsp[-2].string));
    }
#line 1985 "yacc_sql.cpp"
    break;

  case 40: /* nullability: %empty  */
#line 404 "yacc_sql.y"
    {
      (yyval.nullability) = false;
    }
#line 1993 "yacc_sql.cpp"
    break;

  case 41: /* nullability: NULLABLE  */
#line 408 "yacc_sql.y"
    {
      (yyval.nullability) = true;
    }
#line 2001 "yacc_sql.cpp"
    break;

  case 42: /* nullability: NOT NULL_T  */
#line 412 "yacc_sql.y"
    {
      (yyval.nullability) = false;
    }
#line 2009 "yacc_sql.cpp"
    break;

  case 43: /* number: NUMBER  */
#line 418 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2015 "yacc_sql.cpp"
    break;

  case 44: /* type: INT_T  */
#line 421 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2021 "yacc_sql.cpp"
    break;

  case 45: /* type: STRING_T  */
#line 422 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2027 "yacc_sql.cpp"
    break;

  case 46: /* type: FLOAT_T  */
#line 423 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2033 "yacc_sql.cpp"
    break;

  case 47: /* type: DATE_T  */
#line 424 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATE);}
#line 2039 "yacc_sql.cpp"
    break;

  case 48: /* type: NULL_T  */
#line 425 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::NULLS); }
#line 2045 "yacc_sql.cpp"
    break;

  case 49: /* row: LBRACE value value_list RBRACE  */
#line 430 "yacc_sql.y"
    {
      (yyval.value_list) = new std::vector<Value>;
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.value_list)->swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.value_list)->begin(), (yyval.value_list)->end());
      delete (yyvsp[-2].value);
    }
#line 2060 "yacc_sql.cpp"
    break;

  case 50: /* row_list: %empty  */
#line 444 "yacc_sql.y"
    {
      (yyval.row_list) = nullptr;
    }
#line 2068 "yacc_sql.cpp"
    break;

  case 51: /* row_list: COMMA row row_list  */
#line 448 "yacc_sql.y"
    {
      if ((yyvsp[0].row_list) != nullptr) {
        (yyval.row_list) = (yyvsp[0].row_list);
      } else {
        (yyval.row_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.row_list)->emplace_back(*(yyvsp[-1].value_list));
      delete (yyvsp[-1].value_list);
    }
#line 2082 "yacc_sql.cpp"
    break;

  case 52: /* insert_stmt: INSERT INTO ID VALUES row row_list  */
#line 461 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-3].string);
      if ((yyvsp[0].row_list) != nullptr) {
        (yyval.sql_node)->insertion.rows.swap(*(yyvsp[0].row_list));
        delete (yyvsp[0].row_list);
      }
      (yyval.sql_node)->insertion.rows.emplace_back(*(yyvsp[-1].value_list));
      std::reverse((yyval.sql_node)->insertion.rows.begin(), (yyval.sql_node)->insertion.rows.end());
      delete (yyvsp[-1].value_list);
      free((yyvsp[-3].string));
    }
#line 2099 "yacc_sql.cpp"
    break;

  case 53: /* value_list: %empty  */
#line 491 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2107 "yacc_sql.cpp"
    break;

  case 54: /* value_list: COMMA value value_list  */
#line 494 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2121 "yacc_sql.cpp"
    break;

  case 55: /* value: NUMBER  */
#line 505 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2130 "yacc_sql.cpp"
    break;

  case 56: /* value: '-' NUMBER  */
#line 509 "yacc_sql.y"
                {
      (yyval.value) = new Value((int)-(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2139 "yacc_sql.cpp"
    break;

  case 57: /* value: FLOAT  */
#line 513 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2148 "yacc_sql.cpp"
    break;

  case 58: /* value: '-' FLOAT  */
#line 517 "yacc_sql.y"
               {
      (yyval.value) = new Value((float)-(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2157 "yacc_sql.cpp"
    break;

  case 59: /* value: SSS  */
#line 521 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2168 "yacc_sql.cpp"
    break;

  case 60: /* value: NULL_T  */
#line 527 "yacc_sql.y"
             {
      (yyval.value) = new Value();
      (yyval.value)->make_null();
    }
#line 2177 "yacc_sql.cpp"
    break;

  case 61: /* storage_format: %empty  */
#line 534 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2185 "yacc_sql.cpp"
    break;

  case 62: /* storage_format: STORAGE FORMAT EQ ID  */
#line 538 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2193 "yacc_sql.cpp"
    break;

  case 63: /* delete_stmt: DELETE FROM ID where  */
#line 545 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2207 "yacc_sql.cpp"
    break;

  case 64: /* update_stmt: UPDATE ID SET ID EQ value where  */
#line 557 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-5].string);
      (yyval.sql_node)->update.attribute_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.value = *(yyvsp[-1].value);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
    }
#line 2224 "yacc_sql.cpp"
    break;

  case 65: /* select_stmt: SELECT expression_list FROM rel_list where group_by  */
#line 572 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-4].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-4].expression_list));
        delete (yyvsp[-4].expression_list);
      }

      if ((yyvsp[-2].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-2].relation_list));
        delete (yyvsp[-2].relation_list);
      }

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }

      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2251 "yacc_sql.cpp"
    break;

  case 66: /* calc_stmt: CALC expression_list  */
#line 597 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2261 "yacc_sql.cpp"
    break;

  case 67: /* expression_list: expression  */
#line 606 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2270 "yacc_sql.cpp"
    break;

  case 68: /* expression_list: expression COMMA expression_list  */
#line 611 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2283 "yacc_sql.cpp"
    break;

  case 69: /* expression: expression '+' expression  */
#line 621 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2291 "yacc_sql.cpp"
    break;

  case 70: /* expression: expression '-' expression  */
#line 624 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2299 "yacc_sql.cpp"
    break;

  case 71: /* expression: expression '*' expression  */
#line 627 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2307 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression '/' expression  */
#line 630 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2315 "yacc_sql.cpp"
    break;

  case 73: /* expression: LBRACE expression RBRACE  */
#line 633 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2324 "yacc_sql.cpp"
    break;

  case 74: /* expression: '-' expression  */
#line 637 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2332 "yacc_sql.cpp"
    break;

  case 75: /* expression: expr_value  */
#line 640 "yacc_sql.y"
                 {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].expr_value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].expr_value);
    }
#line 2342 "yacc_sql.cpp"
    break;

  case 76: /* expression: rel_attr  */
#line 645 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2353 "yacc_sql.cpp"
    break;

  case 77: /* expression: '*'  */
#line 651 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2361 "yacc_sql.cpp"
    break;

  case 78: /* expression: ID LBRACE expression RBRACE  */
#line 654 "yacc_sql.y"
                                  {
      (yyval.expression) = create_aggregate_expression((yyvsp[-3].string), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2369 "yacc_sql.cpp"
    break;

  case 79: /* expression: ID LBRACE expression COMMA expression RBRACE  */
#line 657 "yacc_sql.y"
                                                   {
      (yyval.expression) = create_aggregate_expression((yyvsp[-5].string), nullptr, sql_string, &(yyloc));
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 80: /* expression: ID LBRACE RBRACE  */
#line 660 "yacc_sql.y"
                       {
      (yyval.expression) = create_aggregate_expression((yyvsp[-2].string), nullptr, sql_string, &(yyloc));
    }
#line 2385 "yacc_sql.cpp"
    break;

  case 81: /* expr_value: NUMBER  */
#line 666 "yacc_sql.y"
           {
      (yyval.expr_value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2394 "yacc_sql.cpp"
    break;

  case 82: /* expr_value: FLOAT  */
#line 670 "yacc_sql.y"
           {
      (yyval.expr_value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2403 "yacc_sql.cpp"
    break;

  case 83: /* expr_value: SSS  */
#line 674 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.expr_value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2414 "yacc_sql.cpp"
    break;

  case 84: /* expr_value: NULL_T  */
#line 680 "yacc_sql.y"
            {
      (yyval.expr_value) = new Value();
      (yyval.expr_value)->make_null();
    }
#line 2423 "yacc_sql.cpp"
    break;

  case 85: /* rel_attr: ID  */
#line 687 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2433 "yacc_sql.cpp"
    break;

  case 86: /* rel_attr: ID DOT ID  */
#line 692 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2445 "yacc_sql.cpp"
    break;

  case 87: /* relation: ID  */
#line 702 "yacc_sql.y"
       {
      (yyval.relation) = new JoinSqlNode;
      (yyval.relation)->relation_name = (yyvsp[0].string);
      (yyval.relation)->join_type = JoinType::UNDEFINED;
      free((yyvsp[0].string));
    }
#line 2456 "yacc_sql.cpp"
    break;

  case 88: /* rel_list: relation  */
#line 711 "yacc_sql.y"
             {
      (yyval.relation_list) = new std::vector<JoinSqlNode>;
      (yyval.relation_list)->emplace_back(*(yyvsp[0].relation));
      delete((yyvsp[0].relation));
    }
#line 2466 "yacc_sql.cpp"
    break;

  case 89: /* rel_list: relation COMMA rel_list  */
#line 716 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<JoinSqlNode>;
      }

      (yyval.relation_list)->emplace((yyval.relation_list)->begin(), *(yyvsp[-2].relation));
      delete (yyvsp[-2].relation);
    }
#line 2481 "yacc_sql.cpp"
    break;

  case 90: /* rel_list: rel_list INNER JOIN relation ON on_condition_list  */
#line 726 "yacc_sql.y"
                                                        {
      (yyvsp[-2].relation)->join_type = JoinType::INNER_JOIN;
      (yyvsp[-2].relation)->on_conditions = *(yyvsp[0].on_condition_list);
      (yyvsp[-5].relation_list)->emplace_back(*(yyvsp[-2].relation));
      delete (yyvsp[-2].relation);
      
      (yyval.relation_list) = (yyvsp[-5].relation_list);
    }
#line 2494 "yacc_sql.cpp"
    break;

  case 91: /* on_condition_list: %empty  */
#line 738 "yacc_sql.y"
    {
      (yyval.on_condition_list) = nullptr;
    }
#line 2502 "yacc_sql.cpp"
    break;

  case 92: /* on_condition_list: on_condition  */
#line 741 "yacc_sql.y"
                   {
      (yyval.on_condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.on_condition_list)->emplace_back(*(yyvsp[0].on_condition));
      delete (yyvsp[0].on_condition);
    }
#line 2512 "yacc_sql.cpp"
    break;

  case 93: /* on_condition_list: on_condition AND on_condition_list  */
#line 746 "yacc_sql.y"
                                         {
      (yyval.on_condition_list) = (yyvsp[0].on_condition_list);
      (yyval.on_condition_list)->emplace_back(*(yyvsp[-2].on_condition));
      delete (yyvsp[-2].on_condition);
    }
#line 2522 "yacc_sql.cpp"
    break;

  case 94: /* on_condition: rel_attr comp_op value  */
#line 754 "yacc_sql.y"
    {
      (yyval.on_condition) = new ConditionSqlNode;
      (yyval.on_condition)->left_is_attr = 1;
      (yyval.on_condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.on_condition)->right_is_attr = 0;
      (yyval.on_condition)->right_value = *(yyvsp[0].value);
      (yyval.on_condition)->comp = (yyvsp[-1].comp);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2537 "yacc_sql.cpp"
    break;

  case 95: /* on_condition: value comp_op value  */
#line 765 "yacc_sql.y"
    {
      (yyval.on_condition) = new ConditionSqlNode;
      (yyval.on_condition)->left_is_attr = 0;
      (yyval.on_condition)->left_value = *(yyvsp[-2].value);
      (yyval.on_condition)->right_is_attr = 0;
      (yyval.on_condition)->right_value = *(yyvsp[0].value);
      (yyval.on_condition)->comp = (yyvsp[-1].comp);
      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2552 "yacc_sql.cpp"
    break;

  case 96: /* on_condition: rel_attr comp_op rel_attr  */
#line 776 "yacc_sql.y"
    {
      (yyval.on_condition) = new ConditionSqlNode;
      (yyval.on_condition)->left_is_attr = 1;
      (yyval.on_condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.on_condition)->right_is_attr = 1;
      (yyval.on_condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.on_condition)->comp = (yyvsp[-1].comp);
      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2567 "yacc_sql.cpp"
    break;

  case 97: /* on_condition: value comp_op rel_attr  */
#line 787 "yacc_sql.y"
    {
      (yyval.on_condition) = new ConditionSqlNode;
      (yyval.on_condition)->left_is_attr = 0;
      (yyval.on_condition)->left_value = *(yyvsp[-2].value);
      (yyval.on_condition)->right_is_attr = 1;
      (yyval.on_condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.on_condition)->comp = (yyvsp[-1].comp);
      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2582 "yacc_sql.cpp"
    break;

  case 98: /* where: %empty  */
#line 801 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2590 "yacc_sql.cpp"
    break;

  case 99: /* where: WHERE condition_list  */
#line 804 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 100: /* condition_list: %empty  */
#line 810 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 101: /* condition_list: condition  */
#line 813 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.condition_list)->emplace_back((yyvsp[0].condition));
    }
#line 2615 "yacc_sql.cpp"
    break;

  case 102: /* condition_list: condition AND condition_list  */
#line 817 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back((yyvsp[-2].condition));
    }
#line 2624 "yacc_sql.cpp"
    break;

  case 103: /* condition: expression comp_op expression  */
#line 824 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr((yyvsp[-1].comp), (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.condition)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2633 "yacc_sql.cpp"
    break;

  case 104: /* condition: expression is_op expression  */
#line 829 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr((yyvsp[-1].comp), (yyvsp[-2].expression), (yyvsp[0].expression));
      (yyval.condition)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2642 "yacc_sql.cpp"
    break;

  case 105: /* comp_op: EQ  */
#line 836 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2648 "yacc_sql.cpp"
    break;

  case 106: /* comp_op: LT  */
#line 837 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2654 "yacc_sql.cpp"
    break;

  case 107: /* comp_op: GT  */
#line 838 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2660 "yacc_sql.cpp"
    break;

  case 108: /* comp_op: LE  */
#line 839 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2666 "yacc_sql.cpp"
    break;

  case 109: /* comp_op: GE  */
#line 840 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2672 "yacc_sql.cpp"
    break;

  case 110: /* comp_op: NE  */
#line 841 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2678 "yacc_sql.cpp"
    break;

  case 111: /* is_op: IS  */
#line 845 "yacc_sql.y"
       { (yyval.comp) = IS_OP; }
#line 2684 "yacc_sql.cpp"
    break;

  case 112: /* is_op: IS NOT  */
#line 846 "yacc_sql.y"
             { (yyval.comp) = IS_NOT; }
#line 2690 "yacc_sql.cpp"
    break;

  case 113: /* group_by: %empty  */
#line 852 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2698 "yacc_sql.cpp"
    break;

  case 114: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 858 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2712 "yacc_sql.cpp"
    break;

  case 115: /* explain_stmt: EXPLAIN command_wrapper  */
#line 871 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2721 "yacc_sql.cpp"
    break;

  case 116: /* set_variable_stmt: SET ID EQ value  */
#line 879 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2733 "yacc_sql.cpp"
    break;


#line 2737 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 891 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
