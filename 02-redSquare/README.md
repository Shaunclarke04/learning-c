COMPILE & LINK
------------
Modern Version: `cl app.c user32.lib gdi32.lib /link /SUBSYSTEM:WINDOWS`  
XP Version (MSVC 2008): `cl /D_Windows app.c user32.lib gdi32.lib /link /SUBSYSTEM:WINDOWS`
