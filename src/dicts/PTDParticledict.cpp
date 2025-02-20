// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdIPTDParticledict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "PTDParticle.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_PTDParticle(void *p = nullptr);
   static void *newArray_PTDParticle(Long_t size, void *p);
   static void delete_PTDParticle(void *p);
   static void deleteArray_PTDParticle(void *p);
   static void destruct_PTDParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PTDParticle*)
   {
      ::PTDParticle *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PTDParticle >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PTDParticle", ::PTDParticle::Class_Version(), "PTDParticle.hh", 14,
                  typeid(::PTDParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PTDParticle::Dictionary, isa_proxy, 4,
                  sizeof(::PTDParticle) );
      instance.SetNew(&new_PTDParticle);
      instance.SetNewArray(&newArray_PTDParticle);
      instance.SetDelete(&delete_PTDParticle);
      instance.SetDeleteArray(&deleteArray_PTDParticle);
      instance.SetDestructor(&destruct_PTDParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PTDParticle*)
   {
      return GenerateInitInstanceLocal((::PTDParticle*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PTDParticle*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr PTDParticle::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PTDParticle::Class_Name()
{
   return "PTDParticle";
}

//______________________________________________________________________________
const char *PTDParticle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PTDParticle*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PTDParticle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PTDParticle*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PTDParticle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PTDParticle*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PTDParticle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PTDParticle*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void PTDParticle::Streamer(TBuffer &R__b)
{
   // Stream an object of class PTDParticle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PTDParticle::Class(),this);
   } else {
      R__b.WriteClassBuffer(PTDParticle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PTDParticle(void *p) {
      return  p ? new(p) ::PTDParticle : new ::PTDParticle;
   }
   static void *newArray_PTDParticle(Long_t nElements, void *p) {
      return p ? new(p) ::PTDParticle[nElements] : new ::PTDParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_PTDParticle(void *p) {
      delete ((::PTDParticle*)p);
   }
   static void deleteArray_PTDParticle(void *p) {
      delete [] ((::PTDParticle*)p);
   }
   static void destruct_PTDParticle(void *p) {
      typedef ::PTDParticle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PTDParticle

namespace {
  void TriggerDictionaryInitialization_PTDParticledict_Impl() {
    static const char* headers[] = {
"PTDParticle.hh",
nullptr
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/root-6.26.06/include/root",
"/sps/nemo/scratch/mpetro/Projects/FalaiseModules/SNCuts/include/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "PTDParticledict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$PTDParticle.hh")))  PTDParticle;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "PTDParticledict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "PTDParticle.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"PTDParticle", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("PTDParticledict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_PTDParticledict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_PTDParticledict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_PTDParticledict() {
  TriggerDictionaryInitialization_PTDParticledict_Impl();
}
