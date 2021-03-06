/*
 * Copyright (c) 2017 Wolthera van Hövell tot Westerflier <griffinvalley@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KIS_EDGE_DETECTION_FILTER_H
#define KIS_EDGE_DETECTION_FILTER_H

#include "filter/kis_filter.h"

#include <Eigen/Core>

class KritaEdgeDetectionFilter : public QObject
{
    Q_OBJECT
public:
    KritaEdgeDetectionFilter(QObject *parent, const QVariantList &);
    ~KritaEdgeDetectionFilter() override;
};

class KisEdgeDetectionFilter : public KisFilter
{
public:
    KisEdgeDetectionFilter();
    void processImpl(KisPaintDeviceSP device,
                     const QRect& rect,
                     const KisFilterConfigurationSP config,
                     KoUpdater* progressUpdater
                     ) const override;
    static inline KoID id() {
        return KoID("edge detection", i18n("Edge Detection"));
    }

    KisFilterConfigurationSP factoryConfiguration() const override;
public:
    KisConfigWidget * createConfigurationWidget(QWidget* parent, const KisPaintDeviceSP dev, bool useForMasks) const override;
    QRect neededRect(const QRect & rect, const KisFilterConfigurationSP _config, int lod) const override;
    QRect changedRect(const QRect & rect, const KisFilterConfigurationSP _config, int lod) const override;
};

#endif // KIS_EDGE_DETECTION_FILTER_H
