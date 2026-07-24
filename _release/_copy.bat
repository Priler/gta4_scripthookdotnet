@ECHO OFF

REM **                                                                              **
REM ** Collects all files required for a release package in the "archive" subfolder **
REM **                                                                              **

mkdir .\archive 2>nul
mkdir ".\archive\scripts\for Developers\bin" 2>nul

copy ..\ScriptHookDotNet.readme.txt .\archive\
REM The Release build already produces the .asi directly (see TargetExt in the vcxproj).
copy ..\bin\ScriptHookDotNet.asi .\archive\ScriptHookDotNet.asi
REM Same assembly, but script projects have to reference it as a .dll.
copy ..\bin\ScriptHookDotNet.asi ".\archive\scripts\for Developers\bin\ScriptHookDotNet.dll"
copy ..\bin\ScriptHookDotNet.xml ".\archive\scripts\for Developers\bin\ScriptHookDotNet.xml"
copy "..\lib\ScriptHook_for_1.0.6.0+\ScriptHook.dll" .\archive\ScriptHook.dll
REM Required on GTA IV Complete Edition (1.2.0.59), harmless on older versions.
copy "..\lib\CompleteEditionHook\aCompleteEditionHook.asi" .\archive\aCompleteEditionHook.asi
copy ..\LICENSE.txt .\archive\
copy ..\LICENSE-ScriptHook.txt .\archive\
copy ..\LICENSE-SlimDX.txt .\archive\
copy .\scriptsMessage.txt ".\archive\scripts\_PUT .NET SCRIPTS HERE"

xcopy /S /Y .\PlainScripts\*.* ".\archive\scripts\for Developers\PlainScripts\"

xcopy /S /Y ..\TestScriptVB\*.* ".\archive\scripts\for Developers\TestScriptVB\"
del /AH ".\archive\scripts\for Developers\TestScriptVB\TestScriptVB.suo" 2>nul
del ".\archive\scripts\for Developers\TestScriptVB\TestScriptVB.vbproj.user" 2>nul
del /Q ".\archive\scripts\for Developers\TestScriptVB\bin\*" 2>nul
rmdir /S /Q ".\archive\scripts\for Developers\TestScriptVB\obj" 2>nul
REM bin\ is not in source control, so it has to be created before the copy below
mkdir ".\archive\scripts\for Developers\TestScriptVB\bin" 2>nul
copy .\postbuildVB.bat ".\archive\scripts\for Developers\TestScriptVB\bin\_postbuild.bat"

xcopy /S /Y ..\TestScriptCS\*.* ".\archive\scripts\for Developers\TestScriptCS\"
del ".\archive\scripts\for Developers\TestScriptCS\TestScriptCS.suo" 2>nul
del ".\archive\scripts\for Developers\TestScriptCS\TestScriptCS.csproj.user" 2>nul
del /Q ".\archive\scripts\for Developers\TestScriptCS\bin\*" 2>nul
rmdir /S /Q ".\archive\scripts\for Developers\TestScriptCS\obj" 2>nul
REM bin\ is not in source control, so it has to be created before the copy below
mkdir ".\archive\scripts\for Developers\TestScriptCS\bin" 2>nul
copy .\postbuildCS.bat ".\archive\scripts\for Developers\TestScriptCS\bin\_postbuild.bat"

pause