#ifndef newZZMatrixElement_newZZMatrixElement_h
#define newZZMatrixElement_newZZMatrixElement_h

#include <vector>
#include <TLorentzVector.h>
#include "ZZMatrixElement/MELA/interface/TVar.hh"
#include "ZZMatrixElement/MELA/interface/TEvtProb.hh"

class  newZZMatrixElement{
public:
  //pathtoHiggsCSandWidth: path to the textfiles of the HiggsCSandWidth package
  newZZMatrixElement(const char* pathtoHiggsCSandWidth,
		     double ebeam,
		     TVar::VerbosityLevel verbosity);

  ~newZZMatrixElement(){};
  /// Compute KD from masses and angles.
  /// The user must ensure that the order of m1/m2 matches the order of theta1/theta2.
  // flavor 1 for 4e, 2 for 4m, 3 for 2e2mu
  void computeXS(float mZZ, float mZ1, float mZ2,
                 float costhetastar,
                 float costheta1,
                 float costheta2,
                 float phistar1,
                 float phi,
				 int flavor,
				 TVar::Process process, 
				 TVar::MatrixElement memethod,
				 TVar::Production prodmode,
				 double couplingvals[SIZE_HVV_FREENORM],
				 double selfDHvvcoupl[SIZE_HVV][2],
				 double selfDZqqcoupl[SIZE_ZQQ][2],
				 double selfDZvvcoupl[SIZE_ZVV][2],
				 double selfDGqqcoupl[SIZE_GQQ][2],
				 double selfDGggcoupl[SIZE_GGG][2],
				 double selfDGvvcoupl[SIZE_GVV][2],
				 float &mevalue
			 );

  void computeProdXS(TLorentzVector jet1,
		     TLorentzVector jet2,
		     TLorentzVector higgs,
		     TVar::Process myModel,
		     TVar::Production myProduction,
			 double selfDHggcoupl[SIZE_HGG][2],
			 double selfDHvvcoupl[SIZE_HVV_VBF][2],
			 double selfDHwwcoupl[SIZE_HWW_VBF][2],
		     float &mevalue
		     );

  void set_mHiggs(float myPoleMass);
  void set_wHiggs(float myPoleWidth);
  void set_LeptonInterference(TVar::LeptonInterference myLepInterf);
  void reset_MCFM_EWKParameters(double ext_Gf, double ext_aemmz, double ext_mW, double ext_mZ);

  //compute four-momenta from angles only 
  // Nota bene: angles, not cos(theta)...
  std::vector<TLorentzVector> Calculate4Momentum(double Mx,double M1,double M2,double theta,double theta1,double theta2,double Phi1,double Phi);

private:
  
  TVar::VerbosityLevel verb;
  TEvtProb Xcal2;
  hzz4l_event_type hzz4l_event;
  float mHiggs;
  float wHiggs;
  double EBEAM;
  TVar::Process myModel;
  TVar::MatrixElement myME;
  TVar::Production myProduction;
  TVar::LeptonInterference myLeptonInterference;

};
#endif
