#include "MainWindow.h"
#include "CmdHwinfo/CmdHwinfoMonitor.h"
#include "CmdHwinfo/CmdHwinfoMouse.h"
#include "CmdHwinfo/CmdHwinfoKeyboard.h"
#include "CmdHwinfo/CmdHwinfoGpu.h"
#include "CmdHwinfo/CmdHwinfoNetwork.h"
#include "CmdHwinfo/CmdHwinfoSound.h"
#include "CmdHwinfo/CmdHwinfoUsb.h"


MainWindow::MainWindow()
{
    CmdHwinfoUsb device;
    device.printInfo();
}
