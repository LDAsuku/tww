//
// Generated by dtk
// Translation Unit: d_a_tbox.cpp
//

#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_s_acch.h"
#include "d/d_bg_w.h"
#include "d/d_cc_d.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "d/d_particle.h"
#include "d/d_procname.h"
#include "f_op/f_op_actor_mng.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_hostIO.h"
#include "dolphin/types.h"


#define DEMO_PROC_WAIT 0
#define DEMO_PROC_OPEN 1
#define DEMO_PROC_APPEAR 2
#define DEMO_PROC_OPEN_SHORT 3

#define FUNC_TYPE_NORMAL 0
#define FUNC_TYPE_SWITCH 1
#define FUNC_TYPE_ENEMIES 2
#define FUNC_TYPE_SWITCH_VISIBLE 3
#define FUNC_TYPE_SWITCH_TRANSPARENT 4
#define FUNC_TYPE_GRAVITY 5
#define FUNC_TYPE_TACT 6
#define FUNC_TYPE_EXTRA_SAVE_INFO 7
#define FUNC_TYPE_EXTRA_SAVE_INFO_SPAWN 8

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};
static u8 dummy3[4] = {0x02, 0x00, 0x02, 0x01};
static f64 dummy4[2] = {3.0, 0.5};

class daTbox_HIO_c {
public:
    daTbox_HIO_c();
    virtual ~daTbox_HIO_c();

    /* 0x0004 */ s8 m0004;
    /* 0x0006 */ u16 m0006;
    /* 0x0008 */ u16 m0008;
    /* 0x000A */ u16 m000A;
    /* 0x000C */ u16 m000C;
};

static daTbox_HIO_c l_HIO;

struct modelInfo {
    u16 modelId;
    u16 openBckId;
    u16 btkId;
    u16 brkId;
    u16 closedColId;
    u16 openColId;
};

static modelInfo l_modelInfo[] = {
    { 0x000E, 0x0009, 0x0022, 0x001B, 0x002A, 0x002B },
    { 0x000F, 0x0008, 0x0023, 0x001C, 0x002A, 0x002B },
    { 0x0010, 0x0008, 0x0024, 0x001D, 0x002A, 0x002B },
    { 0x0014, 0x0008, 0xFFFF, 0xFFFF, 0x002C, 0x002D }
};

class daTbox_c : public fopAc_ac_c {
public:
    daTbox_c();

    void commonShapeSet();
    void effectShapeSet();
    void envShapeSet();
    void bgCheckSet();

    void searchRoomNo();
    void lightReady();
    
    void checkEnv();
    BOOL checkOpen();
    modelInfo& getModelInfo();
    
    void clrDzb();
    void setDzb();

    void surfaceProc();
    void checkRoomDisp(int);
    u32 getShapeType();
    s32 getFuncType();
    void checkNormal();
    
    s32 CreateHeap();
    s32 CreateInit();

    void boxCheck();
    void lightUpProc();
    void lightDownProc();
    void darkProc();
    void volmProc();

    void demoProcOpen();

    void demoInitAppear_Tact();
    void demoInitAppear();

    void demoProcAppear_Tact();
    void demoProcAppear();

    s32 demoProc();

    void OpenInit_com();
    void OpenInit();

    void setCollision();

    bool actionWait();
    bool actionDemo();
    bool actionDemo2();
    bool actionOpenWait();
    bool actionSwOnWait();
    bool actionSwOnWait2();
    bool actionGenocide();

    s32 execute();
    s32 draw();

    /* 0x0290 */ u32 mRoomNo;
    /* 0x0294 */ request_of_phase_process_class mPhs;

    /* 0x029C */ J3DModel* mModel;
    /* 0x02A0 */ mDoExt_bckAnm mBckAnm;
    /* 0x02B0 */ mDoExt_btkAnm* mBtkAnm;
    /* 0x02B4 */ mDoExt_brkAnm* mBrkAnm;

    /* 0x02B8 */ cBgW* mBgWCol;

    /* 0x02BC */ dBgW* m02BC;
    /* 0x02C0 */ dBgW* m02C0;
    /* 0x02C4 */ dBgW* m02C4;

    /* 0x02C8 */ J3DModel* mModel2;

    /* 0x02CC */ mDoExt_bckAnm mBckAnm2;
    /* 0x02DC */ mDoExt_btkAnm mBtkAnm2;
    /* 0x02F0 */ mDoExt_brkAnm mBrkAnm2;
    
    /* 0x0308 */ u32 m0308;

    /* 0x030C */ mDoExt_brkAnm mBrkAnm3;

    /* 0x0324 */ J3DModel* mModel3;

    /* 0x0328 */ mDoExt_brkAnm mBrkAnm4;

    typedef bool (daTbox_c::*actionFunc)();
    /* 0x0340 */ actionFunc mActionFunc;

    /* 0x034C */ float m034C;

    /* 0x0350 */ u32 mStaffId;

    /* 0x0354 */ Mtx mMtx;

    /* 0x0384 */ LIGHT_INFLUENCE mPLight;
    /* 0x03A4 */ LIGHT_INFLUENCE mEfLight;

    /* 0x03C4 */ dPa_smokeEcallBack mSmokeCB;
    /* 0x03E4 */ JPABaseEmitter* mSmokeEmitter;

    /* 0x03E8 */ float mAllColRatio;
    /* 0x03EC */ float m03EC;

    /* 0x03F0 */ u16 m03F0;
    /* 0x03F2 */ s16 m03F2;

    /* 0x03F4 */ u8 m03F4;
    /* 0x03F5 */ u8 m03F5;
    /* 0x03F6 */ u16 m03F6;

    /* 0x03F8 */ u8 m03F8;

    /* 0x03FC */ dBgS_ObjAcch mObjAcch;
    /* 0x05C0 */ dBgS_AcchCir mAcchCir;
    /* 0x0600 */ dCcD_Stts mColStatus;
    /* 0x063C */ dCcD_Cyl mColCyl;

    /* 0x076C */ u8 m076C;
};

/* 000000EC-00000124       .text __ct__12daTbox_HIO_cFv */
daTbox_HIO_c::daTbox_HIO_c() {
    m0004 = -1;
    m0006 = 0x82;
    m0008 = 0xB4;
    m000A = 0x30;
    m000C = 0x1E;
}

/* 00000124-00000550       .text commonShapeSet__8daTbox_cFv */
void daTbox_c::commonShapeSet() {
    /* Nonmatching */
}

/* 00000598-00000764       .text effectShapeSet__8daTbox_cFv */
void daTbox_c::effectShapeSet() {
    /* Nonmatching */
}

/* 00000764-00000928       .text envShapeSet__8daTbox_cFv */
void daTbox_c::envShapeSet() {
    /* Nonmatching */
}

/* 00000928-00000BB0       .text bgCheckSet__8daTbox_cFv */
void daTbox_c::bgCheckSet() {
    /* Nonmatching */
}

/* 00000BB0-00000C14       .text searchRoomNo__8daTbox_cFv */
void daTbox_c::searchRoomNo() {
    /* Nonmatching */
}

/* 00000C14-00000C98       .text lightReady__8daTbox_cFv */
void daTbox_c::lightReady() {
    /* Nonmatching */
}

/* 00000C98-00000CD8       .text checkEnv__8daTbox_cFv */
void daTbox_c::checkEnv() {
    /* Nonmatching */
}

/* 00000CD8-00000D48       .text checkOpen__8daTbox_cFv */
BOOL daTbox_c::checkOpen() {
    /* Nonmatching */
}

/* 00000D48-00000D78       .text getModelInfo__8daTbox_cFv */
modelInfo& daTbox_c::getModelInfo() {
    return l_modelInfo[getShapeType()];
}

/* 00000D78-00000DD0       .text clrDzb__8daTbox_cFv */
void daTbox_c::clrDzb() {
    /* Nonmatching */
}

/* 00000DD0-00000ECC       .text setDzb__8daTbox_cFv */
void daTbox_c::setDzb() {
    /* Nonmatching */
}

/* 00000ECC-00000F8C       .text surfaceProc__8daTbox_cFv */
void daTbox_c::surfaceProc() {
    /* Nonmatching */
}

/* 00000F8C-00000FC0       .text checkRoomDisp__8daTbox_cFi */
void daTbox_c::checkRoomDisp(int) {
    /* Nonmatching */
}

/* 00000FC0-00000FE4       .text getShapeType__8daTbox_cFv */
u32 daTbox_c::getShapeType() {
    s32 shapeType = (fopAcM_GetParam(this) >> 0x14) & 0x0F;
    return shapeType >= 4 ? 0 : shapeType;
}

/* 00000FE4-00000FF0       .text getFuncType__8daTbox_cFv */
s32 daTbox_c::getFuncType() {
    return fopAcM_GetParam(this) & 0x7F;
}

/* 00000FF0-0000108C       .text checkNormal__8daTbox_cFv */
void daTbox_c::checkNormal() {
    /* Nonmatching */
}

/* 0000108C-000010AC       .text CheckCreateHeap__FP10fopAc_ac_c */
void CheckCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 000010AC-0000114C       .text CreateHeap__8daTbox_cFv */
s32 daTbox_c::CreateHeap() {
    /* Nonmatching */
}

/* 0000114C-00001560       .text CreateInit__8daTbox_cFv */
s32 daTbox_c::CreateInit() {
    /* Nonmatching */
}

/* 00001560-00001624       .text boxCheck__8daTbox_cFv */
void daTbox_c::boxCheck() {
    /* Nonmatching */
}

/* 00001624-00001668       .text lightUpProc__8daTbox_cFv */
void daTbox_c::lightUpProc() {
    /* Nonmatching */
}

/* 00001668-000016BC       .text lightDownProc__8daTbox_cFv */
void daTbox_c::lightDownProc() {
    /* Nonmatching */
}

/* 000016BC-0000172C       .text darkProc__8daTbox_cFv */
void daTbox_c::darkProc() {
    /* Nonmatching */
}

/* 0000172C-000017CC       .text volmProc__8daTbox_cFv */
void daTbox_c::volmProc() {
    /* Nonmatching */
}

/* 000017CC-00001890       .text demoProcOpen__8daTbox_cFv */
void daTbox_c::demoProcOpen() {
    /* Nonmatching */
}

/* 00001890-00001A40       .text demoInitAppear_Tact__8daTbox_cFv */
void daTbox_c::demoInitAppear_Tact() {
    /* Nonmatching */
}

/* 00001A40-00001B38       .text demoInitAppear__8daTbox_cFv */
void daTbox_c::demoInitAppear() {
    /* Nonmatching */
}

/* 00001B38-00001CF4       .text demoProcAppear_Tact__8daTbox_cFv */
void daTbox_c::demoProcAppear_Tact() {
    /* Nonmatching */
}

/* 00001CF4-00001E4C       .text demoProcAppear__8daTbox_cFv */
void daTbox_c::demoProcAppear() {
    /* Nonmatching */
}

/* 00001E4C-0000210C       .text demoProc__8daTbox_cFv */
s32 daTbox_c::demoProc() {
    static char* action_table[] = {
        "WAIT",
        "OPEN",
        "APPEAR",
        "OPEN_SHORT"
    };

    s32 actionIdx = dComIfGp_evmng_getMyActIdx(mStaffId, action_table, 4, 0, 0);
    bool bIsAdvance = dComIfGp_evmng_getIsAddvance(mStaffId);

    if (bIsAdvance) {
        m03F4 = 0;

        switch (actionIdx) {
            case DEMO_PROC_OPEN:
                OpenInit();
                lightReady();
                mPLight.mPower = 0.0f;
                mEfLight.mPower = 0.0f;
                break;
            case DEMO_PROC_APPEAR:
                m03F0 |= 0x20;
                m03EC = -130.0f;
                
                setDzb();

                if (getFuncType() == FUNC_TYPE_TACT) {
                    m03F0 &= -3;
                    demoInitAppear_Tact();
                }
                else {
                    m03F0 &= -4;
                    demoInitAppear();
                }

                break;
            case DEMO_PROC_OPEN_SHORT:
                OpenInit_com();
                break;
        }
    }

    switch (actionIdx) {
        case DEMO_PROC_APPEAR:
            if (getFuncType() == FUNC_TYPE_TACT) {
                demoProcAppear_Tact();
            }
            else {
                demoProcAppear();
            }

            surfaceProc();
            break;
        case DEMO_PROC_OPEN:
            if (m03F4 != 0) {
                dComIfGp_evmng_cutEnd(mStaffId);
            }
            else {
                if (mBckAnm.play() != 0) {
                    m03F4 = 1;
                    dComIfGp_evmng_cutEnd(mStaffId);
                    fopAcM_seStart(this, JA_SE_OBJ_TBOX_OPEN_S2, 0);
                }
            }
            break;
        case DEMO_PROC_OPEN_SHORT:
            if (m03F4 != 0) {
                dComIfGp_evmng_cutEnd(mStaffId);
            }
            else {
                if (mBckAnm.play() != 0) {
                    m03F4 = 1;
                    dComIfGp_evmng_cutEnd(mStaffId);
                    fopAcM_seStart(this, JA_SE_OBJ_TBOX_OPEN_S2, 0);
                }
            }
            break;
        default:
            dComIfGp_evmng_cutEnd(mStaffId);
            break;
    }

    if (m03F0 & 0x10) {
        demoProcOpen();
    }

    if (m03F0 & 0x08) {
        dKy_set_allcol_ratio(mAllColRatio);
    }

    return 0;
}

/* 0000210C-00002250       .text OpenInit_com__8daTbox_cFv */
void daTbox_c::OpenInit_com() {
    /* Nonmatching */
}

/* 00002250-00002444       .text OpenInit__8daTbox_cFv */
void daTbox_c::OpenInit() {
    /* Nonmatching */
}

/* 00002444-000024AC       .text setCollision__8daTbox_cFv */
void daTbox_c::setCollision() {
    /* Nonmatching */
}

/* 000024AC-000024B4       .text actionWait__8daTbox_cFv */
bool daTbox_c::actionWait() {
    return true;
}

/* 000024B4-000025A4       .text actionDemo__8daTbox_cFv */
bool daTbox_c::actionDemo() {
    /* Nonmatching */
}

/* 000025A4-00002634       .text actionDemo2__8daTbox_cFv */
bool daTbox_c::actionDemo2() {
    /* Nonmatching */
}

/* 00002634-000027C8       .text actionOpenWait__8daTbox_cFv */
bool daTbox_c::actionOpenWait() {
    /* Nonmatching */
}

/* 000027C8-000028A0       .text actionSwOnWait__8daTbox_cFv */
bool daTbox_c::actionSwOnWait() {
    /* Nonmatching */
}

/* 000028A0-00002914       .text actionSwOnWait2__8daTbox_cFv */
bool daTbox_c::actionSwOnWait2() {
    /* Nonmatching */
}

/* 00002914-00002A2C       .text actionGenocide__8daTbox_cFv */
bool daTbox_c::actionGenocide() {
    /* Nonmatching */
}

/* 00002A2C-00002BF0       .text execute__8daTbox_cFv */
s32 daTbox_c::execute() {
    /* Nonmatching */
}

/* 00002BF0-00002C10       .text daTbox_Draw__FP8daTbox_c */
s32 daTbox_Draw(daTbox_c* i_tbox) {
    return i_tbox->draw();
}

/* 00002C10-00002FB0       .text draw__8daTbox_cFv */
s32 daTbox_c::draw() {
    /* Nonmatching */
}

/* 00002FB0-00002FD0       .text daTbox_Execute__FP8daTbox_c */
s32 daTbox_Execute(daTbox_c* i_tbox) {
    return i_tbox->execute();
}

/* 00002FD0-00002FD8       .text daTbox_IsDelete__FP8daTbox_c */
s32 daTbox_IsDelete(daTbox_c*) {
    return TRUE;
}

/* 00002FD8-00003070       .text daTbox_Delete__FP8daTbox_c */
s32 daTbox_Delete(daTbox_c* i_tbox) {
    if (i_tbox->m02C4 != NULL) {
        g_dComIfG_gameInfo.play.mBgS.Release(i_tbox->m02C4);
    }

    i_tbox->mSmokeCB.end();
    dComIfG_resDelete(&i_tbox->mPhs, "Dalways");

    if (l_HIO.m0004 >= 0) {
        mDoHIO_root.mDoHIO_deleteChild(l_HIO.m0004);
        l_HIO.m0004 = -1;
    }

    return TRUE;
}

/* 00003070-0000315C       .text daTbox_Create__FP10fopAc_ac_c */
s32 daTbox_Create(fopAc_ac_c* i_actor) {
    static const u32 heapsize_tbl[] = {
        0x2E40,
        0x2D7C,
        0x2E40,
        0x2D80
    };

    static const u32 opensize_tbl[] = {
        0x14C0,
        0x14E0,
        0x14C0,
        0x14C0
    };

    daTbox_c* tbox = static_cast<daTbox_c*>(i_actor);
    s32 result;

    fopAcM_SetupActor(tbox, daTbox_c);

    result = dComIfG_resLoad(&tbox->mPhs, "Dalways");

    if (result == cPhs_COMPLEATE_e) {
        tbox->mRoomNo = tbox->orig.angle.x & 0x3F;
        
        u32 shapeType = tbox->getShapeType();
        u32 heapSize = heapsize_tbl[shapeType];

        if (tbox->checkOpen() == FALSE) {
            heapSize += opensize_tbl[shapeType];
        }

        u32 heapResult = fopAcM_entrySolidHeap(i_actor, (heapCallbackFunc)CheckCreateHeap, heapSize);
        if ((heapResult & 0xFF) == 0) {
            return cPhs_ERROR_e;
        }
        else {
            tbox->CreateInit();
            tbox->mAttentionInfo.mFlags = fopAc_Attn_ACTION_TREASURE_e;
        }
    }

    return result;
}

/* 0000315C-000032F0       .text __ct__8daTbox_cFv */
daTbox_c::daTbox_c() {

}

/* 000039E4-00003A2C       .text __dt__12daTbox_HIO_cFv */
daTbox_HIO_c::~daTbox_HIO_c() {

}

static actor_method_class l_daTbox_Method = {
    (process_method_func)daTbox_Create,
    (process_method_func)daTbox_Delete,
    (process_method_func)daTbox_Execute,
    (process_method_func)daTbox_IsDelete,
    (process_method_func)daTbox_Draw,
};

actor_process_profile_definition g_profile_TBOX = {
    fpcLy_CURRENT_e,
    7,
    fpcPi_CURRENT_e,
    PROC_TBOX,
    &g_fpcLf_Method.mBase,
    sizeof(daTbox_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x0113,
    &l_daTbox_Method,
    fopAcStts_UNK40000_e | fopAcStts_UNK4000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
