#ifndef CondTools_SiPixel_SiPixelCondObjForHLTReader_H
#define CondTools_SiPixel_SiPixelCondObjForHLTReader_H
// -*- C++ -*-
//
// Package:    SiPixelCondObjForHLTReader
// Class:      SiPixelCondObjForHLTReader
//
/**\class SiPixelCondObjForHLTReader SiPixelCondObjForHLTReader.h SiPixel/test/SiPixelCondObjForHLTReader.h

 Description: Test analyzer for reading pixel calibration from the DB

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Vincenzo CHIOCHIA
//         Created:  Tue Oct 17 17:40:56 CEST 2006
// $Id: SiPixelCondObjForHLTReader.h,v 1.7 2009/05/28 22:12:55 dlange Exp $
//
//
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
//#include "CondFormats/SiPixelObjForHLTects/interface/SiPixelGainCalibration.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "CalibTracker/SiPixelESProducers/interface/SiPixelGainCalibrationServiceBase.h"

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"

namespace cms {
  class SiPixelCondObjForHLTReader : public edm::one::EDAnalyzer<edm::one::SharedResources> {
  public:
    explicit SiPixelCondObjForHLTReader(const edm::ParameterSet &iConfig);

    void analyze(const edm::Event &, const edm::EventSetup &) override;
    void endJob() override;

  private:
    edm::ParameterSet conf_;
    //edm::ESHandle<SiPixelGainCalibration> SiPixelGainCalibration_;
    const edm::ESGetToken<TrackerGeometry, TrackerDigiGeometryRecord> tkGeomToken_;
    std::unique_ptr<SiPixelGainCalibrationServiceBase> SiPixelGainCalibrationService_;

    std::map<uint32_t, TH1F *> _TH1F_Pedestals_m;
    std::map<uint32_t, TH1F *> _TH1F_Gains_m;
    std::map<uint32_t, double> _deadfrac_m;
    std::map<uint32_t, double> _noisyfrac_m;

    TH1F *_TH1F_Dead_sum;
    TH1F *_TH1F_Noisy_sum;
    TH1F *_TH1F_Gains_sum;
    TH1F *_TH1F_Pedestals_sum;
    TH1F *_TH1F_Dead_all;
    TH1F *_TH1F_Noisy_all;
    TH1F *_TH1F_Gains_all;
    TH1F *_TH1F_Pedestals_all;
    TH1F *_TH1F_Gains_bpix;
    TH1F *_TH1F_Gains_fpix;
    TH1F *_TH1F_Pedestals_bpix;
    TH1F *_TH1F_Pedestals_fpix;
  };
}  // namespace cms
#endif
