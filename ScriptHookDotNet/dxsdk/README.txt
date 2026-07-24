DirectX SDK (March 2008) - d3dx9 subset
Copyright (C) Microsoft Corporation.

Checked in so that ScriptHookDotNet builds without a machine-wide DirectX SDK
installation. Upstream instead required the SDK to be installed and a
"DXSDK_2008-03" environment variable to point at it.

Redistributed under the terms of the DirectX SDK EULA that accompanied the
March 2008 SDK release.

Only the d3dx9 subset that ScriptHookDotNet actually uses is included. At
runtime this creates a dependency on d3dx9_43.dll, which ships with the DirectX
End-User Runtime and is present on any machine that can run GTA IV.
