// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdICDHitdict

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

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "CDHit.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_CDHit(void *p = 0);
   static void *newArray_CDHit(Long_t size, void *p);
   static void delete_CDHit(void *p);
   static void deleteArray_CDHit(void *p);
   static void destruct_CDHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CDHit*)
   {
      ::CDHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CDHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("CDHit", ::CDHit::Class_Version(), "CDHit.hh", 14,
                  typeid(::CDHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CDHit::Dictionary, isa_proxy, 4,
                  sizeof(::CDHit) );
      instance.SetNew(&new_CDHit);
      instance.SetNewArray(&newArray_CDHit);
      instance.SetDelete(&delete_CDHit);
      instance.SetDeleteArray(&deleteArray_CDHit);
      instance.SetDestructor(&destruct_CDHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CDHit*)
   {
      return GenerateInitInstanceLocal((::CDHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CDHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CDHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *CDHit::Class_Name()
{
   return "CDHit";
}

//______________________________________________________________________________
const char *CDHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int CDHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CDHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CDHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CDHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class CDHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CDHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(CDHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CDHit(void *p) {
      return  p ? new(p) ::CDHit : new ::CDHit;
   }
   static void *newArray_CDHit(Long_t nElements, void *p) {
      return p ? new(p) ::CDHit[nElements] : new ::CDHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_CDHit(void *p) {
      delete ((::CDHit*)p);
   }
   static void deleteArray_CDHit(void *p) {
      delete [] ((::CDHit*)p);
   }
   static void destruct_CDHit(void *p) {
      typedef ::CDHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CDHit

namespace {
  void TriggerDictionaryInitialization_CDHitdict_Impl() {
    static const char* headers[] = {
"CDHit.hh",
0
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/snsw/opt/root-6.16.00/include/root",
"/sps/nemo/scratch/mpetro/Projects/FalaiseModules/SNCuts/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CDHitdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$CDHit.hh")))  CDHit;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CDHitdict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CDHit.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CDHit", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CDHitdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CDHitdict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CDHitdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CDHitdict() {
  TriggerDictionaryInitialization_CDHitdict_Impl();
}
