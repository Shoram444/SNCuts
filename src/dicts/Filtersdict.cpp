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
   static void *new_Filters(void *p = 0);
   static void *newArray_Filters(Long_t size, void *p);
   static void delete_Filters(void *p);
   static void deleteArray_Filters(void *p);
   static void destruct_Filters(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Filters*)
   {
      ::Filters *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Filters >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Filters", ::Filters::Class_Version(), "Filters.hh", 16,
                  typeid(::Filters), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Filters::Dictionary, isa_proxy, 4,
                  sizeof(::Filters) );
      instance.SetNew(&new_Filters);
      instance.SetNewArray(&newArray_Filters);
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
   // Wrappers around operator new
   static void *new_Filters(void *p) {
      return  p ? new(p) ::Filters : new ::Filters;
   }
   static void *newArray_Filters(Long_t nElements, void *p) {
      return p ? new(p) ::Filters[nElements] : new ::Filters[nElements];
   }
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

namespace ROOT {
   static TClass *vectorlEfunctionlEbooloPEventaNcPgRsPgR_Dictionary();
   static void vectorlEfunctionlEbooloPEventaNcPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p = 0);
   static void *newArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p);
   static void deleteArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p);
   static void destruct_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<function<bool(Event&)> >*)
   {
      vector<function<bool(Event&)> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<function<bool(Event&)> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<function<bool(Event&)> >", -2, "vector", 216,
                  typeid(vector<function<bool(Event&)> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfunctionlEbooloPEventaNcPgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<function<bool(Event&)> >) );
      instance.SetNew(&new_vectorlEfunctionlEbooloPEventaNcPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR);
      instance.SetDelete(&delete_vectorlEfunctionlEbooloPEventaNcPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEfunctionlEbooloPEventaNcPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<function<bool(Event&)> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<function<bool(Event&)> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfunctionlEbooloPEventaNcPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<function<bool(Event&)> >*)0x0)->GetClass();
      vectorlEfunctionlEbooloPEventaNcPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfunctionlEbooloPEventaNcPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<function<bool(Event&)> > : new vector<function<bool(Event&)> >;
   }
   static void *newArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<function<bool(Event&)> >[nElements] : new vector<function<bool(Event&)> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p) {
      delete ((vector<function<bool(Event&)> >*)p);
   }
   static void deleteArray_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p) {
      delete [] ((vector<function<bool(Event&)> >*)p);
   }
   static void destruct_vectorlEfunctionlEbooloPEventaNcPgRsPgR(void *p) {
      typedef vector<function<bool(Event&)> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<function<bool(Event&)> >

namespace {
  void TriggerDictionaryInitialization_Filtersdict_Impl() {
    static const char* headers[] = {
"Filters.hh",
0
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/BxCppDev/opt/root-6.16.00/include/root",
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
