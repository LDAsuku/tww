//
// Generated by dtk
// Translation Unit: d_demo.cpp
//

#include "d/d_demo.h"
#include "f_op/f_op_camera_mng.h"
#include "d/d_com_inf_game.h"

/* 800692C4-80069330       .text __ct__13dDemo_actor_cFv */
dDemo_actor_c::dDemo_actor_c() {
    mFlags = 0;
    mTranslation.setall(0.0f);
    mScaling.setall(1.0f);
    mRotation.setall(0);
    mModel = NULL;
    mAnimationFrameMax = 3.402823e+38;
    mTexAnimationFrameMax = 3.402823e+38;
}

/* 80069330-800693C0       .text __dt__13dDemo_actor_cFv */
dDemo_actor_c::~dDemo_actor_c() {
    /* Nonmatching */
}

/* 800693C0-800693F4       .text getActor__13dDemo_actor_cFv */
fopAc_ac_c* dDemo_actor_c::getActor() {
    return fopAcM_SearchByID(mActorPcId);
}

/* 800693F4-80069434       .text setActor__13dDemo_actor_cFP10fopAc_ac_c */
void dDemo_actor_c::setActor(fopAc_ac_c* ac) {
    if (ac == NULL)
        mActorPcId = -1;
    else
        mActorPcId = fopAcM_GetID(ac);
    mBckId = -1;
    mBtpId = -1;
    mBtkId = -1;
    mBrkId = -1;
}

/* 80069434-80069550       .text getP_BtpData__13dDemo_actor_cFPCc */
void* dDemo_actor_c::getP_BtpData(const char* name) {
    /* Nonmatching */
    if (!(mFlags & 1))
        return NULL;
}

/* 80069550-800695E8       .text getP_BrkData__13dDemo_actor_cFPCc */
void* dDemo_actor_c::getP_BrkData(const char*) {
    /* Nonmatching */
}

/* 800695E8-8006969C       .text getP_BtkData__13dDemo_actor_cFPCc */
void* dDemo_actor_c::getP_BtkData(const char*) {
    /* Nonmatching */
}

/* 8006969C-80069838       .text getPrm_Morf__13dDemo_actor_cFv */
void dDemo_actor_c::getPrm_Morf() {
    /* Nonmatching */
}

/* 80069838-800698C0       .text dDemo_getJaiPointer__FPCcUliPUs */
void dDemo_getJaiPointer(const char*, u32, int, u16*) {
    /* Nonmatching */
}

/* 800698C0-80069BC0       .text dDemo_setDemoData__FP10fopAc_ac_cUcP14mDoExt_McaMorfPCciPUsUlSc */
BOOL dDemo_setDemoData(fopAc_ac_c*, u8, mDoExt_McaMorf*, const char*, int, u16*, u32, s8) {
    /* Nonmatching */
}

/* 80069BC0-80069BDC       .text JSGSetData__13dDemo_actor_cFUlPCvUl */
void dDemo_actor_c::JSGSetData(u32 p0, const void* p1, u32 p2) {
    field_0x4c = p0;
    field_0x50 = p1;
    field_0x54 = p2;
    mFlags |= 0x01;
}

/* 80069BDC-80069C04       .text JSGSetTranslation__13dDemo_actor_cFRC3Vec */
void dDemo_actor_c::JSGSetTranslation(const Vec& v) {
    mTranslation = v;
    mFlags |= 0x02;
}

/* 80069C04-80069C2C       .text JSGSetScaling__13dDemo_actor_cFRC3Vec */
void dDemo_actor_c::JSGSetScaling(const Vec& v) {
    mScaling = v;
    mFlags |= 0x04;
}

/* 80069C2C-80069C90       .text JSGSetRotation__13dDemo_actor_cFRC3Vec */
void dDemo_actor_c::JSGSetRotation(const Vec& v) {
    mRotation.x = cM_deg2s(v.x);
    mRotation.y = cM_deg2s(v.y);
    mRotation.z = cM_deg2s(v.z);
    mFlags |= 0x08;
}

/* 80069C90-80069CA4       .text JSGSetShape__13dDemo_actor_cFUl */
void dDemo_actor_c::JSGSetShape(u32 id) {
    mShapeId = id;
    mFlags |= 0x10;
}

/* 80069CA4-80069CC0       .text JSGSetAnimation__13dDemo_actor_cFUl */
void dDemo_actor_c::JSGSetAnimation(u32 no) {
    mNextBckId = no;
    mAnimationFrameMax = 3.402823e+38;
    mFlags |= 0x20;
}

/* 80069CC0-80069CD4       .text JSGSetAnimationFrame__13dDemo_actor_cFf */
void dDemo_actor_c::JSGSetAnimationFrame(f32 v) {
    mAnimationFrame = v;
    mFlags |= 0x40;
}

/* 80069CD4-80069CE8       .text JSGSetAnimationTransition__13dDemo_actor_cFf */
void dDemo_actor_c::JSGSetAnimationTransition(f32 v) {
    mAnimationTransition = v;
    mFlags |= 0x40;
}

/* 80069CE8-80069CFC       .text JSGSetTextureAnimation__13dDemo_actor_cFUl */
void dDemo_actor_c::JSGSetTextureAnimation(u32 no) {
    mTexAnimation = no;
    mFlags |= 0x80;
}

/* 80069CFC-80069D10       .text JSGSetTextureAnimationFrame__13dDemo_actor_cFf */
void dDemo_actor_c::JSGSetTextureAnimationFrame(f32 v) {
    mTexAnimationFrame = v;
    mFlags |= 0x100;
}

/* 80069D10-80069D44       .text getView__Fv */
camera_class* getView() {
    if (dComIfGp_getWindowNum() == 0)
        return NULL;

    return dComIfGp_getCamera(dComIfGp_getWindow(0)->getCameraID());
}

/* 80069D44-80069D78       .text JSGGetProjectionNear__14dDemo_camera_cCFv */
f32 dDemo_camera_c::JSGGetProjectionNear() const {
    camera_class* view = getView();
    if (view == NULL)
        return 0.0f;
    return view->mNear;
}

/* 80069D78-80069D8C       .text JSGSetProjectionNear__14dDemo_camera_cFf */
void dDemo_camera_c::JSGSetProjectionNear(f32 v) {
    mProjNear = v;
    mFlags |= 0x01;
}

/* 80069D8C-80069DC0       .text JSGGetProjectionFar__14dDemo_camera_cCFv */
f32 dDemo_camera_c::JSGGetProjectionFar() const {
    camera_class* view = getView();
    if (view == NULL)
        return 1.0f;
    return view->mFar;
}

/* 80069DC0-80069DD4       .text JSGSetProjectionFar__14dDemo_camera_cFf */
void dDemo_camera_c::JSGSetProjectionFar(f32 v) {
    mProjFar = v;
    mFlags |= 0x02;
}

/* 80069DD4-80069E08       .text JSGGetProjectionFovy__14dDemo_camera_cCFv */
f32 dDemo_camera_c::JSGGetProjectionFovy() const {
    camera_class* view = getView();
    if (view == NULL)
        return 60.0f;
    return view->mFovy;
}

/* 80069E08-80069E1C       .text JSGSetProjectionFovy__14dDemo_camera_cFf */
void dDemo_camera_c::JSGSetProjectionFovy(f32 v) {
    mFovy = v;
    mFlags |= 0x04;
}

/* 80069E1C-80069E50       .text JSGGetProjectionAspect__14dDemo_camera_cCFv */
f32 dDemo_camera_c::JSGGetProjectionAspect() const {
    camera_class* view = getView();
    if (view == NULL)
        return 1.3333f;
    return view->mAspect;
}

/* 80069E50-80069E64       .text JSGSetProjectionAspect__14dDemo_camera_cFf */
void dDemo_camera_c::JSGSetProjectionAspect(f32 v) {
    mAspect = v;
    mFlags |= 0x08;
}

/* 80069E64-80069EC0       .text JSGGetViewPosition__14dDemo_camera_cCFP3Vec */
void dDemo_camera_c::JSGGetViewPosition(Vec* dst) const {
    camera_class* view = getView();
    if (view == NULL) {
        dst->x = 0.0f;
        dst->y = 0.0f;
        dst->z = 0.0f;
    }
    *dst = view->mLookat.mEye;
}

/* 80069EC0-80069EE8       .text JSGSetViewPosition__14dDemo_camera_cFRC3Vec */
void dDemo_camera_c::JSGSetViewPosition(const Vec& v) {
    mViewPosition = v;
    mFlags |= 0x10;
}

/* 80069EE8-80069F48       .text JSGGetViewUpVector__14dDemo_camera_cCFP3Vec */
void dDemo_camera_c::JSGGetViewUpVector(Vec* dst) const {
    camera_class* view = getView();
    if (view == NULL) {
        dst->x = 0.0f;
        dst->y = 1.0f;
        dst->z = 0.0f;
    }
    *dst = view->mLookat.mUp;
}

/* 80069F48-80069F70       .text JSGSetViewUpVector__14dDemo_camera_cFRC3Vec */
void dDemo_camera_c::JSGSetViewUpVector(const Vec& v) {
    mUpVector = v;
    mFlags |= 0x20;
}

/* 80069F70-80069FD0       .text JSGGetViewTargetPosition__14dDemo_camera_cCFP3Vec */
void dDemo_camera_c::JSGGetViewTargetPosition(Vec* dst) const {
    camera_class* view = getView();
    if (view == NULL) {
        dst->x = 0.0f;
        dst->y = 0.0f;
        dst->z = 1.0f;
    }
    *dst = view->mLookat.mCenter;
}

/* 80069FD0-80069FF8       .text JSGSetViewTargetPosition__14dDemo_camera_cFRC3Vec */
void dDemo_camera_c::JSGSetViewTargetPosition(const Vec& v) {
    mTargetPosition = v;
    mFlags |= 0x40;
}

/* 80069FF8-8006A050       .text JSGGetViewRoll__14dDemo_camera_cCFv */
f32 dDemo_camera_c::JSGGetViewRoll() const {
    camera_class* view = getView();
    if (view == NULL)
        return 0.0f;
    return cM_sht2d(view->mBank);
}

/* 8006A050-8006A064       .text JSGSetViewRoll__14dDemo_camera_cFf */
void dDemo_camera_c::JSGSetViewRoll(f32 v) {
    mRoll = v;
    mFlags |= 0x80;
}

/* 8006A064-8006A094       .text JSGSetColor__15dDemo_ambient_cF8_GXColor */
void dDemo_ambient_c::JSGSetColor(GXColor color) {
    mColor = color;
    mFlags |= 0x01;
}

/* 8006A094-8006A0A8       .text JSGSetLightType__13dDemo_light_cFQ26JStage7TELight */
void dDemo_light_c::JSGSetLightType(JStage::TELight type) {
    mLightType = type;
    mFlags |= 0x01;
}

/* 8006A0A8-8006A0D0       .text JSGSetPosition__13dDemo_light_cFRC3Vec */
void dDemo_light_c::JSGSetPosition(const Vec& v) {
    mPosition = v;
    mFlags |= 0x02;
}

/* 8006A0D0-8006A100       .text JSGSetColor__13dDemo_light_cF8_GXColor */
void dDemo_light_c::JSGSetColor(GXColor v) {
    mColor = v;
    mFlags |= 0x04;
}

/* 8006A100-8006A11C       .text JSGSetDistanceAttenuation__13dDemo_light_cFff13_GXDistAttnFn */
void dDemo_light_c::JSGSetDistanceAttenuation(f32 ref0, f32 ref1, GXDistAttnFn fn) {
    mDistAttn0 = ref0;
    mDistAttn1 = ref1;
    mAttnFn = fn;
    mFlags |= 0x08;
}

/* 8006A11C-8006A134       .text JSGSetAngleAttenuation__13dDemo_light_cFf9_GXSpotFn */
void dDemo_light_c::JSGSetAngleAttenuation(f32 ref, GXSpotFn fn) {
    mAngleAttn = ref;
    mSpotFn = fn;
    mFlags |= 0x10;
}

/* 8006A134-8006A15C       .text JSGSetDirection__13dDemo_light_cFRC3Vec */
void dDemo_light_c::JSGSetDirection(const Vec& v) {
    mDirection = v;
    mFlags |= 0x20;
}

/* 8006A15C-8006A170       .text JSGSetFogFunction__11dDemo_fog_cF10_GXFogType */
void dDemo_fog_c::JSGSetFogFunction(GXFogType type) {
    mFogType = type;
    mFlags |= 0x01;
}

/* 8006A170-8006A184       .text JSGSetStartZ__11dDemo_fog_cFf */
void dDemo_fog_c::JSGSetStartZ(f32 v) {
    mStartZ = v;
    mFlags |= 0x02;
}

/* 8006A184-8006A198       .text JSGSetEndZ__11dDemo_fog_cFf */
void dDemo_fog_c::JSGSetEndZ(f32 v) {
    mEndZ = v;
    mFlags |= 0x04;
}

/* 8006A198-8006A1C8       .text JSGSetColor__11dDemo_fog_cF8_GXColor */
void dDemo_fog_c::JSGSetColor(GXColor color) {
    mColor = color;
    mFlags |= 0x08;
}

/* 8006A1C8-8006A1E4       .text __ct__14dDemo_object_cFv */
dDemo_object_c::dDemo_object_c() {
    mNumActor = 0;
    mNumLight = 0;
    mpActiveCamera = NULL;
    mpAmbient = NULL;
    mpFog = NULL;
}

/* 8006A1E4-8006A234       .text __dt__14dDemo_object_cFv */
dDemo_object_c::~dDemo_object_c() {
    remove();
}

/* 8006A234-8006A2F8       .text appendActor__14dDemo_object_cFP10fopAc_ac_c */
dDemo_actor_c* dDemo_object_c::appendActor(fopAc_ac_c* ac) {
    dDemo_actor_c* demoActor = dComIfGp_demo_getActor(ac->demoActorID);
    if (demoActor != NULL)
        return demoActor;

    if (mNumActor >= ARRAY_SIZE(mpActors))
        return NULL;

    demoActor = new dDemo_actor_c();
    if (demoActor == NULL)
        return NULL;

    mpActors[mNumActor++] = demoActor;
    demoActor->setActor(ac);
    ac->demoActorID = mNumActor;
    return demoActor;
}

/* 8006A2F8-8006A31C       .text getActor__14dDemo_object_cFUc */
dDemo_actor_c* dDemo_object_c::getActor(u8 no) {
    if (no == 0 || no > ARRAY_SIZE(mpActors))
        return NULL;
    return mpActors[no - 1];
}

/* 8006A31C-8006A398       .text createCamera__14dDemo_object_cFv */
dDemo_camera_c* dDemo_object_c::createCamera() {
    if (mpActiveCamera != NULL)
        return mpActiveCamera;

    mpActiveCamera = new dDemo_camera_c();
    return mpActiveCamera;
}

/* 8006A398-8006A3AC       .text getActiveCamera__14dDemo_object_cFv */
dDemo_camera_c* dDemo_object_c::getActiveCamera() {
    if (mpActiveCamera != NULL)
        return mpActiveCamera;
    return NULL;
}

/* 8006A3AC-8006A428       .text createAmbient__14dDemo_object_cFv */
dDemo_ambient_c* dDemo_object_c::createAmbient() {
    if (mpAmbient != NULL)
        return mpAmbient;

    mpAmbient = new dDemo_ambient_c();
    return mpAmbient;
}

/* 8006A428-8006A4C8       .text appendLight__14dDemo_object_cFv */
dDemo_light_c* dDemo_object_c::appendLight() {
    if (mNumLight >= ARRAY_SIZE(mpLight))
        return NULL;

    dDemo_light_c* demoLight = new dDemo_light_c();
    if (demoLight == NULL)
        return NULL;

    mpLight[mNumLight++] = demoLight;
    return demoLight;
}

/* 8006A4C8-8006A544       .text createFog__14dDemo_object_cFv */
dDemo_fog_c* dDemo_object_c::createFog() {
    if (mpFog != NULL)
        return mpFog;

    mpFog = new dDemo_fog_c();
    return mpFog;
}

/* 8006A544-8006A678       .text remove__14dDemo_object_cFv */
void dDemo_object_c::remove() {
    while (mNumActor)
        delete mpActors[--mNumActor];

    if (mpActiveCamera != NULL) {
        delete mpActiveCamera;
        mpActiveCamera = NULL;
    }

    if (mpAmbient != NULL) {
        delete mpAmbient;
        mpAmbient = NULL;
    }

    while (mNumLight)
        delete mpLight[--mNumLight];

    if (mpFog != NULL) {
        delete mpFog;
        mpFog = NULL;
    }
}

/* 8006A7F8-8006A92C       .text JSGFindObject__14dDemo_system_cCFPCcQ26JStage8TEObject */
void* dDemo_system_c::JSGFindObject(const char* name, JStage::TEObject type) const {
    if (mObject == NULL)
        return NULL;

    if (type == JStage::TOBJ_ACTOR || type == JStage::TOBJ_ACTOR_UNK) {
        fopAc_ac_c* ac = fopAcM_searchFromName((char*)name, 0, 0);
        if (ac == NULL) {
            if (type == JStage::TOBJ_ACTOR && strncmp(name, "d_act", 5) == 0) {
                ac = (fopAc_ac_c*)fopAcM_fastCreate((char*)name, 0);
                if (ac == NULL)
                    return NULL;
                fopAcM_setStageLayer(ac);
            } else {
                return NULL;
            }
        }
        return mObject->appendActor(ac);
    } else if (type == JStage::TOBJ_CAMERA) {
        return mObject->createCamera();
    } else if (type == JStage::TOBJ_AMBIENT) {
        return mObject->createAmbient();
    } else if (type == JStage::TOBJ_LIGHT) {
        return mObject->appendLight();
    } else if (type == JStage::TOBJ_FOG) {
        return mObject->createFog();
    } else {
        return NULL;
    }
}

/* 8006A92C-8006ADA0       .text __ct__15dDemo_manager_cFv */
dDemo_manager_c::dDemo_manager_c() {
    /* Nonmatching */
    mCurFile = NULL;
    mFrame = 0;
    mMesgControl = new dMesg_tControl();
    JUT_ASSERT(0x5b6, mMesgControl != 0);
    mSystem = new dDemo_system_c();
    JUT_ASSERT(0x5ba, mSystem != 0);
    mControl = new JStudio::TControl();
    // TODO: finish this once we make progress on JStudio headers
    // mFactory->appendCreateObj(mStage);
    // mFactory->appendCreateObj(mAudio);
    // mFactory->appendCreateObj(mParticle);
    mSystem->setObject(&mDemoObj);
    // mFactory->appendCreateObj(mMessage);
    mMode = 0;
}

/* 8006ADA0-8006AEFC       .text __dt__15dDemo_manager_cFv */
dDemo_manager_c::~dDemo_manager_c() {
    /* Nonmatching */
}

/* 8006AEFC-8006AF5C       .text __dt__14dMesg_tControlFv */
// dMesg_tControl::~dMesg_tControl() {
//     /* Nonmatching */
// }

/* 8006AF5C-8006AFBC       .text __dt__14dDemo_system_cFv */
dDemo_system_c::~dDemo_system_c() {}

/* 8006AFBC-8006B0D4       .text create__15dDemo_manager_cFPCUcP4cXyzf */
void dDemo_manager_c::create(const u8*, cXyz*, f32) {
    /* Nonmatching */
}

/* 8006B0D4-8006B12C       .text remove__15dDemo_manager_cFv */
void dDemo_manager_c::remove() {
    /* Nonmatching */
}

/* 8006B12C-8006B1B4       .text update__15dDemo_manager_cFv */
void dDemo_manager_c::update() {
    /* Nonmatching */
}
