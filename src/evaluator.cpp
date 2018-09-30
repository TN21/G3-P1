#include "evaluator.h"
#include <string>

using std::string;

Evaluator::Evaluator() {
    
}

int Evaluator::evaluate(string & rawExpression) {
    
}
string Evaluator::addSpaces(string expression)
{
	char current_char;
	string spaced_expression = "";
	string previous_type = "None";
	for (int i = 0;i < expression.length();++i)
	{
		current_char = expression[i];
		if (isdigit(current_char))
		{
			while (isdigit(current_char))
			{
				spaced_expression += current_char;
				++i;
				current_char = expression[i];
			}
			previous_type = "Number";
			spaced_expression += " ";
		}
		if (isOperator(current_char))
		{
			spaced_expression += current_char;
			if (current_char == expression[i + 1] && (current_char == '&' || current_char == '|'))
			{
				spaced_expression += expression[i + 1];
				++i;
			}
			if (previous_type != "Number")
			{
				if (current_char == expression[i + 1] && (current_char == '+' || current_char == '-'))
				{
					spaced_expression += expression[i + 1];
					++i;
				}
				if (current_char == '-' && isdigit(expression[i + 1]))
				{
					++i;
					current_char = expression[i];
					while (isdigit(current_char))
					{
						spaced_expression += current_char;
						++i;
						current_char = expression[i];
					}
					--i;
				}
			}
			if ((current_char == '>' || current_char == '<' || current_char == '=' || current_char == '!') && expression[i + 1] == '=')
			{
				spaced_expression += expression[i + 1];
				++i;

			}
			if (isdigit(spaced_expression[spaced_expression.length() - 1]))
				previous_type = "Number";
			else
				previous_type = "Operator";
		}
		spaced_expression += " ";
	}
	return spaced_expression;
}
