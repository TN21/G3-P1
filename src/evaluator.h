#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
using std::string;
class Evaluator {
    public:
        Evaluator();
        int evaluate(string & rawExpression);
        string addSpaces(string expresion);
        bool precedenceCompare(string op1, string op2);
};
#endif
