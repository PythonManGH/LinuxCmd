#ifndef CMDHWINFOSOUND_H
#define CMDHWINFOSOUND_H

#include "CmdHwinfo.h"

class CmdHwinfoSound : public CmdHwinfo
{
public:
    CmdHwinfoSound();

protected:
    /**
     * @brief initInfo 初始化信息
     */
    void initInfo() override;
};

#endif // CMDHWINFOSOUND_H
