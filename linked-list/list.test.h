#ifndef TEST_LINKED_LIST
#define TEST_LINKED_LIST

namespace F{
class ListTest {
  public:
    ListTest();
    void run();

  private:
    void size();
    void empty();
    void value_at();
    void value_at_from_end();
    void push_front();
    void push_back();
    void pop_front();
    void pop_back();
    void front();
    void back();
    void insert();
    void erase();
    void reverse();
    void remove();
};
}

#endif