set(sayayinshell_SRCS
   main.cpp
   sayayinshell.cpp
 )

kde4_add_executable(sayayinshell ${sayayinshell_SRCS})

target_link_libraries(sayayinshell ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS})

########### install files ###############
install(TARGETS sayayinshell ${INSTALL_TARGETS_DEFAULT_ARGS} )
install( FILES sayayinshell.desktop  DESTINATION  ${XDG_APPS_INSTALL_DIR} )
install( FILES sayayinshell_shell.rc  DESTINATION  ${DATA_INSTALL_DIR}/sayayinshell )


#########################################################################
# KPART SECTION
#########################################################################
#kde_module_LTLIBRARIES = libsayayinshellpart.la
set(sayayinshell_PART_SRCS
   sayayinshell_part.cpp
 )

kde4_add_plugin(sayayinshellpart WITH_PREFIX ${sayayinshell_PART_SRCS})

target_link_libraries(sayayinshellpart ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS} )

install( FILES sayayinshell_part.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES sayayinshell_part.rc  DESTINATION  ${DATA_INSTALL_DIR}/sayayinshellpart )

install(TARGETS sayayinshellpart  DESTINATION ${PLUGIN_INSTALL_DIR} )
