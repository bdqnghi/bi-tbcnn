/* coding: utf-8 */
/**
 * Nekomata
 *
 * Copyright 2012-2013, PSI
 */

#include <cstdarg>
#include <cmath>
#include <set>
#include <algorithm>
#include <functional>
#include <memory>
#include <nekomata/logging/Logging.h>

#include "Object.h"
#include "SystemObject.h"
#include "Cast.h"
#include "Heap.h"

namespace nekomata{
namespace object{

const static std::string TAG("HEAP");

ObjectHeap::ObjectHeap(logging::Logger& log, system::System& system, RootHolder& rootHolder)
:log(log)
,rootHolder(rootHolder)
,from(&area1)
,to(&area2)
,count(0)
,gcThreshold(10000)
,gcCount(0)
,rawObject(*this, true)
,baseObject(*this, false)
,systemObject(baseObject, system)
,baseLabelObject(baseObject)
,baseReplaceObject(baseObject)
,baseSumObject(baseObject)
,baseSumResultObject(baseObject)
,baseShapePbject(baseObject)
,baseLazyEvalObject(baseObject)
,baseLambdaObject(*this)
,baseLambdaScopeObject(rawObject)
,baseStringObject(baseObject)
,baseNumericObject(baseObject)
,trueObject(baseObject, true)
,falseObject(baseObject, false)
,undefinedObject(rawObject)
{
	systemObject.setSlot("Object", newObject());
	systemObject.setSlot("undefined", newUndefinedObject());
}
ObjectHeap::~ObjectHeap()
{
	for(std::vector<Object*>::iterator it = from->begin();it!=from->begin();++it)
	{
		Object* const obj = *it;
		if(obj->refcount() > 0){
			const int nativeRef = obj->refcount();
			log.e(TAG, 0, "[FIXME] Memory leaked! %s has %d native refs on exit.", cast<std::string>(Handler<Object>(obj)).c_str(), nativeRef);
		}
		delete *it;
	}
}

Handler<SystemObject> ObjectHeap::getSystemObject()
{
	return Handler<SystemObject>::__internal__fromRawPointerWithoutCheck(&systemObject);
}

Handler<LabelObject> ObjectHeap::newLabelObject(Handler<system::Label> label)
{
	const Handler<LabelObject> obj(new LabelObject(baseLabelObject, createHash(), label));
	registerObject(obj.get());
	return obj;
}
Handler<ReplaceObject> ObjectHeap::newReplaceObject(Handler<system::Replace> replace)
{
	const Handler<ReplaceObject> obj(new ReplaceObject(baseReplaceObject, createHash(), replace));
	registerObject(obj.get());
	return obj;
}
Handler<SumObject> ObjectHeap::newSumObject(Handler<system::Sum> sum)
{
	const Handler<SumObject> obj(new SumObject(baseSumObject, createHash(), sum));
	registerObject(obj.get());
	return obj;
}
Handler<SumResultObject> ObjectHeap::newSumResultObject(Handler<system::SumResult> sumResult)
{
	const Handler<SumResultObject> obj(new SumResultObject(baseSumResultObject, createHash(), sumResult));
	registerObject(obj.get());
	return obj;
}
Handler<ShapeObject> ObjectHeap::newShapeObject(Handler<system::Shape> shape)
{
	const Handler<ShapeObject> obj(new ShapeObject(baseShapePbject, createHash(), shape));
	registerObject(obj.get());
	return obj;
}

Handler<Object> ObjectHeap::newObject()
{
	Handler<Object> obj(new Object(baseObject, createHash()));
	registerObject(obj.get());
	return obj;
}

Handler<Object> ObjectHeap::newRawObject()
{
	Handler<Object> obj(new Object(rawObject, createHash()));
	registerObject(obj.get());
	return obj;
}

Handler<Object> ObjectHeap::newArrayObject(const size_t argc, ...)
{
	Handler<Object> obj(new Object(rawObject, createHash()));

	va_list list;
	va_start(list, argc);
	for(size_t i=0;i<argc;++i){
		obj->push(Handler<Object>::__internal__fromRawPointerWithoutCheck(va_arg(list, Object*)));
	}
	va_end(list);

	registerObject(obj.get());
	return obj;
}

Handler<LambdaScopeObject> ObjectHeap::newLambdaScopeObject(const Handler<Object> arg)
{
	Handler<LambdaScopeObject> obj(new LambdaScopeObject(baseLambdaScopeObject, createHash(), arg));
	registerObject(obj.get());
	return obj;
}

void ObjectHeap::registerObject(Object* obj){
	if(gcThreshold <= this->from->size()){
		this->gc();
	}
	this->from->push_back(obj);
}

Handler<StringObject> ObjectHeap::newStringObject(const std::string & str)
{
	Handler<StringObject> obj(new StringObject(baseStringObject, createHash(), str));
	registerObject(obj.get());
	return obj;
}



Handler<BooleanObject> ObjectHeap::newBooleanObject(const bool val)
{
	if(val){
		return Handler<BooleanObject>::__internal__fromRawPointerWithoutCheck(&trueObject);
	}else{
		return Handler<BooleanObject>::__internal__fromRawPointerWithoutCheck(&falseObject);
	}
}



Handler<NumericObject> ObjectHeap::newNumericObject(const double num)
{
	Handler<NumericObject> obj(new NumericObject(baseNumericObject, createHash(), num));
	registerObject(obj.get());
	return obj;
}

Handler<UndefinedObject> ObjectHeap::newUndefinedObject()
{
	return Handler<UndefinedObject>::__internal__fromRawPointerWithoutCheck(&undefinedObject);
}

Handler<LazyEvalObject> ObjectHeap::newLazyEvalObject(machine::Machine& machine, const tree::ObjectNode *objNode)
{
	Handler<LazyEvalObject> obj(new LazyEvalObject(baseLazyEvalObject, createHash(), machine, objNode));
	registerObject(obj.get());
	return obj;
}

Handler<MethodNodeObject> ObjectHeap::newMethodNodeObject(const Handler<Object> scope, const tree::Node* node, MethodNodeObject::LocalScopeRule rule, std::vector<std::string>& argList)
{
	Handler<MethodNodeObject> obj(new MethodNodeObject(rawObject, createHash(), scope, node, rule, argList));
	registerObject(obj.get());
	return obj;
}
Handler<MethodNodeObject> ObjectHeap::newMethodNodeObject(const Handler<Object> scope, const tree::Node* node, MethodNodeObject::LocalScopeRule rule)
{
	Handler<MethodNodeObject> obj(new MethodNodeObject(rawObject, createHash(), scope, node, rule));
	registerObject(obj.get());
	return obj;
}

Handler<LambdaObject> ObjectHeap::newLambdaObject(const Handler<Object> scope, const tree::Node* node)
{
	const Handler<LambdaObject> obj(new LambdaObject(baseLambdaObject, createHash(), scope, node));
	registerObject(obj.get());
	return obj;
}

bool deleteFunc(int color, std::set<Object*, std::function<bool(Object*, Object*)> >* unused, Object* obj)
{
	if(obj->getColor() == color){
		return false;
	}else{
		unused->insert(obj);
		return true;
	}
}

void ObjectHeap::gc()
{
	gcCount++;
	size_t before = this->from->size();

	{
		std::auto_ptr<RootHolder::Iterator> it(rootHolder.newIterator());
		while(it->hasNext())
		{
			Object* const obj = it->next();
			obj->mark(this->gcCount);
		}
	}
	//ネイティブから参照されてるオブジェクトもルート扱い。
	for(std::vector<Object*>::const_iterator it=from->begin();it!=from->end();++it)
	{
		Object* const obj = *it;
		if(obj->refcount() > 0){
			obj->mark(gcCount);
		}
	}
	std::set<Object*> unused;
	for(std::vector<Object*>::const_iterator it=from->begin();it!=from->end();++it)
	{
		Object* const obj = *it;
		if(obj->getColor() != gcCount){
			unused.insert(obj);
		}else{
			to->push_back(obj);
		}
	}

	log.d(TAG, 0, "Garbage collected: %d -> %d objects (%d%% collected)", before, before-unused.size(), unused.size()*100/before);
	for(std::set<Object*>::const_iterator it=unused.begin();it!=unused.end();++it)
	{
		delete (*it);
	}

	this->from->clear();
	std::swap(from, to);
}

int ObjectHeap::createHash()
{
	return ++count;
}

}}
