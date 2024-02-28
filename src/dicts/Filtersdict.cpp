// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdIFiltersdict

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
#include "Filters.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_Filters(void *p);
   static void deleteArray_Filters(void *p);
   static void destruct_Filters(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Filters*)
   {
      ::Filters *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Filters >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Filters", ::Filters::Class_Version(), "Filters.hh", 19,
                  typeid(::Filters), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Filters::Dictionary, isa_proxy, 4,
                  sizeof(::Filters) );
      instance.SetDelete(&delete_Filters);
      instance.SetDeleteArray(&deleteArray_Filters);
      instance.SetDestructor(&destruct_Filters);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Filters*)
   {
      return GenerateInitInstanceLocal((::Filters*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Filters*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Filters::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Filters::Class_Name()
{
   return "Filters";
}

//______________________________________________________________________________
const char *Filters::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Filters*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Filters::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Filters*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Filters::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Filters*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Filters::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Filters*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Filters::Streamer(TBuffer &R__b)
{
   // Stream an object of class Filters.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Filters::Class(),this);
   } else {
      R__b.WriteClassBuffer(Filters::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Filters(void *p) {
      delete ((::Filters*)p);
   }
   static void deleteArray_Filters(void *p) {
      delete [] ((::Filters*)p);
   }
   static void destruct_Filters(void *p) {
      typedef ::Filters current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Filters

namespace {
  void TriggerDictionaryInitialization_Filtersdict_Impl() {
    static const char* headers[] = {
"Filters.hh",
0
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/snsw/opt/root-6.16.00/include/root",
"/sps/nemo/scratch/mpetro/Projects/TestFalaiseModule/SNCuts/include/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Filtersdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Filters.hh")))  Filters;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Filtersdict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Filters.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Filters", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Filtersdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Filtersdict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Filtersdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Filtersdict() {
  TriggerDictionaryInitialization_Filtersdict_Impl();
}
