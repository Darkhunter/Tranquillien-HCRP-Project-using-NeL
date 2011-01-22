/*
    Object Viewer Qt
    Copyright (C) 2010 Dzmitry Kamiahin <dnk-88@tut.by>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "stdpch.h"
#include "direction_widget.h"

// Qt includes
#include <QtGui/QInputDialog>

// NeL includes
#include <nel/misc/vector.h>
#include <nel/3d/particle_system.h>

namespace NLQT {

CDirectionWidget::CDirectionWidget(QWidget *parent)
    : QWidget(parent), _Wrapper(NULL), _DirectionWrapper(NULL)
{
	_ui.setupUi(this);
	
	_ui.xzWidget->setMode(Mode::Direction);
	_ui.yzWidget->setMode(Mode::Direction);
	_ui.xzWidget->setText("XZ");
	_ui.yzWidget->setText("YZ");
	_ui.globalPushButton->hide();
	
	connect(_ui.globalPushButton ,SIGNAL(clicked()), this, SLOT(setGlobalDirection()));
	connect(_ui.incVecIPushButton ,SIGNAL(clicked()), this, SLOT(incVecI()));
	connect(_ui.incVecJPushButton ,SIGNAL(clicked()), this, SLOT(incVecJ()));
	connect(_ui.incVecKPushButton ,SIGNAL(clicked()), this, SLOT(incVecK()));
	connect(_ui.decVecIPushButton ,SIGNAL(clicked()), this, SLOT(decVecI()));
	connect(_ui.decVecJPushButton ,SIGNAL(clicked()), this, SLOT(decVecJ()));
	connect(_ui.decVecKPushButton ,SIGNAL(clicked()), this, SLOT(decVecK()));
	
	connect(_ui.xzWidget, SIGNAL(applyNewVector(float,float)), this, SLOT(setNewVecXZ(float,float)));
	connect(_ui.yzWidget, SIGNAL(applyNewVector(float,float)), this, SLOT(setNewVecYZ(float,float)));
}

CDirectionWidget::~CDirectionWidget()
{
}


void CDirectionWidget::setWrapper(IPSWrapper<NLMISC::CVector> *wrapper) 
{ 
	_Wrapper = wrapper;
	_ui.globalPushButton->hide();
}

void CDirectionWidget::setDirectionWrapper(NL3D::CPSDirection *wrapper) 
{ 
	_DirectionWrapper = wrapper;
	if (_DirectionWrapper && _DirectionWrapper->supportGlobalVectorValue())
		_ui.globalPushButton->show();
	else 
		_ui.globalPushButton->hide();
}

void CDirectionWidget::updateUi()
{
	_ui.xzWidget->setVector(_Wrapper->get().x, _Wrapper->get().z);
	_ui.yzWidget->setVector(_Wrapper->get().y, _Wrapper->get().z);
	_ui.xzWidget->repaint();
	_ui.yzWidget->repaint();
	
	checkEnabledGlobalDirection();
}

void CDirectionWidget::setGlobalDirection()
{
	nlassert(_DirectionWrapper);
	
	bool ok;
	QString text = QInputDialog::getText(this, tr("Enter Name"),
					      "", QLineEdit::Normal,
					      QString(_DirectionWrapper->getGlobalVectorValueName().c_str()), &ok);
     
	if (ok)   
	{
		_DirectionWrapper->enableGlobalVectorValue(text.toStdString());
		if (!text.isEmpty())
		{
			// take a non NULL value for the direction
			NL3D::CParticleSystem::setGlobalVectorValue(text.toStdString(), NLMISC::CVector::I);
		}
		checkEnabledGlobalDirection();
	}
}

void CDirectionWidget::incVecI()
{
	_Wrapper->setAndUpdateModifiedFlag(NLMISC::CVector::I);
	_ui.xzWidget->setVector(NLMISC::CVector::I.x, NLMISC::CVector::I.z);
	_ui.yzWidget->setVector(NLMISC::CVector::I.y, NLMISC::CVector::I.z);
}

void CDirectionWidget::incVecJ()
{
	_Wrapper->setAndUpdateModifiedFlag(NLMISC::CVector::J);
	_ui.xzWidget->setVector(NLMISC::CVector::J.x, NLMISC::CVector::J.z);
	_ui.yzWidget->setVector(NLMISC::CVector::J.y, NLMISC::CVector::J.z);
}

void CDirectionWidget::incVecK()
{
	_Wrapper->setAndUpdateModifiedFlag(NLMISC::CVector::K);
	_ui.xzWidget->setVector(NLMISC::CVector::K.x, NLMISC::CVector::K.z);
	_ui.yzWidget->setVector(NLMISC::CVector::K.y, NLMISC::CVector::K.z);
}

void CDirectionWidget::decVecI()
{
	_Wrapper->setAndUpdateModifiedFlag( - NLMISC::CVector::I);
	_ui.xzWidget->setVector((-NLMISC::CVector::I).x, (-NLMISC::CVector::I).z);
	_ui.yzWidget->setVector((-NLMISC::CVector::I).y, (-NLMISC::CVector::I).z);
}

void CDirectionWidget::decVecJ()
{
	_Wrapper->setAndUpdateModifiedFlag( - NLMISC::CVector::J);
	_ui.xzWidget->setVector((-NLMISC::CVector::J).x, (-NLMISC::CVector::J).z);
	_ui.yzWidget->setVector((-NLMISC::CVector::J).y, (-NLMISC::CVector::J).z);
}

void CDirectionWidget::decVecK()
{
	_Wrapper->setAndUpdateModifiedFlag( - NLMISC::CVector::K);
	_ui.xzWidget->setVector((-NLMISC::CVector::K).x, (-NLMISC::CVector::K).z);
	_ui.yzWidget->setVector((-NLMISC::CVector::K).y, (-NLMISC::CVector::K).z);
}

void CDirectionWidget::setNewVecXZ(float x, float y)
{
	const float epsilon = 10E-3f;
	NLMISC::CVector v = _Wrapper->get();
	
	v.x = x;
	v.z = y;
	
	float d = v.x * v.x + v.z * v.z;
	float f; 
	if (fabs(d) > epsilon)
		f = sqrt((1.f - v.y * v.y) / d);
	else
		f = 1;
	
	v.x *= f;
	v.z *= f;
	
	v.normalize();

	_Wrapper->setAndUpdateModifiedFlag(v);
	_ui.xzWidget->setVector(_Wrapper->get().x, _Wrapper->get().z);
	_ui.yzWidget->setVector(_Wrapper->get().y, _Wrapper->get().z);
}

void CDirectionWidget::setNewVecYZ(float x, float y)
{
	const float epsilon = 10E-3f;
	NLMISC::CVector v = _Wrapper->get();
	
	v.y = x;
	v.z = y;
	
	float d = v.y * v.y + v.z * v.z;
	float f; 
	if (fabs(d) > epsilon)
		f = sqrt((1.f - v.x * v.x) / d);
	else
		f = 1;
	
	v.y *= f;
	v.z *= f;
	
	v.normalize();

	_Wrapper->setAndUpdateModifiedFlag(v);
	_ui.xzWidget->setVector(_Wrapper->get().x, _Wrapper->get().z);
	_ui.yzWidget->setVector(_Wrapper->get().y, _Wrapper->get().z);
}

void CDirectionWidget::checkEnabledGlobalDirection()
{
	bool enableUserDirection = true;
	_ui.xzWidget->show();
	_ui.yzWidget->show();
	if (_DirectionWrapper && _DirectionWrapper->supportGlobalVectorValue() && !_DirectionWrapper->getGlobalVectorValueName().empty())
	{
		enableUserDirection = false;
		_ui.xzWidget->hide();
		_ui.yzWidget->hide();
	}
	_ui.incVecIPushButton->setEnabled(enableUserDirection);
	_ui.incVecJPushButton->setEnabled(enableUserDirection);
	_ui.incVecKPushButton->setEnabled(enableUserDirection);
	_ui.decVecIPushButton->setEnabled(enableUserDirection);
	_ui.decVecJPushButton->setEnabled(enableUserDirection);
	_ui.decVecKPushButton->setEnabled(enableUserDirection);
}

} /* namespace NLQT */