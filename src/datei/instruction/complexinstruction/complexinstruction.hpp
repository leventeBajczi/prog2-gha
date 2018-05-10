#ifndef _COMPLEXINSTRUCTION
#define _COMPLEXINSTRUCTION

#include "../instruction.hpp"
#include "../simpleinstruction/simpleinstruction.hpp"
#include <vector>
class ComplexInstruktion : public Instruktion
{
    private:
        std::vector<SimpleInstruktion> instructions;
    public:
        ComplexInstruktion(std::string);
        ComplexInstruktion(std::string, SimpleInstruktion&);
        std::string print();
        void run();
        

};

#endif