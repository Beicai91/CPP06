#include "ScalarConverter.hpp"

//constructors, destructor and operator
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}
ScalarConverter::~ScalarConverter(){}

//other private or public funcs
bool    ScalarConverter::_isInt(const std::string &input)
{
    unsigned int i;

    i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length())
    {
        if (input[i] < '0' || input[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

bool    ScalarConverter::_isDouble(const std::string &input)
{
    unsigned int i;

    i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length())
    {
        if (input[i] == '.')
            break;
        if (input[i] < '0' || input[i] > '9')
            return (false);
        i++;
    }
    if (i == input.length() || i == input.length() - 1)
        return (false); //it is an int or something like 42. in this case
    else
    {
        i++;
        while (i < input.length())
        {
            if (input[i] < '0' || input[i] > '9')
                return (false);
            i++;
        }
    }
    return (true);
}

bool    ScalarConverter::_isFloat(const std::string &input)
{
    unsigned int i;

    if (input[input.length() - 1] != 'f')
        return (false);
    i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length())
    {
        if (input[i] == '.')
            break;
        if (input[i] < '0' || input[i] > '9')
            return (false);
        i++;
    }
    if (i == input.length() || i == input.length() - 2)
        return (false); //it is an int or something like 42.f in this case
    else
    {
        i++;
        while (i < input.length() - 1)
        {
            if (input[i] < '0' || input[i] > '9')
                return (false);
            i++;
        }
    }
    return (true);
}

t_type  ScalarConverter::_parseInput(const std::string &input)
{
    if (input.compare("-inff") == 0 || input.compare("+inff") == 0 || input.compare("-inf") == 0 || input.compare("+inf") == 0)
        return (INF);
    if (input.compare("nanf") == 0 || input.compare("nan") == 0)
        return (NN);
    if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
        return (CHAR);
    if (_isInt(input))
        return (INT);
    if (_isDouble(input))
        return (DOUBLE);
    if (_isFloat(input))
        return (FLOAT);
    return (ERR);
}

void    ScalarConverter::_fromInt(const std::string &input)
{
    int res;

    try
    {
        res = std::stoi(input);
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "Caught out-of-range exception: " << e.what() << std::endl;
    }
    _printChar(static_cast<char>(res));
    _printInt(res);
    _printFloat(static_cast<float>(res));
    _printDouble(static_cast<double>(res));
}

void    ScalarConverter::_fromDouble(const std::string &input)
{
    double  res;

    try
    {
        res = std::stod(input);
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "Caught out-of-range exception: " << e.what() << std::endl;
    }
    _printChar(static_cast<char>(res));
    _printInt(static_cast<int>(res));
    _printFloat(static_cast<float>(res));
    _printDouble(res);
}

void    ScalarConverter::_fromFloat(const std::string &input)
{
    float   res;

    try
    {
        res = std::stof(input);
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "Caught out-of-range exception: " << e.what() << std::endl;
    }
    _printChar(static_cast<char>(res));
    _printInt(static_cast<int>(res));
    _printFloat(res);
    _printDouble(static_cast<double>(res));
}

void    ScalarConverter::_fromNan(const std::string &input)
{
    (void)input;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double nan" << std::endl;
}

void    ScalarConverter::_fromInf(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (input[0] == '-')
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void    ScalarConverter::_fromChar(const std::string &input)
{
    char    res;

    res = input[0];
    _printChar(res);
    _printInt(static_cast<int>(res));
    _printFloat(static_cast<float>(res));
    _printDouble((static_cast<double>(res)));
}

void    ScalarConverter::_reportErr(const std::string &input)
{
    std::cout << "The input " << input << " is not valid" << std::endl;
}

void    ScalarConverter::_printChar(char c)
{
    if (c <= 31 || c >= 127)
        std::cout << "char: non playable" << std::endl;
    else
        std::cout << "char: \'" << c << "\'" << std::endl;
}

void    ScalarConverter::_printInt(int num)
{
    std::cout << "int: " << num << std::endl;
}

void    ScalarConverter::_printFloat(float num)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << num << 'f' << std::endl;
}

void    ScalarConverter::_printDouble(double num)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}


void  ScalarConverter::convert(std::string str)
{
    t_type  type;
    t_type  types[] = {ERR, CHAR, INT, DOUBLE, FLOAT, NN, INF};
    convertFuncs    helpers[] = {_reportErr, _fromChar, _fromInt, _fromDouble, _fromFloat, _fromNan, _fromInf};

    type = _parseInput(str);
    //test
    std::cout << "type: " << type << std::endl;
    //
    for (int i = 0; i < 7; ++i)
    {
        if (type == types[i])
            helpers[i](str);
    }
}