//
// Generated by dtk
// Translation Unit: d_a_obj_dragonhead.cpp
//

#include "d/actor/d_a_obj_dragonhead.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_cc_d.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

static dCcD_SrcSph sph_check_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ AT_TYPE_FIRE_ARROW,
        /* SrcObjTg  SPrm    */ TG_SPRM_SET | TG_SPRM_IS_OTHER,
        /* SrcObjCo  SPrm    */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ 0,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGSphS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 1000.0f,
    },
};

/* 00000078-00000098       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_this) {
    return ((daObjDragonhead_c*)i_this)->CreateHeap();
}

namespace daObjDragonhead_prm {
    inline u32 getSwitchNo(daObjDragonhead_c* ac) { return (fopAcM_GetParam(ac) >> 8) & 0xFF; }
};

/* 00000098-00000228       .text CreateHeap__17daObjDragonhead_cFv */
BOOL daObjDragonhead_c::CreateHeap() {
    J3DModelData* model_data = (J3DModelData*)(dComIfG_getObjectRes("Qdghd", 0x04));
    JUT_ASSERT(0xA0, model_data != 0);
    mpModel = mDoExt_J3DModel__create(model_data, 0x00, 0x11020203);
    if (!mpModel)
        return FALSE;

    s32 ret = 1;

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    mDoMtx_stack_c::scaleM(scale);
    mDoMtx_copy(mDoMtx_stack_c::get(), mtx);

    mpBgW = new dBgW();
    if (!mpBgW || mpBgW->Set((cBgD_t*)dComIfG_getObjectRes("Qdghd", 0x07), cBgW::MOVE_BG_e, &mtx))
        ret = 0;

    if (ret != 1)
        return false;

    return mpModel != NULL;
}

/* 00000228-0000034C       .text CreateInit__17daObjDragonhead_cFv */
void daObjDragonhead_c::CreateInit() {
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    fopAcM_setCullSizeFar(this, 1.0f);
    set_mtx();

    field_0x40c = 0;
    u32 switchNo = daObjDragonhead_prm::getSwitchNo(this);
    if (dComIfGs_isSwitch(switchNo, fopAcM_GetHomeRoomNo(this))) {
        mSwitchOn = true;
        mAlpha = 0;
    } else {
        mSwitchOn = false;
        mAlpha = 0xFF;
        if (field_0x40c == 0 && !dComIfG_Bgsp()->Regist(mpBgW, this))
            field_0x40c = 1;
    }

    mStts.Init(0xFF, 0xFF, this);
    mSph.Set(sph_check_src);
    mSphCenter.set(79338.0f, 950.0f, 220000.0f);
    mSph.SetC(mSphCenter);
    mSph.SetStts(&mStts);
}

/* 0000034C-000003CC       .text set_mtx__17daObjDragonhead_cFv */
void daObjDragonhead_c::set_mtx() {
    mpModel->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(current.angle.y);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

s32 daObjDragonhead_c::_create() {
    fopAcM_SetupActor(this, daObjDragonhead_c);

    s32 ret = dComIfG_resLoad(&mPhs, "Qdghd");

    if (ret == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, CheckCreateHeap, 0x10500) == 0) {
            ret = cPhs_ERROR_e;
        } else {
            CreateInit();
        }
    }

    return ret;
}

BOOL daObjDragonhead_c::_delete() {
    if (heap != NULL && field_0x40c == 1)
        dComIfG_Bgsp()->Release(mpBgW);

    mDoAud_seDeleteObject(&mSphCenter);
    dComIfG_resDelete(&mPhs, "Qdghd");
    return TRUE;
}

BOOL daObjDragonhead_c::_execute() {
    dComIfG_Ccsp()->Set(&mSph);
    if (!mSwitchOn) {
        mDoAud_seStart(JA_SE_OBJ_ICEBERG_BREATH, &mSphCenter, 0, dComIfGp_getReverb(fopAcM_GetRoomNo(this)));
        if (mSph.ChkTgHit()) {
            cCcD_Obj* at = mSph.GetTgHitObj();
            if (at != NULL && at->ChkAtType(AT_TYPE_FIRE_ARROW)) {
                u32 switchNo = daObjDragonhead_prm::getSwitchNo(this);
                dComIfGs_onSwitch(switchNo, fopAcM_GetHomeRoomNo(this));
                mSwitchOn = true;
            }
        }
    }

    u32 switchNo = daObjDragonhead_prm::getSwitchNo(this);
    if (dComIfGs_isSwitch(switchNo, fopAcM_GetHomeRoomNo(this))) {
        if (field_0x40c == 1) {
            if (!dComIfG_Bgsp()->Release(mpBgW))
                field_0x40c = 0;

            mDoAud_seStart(JA_SE_OBJ_ICEVERG_MELT, &eyePos, 0, dComIfGp_getReverb(fopAcM_GetRoomNo(this)));
        }

        if (mAlpha != 0) {
            if (mAlpha >= 2)
                mAlpha -= 2;
            else
                mAlpha = 0;
        }
    } else {
        mSwitchOn = false;
        if (field_0x40c == 0 && !dComIfG_Bgsp()->Regist(mpBgW, this))
            field_0x40c = 1;

        if (mAlpha < 0xFF) {
            if (mAlpha <= 0xFD)
                mAlpha += 2;
            else
                mAlpha = 0xFF;
        }
    }

    set_mtx();
    return TRUE;
}

BOOL daObjDragonhead_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &tevStr);
    g_env_light.setLightTevColorType(mpModel, &tevStr);
    dComIfGd_setListBG();
    J3DModelData* modelData = mpModel->getModelData();
    u16 materialNum = modelData->getMaterialNum();
    for (u16 i = 0; i < materialNum; i++) {
        J3DMaterial* mat = modelData->getMaterialNodePointer(i);
        mat->getTevKColor(3)->mColor.a = mAlpha;
    }
    mDoExt_modelUpdateDL(mpModel);
    dComIfGd_setList();
    return TRUE;
}

/* 000003CC-000004FC       .text daObjDragonhead_Create__FPv */
static s32 daObjDragonhead_Create(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_create();
}

/* 000006B4-00000730       .text daObjDragonhead_Delete__FPv */
static BOOL daObjDragonhead_Delete(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_delete();
}

/* 00000730-00000824       .text daObjDragonhead_Draw__FPv */
static BOOL daObjDragonhead_Draw(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_draw();
}

/* 00000824-00000A48       .text daObjDragonhead_Execute__FPv */
static BOOL daObjDragonhead_Execute(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_execute();
}

/* 00000A48-00000A50       .text daObjDragonhead_IsDelete__FPv */
static BOOL daObjDragonhead_IsDelete(void* i_this) {
    return TRUE;
}

static actor_method_class daObj_DragonheadMethodTable = {
    (process_method_func)daObjDragonhead_Create,
    (process_method_func)daObjDragonhead_Delete,
    (process_method_func)daObjDragonhead_Execute,
    (process_method_func)daObjDragonhead_IsDelete,
    (process_method_func)daObjDragonhead_Draw,
};

actor_process_profile_definition g_profile_Obj_Dragonhead = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Dragonhead,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjDragonhead_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0025,
    /* Actor SubMtd */ &daObj_DragonheadMethodTable,
    /* Status       */ fopAcStts_UNK40000_e | fopAcStts_UNK4000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
