//
// Generated by dtk
// Translation Unit: JASTrack.cpp
//

#include "JSystem/JAudio/JASTrack.h"
#include "JSystem/JAudio/JASBankMgr.h"
#include "JSystem/JAudio/JASCalc.h"
#include "JSystem/JAudio/JASChannel.h"
#include "JSystem/JAudio/JASChGlobal.h"
#include "JSystem/JAudio/JASPlayer.h"
#include "JSystem/JAudio/JASSystemHeap.h"
#include "JSystem/JAudio/JASRate.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 80280960-80280A34       .text __ct__Q28JASystem6TTrackFv */
JASystem::TTrack::TTrack() {
    mParent = NULL;
    field_0x364 = 0.0f;
    field_0x368 = 0.0f;
    field_0x36c = 0;
    mUpdateFlags = 0;
    field_0x374 = 0;
    field_0x376 = 0x78;
    field_0x378 = 0x78;
    field_0x37a = 0;
    field_0x37b = 0;
    mPauseStatus = 0;
    mVolumeMode = 0;
    field_0x37e = 0;
    mIsPaused = 0;
    field_0x386 = 0;
    field_0x387 = 0;
    field_0x388 = 0;
    field_0x389 = 0;
    mChannelUpdater.init();
    for (int i = 0; i < 12; i++) {
        field_0x304[i] = Player::sAdsTable[i];
    }
    Calc::bzero(&mTimedParam, sizeof(TimedParam_));
}

/* 80280A34-80280A80       .text __ct__Q38JASystem6TTrack11TimedParam_Fv */
JASystem::TTrack::TimedParam_::TimedParam_() {}

/* 80280A80-80280C10       .text init__Q28JASystem6TTrackFv */
void JASystem::TTrack::init() {
    mSeqCtrl.init();
    mTrackPort.init();
    field_0x88.init();
    mNoteMgr.init();
    mChannelUpdater.initAllocChannel(0);
    initTimed();
    mRegisterParam.init();
    mOscRoute[0] = 0x0f;
    field_0x2cc[0] = Player::sEnvelopeDef;
    mOscRoute[1] = 0x0f;
    field_0x2cc[1] = Player::sEnvelopeDef;
    mParent = NULL;
    for (int i = 0; i < 16; i++) {
        mChildren[i] = NULL;
    }
    if (mOuterParam) {
        mOuterParam->initExtBuffer();
    }
    field_0x364 = 0.0f;
    field_0x368 = 1.0f;
    field_0x36c = 0;
    mVibrate.init();
    mUpdateFlags = 0;
    field_0x374 = 0;
    field_0x376 = 0x78;
    field_0x378 = 0x30;
    updateTempo();
    field_0x37a = 0;
    field_0x37b = 0;
    mPauseStatus = 10;
    mVolumeMode = 0;
    field_0x37e = 0;
    for (int i = 0; i < 3; i++) {
        mCalcTypes[i] = 0;
        mParentCalcTypes[i] = 0;
        mChannelUpdater.mCalcTypes[i] = 0x0d;
    }
    mIsPaused = 0;
    field_0x386 = 0;
    field_0x387 = 1;
    field_0x388 = 0;
}

/* 80280C10-80280D0C       .text inherit__Q28JASystem6TTrackFv */
void JASystem::TTrack::inherit() {
    if (!mParent) {
        return;
    }
    field_0x376 = mParent->field_0x376;
    field_0x388 = 0;
    field_0x368 = mParent->field_0x368;
    field_0x378 = mParent->field_0x378;
    field_0x387 = mParent->field_0x387;
    mIsPaused = mParent->mIsPaused;
    mPauseStatus = mParent->mPauseStatus;
    mVolumeMode = mParent->mVolumeMode;
    field_0x386 = mParent->field_0x386;
    if (field_0x37b & 2) {
        return;
    }
    mRegisterParam.inherit(mParent->mRegisterParam);
    for (int i = 0; i < 3; i++) {
        mCalcTypes[i] = mParent->mCalcTypes[i];
        mParentCalcTypes[i] = mParent->mParentCalcTypes[i];
        mChannelUpdater.mCalcTypes[i] = mParent->mChannelUpdater.mCalcTypes[i];
    }
}

u16 (*JASystem::TTrack::sCallBackFunc)(JASystem::TTrack*, u16);
JASystem::TSeqParser JASystem::TTrack::sParser;

/* 80280D0C-80280F80       .text mainProc__Q28JASystem6TTrackFv */
s8 JASystem::TTrack::mainProc() {
    /* Nonmatching */
    int r31 = 0;
    if (field_0x388 && mParent) {
        f32 tmp = f32(field_0x376) / f32(mParent->field_0x376);
        if (tmp > 1.0f) {
            tmp = 1.0f;
        }
        field_0x364 += tmp;
        if (field_0x364 < 1.0f) {
            return 0;
        }
        field_0x364 -= 1.0f;
    }
    if (mParent && mChannelUpdater.field_0x0) {
        TChannel* channel = mChannelUpdater.getListHead(0);
        if (channel) {
            mParent->mChannelUpdater.addListHead(channel, 0);
            channel->field_0x4 = &mParent->mChannelUpdater;
            mChannelUpdater.field_0x0--;
            mParent->mChannelUpdater.field_0x0++;
        }
    }
    field_0x88.request(7);
    field_0x88.timerProcess();
    tryInterrupt();
    if (mIsPaused == 0 && (mPauseStatus & 2) == 0) {
        // TODO:
    }
    updateSeq(0, false);
    if (r31 < 0) {
        return -1;
    }
    for (int i = 0; i < 16; i++) {
        TTrack* child = mChildren[i];
        if (child && child->field_0x37e) {
            JUT_ASSERT(276, this == child->mParent);
            if (child->mainProc() == -1) {
                child->close();
                mChildren[i] = NULL;
            }
        }
    }
    return 0;
}

/* 80280F80-80280FA8       .text setInterrupt__Q28JASystem6TTrackFUs */
void JASystem::TTrack::setInterrupt(u16 param_1) {
    field_0x88.request(param_1);
}

/* 80280FA8-80281004       .text tryInterrupt__Q28JASystem6TTrackFv */
bool JASystem::TTrack::tryInterrupt() {
    if (mSeqCtrl.mPreviousFilePtr) {
        return false;
    }
    void* var1 = field_0x88.checkIntr();
    if (var1 == NULL) {
        return false;
    }
    return mSeqCtrl.callIntr(var1);
}

/* 80281004-8028100C       .text assignExtBuffer__Q28JASystem6TTrackFPQ38JASystem6TTrack11TOuterParam */
void JASystem::TTrack::assignExtBuffer(TOuterParam* param_1) {
    mOuterParam = param_1;
}

/* 8028100C-80281050       .text releaseChannelAll__Q28JASystem6TTrackFv */
void JASystem::TTrack::releaseChannelAll() {
    if (mParent) {
        mParent->mChannelUpdater.receiveAllChannels(&mChannelUpdater);
    } else {
        TGlobalChannel::releaseAll(&mChannelUpdater);
    }
}

/* 80281050-80281088       .text flushAll__Q28JASystem6TTrackFv */
void JASystem::TTrack::flushAll() {
    mChannelUpdater.stopAll();
    mChannelUpdater.stopAllRelease();
}

/* 80281088-80281138       .text moveFreeChannel__Q28JASystem6TTrackFPQ28JASystem11TChannelMgrPQ28JASystem11TChannelMgri */
int JASystem::TTrack::moveFreeChannel(TChannelMgr* param_1, TChannelMgr* param_2, int param_3) {
    if (param_3 < 0) {
        u32 r31 = param_1->field_0x0;
        param_2->receiveAllChannels(param_1);
        return r31;
    }
    for (int i = 0; i < param_3; i++) {
        if (!param_1->field_0x0) {
            break;
        }
        TChannel* channel = param_1->getListHead(0);
        if (!channel) {
            break;
        }
        param_1->field_0x0--;
        param_2->addListHead(channel, 0);
        param_2->field_0x0++;
    }
    return 0;
}

/* 80281138-802811DC       .text initTimed__Q28JASystem6TTrackFv */
void JASystem::TTrack::initTimed() {
    for (u8 i = 0; i < 18; i++) {
        mTimedParam.mMoveParams[i].mMoveTime = 0.0f;
        mTimedParam.mMoveParams[i].mCurrentValue = 1.0f;
        mTimedParam.mMoveParams[i].mTargetValue = 1.0f;
    }
    mTimedParam.mMoveParams[1].mCurrentValue = 0.0f;
    mTimedParam.mMoveParams[1].mTargetValue = 0.0f;
    mTimedParam.mMoveParams[3].mCurrentValue = 0.5f;
    mTimedParam.mMoveParams[3].mTargetValue = 0.5f;
    mTimedParam.mMoveParams[16].mCurrentValue = 0.5f;
    mTimedParam.mMoveParams[16].mTargetValue = 0.5f;
    mTimedParam.mMoveParams[17].mCurrentValue = 0.0f;
    mTimedParam.mMoveParams[17].mTargetValue = 0.0f;
    mTimedParam.mMoveParams[2].mCurrentValue = 0.0f;
    mTimedParam.mMoveParams[2].mTargetValue = 0.0f;
    mTimedParam.mMoveParams[4].mCurrentValue = 0.0f;
    mTimedParam.mMoveParams[4].mTargetValue = 0.0f;
    for (u8 i = 1; i < 4; i++) {
        mTimedParam.mMoveParams[i + 12].mCurrentValue = 0.0f;
        mTimedParam.mMoveParams[i + 12].mTargetValue = 0.0f;
    }
    mTimedParam.mMoveParams[5].mCurrentValue = 0.0f;
    mTimedParam.mMoveParams[5].mTargetValue = 0.0f;
}

static void dummy() {
    OSReport("i >= 0");
    OSReport("i < 3");
}

/* 802811DC-80281258       .text connectBus__Q28JASystem6TTrackFii */
void JASystem::TTrack::connectBus(int line, int param_2) {
    JUT_ASSERT(486, line < (6));
    mChannelUpdater.field_0x4e[line] = param_2;
}

/* 80281258-802814AC       .text noteOn__Q28JASystem6TTrackFUclllUl */
int JASystem::TTrack::noteOn(u8 param_1, s32 param_2, s32 param_3, s32 param_4, u32 param_5) {
    if (field_0x386 && (mPauseStatus & 0x40)) {
        return -1;
    }
    noteOff(param_1, 0);
    TChannelMgr* r31 = &mChannelUpdater;
    TTrack* parent = mParent;
    while (r31->field_0x0 == 0 || r31->field_0x8 == 0) {
        if (!parent) {
            r31 = &mChannelUpdater;
            break;
        }
        r31 = &parent->mChannelUpdater;
        parent = parent->mParent;
    }
    if (field_0x37b == 4) {
        JUT_ASSERT(527, mParent != NULL);
        if (r31 != &mParent->mChannelUpdater) {
            if (moveFreeChannel(r31, &mParent->mChannelUpdater, 1) != 1) {
                OSReport("in Player (NOTE-MODE) ... ボイス借用に失敗しました！！ (%d)\n", r31->field_0x0);
            }
            r31 = &mParent->mChannelUpdater;
        }
    } else if (r31 != &mChannelUpdater) {
        if (moveFreeChannel(r31, &mChannelUpdater, 1) != 1) {
            OSReport("in Player ボイス借用に失敗しました！！ (%d)\n", r31->field_0x0);
        }
        r31 = &mChannelUpdater;
    }
    u8 bankNum = mRegisterParam.getBankNumber();
    u8 physNum = BankMgr::getPhysicalNumber(bankNum);
    u8 progNum = mRegisterParam.getProgramNumber();
    TChannel* channel = BankMgr::noteOn(r31, physNum, progNum, param_2, param_3, param_4);
    if (!channel) {
        return -1;
    }
    mNoteMgr.setChannel(param_1, channel);
    channel->field_0xe8 = param_5;
    channel->setPanPower(mRegisterParam.mPanPower[0], mRegisterParam.mPanPower[1], mRegisterParam.mPanPower[2], 0.0f);
    overwriteOsc(channel);
    if (field_0x374) {
        channel->directReleaseOsc(0, field_0x374);
    }
    return 0;
}

/* 802814AC-802815DC       .text overwriteOsc__Q28JASystem6TTrackFPQ28JASystem8TChannel */
void JASystem::TTrack::overwriteOsc(TChannel* param_1) {
    /* Nonmatching */
    u32 r28;
    for (int i = 0; i < 2; i++) {
        u32 var1 = mOscRoute[i];
        if (var1 == 0x0f) {
            continue;
        }
        r28 = var1 & 3;
        if (var1 & 8) {
            if (!param_1->isOsc(r28)) {
                JUT_WARN(593, "%s", "cannot copy osc");
                continue;
            }
            param_1->copyOsc(r28, &field_0x2cc[i]);
        } else if (var1 & 4) {
            s16* var4 = field_0x2cc[i].rel_table;
            if (!param_1->isOsc(r28)) {
                JUT_WARN(603, "%s", "cannot copy osc");
                continue;
            }
            param_1->copyOsc(r28, &field_0x2cc[i]);
            field_0x2cc[i].rel_table = var4;
        }
        param_1->overwriteOsc(r28, &field_0x2cc[i]);
    }
}

/* 802815DC-8028165C       .text noteOff__Q28JASystem6TTrackFUcUs */
bool JASystem::TTrack::noteOff(u8 param_1, u16 param_2) {
    TChannel* channel = mNoteMgr.getChannel(param_1);
    if (!channel) {
        return false;
    }
    if (param_2 == 0) {
        channel->stop(0);
    } else {
        channel->stop(param_2);
    }
    mNoteMgr.releaseChannel(param_1);
    return true;
}

/* 8028165C-802816C4       .text gateOn__Q28JASystem6TTrackFUclll */
int JASystem::TTrack::gateOn(u8 param_1, s32 param_2, s32 param_3, s32 param_4) {
    TChannel* channel = mNoteMgr.getChannel(param_1);
    if (!channel) {
        return -1;
    }
    BankMgr::gateOn(channel, param_2, param_3, param_4);
    return 0;
}

/* 802816C4-80281708       .text checkNoteStop__Q28JASystem6TTrackFl */
int JASystem::TTrack::checkNoteStop(s32 param_1) {
    TChannel* channel = mNoteMgr.getChannel(param_1);
    if (channel == NULL) {
        return true;
    }
    return channel->field_0x1 == 0xff;
}

/* 80281708-802817E4       .text oscSetupFull__Q28JASystem6TTrackFUcUlUl */
void JASystem::TTrack::oscSetupFull(u8 param_1, u32 param_2, u32 param_3) {
    /* Nonmatching */
    u32 var1 = (param_1 & 0x10) >> 4;
    int var2 = param_1 & 0x0f;
    bool var3 = (param_1 & 0x80) >> 7;
    bool var4 = param_1 & 0x40;
    bool var5 = param_1 & 0x20;
    if (var3) {
        field_0x2cc[var1] = Player::sEnvelopeDef;
        field_0x2cc[var1].field_0x0 = var2;
        if (var2 == 1) {
            field_0x2cc[var1].field_0x14 = 1.0f;
        }
    }
    if (var4) {
        if (param_2 == 0) {
            field_0x2cc[var1].table = NULL;
        }
        field_0x2cc[var1].table = (s16*)(mSeqCtrl.mRawFilePtr + param_2);
    }
    if (!var5) {
        return;
    }
    if (param_3 == 0) {
        field_0x2cc[var1].rel_table = Player::sRelTable;
    }
    field_0x2cc[var1].rel_table = (s16*)(mSeqCtrl.mRawFilePtr + param_2);
}

/* 802817E4-80281850       .text oscSetupSimpleEnv__Q28JASystem6TTrackFUcUl */
void JASystem::TTrack::oscSetupSimpleEnv(u8 param_1, u32 param_2) {
    switch (param_1) {
    case 0:
        field_0x2cc[0] = Player::sEnvelopeDef;
        field_0x2cc[0].table = (s16*)(mSeqCtrl.mRawFilePtr + param_2);
        break;
    case 1:
        field_0x2cc[0].rel_table = (s16*)(mSeqCtrl.mRawFilePtr + param_2);
        break;
    }
}

/* 80281850-80281900       .text updateOscParam__Q28JASystem6TTrackFif */
void JASystem::TTrack::updateOscParam(int param_1, f32 param_2) {
    switch (param_1) {
    case 6:
        field_0x2cc[0].field_0x10 = param_2;
        break;
    case 7:
        field_0x2cc[0].field_0x4 = param_2;
        break;
    case 8:
        field_0x2cc[0].field_0x14 = param_2;
        break;
    case 9:
        field_0x2cc[1].field_0x10 = param_2;
        break;
    case 10:
        field_0x2cc[1].field_0x4 = param_2;
        break;
    case 11:
        field_0x2cc[1].field_0x14 = param_2;
        break;
    default:
        JUT_ASSERT(753, false);
        break;
    }
}

/* 80281900-802819D0       .text oscSetupSimple__Q28JASystem6TTrackFUc */
void JASystem::TTrack::oscSetupSimple(u8 param_1) {
    switch (param_1) {
    case 0:
        field_0x2cc[1] = Player::sVibratoDef;
        break;
    case 1:
        field_0x2cc[0] = Player::sTremoroDef;
        break;
    case 2:
        field_0x2cc[1] = Player::sTremoroDef;
        break;
    }
}

/* 802819D0-80281AA4       .text updateTimedParam__Q28JASystem6TTrackFv */
void JASystem::TTrack::updateTimedParam() {
    /* Nonmatching */
}

/* 80281AA4-80281E90       .text updateTrackAll__Q28JASystem6TTrackFv */
void JASystem::TTrack::updateTrackAll() {
    /* Nonmatching */
}

/* 80281E90-80282364       .text updateTrack__Q28JASystem6TTrackFUl */
void JASystem::TTrack::updateTrack(u32) {
    /* Nonmatching */
}

/* 80282364-802824C0       .text updateTempo__Q28JASystem6TTrackFv */
void JASystem::TTrack::updateTempo() {
    /* Nonmatching */
}

/* 802824C0-802825A0       .text updateSeq__Q28JASystem6TTrackFUlb */
void JASystem::TTrack::updateSeq(u32, bool) {
    /* Nonmatching */
}

/* 802825A0-8028265C       .text seqTimeToDspTime__Q28JASystem6TTrackFlUc */
int JASystem::TTrack::seqTimeToDspTime(s32 param_1, u8 param_2) {
    f32 f1 = ((f32)param_1 * (f32)param_2) / 100.0f;
    if (field_0x387) {
        f1 /= field_0x368;
    } else {
        f1 = 120.0f * f1;
        f1 /= field_0x378;
        if (Kernel::getOutputRate() == 0) {
            f1 = (f1 * Kernel::getSubFrames()) / 10.0f;
        }
    }
    return f1;
}

/* 8028265C-8028278C       .text setParam__Q28JASystem6TTrackFifi */
void JASystem::TTrack::setParam(int, f32, int) {
    /* Nonmatching */
}

/* 8028278C-802827F0       .text setSeqData__Q28JASystem6TTrackFPUcli */
bool JASystem::TTrack::setSeqData(u8* param_1, s32, int) {
    /* Nonmatching */
    init();
    field_0x37b = 3;
    mSeqCtrl.start(param_1, 0);
    updateTrackAll();
    field_0x37e = 2;
    return true;
}

/* 802827F0-802828A8       .text startSeq__Q28JASystem6TTrackFv */
bool JASystem::TTrack::startSeq() {
    /* Nonmatching */
}

/* 802828A8-80282908       .text stopSeq__Q28JASystem6TTrackFv */
bool JASystem::TTrack::stopSeq() {
    /* Nonmatching */
}

/* 80282908-80282944       .text stopSeqMain__Q28JASystem6TTrackFv */
void JASystem::TTrack::stopSeqMain() {
    updateSeq(0, 1);
    close();
}

/* 80282944-802829DC       .text noteOffAll__Q28JASystem6TTrackFv */
void JASystem::TTrack::noteOffAll() {
    /* Nonmatching */
}

/* 802829DC-80282A90       .text close__Q28JASystem6TTrackFv */
int JASystem::TTrack::close() {
    /* Nonmatching */
}

/* 80282A90-80282B44       .text muteTrack__Q28JASystem6TTrackFb */
void JASystem::TTrack::muteTrack(bool) {
    /* Nonmatching */
}

/* 80282B44-80282B84       .text start__Q28JASystem6TTrackFPvUl */
bool JASystem::TTrack::start(void* param_1, u32 param_2) {
    /* Nonmatching */
    mSeqCtrl.start(param_1, param_2);
    field_0x37e = 1;
    updateTrackAll();
    return false;
}

/* 80282B84-80282CE8       .text openChild__Q28JASystem6TTrackFUcUc */
JASystem::TTrack* JASystem::TTrack::openChild(u8, u8) {
    /* Nonmatching */
}

/* 80282CE8-80282D80       .text loadTbl__Q28JASystem6TTrackFUlUlUl */
int JASystem::TTrack::loadTbl(u32 param_1, u32 param_2, u32 param_3) {
    /* Nonmatching */
    switch (param_3) {
    case 4:
        return mSeqCtrl.mRawFilePtr[param_1 + param_2];
    case 5:
        return mSeqCtrl.get16(param_1 + param_2 * 2);
    case 6:
        return mSeqCtrl.get24(param_1 + param_2 * 3);
    case 7:
        return mSeqCtrl.get32(param_1 + param_2 * 4);
    case 8:
        return mSeqCtrl.get32(param_1 + param_2);
    }
}

/* 80282D80-80282DC0       .text exchangeRegisterValue__Q28JASystem6TTrackFUc */
int JASystem::TTrack::exchangeRegisterValue(u8) {
    /* Nonmatching */
}

/* 80282DC0-80282ED4       .text readReg32__Q28JASystem6TTrackFUc */
u32 JASystem::TTrack::readReg32(u8) {
    /* Nonmatching */
}

/* 80282ED4-802830AC       .text readReg16__Q28JASystem6TTrackFUc */
u16 JASystem::TTrack::readReg16(u8) {
    /* Nonmatching */
}

/* 802830AC-80283164       .text writeRegDirect__Q28JASystem6TTrackFUcUs */
void JASystem::TTrack::writeRegDirect(u8, u16) {
    /* Nonmatching */
}

/* 80283164-802836FC       .text writeRegParam__Q28JASystem6TTrackFUc */
void JASystem::TTrack::writeRegParam(u8) {
    /* Nonmatching */
}

/* 802836FC-80283720       .text readSelfPort__Q28JASystem6TTrackFi */
u16 JASystem::TTrack::readSelfPort(int param_1) {
    /* Nonmatching */
    return mTrackPort.readImport(param_1);
}

/* 80283720-80283744       .text writeSelfPort__Q28JASystem6TTrackFiUs */
void JASystem::TTrack::writeSelfPort(int param_1, u16 param_2) {
    /* Nonmatching */
    mTrackPort.writeExport(param_1, param_2);
}

/* 80283744-802837AC       .text writePortAppDirect__Q28JASystem6TTrackFUlUs */
int JASystem::TTrack::writePortAppDirect(u32, u16) {
    /* Nonmatching */
}

/* 802837AC-802837E4       .text readPortAppDirect__Q28JASystem6TTrackFUlPUs */
int JASystem::TTrack::readPortAppDirect(u32, u16*) {
    /* Nonmatching */
}

/* 802837E4-8028381C       .text routeTrack__Q28JASystem6TTrackFUl */
void JASystem::TTrack::routeTrack(u32) {
    /* Nonmatching */
}

/* 8028381C-80283870       .text writePortApp__Q28JASystem6TTrackFUlUs */
int JASystem::TTrack::writePortApp(u32, u16) {
    /* Nonmatching */
}

/* 80283870-802838C4       .text readPortApp__Q28JASystem6TTrackFUlPUs */
int JASystem::TTrack::readPortApp(u32, u16*) {
    /* Nonmatching */
}

/* 802838C4-80283A64       .text pause__Q28JASystem6TTrackFbb */
void JASystem::TTrack::pause(bool, bool) {
    /* Nonmatching */
}

/* 80283A64-80283AB4       .text getTranspose__Q28JASystem6TTrackCFv */
int JASystem::TTrack::getTranspose() const {
    /* Nonmatching */
}

/* 80283AB4-80283AF0       .text setTempo__Q28JASystem6TTrackFUs */
void JASystem::TTrack::setTempo(u16) {
    /* Nonmatching */
}

/* 80283AF0-80283B20       .text setTimebase__Q28JASystem6TTrackFUs */
void JASystem::TTrack::setTimebase(u16) {
    /* Nonmatching */
}

/* 80283B20-80283BBC       .text panCalc__Q28JASystem6TTrackFfffUc */
f32 JASystem::TTrack::panCalc(f32, f32, f32, u8) {
    /* Nonmatching */
}

/* 80283BBC-80283C9C       .text rootCallback__Q28JASystem6TTrackFPv */
int JASystem::TTrack::rootCallback(void*) {
    /* Nonmatching */
}

/* 80283C9C-80283CE8       .text registerSeqCallback__Q28JASystem6TTrackFPFPQ28JASystem6TTrackUs_Us */
void JASystem::TTrack::registerSeqCallback(u16 (*param_1)(TTrack*, u16)) {
    /* Nonmatching */
    if (sCallBackFunc) {
        OSReport("in Player ... overwrite callback\n");
    }
    sCallBackFunc = param_1;
}

/* 80283CE8-80283E9C       .text newMemPool__Q28JASystem6TTrackFi */
void JASystem::TTrack::newMemPool(int param_1) {
    /* Nonmatching */
    TTrack* runner = (TTrack*)new (JASDram, 0) u8[sizeof(TTrack)];
    JUT_ASSERT(2218, runner);
    TOuterParam* outer = new (JASDram, 0) TOuterParam();
    JUT_ASSERT(2220, outer);
    runner->assignExtBuffer(outer);
    sFreeList = runner;
    for (int i = 1; i < param_1; i++) {
        runner->next = (TTrack*)new (JASDram, 0) u8[sizeof(TTrack)];
        JUT_ASSERT(2228, runner->next);
        TOuterParam* outer = new (JASDram, 0) TOuterParam();
        JUT_ASSERT(2230, outer);
        runner->next->assignExtBuffer(outer);
        runner = runner->next;
    }
    runner->next = NULL;
}

/* 80283E9C-80283ECC       .text __ct__Q28JASystem8TVibrateFv */
JASystem::TVibrate::TVibrate() {
    /* Nonmatching */
    init();
}

/* 80283ECC-80283EE4       .text init__Q28JASystem8TVibrateFv */
void JASystem::TVibrate::init() {
    /* Nonmatching */
    mPitch = 1.0f / 18.0f;
    mDepth = 0.0f;
    field_0x0 = 0.0f;
}

/* 80283EE4-80283F18       .text incCounter__Q28JASystem8TVibrateFv */
void JASystem::TVibrate::incCounter() {
    /* Nonmatching */
    field_0x0 += mPitch;
    if (!(field_0x0 >= 4.0)) {
        return;
    }
    field_0x0 -= 4.0f;
}

/* 80283F18-80283FD0       .text getValue__Q28JASystem8TVibrateCFv */
f32 JASystem::TVibrate::getValue() const {
    /* Nonmatching */
}

/* 80283FE8-80284118       .text __ct__Q38JASystem6TTrack12AInnerParam_Fv */
JASystem::TTrack::AInnerParam_::AInnerParam_()
    : mVolume()
    , mPitch()
    , mFxmix()
    , mPan()
    , mDolby()
    , _50()
    , mOsc0Width()
    , mOsc0Rate()
    , mOsc0Vertex()
    , mOsc1Width()
    , mOsc1Rate()
    , mOsc1Vertex()
    , mIIRs()
    , _100()
    , _110()
{
}
