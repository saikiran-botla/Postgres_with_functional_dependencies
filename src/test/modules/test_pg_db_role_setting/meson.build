# Copyright (c) 2022-2023, PostgreSQL Global Development Group

test_pg_db_role_setting_sources = files(
  'test_pg_db_role_setting.c',
)

if host_system == 'windows'
  test_pg_db_role_setting_sources += rc_lib_gen.process(win32ver_rc, extra_args: [
    '--NAME', 'test_pg_db_role_setting',
    '--FILEDESC', 'test_pg_db_role_setting - tests for default GUC values stored in pg_db_role_settings',])
endif

test_pg_db_role_setting = shared_module('test_pg_db_role_setting',
  test_pg_db_role_setting_sources,
  kwargs: pg_test_mod_args,
)
test_install_libs += test_pg_db_role_setting

test_install_data += files(
  'test_pg_db_role_setting.control',
  'test_pg_db_role_setting--1.0.sql',
)

tests += {
  'name': 'test_pg_db_role_setting',
  'sd': meson.current_source_dir(),
  'bd': meson.current_build_dir(),
  'regress': {
    'sql': [
      'test_pg_db_role_setting',
    ],
    'runningcheck': false,
  },
}
