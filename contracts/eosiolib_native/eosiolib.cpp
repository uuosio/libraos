#include <eosiolib/types.h>
#include <eosiolib/privileged.hpp>

#include <eosiolib/datastream.hpp>

namespace eosio {

   void set_blockchain_parameters(const eosio::blockchain_parameters& params) {
      char buf[sizeof(eosio::blockchain_parameters)];
      eosio::datastream<char *> ds( buf, sizeof(buf) );
      ds << params;
      set_blockchain_parameters_packed( buf, ds.tellp() );
   }

   void get_blockchain_parameters(eosio::blockchain_parameters& params) {
      char buf[sizeof(eosio::blockchain_parameters)];
      size_t size = get_blockchain_parameters_packed( buf, sizeof(buf) );
      eosio_assert( size <= sizeof(buf), "buffer is too small" );
      eosio::datastream<const char*> ds( buf, size_t(size) );
      ds >> params;
   }

} /// namespace eosio

#include "vm_api.h"
static struct vm_api* s_api = nullptr;
void vm_register_api(struct vm_api* api) {
   if (!api) {
      throw std::runtime_error("vm_api pointer can not be NULL!");
   }
   s_api = api;
}

struct vm_api* get_vm_api() {
   if (!s_api) {
      throw std::runtime_error("vm api not specified!!!");
   }
   return s_api;
}
