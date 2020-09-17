#ifndef CMDHWINFOKEYBOARD_H
#define CMDHWINFOKEYBOARD_H

#include "CmdHwinfo.h"

class CmdHwinfoKeyboard : public CmdHwinfo
{
public:
    CmdHwinfoKeyboard();
protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOKEYBOARD_H
