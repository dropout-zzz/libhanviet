# libhangul
# Copyright 2021 Choe Hwanjin
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

cmake_minimum_required(VERSION 4.2.0)
project(hanviet LANGUAGES C VERSION 0.1.0)

option(BUILD_SHARED_LIBS
    "Enable/Disable shared library build."
    ON
)

include(GNUInstallDirs)

set(hanviet_PUBLIC_HEADERS
  hanviet.h)

add_library(hanviet
  ${hanviet_PUBLIC_HEADERS}
  hanviet.c)

target_compile_definitions(hanviet PRIVATE
  -DLIBHANVIET_DEFAULT_DIC=\"${CMAKE_INSTALL_FULL_DATADIR}/${CMAKE_PROJECT_NAME}/dict.txt\")

add_executable(hanviet_test
  test.c)
target_link_libraries(hanviet_test
  hanviet)

install(TARGETS hanviet
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)

install(FILES ${hanviet_PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
)

install(
    FILES
        dict.txt
    DESTINATION
        "${CMAKE_INSTALL_DATADIR}/${CMAKE_PROJECT_NAME}"
)

configure_file(
    libhanviet.pc.in
    "${CMAKE_CURRENT_BINARY_DIR}/libhanviet.pc"
    @ONLY
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/libhanviet.pc"
    DESTINATION
        "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
    COMPONENT
        dev
)

install(TARGETS hanviet_test)
