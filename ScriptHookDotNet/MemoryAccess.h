/*
* Copyright (c) 2009-2011 Hazard (hazard_x@gmx.net / twitter.com/HazardX)
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#pragma once
#pragma managed

namespace GTA {
	value class Vector3;
}

namespace unmanaged {

	using namespace System;
	using namespace System::Collections::Generic;

	private ref class MemoryAccess {
	private:
		MemoryAccess(){}

		static String^ GobalsError = "Accessing Globals failed! Invalid Memory Address!";

		static u32 ADDRESS_BLIPLIST = 0;
		static u32 ADDRESS_OBJECTPOOL = 0;
		static u32 ADDRESS_PEDPOOL = 0;
		static u32 ADDRESS_VEHICLEPOOL = 0;
		// CShadows::AddSceneLight
		// @TODO: Left at 0 on every version whose address has not been verified against a real exe - callers must check hasSceneLights() first
		static u32 ADDRESS_ADDSCENELIGHT = 0;

		// Offset for Ped.get_RelationshipGroup
		static u32 OFFSET_PED_RELATIONSHIPGROUP = 0xBB4;

		//static u32 ADDRESS_GETDIRECT3DDEVICE9 = 0; //GetDirect3DDevice9
		//static u32 ADDRESS_GLOBALLIST = 0;
		//static u32 ADDRESS_PHONENUMBER = 0;
		//static u32 ADDRESS_PLAYERLIST = 0;

	public:

		// IMPORTANT: EASY way to get the adresses! Run "FunctionAddressScript" or get adresses of object script function manually (subtract baseAddress).
		// Then open IDA Pro and jump to the adresses. Enter the inner function (usually first and only CALL).
		// In the inner function, first call usually takes the index and THE POOL ADDRESS)
		// funcs: GET_CAR_HEALTH, GET_CHAR_HEALTH, SET_OBJECT_VISIBLE, GET_BLIP_COLOUR

		static void Init(u32 BaseAddress, GTA::GameVersion Version) {
			OFFSET_PED_RELATIONSHIPGROUP = 0xBB4;

			switch (Version) {
				case GTA::GameVersion::v1000:
					ADDRESS_BLIPLIST			= BaseAddress + 0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0;
					ADDRESS_PEDPOOL				= BaseAddress + 0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x013DE9D0;	// itemsize 8400(0x20D0), count 140(0x8C)
					break;
				case GTA::GameVersion::v1010:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FB1AF0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011E73E8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x016EB9A0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011E1540;
					//ADDRESS_GETDIRECT3DDEVICE9	= BaseAddress + 0x0156F56C;
					//ADDRESS_GLOBALLIST			= BaseAddress + 0x015B5A88;
					//ADDRESS_PHONENUMBER			= BaseAddress + 0x0142D7D0;
					//ADDRESS_PLAYERLIST			= BaseAddress + 0x01064808;
					break;
				case GTA::GameVersion::v1020:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FAB470;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011D13C8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x016E37E0;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011CB520;
					//ADDRESS_GETDIRECT3DDEVICE9	= BaseAddress + 0x0155F750;
					//ADDRESS_GLOBALLIST			= BaseAddress + 0x015AD8B4;
					//ADDRESS_PHONENUMBER			= BaseAddress + 0x0141E1D0;
					//ADDRESS_PLAYERLIST			= BaseAddress + 0x01009798;
					break;
				case GTA::GameVersion::v1030:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FCA9D0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011F5B38;
					ADDRESS_PEDPOOL				= BaseAddress + 0x017564D8;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011EFC90;
					break;
				case GTA::GameVersion::v1040:
					ADDRESS_BLIPLIST			= BaseAddress + 0x00FCFC70;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x011FADD8;
					ADDRESS_PEDPOOL				= BaseAddress + 0x0175B77C;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x011F4F30;
					break;
				case GTA::GameVersion::v1050:
					ADDRESS_BLIPLIST			= BaseAddress + 0x010D3AF0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x010EBD08;
					ADDRESS_PEDPOOL				= BaseAddress + 0x017DFCA8;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x010E8BD0;
					break;
				case GTA::GameVersion::v1060:
					ADDRESS_BLIPLIST			= BaseAddress + 0x119DD50;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x134FD00;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A72BC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1618260;
					break;
				case GTA::GameVersion::v1070:
					ADDRESS_BLIPLIST			= BaseAddress + 0x119ED50;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x1350CE0;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A82AC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1619240;
					break;
				case GTA::GameVersion::v1110:
					ADDRESS_BLIPLIST			= BaseAddress + 0x1122E20;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x1471440;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18A3080;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x1621C10;
					break;
				case GTA::GameVersion::v1120:
					ADDRESS_BLIPLIST			= BaseAddress + 0x10C3EA0;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x118A660;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18219EC;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x15C17B0;
					break;
				case GTA::GameVersion::v1259:
					// Complete Edition.
					// Verified against GTAIV.exe 1.2.0.59:
					// BLIPLIST is a table base   -> mov eax,[eax*4+0x118F6F8]
					// the three pools are single -> mov reg,[addr] pointer loads
					//
					// VEHICLEPOOL and BLIPLIST were independently confirmed against the
					// auto-generated 12059.ini from https://github.com/Kev7cks/IV-SDK-DotNet
					// That file stores the RVA of the 4-byte operand field of an instruction referencing the
					// global, not the global itself, so its values need one extra step:
					//
					//   [CPools] ms_pVehiclePool = 0x5DC2E5 -> operand reads 0x012E22A4
					//   [CRadar] RadarTrace      = 0x50429A -> operand reads 0x0118F6F8
					//
					// PEDPOOL and OBJECTPOOL cannot be cross-checked that way: the entries
					// for them (0xEE24C, 0xA9D72) sit inside the encrypted part of .text
					// (RVA 0x1000-0x101000, entropy 8.00), which only exists decrypted at
					// runtime. Those two still rest on the xref scan of the exe alone.
					ADDRESS_BLIPLIST			= BaseAddress + 0x118F6F8;
					ADDRESS_OBJECTPOOL			= BaseAddress + 0x1632C60;
					ADDRESS_PEDPOOL				= BaseAddress + 0x18B6F1C;
					ADDRESS_VEHICLEPOOL			= BaseAddress + 0x12E22A4;

					// CShadows::AddSceneLight. RVA 0x6BCCD0 from the same 12059.ini, checked
					// directly in GTAIV.exe 1.2.0.59 - it lands on a real function prologue
					// (55 8B EC 83 E4 F0 = push ebp / mov ebp,esp / and esp,~0xF), so unlike
					// the data entries above this one needs no decoding.
					// +0x400000 converts the RVA to the VA form the rest of this table uses.
					// The equivalents for 1.0.7.0 (0x4C59F0) and 1.0.8.0 (0x62DF00) are known
					// from IV-SDK .NET but have not been checked (@TODO).
					ADDRESS_ADDSCENELIGHT		= BaseAddress + 0xABCCD0;

					// CPed shrank by 0x10 ahead of this field on Complete Edition
					OFFSET_PED_RELATIONSHIPGROUP = 0xBA4;
					break;
			}
		}

		/// <summary>
		/// Whether this game version has a known CShadows::AddSceneLight address.
		/// </summary>
		static bool hasSceneLights() {
			return (ADDRESS_ADDSCENELIGHT != 0);
		}

		/// <summary>
		/// Queues one light into the scene light list for this frame.
		/// </summary>
		static void AddSceneLight(
			u32 LightType, u32 Flags,
			float DirX, float DirY, float DirZ,
			float TanDirX, float TanDirY, float TanDirZ,
			float PosX, float PosY, float PosZ,
			float ColR, float ColG, float ColB,
			float Intensity, int TexHash, int TxdSlot, float Range,
			float InnerConeAngle, float OuterConeAngle,
			float VolIntensity, float VolSizeScale,
			int InteriorId, u32 ID);

		static int GetGlobalAddress(int index);
		static int GetGlobalInteger(int index);
		static float GetGlobalFloat(int index);
		static String^ GetGlobalString(int index);
		static void SetGlobal(int index, int value);
		static void SetGlobal(int index, float value);
		static void SetGlobal(int index, String^ value);

		static int HandleToIndex(int Handle) {
			return Handle >> 8;
		}
		static int GetAddressOfItemInPool(int PoolAddress, int Handle);
		static int GetAddressOfItemInPoolByIndex(int PoolAddress, int Index);
		static array<int>^ GetListOfHandlesInPool(int PoolAddress);

		static u32 GetPedRelationshipGroupOffset() {
			return OFFSET_PED_RELATIONSHIPGROUP;
		}

		static int GetAddressOfPed(int Handle);
		static int GetAddressOfVehicle(int Handle);
		static int GetAddressOfObject(int Handle);
		static int GetAddressOfBlip(int Handle);

		static array<int>^ GetPedHandleList();
		static array<int>^ GetVehicleHandleList();
		static array<int>^ GetObjectHandleList();
		static array<int>^ GetBlipHandleList();

		static float GetVehicleRPM(int Handle);
		static GTA::Vector3 GetPositionOfVehicle(int Handle);

		static GTA::Vector3 GetPositionOfBlip(int Handle);

		static String^ GetPhoneNumber();

		//static System::IntPtr GetDirect3DDevice9();

	};
}