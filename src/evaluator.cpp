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
	for (int i = 0;i < expression.length();++i) //iterate over entire string
	{
		current_char = expression[i];
		if (isdigit(current_char)) //GETTING THE FULL NUMBER
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
		if (isOperator(current_char)) //GETTING THE FULL OPERATOR
		{
			spaced_expression += current_char;
			if (current_char == expression[i + 1] && (current_char == '&' || current_char == '|'))
			{
				spaced_expression += expression[i + 1];
				++i;
			}
			if (previous_type != "Number") //checks for cases where there are multiple - or +
			{
				if (current_char == expression[i + 1] && (current_char == '+' || current_char == '-')) //creates proper increment and decrement
				{
					spaced_expression += expression[i + 1];
					++i;
				}
				if (current_char == '-' && isdigit(expression[i + 1])) //checks for negative numbers and adds them to expression as a number that is negative
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
			if ((current_char == '>' || current_char == '<' || current_char == '=' || current_char == '!') && expression[i + 1] == '=') //comparison operators
			{
				spaced_expression += expression[i + 1];
				++i;

			}
			if (isdigit(spaced_expression[spaced_expression.length() - 1])) //sets the previous type for use in conditional above
				previous_type = "Number";
			else
				previous_type = "Operator";
		}
		spaced_expression += " "; //adds spaces to properly read as tokens
	}
	return spaced_expression;
}
