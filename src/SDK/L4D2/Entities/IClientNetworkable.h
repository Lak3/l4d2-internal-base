#pragma once

#include "IClientRenderable.h"

enum ShouldTransmitState_t {
	SHOULDTRANSMIT_START = 0,
	SHOULDTRANSMIT_END
};

enum DataUpdateType_t {
	DATA_UPDATE_CREATED = 0,
	DATA_UPDATE_DATATABLE_CHANGED
};

class IClientNetworkable
{
public:
	virtual void				Release() = 0;
	virtual ClientClass*		GetClientClass() = 0;
	virtual void				NotifyShouldTransmit(ShouldTransmitState_t state) = 0;
	virtual void				OnPreDataChanged(DataUpdateType_t updateType) = 0;
	virtual void				OnDataChanged(DataUpdateType_t updateType) = 0;
	virtual void				PreDataUpdate(DataUpdateType_t updateType) = 0;
	virtual void				PostDataUpdate(DataUpdateType_t updateType) = 0;
	virtual bool				IsDormant(void) const = 0;
	virtual int					entindex(void) const = 0;
	virtual void				ReceiveMessage(int classID, void* msg) = 0;
	virtual void*				GetDataTableBasePtr() = 0;
	virtual void				SetDestroyedOnRecreateEntities(void) = 0;
};