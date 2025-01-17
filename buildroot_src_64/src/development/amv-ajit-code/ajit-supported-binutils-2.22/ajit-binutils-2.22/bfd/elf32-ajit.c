/* AJIT-specific support for 32-bit ELF
   Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
   2003, 2004, 2005, 2006, 2007, 2010, 2011
   Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/ajit.h"
#include "opcode/ajit.h"
#include "elfxx-ajit.h"
#include "elf-vxworks.h"

/* Support for core dump NOTE sections.  */

static bfd_boolean
elf32_ajit_grok_psinfo (bfd *abfd, Elf_Internal_Note *note)
{
  switch (note->descsz)
    {
    default:
      return FALSE;

    case 260:			/* Solaris prpsinfo_t.  */
      elf_tdata (abfd)->core_program
	= _bfd_elfcore_strndup (abfd, note->descdata + 84, 16);
      elf_tdata (abfd)->core_command
	= _bfd_elfcore_strndup (abfd, note->descdata + 100, 80);
      break;

    case 336:			/* Solaris psinfo_t.  */
      elf_tdata (abfd)->core_program
	= _bfd_elfcore_strndup (abfd, note->descdata + 88, 16);
      elf_tdata (abfd)->core_command
	= _bfd_elfcore_strndup (abfd, note->descdata + 104, 80);
      break;
    }

  return TRUE;
}

/* Functions for dealing with the e_flags field.

   We don't define set_private_flags or copy_private_bfd_data because
   the only currently defined values are based on the bfd mach number,
   so we use the latter instead and defer setting e_flags until the
   file is written out.  */

/* Merge backend specific data from an object file to the output
   object file when linking.  */

static bfd_boolean
elf32_ajit_merge_private_bfd_data (bfd *ibfd, bfd *obfd)
{
  bfd_boolean error;
  unsigned long ibfd_mach;
  /* FIXME: This should not be static.  */
  static unsigned long previous_ibfd_e_flags = (unsigned long) -1;

  if (bfd_get_flavour (ibfd) != bfd_target_elf_flavour
      || bfd_get_flavour (obfd) != bfd_target_elf_flavour)
    return TRUE;

  error = FALSE;

  ibfd_mach = bfd_get_mach (ibfd);
  if (bfd_mach_ajit_64bit_p (ibfd_mach))
    {
      error = TRUE;
      (*_bfd_error_handler)
	(_("%B: compiled for a 64 bit system and target is 32 bit"), ibfd);
    }
  else if ((ibfd->flags & DYNAMIC) == 0)
    {
      if (bfd_get_mach (obfd) < ibfd_mach)
	bfd_set_arch_mach (obfd, bfd_arch_ajit, ibfd_mach);
    }

  if (((elf_elfheader (ibfd)->e_flags & EF_AJIT_LEDATA)
       != previous_ibfd_e_flags)
      && previous_ibfd_e_flags != (unsigned long) -1)
    {
      (*_bfd_error_handler)
	(_("%B: linking little endian files with big endian files"), ibfd);
      error = TRUE;
    }
  previous_ibfd_e_flags = elf_elfheader (ibfd)->e_flags & EF_AJIT_LEDATA;

  if (error)
    {
      bfd_set_error (bfd_error_bad_value);
      return FALSE;
    }

  return _bfd_ajit_elf_merge_private_bfd_data (ibfd, obfd);
}

/* The final processing done just before writing out the object file.
   We need to set the e_machine field appropriately.  */

static void
elf32_ajit_final_write_processing (bfd *abfd,
				    bfd_boolean linker ATTRIBUTE_UNUSED)
{
  switch (bfd_get_mach (abfd))
    {
    case bfd_mach_ajit :
    /* case bfd_mach_ajit_ajitlet : */
    /* case bfd_mach_ajit_ajitlite : */
      break; /* nothing to do */
    /* case bfd_mach_ajit_v8plus : */
    /*   elf_elfheader (abfd)->e_machine = EM_AJIT32PLUS; */
    /*   elf_elfheader (abfd)->e_flags &=~ EF_AJIT_32PLUS_MASK; */
    /*   elf_elfheader (abfd)->e_flags |= EF_AJIT_32PLUS; */
    /*   break; */
    /* case bfd_mach_ajit_v8plusa : */
    /*   elf_elfheader (abfd)->e_machine = EM_AJIT32PLUS; */
    /*   elf_elfheader (abfd)->e_flags &=~ EF_AJIT_32PLUS_MASK; */
    /*   elf_elfheader (abfd)->e_flags |= EF_AJIT_32PLUS | EF_AJIT_SUN_US1; */
    /*   break; */
    /* case bfd_mach_ajit_v8plusb : */
    /*   elf_elfheader (abfd)->e_machine = EM_AJIT32PLUS; */
    /*   elf_elfheader (abfd)->e_flags &=~ EF_AJIT_32PLUS_MASK; */
    /*   elf_elfheader (abfd)->e_flags |= EF_AJIT_32PLUS | EF_AJIT_SUN_US1 */
    /* 				       | EF_AJIT_SUN_US3; */
    /*   break; */
    /* case bfd_mach_ajit_ajitlite_le : */
    /*   elf_elfheader (abfd)->e_flags |= EF_AJIT_LEDATA; */
    /*   break; */
    default :
      abort ();
      break;
    }
}

static enum elf_reloc_type_class
elf32_ajit_reloc_type_class (const Elf_Internal_Rela *rela)
{
  switch ((int) ELF32_R_TYPE (rela->r_info))
    {
    case R_AJIT_RELATIVE:
      return reloc_class_relative;
    case R_AJIT_JMP_SLOT:
      return reloc_class_plt;
    case R_AJIT_COPY:
      return reloc_class_copy;
    default:
      return reloc_class_normal;
    }
}

/* Hook called by the linker routine which adds symbols from an object
   file.  */

static bfd_boolean
elf32_ajit_add_symbol_hook (bfd * abfd,
			     struct bfd_link_info * info ATTRIBUTE_UNUSED,
			     Elf_Internal_Sym * sym,
			     const char ** namep ATTRIBUTE_UNUSED,
			     flagword * flagsp ATTRIBUTE_UNUSED,
			     asection ** secp ATTRIBUTE_UNUSED,
			     bfd_vma * valp ATTRIBUTE_UNUSED)
{
  if ((abfd->flags & DYNAMIC) == 0
      && (ELF_ST_TYPE (sym->st_info) == STT_GNU_IFUNC
	  || ELF_ST_BIND (sym->st_info) == STB_GNU_UNIQUE))
    elf_tdata (info->output_bfd)->has_gnu_symbols = TRUE;
  return TRUE;
}

#define TARGET_BIG_SYM	bfd_elf32_ajit_vec
#define TARGET_BIG_NAME	"elf32-ajit"
#define ELF_ARCH	bfd_arch_ajit
#define ELF_TARGET_ID	AJIT_ELF_DATA
#define ELF_MACHINE_CODE EM_AJIT
/* #define ELF_MACHINE_ALT1 EM_AJIT32PLUS */
#define ELF_MAXPAGESIZE 0x10000
#define ELF_COMMONPAGESIZE 0x2000

#define bfd_elf32_bfd_merge_private_bfd_data \
					elf32_ajit_merge_private_bfd_data
#define elf_backend_final_write_processing \
					elf32_ajit_final_write_processing
#define elf_backend_grok_psinfo		elf32_ajit_grok_psinfo
#define elf_backend_reloc_type_class	elf32_ajit_reloc_type_class

#define elf_info_to_howto		_bfd_ajit_elf_info_to_howto
#define bfd_elf32_bfd_reloc_type_lookup	_bfd_ajit_elf_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup \
  _bfd_ajit_elf_reloc_name_lookup
#define bfd_elf32_bfd_link_hash_table_create \
					_bfd_ajit_elf_link_hash_table_create
#define bfd_elf32_bfd_link_hash_table_free \
					_bfd_ajit_elf_link_hash_table_free
#define bfd_elf32_bfd_relax_section	_bfd_ajit_elf_relax_section
#define bfd_elf32_new_section_hook	_bfd_ajit_elf_new_section_hook
#define elf_backend_copy_indirect_symbol \
					_bfd_ajit_elf_copy_indirect_symbol
#define elf_backend_create_dynamic_sections \
					_bfd_ajit_elf_create_dynamic_sections
#define elf_backend_check_relocs	_bfd_ajit_elf_check_relocs
#define elf_backend_adjust_dynamic_symbol \
					_bfd_ajit_elf_adjust_dynamic_symbol
#define elf_backend_omit_section_dynsym	_bfd_ajit_elf_omit_section_dynsym
#define elf_backend_size_dynamic_sections \
					_bfd_ajit_elf_size_dynamic_sections
#define elf_backend_relocate_section	_bfd_ajit_elf_relocate_section
#define elf_backend_finish_dynamic_symbol \
					_bfd_ajit_elf_finish_dynamic_symbol
#define elf_backend_finish_dynamic_sections \
					_bfd_ajit_elf_finish_dynamic_sections
#define bfd_elf32_mkobject		_bfd_ajit_elf_mkobject
#define elf_backend_object_p		_bfd_ajit_elf_object_p
#define elf_backend_gc_mark_hook	_bfd_ajit_elf_gc_mark_hook
#define elf_backend_gc_sweep_hook       _bfd_ajit_elf_gc_sweep_hook
#define elf_backend_plt_sym_val		_bfd_ajit_elf_plt_sym_val
#define elf_backend_init_index_section	_bfd_elf_init_1_index_section

#define elf_backend_can_gc_sections 1
#define elf_backend_can_refcount 1
#define elf_backend_want_got_plt 0
#define elf_backend_plt_readonly 0
#define elf_backend_want_plt_sym 1
#define elf_backend_got_header_size 4
#define elf_backend_rela_normal 1

#define elf_backend_post_process_headers	_bfd_elf_set_osabi
#define elf_backend_add_symbol_hook		elf32_ajit_add_symbol_hook

#include "elf32-target.h"

/* Solaris 2.  */

#undef	TARGET_BIG_SYM
#define	TARGET_BIG_SYM				bfd_elf32_ajit_sol2_vec
#undef	TARGET_BIG_NAME
#define	TARGET_BIG_NAME				"elf32-ajit-sol2"

#undef elf32_bed
#define elf32_bed				elf32_ajit_sol2_bed

/* The 32-bit static TLS arena size is rounded to the nearest 8-byte
   boundary.  */
#undef elf_backend_static_tls_alignment
#define elf_backend_static_tls_alignment	8

#include "elf32-target.h"

/* A wrapper around _bfd_ajit_elf_link_hash_table_create that identifies
   the target system as VxWorks.  */

static struct bfd_link_hash_table *
elf32_ajit_vxworks_link_hash_table_create (bfd *abfd)
{
  struct bfd_link_hash_table *ret;

  ret = _bfd_ajit_elf_link_hash_table_create (abfd);
  if (ret)
    {
      struct _bfd_ajit_elf_link_hash_table *htab;

      htab = (struct _bfd_ajit_elf_link_hash_table *) ret;
      htab->is_vxworks = 1;
    }
  return ret;
}

/* A final_write_processing hook that does both the AJIT- and VxWorks-
   specific handling.  */

static void
elf32_ajit_vxworks_final_write_processing (bfd *abfd, bfd_boolean linker)
{
  elf32_ajit_final_write_processing (abfd, linker);
  elf_vxworks_final_write_processing (abfd, linker);
}

#undef TARGET_BIG_SYM
#define TARGET_BIG_SYM	bfd_elf32_ajit_vxworks_vec
#undef TARGET_BIG_NAME
#define TARGET_BIG_NAME	"elf32-ajit-vxworks"

#undef ELF_MINPAGESIZE
#define ELF_MINPAGESIZE	0x1000

#undef bfd_elf32_bfd_link_hash_table_create
#define bfd_elf32_bfd_link_hash_table_create \
  elf32_ajit_vxworks_link_hash_table_create

#undef elf_backend_want_got_plt
#define elf_backend_want_got_plt		1
#undef elf_backend_plt_readonly
#define elf_backend_plt_readonly		1
#undef elf_backend_got_header_size
#define elf_backend_got_header_size		12
#undef elf_backend_add_symbol_hook
#define elf_backend_add_symbol_hook \
  elf_vxworks_add_symbol_hook
#undef elf_backend_link_output_symbol_hook
#define elf_backend_link_output_symbol_hook \
  elf_vxworks_link_output_symbol_hook
#undef elf_backend_emit_relocs
#define elf_backend_emit_relocs \
  elf_vxworks_emit_relocs
#undef elf_backend_final_write_processing
#define elf_backend_final_write_processing \
  elf32_ajit_vxworks_final_write_processing
#undef elf_backend_static_tls_alignment

#undef elf32_bed
#define elf32_bed				ajit_elf_vxworks_bed

#include "elf32-target.h"
