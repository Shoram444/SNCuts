// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdICDBankdict

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
#include "CDBank.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_CDBank(void *p = 0);
   static void *newArray_CDBank(Long_t size, void *p);
   static void delete_CDBank(void *p);
   static void deleteArray_CDBank(void *p);
   static void destruct_CDBank(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CDBank*)
   {
      ::CDBank *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CDBank >(0);
      static ::ROOT::TGenericClassInfo 
         instance("CDBank", ::CDBank::Class_Version(), "CDBank.hh", 16,
                  typeid(::CDBank), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CDBank::Dictionary, isa_proxy, 4,
                  sizeof(::CDBank) );
      instance.SetNew(&new_CDBank);
      instance.SetNewArray(&newArray_CDBank);
      instance.SetDelete(&delete_CDBank);
      instance.SetDeleteArray(&deleteArray_CDBank);
      instance.SetDestructor(&destruct_CDBank);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CDBank*)
   {
      return GenerateInitInstanceLocal((::CDBank*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CDBank*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CDBank::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *CDBank::Class_Name()
{
   return "CDBank";
}

//______________________________________________________________________________
const char *CDBank::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int CDBank::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CDBank::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CDBank::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CDBank::Streamer(TBuffer &R__b)
{
   // Stream an object of class CDBank.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CDBank::Class(),this);
   } else {
      R__b.WriteClassBuffer(CDBank::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CDBank(void *p) {
      return  p ? new(p) ::CDBank : new ::CDBank;
   }
   static void *newArray_CDBank(Long_t nElements, void *p) {
      return p ? new(p) ::CDBank[nElements] : new ::CDBank[nElements];
   }
   // Wrapper around operator delete
   static void delete_CDBank(void *p) {
      delete ((::CDBank*)p);
   }
   static void deleteArray_CDBank(void *p) {
      delete [] ((::CDBank*)p);
   }
   static void destruct_CDBank(void *p) {
      typedef ::CDBank current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CDBank

namespace ROOT {
   static TClass *vectorlECDHitgR_Dictionary();
   static void vectorlECDHitgR_TClassManip(TClass*);
   static void *new_vectorlECDHitgR(void *p = 0);
   static void *newArray_vectorlECDHitgR(Long_t size, void *p);
   static void delete_vectorlECDHitgR(void *p);
   static void deleteArray_vectorlECDHitgR(void *p);
   static void destruct_vectorlECDHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CDHit>*)
   {
      vector<CDHit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CDHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CDHit>", -2, "vector", 216,
                  typeid(vector<CDHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECDHitgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CDHit>) );
      instance.SetNew(&new_vectorlECDHitgR);
      instance.SetNewArray(&newArray_vectorlECDHitgR);
      instance.SetDelete(&delete_vectorlECDHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlECDHitgR);
      instance.SetDestructor(&destruct_vectorlECDHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CDHit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<CDHit>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECDHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<CDHit>*)0x0)->GetClass();
      vectorlECDHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECDHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECDHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CDHit> : new vector<CDHit>;
   }
   static void *newArray_vectorlECDHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CDHit>[nElements] : new vector<CDHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECDHitgR(void *p) {
      delete ((vector<CDHit>*)p);
   }
   static void deleteArray_vectorlECDHitgR(void *p) {
      delete [] ((vector<CDHit>*)p);
   }
   static void destruct_vectorlECDHitgR(void *p) {
      typedef vector<CDHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<CDHit>

namespace {
  void TriggerDictionaryInitialization_CDBankdict_Impl() {
    static const char* headers[] = {
"CDBank.hh",
0
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/snsw/opt/root-6.16.00/include/root",
"/sps/nemo/scratch/mpetro/Projects/TestFalaiseModule/SNCuts/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CDBankdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$CDBank.hh")))  CDBank;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CDBankdict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CDBank.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CDBank", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CDBankdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CDBankdict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CDBankdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CDBankdict() {
  TriggerDictionaryInitialization_CDBankdict_Impl();
}
