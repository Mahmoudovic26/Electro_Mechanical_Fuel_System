#include <gui/main_screen/mainView.hpp>
#include <gui/main_screen/mainPresenter.hpp>

mainPresenter::mainPresenter(mainView& v)
    : view(v)
{

}

void mainPresenter::activate()
{

}

void mainPresenter::deactivate()
{

}

void mainPresenter::updateNumber(uint32_t number)
{
    view.setNum(number);
}