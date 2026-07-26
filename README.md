# GTAIV .Net Script Hook </> Fork by Priler

This is a forked version of ScriptHookDotNet by HazardX, which involves some of the code fixes by Tomasak (rain bug fix and support for CE).  
Rain bug specifically was rewritten and on top of that, it also fixes known memory leaks and other minor issues (such as fixing offsets for Ped.get_RelationshipGroup, etc).  
Packed with aCompleteEditionHook.asi by LMS.

Since IV-SDK-DotNet and other projects doesn't properly support CE, and older versions of SHDN contains issues, I've decided to try and make my own fork while also fixing some of the infamous bugs.  
Along the way I'll extend this fork with new offsets built-in, as well as tools to easily find them in future when GTA IV CE will be updated.


### **Supported game versions**

- GTA IV: 1.0.1.0 up to 1.0.7.0
- EFLC: 1.1.1.0 up to 1.1.2.0
- **GTA IV Complete Edition: 1.2.0.59**

Complete Edition additionally requires `aCompleteEditionHook.asi`
(in `lib/CompleteEditionHook/`).  
This fork of SHDN was made for CE, in the first place.


### **Building**

Required to compile the sourcecode:

- Visual Studio 2022 with the workloads
  "Desktop development with C++" and ".NET desktop development",
  plus the individual component "C++/CLI support for v143 build tools"
- Windows 10/11 SDK
- .NET Framework 4.8 targeting pack

Then just open `ScriptHookDotNet.sln` and build **Release | Win32**.

The build produces `bin\ScriptHookDotNet.asi` (the plugin) along with
`bin\ScriptHookDotNet.xml` (IntelliSense documentation for script authors).
Run `_release\_copy.bat` afterwards to assemble a complete release package in `_release\archive`.

No DirectX SDK installation is needed. The `d3dx9` headers and import
library the project uses are checked into `ScriptHookDotNet/dxsdk/`, and
the import library for Aru's Script Hook is checked in as
`ScriptHookDotNet/ScriptHook.lib`. Older revisions of this project instead required the DirectX SDK March 2008 to be installed and a `DXSDK_2008-03` environment variable pointing at it.
That is no longer the case.

See the included ScriptHookDotNet.readme.txt on how to actually run 
the Script Hook with the game.


### **Credits**

Original repo by Hazard (hazard_x@gmx.net / twitter.com/HazardX)
Some of the code edits was merged from Tomasak's fork.
Some things was inspired by ideas behind IV-SDK-DotNet project by ClonkAndre.

Based on and includes parts of the GTAIV C++ Script Hook
from Aru <oneforaru at gmail dot com>

Classes Vector2, Vector3, Vector4, Quaternion and Matrix based on
sourcecode from SlimDX (https://github.com/SlimDX/slimdx)


### **License**

The GTAIV .Net Script Hook sourcecode is published unter the MIT license. 
See LICENSE.txt for the complete license text.

When you release sourcecode from this project make sure that you keep 
the full, unaltered license text at the beginning of the files. When
you changed parts of the released sourcecode make sure to include a
notice right below the license text in the modified files that states
that you altered the sourcecode, to make clear that i am not the sole 
author of all of the file's contents anymore.

You are free to distribute compiled derivative works of this in binary
form in any way you see fit and without limitations. It would be nice,
though, to give credit to Hazard (hazard_x@gmx.net / twitter.com/HazardX)
as author of the original GTAIV .Net Script Hook.

See LICENSE-ScriptHook.txt for the license of the GTAIV C++ Script Hook,
and LICENSE-SlimDX.txt for the license of the SlimDX sourcecode.
