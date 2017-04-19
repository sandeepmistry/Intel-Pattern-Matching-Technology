/*
   Copyright (c) 2016 Intel Corporation.  All rights reserved.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef _CURIE_PME_H_
#define _CURIE_PME_H_

#include <Arduino.h>

extern "C"
{
  #include <stdint.h>
}

//// New proposed API's ///////////////////////////////////////////////////////////////////////////

// constants for the distance mode
typedef enum {
	// default, uses the drift of the sum of all components, good for when components have different units
	PME_L1_NORM_DISTANCE_MODE, 

	// uses the largest drift, good for noisy inputs
	PME_LSUP_NORM_DISTANCE_MODE
} pme_distance_mode_t;

// used to return no category match or specify no category associated when learning
#define PME_NO_CATEGORY 0

// sets the global context to all, this enables the use of all neurons
#define PME_CONTEXT_ALL 0

///////////////////////////////////////////////////////////////////////////////////////////////////


class Intel_PMT : Print
{
//// New proposed API's ///////////////////////////////////////////////////////////////////////////
public:
	// Starts the learning process for the specified category. Use Print methods like .write(...)
	// to send training data (up to 128 bytes)
	//
	// Parameters
	// - category: PME_NO_CATEGORY or 1 - 32766
	//
	// Return Value
	// 1 on success, 0 on failure (invalid category)
	int beginLearning(int category);

	// Ends the learning process started by beginLearning
	//
	// Return Value
	// 1 on success, 0 on failure (invalid category)
	int endLearning();


	// Starts the classification process for the specified category. Use Print methods like .write(...)
	// to send data (up to 128 bytes) that needs to be classified.
	//
	// Return Value
	// 1 on success, 0 on failure
	int beginClassify();

	// Ends the classification process started by beginClassify
	//
	// Return Value
	// the category or PME_NO_CATEGORY (0) for no match
	int endClassify();

	// from Print
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buffer, size_t size);

	// template <typename T> inline size_t write(T val)
	// {
	// 	return write((uint8_t*)&val, sizeof(T));
	// }

	// clears the state of any learning
	void clearState();

	// Saves the current training state to the specified output Stream.
	// Up to maxNeuronStateSize() bytes will be written
	//
	// Return Value
	// 1 on success, 0 on failure
	int saveState(Stream& out);

	// Restors the current training state to the specified input Stream.
	// Up to maxNeuronStateSize() bytes will be read
	//
	// Return Value
	// 1 on success, 0 on failure
	int restoreState(Stream& in);

	// reads the maximum size in bytes of the neuron state
	int maxNeuronStateSize();

	// returns the number of neurons that are currently committed with learning/training data
	int neuronsCommitted();

	// return if the last training/learning data de-generated a neuron
	int neuronDegenerated();

	// set the distance calculation mode: PME_L1_NORM_DISTANCE_MODE or PME_LSUP_NORM_DISTANCE_MODE
	void setDistanceMode(int distanceMode);

	// Sets the current glocal context. By default PME_CONTEXT_ALL is used which specified to use
	// all neurons. You can use different contexts for different input componebts and the engine 
	// will automatically distribute the neurons per context for you.
	// Examples of different context are: 1 for audio data, 2 for video data.
	//
	// Parameters:
	// - context: PME_CONTEXT_ALL or 1 - 127
	void setContext(int context);

	// Set the learning influence parameters
	//
	// Parameters
	// - min: the miniumum learning influence, which controls the uncertainty domain
	// - max: the maximum learning influence (between 2 and 65535), the smaller 
	//        the value the more conservative the engine is
	void setLearningInfluence(int min, int max);

private:
	uint16_t _category;
	uint8_t _buffer[128];
	uint16_t _bufferIndex;
	int _distance;

///////////////////////////////////////////////////////////////////////////////////////////////////

public:

	static const uint32_t noMatch = 0x7fff;
	static const uint16_t minContext = 0;
	static const uint16_t maxContext = 127;
	static const int32_t maxVectorSize = 128;
	static const int32_t firstNeuronID = 1;
	static const int32_t lastNeuronID = 128;
	static const int32_t maxNeurons = 128;
	static const int32_t saveRestoreSize = 128;

	enum PATTERN_MATCHING_CLASSIFICATION_MODE
	{
		RBF_Mode = 0,
		KNN_Mode = 1
	} ;

	enum PATTERN_MATCHING_DISTANCE_MODE
	{
		L1_Distance = 0,
		LSUP_Distance = 1
	} ;

	typedef struct neuronData
	{
		uint16_t  context;
		uint16_t  influence;
		uint16_t  minInfluence;
		uint16_t  category;

		uint8_t   vector[saveRestoreSize];

	} neuronData;

	// constructor - the semantic is to construct, then initialise with a begin() method
	Intel_PMT();

	// Default initializer
	void begin(void);

	// custom initializer for the neural network
	void begin( 	uint16_t global_context,
			PATTERN_MATCHING_DISTANCE_MODE distance_mode,
			PATTERN_MATCHING_CLASSIFICATION_MODE classification_mode,
			uint16_t minAIF, uint16_t maxAIF );

	void forget( void );

	void configure( 	uint16_t global_context,
			PATTERN_MATCHING_DISTANCE_MODE distance_mode,
			PATTERN_MATCHING_CLASSIFICATION_MODE classification_mode,
			uint16_t minAIF, uint16_t maxAIF );

	uint16_t learn(uint8_t *pattern_vector, int32_t vector_length, uint16_t category);
	uint16_t classify(uint8_t *pattern_vector, int32_t vector_length);

	uint16_t readNeuron( int32_t neuronID, neuronData& data_array);

	// save and restore knowledge
	void beginSaveMode(void);  // saves the contents of the NSR register
	uint16_t iterateNeuronsToSave( neuronData& data_array );
	void endSaveMode(void); // restores the NSR value saved by beginSaveMode

	void beginRestoreMode(void);
	uint16_t iterateNeuronsToRestore( neuronData& data_array );
	void endRestoreMode(void);

	//getter and setters
	PATTERN_MATCHING_DISTANCE_MODE getDistanceMode(void);
	void setDistanceMode( PATTERN_MATCHING_DISTANCE_MODE mode);
	uint16_t getGlobalContext( void );
	void setGlobalContext( uint16_t context ); // valid range is 1-127
	uint16_t getNeuronContext( void );
	void setNeuronContext( uint16_t context ); // valid range is 1-127

	// NOTE: getCommittedCount() will give inaccurate value if the network is in Save/Restore mode.
	// It should not be called between the beginSaveMode() and endSaveMode() or between
	// beginRestoreMode() and endRestoreMode()
	uint16_t getCommittedCount( void );

	PATTERN_MATCHING_CLASSIFICATION_MODE getClassifierMode( void ); // RBF or KNN
	void setClassifierMode( PATTERN_MATCHING_CLASSIFICATION_MODE mode );

	// write vector is used for kNN recognition and does not alter
	// the CAT register, which moves the chain along.
	uint16_t writeVector(uint8_t *pattern_vector, int32_t vector_length);

    // raw register access - not recommended.
	uint16_t getNCR( void );
	uint16_t getCOMP( void );
	uint16_t getLCOMP( void );
	uint16_t getIDX_DIST( void );
	uint16_t getCAT( void );
	uint16_t getAIF( void );
	uint16_t getMINIF( void );
	uint16_t getMAXIF( void );
	uint16_t getNID( void );
	uint16_t getGCR( void );
	uint16_t getRSTCHAIN( void );
	uint16_t getNSR( void );
	uint16_t getFORGET_NCOUNT( void );

	protected:

	// base address of the pattern matching accelerator in Intel(r) Curie(tm) and QuarkSE(tm)
	static const uint32_t baseAddress =  0xB0600000L;

	enum Registers
	{
		NCR              = 0x00,	// Neuron Context Register
		COMP             = 0x04, 	// Component Register
		LCOMP            = 0x08, 	// Last Component
		IDX_DIST         = 0x0C, 	// Write Component Index / Read Distance
		CAT              = 0x10, 	// Category Register
		AIF              = 0x14, 	// Active Influence Field
		MINIF            = 0x18, 	// Minimum Influence Field
		MAXIF            = 0x1C, 	// Maximum Influence Field
		TESTCOMP         = 0x20, 	// Write Test Component
		TESTCAT          = 0x24, 	// Write Test Category
		NID              = 0x28, 	// Network ID
		GCR              = 0x2C, 	// Global Context Register
		RSTCHAIN         = 0x30, 	// Reset Chain
		NSR              = 0x34, 	// Network Status Register
		FORGET_NCOUNT    = 0x3C 	// Forget Command / Neuron Count
	};

	enum Masks
	{
		NCR_ID = 			0xFF00,	// Upper 8-bit of Neuron ID
		NCR_NORM = 			0x0040,	// 1 = LSUP, 0 = L1
		NCR_CONTEXT = 		0x007F,	// Neuron Context
		CAT_DEGEN = 		0x8000,	// Indicates neuron is degenerate
		CAT_CATEGORY =		0x7FFF, // the category associated with a neuron
		GCR_DIST = 			0x0080, // distance type, 1 = Lsup, 0 = L1
		GCR_GLOBAL =		0x007F, // the context of the neuron, used to segment the network
		NSR_CLASS_MODE = 	0x0020,	// Classifier mode 1 = KNN, 0 = RBF (KNN not for learning mode)
		NSR_NET_MODE =		0x0010,	// 1 = SR (save/restore) 0 = LR (learn/recognize)
		NSR_ID_FLAG = 		0x0008,	// Indicates positive identification
		NSR_UNCERTAIN_FLAG = 0x0004,// Indicates uncertain identification
	};

	// all pattern matching accelerator registers are 16-bits wide, memory-addressed
	// define efficient inline register access
	inline volatile uint16_t *regAddress (Registers reg)
	{
		return reinterpret_cast<volatile uint16_t*>(baseAddress + reg);
	}

	inline uint16_t regRead16 (Registers reg)
	{
		return *regAddress(reg);
	}

	inline void regWrite16 (Registers reg, uint16_t value)
	{
		*regAddress(reg) = value;
	}

	inline void regWrite16 (Registers reg, uint8_t value)
	{
		*regAddress(reg) = value;
	}

	inline void regWrite16 (Registers reg, int value)
	{
		*regAddress(reg) = value;
	}

private:
    uint16_t nsr_save;

};

extern Intel_PMT CuriePME;

#endif
