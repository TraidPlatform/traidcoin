// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
	uint8_t addr[16];
	uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds array into usable address objects.
static void convertSeeds(std::vector<CAddress> &vSeedsOut, const unsigned int *data, unsigned int count, int port)
{
	// It'll only connect to one or two seed nodes because once it connects,
	// it'll get a pile of addresses with newer timestamps.
	// Seed nodes are given a random 'last seen time' of between one and two
	// weeks ago.
	const int64_t nOneWeek = 7 * 24 * 60 * 60;
	for (unsigned int k = 0; k < count; ++k)
	{
		struct in_addr ip;
		unsigned int i = data[k], t;

		// -- convert to big endian
		t = (i & 0x000000ff) << 24u
			| (i & 0x0000ff00) << 8u
			| (i & 0x00ff0000) >> 8u
			| (i & 0xff000000) >> 24u;

		memcpy(&ip, &t, sizeof(ip));

		CAddress addr(CService(ip, port));
		addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
		vSeedsOut.push_back(addr);
	}
}

class CMainParams : public CChainParams {
public:
	CMainParams() {
		// The message start string is designed to be unlikely to occur in normal data.
		// The characters are rarely used upper ASCII, not valid as UTF-8, and produce
		// a large 4-byte int at any alignment.
		pchMessageStart[0] = 0x21;
		pchMessageStart[1] = 0xa1;
		pchMessageStart[2] = 0xde;
		pchMessageStart[3] = 0xa1;
		vAlertPubKey = ParseHex("043022c8409e72e15e23511a735ecfa8c2e80ca6c282b812cd42f0b38366cc512dc89d932a55a4ceab8f87cc6c14c296ae95704cc89745874a6af5a2543ec0fbf5");
		nDefaultPort = 53569;
		nRPCPort = 53568;
		bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
		/* The initial difficulty after switching to NeoScrypt (0.0625) */
		bnNeoScryptFirstTarget = CBigNum(~uint256(0) >> 28);

		// Build the genesis block. Note that the output of the genesis coinbase cannot
		// be spent as it did not originally exist in the database.

		const char* pszTimestamp = "Here on Sunday, July 29, 2018 6:00:00 PM GMT we start the Traid";
		std::vector<CTxIn> vin;
		vin.resize(1);
		vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
		std::vector<CTxOut> vout;
		vout.resize(1);
		vout[0].SetEmpty();
		CTransaction txNew(1, 1426700641, vin, vout, 0);
		genesis.vtx.push_back(txNew);
		genesis.hashPrevBlock = 0;
		genesis.hashMerkleRoot = genesis.BuildMerkleTree();
		genesis.nVersion = 1;
		genesis.nTime = 1532887200;
		genesis.nBits = 520159231;
		genesis.nNonce = 591319;



		hashGenesisBlock = genesis.GetHash();

		assert(genesis.hashMerkleRoot == uint256("0x16fbb572534be1bfa0dd60ab87cd61d945ce8ade0207a8ad96a012863587606d"));
		assert(hashGenesisBlock == uint256("0x0000b277c7e915e45dcecc5f275cafe5ddd6d3809940dcf623692f556d72e960"));


		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66); // T
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 61); // R
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 138); // x
		base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1, 76); // X
		base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0x06)(0x2D).convert_to_container<std::vector<unsigned char> >();
		base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vSeeds.push_back(CDNSSeedData("seed1", "seed1.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed2", "seed2.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed3", "seed3.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed4", "seed4.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed5", "seed5.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed6", "seed6.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed7", "seed7.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed8", "seed8.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed9", "seed9.traid.tv"));
        vSeeds.push_back(CDNSSeedData("seed10", "seed10.traid.tv"));
		convertSeeds(vFixedSeeds, pnSeed, ARRAYLEN(pnSeed), nDefaultPort);

		nPoolMaxTransactions = 3;
		//strSporkKey = "046f78dcf911fbd61910136f7f0f8d90578f68d0b3ac973b5040fb7afb501b5939f39b108b0569dca71488f5bbf498d92e4d1194f6f941307ffd95f75e76869f0e";
		//strMasternodePaymentsPubKey = "046f78dcf911fbd61910136f7f0f8d90578f68d0b3ac973b5040fb7afb501b5939f39b108b0569dca71488f5bbf498d92e4d1194f6f941307ffd95f75e76869f0e";
		strDarksendPoolDummyAddress = "TxXj6RGmcJw8f9iUAHHUbD6av91amQsoq6";
		nLastPOWBlock = 100000000;
		nPOSStartBlock = 1;
	}


	virtual const CBlock& GenesisBlock() const { return genesis; }
	virtual Network NetworkID() const { return CChainParams::MAIN; }

	virtual const vector<CAddress>& FixedSeeds() const {
		return vFixedSeeds;
	}
protected:
	CBlock genesis;
	vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
	CTestNetParams() {
		// The message start string is designed to be unlikely to occur in normal data.
		// The characters are rarely used upper ASCII, not valid as UTF-8, and produce
		// a large 4-byte int at any alignment.
		pchMessageStart[0] = 0x3e;
		pchMessageStart[1] = 0x2d;
		pchMessageStart[2] = 0x15;
		pchMessageStart[3] = 0x1a;
		bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
		bnNeoScryptFirstTarget = CBigNum(~uint256(0) >> 20);
		vAlertPubKey = ParseHex("04bec2d38c56a34920e0b4eae6718fb0a0bfc05bd30e676c48236552c35f72bac35e9905656373e04ed3b334cc23709955df30709f51757100edd616e2e4e6de9d");
		nDefaultPort = 43569;
		nRPCPort = 43568;
		strDataDir = "testnet";

		// Modify the testnet genesis block so the timestamp is valid for a later start.
		genesis.nBits = 520159231;
		genesis.nNonce = 591319;

		assert(hashGenesisBlock == uint256("0x0000b277c7e915e45dcecc5f275cafe5ddd6d3809940dcf623692f556d72e960"));

		vFixedSeeds.clear();
		vSeeds.clear();

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66);
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 61);
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 88);
		base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1, 98);
		base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
		base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

	vSeeds.push_back(CDNSSeedData("testseed1", "testseed1.traid.tv"));
        vSeeds.push_back(CDNSSeedData("testseed2", "testseed2.traid.tv"));
        vSeeds.push_back(CDNSSeedData("testseed3", "testseed3.traid.tv"));
        vSeeds.push_back(CDNSSeedData("testseed4", "testseed4.traid.tv"));
        vSeeds.push_back(CDNSSeedData("testseed5", "testseed5.traid.tv"));
		convertSeeds(vFixedSeeds, pnTestnetSeed, ARRAYLEN(pnTestnetSeed), nDefaultPort);

		nLastPOWBlock = 0x7fffffff;
	}
	virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
	return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
	switch (network) {
	case CChainParams::MAIN:
		pCurrentParams = &mainParams;
		break;
	case CChainParams::TESTNET:
		pCurrentParams = &testNetParams;
		break;
	default:
		assert(false && "Unimplemented network");
		return;
	}
}

bool SelectParamsFromCommandLine() {

	fTestNet = GetBoolArg("-testnet", false);

	if (fTestNet) {
		SelectParams(CChainParams::TESTNET);
	}
	else {
		SelectParams(CChainParams::MAIN);
	}
	return true;
}
