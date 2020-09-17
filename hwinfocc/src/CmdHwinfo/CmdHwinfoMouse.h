#ifndef CMDHWINFOMOUSE_H
#define CMDHWINFOMOUSE_H

#include "CmdHwinfo.h"

class CmdHwinfoMouse : public CmdHwinfo
{
public:
    CmdHwinfoMouse();
protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOMOUSE_H
