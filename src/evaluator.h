#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
using std::string;
class Evaluator {
    public:
        Evaluator();
        int evaluate(string & rawExpression);
};
#endif