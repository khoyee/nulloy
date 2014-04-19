/********************************************************************
**  Nulloy Music Player, http://nulloy.com
**  Copyright (C) 2010-2014 Sergey Vlasov <sergey@vlasov.me>
**
**  This program can be distributed under the terms of the GNU
**  General Public License version 3.0 as published by the Free
**  Software Foundation and appearing in the file LICENSE.GPL3
**  included in the packaging of this file.  Please review the
**  following information to ensure the GNU General Public License
**  version 3.0 requirements will be met:
**
**  http://www.gnu.org/licenses/gpl-3.0.html
**
*********************************************************************/

#include "volumeSlider.h"
#include <QToolTip>
#include <QMouseEvent>

NVolumeSlider::NVolumeSlider(QWidget *parent) : NSlider(parent)
{
	connect(this, SIGNAL(valueChanged(int)), this, SLOT(on_valueChanged(int)));
}

void NVolumeSlider::on_valueChanged(int value)
{
	setToolTip(toolTipText(value));
}

void NVolumeSlider::mousePressEvent(QMouseEvent *event)
{
	showToolTip(event->x(), event->y());
	NSlider::mousePressEvent(event);
}

void NVolumeSlider::mouseMoveEvent(QMouseEvent *event)
{
	showToolTip(event->x(), event->y());
	NSlider::mouseMoveEvent(event);
}

void NVolumeSlider::wheelEvent(QWheelEvent *event)
{
	showToolTip(event->x(), event->y());
	NSlider::wheelEvent(event);
}

QString NVolumeSlider::toolTipText(int value)
{
	return QString("%1 %3\%").arg(tr("Volume")).arg(QString::number(value));
}

void NVolumeSlider::showToolTip(int x, int y)
{
	if (x == -1 || y == -1)
		return;

	QToolTip::showText(mapToGlobal(QPoint(x, y)), toolTipText(value()));
}

