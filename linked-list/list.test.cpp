#include <cassert>
#include "list.test.h"
#include "list.h"
#include "list.cpp"

namespace F {
  ListTest::ListTest() {}

  void ListTest::run() {
    size();
    empty();
    value_at();
    value_at_from_end();
    push_front();
    push_back();
    pop_front();
    pop_back();
    front();
    back();
    insert();
    erase();
    reverse();
    remove();
    std::cout << "All tests pass!" << std::endl;
  }

  void ListTest::size() {
    List<int>* list = new List<int>();

    assert(list->size() == 0);
  }

  void ListTest::empty() {
    List<int>* list = new List<int>();

    assert(list->empty());
    
    list->push_front(1);

    assert(!list->empty());
  }

  void ListTest::value_at() {
    List<int>* list = new List<int>();
    
    list->push_front(0);
    list->push_front(1);
    list->push_front(2);

    assert(list->value_at(2) == 0);
    assert(list->value_at(1) == 1);
    assert(list->value_at(0) == 2);
  }

  void ListTest::value_at_from_end() {
    List<int>* list = new List<int>();
    
    list->push_front(0);
    list->push_front(1);
    list->push_front(2);

    assert(list->value_at_from_end(0) == 0);
    assert(list->value_at_from_end(1) == 1);
    assert(list->value_at_from_end(2) == 2);
  }

  void ListTest::push_front() {
    List<int>* list = new List<int>();
   

    list->push_front(1);
    assert(list->size() == 1);

    list->push_front(2);
    list->push_front(5);
    
    assert(list->size() == 3);
  }

  void ListTest::push_back() {
    List<int>* list = new List<int>();
   

    list->push_back(1);
    assert(list->size() == 1);

    list->push_back(2);
    list->push_back(5);

    assert(list->size() == 3);
  }

  void ListTest::pop_front() {
    List<int>* list = new List<int>();

    int first = 12;
    int second = 31;
    int last = 2;
    list->push_back(first);
    list->push_back(second);
    list->push_back(5);
    list->push_back(last);

    assert(list->pop_front() == first);
    assert(list->pop_front() == second);
    list->pop_front();
    assert(list->pop_front() == last);
  }

  void ListTest::pop_back() {
    List<int>* list = new List<int>();

    int first = 12;
    int second = 31;
    int last = 2;
    list->push_front(first);
    list->push_front(second);
    list->push_front(5);
    list->push_front(last);

    assert(list->pop_back() == first);
    assert(list->pop_back() == second);
    list->pop_back();
    assert(list->pop_back() == last);
  }

  void ListTest::front() {
    List<int>* list = new List<int>();

    int first = 10;
    list->push_front(first);
    assert(list->front() == first);

    int second = 124;
    list->push_front(second);
    assert(list->front() == second);

    int last = 1;
    list->push_front(last);
    assert(list->front() == last);
  }

  void ListTest::back() {
    List<int>* list = new List<int>();
    
    int first = 10;
    list->push_back(first);
    assert(list->back() == first);

    int second = 124;
    list->push_back(second);
    assert(list->back() == second);

    int last = 1;
    list->push_back(last);
    assert(list->back() == last);
  }

  void ListTest::insert() {
    List<int>* list = new List<int>();
    
    int quant = 10;

    for (int i = 0; i < quant; i++)
      list->insert(i, i);
    
    for (int i = 0; i < quant; i++)
      assert(list->value_at(i) == i);
  }

  void ListTest::erase() {
    List<int>* list = new List<int>(); 

    for (int i = 0; i < 4; i++)
      list->insert(i, i);

    assert(list->erase(0) == 0);
    assert(list->erase(2) == 3);
    assert(list->erase(0) == 1);
    assert(list->erase(0) == 2);
  }

  void ListTest::reverse() {
    List<int>* list = new List<int>();

    int len = 4;
    for (int i = 0; i < len; i++)
      list->insert(i, i);

    for (int i = 0; i < len; i++)
      assert(list->value_at(i) == i);
    list->reverse();

    for (int i = 0; i < len; i++)
      assert(list->value_at_from_end(i) == i);
  }

  void ListTest::remove() {
    List<int>* list = new List<int>();

    int len = 10;
    int itemToRemove = len / 2;
    for (int i = 0; i < len; i++)
      list->insert(i, i);

    assert(list->value_at(itemToRemove) == itemToRemove);
    list->remove(itemToRemove);
    assert(list->value_at(itemToRemove - 1) != itemToRemove);
    assert(list->value_at(itemToRemove) != itemToRemove);
    assert(list->value_at(itemToRemove + 1) != itemToRemove);
  }
}