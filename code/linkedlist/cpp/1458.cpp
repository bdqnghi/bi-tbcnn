#include "linkedlist.h"
#include "empty.h"
#include "error.h"
#include "symbol.h"
#include "environment.h"
#include "boolean.h"
#include "function.h"
#include "nil.h"

using std::shared_ptr;
using std::unique_ptr;

namespace lisp
{

LinkedList::LinkedList(std::list<shared_ptr<Object>> &items)
    : m_items(items)
{
    if (items.size() < 1)
    {
        throw Error("linked list must contain items");
    }
}

shared_ptr<Object> LinkedList::car() const
{
    return m_items.front();
}

shared_ptr<Object> LinkedList::cdr() const
{
    if (m_items.size() == 1)
    {
        return Empty::get();
    }
    auto items = m_items;
    items.pop_front();
    return shared_ptr<LinkedList>(new LinkedList(items));
}

shared_ptr<Object> LinkedList::eval(shared_ptr<Environment> env)
{
    shared_ptr<Object> obj = Nil::get();
    if ((obj = eval_quote()) != Nil::get()) return obj;
    if ((obj = eval_set(env)) != Nil::get()) return obj;
    if ((obj = eval_if(env)) != Nil::get()) return obj;
    if ((obj = eval_cond(env)) != Nil::get()) return obj;
    if ((obj = eval_define(env)) != Nil::get()) return obj;
    if ((obj = eval_lambda(env)) != Nil::get()) return obj;
    if ((obj = eval_cons(env)) != Nil::get()) return obj;
    if ((obj = eval_car(env)) != Nil::get()) return obj;
    if ((obj = eval_cdr(env)) != Nil::get()) return obj;
    if ((obj = eval_eq(env)) != Nil::get()) return obj;
    if ((obj = eval_function(env)) != Nil::get()) return obj;
    throw Error("can't eval linked list");
}

unsigned int LinkedList::size() const
{
    return m_items.size();
}

unique_ptr<lisp::Iterator> LinkedList::iterator() const
{
    auto it = new LinkedListIterator(m_items.begin(), m_items.end());
    return unique_ptr<lisp::Iterator>(it);
}

shared_ptr<Object> LinkedList::eval_quote() const
{
    if (!(m_items.size() == 2)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto obj = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "quote")) return Nil::get();
    return obj;
}

shared_ptr<Object> LinkedList::eval_set(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 3)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto key = *it;
    it++;
    auto body = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "set!")) return Nil::get();
    return env->set(Symbol::name(key), lisp::eval(env, body));
}

shared_ptr<Object> LinkedList::eval_if(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 4)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto pred = *it;
    it++;
    auto on_true = *it;
    it++;
    auto on_false = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "if")) return Nil::get();
    if (Boolean::value(lisp::eval(env, pred)))
    {
        return lisp::eval(env, on_true);
    }
    else
    {
        return lisp::eval(env, on_false);
    }
}

shared_ptr<Object> LinkedList::eval_cond(shared_ptr<Environment> env) const
{
    if (!(m_items.size() >= 2)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "cond")) return Nil::get();
    it++;
    for (; it != m_items.end(); ++it)
    {
        auto list = List::to(*it);
        if (list->size() != 2)
        {
            throw Error("condition has wrong list size");
        }
        auto list_it = list->iterator();
        if (Boolean::value(lisp::eval(env, list_it->get())))
        {
            list_it->next();
            return lisp::eval(env, list_it->get());
        }
    }
    throw Error("all conditions failed");
}

shared_ptr<Object> LinkedList::eval_define(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 3)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto key = *it;
    it++;
    auto body = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "def")) return Nil::get();
    if (key->type() == Type::Symbol) 
    {
        return env->define(Symbol::name(key), lisp::eval(env, body));
    }
    else if (key->type() == Type::List)
    {
        auto fn_params = List::to(key);
        if (fn_params->size() >= 1)
        {
            auto it = fn_params->iterator();
            auto fn = it->get();
            if (fn->type() != Type::Symbol) return Nil::get();

            std::list<shared_ptr<Object>> params;
            for (it->next(); !it->is_done(); it->next())
            {
                params.push_back(it->get());
            }
            auto lambda = shared_ptr<Object>(new Lambda(shared_ptr<Object>(new LinkedList(params)), body, env));
            return env->define(Symbol::name(fn), lambda);
        }
        return Nil::get();
    }
    return Nil::get();
}

shared_ptr<Object> LinkedList::eval_lambda(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 3)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto params = *it;
    it++;
    auto body = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "lam")) return Nil::get();
    if (!(params->type() == Type::List)) return Nil::get();
    return shared_ptr<Object>(new Lambda(params, body, env));
}

shared_ptr<Object> LinkedList::eval_function(shared_ptr<Environment> env) const
{
    if (!(m_items.size() >= 1)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    std::list<shared_ptr<Object>> items;
    for (; it != m_items.end(); ++it)
    {
        items.push_back(lisp::eval(env, *it));
    }
    auto args = shared_ptr<LinkedList>(new LinkedList(items));
    return lisp::eval(env, op)->apply(args);
}

shared_ptr<Object> LinkedList::eval_cons(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 3)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto fst = *it;
    it++;
    auto snd = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "cons")) return Nil::get();
    auto car = lisp::eval(env, fst);
    auto cdr = lisp::eval(env, snd);
    return lisp::cons(car, cdr);
}

shared_ptr<Object> LinkedList::eval_car(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 2)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto list = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "car")) return Nil::get();
    return List::to(lisp::eval(env, list))->car();
}

shared_ptr<Object> LinkedList::eval_cdr(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 2)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto list = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "cdr")) return Nil::get();
    return List::to(lisp::eval(env, list))->cdr();
}

shared_ptr<Object> LinkedList::eval_eq(shared_ptr<Environment> env) const
{
    if (!(m_items.size() == 3)) return Nil::get();
    auto it = m_items.begin();
    auto op = *it;
    it++;
    auto fst = *it;
    it++;
    auto snd = *it;
    if (!(op->type() == Type::Symbol)) return Nil::get();
    if (!(Symbol::name(op) == "eq?")) return Nil::get();
    auto left = lisp::eval(env, fst);
    auto right = lisp::eval(env, snd);
    return shared_ptr<Boolean>(new Boolean(left->eq(right)));
}

LinkedListIterator::LinkedListIterator(std::list<shared_ptr<Object>>::const_iterator start, std::list<shared_ptr<Object>>::const_iterator last)
    : m_current(start)
    , m_last(last)
    , m_end(last)
{
    m_last--;
}

void LinkedListIterator::next()
{
    m_current++;
}

bool LinkedListIterator::is_done() const
{
    return m_current == m_end;
}

bool LinkedListIterator::is_last() const
{
    return m_current == m_last;
}

shared_ptr<Object> LinkedListIterator::get() const
{
    return *m_current;
}

}
