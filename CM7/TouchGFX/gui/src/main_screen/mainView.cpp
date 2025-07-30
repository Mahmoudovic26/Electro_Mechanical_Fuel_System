#include <gui/main_screen/mainView.hpp>
#include <cstdint>
uint32_t __attribute__((section(".share_data"))) num ;

mainView::mainView()
{

}

void mainView::setupScreen()
{
    mainViewBase::setupScreen();
}

void mainView::tearDownScreen()
{
    mainViewBase::tearDownScreen();
}
void mainView::setNum(int number)
{
   Unicode::snprintf(companyNameBuffer, COMPANYNAME_SIZE, "%d", number);
   companyName.invalidate();
}