#pragma once

#include "SourceInterfaces.h"

#include "MirvCalcs.h"

#include <string>

class CMirvCam
{
public:
	enum Origin_e {
		O_Net,
		O_View
	};

	enum Angles_e {
		A_Net,
		A_View
	};

	void ApplySource(float & x, float & y, float & z, float & xRotation, float & yRotation, float & zRotation);

	void ApplyOffset(float & x, float & y, float & z, float & xRotation, float & yRotation, float & zRotation);

public:
	SOURCESDK::CSGO::CBaseHandle m_SourceHandle;
	Origin_e m_SourceOrigin = O_View;
	Angles_e m_SourceAngles = A_View;
	std::string m_SourceAttachment;

	void RebuildCalc(void);

	bool m_SourceUseX = true;
	bool m_SourceUseY = true;
	bool m_SourceUseZ = true;
	bool m_SourceUseXRotation = true;
	bool m_SourceUseYRotation = true;
	bool m_SourceUseZRotation = true;
	float m_OffsetForwad = 0;
	float m_OffsetLeft = 0;
	float m_OffsetUp = 0;
	float m_OffsetForwardRot = 0;
	float m_OffseLeftRot = 0;
	float m_OffsetUpRot = 0;

	~CMirvCam()
	{
		Source_set(0);
	}

	IMirvVecAngCalc * Source_get(void)
	{
		return m_Source;
	}

	void Source_set(IMirvVecAngCalc * value)
	{
		if (m_Source) m_Source->Release();
		m_Source = value;
		if (m_Source) m_Source->AddRef();
	}

private:
	IMirvVecAngCalc * m_Source = 0;

};

extern CMirvCam g_MirvCam;
