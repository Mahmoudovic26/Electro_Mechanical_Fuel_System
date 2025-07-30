#ifndef MODEL_HPP
#define MODEL_HPP
#include <cstdint>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
};
extern uint32_t __attribute__((section(".share_data"))) num;

#endif // MODEL_HPP
