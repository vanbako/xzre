add_library(xzre_code
	backdoor_entry.c
	chacha_decrypt.c
	elf_parse.c
	elf_symbol_get_addr.c
	get_lzma_allocator.c
	is_endbr64_instruction.c
	fake_lzma_alloc.c
	fake_lzma_free.c
	main_elf_parse.c
	run_backdoor_commands.c
	secret_data_append_from_address.c
	secret_data_append_item.c
	secret_data_append_singleton.c
	secret_data_get_decrypted.c
	sha256.c
	sshd_patch_variables.c
)
target_compile_options(xzre_code PRIVATE
	-Os -fomit-frame-pointer
)

add_custom_command(
	OUTPUT ${CMAKE_BINARY_DIR}/xzre_merged.o
	DEPENDS $<TARGET_OBJECTS:xzre_code>
	COMMAND ${CMAKE_LINKER}
		-relocatable $<TARGET_OBJECTS:xzre_code>
		-o ${CMAKE_BINARY_DIR}/xzre_merged.o
	COMMAND_EXPAND_LISTS
	VERBATIM
)

add_custom_target(make_object_file ALL
	DEPENDS ${CMAKE_BINARY_DIR}/xzre_merged.o
)
add_dependencies(make_object_file xzre_code)
