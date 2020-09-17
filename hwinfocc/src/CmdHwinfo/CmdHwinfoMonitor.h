#ifndef CMDHWINFOMONITOR_H
#define CMDHWINFOMONITOR_H

#include "CmdHwinfo.h"

class CmdHwinfoMonitor : public CmdHwinfo
{
public:
    CmdHwinfoMonitor();

protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOMONITOR_H
