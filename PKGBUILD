pkgname=libhanviet-git
pkgver=0.1.0
pkgrel=1
pkgdesc='sino-Vietnamese dictionary for keyboards'
url='https://github.com/dropout-zzz/libhanviet'
arch=('x86_64')
license=('LGPL')
makedepends=(git
             cmake)
conflicts=(libhanviet)
provides=(libhanviet)
source=(CMakeLists.txt
        dict.txt
        hanviet.c
        hanviet.h
        libhanviet.pc.in
        test.c)
sha512sums=(SKIP
            SKIP
            SKIP
            SKIP
            SKIP
            SKIP)

pkgver() {
  ( set -o pipefail
    git describe --long --abbrev=7 2>/dev/null | sed 's/\([^-]*-g\)/r\1/;s/-/./g' ||
    printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short=7 HEAD)"
  )
}

build() {
  cmake -S . -DCMAKE_BUILD_TYPE=None \
             -DCMAKE_INSTALL_PREFIX=/usr \
             -DBUILD_SHARED_LIBS=ON
  make
}

package() {
  DESTDIR="$pkgdir" make install
}
