// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 25 "parser.y"

    #include "driver.hh"
    #include "location.hh"
    #include "utils/forward_include.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 55 "/tmp/miniJava/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 146 "/tmp/miniJava/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 49: // type
        value.YY_MOVE_OR_COPY< Type > (YY_MOVE (that.value));
        break;

      case 4: // "-"
      case 5: // "+"
      case 6: // "*"
      case 7: // "/"
      case 8: // "&&"
      case 9: // "||"
      case 10: // "<"
      case 11: // ">"
      case 12: // "=="
      case 13: // "%"
      case 42: // "number"
      case 48: // intExpr
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 53: // classDecl
        value.YY_MOVE_OR_COPY< std::shared_ptr<Class> > (YY_MOVE (that.value));
        break;

      case 51: // classDeclList
        value.YY_MOVE_OR_COPY< std::shared_ptr<ClassDeclList> > (YY_MOVE (that.value));
        break;

      case 52: // mainClass
        value.YY_MOVE_OR_COPY< std::shared_ptr<ClassMain> > (YY_MOVE (that.value));
        break;

      case 56: // decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 59: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 55: // declList
        value.YY_MOVE_OR_COPY< std::shared_ptr<List> > (YY_MOVE (that.value));
        break;

      case 50: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case 58: // statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 54: // statementList
        value.YY_MOVE_OR_COPY< std::shared_ptr<StatementsList> > (YY_MOVE (that.value));
        break;

      case 57: // varDecl
        value.YY_MOVE_OR_COPY< std::shared_ptr<Var> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 49: // type
        value.move< Type > (YY_MOVE (that.value));
        break;

      case 4: // "-"
      case 5: // "+"
      case 6: // "*"
      case 7: // "/"
      case 8: // "&&"
      case 9: // "||"
      case 10: // "<"
      case 11: // ">"
      case 12: // "=="
      case 13: // "%"
      case 42: // "number"
      case 48: // intExpr
        value.move< int > (YY_MOVE (that.value));
        break;

      case 53: // classDecl
        value.move< std::shared_ptr<Class> > (YY_MOVE (that.value));
        break;

      case 51: // classDeclList
        value.move< std::shared_ptr<ClassDeclList> > (YY_MOVE (that.value));
        break;

      case 52: // mainClass
        value.move< std::shared_ptr<ClassMain> > (YY_MOVE (that.value));
        break;

      case 56: // decl
        value.move< std::shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 59: // expr
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 55: // declList
        value.move< std::shared_ptr<List> > (YY_MOVE (that.value));
        break;

      case 50: // program
        value.move< std::shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case 58: // statement
        value.move< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 54: // statementList
        value.move< std::shared_ptr<StatementsList> > (YY_MOVE (that.value));
        break;

      case 57: // varDecl
        value.move< std::shared_ptr<Var> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 49: // type
        value.copy< Type > (that.value);
        break;

      case 4: // "-"
      case 5: // "+"
      case 6: // "*"
      case 7: // "/"
      case 8: // "&&"
      case 9: // "||"
      case 10: // "<"
      case 11: // ">"
      case 12: // "=="
      case 13: // "%"
      case 42: // "number"
      case 48: // intExpr
        value.copy< int > (that.value);
        break;

      case 53: // classDecl
        value.copy< std::shared_ptr<Class> > (that.value);
        break;

      case 51: // classDeclList
        value.copy< std::shared_ptr<ClassDeclList> > (that.value);
        break;

      case 52: // mainClass
        value.copy< std::shared_ptr<ClassMain> > (that.value);
        break;

      case 56: // decl
        value.copy< std::shared_ptr<Declaration> > (that.value);
        break;

      case 59: // expr
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case 55: // declList
        value.copy< std::shared_ptr<List> > (that.value);
        break;

      case 50: // program
        value.copy< std::shared_ptr<Program> > (that.value);
        break;

      case 58: // statement
        value.copy< std::shared_ptr<Statement> > (that.value);
        break;

      case 54: // statementList
        value.copy< std::shared_ptr<StatementsList> > (that.value);
        break;

      case 57: // varDecl
        value.copy< std::shared_ptr<Var> > (that.value);
        break;

      case 43: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 49: // type
        value.move< Type > (that.value);
        break;

      case 4: // "-"
      case 5: // "+"
      case 6: // "*"
      case 7: // "/"
      case 8: // "&&"
      case 9: // "||"
      case 10: // "<"
      case 11: // ">"
      case 12: // "=="
      case 13: // "%"
      case 42: // "number"
      case 48: // intExpr
        value.move< int > (that.value);
        break;

      case 53: // classDecl
        value.move< std::shared_ptr<Class> > (that.value);
        break;

      case 51: // classDeclList
        value.move< std::shared_ptr<ClassDeclList> > (that.value);
        break;

      case 52: // mainClass
        value.move< std::shared_ptr<ClassMain> > (that.value);
        break;

      case 56: // decl
        value.move< std::shared_ptr<Declaration> > (that.value);
        break;

      case 59: // expr
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case 55: // declList
        value.move< std::shared_ptr<List> > (that.value);
        break;

      case 50: // program
        value.move< std::shared_ptr<Program> > (that.value);
        break;

      case 58: // statement
        value.move< std::shared_ptr<Statement> > (that.value);
        break;

      case 54: // statementList
        value.move< std::shared_ptr<StatementsList> > (that.value);
        break;

      case 57: // varDecl
        value.move< std::shared_ptr<Var> > (that.value);
        break;

      case 43: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 49: // type
        yylhs.value.emplace< Type > ();
        break;

      case 4: // "-"
      case 5: // "+"
      case 6: // "*"
      case 7: // "/"
      case 8: // "&&"
      case 9: // "||"
      case 10: // "<"
      case 11: // ">"
      case 12: // "=="
      case 13: // "%"
      case 42: // "number"
      case 48: // intExpr
        yylhs.value.emplace< int > ();
        break;

      case 53: // classDecl
        yylhs.value.emplace< std::shared_ptr<Class> > ();
        break;

      case 51: // classDeclList
        yylhs.value.emplace< std::shared_ptr<ClassDeclList> > ();
        break;

      case 52: // mainClass
        yylhs.value.emplace< std::shared_ptr<ClassMain> > ();
        break;

      case 56: // decl
        yylhs.value.emplace< std::shared_ptr<Declaration> > ();
        break;

      case 59: // expr
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case 55: // declList
        yylhs.value.emplace< std::shared_ptr<List> > ();
        break;

      case 50: // program
        yylhs.value.emplace< std::shared_ptr<Program> > ();
        break;

      case 58: // statement
        yylhs.value.emplace< std::shared_ptr<Statement> > ();
        break;

      case 54: // statementList
        yylhs.value.emplace< std::shared_ptr<StatementsList> > ();
        break;

      case 57: // varDecl
        yylhs.value.emplace< std::shared_ptr<Var> > ();
        break;

      case 43: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 120 "parser.y"
                   { yylhs.value.as < std::shared_ptr<Program> > () = std::make_shared<Program>(yystack_[0].value.as < std::shared_ptr<ClassMain> > ()); driver.program = yylhs.value.as < std::shared_ptr<Program> > (); }
#line 889 "/tmp/miniJava/parser.cpp"
    break;

  case 3:
#line 121 "parser.y"
                                  { yylhs.value.as < std::shared_ptr<Program> > () = std::make_shared<Program>(yystack_[1].value.as < std::shared_ptr<ClassMain> > (), yystack_[0].value.as < std::shared_ptr<ClassDeclList> > ()); driver.program = yylhs.value.as < std::shared_ptr<Program> > (); }
#line 895 "/tmp/miniJava/parser.cpp"
    break;

  case 4:
#line 124 "parser.y"
                         { yylhs.value.as < std::shared_ptr<ClassDeclList> > () = std::make_shared<ClassDeclList>(); yylhs.value.as < std::shared_ptr<ClassDeclList> > ()->AddItem(yystack_[0].value.as < std::shared_ptr<Class> > ()); }
#line 901 "/tmp/miniJava/parser.cpp"
    break;

  case 5:
#line 125 "parser.y"
                                       { yylhs.value.as < std::shared_ptr<ClassDeclList> > () = yystack_[1].value.as < std::shared_ptr<ClassDeclList> > (); yylhs.value.as < std::shared_ptr<ClassDeclList> > ()->AddItem(yystack_[0].value.as < std::shared_ptr<Class> > ()); }
#line 907 "/tmp/miniJava/parser.cpp"
    break;

  case 6:
#line 128 "parser.y"
                                                                                  { yylhs.value.as < std::shared_ptr<ClassMain> > () = std::make_shared<ClassMain>(yystack_[2].value.as < std::shared_ptr<StatementsList> > ()); }
#line 913 "/tmp/miniJava/parser.cpp"
    break;

  case 7:
#line 131 "parser.y"
                                     { yylhs.value.as < std::shared_ptr<Class> > () = std::make_shared<Class>(yystack_[1].value.as < std::shared_ptr<List> > ()); }
#line 919 "/tmp/miniJava/parser.cpp"
    break;

  case 8:
#line 132 "parser.y"
                                                { yylhs.value.as < std::shared_ptr<Class> > () = std::make_shared<Class>(yystack_[1].value.as < std::shared_ptr<List> > ()); }
#line 925 "/tmp/miniJava/parser.cpp"
    break;

  case 9:
#line 135 "parser.y"
                         { yylhs.value.as < std::shared_ptr<StatementsList> > () = std::make_shared<StatementsList>(); yylhs.value.as < std::shared_ptr<StatementsList> > ()->AddItem(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 931 "/tmp/miniJava/parser.cpp"
    break;

  case 10:
#line 136 "parser.y"
                                       { yylhs.value.as < std::shared_ptr<StatementsList> > () = yystack_[1].value.as < std::shared_ptr<StatementsList> > (); yylhs.value.as < std::shared_ptr<StatementsList> > ()->AddItem(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 937 "/tmp/miniJava/parser.cpp"
    break;

  case 11:
#line 139 "parser.y"
                   { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<LocalVarDeclStmt>(yystack_[0].value.as < std::shared_ptr<Var> > ()); }
#line 943 "/tmp/miniJava/parser.cpp"
    break;

  case 12:
#line 140 "parser.y"
                                 { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<StmtListStmt>(yystack_[1].value.as < std::shared_ptr<StatementsList> > ()); }
#line 949 "/tmp/miniJava/parser.cpp"
    break;

  case 13:
#line 141 "parser.y"
                                     { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<If>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 955 "/tmp/miniJava/parser.cpp"
    break;

  case 14:
#line 142 "parser.y"
                                                    { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<IfElse>(yystack_[4].value.as < std::shared_ptr<Expression> > (), yystack_[2].value.as < std::shared_ptr<Statement> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 961 "/tmp/miniJava/parser.cpp"
    break;

  case 15:
#line 143 "parser.y"
                                        { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<While>(yystack_[2].value.as < std::shared_ptr<Expression> > (), yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 967 "/tmp/miniJava/parser.cpp"
    break;

  case 16:
#line 144 "parser.y"
                                           { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<PrintStmt>(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 973 "/tmp/miniJava/parser.cpp"
    break;

  case 41:
#line 197 "parser.y"
                    {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::AND     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 979 "/tmp/miniJava/parser.cpp"
    break;

  case 42:
#line 198 "parser.y"
                    {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::OR     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 985 "/tmp/miniJava/parser.cpp"
    break;

  case 43:
#line 199 "parser.y"
                        {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::GREATER     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 991 "/tmp/miniJava/parser.cpp"
    break;

  case 44:
#line 200 "parser.y"
                      {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::EQUAL     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 997 "/tmp/miniJava/parser.cpp"
    break;

  case 45:
#line 201 "parser.y"
                     {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::PLUS     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1003 "/tmp/miniJava/parser.cpp"
    break;

  case 46:
#line 202 "parser.y"
                      {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::MINUS     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1009 "/tmp/miniJava/parser.cpp"
    break;

  case 47:
#line 203 "parser.y"
                     {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::STAR     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1015 "/tmp/miniJava/parser.cpp"
    break;

  case 48:
#line 204 "parser.y"
                      {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::SLASH     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1021 "/tmp/miniJava/parser.cpp"
    break;

  case 49:
#line 205 "parser.y"
                    {yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<BinaryOp>(yystack_[2].value.as < std::shared_ptr<Expression> > (), BinaryOp::Operation::MOD     , yystack_[0].value.as < std::shared_ptr<Expression> > ());}
#line 1027 "/tmp/miniJava/parser.cpp"
    break;

  case 50:
#line 206 "parser.y"
                        { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<True>(); }
#line 1033 "/tmp/miniJava/parser.cpp"
    break;

  case 51:
#line 207 "parser.y"
                         { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<True>(); }
#line 1039 "/tmp/miniJava/parser.cpp"
    break;

  case 53:
#line 209 "parser.y"
         { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Id>(yystack_[0].value.as < std::string > ()); }
#line 1045 "/tmp/miniJava/parser.cpp"
    break;

  case 54:
#line 210 "parser.y"
              { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Int>(yystack_[0].value.as < int > ()); }
#line 1051 "/tmp/miniJava/parser.cpp"
    break;

  case 56:
#line 212 "parser.y"
           { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<True>(); }
#line 1057 "/tmp/miniJava/parser.cpp"
    break;

  case 57:
#line 213 "parser.y"
            { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<False>(); }
#line 1063 "/tmp/miniJava/parser.cpp"
    break;

  case 59:
#line 215 "parser.y"
               { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Not>(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1069 "/tmp/miniJava/parser.cpp"
    break;

  case 60:
#line 218 "parser.y"
                  { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1075 "/tmp/miniJava/parser.cpp"
    break;

  case 61:
#line 219 "parser.y"
                      { yylhs.value.as < int > () = -yystack_[0].value.as < int > (); }
#line 1081 "/tmp/miniJava/parser.cpp"
    break;


#line 1085 "/tmp/miniJava/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -68;

  const signed char parser::yytable_ninf_ = -40;

  const short
  parser::yypact_[] =
  {
      -9,   -11,    34,    20,    38,   -68,    16,    20,   -68,    27,
     -13,   -68,    30,    33,    25,    44,   -20,   -68,   -68,   -68,
     -68,    40,    67,    33,   -68,   -68,    73,   -68,   -68,    69,
      54,    61,    89,   -68,   -68,    94,    33,   102,   103,   -68,
     -68,   101,   104,   -10,   110,   -68,   112,   -68,    77,   114,
     109,   168,   168,   -68,   -68,   -20,    96,   176,   168,    88,
     -68,   -68,   -68,   118,   125,   176,   -68,     3,   176,   176,
     -68,    63,   -68,   -68,   347,   121,    98,   -68,   -68,   -68,
     279,   -68,   133,   131,   176,   176,   236,   219,   367,   -68,
     -68,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   105,   -68,   129,   -68,   -68,   136,   296,   313,   -68,
     -68,    43,    43,    35,    35,   357,   357,    90,   367,   347,
     330,   138,   -68,   -68,   168,   168,   -68,   176,   126,   -68,
     261,   140,   168,   176,   -68,   -68,   -68
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     3,     4,     0,
       0,     5,     0,     0,     0,     0,     0,    35,    36,    37,
      39,     0,     0,    22,    24,    25,    33,    38,    34,     0,
       0,     0,     0,     7,    23,     0,     0,     0,     0,    26,
      40,     0,     0,     0,     0,     8,     0,    28,     0,     0,
      30,     0,     0,    32,    29,     0,     0,     0,     0,     0,
      55,    56,    57,     0,     0,     0,    60,    53,     0,     0,
      54,     0,    11,     9,     0,    58,     0,    31,    61,    53,
       0,    58,     0,     0,     0,     0,     0,     0,    59,    27,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    52,    12,     0,     0,     0,    17,
      16,    46,    45,    47,    48,    41,    42,    43,    44,    49,
       0,     0,     6,    51,     0,     0,    50,     0,    13,    15,
      20,     0,     0,     0,    19,    14,    21
  };

  const short
  parser::yypgoto_[] =
  {
     -68,   -68,    -8,   -68,   -68,   -68,   146,   -46,   -12,   -68,
      39,   -67,   -55,   -51,    28,   -68,   -68,   108,   -68,   -68,
     106,   -68
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    70,    21,     2,     7,     3,     8,    71,    22,    23,
      72,    73,    74,    81,   131,    25,    44,    49,    50,    26,
      27,    28
  };

  const short
  parser::yytable_[] =
  {
      75,    75,    80,    13,    90,    47,    76,    75,    31,    90,
      86,    34,    82,    87,    88,    90,    17,    18,    19,    14,
      75,   -39,     1,    20,    41,    75,    17,    18,    19,   107,
     108,    75,     4,    20,     5,    48,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   -39,    48,    99,    93,
      94,     6,    24,   100,     9,   101,    99,   128,   129,    10,
      12,   100,    24,   101,    15,   135,    16,    56,    29,    17,
      18,    19,   130,    75,    75,    24,    20,    57,   130,    58,
      89,    75,    30,    32,    33,    36,    59,    60,    61,    62,
      63,    35,    64,    37,    91,    92,    93,    94,    65,    17,
      18,    19,    56,    99,    38,    66,    67,    68,   100,    69,
     101,    39,    57,    40,    58,   103,    42,    43,    45,    46,
      53,    59,    60,    61,    62,    63,    51,    64,    52,    54,
      55,    20,    84,    65,    17,    18,    19,    56,    78,    85,
      66,    67,    68,   102,    69,   106,   122,    57,   121,    58,
     105,   123,   127,    11,   132,   134,    59,    60,    61,    62,
      63,   136,    64,    77,     0,    83,     0,     0,    65,    17,
      18,    19,    56,     0,     0,    66,    67,    68,     0,    69,
      56,     0,    57,     0,    58,     0,     0,     0,     0,     0,
      57,    59,    60,    61,    62,    63,     0,    64,     0,    59,
      60,    61,    62,    65,    17,    18,    19,     0,     0,     0,
      66,    67,    68,     0,    69,     0,     0,     0,    66,    79,
       0,     0,    69,    91,    92,    93,    94,    95,    96,     0,
      97,    98,    99,     0,     0,     0,     0,   100,     0,   101,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
       0,     0,     0,     0,   100,     0,   101,     0,   109,     0,
       0,     0,     0,     0,   110,    91,    92,    93,    94,    95,
      96,     0,    97,    98,    99,     0,     0,     0,     0,   100,
       0,   101,   133,    91,    92,    93,    94,    95,    96,     0,
      97,    98,    99,     0,   104,     0,     0,   100,     0,   101,
      91,    92,    93,    94,    95,    96,     0,    97,    98,    99,
       0,   124,     0,     0,   100,     0,   101,    91,    92,    93,
      94,    95,    96,     0,    97,    98,    99,     0,   125,     0,
       0,   100,     0,   101,    91,    92,    93,    94,    95,    96,
       0,    97,    98,    99,     0,     0,     0,     0,   100,   126,
     101,    91,    92,    93,    94,    95,    96,     0,    97,    98,
      99,    91,    92,    93,    94,   100,     0,   101,    97,    98,
      99,    91,    92,    93,    94,   100,     0,   101,    97,     0,
      99,     0,     0,     0,     0,   100,     0,   101
  };

  const short
  parser::yycheck_[] =
  {
      51,    52,    57,    16,    71,    15,    52,    58,    16,    76,
      65,    23,    58,    68,    69,    82,    36,    37,    38,    32,
      71,    18,    31,    43,    36,    76,    36,    37,    38,    84,
      85,    82,    43,    43,     0,    43,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    43,    55,    13,     6,
       7,    31,    13,    18,    16,    20,    13,   124,   125,    43,
      33,    18,    23,    20,    34,   132,    33,     4,    43,    36,
      37,    38,   127,   124,   125,    36,    43,    14,   133,    16,
      17,   132,    38,    43,    17,    16,    23,    24,    25,    26,
      27,    18,    29,    39,     4,     5,     6,     7,    35,    36,
      37,    38,     4,    13,    43,    42,    43,    44,    18,    46,
      20,    22,    14,    19,    16,    17,    14,    14,    17,    15,
      43,    23,    24,    25,    26,    27,    16,    29,    16,    15,
      21,    43,    14,    35,    36,    37,    38,     4,    42,    14,
      42,    43,    44,    22,    46,    14,    17,    14,    43,    16,
      17,    15,    14,     7,    28,    15,    23,    24,    25,    26,
      27,   133,    29,    55,    -1,    59,    -1,    -1,    35,    36,
      37,    38,     4,    -1,    -1,    42,    43,    44,    -1,    46,
       4,    -1,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      14,    23,    24,    25,    26,    27,    -1,    29,    -1,    23,
      24,    25,    26,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    43,    44,    -1,    46,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    45,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    -1,    15,    -1,    -1,    18,    -1,    20,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      -1,    15,    -1,    -1,    18,    -1,    20,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    -1,    15,    -1,
      -1,    18,    -1,    20,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,     4,     5,     6,     7,    18,    -1,    20,    11,    12,
      13,     4,     5,     6,     7,    18,    -1,    20,    11,    -1,
      13,    -1,    -1,    -1,    -1,    18,    -1,    20
  };

  const signed char
  parser::yystos_[] =
  {
       0,    31,    50,    52,    43,     0,    31,    51,    53,    16,
      43,    53,    33,    16,    32,    34,    33,    36,    37,    38,
      43,    49,    55,    56,    57,    62,    66,    67,    68,    43,
      38,    49,    43,    17,    55,    18,    16,    39,    43,    22,
      19,    55,    14,    14,    63,    17,    15,    15,    49,    64,
      65,    16,    16,    43,    15,    21,     4,    14,    16,    23,
      24,    25,    26,    27,    29,    35,    42,    43,    44,    46,
      48,    54,    57,    58,    59,    60,    54,    64,    42,    43,
      59,    60,    54,    67,    14,    14,    59,    59,    59,    17,
      58,     4,     5,     6,     7,     8,     9,    11,    12,    13,
      18,    20,    22,    17,    15,    17,    14,    59,    59,    22,
      45,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    43,    17,    15,    15,    15,    19,    14,    58,    58,
      59,    61,    28,    21,    15,    58,    61
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    58,    58,    58,    58,    58,    58,    58,    58,    60,
      61,    61,    55,    55,    56,    56,    57,    62,    63,    63,
      64,    64,    65,    49,    49,    66,    66,    66,    66,    67,
      68,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      48,    48
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,    13,     5,     7,     1,
       2,     1,     3,     5,     7,     5,     3,     3,     2,     6,
       1,     3,     1,     2,     1,     1,     3,     7,     2,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     4,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"&&\"", "\"||\"", "\"<\"", "\">\"", "\"==\"",
  "\"%\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\".\"",
  "\",\"", "\";\"", "\"new\"", "\"this\"", "\"true\"", "\"false\"",
  "\"if\"", "\"else\"", "\"while\"", "\"assert\"", "\"class\"",
  "\"extends\"", "\"public\"", "\"static\"", "\"return\"", "\"int\"",
  "\"boolean\"", "\"void\"", "\"main\"", "\"System.out.println\"",
  "\"length\"", "\"number\"", "\"identifier\"", "\"System.out.println(\"",
  "\");\"", "NOT", "$accept", "intExpr", "type", "program",
  "classDeclList", "mainClass", "classDecl", "statementList", "declList",
  "decl", "varDecl", "statement", "expr", "methodCall", "rvalArgs",
  "methodDecl", "argList", "args", "arg", "primitiveType", "typeId",
  "arrayType", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   120,   120,   121,   124,   125,   128,   131,   132,   135,
     136,   139,   140,   141,   142,   143,   144,   146,   147,   150,
     153,   154,   157,   157,   160,   160,   163,   166,   169,   169,
     172,   172,   175,   178,   178,   181,   181,   181,   181,   184,
     187,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     218,   219
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1611 "/tmp/miniJava/parser.cpp"

#line 224 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
