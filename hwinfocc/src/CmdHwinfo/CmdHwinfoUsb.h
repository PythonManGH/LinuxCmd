#ifndef CMDHWINFOUSB_H
#define CMDHWINFOUSB_H

#include "CmdHwinfo.h"

class CmdHwinfoUsb : public CmdHwinfo
{
public:
    CmdHwinfoUsb();

protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOUSB_H
