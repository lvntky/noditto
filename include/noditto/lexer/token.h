#ifndef TOKEN_H_
#define TOKEN_H_

#include <noditto/lexer/token_type>
#include <string>

typedef struct token
{
    enum TokenType type;
    std::string value;
    int line;
    int column;
} token_t;

#endif //TOKEN_H_
