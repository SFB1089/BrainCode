//
//  NeuronPopSample.hpp
//  NeuralNetworkCode
//
//  Created by Andreas Nold on 20.11.17.
//  Copyright © 2017 Andreas Nold. All rights reserved.
//

#ifndef NeuronPopSample_hpp
#define NeuronPopSample_hpp

#include <iostream>
#include <vector>
#include <random>
#include <typeinfo>
#include <cstring>
#include <valarray>
#include <fstream>
#include "GlobalFunctions.hpp"
#include "NeuronPop/NeuronPop.hpp"
#include "NeuronPop/LIFNeuronPop.hpp"
#include "NeuronPop/EIFNeuronPop.hpp"
#include "NeuronPop/QIFNeuronPop.hpp"
#include "NeuronPop/PoissonNeuronPop.hpp"


class NeuronPopSample
{
protected:

    int             generalNeuronSeed;

    GlobalSimInfo * info;

    unsigned int       noPopulations;
    NeuronPop **neuronPops;

public:
    NeuronPopSample(std::vector<std::string> *input,GlobalSimInfo * info);

    //*******************
    //Get-Functions
    //*******************
    unsigned long GetTotalNeurons()                   {return info->N;}
    unsigned int  GetTotalPopulations()               {return this->noPopulations;}
    unsigned long GetNeuronsPop(int popId)            {return neuronPops[popId]->GetNoNeurons();}
    NeuronPop * GetPop(int popId)            {return neuronPops[popId];}
    std::vector<long> * GetSpikers(int pop)  {return neuronPops[pop]->GetSpikers();}
	double GetX_Pos(int pop, long i)	    {return neuronPops[pop]->get_Xpos(i); }
	double GetY_Pos(int pop, long i)		{return neuronPops[pop]->get_Ypos(i); }
	double GetPotential(int pop, long i) { return neuronPops[pop]->GetPotential(i); }
    //*******************
    //Set-Functions
    //*******************
    void advect(std::vector<std::vector<double>> * synaptic_dV);
    void LoadParameters(std::vector<std::string> *input);
    void SaveParameters(std::ofstream * stream);
};

#endif /* NeuronPopSample_hpp */
