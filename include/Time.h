#pragma once


class
{
	int     m_total         = 0;
	double  m_secsPerFrame  = 0.;
	int     m_fpsWanted     = 60;
	int     m_fpsReal       = 0;
public:
	const int    &  total         = m_total;
	const double &  secsPerFrame  = m_secsPerFrame;
	unsigned  int    &  m_fpsWanted = m_fpsWanted;
	const int    &  fpsReal       = m_fpsReal;

}time;