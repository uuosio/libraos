#include <eosio/chain/exceptions.hpp>
#include <eosiolib_native/vm_exceptions.h>

using namespace eosio::chain;
using namespace fc;

[[ noreturn ]] void vm_throw_exception(int type, const char* fmt, ...) {

#define CASE_EXCEPTION(exc_type) \
   case (int)enum_##exc_type: \
      throw exc_type( FC_LOG_MESSAGE( error, output.data() ) ); \
      break;

#define CASE_FC_EXCEPTION(exc_type) \
   case (int)enum_##exc_type: \
      throw fc::exc_type( FC_LOG_MESSAGE( error, output.data() ) ); \
      break;


   std::vector<char> output(256);
   memset(output.data(), 0, output.size());

   va_list args;
   va_start(args, fmt);
   int len = vsnprintf(output.data(), output.size()-1, fmt, args);
   va_end(args);

   switch(type) {
      CASE_FC_EXCEPTION(exception)
      CASE_FC_EXCEPTION(timeout_exception)
      CASE_FC_EXCEPTION(file_not_found_exception)
      CASE_FC_EXCEPTION(parse_error_exception)
      CASE_FC_EXCEPTION(invalid_arg_exception)
      CASE_FC_EXCEPTION(key_not_found_exception)
      CASE_FC_EXCEPTION(bad_cast_exception)
      CASE_FC_EXCEPTION(out_of_range_exception)
      CASE_FC_EXCEPTION(invalid_operation_exception)
      CASE_FC_EXCEPTION(unknown_host_exception)
      CASE_FC_EXCEPTION(canceled_exception)
      CASE_FC_EXCEPTION(assert_exception)
      CASE_FC_EXCEPTION(eof_exception)
      CASE_FC_EXCEPTION(null_optional)
      CASE_FC_EXCEPTION(udt_exception)
      CASE_FC_EXCEPTION(aes_exception)
      CASE_FC_EXCEPTION(overflow_exception)
      CASE_FC_EXCEPTION(underflow_exception)
      CASE_FC_EXCEPTION(divide_by_zero_exception)

      CASE_EXCEPTION(chain_type_exception)
      CASE_EXCEPTION(name_type_exception)
      CASE_EXCEPTION(public_key_type_exception)
      CASE_EXCEPTION(private_key_type_exception)
      CASE_EXCEPTION(authority_type_exception)
      CASE_EXCEPTION(action_type_exception)
      CASE_EXCEPTION(transaction_type_exception)
      CASE_EXCEPTION(abi_type_exception)
      CASE_EXCEPTION(block_id_type_exception)
      CASE_EXCEPTION(transaction_id_type_exception)
      CASE_EXCEPTION(packed_transaction_type_exception)
      CASE_EXCEPTION(asset_type_exception)
      CASE_EXCEPTION(chain_id_type_exception)
      CASE_EXCEPTION(fixed_key_type_exception)
      CASE_EXCEPTION(symbol_type_exception)
      CASE_EXCEPTION(fork_database_exception)
      CASE_EXCEPTION(fork_db_block_not_found)
      CASE_EXCEPTION(block_validate_exception)
      CASE_EXCEPTION(unlinkable_block_exception)
      CASE_EXCEPTION(block_tx_output_exception)
      CASE_EXCEPTION(block_concurrency_exception)
      CASE_EXCEPTION(block_lock_exception)
      CASE_EXCEPTION(block_resource_exhausted)
      CASE_EXCEPTION(block_too_old_exception)
      CASE_EXCEPTION(block_from_the_future)
      CASE_EXCEPTION(wrong_signing_key)
      CASE_EXCEPTION(wrong_producer)
      CASE_EXCEPTION(transaction_exception)
      CASE_EXCEPTION(tx_decompression_error)
      CASE_EXCEPTION(tx_no_action)
      CASE_EXCEPTION(tx_no_auths)
      CASE_EXCEPTION(cfa_irrelevant_auth)
      CASE_EXCEPTION(expired_tx_exception)
      CASE_EXCEPTION(tx_exp_too_far_exception)
      CASE_EXCEPTION(invalid_ref_block_exception)
      CASE_EXCEPTION(tx_duplicate)
      CASE_EXCEPTION(deferred_tx_duplicate)
      CASE_EXCEPTION(cfa_inside_generated_tx)
      CASE_EXCEPTION(tx_not_found)
      CASE_EXCEPTION(too_many_tx_at_once)
      CASE_EXCEPTION(tx_too_big)
      CASE_EXCEPTION(unknown_transaction_compression)
      CASE_EXCEPTION(action_validate_exception)
      CASE_EXCEPTION(account_name_exists_exception)
      CASE_EXCEPTION(invalid_action_args_exception)
      CASE_EXCEPTION(eosio_assert_message_exception)
      CASE_EXCEPTION(eosio_assert_code_exception)
      CASE_EXCEPTION(action_not_found_exception)
      CASE_EXCEPTION(action_data_and_struct_mismatch)
      CASE_EXCEPTION(unaccessible_api)
      CASE_EXCEPTION(abort_called)
      CASE_EXCEPTION(inline_action_too_big)
      CASE_EXCEPTION(database_exception)
      CASE_EXCEPTION(permission_query_exception)
      CASE_EXCEPTION(account_query_exception)
      CASE_EXCEPTION(contract_table_query_exception)
      CASE_EXCEPTION(contract_query_exception)
      CASE_EXCEPTION(guard_exception)
      CASE_EXCEPTION(database_guard_exception)
      CASE_EXCEPTION(reversible_guard_exception)
      CASE_EXCEPTION(wasm_exception)
      CASE_EXCEPTION(page_memory_error)
      CASE_EXCEPTION(wasm_execution_error)
      CASE_EXCEPTION(wasm_serialization_error)
      CASE_EXCEPTION(overlapping_memory_error)
      CASE_EXCEPTION(binaryen_exception)
      CASE_EXCEPTION(resource_exhausted_exception)
      CASE_EXCEPTION(ram_usage_exceeded)
      CASE_EXCEPTION(tx_net_usage_exceeded)
      CASE_EXCEPTION(block_net_usage_exceeded)
      CASE_EXCEPTION(tx_cpu_usage_exceeded)
      CASE_EXCEPTION(block_cpu_usage_exceeded)
      CASE_EXCEPTION(deadline_exception)
      CASE_EXCEPTION(greylist_net_usage_exceeded)
      CASE_EXCEPTION(greylist_cpu_usage_exceeded)
      CASE_EXCEPTION(leeway_deadline_exception)
      CASE_EXCEPTION(authorization_exception)
      CASE_EXCEPTION(tx_duplicate_sig)
      CASE_EXCEPTION(tx_irrelevant_sig)
      CASE_EXCEPTION(unsatisfied_authorization)
      CASE_EXCEPTION(missing_auth_exception)
      CASE_EXCEPTION(irrelevant_auth_exception)
      CASE_EXCEPTION(insufficient_delay_exception)
      CASE_EXCEPTION(invalid_permission)
      CASE_EXCEPTION(unlinkable_min_permission_action)
      CASE_EXCEPTION(invalid_parent_permission)
      CASE_EXCEPTION(misc_exception)
      CASE_EXCEPTION(rate_limiting_state_inconsistent)
      CASE_EXCEPTION(unknown_block_exception)
      CASE_EXCEPTION(unknown_transaction_exception)
      CASE_EXCEPTION(fixed_reversible_db_exception)
      CASE_EXCEPTION(extract_genesis_state_exception)
      CASE_EXCEPTION(subjective_block_production_exception)
      CASE_EXCEPTION(multiple_voter_info)
      CASE_EXCEPTION(unsupported_feature)
      CASE_EXCEPTION(node_management_success)
      CASE_EXCEPTION(plugin_exception)
      CASE_EXCEPTION(missing_chain_api_plugin_exception)
      CASE_EXCEPTION(missing_wallet_api_plugin_exception)
      CASE_EXCEPTION(missing_history_api_plugin_exception)
      CASE_EXCEPTION(missing_net_api_plugin_exception)
      CASE_EXCEPTION(missing_chain_plugin_exception)
      CASE_EXCEPTION(plugin_config_exception)
      CASE_EXCEPTION(wallet_exception)
      CASE_EXCEPTION(wallet_exist_exception)
      CASE_EXCEPTION(wallet_nonexistent_exception)
      CASE_EXCEPTION(wallet_locked_exception)
      CASE_EXCEPTION(wallet_missing_pub_key_exception)
      CASE_EXCEPTION(wallet_invalid_password_exception)
      CASE_EXCEPTION(wallet_not_available_exception)
      CASE_EXCEPTION(wallet_unlocked_exception)
      CASE_EXCEPTION(key_exist_exception)
      CASE_EXCEPTION(key_nonexistent_exception)
      CASE_EXCEPTION(unsupported_key_type_exception)
      CASE_EXCEPTION(invalid_lock_timeout_exception)
      CASE_EXCEPTION(secure_enclave_exception)
      CASE_EXCEPTION(whitelist_blacklist_exception)
      CASE_EXCEPTION(actor_whitelist_exception)
      CASE_EXCEPTION(actor_blacklist_exception)
      CASE_EXCEPTION(contract_whitelist_exception)
      CASE_EXCEPTION(contract_blacklist_exception)
      CASE_EXCEPTION(action_blacklist_exception)
      CASE_EXCEPTION(key_blacklist_exception)
      CASE_EXCEPTION(controller_emit_signal_exception)
      CASE_EXCEPTION(checkpoint_exception)
      CASE_EXCEPTION(abi_exception)
      CASE_EXCEPTION(abi_not_found_exception)
      CASE_EXCEPTION(invalid_ricardian_clause_exception)
      CASE_EXCEPTION(invalid_ricardian_action_exception)
      CASE_EXCEPTION(invalid_type_inside_abi)
      CASE_EXCEPTION(duplicate_abi_type_def_exception)
      CASE_EXCEPTION(duplicate_abi_struct_def_exception)
      CASE_EXCEPTION(duplicate_abi_action_def_exception)
      CASE_EXCEPTION(duplicate_abi_table_def_exception)
      CASE_EXCEPTION(duplicate_abi_err_msg_def_exception)
      CASE_EXCEPTION(abi_serialization_deadline_exception)
      CASE_EXCEPTION(abi_recursion_depth_exception)
      CASE_EXCEPTION(abi_circular_def_exception)
      CASE_EXCEPTION(unpack_exception)
      CASE_EXCEPTION(pack_exception)
      CASE_EXCEPTION(duplicate_abi_variant_def_exception)
      CASE_EXCEPTION(unsupported_abi_version_exception)
      CASE_EXCEPTION(contract_exception)
      CASE_EXCEPTION(invalid_table_payer)
      CASE_EXCEPTION(table_access_violation)
      CASE_EXCEPTION(invalid_table_iterator)
      CASE_EXCEPTION(table_not_in_cache)
      CASE_EXCEPTION(table_operation_not_permitted)
      CASE_EXCEPTION(invalid_contract_vm_type)
      CASE_EXCEPTION(invalid_contract_vm_version)
      CASE_EXCEPTION(set_exact_code)
      CASE_EXCEPTION(abi_file_not_found)
      CASE_EXCEPTION(producer_exception)
      CASE_EXCEPTION(producer_priv_key_not_found)
      CASE_EXCEPTION(missing_pending_block_state)
      CASE_EXCEPTION(producer_double_confirm)
      CASE_EXCEPTION(producer_schedule_exception)
      CASE_EXCEPTION(producer_not_in_schedule)
      CASE_EXCEPTION(reversible_blocks_exception)
      CASE_EXCEPTION(invalid_reversible_blocks_dir)
      CASE_EXCEPTION(reversible_blocks_backup_dir_exist)
      CASE_EXCEPTION(gap_in_reversible_blocks_db)
      CASE_EXCEPTION(block_log_exception)
      CASE_EXCEPTION(block_log_unsupported_version)
      CASE_EXCEPTION(block_log_append_fail)
      CASE_EXCEPTION(block_log_not_found)
      CASE_EXCEPTION(block_log_backup_dir_exist)
      CASE_EXCEPTION(http_exception)
      CASE_EXCEPTION(invalid_http_client_root_cert)
      CASE_EXCEPTION(invalid_http_response)
      CASE_EXCEPTION(resolved_to_multiple_ports)
      CASE_EXCEPTION(fail_to_resolve_host)
      CASE_EXCEPTION(http_request_fail)
      CASE_EXCEPTION(invalid_http_request)
      CASE_EXCEPTION(resource_limit_exception)
      CASE_EXCEPTION(mongo_db_exception)
      CASE_EXCEPTION(mongo_db_insert_fail)
      CASE_EXCEPTION(mongo_db_update_fail)
      CASE_EXCEPTION(contract_api_exception)
      CASE_EXCEPTION(crypto_api_exception)
      CASE_EXCEPTION(db_api_exception)
      CASE_EXCEPTION(arithmetic_exception)
//      CASE_EXCEPTION(abi_generation_exception)
      default:
         break;
   }
   throw exception( FC_LOG_MESSAGE( error, output.data() ) );
#undef   CASE_EXCEPTION
#undef   CASE_FC_EXCEPTION
}
