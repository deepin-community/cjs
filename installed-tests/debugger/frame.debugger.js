// SPDX-License-Identifier: MIT OR LGPL-2.0-or-later
// SPDX-FileCopyrightText: 2018 Philip Chimento <philip.chimento@gmail.com>
function a() {
    b();
}

function b() {
    debugger;
}

a();
