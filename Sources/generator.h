

#ifndef GENERATOR
#define GENERATOR

<<<<<<< HEAD
namespace Logic
{

=======
#include <string>
>>>>>>> 77177ef373bc97d8dfee11fc6a8fb29ef31a81e1

class BaseGenerator
{
public:
    virtual ~BaseGenerator(){;};
    virtual void generate()=0;
    virtual void receiveData(std::vector<std::string> strv,int parserId)=0;
    virtual void notify(int id)=0;
};

}

#endif // GENERATOR

