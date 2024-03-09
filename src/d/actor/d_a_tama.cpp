//
// Generated by dtk
// Translation Unit: d_a_tama.cpp
//

#include "d/actor/d_a_tama.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "d/d_npc.h"

static dCcD_SrcSph l_sph_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ AT_TYPE_ALL,
        /* SrcObjTg  SPrm    */ TG_SPRM_SET | TG_SPRM_IS_ENEMY,
        /* SrcObjCo  SPrm    */ CO_SPRM_SET | CO_SPRM_VS_UNK2 | CO_SPRM_VS_UNK8 | CO_SPRM_IS_UNK4,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ G_TG_SPRM_NO_HIT_MARK,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGSphS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
    },
};

/* 00000078-00000114       .text createInit__8daTama_cFv */
BOOL daTama_c::createInit() {
    mAcchCir.SetWall(0.0f, 35.0f);
    mAcch.Set(fopAcM_GetPosition_p(this), fopAcM_GetOldPosition_p(this), this, 1, &mAcchCir, fopAcM_GetSpeed_p(this));
    mStts.Init(0, 0xFF, this);
    mSph.SetStts(&mStts);
    mSph.Set(l_sph_src);
    return TRUE;
}

/* 00000114-0000011C       .text _draw__8daTama_cFv */
BOOL daTama_c::_draw() {
    return TRUE;
}

/* 0000011C-000002D4       .text _execute__8daTama_cFv */
BOOL daTama_c::_execute() {
    /* Nonmatching */
    fopNpc_npc_c* partner = (fopNpc_npc_c*)fopAcM_SearchByID(mPartnerID);
    bool del = true;
    if (partner != NULL) {
        f32 distXZ = fopAcM_searchActorDistanceXZ(this, partner);
        f32 distY = fabsf(current.pos.y - partner->current.pos.y);
        if (distXZ < mDis && distY < 400.0f) {
            del = false;
            speed.y = speedF * cM_ssin(current.angle.x);
            fopAcM_posMoveF(this, mStts.GetCCMoveP());
            mAcch.CrrPos(*dComIfG_Bgsp());
            if (mAcch.ChkWallHit()) {
                del = true;
            } else if (mAcch.ChkGroundHit()) {
                del = true;
            }

            if (!del && mSph.ChkCoHit()) {
                cCcD_Obj* hitobj = mSph.GetCoHitObj();
                del = true;
                if (hitobj != NULL) {
                    fopAc_ac_c* hitac = hitobj->GetAc();
                    if (hitac != NULL) {
                        if (hitac != partner) {
                            if (fopAcM_GetName(hitac) == PROC_PLAYER) {
                                partner->field_0x6ba = 1;
                            }
                        } else {
                            del = false;
                        }
                    }
                }
            }

            mSph.SetC(current.pos);
            mSph.SetR(20.0f);
            dComIfG_Ccsp()->Set(&mSph);
        }
    }
    if (del) {
        fopAcM_delete(this);
    }
    return TRUE;
}

/* 000002D4-000002DC       .text _delete__8daTama_cFv */
BOOL daTama_c::_delete() {
    return TRUE;
}

/* 000002DC-00000410       .text _create__8daTama_cFv */
s32 daTama_c::_create() {
    s32 rt = cPhs_COMPLEATE_e;
    fopAcM_SetupActor(this, daTama_c);
    if (!createInit())
        rt = cPhs_ERROR_e;
    return rt;
}

/* 00000638-00000658       .text daTama_Create__FP10fopAc_ac_c */
static s32 daTama_Create(fopAc_ac_c* i_this) {
    return ((daTama_c*)i_this)->_create();
}

/* 00000658-00000678       .text daTama_Delete__FP8daTama_c */
static BOOL daTama_Delete(daTama_c* i_this) {
    return i_this->_delete();
}

/* 00000678-00000698       .text daTama_Execute__FP8daTama_c */
static BOOL daTama_Execute(daTama_c* i_this) {
    return i_this->_execute();
}

/* 00000698-000006B8       .text daTama_Draw__FP8daTama_c */
static BOOL daTama_Draw(daTama_c* i_this) {
    return i_this->_draw();
}

/* 000006B8-000006C0       .text daTama_IsDelete__FP8daTama_c */
static BOOL daTama_IsDelete(daTama_c* i_this) {
    return TRUE;
}

static actor_method_class l_daTama_Method = {
    (process_method_func)daTama_Create,
    (process_method_func)daTama_Delete,
    (process_method_func)daTama_Execute,
    (process_method_func)daTama_IsDelete,
    (process_method_func)daTama_Draw,
};

actor_process_profile_definition g_profile_TAMA = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 9,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_TAMA,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daTama_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x012C,
    /* Actor SubMtd */ &l_daTama_Method,
    /* Status       */ fopAcStts_UNK40000_e | fopAcStts_UNK4000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
