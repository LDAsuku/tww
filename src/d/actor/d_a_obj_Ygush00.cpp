//
// Generated by dtk
// Translation Unit: d_a_obj_Ygush00.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_a_obj.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

struct daObjGryw00_c {
public:
    f32 get_draw_water_lvl(void *i_this);
};

struct daObjYgush00_c : public fopAc_ac_c {
public:
    enum Param_e {
        PRM_TYPE_W = 3,
        PRM_TYPE_S = 0,
    };

    s32 _create();
    s32 _delete();
    s32 _execute();
    s32 _draw();
    s32 create_heap();
    static s32 solidHeapCB(fopAc_ac_c*);

public:
    request_of_phase_process_class mPhs;
    J3DModel * mpModel;
    mDoExt_btkAnm mBtkAnm;
    mDoExt_bckAnm mBckAnm;
    u32 mType;
    daObjGryw00_c * mpGryw00;
};

namespace {
    static const char l_arcname[] = "Ygush00";
};

/* 00000078-0000009C       .text solidHeapCB__14daObjYgush00_cFP10fopAc_ac_c */
s32 daObjYgush00_c::solidHeapCB(fopAc_ac_c* ac) {
    return ((daObjYgush00_c*)ac)->create_heap();
}

/* 0000009C-00000250       .text create_heap__14daObjYgush00_cFv */
s32 daObjYgush00_c::create_heap() {
    static u32 mdl_table[] = { 0x0A, 0x09, 0x09, 0x09 };
    static u32 btk_table[] = { 0x0E, 0x0D, 0x0D, 0x0D };
    static u32 bck_table[] = { 0x06, 0x05, 0x05, 0x05 };

    s32 ret = 1;

    J3DModelData * pModelData = (J3DModelData *)dComIfG_getObjectRes(l_arcname, mdl_table[mType]);
    J3DAnmTextureSRTKey * pBtk = (J3DAnmTextureSRTKey *)dComIfG_getObjectRes(l_arcname, btk_table[mType]);
    J3DAnmTransform * pBck = (J3DAnmTransform *)dComIfG_getObjectRes(l_arcname, bck_table[mType]);

    if (!pModelData || !pBtk || !pBck) {
        JUT_ASSERT(207, 0);
        ret = 0;
        return ret;
    }

    mpModel = mDoExt_J3DModel__create(pModelData, 0x80000, 0x11000222);
    s32 btkRet = mBtkAnm.init(pModelData, pBtk, true, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, false, false);
    s32 bckRet = mBckAnm.init(pModelData, pBck, true, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, false);

    if (!mpModel || !btkRet || !bckRet)
        ret = 0;

    return ret;
}

/* 00000250-000003F4       .text _create__14daObjYgush00_cFv */
s32 daObjYgush00_c::_create() {
    const char * arcname = l_arcname;

    fopAcM_SetupActor(this, daObjYgush00_c);

    if (fpcM_IsFirstCreating(this)) {
        u32 type = daObj::PrmAbstract(this, PRM_TYPE_W, PRM_TYPE_S);
        mType = type;
        if ((int)mType < 0 || 4 <= (int)mType)
            mType = 0;
    }

    if (dComIfG_resLoad(&mPhs, arcname) == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, (heapCallbackFunc)solidHeapCB, 0x740) == 1) {
            mpModel->setBaseScale(mScale);
            mDoMtx_stack_c::transS(getPosition());
            mpModel->i_setBaseTRMtx(mDoMtx_stack_c::get());
            fopAcM_SetMtx(this, mpModel->getBaseTRMtx());

            fopAcM_setCullSizeBox(this,
                mScale.x * -80.0f, 0.0f, mScale.z * -80.0f,
                mScale.x * 80.0f, mScale.y * 125.0f, mScale.z * 80.0f);
        } else {
            return cPhs_ERROR_e;
        }
    }
}

/* 000004F4-00000524       .text _delete__14daObjYgush00_cFv */
s32 daObjYgush00_c::_delete() {
    dComIfG_resDelete(&mPhs, l_arcname);
    return 1;
}

/* 00000524-0000066C       .text _execute__14daObjYgush00_cFv */
s32 daObjYgush00_c::_execute() {
    if (mType != 3 || dComIfGs_isEventBit(EV_BIT_TALKED_TO_IRCH_IN_FOREST_HAVEN)) {
        mBtkAnm.play();
        mBckAnm.play();
    }

    if (mType == 1) {
        if (mpGryw00 != NULL) {
            if (mpGryw00->get_draw_water_lvl(mpGryw00) <= getPosition().y) {
                // fopAcM_seStartCurrent(this, 0x61fe, 0);
            }
        } else {
            mpGryw00 = (daObjGryw00_c*)i_fopAcM_SearchByName(PROC_Obj_Gryw00);
        }
    } else {
        // fopAcM_seStartCurrent(this, 0x61fe, 0);
    }
}

/* 0000066C-000006FC       .text _draw__14daObjYgush00_cFv */
s32 daObjYgush00_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG1, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    mBtkAnm.entry(mpModel->getModelData());
    mBckAnm.entry(mpModel->getModelData());
    mDoExt_modelUpdateDL(mpModel);
    return 1;
}

/* 000006FC-0000071C       .text daObjYgush00_Create__FP14daObjYgush00_c */
s32 daObjYgush00_Create(daObjYgush00_c* i_this) {
    return i_this->_create();
}

/* 0000071C-00000740       .text daObjYgush00_Delete__FP14daObjYgush00_c */
s32 daObjYgush00_Delete(daObjYgush00_c* i_this) {
    return i_this->_delete();
}

/* 00000740-00000764       .text daObjYgush00_Execute__FP14daObjYgush00_c */
s32 daObjYgush00_Execute(daObjYgush00_c* i_this) {
    return i_this->_execute();
}

/* 00000764-00000788       .text daObjYgush00_Draw__FP14daObjYgush00_c */
s32 daObjYgush00_Draw(daObjYgush00_c* i_this) {
    return i_this->_draw();
}

/* 00000788-00000790       .text daObjYgush00_IsDelete__FP14daObjYgush00_c */
s32 daObjYgush00_IsDelete(daObjYgush00_c* i_this) {
    return 1;
}

static actor_method_class l_daObjYgush00_Mehtod = {
    (process_method_func)daObjYgush00_Create,
    (process_method_func)daObjYgush00_Delete,
    (process_method_func)daObjYgush00_Execute,
    (process_method_func)daObjYgush00_IsDelete,
    (process_method_func)daObjYgush00_Draw,
};

extern actor_process_profile_definition g_profile_Obj_Ygish00 = {
    -3,
    3,
    0xFFFD,
    PROC_Obj_Ygush00,
    &g_fpcLf_Method.mBase,
    sizeof(daObjYgush00_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x005E,
    &l_daObjYgush00_Mehtod,
    0x00040100,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
