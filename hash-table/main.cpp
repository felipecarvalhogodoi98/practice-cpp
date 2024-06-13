#include <unistd.h>
#include "hash_table.h"
#include "hash_table.cpp"

static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

std::string gen_random(const int len) {
  std::string tmp_s;
  tmp_s.reserve(len);

  for (int i = 0; i < len; ++i) {
    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
  }
  
  return tmp_s;
}

std::string int_to_string(int v) {
  return std::to_string(v * v * 7);
}

int main (int argc, char* argv[]) {
  srand((unsigned)time(NULL) * getpid());

  F::HashTable<std::string> *ht = new F::HashTable<std::string>();

  std::cout << "Fill hash table" << std::endl;
  for (int i = 0; i < initialCapacity; i ++) {
    ht->add(int_to_string(i), gen_random(5));
  }
      
  std::cout << *ht;

  for (int i = 0; i < initialCapacity; i ++) {
    assert(ht->exists(int_to_string(i)));
  }

  for (int i = 0; i < initialCapacity; i ++) {
    std::string key = int_to_string(i);
    F::Element<std::string> *el = ht->get(key);

    assert(el != nullptr);

    assert(el->getKey().compare(key) == 0);
  }

  std::cout << "Remove all items of hash table" << std::endl;
  for (int i = 0; i < initialCapacity; i ++) {
    std::string keyToRemove = int_to_string(i);
    assert(ht->exists(keyToRemove));
    ht->remove(keyToRemove);
    assert(!ht->exists(keyToRemove));
  }
  std::cout << *ht;


  std::cout << "Fill hash table to resize" << std::endl;
  for (int i = 0; i < initialCapacity; i ++) {
    ht->add(int_to_string(i), gen_random(5));
  }
  std::cout << *ht;
  
  return 0;
}
