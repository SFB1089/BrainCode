//
//  GlobalFunctions.h
//  NeuralNetworkCode
//
//  Created by Andreas Nold on 13/01/2017.
//  Copyright © 2017 Andreas Nold. All rights reserved.
//

#ifndef GlobalFunctions_h
#define GlobalFunctions_h

#include <random>

struct GlobalSimInfo {

    std::default_random_engine globalGenerator;
    int		globalSeed;
    long    time_step;
    int     waiting_index;
    double  dt;
	int     density;
	double  Lx;
	double  Ly;
	int     Dimensions;
	double  simulationTime;
    double  networkScaling_synStrength;
    int     networkScaling_extern; // 0: default (=1)
    long    N;

} ;

struct ParameterFileEntry {
    std::string name;
    std::vector<std::string> values;

    ParameterFileEntry(std::string n, std::vector<std::string> v) : name(std::move(n)), values(std::move(v)) {
    }
    ParameterFileEntry(){}
};

struct IterableParameterFileEntry : ParameterFileEntry {
    std::string iterate_id;
    IterableParameterFileEntry(std::string it_id, std::string n, std::vector<std::string> v) :  ParameterFileEntry(n, v), iterate_id(it_id){
    }
};

const std::string str_randomConnectivity("RandomConnectivity");
const std::string str_binaryrandomConnectivity("BinaryRandomConnectivity");
const std::string str_distanceConnectivity("DistanceConnectivity");
//const std::string str_localConnectivity("LocalConnectivity");


const std::string str_currentSynapse("CurrentSynapse");
const std::string str_conductanceSynapse("ConductanceSynapse");
const std::string str_mongilloSynapse("MongilloSynapse");
const std::string str_mongilloSynapseContinuous("MongilloSynapseContinuous");
const std::string str_probabilisticCurrentSynapse("ProbabilisticCurrentSynapse");
const std::string str_prgSynapseContinuous("PRGSynapseContinuous");

const std::string str_exponentialCurrentSynapse("ExponentialCurrentSynapse");
const std::string str_powerlawsynapse("PowerLawSynapse");
const std::string str_exponentialConductanceSynapse("ExponentialConductanceSynapse");
const std::string str_exponentialMongilloSynapse("ExponentialMongilloSynapse");

const std::string str_exponentialSynapseAddon("ExponentialSynapseAddon");

const std::string str_LIFNeuron("LIFNeuron");
const std::string str_QIFNeuron("QIFNeuron");
const std::string str_EIFNeuron("EIFNeuron");
const std::string str_PoissonNeuron("PoissonNeuron");

const std::string str_leanRecorder("LeanRecorder");
const std::string str_advancedRecorder("AdvancedRecorder");

const std::string str_uncorrelatedStimulus("UncorrelatedStimulus");
const std::string str_whitenoiseStimulus("WhiteNoiseStimulus");
const std::string str_whitenoiseRescaled("WhiteNoiseRescaled");
const std::string str_Tims_sin_Stimulus("TimsSinStimulus");
const std::string str_whitenoiseLinear("WhiteNoiseLinear");
const std::string str_spatialgaussianStimulus("SpatialGaussianStimulus");
const std::string str_spatialpoissonStimulus("SpatialPoissonStimulus");

void multiply_vector (std::vector<unsigned long> &vector, unsigned long value);
void multiply_vector (std::vector<double> &vector, double value);

void TestWritingFile(std::string filename);

void FilterStringEntries(std::vector<ParameterFileEntry> *str_full,std::string token,std::vector<ParameterFileEntry> *str_filtered);
void FilterStringVector(std::vector<std::string> *str_full,std::string token,std::vector<std::string> *str_filtered);
void SplitString(std::string *full_str,std::string *name,std::vector<std::string> *values);
void SplitString(std::string *full_str, std::string *iterate_id, std::string *name, std::vector<std::string> *values);

void SaveDoubleFile(std::ofstream *file,double val,int precision);

bool is_double(const std::string& s);

ParameterFileEntry stringToParameterFileEntry(std::string);
IterableParameterFileEntry stringToIterableParameterFileEntry(std::string);

void checkConsistencyOfIterationParameters(const std::vector<IterableParameterFileEntry>&);

//int INTMAX = 2;
//double PI = 3.14159265359;

#endif /* GlobalFunctions_h */
