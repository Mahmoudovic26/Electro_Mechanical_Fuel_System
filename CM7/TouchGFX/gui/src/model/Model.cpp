#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#include "stm32h7xx_hal.h"  // For STM32H7 HAL functions
#define HSEM_ID 0

extern uint32_t __attribute__((section(".share_data"))) num;
volatile bool data_updated = false;

// In M7, set up interrupt handler for M4 notifications
void HAL_HSEM_FreeCallback(uint32_t SemMask) {
    if (SemMask == HSEM_ID) {
        data_updated = true;
    }
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    SCB_InvalidateDCache_by_Addr((uint32_t*)&num, sizeof(num));
    if (modelListener)
        {
            modelListener->updateNumber(num);  // This calls your presenter!
        }
        data_updated = false;  // Reset the flag after processing
}
